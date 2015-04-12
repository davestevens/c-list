#include "test.h"
#include "list.h"

TestStatus integer_push_test(void)
{
  List *list = list_new();
  uint32_t integer = 123;
  printf("Pushing an Interger");

  list->push(list, INT, (void *)&integer);

  if (list->count != 1) { return FAIL; }
  if (list->items->data.integer != integer) { return FAIL; }

  return PASS;
}
