/*
 * List Item
 */

#ifndef _LIST_ITEM
#define _LIST_ITEM

#include "list.h"
#include "list_types.h"

typedef struct list_item_t
{
  ListItemType type;
  union
  {
    uint32_t integer;
    struct list_t *list;
  } data;
  struct list_item_t *next;
  void (*print)(struct list_item_t *);
} ListItem;

ListItem *list_item_new(ListItemType, void *);

#endif
