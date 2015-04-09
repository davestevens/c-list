/*
 * List Implementation
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "list.h"

void list_push(List *, ListItemType, void *);
void list_shuffle(List *);
void list_flatten(List *);
void list_print(List *);

List *list_new(void) {
  List *list = (List *)calloc(1, sizeof(List));
  list->push = list_push;
  list->shuffle = list_shuffle;
  list->flatten = list_flatten;
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

void list_shuffle(List *self)
{
  if (self->count <= 1) {
    return;
  }

  /* Create an Array of List Item pointers */
  void **nodes = (void *)calloc(self->count, sizeof(void *));
  {
    ListItem *item = self->items;
    while(item) {
      *(nodes++) = item;
      item = item->next;
    }
  }
  nodes -= self->count;

  /* Shuffle the Array */
  srand((int)time(NULL));
  {
    for (uint32_t index = 0; index < self->count; ++index)
    {
      uint32_t other = rand() % self->count;
      void *temp = nodes[other];
      nodes[other] = nodes[index];
      nodes[index] = temp;
    }
  }

  /* Use shuffled array to set the list items next values */
  {
    ListItem *item;
    self->items = item = nodes[0];
    for(uint32_t i = 1; i < self->count; ++i) {
      item->next = nodes[i];
      self->head = item = item->next;
      item->next = (void *)0;
    }
  }

  free(nodes);
}

void list_flatten(List *self)
{
  ListItem *item = self->items;
  ListItem *previous = (void *)0;
  while(item) {
    if (item->type == LIST) {
      List *nested_list = item->data.list;
      if (previous) {
        previous->next = nested_list->items;
      }
      else {
        self->items = nested_list->items;
      }
      nested_list->head->next = item->next;

      nested_list->flatten(nested_list);
      /*
       * TODO: free the nested list object
       */
    }
    previous = item;
    item = item->next;
  }
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
