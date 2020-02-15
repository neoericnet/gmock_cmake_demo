//
// Created by eric on 2020/2/15.
//

#ifndef GMOCK_CMAKE_DEMO_FRIEND_TEST_H
#define GMOCK_CMAKE_DEMO_FRIEND_TEST_H

class Point{
public:
  void buildData();
  int getA();
  int getB();
  friend void fun(Point t);//友元函数
private:
  int a;
protected:
  int b;
};

void fun(Point t);

#endif //GMOCK_CMAKE_DEMO_FRIEND_TEST_H
