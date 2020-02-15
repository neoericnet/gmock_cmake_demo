//
// Created by eric on 2020/2/14.
//

#include "namespace_test.h"
#include <iostream>
using namespace std;

void NameSpaceTest::setX(int x) {
  this->x = x;
}

void NameSpaceTest::setY(int x) {
  this->y = y;
}

int NameSpaceTest::getXOrY() {
  cout << "x is :" << x <<endl;
  return x;
}

int testMain::NameSpaceTest::getXOrY() {
  cout << "y is :" << y <<endl;
  return y;
}

void testNameSpace(){
  NameSpaceTest test;
  test.setX(1);
  test.setY(2);
  test.getXOrY();
}