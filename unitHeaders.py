import os
import argparse
from typing import List, Dict

import jinja2

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

args = vars(parser.parse_args())

units = args['units']
export_macro = args['exportMacro']
output_dir = args['outDir']
script_dir = os.path.realpath(os.path.dirname(__file__))
combinations = args['combinations']

if args['unitHeader']:
    template_file_name = script_dir + '/templates/units.template'
    units_template_file = open(template_file_name, "r")
    units_template_string = units_template_file.read()
    units_template_file.close()

    template_units = jinja2.Template(units_template_string)
    units_text = template_units.render({
        'units': units,
        'export_macro': export_macro,
    })

    # print(len(current_unit.literals), current_unit.literals)
    units_file = open(os.path.join(output_dir, 'units.hpp'), "w")
    units_file.write(units_text)
    units_file.close()

if args['genCombinations'] and args['unitHeader']:
    # the file names for the templates
    header_file_name = script_dir + '/templates/header_combine.template'
    source_file_name = script_dir + '/templates/source_combine.template'

    # load the template files
    header_template_file = open(header_file_name, "r")
    header_template_string = header_template_file.read()
    header_template_file.close()

    source_template_file = open(source_file_name, "r")
    source_template_string = source_template_file.read()
    source_template_file.close()

    # generate header file
    template_header = jinja2.Template(header_template_string)
    header_text = template_header.render({
        'combinations': combinations,
        'export_macro': export_macro,
    })

    # print(len(current_unit.literals), current_unit.literals)
    header_file = open(os.path.join(output_dir, 'combinations.hpp'), "w")
    header_file.write(header_text)
    header_file.close()

    # generate source file
    template_source = jinja2.Template(source_template_string)
    source_text = template_source.render({
        'combinations': combinations,
        'export_macro': export_macro,
    })

    source_file = open(os.path.join(output_dir, 'combinations.cpp'), "w")
    source_file.write(source_text)
    source_file.close()
