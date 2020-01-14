//
// Created by yaodi on 2020/1/13.
//
#include "fakefoo.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using ::testing::_;
using ::testing::Invoke;

class MockFoo : public FooTest {
public:
    // Normal mock method definitions using Google Mock.
    MOCK_METHOD1(DoThis, char(int n));
//    MOCK_METHOD2(DoThat, void(const char* s, int* p));

    // Delegates the default actions of the methods to a FakeFoo object.
    // This must be called *before* the custom ON_CALL() statements.
    void DelegateToFake() {
        ON_CALL(*this, DoThis(_))
                .WillByDefault(Invoke(&fake_, &FakeFoo::DoThis));
//        ON_CALL(*this, DoThat(_, _))
//                .WillByDefault(Invoke(&fake_, &FakeFoo::DoThat));
    }
private:
    FakeFoo fake_;  // Keeps an instance of the fake in the mock.
};