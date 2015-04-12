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
  struct list_t* (*push)(struct list_t *, ListItemType, void *);
  struct list_item_t* (*pop)(struct list_t *);
  struct list_t* (*shuffle)(struct list_t *);
  struct list_t* (*flatten)(struct list_t *);
  struct list_item_t* (*shift)(struct list_t *);
  uint32_t *(*int_array)(struct list_t *);
  void (*free)(struct list_t *, uint8_t);
  void (*print)(struct list_t *);
} List;

List *list_new(void);

#define LIST_PUSH(list, type, value) list->push(list, type, (void *)value)
#define LIST_PUSH_INT(list, value)              \
  {                                             \
    uint32_t v = value;                         \
    LIST_PUSH(list, INT, &v);                   \
  }
#define LIST_PUSH_LIST(list, value) LIST_PUSH(list, LIST, value)
#define LIST_POP(list) list->pop(list)
#define LIST_SHUFFLE(list) list->shuffle(list)
#define LIST_FLATTEN(list) list->flatten(list)
#define LIST_SHIFT(list) list->shift(list)
#define LIST_INT_ARRAY(list) list->int_array(list)
#define LIST_FREE(list) list->free(list, 1)
#define LIST_PRINT(list) list->print(list)

#endif /* _LIST */
