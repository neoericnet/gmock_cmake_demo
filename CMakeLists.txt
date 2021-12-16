cmake_minimum_required(VERSION 2.8)
project(gmock_cmake_demo)

enable_testing()

set(main_srcs
    ${CMAKE_CURRENT_SOURCE_DIR}/main/sample1.cc)

add_subdirectory(main)
# add_subdirectory(test)
# add_subdirectory(libturtle)
# add_subdirectory(flamegraph)
