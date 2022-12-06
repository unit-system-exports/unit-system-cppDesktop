#!/bin/python
import json
import os.path
import argparse

import unitGenerator
import unitHeaders

if __name__ == "__main__":
    msg = "A code generator for the unit system library.\n"
    msg += "This script generates all units and contains all of the unit definitions."

    parser = argparse.ArgumentParser(
        description=msg
    )

    parser.add_argument(
        "--genArduino",
        help="Generate the output for arduino",
        required=False,
        default=False,
        dest='genArduino',
        action='store_true'
    )

    # define the 'outDir' argument, which is optional, should be a string, and has a default value of ''
    parser.add_argument(
        "--outDir",
        help="Put all files in the same given directory. This overwrites the baseDir.",
        required=False,
        default='',
        dest='outDir',
        type=str,
    )

    parser.add_argument(
        "--exportMacro",
        help="the export macro that should be used for the types",
        required=False,
        default='',
        dest='exportMacro',
        action='store_const',
        const='UNIT_SYSTEM_EXPORT_MACRO '
    )

    parser.add_argument(
        "--printOutFiles",
        help="set to true if the generated file should be print",
        required=False,
        default=False,
        dest='printOutFiles',
        action='store_true',
    )

    args = vars(parser.parse_args())

    script_dir = os.path.realpath(os.path.dirname(__file__))
    template_dir = os.path.join(script_dir, 'templates')

    printFiles = args['printOutFiles']

    genStd = True
    outDir = args['outDir']
    if args['genArduino']:
        arduino_src_dir = os.path.join(script_dir, 'unit-system-adruino')
        arduino_src_dir = os.path.join(arduino_src_dir, 'src')

        if outDir == '':
            outDir = arduino_src_dir

        genStd = False

    json_string = unitGenerator.load_file_to_string(os.path.join(template_dir, 'units.json'))

    # Use a list comprehension to parse the JSON string and create the 'units' list
    units = [unitGenerator.unit_from_json(unit) for unit in json.loads(json_string)]

    # Use the update() method to update the 'export_macro' and 'out_dir' keys in the 'units' list
    for unit in units:
        unit.export_macro = args['exportMacro']
        unit.out_dir = outDir

    json_string = unitGenerator.load_file_to_string(os.path.join(template_dir, 'combinations.json'))
    combinations = [[comb['factor1'], comb['factor2'], comb['product']] for comb in json.loads(json_string)]

    json_string = unitGenerator.load_file_to_string(os.path.join(template_dir, 'constants.json'))
    #constants = []
    #json_data = json.loads(json_string)
    #for constant in json_data:
    #    constants += [constant]
    constants = [constant for constant in json.loads(json_string)]

    unit_strings = []
    for unit in units:
        unitGenerator.generate_sources(unit)
        unit_strings += [unit.name]
        if printFiles:
            print(unit.get_header_path())
            print(unit.get_source_path())

    fillDict = {
        'export_macro': args['exportMacro'],
        'units': unit_strings,
        'disable_std': not genStd,
        'combinations': combinations,
        'constants': constants,
    }

    unitHeaders.create_headers(
        fillDict,
        True,
        True,
        True,
        True,
        outDir,
        printFiles,
    )
