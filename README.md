# c-list

I want to implement something similar to how Arrays work in Ruby, in C.

Example:
```ruby
list = [4, [1, 2, 3], 5]
list << 6
list << [7, 8, 9]

puts list         # => [4, [1, 2, 3], 5, 6, [7, 8, 9]]
puts list.flatten # => [4, 1, 2, 3, 5, 6, 7, 8, 9]
puts list.shuffle  # => [6, 4, [1, 2, 3], [7, 8, 9], 5]
```

## Current Implementation
Some basic functionality has been defined.
- `List`s can have many `ListItem`s.
- `ListItem`s can be either a `uint32_t` or a `List`.
- `shuffle` is at the `List` level and randomizes the order of it `ListItem`s.
- `flatten` will return a single `List` of `uint32_t`s.

```c
#include "list.h"

/* Create a new List */
List *list = list_new();

/* Add some data */
LIST_PUSH_INT(list, 123);
LIST_PUSH_INT(list, 456);
LIST_PUSH_INT(list, 789);

/* `list` now contains: [123, 456, 789] */

/* Create another List */
List *another_list = list_new();

/* Add some data */
LIST_PUSH_INT(another_list, 321);
LIST_PUSH_INT(another_list, 654);

/* Add `another_list` to `list` */
LIST_PUSH_LIST(list, another_list);

/* `list` now contains: [123, 456, 789, [321, 654]] */

/* Randomize the order of `list` */
LIST_SHUFFLE(list);

/* `list` now contains: [789, [321, 654], 123, 456] */

/* Flatten `list` */
LIST_FLATTEN(list);

/* `list` now contains: [789, 321, 654, 123, 456] */

/* Shift from a `list` */
ListItem *item = LIST_SHIFT(list);

/* `list` now contains: [321, 654, 123, 456] */
/* `item` is a `ListItem` with an integer value of 789 */
```

## TODO
- [x] free
- [x] push
- [x] count
- [x] shuffle
- [x] flatten
- [x] int_array
 - [ ] ensure flattened list first?
 - [ ] skip non-int types?
- [ ] pop
- [x] shift
- [ ] unshift
