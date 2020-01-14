//
// Created by yaodi on 2020/1/13.
//

#include "mock_fakefoo.h"

namespace fakefootest{
    using ::testing::_;

    TEST(FakeTest, funcTest) {
        MockFoo foo;
        foo.DelegateToFake(); // Enables the fake for delegation.

        // No action specified, meaning to use the default action.
        EXPECT_CALL(foo, DoThis(5));
//        EXPECT_CALL(foo, DoThat(_, _));


        foo.DoThis(5);
//        int n = 0;
//        EXPECT_EQ('+', foo.DoThis(5));  // FakeFoo::DoThis() is invoked.
//        foo.DoThat("Hi", &n);           // FakeFoo::DoThat() is invoked.
//        EXPECT_EQ(2, n);
    }
}