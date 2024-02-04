#include <stdio.h>

#include "base_container.h"
#include "list.h"

int Tcreate_list(void);
int Tappend_list(void);

int main(void){
   int create_list_code = Tcreate_list();
   printf("They was %d error%s when running create_list\n", create_list_code, create_list_code >= 2 ? "s": "");
   int append_list_code = Tappend_list();
   printf("They was %d error%s when running append_list\n", append_list_code, append_list_code >= 2 ? "s": "");
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
   // TODO check that all values are properly stored

   free_list(tList);
   return code;
}

int Tappend_list(void){
   printf("Test for append list :\n");
   int code = 0;
   list tList = create_list();

   size_t list_size = 0;

   list_size++;
   int test_value_int = 42;
   append_list(tList, INT, 1, test_value_int);
   if((*tList)->array[list_size - 1].type != INT){
      printf("Error wrong type when appending the list.\n");
      code++;
   }
   if((*tList)->array[list_size - 1].content._int != test_value_int){
      printf("Error wrong value stored.\n");
      code++;
   }
   if((*tList)->size != list_size){
      printf("Error the size is wrong");
      code++;
   }

   list_size++;
   float test_value_float = 3.14;
   append_list(tList, FLOAT, 1, test_value_float);
   if((*tList)->array[list_size - 1].type != FLOAT){
      printf("Error wrong type when appending the list.\n");
      code++;
   }
   if((*tList)->array[list_size - 1].content._float != test_value_float){
      printf("Error wrong value stored.\n");
      code++;
   }
   if((*tList)->size != list_size){
      printf("Error the size is wrong");
      code++;
   }

   list_size++;
   double test_value_double = 435413.4485454;
   append_list(tList, DOUBLE, 1, test_value_double);
   if((*tList)->array[list_size - 1].type != DOUBLE){
      printf("Error wrong type when appending the list.\n");
      code++;
   }
   if((*tList)->array[list_size - 1].content._double != test_value_double){
      printf("Error wrong value stored.\n");
      code++;
   }
   if((*tList)->size != list_size){
      printf("Error the size is wrong");
      code++;
   }

   list_size++;
   char test_value_char = 'h';
   append_list(tList, CHAR, 1, test_value_char);
   if((*tList)->array[list_size - 1].type != CHAR){
      printf("Error wrong type when appending the list.\n");
      code++;
   }
   if((*tList)->array[list_size - 1].content._char != test_value_char){
      printf("Error wrong value stored.\n");
      code++;
   }
   if((*tList)->size != list_size){
      printf("Error the size is wrong");
      code++;
   }
   
   list_size++;
   long test_value_long = 987654321123;
   append_list(tList, LONG, 1, test_value_long);
   if((*tList)->array[list_size - 1].type != LONG){
      printf("Error wrong type when appending the list.\n");
      code++;
   }
   if((*tList)->array[list_size - 1].content._long != test_value_long){
      printf("Error wrong value stored.\n");
      code++;
   }
   if((*tList)->size != list_size){
      printf("Error the size is wrong");
      code++;
   }

   free_list(tList);
   return code;
}