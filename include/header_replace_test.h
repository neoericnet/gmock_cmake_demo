//
// Created by eric on 2020/2/15.
//

#ifndef GMOCK_CMAKE_DEMO_HEADER_REPLACE_TEST_H
#define GMOCK_CMAKE_DEMO_HEADER_REPLACE_TEST_H

class HEADER_REPLACE{
public:
  void buildData();
  int getX();
private:
  int x;
};

void testReplaceHeader();

#endif //GMOCK_CMAKE_DEMO_HEADER_REPLACE_TEST_H
