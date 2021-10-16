#include "List.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define EMPTY ""

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
  char names[2][100] = {"", ""};
  char words[30];
  int agendaCount = 0;

void add(ListPtr list, char *name, char *time){
  EventPtr event = (EventPtr) malloc(sizeof(EventObj));
  event->name = name;
  event->time = time;
  int index = 0;
  EventPtr before = NULL;
  EventPtr temp = list->head;
  while(temp )
}

int main(int argc, char **argv) {
  ListPtr one = newList(&dataEqual, &dataPrinter, &freeData);
  ListPtr two = newList(&dataEqual, &dataPrinter, &freeData);
  while(scanf("%30s", words) != EOF){
    if(strcmp(words, "ADD") == 0)
    if(strcmp(words, "DEL") == 0)
    if(strcmp(words, "SWAP") == 0)
    if(strcmp(words, "PRINT") == 0)
    if(strcmp(words, "MERGE") == 0)
  }
 return 0;
}
