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

/// @brief Append one or multiple elements to the list
/// @param _list The list in wich to add the elements
/// @param type the type of the elements to add (to add elements of different types the function must be called multiple times)
/// @param count the number of elements to add
/// @param 
/// @return 
int append_list(list* _list, int type, int count, ...){
    // Check if the list's array is full
    if((*_list)->size == (*_list)->memory_size){
        // Reallocate memory (previous size + LIST_GROWTH_FACTOR + the number of elements to add) * the size of the container (element of the array) 
        list nList = realloc((*_list), ((*_list)->memory_size + LIST_GROWTH_FACTOR + count) * sizeof(struct __base_container));
        if(nList == NULL){
            return 1;
        }
        *_list = nList;
        (*_list)->memory_size += LIST_GROWTH_FACTOR;
    }
    va_list ap;
    va_start(ap, count);
    for(int j = 0; j < count; ++j){
        base_container var = {0};
        // Switch to get the correct type
        switch (type){
        case INT:
            int varI = va_arg(ap, int);
            var.type = INT;
            var.content._int = varI;
            break;
        case FLOAT:
            float varF = va_arg(ap, double);
            var.type = FLOAT;
            var.content._float = varF;
            break;
        case DOUBLE:
            double varD = va_arg(ap, double);
            var.type = DOUBLE;
            var.content._double = varD;
            break;
        case CHAR:
            char varC = va_arg(ap, int);
            var.type = CHAR;
            var.content._char = varC;
            break;
        case LONG:
            long varL = va_arg(ap, long);
            var.type = LONG;
            var.content._long = varL;
            break;
        
        default:
            return 2;
            break;
        }
        // Add the base container to the list and increase the size
        (*_list)->array[(*_list)->size] = var;
        (*_list)->size++;
    }
}