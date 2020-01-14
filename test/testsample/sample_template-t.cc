//
// Created by yaodi on 2020/1/9.
//
#include "mock_stack_interface.h"

namespace templatetestdemo{
    TEST(TemplateMockTest, funcGetSize) {
        MockStack<int> stack;
        EXPECT_CALL(stack, GetSize())
            .Times(1);

        TemplateStackTest<int> templateStackTest(&stack);
        templateStackTest.testGetSize();
    }

    TEST(TemplateMockTest, funcPush) {
        MockStack<int> stack;
        EXPECT_CALL(stack, Push(1))
            .Times(1);

        TemplateStackTest<int> templateStackTest(&stack);
        templateStackTest.testPush(1);
    }
}