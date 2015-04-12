#include "test.h"
#include "list.h"

TestStatus shift_test(void)
{
  List *list = list_new();
  uint32_t integer_1 = 123, integer_2 = 456;
  LIST_PUSH_INT(list, integer_1);
  LIST_PUSH_INT(list, integer_2);
  printf("Shifting from a List");

  {
    ListItem *item;
    item = list->shift(list);

    if (item->data.integer != integer_1) { return FAIL; }
    if (list->count != 1) { return FAIL; }
    if (list->items->data.integer != integer_2) { return FAIL; }
  }

  return PASS;
}
