//
// Created by yaodi on 2020/1/13.
//
#include "string.h"

class FooTest {
public:
    virtual ~FooTest() {}
    virtual char DoThis(int n) = 0;
    virtual void DoThat(const char* s, int* p) = 0;
};

class FakeFoo : public Foo {
public:
    virtual char DoThis(int n) {
        return (n > 0) ? '+' :
               (n < 0) ? '-' : '0';
    }

    virtual void DoThat(const char* s, int* p) {
        *p = strlen(s);
    }
};