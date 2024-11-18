## BUILD CONFIGURATIONS ##
set(MATH_TYPES math_types)
set(ECEF_UNIT_TESTS ecef_unit_tests)
set(ENU_UNIT_TESTS enu_unit_tests)
set(QUARTERNION_UNIT_TESTS quarternion_unit_tests)

add_executable(${ECEF_UNIT_TESTS} ${CMAKE_CURRENT_SOURCE_DIR}/coordinates/ECEFUnitTests.cpp)
target_link_libraries(${ECEF_UNIT_TESTS} PRIVATE GTest::gtest ${MATH_TYPES} gcov)

# add_executable(${ENU_UNIT_TESTS} ${CMAKE_CURRENT_SOURCE_DIR}/coordinates/ENUUnitTests.cpp)
# target_link_libraries(${ENU_UNIT_TESTS} PRIVATE GTest::gtest ${MATH_TYPES})

# add_executable(${QUARTERNION_UNIT_TESTS} ${CMAKE_CURRENT_SOURCE_DIR}/algebra/QuarternionUnitTests.cpp)
# target_link_libraries(${QUARTERNION_UNIT_TESTS} PRIVATE GTest::gtest ${MATH_TYPES})

gtest_discover_tests(${ECEF_UNIT_TESTS})
# gtest_discover_tests(${ENU_UNIT_TESTS})
# gtest_discover_tests(${QUARTERNION_UNIT_TESTS})