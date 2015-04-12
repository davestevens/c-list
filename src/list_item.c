/*
 * List Item Implementation
 */

#include <stdio.h>
#include <stdlib.h>

#include "list_item.h"

void list_item_free(ListItem *);
void list_item_print(ListItem *);

ListItem *list_item_new(ListItemType type, void *data)
{
  ListItem *list_item = (ListItem *)calloc(1, sizeof(ListItem));
  list_item->free = list_item_free;
  list_item->print = list_item_print;
  list_item->type = type;

  switch(type)
  {
    case INT:
      list_item->data.integer = *((uint32_t *)data);
      break;
    case LIST:
      list_item->data.list = (List *)data;
      break;
  }
  return list_item;
}

void list_item_free(ListItem *self)
{
  if (self->type == LIST) {
    LIST_FREE(self->data.list);
  }
  free(self);
}

void list_item_print(ListItem *self)
{
  switch(self->type)
  {
    case INT:
      printf("%d", self->data.integer);
      break;
    case LIST:
      self->data.list->print(self->data.list);
      break;
  }
}
