set(libturtle_srcs
    turtle.cc
)

include_directories("${PROJECT_SOURCE_DIR}/include")

# Declare the library
add_library(libturtle STATIC
    ${libturtle_srcs}
)

# Specify here the include directories exported
# by this library
target_include_directories(libturtle PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
