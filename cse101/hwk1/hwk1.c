#include "List.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 * These are variables that are used to loop over user input.
 */
char command[15];
char *APPEND = "APPEND";
char *DELETE = "DELETE";
char *MAX = "MAX";
char *PRINT = "PRINT";
char *LENGTH = "LENGTH";
int next = 0;
/*
 * This function is run at program execution.
 * It creates a new List and reads commands
 * in from stdin, printing to stdout.
 * At the EOF, the list is freed and the program exits.
 */
int main(int argc, char **argv){
  ListPtr L = newList(); // A new list is created.
  while(scanf("%s", command) != EOF){ //while there is more input.
    // parse user input
   if(strcmp(command, APPEND) == 0){
     scanf("%d", &next);
     appendList(L, next);
   }
   if(strcmp(command, DELETE) == 0){
     scanf("%d", &next);
     printf("%d\n",delElement(L, next));
   }
   if(strcmp(command, MAX) == 0){
     printf("%d\n",max(L));
   }
   if(strcmp(command, PRINT) == 0){
     printList(L);
   }
   if(strcmp(command, LENGTH) == 0){
     printf("%d\n",length(L));
   }
  }
  freeList(&L); // Free the created list.
  return 0;
}
