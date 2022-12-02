#make both dependencies into one array
deps = [
    dependency('unit-system', required: true),
    dependency('gtest', required: true, fallback:['gtest','gtest_dep'])
]

tests = [
    'unit_t_test',
    'base_units_test',
    'common_test',
]

#create all the tests
foreach test_obj : tests
    exe = executable(
        test_obj, 
        test_obj + '.cpp',
        dependencies: deps,
        link_depends: gen_sources,
    )
    test(
        test_obj + ' Test',
        exe,
        protocol: 'gtest',
    )
endforeach
