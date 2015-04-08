/*
 * List Implementation
 */

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

void list_push(List *, ListItemType, void *);
void list_print(List *);

List *list_new(void) {
  List *list = (List *)calloc(1, sizeof(List));
  list->push = list_push;
  list->print = list_print;
  return list;
}

void list_push(List *self, ListItemType type, void *data)
{
  ListItem *list_item = list_item_new(type, data);
  if (self->items) {
    self->head = self->head->next = list_item;
  }
  else {
    self->head = self->items = list_item;
  }
  self->count++;
}

void list_print(List *self)
{
  ListItem *item = self->items;
  printf("[");
  while(item) {
    item->print(item);
    item = item->next;
    if (item) { printf(", "); }
  }
  printf("]");
}
