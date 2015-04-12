#include "test.h"
#include "list.h"

TestStatus list_push_test(void)
{
  List *list = list_new();
  List *nested_list = list_new();
  uint32_t integer = 123;
  LIST_PUSH_INT(nested_list, integer);
  printf("Pushing a List");

  list->push(list, LIST, (void *)nested_list);

  if (list->count != 1) { return FAIL; }
  if (list->items->data.list != nested_list) { return FAIL; }

  return PASS;
}
