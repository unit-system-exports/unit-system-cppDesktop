cc = meson.get_compiler('cpp')

sources = [
   'src/unit_t.cpp',
]

incdir = include_directories('include','..')

core_deps = [
    dependency('threads'),
]
unit_system_base = library(
    'unit-system-base', 
    sources, 
    version : meson.project_version(), 
    soversion : '0',
    include_directories : incdir,
    dependencies: core_deps,
    install : true,
)

unit_system_base_dep = declare_dependency(
    include_directories : incdir,
    link_with : unit_system_base,
    dependencies : core_deps,
    version: meson.project_version(),
)

install_subdir('include', install_dir : 'include/unit-system', strip_directory : true)

pkg = import('pkgconfig')
pkg.generate(unit_system_base)

if get_option('force_build_tests') or (get_option('build_tests') and not meson.is_subproject())
    subdir('tests')
endif
