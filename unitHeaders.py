import argparse
import os
from typing import Dict

import unitGenerator


def create_headers(
    fill_dict: Dict,
    gen_unit_t: bool,
    gen_unit_header: bool,
    gen_combinations: bool,
    gen_constants: bool,
    output_dir: os.path,
):
    script_dir = os.path.realpath(os.path.dirname(__file__))
    template_dir = os.path.join(script_dir, 'templates')

    # generate unit_t.hpp
    if gen_unit_t:
        unitGenerator.fill_template(
            os.path.join(template_dir, 'unit_type.template'),
            fill_dict,
            os.path.join(output_dir, 'unit_system_unit_t.hpp')
        )

    # generate units.hpp
    if gen_unit_header:
        unitGenerator.fill_template(
            os.path.join(template_dir, 'units.template'),
            fill_dict,
            os.path.join(output_dir, 'unit_system_units.hpp')
        )

    # generate combinations.cpp and combinations.hpp
    if gen_combinations:
        unitGenerator.fill_template(
            os.path.join(template_dir, 'header_combine.template'),
            fill_dict,
            os.path.join(output_dir, 'unit_system_combinations.hpp')
        )

        unitGenerator.fill_template(
            os.path.join(template_dir, 'source_combine.template'),
            fill_dict,
            os.path.join(output_dir, 'unit_system_combinations.cpp')
        )

    # generate constants.hpp
    if gen_constants:
        unitGenerator.fill_template(
            os.path.join(template_dir, 'constants.template'),
            fill_dict,
            os.path.join(output_dir, 'unit_system_constants.hpp')
        )


if __name__ == "__main__":

    msg = "A code generator for the unit system library."

    parser = argparse.ArgumentParser(
        description=msg
    )
    parser.add_argument(
        "-u",
        "--unit",
        help="a unit that is enabled and generated. One literal per argument.",
        required=False,
        type=str,
        dest='units',
        action='append'
    )
    parser.add_argument(
        "-c",
        "--combine",
        help="combine two units, so that unit0 * unit1 = unit2",
        required=False,
        type=str,
        dest='combinations',
        action='append',
        nargs=3,
    )
    parser.add_argument(
        "--constant",
        help="a constant value that gets defined.",
        required=False,
        type=str,
        dest='constants',
        action='append',
        nargs=2,
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
        "--outDir",
        help="Put all files in the same given directory. This overwrites the baseDir.",
        required=True,
        default='',
        dest='outDir',
        type=str,
    )
    parser.add_argument(
        "--unitHeader",
        help="This should generate the unitHeader",
        required=False,
        default=False,
        dest='unitHeader',
        action='store_true'
    )
    parser.add_argument(
        "--combinations",
        help="This should generate the combinations header and sources",
        required=False,
        default=False,
        dest='genCombinations',
        action='store_true'
    )
    parser.add_argument(
        "--genConstants",
        help="This should generate the constants header",
        required=False,
        default=False,
        dest='genConstants',
        action='store_true'
    )
    parser.add_argument(
        "--disableSTD",
        help="disable the std functions",
        required=False,
        default=False,
        dest='disableSTD',
        action='store_true'
    )
    parser.add_argument(
        "--genUnit_t",
        help="generate the unit type header",
        required=False,
        default=False,
        dest='genUnit_t',
        action='store_true'
    )

    args = vars(parser.parse_args())

    units = args['units']
    exportMacro = args['exportMacro']
    outputDir = args['outDir']
    combinations = []

    if args['combinations']:
        for comb in args['combinations']:
            if comb[0] in units and comb[1] in units and comb[2] in units:
                combinations += [comb]

    constants = []
    if args['constants']:
        for pair in args['constants']:
            c_name = pair[0]
            c_value = float(pair[1])
            constants += [dict({'name': c_name, 'value': c_value})]

    # create the dict that fills all the templates
    fillDict = {
        'export_macro': exportMacro,
        'units': units,
        'disable_std': args['disableSTD'],
        'combinations': combinations,
        'constants': constants,
    }

    create_headers(
        fillDict,
        args['genUnit_t'],
        args['unitHeader'],
        args['genCombinations'],
        args['genConstants'],
        outputDir,
    )
