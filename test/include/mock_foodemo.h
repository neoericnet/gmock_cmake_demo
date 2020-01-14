//
// Created by yaodi on 2020/1/8.
//
#include "foodemo.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

class MockFoo : public FooDemo{
public:
    using BoolAndIntPair = std::pair<bool, int>;
    MOCK_METHOD0(GetPair, BoolAndIntPair());
    MOCK_METHOD2(CheckMap, bool(std::map<int, double>, bool));
    MOCK_METHOD0(Resume, void());
    MOCK_METHOD0(GetTimeOut, int());
};

class FooTest{
private:
    FooDemo *foo;
public:
    FooTest(FooDemo *foo)
    {
        this->foo = foo;
    }

    std::pair<bool, int> testGetPair()
    {
        return foo->GetPair();
    }

    bool testCheckMap(std::map<int, double> reqMap, bool flag)
    {
        return foo->CheckMap(reqMap, flag);
    }

//    int testResume()
//    {
//        foo->Resume();
//        return 1;
//    }
//
//    int testGetTimeOut()
//    {
//        return foo->GetTimeOut();
//    }
};