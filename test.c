#include <stdio.h>

#include "base_container.h"
#include "list.h"

int main(void){
   base_container a = {0, 49};
   base_container b = {3, 'a'};
   printf("%d et %c\n", a.content._int, a.content._char);
   return 0;
}