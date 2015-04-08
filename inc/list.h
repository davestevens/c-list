/*
 * List
 */

#ifndef _LIST
#define _LIST

#include <stdint.h>

#include "list_item.h"
#include "list_types.h"

typedef struct list_t
{
  struct list_item_t *items;
  struct list_item_t *head;
  void (*push)(struct list_t *, ListItemType, void *);
  void (*print)(struct list_t *);
} List;

List *list_new(void);

#endif /* _LIST */
