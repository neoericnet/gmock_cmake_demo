//
// Created by eric on 2020/2/14.
//

#ifndef GMOCK_CMAKE_DEMO_NAMESPACE_TEST_H
#define GMOCK_CMAKE_DEMO_NAMESPACE_TEST_H


class NameSpaceTest {
public:
  void setX(int x);
  void setY(int x);

  int getXOrY();
private:
  int x,y;
};

namespace testMain{

  class NameSpaceTest {
  public:
    void setX(int x);
    void setY(int x);

    int getXOrY();
  private:
    int x,y;
  };
}

void testNameSpace();

#endif //GMOCK_CMAKE_DEMO_NAMESPACE_TEST_H
