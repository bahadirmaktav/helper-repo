add_executable(unit_dummy_test unit_dummy_test.cpp)

target_link_libraries(unit_dummy_test 
    PRIVATE
        GTest::gtest_main
)

gtest_discover_tests(unit_dummy_test)