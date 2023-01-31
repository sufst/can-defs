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

## Telemetry System GENerator (TSGEN) 


### About
TSGEN is a Python module which generates various parts of the telemetry system
based on the DBC for the car. This includes:

- The telemetry and sensor schema for the [intermediate server](https://github.com/sufst/intermediate-server).
- C source code for unpacking CAN messages using the [`cantools` module](https://pypi.org/project/cantools/),
  which will be used in the on-car telemetry system.
- Parts of the embedded code for on-car telemetry.

### Setup

Install the dependencies in `tsgen/requirements.txt` to your chosen Python
environment.

### Usage

From the command line:

```sh
python -m tsgen <PATH TO DBC FILE>
```