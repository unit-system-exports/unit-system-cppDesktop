#get gtest
gtest = dependency('gtest', required: true, fallback:['gtest','gtest_dep'])

#make both dependencies into one array
deps = [unit_system_base_dep]
deps += gtest

tests = [
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
