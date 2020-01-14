#file(GLOB testsample_srcs *.cc)

set(testsample_srcs
    testsample_main.cc
    sample1-t.cc
    sample2-t.cc
    sample3-t.cc
    sample_template-t.cc
#    sample_fake-t.cc
    )

include_directories("${PROJECT_SOURCE_DIR}/include"
        ${PROJECT_SOURCE_DIR}/test/include
        )

ADD_EXECUTABLE(testsample
        ${testsample_srcs}
        ${main_srcs})

TARGET_LINK_LIBRARIES(testsample
    libturtle
    libgtest
    libgmock
)

add_test(NAME testsample
         COMMAND testsample)
