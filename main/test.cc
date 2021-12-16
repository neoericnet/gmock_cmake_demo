#include "iostream"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#define NullS		(char *) 0

using namespace std;

static const string RECYCLEBIN_TABLE_NAME_SPLIT=("_");

char *strxnmov(char *dst, size_t len, const char *src, ...)
{
  va_list pvar;
  char *end_of_dst=dst+len;

  va_start(pvar,src);
  while (src != NullS)
  {
    do
    {
      if (dst == end_of_dst)
        goto end;
    }
    while ((*dst++ = *src++));
    dst--;
    src = va_arg(pvar, char *);
  }
  end:
  *dst=0;
  va_end(pvar);
  return dst;
}

char *my_stpnmov(char *dst, const char *src, size_t n)
{
  while (n-- != 0) {
    if (!(*dst++ = *src++)) {
      return (char*) dst-1;
    }
  }
  return dst;
}

void test_append_char()
{
  const char* storage_name= "InnoDb";
  char storage_name_lower[5 + 1];
  char new_table_name[8 + 1];
  int table_id= 43;
  uint32_t i=0;
  const char* test_copy= "test";
  size_t test_copy_len= strlen(test_copy);
  char* new_test_str= NULL;

  my_stpnmov(storage_name_lower, storage_name, sizeof(storage_name_lower) - 1);
  for(; (i<(sizeof(storage_name_lower) - 1) && (storage_name_lower[i] != '\0')); i++)
  {
    printf("new_table_name=%c,i=%d\n", storage_name_lower[i], i);
    storage_name_lower[i]= tolower(storage_name_lower[i]);
  }

  snprintf(new_table_name,
              sizeof(new_table_name) - 1,
              "%s%s%s%s%d",
              RECYCLEBIN_TABLE_NAME_SPLIT.c_str(),
              RECYCLEBIN_TABLE_NAME_SPLIT.c_str(),
              storage_name_lower,
              RECYCLEBIN_TABLE_NAME_SPLIT.c_str(),
              table_id
  );

  printf("new_table_name=%s\n", new_table_name);
  printf("storage_name size=%d\n", sizeof(storage_name));
  printf("storage_name len=%d\n", strlen(storage_name));
  printf("new_table_name end=%d\n", new_table_name[sizeof(new_table_name) - 1]);
  printf("new_table_name end-1=%d\n", new_table_name[sizeof(new_table_name) - 2]);

  new_test_str= (char*) malloc(test_copy_len - 1);
  strncpy(new_test_str, test_copy, test_copy_len - 1);
  printf("test_copy_len=%d\n", test_copy_len);
  printf("test_copy=%s\n", test_copy);
  printf("new_test_str=%s\n", new_test_str);
  printf("test_copy last char=%d\n", test_copy[test_copy_len]);
  printf("new_test_str last char=%d\n", new_test_str[test_copy_len - 1]);
}

int main()
{
  printf("1111\n");
  test_append_char();
}
