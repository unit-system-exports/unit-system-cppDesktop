project(
    'unit-system',
    'cpp',
    default_options : [
        'cpp_std=c++17',
        'warning_level=3',
        'python.install_env=venv'
    ],
    version : '0.7.0',
    meson_version: '>= 1.0.0',
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

#compile modules
pymod = import('python')
pyinstall = pymod.find_installation('python3')

if not pyinstall.dependency().found()
    error('python is needed to generate the code but not found.')
endif

if not get_option('no_pip_install')
    r = run_command(pyinstall.full_path(), '-m', 'pip', 'install', '-r', 'requirements.txt', check: true)
endif

header_install_location = 'include/unit_system'

incdirs = include_directories('.','include')
units = [
    'time_si',
    'length',
    'mass',
    'temperature',
    'amount',
    'electric_current',
    'luminous_intensity',
    'energy',
    'power',
    'speed',
    'acceleration',
    'area',
    'force',
    'momentum',
]
generatedFiles = [
    'unit_system_unit_t.hpp',
    'unit_system_units.hpp',
    'unit_system_combinations.hpp',
    'unit_system_combinations.cpp',
    'unit_system_constants.hpp',
]

gen_sources = []
gen_sources += custom_target(
    'generated_unit_system_headers',
    output: generatedFiles,
    input: 'genSources.py',
    command : [
        pyinstall, '@INPUT@',
        '--outDir', '@OUTDIR@',
        '--exportMacro',
    ],
    install : true,
    install_dir : [
        header_install_location,
        header_install_location,
        header_install_location,
        false,
        header_install_location,
    ],
)

foreach unit : units
    gen_sources += custom_target(
        unit,
        output : ['unit_system_'+unit+'.cpp', 'unit_system_'+unit+'.hpp'],
        input: 'genSources.py',
        command : [
            pyinstall, '@INPUT@',
            '--outDir', '@OUTDIR@',
            '--exportMacro',
        ],
        install : true,
        install_dir: [false, header_install_location],
    )
endforeach


# Allow 'meson build generate -C build' which genereates all sources before full compile
alias_target('generate', gen_sources)

unit_system = library(
    'unit-system', 
    gen_sources, 
    version : meson.project_version(), 
    soversion : '0',
    include_directories : incdirs,
    install : true,
)
    
    
unit_system_dep = declare_dependency(
    include_directories : incdirs,
    link_with : unit_system,
    version: meson.project_version(),
)

install_subdir('include', install_dir : header_install_location, strip_directory : true)

pkg = import('pkgconfig')
pkg.generate(unit_system, subdirs: 'unit_system')

meson.override_dependency('unit-system', unit_system_dep)

if get_option('force_build_tests') or (get_option('build_tests') and not meson.is_subproject())
    subdir('tests')
endif
