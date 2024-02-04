# Methods of the list type in python

- append(_x_) : add _x_ at the end of the list
- extend(_iterable_) : extend the list with all the elements of the iterable
- insert(_i_, _x_) : insert _x_ at the index _i_ in the list
- remove(_x_) : remove the first element with the value _x_ in the list, exception if no element with this value
- pop(_i_) : remove the element at index i from the list and returns its value, in python _i_ is facultative if called with no arguments the function removes the last argument
- clear() : removes all elements from the list
- index(_x_, _start_, _end_) : returns the index of the first element of the list with the value _x_ between _start_ and _end_, the index is relative to the actual start of the list not _start_, in python _start_ and _end_ are facultative
- count(_x_) : return the number of elements with the value _x_ in the list
- sort() : sort the list
- reverse() : reverses the list
- copy() : returns a copy of the list