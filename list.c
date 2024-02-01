#include <stdarg.h>

#include "list.h"
#include "base_container.h"

/// @brief Create a new list
/// @details The function first creates a struct __list and then a list with a pointer to this struct.
/// @details We then initialize the size to 0 and allocate memory to the array
/// @return The list (pointer to a struct __list)
list create_list(void){
    // Creation of the list
    struct __list rNewList= {0};
    list newList = &rNewList;
    newList->size = 0;
    newList->array = calloc(LIST_DEFAULT_ALLOCATED_SPACE, sizeof(struct __base_container));
    if(newList->array == NULL){
        newList->memory_size = 0;
        return NULL;
    }
    newList->memory_size = LIST_DEFAULT_ALLOCATED_SPACE;
    return newList;
}

int append_list(list* _list, int type, int count, ...){
    if((*_list)->size == (*_list)->memory_size){
        list nList = realloc((*_list), ((*_list)->memory_size + LIST_GROWTH_FACTOR) * sizeof(struct __base_container));
        if(nList == NULL){
            return 1;
        }
        *_list = nList;
    }
    va_list ap;
    va_start(ap, count);
    for(int j = 0; j < count; ++j){
        switch (type){
        case INT:
            int varI = va_arg(ap, int);
            break;
        case FLOAT:
            float varF = va_arg(ap, double);
            break;
        case DOUBLE:
            double varD = va_arg(ap, double);
            break;
        case CHAR:
            char varC = va_arg(ap, int);
            break;
        case LONG:
            long varL = va_arg(ap, long);
            break;
        
        default:
            break;
        }
    }
}