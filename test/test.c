/*
 * Test
 */
#include <stdio.h>
#include "list.h"

typedef int (*foo_ptr_t)( int );

int test(int)
{
  printf("test!\n");
  return 0;
}

foo_ptr_t foo_ptr_array[] = {
  &test
};

int main(void)
{
  printf("Hello, World!\n");
  uint32_t size = sizeof(foo_ptr_array) / sizeof(foo_ptr_t);
  printf("size: %d\n", size);
  return 0;
}
