#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void)
{
  List *list_1, *list_2, *list_3;
  list_1 = list_new();
  LIST_PUSH_INT(list_1, 11);

  list_2 = list_new();

  LIST_PUSH_INT(list_2, 21);
  LIST_PUSH_INT(list_2, 22);
  LIST_PUSH_INT(list_2, 23);
  list_3 = list_new();
  LIST_PUSH_INT(list_3, 31);
  LIST_PUSH_INT(list_3, 32);
  LIST_PUSH_LIST(list_2, list_3);
  LIST_PUSH_LIST(list_1, list_2);

  LIST_PUSH_INT(list_1, 12);

  LIST_SHUFFLE(list_2);

  LIST_PRINT(list_1);
  printf("\n");

  LIST_FLATTEN(list_1);
  LIST_PRINT(list_1);
  printf("\n");

  uint32_t *a = LIST_INT_ARRAY(list_1);

  for(uint32_t i=0;i<list_1->count;++i) {
    printf("%d: %d\n", i, a[i]);
  }

  free(a);

  return 0;
}
