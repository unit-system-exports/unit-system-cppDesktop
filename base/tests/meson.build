#get catch2
catch2 = dependency('catch2', required: true, fallback:['catch2','catch2_dep'])

#create main_test as library and export the dependency
main_test = static_library(
    'main_test',
    'test-main.cpp', 
    dependencies: catch2
)

main_test_dep = declare_dependency(
    link_with : main_test,
    dependencies : catch2,
    version: meson.project_version(),
)

#create test_helper with commonly used functions
test_incdir = include_directories('.')

test_helper = static_library(
    'test_helper',
    'test_helper.cpp',
    include_directories: test_incdir,
    dependencies: unit_system_base_dep,
)

test_helper_dep = declare_dependency(
    link_with : test_helper,
    version: meson.project_version(),
    include_directories: test_incdir,
    dependencies: unit_system_base_dep,
)

#make both dependencies into one array
deps = [unit_system_base_dep]
deps += main_test_dep
deps += test_helper_dep

tests = [
    'unit_t_test',
    'base_units_test',
]

#create all the tests
foreach test_obj : tests
    exe = executable(
        test_obj, 
        test_obj + '.cpp',
        dependencies: deps
    )
    test(test_obj + ' Test', exe)
endforeach
