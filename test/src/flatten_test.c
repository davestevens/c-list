#include "test.h"
#include "list.h"
#include <stdlib.h>

TestStatus flatten_test(void)
{
  List *list = list_new();
  List *nested_list = list_new();
  uint32_t integer_1 = 1, integer_2 = 2, integer_3 = 3, integer_4 = 4;
  list->push(list, INT, (void *)&integer_1);
  list->push(list, INT, (void *)&integer_2);
  list->push(list, LIST, (void *)nested_list);
  nested_list->push(nested_list, INT, (void *)&integer_3);
  nested_list->push(nested_list, INT, (void *)&integer_4);
  printf("Flattening a List");

  list->flatten(list);

  if (list->count != 4) { return FAIL; }
  {
    ListItem *item = list->items;
    uint32_t expected_array[] = { integer_1, integer_2, integer_3, integer_4 };
    uint32_t index = 0;
    while(item) {
      if (item->data.integer != expected_array[index]) { return FAIL; }
      ++index;
      item = item->next;
    }
  }

  return PASS;
}
