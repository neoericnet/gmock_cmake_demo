#include "mock_turtle.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "painter.h"                        // #1

namespace {
    TEST(PainterTest, CanDrawSomething) {
        MockTurtle turtle;                              // #2
        EXPECT_CALL(turtle, PenDown())                  // #3
                .Times(1);

        Painter painter(&turtle);                       // #4

        EXPECT_TRUE(painter.DrawCircle(0, 0, 10));      // #5
    }
}

