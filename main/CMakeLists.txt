include_directories("${PROJECT_SOURCE_DIR}/include")

# add_executable(${PROJECT_NAME}_main
#         main.cc
#         namespace_test.cc
#         derivedclass_test.cc
#         header_replace_test.cc
#         friend_test.cc
#         ${main_srcs}
#         )

# # Specify here the libraries this program depends on
# target_link_libraries(${PROJECT_NAME}_main
#         libturtle
#         )

# add_executable(test_main
#         test.cc
#         )

add_executable(sem_main
        test_sem.cc
        )

target_link_libraries(sem_main
        libpthread
        )