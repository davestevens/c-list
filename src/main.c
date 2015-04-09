#include <stdio.h>
#include "list.h"

#define list_push(list, type, value) list->push(list, type, (void *)value)
#define list_push_int(list, value) list_push(list, INT, &value)
#define list_push_list(list, value) list_push(list, LIST, value)
#define list_print(list) list->print(list)
#define list_shuffle(list) list->shuffle(list)
#define list_flatten(list) list->flatten(list)

int main(void)
{
  List *list_1, *list_2, *list_3;
  uint32_t input;
  list_1 = list_new();
  input = 11;
  list_push_int(list_1, input);

  list_2 = list_new();

  list_3 = list_new();
  input = 31;
  list_push_int(list_3, input);
  input = 32;
  list_push_int(list_3, input);
  list_push_list(list_2, list_3);

  input = 21;
  list_push_int(list_2, input);
  input = 22;
  list_push_int(list_2, input);
  input = 23;
  list_push_int(list_2, input);
  list_push_list(list_1, list_2);

  input = 12;
  list_push_int(list_1, input);

  /* list_shuffle(list_2); */

  list_print(list_1);
  printf("\n");

  list_flatten(list_1);
  list_print(list_1);
  printf("\n");

  return 0;
}
