## BUILD CONFIGURATIONS ##
set(MATH_FUNCTIONS math_functions)

file(GLOB_RECURSE sources
    ${CMAKE_SOURCE_DIR}/development/src/*.c
    ${CMAKE_SOURCE_DIR}/development/src/*.cxx
    ${CMAKE_SOURCE_DIR}/development/src/*.cpp
)
file(GLOB_RECURSE public_headers
    ${CMAKE_SOURCE_DIR}/development/include/*.h
    ${CMAKE_SOURCE_DIR}/development/include/*.hxx
    ${CMAKE_SOURCE_DIR}/development/include/*.hpp
)

add_library(${MATH_FUNCTIONS} STATIC ${sources})

target_include_directories(${MATH_FUNCTIONS}
    PRIVATE
        ${CMAKE_SOURCE_DIR}/development/src
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/development/include>
)

target_link_libraries(${MATH_FUNCTIONS}
    PUBLIC
        ${${MATH_TYPES_PACKAGE_NAME}_LIBRARIES}
)

## INTSTALL CONFIGURATIONS ##
install(TARGETS ${MATH_FUNCTIONS}
    EXPORT ${MATH_FUNCTIONS}Targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(FILES ${public_headers} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(EXPORT ${MATH_FUNCTIONS}Targets
    FILE ${MATH_FUNCTIONS}Targets.cmake
    NAMESPACE ${CMAKE_PROJECT_NAME}::
    DESTINATION cmake
)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/${MATH_FUNCTIONS}ConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(${CMAKE_SOURCE_DIR}/cmake/Config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/${MATH_FUNCTIONS}Config.cmake
    INSTALL_DESTINATION cmake
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/${MATH_FUNCTIONS}Config.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/${MATH_FUNCTIONS}ConfigVersion.cmake
    DESTINATION cmake
)
