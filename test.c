#include <stdio.h>

#include "base_container.h"
#include "list.h"

int Tcreate_list();

int main(void){
   Tcreate_list();
   return 0;
}

int Tcreate_list(){
   printf("Test for create list :\n");
   int code = 0;
   list tList = create_list();
   if((*tList)->size != 0){
      printf("Error a new list size is %zu not 0.\n", (*tList)->size);
      code++;
   }
   if((*tList)->memory_size != LIST_DEFAULT_ALLOCATED_SPACE){
      printf("Error wrong value for memory size it is %zu when it should be %zu\n", (*tList)->memory_size, LIST_DEFAULT_ALLOCATED_SPACE);
      code++;
   }
   if(! code){ 
      printf("All good no error for create_list\n");
   }
   return code;
}