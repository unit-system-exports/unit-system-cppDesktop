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
    add_project_link_arguments('/MAP', language: 'cpp')
    add_project_link_arguments('/MAPINFO:EXPORTS', language: 'cpp')
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
    units += [['speed', 'common', '201', ['-l', '{"name":"kmph", "multiplier":3.6}', '-l', '{"name":"mps"}']]]
    units += [['acceleration', 'common', '2011', ['-l', '{"name":"G", "multiplier":9.81}', '-l', '{"name":"mps2"}']]]
    
    gen_sources = []
    incdirs = include_directories('.')
    foreach unit : units
        gen_sources += custom_target(
            unit[0] + '.cpp',
            output : [unit[0]+'.cpp', unit[0]+'.hpp'],
            input : 'unitGenerator.py',
            command : [
                pyinstall, '@INPUT@',
                '--name', unit[0],
                '--namespace', unit[1],
                '--unit_identifier', unit[2],
                '--outDir', '@OUTDIR@',
                unit[3],
                '--exportMacro'
            ],
        )
    endforeach
    
    unit_system_common_gen = library(
        'unit-system-common-gen', 
        gen_sources, 
        version : meson.project_version(), 
        soversion : '0',
        include_directories : incdirs,
        dependencies: [dependency('threads'), dependency('unit-system-base', required: true, version : '=' + meson.project_version())],
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
