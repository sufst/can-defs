
# python imports
import json
import os
import re
import sys
import textwrap
from dataclasses import dataclass

# third-party imports
import cantools
from cantools.subparsers.generate_c_source import generate as do_generate_c_code


@dataclass
class DBCAttributes:
    """Custom DBC 
    These are added to the DBC using Vector CANdb++
    """
    enabled: bool
    pdu_id: int


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
    CAN_S_APP = 'can_s'
    CAN_C_APP = 'can_c'
    CAN_HANDLER_SOURCE_NAME = 'can_handlers'
    JSON_INDENT = 2

    def __init__(self, can_c_file: str, can_s_file: str):
        """Initialises telemetry configuration generator

        Args:
            can_c_file:   DBC database CAN-S file
            can_s_file:   DBC database CAN-C file
        """
        self.can_c = cantools.database.load_file(can_c_file)
        self.can_s = cantools.database.load_file(can_s_file)

    def generate(self):
        """Generates all files
        """
        self._c_header_can_c, self._c_source_can_c = self.generate_c_code(self.CAN_C_APP)
        self._c_header_can_s, self._c_source_can_s = self.generate_c_code(self.CAN_S_APP)
        self._sensor_schema = None
        self._telemetry_schema = None
        self._oct_attributes = None

        self.generate_intermediate_server()
        self.generate_on_car_telemetry() # depends on intermediate server

    def generate_c_code(self, bus: str):
        """Runs the C code generation of the cantools module

        Args:
            dbc:    DBC database

        Return:
            Tuple containing paths to C header and source files
        """
        HEADER_FILE = f'{bus}.h'
        SOURCE_FILE = f'{bus}.c'

        header, source, _, _ = do_generate_c_code(self.__getattribute__(bus),
                                                  bus, 
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
        assert(self._oct_attributes is not None)

        STRUCT_KEYWORD = 'struct'
        struct_names_can_c: list[str] = []
        struct_names_can_s: list[str] = []

        # find all the names of the structs representing unpacked messages and 
        # create a dictionary of struct names and corresponding unpacking funcs
        with open(self._c_header_can_c) as file:
            
            for line in file:

                if STRUCT_KEYWORD in line[0:len(STRUCT_KEYWORD)]:

                    # actual struct name after 'struct' keyword
                    struct_name = line.split(' ')[1]
                    struct_names_can_c.append(struct_name)

        with open(self._c_header_can_s) as file:
            
            for line in file:

                if STRUCT_KEYWORD in line[0:len(STRUCT_KEYWORD)]:

                    # actual struct name after 'struct' keyword
                    struct_name = line.split(' ')[1]
                    struct_names_can_s.append(struct_name)

        # create the table of CAN message IDs, struct names and look-up functions
        # double underscores indicate things that will be replaced in the template code
        h_code = \
            '''
                #ifndef CAN_HANDLERS_H
                #define CAN_HANDLERS_H

                #include <stdbool.h>
                #include <stdint.h>
                #include <stddef.h>

                #define CAN_C_HANDLERS_TABLE_SIZE __TABLE_SIZE_CAN_C__
                #define CAN_S_HANDLERS_TABLE_SIZE __TABLE_SIZE_CAN_S__

                #define CAN_C_HANDLER_TABLE_INSTANCE 0
                #define CAN_S_HANDLER_TABLE_INSTANCE 1

                /**
                 * @brief   Entry in CAN handler table
                 */
                typedef struct {
                    uint32_t identifier;
                    uint32_t pdu_id;
                    void (*unpack_func)(uint8_t*, const uint8_t*, size_t);
                } can_handler_t;

                /* 
                 * function prototypes
                 */
                const can_handler_t* can_handler_get(uint32_t index, uint8_t instance);

                #endif
            '''

        c_code = \
            ''' 
                #include "can_handlers.h"
                #include "can_s.h"
                #include "can_c.h"

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
                __HANDLER_WRAPPERS_CAN_C__
                __HANDLER_WRAPPERS_CAN_S__

                /**
                 * @brief   Table of CAN message IDs and associated unpacking functions
                 */
                static const can_handler_t can_c_handler_table[] = {__TABLE_ITEMS_CAN_C__
                };

                /**
                 * @brief   Table of CAN message IDs and associated unpacking functions
                 */
                static const can_handler_t can_s_handler_table[] = {__TABLE_ITEMS_CAN_S__
                };

                /**
                 * @brief       Returns the CAN handler at the specified index in the table, or 
                 *              NULL if out of bounds or wrong instance number
                 * 
                 * @param[in]   index       Index in table
                 * @param[in]   instance    Selection of can handler table 
                 *                          CAN_C_HANDLER_TABLE_INSTANCE or CAN_S_HANDLER_TABLE_INSTANCE
                 */
                const can_handler_t* can_handler_get(uint32_t index, uint8_t instance)
                {
                    const can_handler_t* handler = NULL;

                    if (instance == CAN_C_HANDLER_TABLE_INSTANCE)
                    {
                        if (index < CAN_C_HANDLERS_TABLE_SIZE)
                        {
                            handler = &can_c_handler_table[index];
                        }                    
                    }
                    else if(instance == CAN_S_HANDLER_TABLE_INSTANCE)
                    {
                        if (index < CAN_S_HANDLERS_TABLE_SIZE)
                        {
                            handler = &can_s_handler_table[index];
                        }                      
                    }
                    return handler;
                }
            '''

        h_code = textwrap.dedent(h_code)
        c_code = textwrap.dedent(c_code)

        table_items = ''
        handler_wrappers = ''
        num_handlers = 0

        for struct_name in struct_names_can_c:

            struct_basename: str = struct_name[:-2] # without _t

            # _t at end of name replaced with _unpack
            unpack_func = f'{struct_basename}_unpack'

            # get the message attributes extracted during schema creation
            struct_short_name: str = struct_basename[len(self.CAN_C_APP) + 1:]
            attr: DBCAttributes = self._oct_attributes[struct_short_name]

            if not attr.enabled: 
                continue

            pdu_id = attr.pdu_id

            # handler wrapper
            handler_wrapper = f'IMPL_HANDLER({struct_name}, {unpack_func})'
            handler_name = f'{struct_name}_handler'

            # macro for CAN identifier in uppercase with _FRAME_ID at end
            identifier_macro = f'{struct_basename.upper()}_FRAME_ID'

            # add to code
            num_handlers += 1

            table_item = f'{{{identifier_macro}, {pdu_id}, {handler_name}}},'
            table_items = f'{table_items}\n    {table_item}'
            handler_wrappers = f'{handler_wrappers}\n{handler_wrapper}'

        c_code = c_code.replace('__TABLE_ITEMS_CAN_C__', table_items)
        c_code = c_code.replace('__HANDLER_WRAPPERS_CAN_C__', handler_wrappers)
        h_code = h_code.replace('__TABLE_SIZE_CAN_C__', str(num_handlers))

        table_items = ''
        handler_wrappers = ''
        num_handlers = 0

        for struct_name in struct_names_can_s:

            struct_basename: str = struct_name[:-2] # without _t

            # _t at end of name replaced with _unpack
            unpack_func = f'{struct_basename}_unpack'

            # get the message attributes extracted during schema creation
            struct_short_name: str = struct_basename[len(self.CAN_S_APP) + 1:]
            attr: DBCAttributes = self._oct_attributes[struct_short_name]

            if not attr.enabled: 
                continue

            pdu_id = attr.pdu_id

            # handler wrapper
            handler_wrapper = f'IMPL_HANDLER({struct_name}, {unpack_func})'
            handler_name = f'{struct_name}_handler'

            # macro for CAN identifier in uppercase with _FRAME_ID at end
            identifier_macro = f'{struct_basename.upper()}_FRAME_ID'

            # add to code
            num_handlers += 1

            table_item = f'{{{identifier_macro}, {pdu_id}, {handler_name}}},'
            table_items = f'{table_items}\n    {table_item}'
            handler_wrappers = f'{handler_wrappers}\n{handler_wrapper}'

        c_code = c_code.replace('__TABLE_ITEMS_CAN_S__', table_items)
        c_code = c_code.replace('__HANDLER_WRAPPERS_CAN_S__', handler_wrappers)
        h_code = h_code.replace('__TABLE_SIZE_CAN_S__', str(num_handlers))

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
        self._oct_attributes = {}
        pdus = {}

        for message in self.can_c.messages + self.can_s.messages:
            attr = self.get_dbc_attributes(message)
            c_struct_name = self.camel_to_snake_case(message.name)
            self._oct_attributes[c_struct_name] = attr

            if attr.enabled:

                pdus[message.name] = self.create_pdu(message, attr.pdu_id)

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

    @staticmethod
    def get_dbc_attributes(message: cantools.database.can.Message) -> DBCAttributes:
        """Extracts custom attributes which we have defined in the DBC file
        """
        attr = message.dbc.attributes

        try:
            return DBCAttributes(
                enabled=(attr['OCT_ENABLE'].value == 1),
                pdu_id=int(attr['OCT_PDU_ID'].value)
            )
        except KeyError:
            print(f'Warning: Attributes missing for message {message.name}')
        
        # message disabled because required attributes are missing
        return DBCAttributes(False, None)

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
            id:             Unique PDU identifier

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

        struct_field_name = self.camel_to_snake_case(signal.name)

        # TODO: it's a bit wasteful to open and search the file every time
        #       better to go through the file at the beginning and do it all then
        with open(self._c_header_can_c, 'r') as f:
            for line in f:
                if struct_field_name in line:
                    dtype = line.strip().split(' ')[0]
                    return types[dtype]                
        #Look in can_s if can_c doesnt contain valid signal
        with open(self._c_header_can_s, 'r') as f:
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
    
    @staticmethod
    def camel_to_snake_case(value) -> str:
        value = re.sub(r'(.)([A-Z][a-z]+)', r'\1_\2', value)
        value = re.sub(r'(_+)', '_', value)
        value = re.sub(r'([a-z0-9])([A-Z])', r'\1_\2', value).lower()
        value = re.sub(r'[^a-zA-Z0-9]', '_', value)
        return value


if __name__ == '__main__':

    # TODO: make this into an actual CLI, e.g. with argparse
    if len(sys.argv) < 3:
        print('Error: please specify two DBC files: can_c and can_s')
        sys.exit(1)

    can_c_file = sys.argv[1]
    can_s_file = sys.argv[2]

    if not os.path.isfile(can_c_file):
        print('Error: invalid CAN-C file')
        sys.exit(1)

    if not os.path.isfile(can_s_file):
        print('Error: invalid CAN-S file')
        sys.exit(1)

    tsgen = TelemetrySystemGenerator(can_c_file, can_s_file)
    tsgen.generate()
