//
// Created by eric on 2020/2/15.
//

#define GMOCK_CMAKE_DEMO_HEADER_REPLACE_TEST_H

class HEADER_REPLACE{
public:
  void buildData();
  int getX();
  friend void prepare(HEADER_REPLACE obj);
private:
  int x;
};

void testReplaceHeader();
