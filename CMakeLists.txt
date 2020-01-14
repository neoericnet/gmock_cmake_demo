cmake_minimum_required(VERSION 2.8)
project(gdemo)

enable_testing()

set(main_srcs
    ${CMAKE_CURRENT_SOURCE_DIR}/main/sample1.cc)

add_subdirectory(main)
add_subdirectory(test)
add_subdirectory(libturtle)
