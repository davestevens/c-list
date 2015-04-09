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
  uint32_t count;
  void (*push)(struct list_t *, ListItemType, void *);
  void (*shuffle)(struct list_t *);
  void (*flatten)(struct list_t *);
  uint32_t *(*int_array)(struct list_t *);
  void (*print)(struct list_t *);
} List;

List *list_new(void);

#endif /* _LIST */
