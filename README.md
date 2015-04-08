# c-list

I want to implement something similar to how Arrays work in Ruby, in C.

Example:
```ruby
list = [4, [1, 2, 3], 5]
list << 6
list << [7, 8, 9]

puts list         # => [4, [1, 2, 3], 5, 6, [7, 8, 9]]
puts list.flatten # => [4, 1, 2, 3, 5, 6, 7, 8, 9]
put list.shuffle  # => [6, 4, [1, 2, 3], [7, 8, 9], 5]
```
