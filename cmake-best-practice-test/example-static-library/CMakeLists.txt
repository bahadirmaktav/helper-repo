cmake_minimum_required(VERSION 3.15.0)
project(example_static_lib
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_DEBUG_POSTFIX -d)

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

set(EXAMPLE_STATIC_LIB example_static_lib)

set(INSTALL_ROOT_DIR ${CMAKE_SOURCE_DIR}/install)
if(DEFINED ENV{INSTALL_ROOT_DIR})
    set(INSTALL_ROOT_DIR $ENV{INSTALL_ROOT_DIR})
endif()

set(CMAKE_INSTALL_PREFIX 
    ${INSTALL_ROOT_DIR}/${PROJECT_NAME}/${CMAKE_SYSTEM_NAME}/${CMAKE_BUILD_TYPE}/${PROJECT_VERSION}
)

file(GLOB_RECURSE sources
    ${CMAKE_SOURCE_DIR}/src/*.c
    ${CMAKE_SOURCE_DIR}/src/*.cxx
    ${CMAKE_SOURCE_DIR}/src/*.cpp
)
file(GLOB_RECURSE private_headers
    ${CMAKE_SOURCE_DIR}/src/*.h
    ${CMAKE_SOURCE_DIR}/src/*.hxx
    ${CMAKE_SOURCE_DIR}/src/*.hpp
)
file(GLOB_RECURSE public_headers
    ${CMAKE_SOURCE_DIR}/inc/*.h
    ${CMAKE_SOURCE_DIR}/inc/*.hxx
    ${CMAKE_SOURCE_DIR}/inc/*.hpp
)

add_library(${EXAMPLE_STATIC_LIB} STATIC ${sources})

target_include_directories(${EXAMPLE_STATIC_LIB}
    PRIVATE
        ${CMAKE_SOURCE_DIR}/src
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/inc>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

install(TARGETS ${EXAMPLE_STATIC_LIB}
    EXPORT ${EXAMPLE_STATIC_LIB}Targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(FILES ${public_headers} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(EXPORT ${EXAMPLE_STATIC_LIB}Targets
    FILE ${EXAMPLE_STATIC_LIB}Targets.cmake
    NAMESPACE ${CMAKE_PROJECT_NAME}::
    DESTINATION cmake
)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/${EXAMPLE_STATIC_LIB}ConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(${CMAKE_SOURCE_DIR}/cmake/Config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/${EXAMPLE_STATIC_LIB}Config.cmake
    INSTALL_DESTINATION cmake
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/${EXAMPLE_STATIC_LIB}Config.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/${EXAMPLE_STATIC_LIB}ConfigVersion.cmake
    DESTINATION cmake
)
