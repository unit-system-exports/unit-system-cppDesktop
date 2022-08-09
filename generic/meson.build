cc = meson.get_compiler('cpp')

sources = [
]

incdir = include_directories('include','..')

generic_deps = [
    dependency('threads'),
]

unit_system_generic = library(
    'unit-system-generic', 
    sources, 
    version : meson.project_version(), 
    soversion : '0',
    include_directories : incdir,
    dependencies: generic_deps,
    install : true,
)

unit_system_generic_dep = declare_dependency(
    include_directories : incdir,
    link_with : unit_system_generic,
    dependencies : generic_deps,
    version: meson.project_version(),
)

install_subdir('include', install_dir : 'include/unit-system', strip_directory : true)

pkg = import('pkgconfig')
pkg.generate(unit_system_generic)

if get_option('force_build_tests') or (get_option('build_tests') and not meson.is_subproject())
    #subdir('tests')
endif
