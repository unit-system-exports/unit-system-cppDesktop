#!/bin/python
import json
import os.path

import unitGenerator
import unitHeaders

script_dir = os.path.realpath(os.path.dirname(__file__))
arduino_src_dir = os.path.join(script_dir, 'unit-system-adruino')
arduino_src_dir = os.path.join(arduino_src_dir, 'src')

arduino_export_macro = ''

units = []
# base units
units += [unitGenerator.Unit('time_si', 'seconds', 1, [
    unitGenerator.UnitLiteral(json.loads('{"name":"a", "multiplier":31536000000}')),
    unitGenerator.UnitLiteral(json.loads('{"name":"d", "multiplier":86400000}')),
    unitGenerator.UnitLiteral(json.loads('{"name":"h", "multiplier":3600}')),
    unitGenerator.UnitLiteral(json.loads('{"name":"minute", "multiplier":60}')),
    unitGenerator.UnitLiteral(json.loads('{"name":"s", "multiplier":1e0}')),
    unitGenerator.UnitLiteral(json.loads('{"name":"ms", "multiplier":1e-3}')),
    unitGenerator.UnitLiteral(json.loads('{"name":"ns", "multiplier":1e-6}')),
    unitGenerator.UnitLiteral(json.loads('{"name":"us", "multiplier":1e-9}')),
    unitGenerator.UnitLiteral(json.loads('{"name":"fs", "multiplier":1e-12}')),
], arduino_export_macro, arduino_src_dir)]
units += [unitGenerator.Unit('length', 'meter', 2, [
    unitGenerator.UnitLiteral(json.loads('{"name":"km", "multiplier":1e3}')),
    unitGenerator.UnitLiteral(json.loads('{"name":"m", "multiplier":1e0}')),
    unitGenerator.UnitLiteral(json.loads('{"name":"dm", "multiplier":1e-1}')),
    unitGenerator.UnitLiteral(json.loads('{"name":"cm", "multiplier":1e-2}')),
    unitGenerator.UnitLiteral(json.loads('{"name":"mm", "multiplier":1e-3}')),
    unitGenerator.UnitLiteral(json.loads('{"name":"um", "multiplier":1e-6}')),
    unitGenerator.UnitLiteral(json.loads('{"name":"nm", "multiplier":1e-9}')),
], arduino_export_macro, arduino_src_dir)]
units += [unitGenerator.Unit('mass', 'kilogram', 3, [
    unitGenerator.UnitLiteral(json.loads('{"name":"t", "multiplier":1e3}')),
    unitGenerator.UnitLiteral(json.loads('{"name":"kg", "multiplier":1e0}')),
    unitGenerator.UnitLiteral(json.loads('{"name":"g", "multiplier":1e-3}')),
    unitGenerator.UnitLiteral(json.loads('{"name":"mg", "multiplier":1e-6}')),
    unitGenerator.UnitLiteral(json.loads('{"name":"ug", "multiplier":1e-9}')),
], arduino_export_macro, arduino_src_dir)]
units += [unitGenerator.Unit('temperature', 'Kelvin', 4, [
    unitGenerator.UnitLiteral(json.loads('{"name":"K", "multiplier":1e0}')),
    unitGenerator.UnitLiteral(json.loads('{"name":"C", "multiplier":1e0, "offset":273.15}')),
], arduino_export_macro, arduino_src_dir)]
units += [unitGenerator.Unit('amount', 'things', 5, [
    unitGenerator.UnitLiteral(json.loads('{"name":"mol", "multiplier":6.02214076e23}')),
    unitGenerator.UnitLiteral(json.loads('{"name":"things", "multiplier":1e0}')),
], arduino_export_macro, arduino_src_dir)]
units += [unitGenerator.Unit('electric_current', 'Ampere', 6, [
    unitGenerator.UnitLiteral(json.loads('{"name":"MA", "multiplier":1e6}')),
    unitGenerator.UnitLiteral(json.loads('{"name":"kA", "multiplier":1e3}')),
    unitGenerator.UnitLiteral(json.loads('{"name":"A", "multiplier":1e-0}')),
    unitGenerator.UnitLiteral(json.loads('{"name":"mA", "multiplier":1e-3}')),
    unitGenerator.UnitLiteral(json.loads('{"name":"uA", "multiplier":1e-6}')),
    unitGenerator.UnitLiteral(json.loads('{"name":"nA", "multiplier":1e-9}')),
], arduino_export_macro, arduino_src_dir)]
units += [unitGenerator.Unit('luminous_intensity', 'candela', 7, [
    unitGenerator.UnitLiteral(json.loads('{"name":"cd", "multiplier":1e-0}')),
], arduino_export_macro, arduino_src_dir)]


# common units
units += [unitGenerator.Unit('energy', 'Joules', 8, [
    unitGenerator.UnitLiteral(json.loads('{"name":"MJ", "multiplier":1e6}')),
    unitGenerator.UnitLiteral(json.loads('{"name":"kJ", "multiplier":1e3}')),
    unitGenerator.UnitLiteral(json.loads('{"name":"J", "multiplier":1e0}')),
    unitGenerator.UnitLiteral(json.loads('{"name":"Nm", "multiplier":1e0}')),
    unitGenerator.UnitLiteral(json.loads('{"name":"kWh", "multiplier":3600000}')),
    unitGenerator.UnitLiteral(json.loads('{"name":"Wh", "multiplier":3600}')),
    unitGenerator.UnitLiteral(json.loads('{"name":"GeV", "multiplier":1.602176565e-10}')),
    unitGenerator.UnitLiteral(json.loads('{"name":"MeV", "multiplier":1.602176565e-13}')),
    unitGenerator.UnitLiteral(json.loads('{"name":"keV", "multiplier":1.602176565e-16}')),
    unitGenerator.UnitLiteral(json.loads('{"name":"eV", "multiplier":1.602176565e-19}')),
], arduino_export_macro, arduino_src_dir)]
units += [unitGenerator.Unit('power', 'Watt', 801, [
    unitGenerator.UnitLiteral(json.loads('{"name":"GW", "multiplier":1e9}')),
    unitGenerator.UnitLiteral(json.loads('{"name":"MW", "multiplier":1e6}')),
    unitGenerator.UnitLiteral(json.loads('{"name":"kW", "multiplier":1e3}')),
    unitGenerator.UnitLiteral(json.loads('{"name":"W", "multiplier":1e0}')),
    unitGenerator.UnitLiteral(json.loads('{"name":"mW", "multiplier":1e-3}')),
], arduino_export_macro, arduino_src_dir)]
units += [unitGenerator.Unit('speed', 'meter per second', 201, [
    unitGenerator.UnitLiteral(json.loads('{"name":"kmph", "multiplier":0.27777777777777777777777777777}')),
    unitGenerator.UnitLiteral(json.loads('{"name":"mps", "multiplier":1e0}')),
], arduino_export_macro, arduino_src_dir)]
units += [unitGenerator.Unit('acceleration', 'meter per second^2', 2011, [
    unitGenerator.UnitLiteral(json.loads('{"name":"G", "multiplier":9.81}')),
    unitGenerator.UnitLiteral(json.loads('{"name":"mps2", "multiplier":1e0}')),
], arduino_export_macro, arduino_src_dir)]
units += [unitGenerator.Unit('area', 'meters^2', 22, [
    unitGenerator.UnitLiteral(json.loads('{"name":"km2", "multiplier":1e6}')),
    unitGenerator.UnitLiteral(json.loads('{"name":"m2", "multiplier":1e0}')),
    unitGenerator.UnitLiteral(json.loads('{"name":"mm2", "multiplier":1e-6}')),
], arduino_export_macro, arduino_src_dir)]
units += [unitGenerator.Unit('force', 'Newton', 32011, [
    unitGenerator.UnitLiteral(json.loads('{"name":"N", "multiplier":1.0}')),
], arduino_export_macro, arduino_src_dir)]
units += [unitGenerator.Unit('momentum', 'kilogram * meter per second', 3201, [
    unitGenerator.UnitLiteral(json.loads('{"name":"kgmps", "multiplier":1.0}')),
], arduino_export_macro, arduino_src_dir)]

unit_strings = []

for unit in units:
    unitGenerator.generate_sources(unit)
    unit_strings += [unit.name]

combinations = []
combinations += [['speed', 'time_si', 'length']]
combinations += [['acceleration', 'time_si', 'speed']]
combinations += [['length', 'length', 'area']]
combinations += [['force', 'length', 'energy']]
combinations += [['power', 'time_si', 'energy']]
combinations += [['momentum', 'speed', 'energy']]
combinations += [['force', 'time_si', 'momentum']]
combinations += [['mass', 'acceleration', 'force']]
combinations += [['mass', 'speed', 'momentum']]
combinations += [['force', 'speed', 'power']]

constants = []
constants += [{'name': 'avogadro_constant', 'value': 6.02214076e23}]
constants += [{'name': 'waterFreezingPoint', 'value': 273.15}]

fillDict = {
    'export_macro': arduino_export_macro,
    'units': unit_strings,
    'disable_std': True,
    'combinations': combinations,
    'constants': constants,
}

unitHeaders.create_headers(
    fillDict,
    True,
    True,
    True,
    True,
    arduino_src_dir,
)
