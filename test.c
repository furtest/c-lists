#include <stdio.h>

#include "base_container.h"
#include "list.h"

int Tcreate_list(void);
int Tappend_list(void);

int main(void){
   int create_list_code = Tcreate_list();
   printf("They were %d error%s when running create_list\n", create_list_code, create_list_code >= 2 ? "s": "");
   Tappend_list();
   return 0;
}

int Tcreate_list(void){
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

   // free (before doing a function for it)
   free((*tList)->array);
   free(*tList);
   free(tList);

   return code;
}

int Tappend_list(void){
   list tList = create_list();
   append_list(tList, INT, 1, 1);
   append_list(tList, FLOAT, 1, 1.2);
   append_list(tList, DOUBLE, 1, 435413.4485454);
   append_list(tList, CHAR, 1, 'a');
   append_list(tList, LONG, 1, 15161256216521);
   return 0;
}