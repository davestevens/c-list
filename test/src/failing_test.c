#include "test.h"

TestStatus failing(void)
{
  printf("this test should fail");
  return FAIL;
}
