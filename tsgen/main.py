
# python imports
import os
import sys
from typing import cast

# third-party imports
import cantools
import cantools.database
from cantools.database import Database
from cantools.database.can.c_source import generate as do_generate_c_code


class TelemetrySystemGenerator:
    """Generates C source code for both CAN buses from their DBC files"""

    # TODO: this could be a nice CLI
    OUTPUT_FOLDER = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), 'out')
    CAN_S_DATABASE_NAME = 'can_s'
    CAN_T_DATABASE_NAME = 'can_t'

    def __init__(self, can_t_file: str, can_s_file: str):
        """Initialises telemetry configuration generator

        Args:
            can_t_file:   DBC database CAN-T file
            can_s_file:   DBC database CAN-S file
        """
        self.can_t = cast(Database, cantools.database.load_file(can_t_file))
        self.can_s = cast(Database, cantools.database.load_file(can_s_file))

    def generate(self):
        """Generates all files"""
        self.generate_c_code(self.CAN_T_DATABASE_NAME, self.can_t)
        self.generate_c_code(self.CAN_S_DATABASE_NAME, self.can_s)

    def generate_c_code(self, bus: str, db: Database) -> tuple[str, str]:
        """Runs the C code generation of the cantools module

        Args:
            bus:    Database name / bus prefix (e.g. 'can_t')
            db:     Loaded cantools database

        Returns:
            Tuple of (header_path, source_path)
        """
        header_file = f'{bus}.h'
        source_file = f'{bus}.c'

        header, source, _, _ = do_generate_c_code(db, bus, header_file, source_file, source_file)

        header_path = os.path.join(self.OUTPUT_FOLDER, header_file)
        source_path = os.path.join(self.OUTPUT_FOLDER, source_file)

        with open(header_path, 'w') as f:
            f.write(header)
        with open(source_path, 'w') as f:
            f.write(source)

        return header_path, source_path


if __name__ == '__main__':
    repo_root = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

    can_t_file = os.path.join(repo_root, 'dbc', 'CAN-T.dbc')
    can_s_file = os.path.join(repo_root, 'dbc', 'CAN-S.dbc')

    if not os.path.isfile(can_t_file):
        print('Error: invalid CAN-T file')
        sys.exit(1)

    if not os.path.isfile(can_s_file):
        print('Error: invalid CAN-S file')
        sys.exit(1)

    tsgen = TelemetrySystemGenerator(can_t_file, can_s_file)
    tsgen.generate()
