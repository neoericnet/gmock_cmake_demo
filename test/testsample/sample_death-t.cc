#include "gtest/gtest.h"

#define DBUG_ASSERT(A) assert(A)

namespace {

    TEST(BoundedQueueDeathTest, DieIfNotInitialized)
{
//    ::testing::FLAGS_gtest_death_test_style = "threadsafe";
    DBUG_ASSERT(0x00);
}
}
