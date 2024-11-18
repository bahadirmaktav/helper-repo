## PROJECT CONFIGURATIONS ##
cmake_minimum_required(VERSION 3.23.0)
project(math_types
    VERSION 1.0.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_DEBUG_POSTFIX -d)

option(INSTALL_ROOT_DIR "Sets installation and dependecies root directory." "C:/Program Files")
option(ENABLE_COVERAGE "Enable coverage reporting." OFF)
option(BUILD_TESTS "Builds the tests." OFF)
option(USE_CONAN "Modifies instal configuration for Conan usage (Sets to TRUE by Conan recipe)." FALSE)

## DEPENDENCIES CONFIGURATIONS ##
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

include(Dependencies)
if(ENABLE_COVERAGE)
    include(CodeCoverage)
endif()

## SUBDIRECTORIES ##
add_subdirectory(development)
if(BUILD_TESTS)
    add_subdirectory(tests)
endif()