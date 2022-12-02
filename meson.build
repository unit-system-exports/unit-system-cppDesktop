project(
    'unit-system',
    'cpp',
    default_options : [
        'cpp_std=c++17',
        'warning_level=3'
    ],
    version : '0.6.0',
)

#set windows linker argument
cpp = meson.get_compiler('cpp')
if target_machine.system() == 'windows'
  if get_option('buildtype') != 'static'
    add_project_arguments('-DUNIT_SYSTEM_EXPORT_MACRO=__declspec(dllexport)', language: 'cpp')
  else
    add_project_arguments('-DUNIT_SYSTEM_EXPORT_MACRO=__declspec(dllimport)', language: 'cpp')
  endif
endif

if cpp.get_argument_syntax() != 'msvc'
    add_project_link_arguments('-ldwmapi', language: 'cpp')
endif


#compile modules
pymod = import('python')
pyinstall = pymod.find_installation('python3')

if not pyinstall.dependency().found()
    error('python is needed to generate the code but not found.')
endif

if not get_option('no_pip_install')
    r = run_command(pyinstall.path(), '-m', 'pip', 'install', '-r', 'requirements.txt', check: true)
endif

header_install_location = 'include/unit_system'

units = []
# base units
units += [['time_si', 'seconds', '1', [
    '-l', '{"name":"a", "multiplier":31536000000}',
    '-l', '{"name":"d", "multiplier":86400000}',
    '-l', '{"name":"h", "multiplier":3600}',
    '-l', '{"name":"minute", "multiplier":60}',
    '-l', '{"name":"s", "multiplier":1e0}',
    '-l', '{"name":"ms", "multiplier":1e-3}',
    '-l', '{"name":"ns", "multiplier":1e-6}',
    '-l', '{"name":"us", "multiplier":1e-9}',
    '-l', '{"name":"fs", "multiplier":1e-12}',
]]]
units += [['length', 'meter', '2', [
    '-l', '{"name":"km", "multiplier":1e3}',
    '-l', '{"name":"m", "multiplier":1e0}',
    '-l', '{"name":"dm", "multiplier":1e-1}',
    '-l', '{"name":"cm", "multiplier":1e-2}',
    '-l', '{"name":"mm", "multiplier":1e-3}',
    '-l', '{"name":"um", "multiplier":1e-6}',
    '-l', '{"name":"nm", "multiplier":1e-9}',
]]]
units += [['mass', 'kilogram', '3', [
    '-l', '{"name":"t", "multiplier":1e3}',
    '-l', '{"name":"kg", "multiplier":1e0}',
    '-l', '{"name":"g", "multiplier":1e-3}',
    '-l', '{"name":"mg", "multiplier":1e-6}',
    '-l', '{"name":"ug", "multiplier":1e-9}',
]]]
units += [['temperature', 'Kelvin', '4', [
    '-l', '{"name":"K", "multiplier":1e0}',
    '-l', '{"name":"C", "multiplier":1e0, "offset":273.15}',
]]]
units += [['amount', 'things', '5', [
    '-l', '{"name":"mol", "multiplier":6.02214076e23}',
    '-l', '{"name":"things", "multiplier":1e0}',
]]]
units += [['electric_current', 'Ampere', '6', [
    '-l', '{"name":"MA", "multiplier":1e6}',
    '-l', '{"name":"kA", "multiplier":1e3}',
    '-l', '{"name":"A", "multiplier":1e-0}',
    '-l', '{"name":"mA", "multiplier":1e-3}',
    '-l', '{"name":"uA", "multiplier":1e-6}',
    '-l', '{"name":"nA", "multiplier":1e-9}',
]]]
units += [['luminous_intensity', 'candela', '7', [
    '-l', '{"name":"cd", "multiplier":1e-0}',
]]]


# common units
units += [['energy', 'Joules', '8', [
    '-l', '{"name":"MJ", "multiplier":1e6}',
    '-l', '{"name":"kJ", "multiplier":1e3}',
    '-l', '{"name":"J", "multiplier":1e0}',
    '-l', '{"name":"Nm", "multiplier":1e0}',
    '-l', '{"name":"kWh", "multiplier":3600000}',
    '-l', '{"name":"Wh", "multiplier":3600}',
    '-l', '{"name":"GeV", "multiplier":1.602176565e-10}',
    '-l', '{"name":"MeV", "multiplier":1.602176565e-13}',
    '-l', '{"name":"keV", "multiplier":1.602176565e-16}',
    '-l', '{"name":"eV", "multiplier":1.602176565e-19}',
]]]
units += [['power', 'Watt', '801', [
    '-l', '{"name":"GW", "multiplier":1e9}',
    '-l', '{"name":"MW", "multiplier":1e6}',
    '-l', '{"name":"kW", "multiplier":1e3}',
    '-l', '{"name":"W", "multiplier":1e0}',
    '-l', '{"name":"mW", "multiplier":1e-3}',
]]]
units += [['speed', 'meter per second', '201', [
    '-l', '{"name":"kmph", "multiplier":0.27777777777777777777777777777}',
    '-l', '{"name":"mps", "multiplier":1e0}',
]]]
units += [['acceleration', 'meter per second^2', '2011', [
    '-l', '{"name":"G", "multiplier":9.81}',
    '-l', '{"name":"mps2", "multiplier":1e0}',
]]]
units += [['area', 'meters^2', '22', [
    '-l', '{"name":"km2", "multiplier":1e6}',
    '-l', '{"name":"m2", "multiplier":1e0}',
    '-l', '{"name":"mm2", "multiplier":1e-6}',
]]]
units += [['force', 'Newton', '32011', [
    '-l', '{"name":"N", "multiplier":1.0}',
]]]
units += [['momentum', 'kilogram * meter per second', '3201', [
    '-l', '{"name":"kgmps", "multiplier":1.0}',
]]]

gen_sources = []
generatedUnits = []
incdirs = include_directories('.','include')

gen_sources += custom_target(
    'unit_system_unit_t.hpp',
    output: [
        'unit_system_unit_t.hpp',
    ],
    input: 'unitHeaders.py',
    command : [
        pyinstall, '@INPUT@',
        '--outDir', '@OUTDIR@',
        '--exportMacro',
        '--genUnit_t',
    ],
    install : true,
    install_dir: header_install_location,
)

foreach unit : units
    gen_sources += custom_target(
        unit[0],
        output : ['unit_system_'+unit[0]+'.cpp', 'unit_system_'+unit[0]+'.hpp'],
        input : 'unitGenerator.py',
        command : [
            pyinstall, '@INPUT@',
            '--name', unit[0],
            '--baseName', unit[1],
            '--unit_identifier', unit[2],
            '--outDir', '@OUTDIR@',
            unit[3],
            '--exportMacro',
        ],
        install : true,
        install_dir: [false, header_install_location],
    )
    
    generatedUnits += '--unit'
    generatedUnits += unit[0]
endforeach

combinations = []
combinations += ['--combine','speed','time_si','length']
combinations += ['--combine','acceleration','time_si','speed']
combinations += ['--combine','length','length','area']
combinations += ['--combine','force','length','energy']
combinations += ['--combine','power','time_si','energy']
combinations += ['--combine','momentum','speed','energy']
combinations += ['--combine','force','time_si','momentum']
combinations += ['--combine','mass','acceleration','force']
combinations += ['--combine','mass','speed','momentum']
combinations += ['--combine','force','speed','power']

constants = []
constants += ['--constant', 'avogadro_constant', '6.02214076e23']
constants += ['--constant', 'waterFreezingPoint', '273.15']

gen_sources += custom_target(
    'unit_system_constants.hpp',
    output: [
        'unit_system_constants.hpp',
    ],
    input: 'unitHeaders.py',
    command : [
        pyinstall, '@INPUT@',
        '--outDir', '@OUTDIR@',
        generatedUnits,
        constants,
        '--exportMacro',
        '--genConstants',
    ],
    install : true,
    install_dir: header_install_location,
)

gen_sources += custom_target(
    'unit_system_units.hpp',
    output: [
        'unit_system_units.hpp',
    ],
    input: 'unitHeaders.py',
    command : [
        pyinstall, '@INPUT@',
        '--outDir', '@OUTDIR@',
        generatedUnits,
        '--exportMacro',
        '--unitHeader',
    ],
    install : true,
    install_dir: header_install_location,
)
gen_sources += custom_target(
    'unit_system_combinations.cpp',
    output: [
        'unit_system_combinations.hpp',
        'unit_system_combinations.cpp',
    ],
    input: 'unitHeaders.py',
    command : [
        pyinstall, '@INPUT@',
        '--outDir', '@OUTDIR@',
        generatedUnits,
        combinations,
        '--exportMacro',
        '--unitHeader',
        '--combinations',
    ],
    install : true,
    install_dir: [header_install_location, false],
)

# Allow 'meson build generate -C build' which genereates all sources before full compile
alias_target('generate', gen_sources)

unit_system_gen = library(
    'unit-system-common-gen', 
    gen_sources, 
    version : meson.project_version(), 
    soversion : '0',
    include_directories : incdirs,
    install : true,
)
    
    
unit_system_dep = declare_dependency(
    include_directories : incdirs,
    link_with : unit_system_gen,
    version: meson.project_version(),
)

install_subdir('include', install_dir : header_install_location, strip_directory : true)

pkg = import('pkgconfig')
pkg.generate(unit_system_gen, subdirs: 'unit_system')

meson.override_dependency('unit-system', unit_system_dep)

if get_option('force_build_tests') or (get_option('build_tests') and not meson.is_subproject())
    subdir('tests')
endif
