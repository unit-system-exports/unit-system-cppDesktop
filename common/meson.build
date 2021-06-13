cc = meson.get_compiler('cpp')

sources = [
    'src/speed.cpp',
    'src/acceleration.cpp',
    'src/momentum.cpp',
    'src/force.cpp',
    'src/energy.cpp',
    'src/power.cpp',
]

incdir = include_directories('include','..')

common_deps = [
    dependency('threads'),
    dependency('unit-system-base', required: true, version : '=' + meson.project_version()),
]

unit_system_common = library(
    'unit-system-common', 
    sources, 
    version : meson.project_version(), 
    soversion : '0',
    include_directories : incdir,
    dependencies: common_deps,
    install : true,
)

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
