cc = meson.get_compiler('cpp')

sources = [
    'src/time.cpp',
    'src/length.cpp',
    'src/mass.cpp',
    'src/amount.cpp',
    'src/temperature.cpp',
    'src/electric_current.cpp',
    'src/luminous_intensity.cpp',
    'src/base.cpp',
]

incdir = include_directories('include','..')

core_deps = [
    dependency('threads'),
    dependency('unit-system-generic', required: true, version : '=' + meson.project_version()),
]

deffile = meson.project_source_root() + '/windows-extras/base/unit-system-base-0.def'

cpp = meson.get_compiler('cpp')
if cpp.get_argument_syntax() == 'msvc'
    unit_system_base = library(
        'unit-system-base', 
        sources, 
        version : meson.project_version(), 
        soversion : '0',
        include_directories : incdir,
        vs_module_defs: deffile,
        dependencies: core_deps,
        install : true,
    )
else
    unit_system_base = library(
        'unit-system-base', 
        sources, 
        version : meson.project_version(), 
        soversion : '0',
        include_directories : incdir,
        dependencies: core_deps,
        install : true,
    )
endif



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
