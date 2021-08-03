project(
    'unit-system',
    'cpp',
    default_options : ['cpp_std=c++17'],
    version : '0.5.1',
)

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
