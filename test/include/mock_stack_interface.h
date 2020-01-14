//
// Created by yaodi on 2020/1/9.
//
#include "stack_interface.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

template <typename Elem>
class MockStack : public StackInterface<Elem> {
public:
    MOCK_CONST_METHOD0_T(GetSize, int());
    MOCK_METHOD1_T(Push, void(const Elem& x));
};

template <typename Elem>
class TemplateStackTest{
private:
    StackInterface<Elem> *stack;
public:
    TemplateStackTest(StackInterface<Elem> *stack)
    {
        this->stack = stack;
    }

    int testGetSize()
    {
        return stack->GetSize();
    }

    int testPush(const Elem& x)
    {
        stack->Push(x);
        return 1;
    }
};