//
// Created by eric on 2020/2/14.
//

#ifndef GMOCK_CMAKE_DEMO_DERIVEDCLASSTEST_H
#define GMOCK_CMAKE_DEMO_DERIVEDCLASSTEST_H

class Shape {
protected:
  int width, height;
public:
  Shape( int a=0, int b=0);

  int testAccessLocalOrSub();

  virtual int area();
};

class Rectangle: public Shape{
public:
  Rectangle( int a=0, int b=0);
  int area ();
  int testAccessLocalOrSub();
};

class Triangle: public Shape{
public:
  Triangle( int a=0, int b=0);
  int area ();
};

int testDerivedClass();

#endif //GMOCK_CMAKE_DEMO_DERIVEDCLASSTEST_H
