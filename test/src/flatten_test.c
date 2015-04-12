#include "test.h"
#include "list.h"
#include <stdlib.h>

TestStatus flatten_1_test(void)
{
  List *list = list_new();
  List *nested_list = list_new();
  uint32_t integer_1 = 1, integer_2 = 2, integer_3 = 3, integer_4 = 4;
  LIST_PUSH_INT(list, integer_1);
  LIST_PUSH_INT(list, integer_2);
  LIST_PUSH_LIST(list, nested_list);
  LIST_PUSH_INT(nested_list, integer_3);
  LIST_PUSH_INT(nested_list, integer_4);
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

TestStatus flatten_2_test(void)
{
  List *list = list_new();
  List *nested_list_1 = list_new();
  List *nested_list_2 = list_new();
  LIST_PUSH_INT(nested_list_1, 1);
  LIST_PUSH_INT(nested_list_1, 2);
  LIST_PUSH_INT(nested_list_1, 3);
  LIST_PUSH_INT(nested_list_2, 5);
  LIST_PUSH_INT(nested_list_2, 6);
  LIST_PUSH_INT(nested_list_2, 7);
  LIST_PUSH_LIST(list, nested_list_1);
  LIST_PUSH_INT(list, 4);
  LIST_PUSH_LIST(list, nested_list_2);
  printf("Flattening a List");

  list->flatten(list);

  if (list->count != 7) { return FAIL; }
  {
    ListItem *item = list->items;
    uint32_t expected_array[] = { 1, 2, 3, 4, 5, 6, 7 };
    uint32_t index = 0;
    while(item) {
      if (item->data.integer != expected_array[index]) { return FAIL; }
      ++index;
      item = item->next;
    }
  }

  return PASS;
}

TestStatus flatten_3_test(void)
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
  printf("Flattening a List");

  list->flatten(list);

  if (list->count != 6) { return FAIL; }
  {
    ListItem *item = list->items;
    uint32_t expected_array[] = { 1, 2, 3, 4, 5, 6 };
    uint32_t index = 0;
    while(item) {
      if (item->data.integer != expected_array[index]) { return FAIL; }
      ++index;
      item = item->next;
    }
  }

  return PASS;
}
