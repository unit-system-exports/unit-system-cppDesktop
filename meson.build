project(
    'unit-system',
    'cpp',
    default_options : [
        'cpp_std=c++17',
        'warning_level=3'
    ],
    version : '0.5.3',
)

#set windows linker argument
cpp = meson.get_compiler('cpp')
if cpp.get_argument_syntax() == 'msvc'
  if get_option('buildtype') != 'static'
    add_project_arguments('-DUNIT_SYSTEM_EXPORT_MACRO=__declspec(dllexport)', language: 'cpp')
  else
    add_project_arguments('-DUNIT_SYSTEM_EXPORT_MACRO=__declspec(dllimport)', language: 'cpp')
  endif
else
  if target_machine.system() == 'windows'
    add_project_link_arguments('-ldwmapi', language: 'cpp')
  endif
endif

#set the configuration
conf_data = configuration_data()
conf_data.set('HAS_GENERIC_SUPPORT', true)

if get_option('build_base') or get_option('build_full')
    conf_data.set('HAS_BASE_SUPPORT', true)
endif

if get_option('build_common') or get_option('build_full')
    conf_data.set('HAS_COMMON_SUPPORT', true)
endif

configure_file(output : 'unit_system_config.hpp', configuration : conf_data, install: true, install_dir: 'include/unit-system')

#compile modules

subdir('generic')
meson.override_dependency('unit-system-generic', unit_system_generic_dep)

if get_option('build_base') or get_option('build_full')
    subdir('base')
    meson.override_dependency('unit-system-base', unit_system_base_dep)
endif

if get_option('build_common') or get_option('build_full')
    subdir('common')
    meson.override_dependency('unit-system-common', unit_system_common_dep)
endif

if get_option('generateUnits')
    pymod = import('python')
    pyinstall = pymod.find_installation('python3')
    
    if not pyinstall.dependency().found()
        error('python is needed to generate the code but not found.')
    endif
    
    r = run_command(pyinstall.path(), '-m', 'pip', 'install', '-r', 'requirements.txt', check: true)
    
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
        '-l', '{"name":"Celsius", "multiplier":1e0, "offset":273.15}',
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
        '-l', '{"name":"kmph", "multiplier":3.6}',
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
        '-l', '{"name":"Newton", "multiplier":1.0}',
    ]]]
    units += [['momentum', 'kilogram * meter per second', '3201', [
        '-l', '{"name":"kgmps", "multiplier":1.0}',
    ]]]
    
    gen_sources = []
    generatedUnits = []
    incdirs = include_directories('.')
    foreach unit : units
        gen_sources += custom_target(
            unit[0] + '.cpp',
            output : [unit[0]+'.cpp', unit[0]+'.hpp'],
            input : 'unitGenerator.py',
            command : [
                pyinstall, '@INPUT@',
                '--name', unit[0],
                '--baseName', unit[1],
                '--unit_identifier', unit[2],
                '--outDir', '@OUTDIR@',
                unit[3],
                '--exportMacro',
                '--genOstream',
            ],
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
    
    constants = []
    constants += ['--constant', 'avogadro_constant', '6.02214076e23']
    constants += ['--constant', 'waterFreezinPoint', '273.15']
    
    gen_sources += custom_target(
        'units.hpp',
        output: ['units.hpp','combinations.hpp','combinations.cpp','constants.hpp'],
        input: 'unitHeaders.py',
        command : [
            pyinstall, '@INPUT@',
            '--outDir', '@OUTDIR@',
            generatedUnits,
            combinations,
            constants,
            '--exportMacro',
            '--unitHeader',
            '--combinations',
            '--genConstants',
        ],
    )
    
    unit_system_common_gen = library(
        'unit-system-common-gen', 
        gen_sources, 
        version : meson.project_version(), 
        soversion : '0',
        include_directories : incdirs,
        dependencies: [dependency('threads'), dependency('unit-system-generic', required: true, version : '=' + meson.project_version())],
        install : false,
    )
    
endif

#declare the dependency libtrainsim_full
if get_option('build_full') or ( get_option('build_base') and get_option('build_common') )
    unit_system_full_dep = declare_dependency(
        dependencies : [
            dependency('unit-system-generic', required: true, version : '=' + meson.project_version()),
            dependency('unit-system-base', required: true, version : '=' + meson.project_version()),
            dependency('unit-system-common', required: true, version : '=' + meson.project_version()),
        ],
        version: meson.project_version()
    )
    meson.override_dependency('unit-system-full', unit_system_full_dep)
endif
