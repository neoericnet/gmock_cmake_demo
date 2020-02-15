//
// Created by eric on 1/8.
//
#include "proxy_header_replace_test.h"
#include "derivedclass_test.h"
#include "namespace_test.h"
#include "header_replace_test.cc"
#include "iostream"
using namespace std;

void prepare(HEADER_REPLACE obj){
  obj.x = 11;
}

void testReplaceHeader(){
  HEADER_REPLACE test;
  test.buildData();
  prepare(test);
  cout << "testReplaceHeader x is :" << test.getX() << endl;
}

// 程序的主函数
int main( )
{
//  testDerivedClass();
//  testNameSpace();
//  using namespace testMain;
//  testNameSpace();
  testReplaceHeader();
}