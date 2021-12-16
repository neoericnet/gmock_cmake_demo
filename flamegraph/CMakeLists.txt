
add_executable(flamegraph_main
        cpuflamegraph.cc
        )

# Specify here the libraries this program depends on
target_link_libraries(flamegraph_main
        libpthread
        )
