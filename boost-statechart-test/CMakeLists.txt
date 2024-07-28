cmake_minimum_required(VERSION 3.5.0)
project(boost_statechart_test VERSION 0.1.0 LANGUAGES C CXX)

# Find the Boost library
find_package(Boost 1.71.0)

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find Boost")
endif()

include_directories(${Boost_INCLUDE_DIRS})

add_executable(statechart_eg1 statechart_eg1.cpp)
add_executable(statechart_eg2 statechart_eg2.cpp)

# Include Boost headers
# target_include_directories(boost_statechart_test PRIVATE ${Boost_INCLUDE_DIRS})

# Link Boost libraries
# TODO(MBM): Boost statchart library is header-only. Can you remove the line below?
# target_link_libraries(boost_statechart_test PRIVATE ${Boost_LIBRARIES})