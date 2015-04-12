/*
 * List Implementation
 */

#include <stdio.h>
#include <stdlib.h>
#ifndef TEST
#include <time.h>
#endif /* TEST */

#include "list.h"

List *list_push(List *, ListItemType, void *);
ListItem *list_pop(List *);
List *list_shuffle(List *);
List *list_flatten(List *);
ListItem *list_shift(List *);
List *list_shift_many(List *, uint32_t);
uint32_t *list_int_array(List *);
void list_free(List *, uint8_t);
void list_print(List *);

List *list_new(void) {
  List *list = (List *)calloc(1, sizeof(List));
  list->push = list_push;
  list->pop = list_pop;
  list->shuffle = list_shuffle;
  list->flatten = list_flatten;
  list->shift = list_shift;
  list->shift_many = list_shift_many;
  list->int_array = list_int_array;
  list->free = list_free;
  list->print = list_print;
  return list;
}

List *list_push(List *self, ListItemType type, void *data)
{
  ListItem *list_item = list_item_new(type, data);
  if (self->items) {
    list_item->previous = self->head;
    self->head = self->head->next = list_item;
  }
  else {
    self->head = self->items = list_item;
  }
  self->count++;

  return self;
}

ListItem *list_pop(List *self)
{
  if (!self->head) {
    return NULL;
  }

  ListItem *item = self->head;
  self->head = item->previous;
  item->previous = NULL;

  self->count--;

  return item;
}

List *list_shuffle(List *self)
{
  if (self->count <= 1) {
    return self;
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
#ifndef TEST
  srand((int)time(NULL));
#endif /* TEST */
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
    item->previous = NULL;
    for(uint32_t i = 1; i < self->count; ++i) {
      item->next = nodes[i];
      item->next->previous = item;
      self->head = item = item->next;
      item->next = NULL;
    }
  }

  free(nodes);
  return self;
}

List *list_flatten(List *self)
{
  ListItem *item = self->items;
  while(item) {
    if (item->type == LIST) {
      List *nested_list = item->data.list;
      list_flatten(nested_list);
      if (item->previous) {
        item->previous->next = nested_list->items;
        nested_list->items->previous = item->previous;
      }
      else {
        self->items = nested_list->items;
        nested_list->items->previous = NULL;
      }
      nested_list->head->next = item->next;
      if (item->next) {
        item->next->previous = nested_list->head;
      }

      self->count += (nested_list->count - 1);
      nested_list->free(nested_list, 0);
    }
    item = item->next;
  }
  return self;
}

ListItem *list_shift(List *self)
{
  if (!self->items) {
    return NULL;
  }

  ListItem *item = self->items;
  self->items = item->next;
  item->next = NULL;

  self->count--;

  return item;
}

List *list_shift_many(List *self, uint32_t count)
{
  if (!self->items) {
    return NULL;
  }

  List *shifted_list = list_new();
  uint32_t index = 0;
  while(index < count) {
    ListItem *item = self->shift(self);
    shifted_list->push(shifted_list, item->type, (void *)&item->data);
    item->free(item);
    ++index;
  }

  return shifted_list;
}

uint32_t *list_int_array(List *self)
{
  uint32_t *array;
  ListItem *item;
  uint32_t index = 0;
  array = (uint32_t *)calloc(1, (self->count * sizeof(uint32_t)));
  item = self->items;
  while(item) {
    array[index++] = item->data.integer;
    item = item->next;
  }
  return array;
}

void list_free(List *self, uint8_t free_items)
{
  if (free_items) {
    ListItem *item = self->items;
    while(item) {
      item->free(item);
      item = item->next;
    }
  }
  free(self);
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
