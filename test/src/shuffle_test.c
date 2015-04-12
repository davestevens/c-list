#include "test.h"
#include "list.h"
#include <stdlib.h>

TestStatus shuffle_test(void)
{
  List *list = list_new();
  uint32_t integer_1 = 123, integer_2 = 456, integer_3 = 789;
  LIST_PUSH_INT(list, integer_1);
  LIST_PUSH_INT(list, integer_2);
  LIST_PUSH_INT(list, integer_3);
  printf("Shuffling a List");
  srand(1234);

  list->shuffle(list);

  if (list->count != 3) { return FAIL; }
  {
    ListItem *item = list->items;
    uint32_t expected_array[] = { 789, 123, 456 };
    uint32_t index = 0;
    while(item) {
      if (item->data.integer != expected_array[index]) { return FAIL; }
      ++index;
      item = item->next;
    }
  }

  return PASS;
}
