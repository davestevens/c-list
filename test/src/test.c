/*
 * Test
 */
#include <stdio.h>
#include "test.h"
#include "active_tests.h"
#include "list.h"

int main(void)
{
  uint32_t count, passed = 0, failed = 0, pending = 0;

  count = sizeof(test_function_array) / sizeof(test_function_t);

  printf("Running %d tests\n\n", count);

  for(uint32_t i = 0; i < count; ++i) {
    printf("%d: ", i + 1);
    switch(test_function_array[i]())
    {
      case PASS:
        printf(" %s%s", KGRN, "passed");
        passed++;
        break;
      case FAIL:
        printf(" %s%s", KRED, "failed");
        failed++;
        break;
      case PENDING:
        printf(" %s%s", KYEL, "pending");
        pending++;
        break;
    }
    printf("%s\n", KNRM);
  }

  printf("\n");
  printf("passed: %d (%.2f)\n", passed, (float)((float)passed / (float)count));
  printf("failed: %d (%.2f)\n", passed, (float)((float)failed / (float)count));
  printf("pending: %d (%.2f)\n", passed, (float)((float)pending / (float)count));

  return (failed > 0) ? -1 : 0;
}
