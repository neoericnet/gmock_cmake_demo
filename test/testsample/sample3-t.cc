//
// Created by yaodi on 2020/1/8.
// test for
//

#include "mock_foodemo.h"

namespace footestdemo{
    TEST(FooMockTest, funcGetPair) {
        MockFoo foo;
        EXPECT_CALL(foo, GetPair())
            .Times(1);

        FooTest fooTest(&foo);
        fooTest.testGetPair();
    }

    TEST(FooMockTest, funcCheckMap) {
        MockFoo foo;
        std::map<int, double> reqMap;
        bool flag = true;
        EXPECT_CALL(foo, CheckMap(reqMap, flag))
                .Times(1);

        FooTest fooTest(&foo);
        fooTest.testCheckMap(reqMap, flag);
    }
}