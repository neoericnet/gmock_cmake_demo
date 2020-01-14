include_directories("${PROJECT_SOURCE_DIR}/include")

add_executable(${PROJECT_NAME}_main
        main.cc
        ${main_srcs}
        )

# Specify here the libraries this program depends on
target_link_libraries(${PROJECT_NAME}_main
        libturtle
        )