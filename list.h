#ifndef LIST_HEADER
#define LIST_HEADER

#include <stdlib.h>
#include "base_container.h"

#define LIST_DEFAULT_ALLOCATED_SPACE ((size_t) 20)
#define LIST_GROWTH_FACTOR ((size_t) 10)

struct __list {
    size_t memory_size;
    size_t size;
    base_container* array;
};

typedef struct __list* list;

list create_list(void);
int append_list(list* _list, int type, int count, ...);

#endif