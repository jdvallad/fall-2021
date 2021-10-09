#include "List.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char **argv){
	// Declare a new list
  ListPtr L = newList();
	// Accept input from the user
  char command[15];
  char *APPEND = "APPEND";
  char *DELETE = "DELETE";
  char *MAX = "MAX";
  char *PRINT = "PRINT";
  char *LENGTH = "LENGTH";
  int next = 0;
  while(scanf("%s", command) != EOF){
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
  freeList(&L);
  return 0;
}
