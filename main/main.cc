//
// Created by eric on 1/8.
//
#include "proxy_header_replace_test.h"
#include "derivedclass_test.h"
#include "namespace_test.h"
#include "header_replace_test.h"
#include "friend_test.h"
#include "iostream"
using namespace std;

void fun(Point t)
{
  t.a = 100;
  t.b = 2000;
  cout << t.a << "   " << t.b << endl;
}

int testFriend()
{
  Point test;
  test.buildData();
  cout << test.getA() << "   " << test.getB() << endl;
  fun(test);
  cout << test.getA() << "   " << test.getB() << endl;
  return 0;
}

void HEADER_REPLACE::prepare(){
  x = 11;
  cout << "testReplaceHeader x is :" << x << endl;
}

void testReplaceHeader(){
  HEADER_REPLACE test;
  test.buildData();
  cout << "testReplaceHeader x is :" << test.getX() << endl;
  test.prepare();
}

// 程序的主函数
int main( )
{
  testDerivedClass();
  testNameSpace();
  using namespace testMain;
  testNameSpace();
  testFriend();
  testReplaceHeader();
}
