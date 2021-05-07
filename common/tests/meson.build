#make both dependencies into one array
deps = [unit_system_common_dep]
deps += main_test_dep
deps += test_helper_dep

tests = [
    'speed_test',
    'acceleration_test',
    'momentum_test',
    'force_test',
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
