project(
    'unit-system',
    'cpp',
    default_options : ['cpp_std=c++17'],
    version : '0.1.0'
)

#set the configuration
conf_data = configuration_data()
conf_data.set('HAS_BASE_SUPPORT', true)

#if get_option('build_video') or get_option('build_full')
#    conf_data.set('HAS_VIDEO_SUPPORT', true)
#endif

configure_file(output : 'unit_system_config.hpp', configuration : conf_data, install: true, install_dir: 'include/unit-system')

#compile modules
subdir('base')
meson.override_dependency('unit-system-base', unit_system_base_dep)

#if get_option('build_video') or get_option('build_full')
#    subdir('video')
#    meson.override_dependency('libtrainsim-video', libtrainsim_video_dep)
#endif

#declare the dependency libtrainsim_full
if get_option('build_full')
    unit_system_full_dep = declare_dependency(
        dependencies : [
            dependency('unit-system-base', required: true, version : '=' + meson.project_version()),
            #dependency('libtrainsim-video', required: true, version : '=' + meson.project_version()),
        ],
        version: meson.project_version()
    )
    meson.override_dependency('unit-system-full', unit_system_full_dep)
endif
