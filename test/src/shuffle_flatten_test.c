#include "test.h"
#include "list.h"
#include <stdlib.h>

TestStatus shuffle_flatten_test(void)
{
  List *list = list_new();
  List *nested_list_1 = list_new();
  List *nested_list_2 = list_new();
  List *nested_list_3 = list_new();
  LIST_PUSH_INT(nested_list_1, 1);
  LIST_PUSH_INT(nested_list_1, 2);

  LIST_PUSH_INT(nested_list_2, 3);
  LIST_PUSH_INT(nested_list_2, 4);

  LIST_PUSH_INT(nested_list_3, 5);
  LIST_PUSH_INT(nested_list_3, 6);

  LIST_PUSH_LIST(list, nested_list_1);
  LIST_PUSH_LIST(list, nested_list_2);
  LIST_PUSH_LIST(list, nested_list_3);
  printf("Flattening a shuffled List");

  list->shuffle(list);
  list->flatten(list);

  if (list->count != 6) { return FAIL; }
  {
    ListItem *item = list->items;
    uint32_t expected_array[] = { 3, 4, 1, 2, 5, 6 };
    uint32_t index = 0;
    while(item) {
      if (item->data.integer != expected_array[index]) { return FAIL; }
      ++index;
      item = item->next;
    }
  }

  return PASS;
}
