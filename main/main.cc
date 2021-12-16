//
// Created by eric on 1/8.
//
#include "proxy_header_replace_test.h"
#include "derivedclass_test.h"
#include "namespace_test.h"
#include "header_replace_test.h"
#include "friend_test.h"
#include "iostream"
#include <sys/time.h>
#include <unistd.h>
#include "vector"
#include <stdio.h>
#include <iostream>
#include "stdlib.h"


#include <sstream>

using namespace std;

static const string table_name_prefix=("__");

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

static inline int64_t GetUnixTimeUs() {
  struct timeval tp;
  gettimeofday(&tp, nullptr);
  return (((int64_t) tp.tv_sec) * 1000000 + (int64_t) tp.tv_usec);
}

void test_time()
{
  int64_t timeu = GetUnixTimeUs();
  //5s
  sleep(5);
  printf("timeu=%llums, data=%d\n", (GetUnixTimeUs() - timeu)/1000, 1 % 99);

//  timeval now;
//  gettimeofday(&tp, nullptr);

  struct tm *local;
  time_t t;
  t=time(NULL);
  local=localtime(&t);
  printf("Local month=%d, hour=%d\n", local->tm_mon, local->tm_hour);
  printf("Local time=%s\n", ctime(&t));
  printf("Local time_t=%lu\n", t);
  local=gmtime(&t);
  printf("UTC hour is: %d\n",local->tm_hour);
  printf("UTC time=%s\n", ctime(&t));
  printf("UTC time_t=%lu\n", t);
}

class Test_object{
public:
    Test_object(std::string name)
    {
      m_name= name;
    }
    ~Test_object()
    {

    }
public:
    std::string m_name;
};

void test_vector()
{
  std::vector<Test_object*> test_vector;
  test_vector.push_back(new Test_object("aaa"));
  test_vector.push_back(new Test_object("bbb"));
  test_vector.push_back(new Test_object("ccc"));

  printf("test_vector size=%lu\n", test_vector.size());

  for(int i=0; i<test_vector.size(); i++)
  {
    printf("%s\n", test_vector[i]->m_name.c_str());
    delete test_vector[i];
  }

  std::vector<Test_object*>::iterator test_vector_iterator;
  for (test_vector_iterator= test_vector.begin();
       test_vector_iterator!= test_vector.end();
       test_vector_iterator++) {
    Test_object* test_object= (*test_vector_iterator);
  }

  printf("test_vector size=%lu\n", test_vector.size());

  test_vector.clear();

  printf("test_vector size=%lu\n", test_vector.size());
}

void test_append_char()
{
  const char * storage_name= "innodb";
  int table_id= 0;
  char* table_name= new char[table_name_prefix.size() + strlen(storage_name) + sizeof(table_id)];
  sprintf(table_name, "%s%s_%d", table_name_prefix.c_str(), storage_name, table_id);
  printf("table_name=%s\n", table_name);

  ostringstream oss;
  oss << table_name_prefix << storage_name << "_" << table_id;
  cout << oss.str() << endl;

  char str[10]={0};
  printf("str len=%d\n",sizeof(str));
  int nLen=snprintf(str,sizeof(str),"123456789012345678");
  printf("str=%s\n",str);
  printf("nLen=%d\n",nLen);

  char* new_table_name= new char[table_name_prefix.size() + strlen(storage_name) + sizeof(table_id) + 1];

  snprintf(new_table_name, sizeof(new_table_name), "%s%s_%d", table_name_prefix.c_str(), storage_name, table_id);

  printf("table_name=%s\n", table_name);
}

class A
{
public:
  void strcpy()
  {
    printf("call A::strcpy\n");
  }

  void strcat()
  {
    printf("call A::strcat\n");
  }
};

void dispatcher(A * p, void (A::*pmf)())
{
  (p->*pmf)(); //将成员函数绑定到pmf
}

void test_func_ptr()
{
  A a1;
  A *p= &a1;
  void (A::*pmf)() = &A::strcpy;
  dispatcher(p, pmf);

//  void (A::*PMA[2])(char *, const char *)= {&A::strcpy, &A::strcat};

}

void test_ostringstream()
{
    //need read elf
    char* mem= new char[1];
    size_t		m_size= 10;
    ostringstream oss;
    oss << "Disabling @@core_file because @@innodb_buffer_pool_in_core_file is disabled, "
           "yet madvise(" << (void *)(mem) << "," << static_cast<const void *>(mem) << "," << m_size << "," << "MADV_DODUMP) failed with "
            << strerror(errno);
    cout << oss.str() << endl;

    printf("madvise(%x,%d,%s)", mem, m_size, "MADV_DODUMP");

    delete mem;
}

void test_string_size()
{
  char            sun_path[104];
  std::string aa("123456");
  std::string bb("1234567");

  std::cout << "sun_path size=" << sizeof(sun_path) << std::endl;
  std::cout << "aa size=" << aa.size() << std::endl;
  std::cout << "bb size=" << bb.size() << std::endl;
    std::cout << "strlen size=" << strlen("CREATE TABLE t1 (a int COMMENT '.')") << std::endl;
    std::cout << "strlen size=" << strlen("CREATE TABLE t1 (a int COMMENT '测试.')") << std::endl;
    std::cout << "strlen size=" << strlen("123") << std::endl;
}

struct byte_pad1
{
    int b;
    short c;
    char a;
};

int test_byte_pad()
{
    cout << sizeof(byte_pad1) << endl; //
    return 0;
}

class Data
{

};

int test_ref()
{
    void f(Data&  data);  // 1, data is l-ref
    void f(Data&& data);  // 2, data is r-ref
    Data   data;

    Data&  data1 = data;             // OK
    Data&  data11 = Data{};           // not compile: invalid binding
    Data&& data2 = Data{};           // OK
    Data&& data21 = data;             // not compile: invalid binding
    Data&& data22 = std::move(data);  // OK

    f(data);    // 1, data is lvalue
    f(Data{});  // 2, data is rvalue
    f(data1);   // 1, data1 is l-ref type and lvalue
    f(data22);   // 1, data2 is r-ref type but lvalue
    return 0;
}

// 程序的主函数
int main( )
{
  printf("1111\n");

//  testDerivedClass();
//  testNameSpace();
//  using namespace testMain;
//  testNameSpace();
//  testFriend();
//  testReplaceHeader();
//  test_time();
//  test_vector();
//  test_append_char();
//  test_func_ptr();
//    test_ostringstream();
//  test_string_size();
//    test_byte_pad();
    // test_ref();
    test_sem();
}
