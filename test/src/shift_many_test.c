#include "test.h"
#include "list.h"

TestStatus shift_many_test(void)
{
  List *list = list_new();
  uint32_t integer_1 = 123, integer_2 = 456, integer_3 = 789;
  LIST_PUSH_INT(list, integer_1);
  LIST_PUSH_INT(list, integer_2);
  LIST_PUSH_INT(list, integer_3);
  printf("Shifting many items from a List");

  {
    List *shifted_list;
    shifted_list = list->shift_many(list, 2);

    if (shifted_list->count != 2) { return FAIL; }
    {
      ListItem *item = shifted_list->items;
      uint32_t index = 0;
      uint32_t expected_array[] = { 123, 456 };
      while(item) {
        if (item->data.integer != expected_array[index]) { return FAIL; }
        item = item->next;
        ++index;
      }
    }

    if (list->count != 1) { return FAIL; }
    if (list->items->data.integer != integer_3) { return FAIL; }
  }

  return PASS;
}
