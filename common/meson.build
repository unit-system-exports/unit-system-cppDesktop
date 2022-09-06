cc = meson.get_compiler('cpp')

sources = [
    'src/area.cpp',
    'src/speed.cpp',
    'src/acceleration.cpp',
    'src/momentum.cpp',
    'src/force.cpp',
    'src/energy.cpp',
    'src/power.cpp',
    'src/common.cpp',
]

incdir = include_directories('include','..')

common_deps = [
    dependency('threads'),
    dependency('unit-system-base', required: true, version : '=' + meson.project_version()),
]

deffile = meson.project_source_root() + '/windows-extras/common/unit-system-common-0.def'
cpp = meson.get_compiler('cpp')
if cpp.get_argument_syntax() == 'msvc'
    unit_system_common = library(
        'unit-system-common', 
        sources, 
        version : meson.project_version(), 
        soversion : '0',
        include_directories : incdir,
        vs_module_defs: deffile,
        dependencies: common_deps,
        install : true,
    )
else
    unit_system_common = library(
        'unit-system-common', 
        sources, 
        version : meson.project_version(), 
        soversion : '0',
        include_directories : incdir,
        dependencies: common_deps,
        install : true,
    )
endif

unit_system_common_dep = declare_dependency(
    include_directories : incdir,
    link_with : unit_system_common,
    dependencies : common_deps,
    version: meson.project_version(),
)

install_subdir('include', install_dir : 'include/unit-system', strip_directory : true)

pkg = import('pkgconfig')
pkg.generate(unit_system_common)

if get_option('force_build_tests') or (get_option('build_tests') and not meson.is_subproject())
    subdir('tests')
endif
