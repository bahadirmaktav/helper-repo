## PROJECT SETTINGS ##
cmake_minimum_required(VERSION 3.23.0)
project(math_types
    VERSION 1.0.0
    LANGUAGES CXX
)

## CXX SETTINGS ##
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_DEBUG_POSTFIX -d)

## COMMON CONFIGURATIONS ##
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(INSTALL_ROOT_DIR "Sets installation and dependecies root directory." "C:/Program Files")
option(BUILD_TESTS "Builds the tests." OFF)
option(USE_CONAN "Modifies instal configuration for Conan usage (Sets to TRUE by Conan recipe)." FALSE)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

## DEPENDENCIES CONFIGURATIONS ##
include(Dependencies)

## INSTALL CONFIGURATIONS ##
include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

set(CMAKE_INSTALL_PREFIX 
    ${INSTALL_ROOT_DIR}/${PROJECT_NAME}/${CMAKE_SYSTEM_NAME}/${CMAKE_SYSTEM_VERSION}/v${PROJECT_VERSION}
)

## SUBDIRECTORIES ##
add_subdirectory(development)
if(BUILD_TESTS)
    add_subdirectory(test)
endif()