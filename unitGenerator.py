import jinja2
import os
import argparse
import json
from typing import List, Dict


class UnitLiteral(Dict):
    def __init__(self, _data: dict):
        super().__init__(_data)
        # print(_data)
        self.name = _data['name']
        if 'multiplier' in _data:
            self.multiplier = _data['multiplier']
        else:
            self.multiplier = 1.0

        if 'offset' in _data:
            self.offset = _data['offset']
        else:
            self.offset = 0.0


include_subdir = 'include'
src_subdir = 'src'


class Unit:
    def __init__(
        self,
        name: str,
        base_name: str,
        unit_id: int,
        literals: List[UnitLiteral],
        export_macro: str,
        out_dir: bool,
        ostream: bool,
    ):
        self.name = name
        if base_name == '' or base_name is None:
            self.base_name = name
        else:
            self.base_name = base_name
        self.unit_id = unit_id
        self.literals = literals
        self.export_macro = export_macro
        self.out_dir = out_dir
        self.ostream = ostream

    def get_header_path(self) -> str:
        if self.out_dir:
            path = self.out_dir
        else:
            path = os.path.join(base_dir, include_subdir)
        path = os.path.join(path, self.name + '.hpp')

        os.makedirs(os.path.dirname(path), exist_ok=True)
        return path

    def get_source_path(self) -> str:
        if self.out_dir:
            path = self.out_dir
        else:
            path = os.path.join(base_dir, include_subdir)
        path = os.path.join(path, self.name + '.cpp')

        os.makedirs(os.path.dirname(path), exist_ok=True)
        return path


def generate_source(current_unit: Unit):
    # the file names for the templates
    script_dir = os.path.realpath(os.path.dirname(__file__))
    header_file_name = script_dir + '/templates/header.template'
    source_file_name = script_dir + '/templates/source.template'

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
        'unit_name': current_unit.name,
        'unit_base_name': current_unit.base_name,
        'unit_id': current_unit.unit_id,
        'literals': current_unit.literals,
        'create_literals': len(current_unit.literals) > 0,
        'export_macro': current_unit.export_macro,
        'gen_ostream': current_unit.ostream,
    })

    # print(len(current_unit.literals), current_unit.literals)
    header_file = open(current_unit.get_header_path(), "w")
    header_file.write(header_text)
    header_file.close()

    # generate source file
    template_source = jinja2.Template(source_template_string)
    source_text = template_source.render({
        'unit_name': current_unit.name,
        'unit_base_name': current_unit.base_name,
        'unit_id': current_unit.unit_id,
        'literals': current_unit.literals,
        'create_literals': len(current_unit.literals) > 0,
        'export_macro': current_unit.export_macro,
        'gen_ostream': current_unit.ostream,
    })

    source_file = open(current_unit.get_source_path(), "w")
    source_file.write(source_text)
    source_file.close()


# create the parser for the cmd inputs
msg = "A code generator for the unit system library."

parser = argparse.ArgumentParser(
    description=msg
)
parser.add_argument(
    "-n",
    "--name",
    help="name of the unit",
    required=True,
    type=str,
    dest='name'
)
parser.add_argument(
    "--baseName",
    help="the name of the basic unit (e.g. meters for length).",
    required=False,
    type=str,
    dest='baseName'
)
parser.add_argument(
    "-id",
    "--unit_identifier",
    help="id of the unit",
    required=True,
    type=int,
    dest='unit_id'
)
parser.add_argument(
    "-l",
    "--literal",
    help="a literal of the unit in json format. One literal per argument.",
    required=False,
    type=str,
    dest='literals',
    action='append'
)
parser.add_argument(
    "--baseDir",
    help="the base directory to output to",
    required=False,
    default='generated',
    type=str,
    dest='baseDir'
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
    required=False,
    default='',
    dest='outDir',
    type=str,
)
parser.add_argument(
    "--genOstream",
    help="Create the std stream functions",
    required=False,
    default=False,
    dest='genOstream',
    action='store_true'
)

args = vars(parser.parse_args())

base_dir = args['baseDir']

currLiteral = []
if args['literals']:
    for data in args['literals']:
        currLiteral.append(UnitLiteral(json.loads(data)))

# get the actual unit from the parsed input
currUnit = Unit(
    args['name'],
    args['baseName'],
    args['unit_id'],
    currLiteral,
    args['exportMacro'],
    args['outDir'],
    args['genOstream'],
)

# generate the sources for that unit
generate_source(currUnit)
