#include "test.h"
#include "list.h"
#include <stdlib.h>

TestStatus int_array_test(void)
{
  List *list = list_new();
  uint32_t integer_1 = 123, integer_2 = 456, integer_3 = 789;
  LIST_PUSH_INT(list, integer_1);
  LIST_PUSH_INT(list, integer_2);
  LIST_PUSH_INT(list, integer_3);
  printf("Converting to an Integer array");

  uint32_t *array = list->int_array(list);

  {
    uint32_t size = list->count;
    uint32_t expected_array[] = { integer_1, integer_2, integer_3 };
    uint32_t index;
    for(index = 0; index < size; ++index) {
      if (array[index] != expected_array[index]) { return FAIL; }
    }
  }

  return PASS;
}
