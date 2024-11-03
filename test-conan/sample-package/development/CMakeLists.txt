add_library(hello ${CMAKE_SOURCE_DIR}/development/src/hello.cpp)
target_include_directories(hello PUBLIC ${CMAKE_SOURCE_DIR}/development/include)



set_target_properties(hello PROPERTIES PUBLIC_HEADER "${CMAKE_SOURCE_DIR}/development/include/hello.h")
install(TARGETS hello)