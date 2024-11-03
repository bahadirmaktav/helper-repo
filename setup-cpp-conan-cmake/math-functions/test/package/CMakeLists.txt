## PROJECT SETTINGS ##
cmake_minimum_required(VERSION 3.19.0)
project(math_functions_package_test LANGUAGES CXX)

## CXX SETTINGS ##
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_DEBUG_POSTFIX -d)

## DEPENDENCIES CONFIGURATIONS ##
find_package(math_functions CONFIG REQUIRED)

## BUILD CONFIGURATIONS ##
add_executable(math_functions_package_test ${CMAKE_CURRENT_SOURCE_DIR}/MathFunctionsPackageTest.cpp)

target_link_libraries(math_functions_package_test math_functions::math_functions)