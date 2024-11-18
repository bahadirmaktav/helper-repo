## GOOGLE TEST CONFIGURATIONS ##
list(APPEND CMAKE_PREFIX_PATH "${INSTALL_ROOT_DIR}/googletest/lib/cmake/GTest")

find_package(GTest)

enable_testing()
include(GoogleTest)
include(CTest)

## SUBDIRECTORIES ##
add_subdirectory(unit)
add_subdirectory(integration)