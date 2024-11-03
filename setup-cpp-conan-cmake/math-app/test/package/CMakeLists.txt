## PROJECT SETTINGS ##
cmake_minimum_required(VERSION 3.19.0)
project(math_app_package_test LANGUAGES CXX)

## CXX SETTINGS ##
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_DEBUG_POSTFIX -d)

## DEPENDENCIES CONFIGURATIONS ##
find_package(math_app CONFIG REQUIRED)

## BUILD CONFIGURATIONS ##
add_executable(math_app_package_test ${CMAKE_CURRENT_SOURCE_DIR}/MathAppPackageTest.cpp)

target_link_libraries(math_app_package_test math_app::math_app)