
# python imports
import json
import os
import re
import sys
import textwrap

# third-party imports
import cantools
from cantools.subparsers.generate_c_source import generate as do_generate_c_code


class TelemetrySystemGenerator:
    """Telemetry configuration and code generator

    Generates configurations and source code for:
    - The telemetry and sensor schema for the intermediate server
    - C code for the on-car telemetry system
    """

    # configs
    # TODO: this could be a nice CLI
    OUTPUT_FOLDER = './out'
    SENSORS_FILE_NAME = 'sensors.json'
    SCHEMA_FILE_NAME = 'schema.json'
    C_DATABASE_NAME = 'can_database'
    CAN_HANDLER_SOURCE_NAME = 'can_handlers'
    JSON_INDENT = 2

    def __init__(self, dbc_file: str):
        """Initialises telemetry configuration generator

        Args:
            dbc_file:   DBC database file
        """
        self._dbc = cantools.database.load_file(dbc_file)

    def generate(self):
        """Generates all files
        """
        self._c_header, self._c_source = self.generate_c_code()
        self._sensor_schema = None
        self._telemetry_schema = None

        self.generate_intermediate_server()
        self.generate_on_car_telemetry()

    def generate_c_code(self):
        """Runs the C code generation of the cantools module

        Args:
            dbc:    DBC database

        Return:
            Tuple containing paths to C header and source files
        """
        HEADER_FILE = f'{self.C_DATABASE_NAME}.h'
        SOURCE_FILE = f'{self.C_DATABASE_NAME}.c'

        header, source, _, _ = do_generate_c_code(self._dbc,
                                                  self.C_DATABASE_NAME, 
                                                  HEADER_FILE, 
                                                  SOURCE_FILE, 
                                                  SOURCE_FILE)

        file_paths = [os.path.join(self.OUTPUT_FOLDER, name) for name in [HEADER_FILE, SOURCE_FILE]]

        for file_path, data in zip(file_paths, [header, source]):
            with open(file_path, 'w') as f:
                f.write(data)

        return file_paths

    def generate_on_car_telemetry(self):
        """Generates CAN message handler database for on-car telemetry
        """
        assert(self._sensor_schema is not None)
        assert(self._telemetry_schema is not None)

        STRUCT_KEYWORD = 'struct'

        struct_names: list[str] = []

        # find all the names of the structs representing unpacked messages and 
        # create a dictionary of struct names and corresponding unpacking funcs
        with open(self._c_header) as file:
            
            for line in file:

                if STRUCT_KEYWORD in line[0:len(STRUCT_KEYWORD)]:

                    # actual struct name after 'struct' keyword
                    struct_name = line.split(' ')[1]
                    struct_names.append(struct_name)

        # create the table of CAN message IDs, struct names and look-up functions
        h_code = \
            '''
                #ifndef CAN_HANDLERS_H
                #define CAN_HANDLERS_H

                #include <stdint.h>

                /**
                 * @brief   Entry in CAN handler table
                 */
                typedef struct {
                    uint32_t identifier;
                    void (*unpack_func)(uint8_t*, const uint8_t*, size_t);
                } can_handler_t;

                /* 
                 * function prototypes
                 */
                const can_handler_t* can_handler_get(uint32_t index);
                uint32_t can_handler_table_size();

                #endif
            '''

        c_code = \
            ''' 
                #include "can_handlers.h"
                #include "__CAN_DATABASE__.h"

                /**
                 * @brief   Function template for handler implementation
                 *
                 * @details Because the actual unpacking functions have concrete struct types,
                            they all have different function signatures and cannot be stored 
                            in the CAN handler table. This macro generates a wrapper function 
                            which casts the pointer to the bytes to unpack into to the actual
                            type and calls the unpacking function.
                 */
                #define IMPL_HANDLER(T, f) \\
                    static void T##_handler(uint8_t* dst, const uint8_t* src, size_t length) \\
                    { \\
                        struct T* output = (struct T*) dst; \\
                        f(dst, src, length); \\
                    } \\
                __HANDLER_WRAPPERS__

                /**
                 * @brief   Table of CAN message IDs and associated unpacking functions
                 */
                static const can_handler_t can_handler_table[] = {__TABLE_ITEMS__
                };

                /**
                 * @brief       Returns the CAN handler at the specified index in the table, or 
                 *              NULL if out of bounds
                 * 
                 * @param[in]   index   Index in table
                 */
                const can_handler_t* can_handler_get(uint32_t index)
                {
                    const can_handler_t* handler = NULL;

                    if (index < can_handler_table_size())
                    {
                        handler = &can_handler_table[index];
                    }

                    return handler;
                }

                /**
                 * @brief   Returns the number of CAN handlers in the table
                 */
                uint32_t can_handler_table_size()
                {
                    return sizeof(can_handler_table) / sizeof(can_handler_table[0]);
                }
            '''

        h_code = textwrap.dedent(h_code)
        c_code = textwrap.dedent(c_code)

        table_items = ''
        handler_wrappers = ''

        for struct_name in struct_names:

            struct_basename: str = struct_name[:-2] # without _t

            # _t at end of name replaced with _unpack
            unpack_func = f'{struct_basename}_unpack'

            # handler wrapper
            handler_wrapper = f'IMPL_HANDLER({struct_name}, {unpack_func})'
            handler_name = f'{struct_name}_handler'

            # macro for CAN identifier in uppercase with _FRAME_ID at end
            identifier_macro = f'{struct_basename.upper()}_FRAME_ID'

            # add to code
            table_item = f'{{{identifier_macro}, {handler_name}}},'
            table_items = f'{table_items}\n    {table_item}'

            handler_wrappers = f'{handler_wrappers}\n{handler_wrapper}'

        c_code = c_code.replace('__TABLE_ITEMS__', table_items)
        c_code = c_code.replace('__HANDLER_WRAPPERS__', handler_wrappers)
        c_code = c_code.replace('__CAN_DATABASE__.h', f'{self.C_DATABASE_NAME}.h')

        # save the code to file
        def save_code(file_name, code):
            with open(os.path.join(self.OUTPUT_FOLDER, file_name), 'w') as file:
                file.write(code)

        save_code(f'{self.CAN_HANDLER_SOURCE_NAME}.h', h_code)
        save_code(f'{self.CAN_HANDLER_SOURCE_NAME}.c', c_code)
        
    def generate_intermediate_server(self):
        """Generates schemas for the intermediate server and saves them in the
        output folder
        """
        self._sensor_schema = {}
        pdus = {}

        for id, message in enumerate(self._dbc.messages):

            pdus[message.name] = self.create_pdu(message, id)

            for signal in message.signals:
                schema = self.create_sensor_schema(signal, message.name)
                self._sensor_schema |= schema

        self._telemetry_schema = {
            "startByte": 1,
            "pdu": pdus
        }

        # save output to file
        def save_output(file_name, json_data):
            with open(os.path.join(self.OUTPUT_FOLDER, file_name), 'w') as file:
                file.write(json.dumps(json_data, indent=self.JSON_INDENT))

        save_output(self.SENSORS_FILE_NAME, self._sensor_schema)
        save_output(self.SCHEMA_FILE_NAME, self._telemetry_schema)

    def create_pdu(self, 
                   message: cantools.database.can.Message, 
                   id: int) -> dict:
        """Creates the schema for a single PDU from a CAN message

        Each signal in the message becomes one of the data points in the body. 
        Since CAN messages are limited to 8 bytes, protocol frames will always
        be much smaller than the maximum size of 128 bytes. This could make the
        system less efficient as the overhead from the header takes up a greater
        proportion of the bandwidth, but it is the simplest way to group data
        into PDUs for now.

        Args:
            message:        CAN message information
            id:             Unique ID number for PDU

        Returns:
            PDU schema dictionary
        """

        return {
            "id": id,
            "header": [ # TODO: this always seems to be the same?
                {"name": "valid_bitfield", "cType": "H"},
                {"name": "epoch", "cType": "d"}
            ],
            "body": [
                {"name": signal.name, "cType": self.signal_ctype(signal)} for signal in message.signals
            ]
        }    

    def create_sensor_schema(self,
                             signal: cantools.database.can.signal.Signal, 
                             group: str) -> dict:
        """Create the JSON schema defining a single sensor

        Args:
            signal:     Signal information
            group:      Signal group name

        Returns:
            JSON schema
        """
        def format_units(unit):
            # clean up the units
            # example: "torque:N.m" -> "Nm"
            if unit is not None:
                unit = unit.split(':')[-1]
                unit = unit.replace('.', '')
            else:
                unit = "Code" # defaulting to "code" for things without units
            return unit
        
        return {
            signal.name: {
                "name": signal.name.replace('_', ' '),
                "units": format_units(signal.unit),
                "enable": True,
                "group": group,
                "min": signal.minimum,
                "max": signal.maximum,
                "on_dash": False, # we don't have a dash yet...
                "emulation": self.create_emulator(signal)
            }
        }

    def signal_ctype(self, signal: cantools.database.can.Signal) -> str:
        """Works out the cType of a signal

        Args:
            signal:     Signal information

        Returns:
            cType string
        """
        types = {
            "int8_t": "b",
            "uint8_t": "B",
            "int16_t": "h",
            "uint16_t": "H",
            "int32_t": "i",
            "uint32_t": "I",
            "float": "f",
            "double": "d",
            "bool": "?"
        }

        def camel_to_snake_case(value):
            value = re.sub(r'(.)([A-Z][a-z]+)', r'\1_\2', value)
            value = re.sub(r'(_+)', '_', value)
            value = re.sub(r'([a-z0-9])([A-Z])', r'\1_\2', value).lower()
            value = re.sub(r'[^a-zA-Z0-9]', '_', value)
            return value

        struct_field_name = camel_to_snake_case(signal.name)

        # TODO: it's a bit wasteful to open and search the file every time
        #       better to go through the file at the beginning and do it all then
        with open(self._c_header, 'r') as f:
            for line in f:
                if struct_field_name in line:
                    dtype = line.strip().split(' ')[0]
                    return types[dtype]

        print(f'Warning: could not determine cType for {signal.name}')
        return None

    @staticmethod
    def create_emulator(signal: cantools.database.can.Signal) -> str:
        """Creates the emulator code for a sensor signal

        Args:
            signal:     Signal information

        Returns:
            Emulator code
        """

        # TODO: signals with choices

        isfloat = signal.is_float or any(isinstance(x, float) for x in [signal.minimum, signal.maximum]) # isfloat doesn't really seem to be accurate
        isbool = not isfloat and (signal.minimum == 0 and signal.maximum == 1)
        isint = not isfloat and not isbool

        em = '0'
        try:
            if isfloat or isint:
                scale = (signal.maximum - signal.minimum) / 2
                offset = signal.minimum + scale
                cast = 'int' if isint else 'float'
                offset_sign = '+' if offset >= 0 else '-'
                em = f'{cast}({scale} * modules.math.sin(modules.math.radians(x * 10)) {offset_sign} {abs(offset)})'
            elif isbool:
                em = 'bool((x % 50) > 25)' # square wave
        except TypeError:
            print('Warning: could not create emulator for signal', repr(signal.name))

        return em


if __name__ == '__main__':

    # TODO: make this into an actual CLI, e.g. with argparse
    if len(sys.argv) < 2:
        print('Error: please specify a DBC file')
        sys.exit(1)

    dbc_file = sys.argv[1]

    if not os.path.isfile(dbc_file):
        print('Error: invalid DBC file')
        sys.exit(1)

    tsgen = TelemetrySystemGenerator(dbc_file)
    tsgen.generate()
