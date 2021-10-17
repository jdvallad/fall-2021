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

bool dataEqual(void *a, void *b){
  EventPtr x = (EventPtr) a;
  EventPtr y = (EventPtr) b;
  return x->time == y->time &&
    strcmp(x->name,y->name) == 0;
}
void dataPrinter(void *a){
  EventPtr x = (EventPtr) a;
  printf("%d:%d %s\n",x->time / 60,x->time % 60,x->name);
  return;
}
void freeData(void *a){
  free(a);
  return;
}

void parseLine(char **buffer, int elements){

}
int main(int argc, char **argv) {
  ListPtr lists[2];
  char *names[2] = {"", ""};
  char input[30];
  lists[0] = newList(&dataEqual, &dataPrinter, &freeData);
  lists[1] = newList(&dataEqual, &dataPrinter, &freeData);
  while(scanf("%30s", input) != EOF){
    if(strcmp(input, "ADD") == 0){
      char *agendaName;
      char *eventName;
      int startTime = 0;
      scanf("%30s", agendaName);
      scanf("%30s", eventName);
      scanf("%d", eventName);
    }
  }
  freeList(&lists[0], true);
  freeList(&lists[1], true);
 return 0;
}
