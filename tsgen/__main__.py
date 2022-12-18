
# python imports
import glob
import json
import os
import sys

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
    C_DATABASE_NAME = 'candb'
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

        struct_field_name = signal.name.lower()

        # TODO: it's a bit wasteful to open and search the file every time
        #       better to go through the file at the beginning and do it all then
        with open(self._c_header, 'r') as f:
            for line in f:
                if struct_field_name in line:
                    dtype = line.strip().split(' ')[0]
                    return types[dtype]

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
        # TODO: cast to bool if signal is int and values can only be 0 and 1

        def cast_int():
            return f'int(x * {signal.scale} + {signal.offset})'

        def cast_float():
            return f'float(x * {signal.scale} + {signal.offset})'

        if signal.is_float:
            return cast_float()
        else:
            return cast_int()


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