#include <stdio.h>
#include "list.h"

int main(void)
{
  List *list = list_new();
  uint32_t input = 123;
  list->push(list, INT, (void *)&input);
  input = 456;
  list->push(list, INT, (void *)&input);
  List *nested_list = list_new();
  input = 789;
  nested_list->push(nested_list, INT, (void *)&input);
  list->push(list, LIST, nested_list);
  nested_list->print(nested_list);
  list->print(list);

  return 0;
}
