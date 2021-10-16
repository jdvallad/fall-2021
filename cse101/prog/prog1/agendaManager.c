#include "List.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct EventObj{
    char *name;
    int time;
} EventObj;
typedef EventObj* EventPtr;


// provided for output header formatting
void print(ListPtr l, char *agenda_name) {
    printf("======== %s ========\n", agenda_name);
    printList(l);
    printf("===== END OF %s =====\n", agenda_name);
}

bool dataEqual()
int main(int argc, char **argv) {
  //
	// declare 2 lists
  //
   ListPtr one = newList



	// accept input from the user



	// process input and modify appropriate list




	// be sure to release memory
}
