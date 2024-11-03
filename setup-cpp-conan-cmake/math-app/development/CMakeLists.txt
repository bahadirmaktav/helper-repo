## BUILD CONFIGURATIONS ##
set(MATH_APP math_app)

file(GLOB_RECURSE sources
    ${CMAKE_SOURCE_DIR}/development/src/*.c
    ${CMAKE_SOURCE_DIR}/development/src/*.cxx
    ${CMAKE_SOURCE_DIR}/development/src/*.cpp
)

add_library(${MATH_APP} STATIC ${sources})

target_include_directories(${MATH_APP}
    PRIVATE
        ${CMAKE_SOURCE_DIR}/development/src
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/development/include>
)

target_link_libraries(${MATH_APP}
    PRIVATE
        ${${MATH_FUNCTIONS_PACKAGE_NAME}_LIBRARIES}
)

## INTSTALL CONFIGURATIONS ##
install(TARGETS ${MATH_APP}
    EXPORT ${MATH_APP}Targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(DIRECTORY include/ 
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    FILES_MATCHING PATTERN "*.h" 
                   PATTERN "*.hpp" 
                   PATTERN "*.hxx"
)

# install(EXPORT ${MATH_APP}Targets
#     FILE ${MATH_APP}Targets.cmake
#     NAMESPACE ${CMAKE_PROJECT_NAME}::
#     DESTINATION cmake
# )

# write_basic_package_version_file(
#     ${CMAKE_CURRENT_BINARY_DIR}/${MATH_APP}ConfigVersion.cmake
#     VERSION ${PROJECT_VERSION}
#     COMPATIBILITY SameMajorVersion
# )

# configure_package_config_file(${CMAKE_SOURCE_DIR}/cmake/Config.cmake.in
#     ${CMAKE_CURRENT_BINARY_DIR}/${MATH_APP}Config.cmake
#     INSTALL_DESTINATION cmake
# )

# install(FILES
#     ${CMAKE_CURRENT_BINARY_DIR}/${MATH_APP}Config.cmake
#     ${CMAKE_CURRENT_BINARY_DIR}/${MATH_APP}ConfigVersion.cmake
#     DESTINATION cmake
# )
