//
// Created by eric on 2020/2/14.
//
#include "derivedclass_test.h"
#include "iostream"
using namespace std;

Shape::Shape( int a, int b)
{
  width = a;
  height = b;
}

int Shape::area()
{
  cout << "Parent class area :" <<endl;
  return 0;
}

int Shape::testAccessLocalOrSub(){
  cout << "Parent testAccessLocalOrSub :" <<endl;
  return (width * height);
}

Rectangle::Rectangle( int a, int b):Shape(a, b) { }

int Rectangle::area ()
{
  cout << "Rectangle class area :" <<endl;
  return (width * height);
}

int Rectangle::testAccessLocalOrSub(){
  cout << "Rectangle testAccessLocalOrSub :" <<endl;
  return (width * height);
}

Triangle::Triangle( int a, int b):Shape(a, b) { }

int Triangle::area ()
{
  cout << "Triangle class area :" <<endl;
  return (width * height / 2);
}

int testDerivedClass()
{
  Shape *shape;
  Rectangle rec(10,7);
  Triangle  tri(10,5);

  // 存储矩形的地址
  shape = &rec;
  // 调用矩形的求面积函数 area
  shape->area();
  shape->testAccessLocalOrSub();

  // 存储三角形的地址
  shape = &tri;
  // 调用三角形的求面积函数 area
  shape->area();

  return 0;
}