# CAN Definitions

This repository defines the messages on the CAN bus in the car in the form of
a DBC database and provides various utilities for generating system
configuration files and source code from its contents.

## Using Generated Configurations

Generated configurations are stored in this repository in the `/out` folder. 
Configurations are version controlled so that we can ensure each part of the
system is referring to the same configurations.

To use the generated configuration in a project, add this repo as a submodule.
For example:

```sh
cd <LOCATION TO CLONE SUBMODULE>
git submodule add https://github.com/sufst/can-defs
```

Note that the use of submodules will require the following commands to be run
when cloning a project for the first time:

```sh
git submodule init
git submodule update
```

For more information on submodules, see the [Git submodule documentation](https://git-scm.com/book/en/v2/Git-Tools-Submodules).

## DBC Files

[DBC](https://www.csselectronics.com/pages/can-dbc-file-database-intro) ("Data 
Base CAN") is an industry standard file format for defining the content of 
messages on a CAN bus. Many device vendors provide DBC files for the CAN traffic
generated by their devices.

STAG 9 has two CAN buses:

1. CAN-C ("critical systems") bus.
2. CAN-S ("sensor/non-critical systems") bus.

There are many tools for working with DBC files. We suggest the use of
[Kvaser Database Editor 3](https://www.kvaser.com/download/) which can be
downloaded for free (Windows only).

Note also that DBC files can often be imported by CAN datalogger configuration softwares. We can use this for our MoTeC L120 datalogger to automatically configure the parsing and logging of CAN data.

## Telemetry System GENerator (TSGEN) 

### About
TSGEN is a Python module which generates various parts of the telemetry system
based on the DBC for the car. This includes:

- The telemetry and sensor schema for the [intermediate server](https://github.com/sufst/intermediate-server).
- C source code for unpacking CAN messages using the [`cantools` module](https://pypi.org/project/cantools/),
  which will be used in the on-car telemetry system.
- Parts of the embedded code for on-car telemetry.

The output of this generator is the `/out` folder, the contents of which can be used by other repositories by including this repository as a submodule.

### Setup

Install the dependencies in `tsgen/requirements.txt` to your chosen Python
environment.

### Usage

From the command line:

```sh
python -m tsgen <PATH TO DBC FILE>
```

### Releases
After a new set of configurations are generated, the corresponding commit to `main` should be tagged with a new version number:

```sh
git tag v1.1.2
git push --tags
```

Other repos using the generated outputs should be updated to the latest release **at the same time** to ensure they are using the same definitions.
