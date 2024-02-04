# Goal
Create a python like implementation of the list data structure (resizable array and much more).
Two do so we use two data structures and a variety of functions explained below.

# Data structures 
## [Base container](base_container.h)
A data container making it possible to store any type of data in an array using two rows
- An enumeration which is used to store the type of the data
- An union which allows us to store any type of data without wasting too much memory, the size of the union will be the size of the largest element, we loose some space when storing data that takes less space like char

## [List](list.h)
The type list is a pointer to a pointer to a struct __list, this struct contains three rows
- memory_size : the space currently allocated to the list's array (precisely the number of elements that can be stored)
- size : the number of elements currently stored in the list
- array : a pointer to the array of base_container containing the data

# Functions
## [create_list](list.c#L11) 
This function create the list by allocating memory and initializing the variables.
## [append_list](list.c#L42)
Add a defined number of elements of the same type at the end of the list.
(Looks like extend but I want to make extend accept a list as parameter) 