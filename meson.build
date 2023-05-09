project(
    'unit-system',
    'cpp',
    default_options : [
        'cpp_std=c++17',
        'warning_level=3'
    ],
    version : '0.7.0',
    meson_version: '>= 1.1.0',
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


incdirs = include_directories('include')
sources = [
    
    'src/time_si.cpp',
    
    'src/length.cpp',
    
    'src/mass.cpp',
    
    'src/temperature.cpp',
    
    'src/amount.cpp',
    
    'src/electric_current.cpp',
    
    'src/luminous_intensity.cpp',
    
    'src/energy.cpp',
    
    'src/power.cpp',
    
    'src/speed.cpp',
    
    'src/acceleration.cpp',
    
    'src/area.cpp',
    
    'src/force.cpp',
    
    'src/momentum.cpp',
    
    'src/combinations.cpp',
]

unit_system = library(
    'unit-system', 
    sources,
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

pkg = import('pkgconfig')
pkg.generate(unit_system, subdirs: 'unit_system')


    install_headers('include/unit_system/time_si.hpp', subdir : 'unit-system')

    install_headers('include/unit_system/length.hpp', subdir : 'unit-system')

    install_headers('include/unit_system/mass.hpp', subdir : 'unit-system')

    install_headers('include/unit_system/temperature.hpp', subdir : 'unit-system')

    install_headers('include/unit_system/amount.hpp', subdir : 'unit-system')

    install_headers('include/unit_system/electric_current.hpp', subdir : 'unit-system')

    install_headers('include/unit_system/luminous_intensity.hpp', subdir : 'unit-system')

    install_headers('include/unit_system/energy.hpp', subdir : 'unit-system')

    install_headers('include/unit_system/power.hpp', subdir : 'unit-system')

    install_headers('include/unit_system/speed.hpp', subdir : 'unit-system')

    install_headers('include/unit_system/acceleration.hpp', subdir : 'unit-system')

    install_headers('include/unit_system/area.hpp', subdir : 'unit-system')

    install_headers('include/unit_system/force.hpp', subdir : 'unit-system')

    install_headers('include/unit_system/momentum.hpp', subdir : 'unit-system')


install_headers('include/unit_system/combinations.hpp', subdir : 'unit-system')
install_headers('include/unit_system/constants.hpp', subdir : 'unit-system')
install_headers('include/unit_system/unit_t.hpp', subdir : 'unit-system')
install_headers('include/unit_system/units.hpp', subdir : 'unit-system')
install_headers('include/unit_system/std_implements.hpp', subdir : 'unit-system')
install_headers('include/unit_system.hpp')

meson.override_dependency('unit-system', unit_system_dep)

build_tests = get_option('build_tests').enable_auto_if(not meson.is_subproject())
if build_tests.enabled()
    subdir('tests')
endif