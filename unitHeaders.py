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

args = vars(parser.parse_args())

units = args['units']
export_macro = args['exportMacro']
output_dir = args['outDir']
script_dir = os.path.realpath(os.path.dirname(__file__))

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
