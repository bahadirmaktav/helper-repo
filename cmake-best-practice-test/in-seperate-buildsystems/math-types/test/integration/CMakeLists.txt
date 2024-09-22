add_executable(integration_dummy_test integration_dummy_test.cpp)

target_link_libraries(integration_dummy_test 
    PRIVATE
        GTest::gtest_main
)

gtest_discover_tests(integration_dummy_test)