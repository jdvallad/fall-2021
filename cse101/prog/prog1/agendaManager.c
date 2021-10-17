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

void parseLine(char **buffer, int elements, bool hasInt){
  char *line[200];
  gets(line);
  int ind, innerInd,elementInd;
  char c;
  ind=innerInd=elementInd=0;
  c =line[ind];
  while(c != " "){
    buffer[elementInd][innerInd] = c;
    innerInd++;
    ind++;
    c = line[ind];
  }
  buffer[elementInd][innerInd + 1] = '\0';
  ind+=2;
  innerInd = 0;
  elementInd++;
  for(int i = 1; i < elements - 1; i++){
    ind=innerInd=elementInd=0;
    c =line[ind];
    while(c != "\""){
      buffer[elementInd][innerInd] = c;
      innerInd++;
      ind++;
      c = line[ind];
    }
    buffer[elementInd][innerInd + 1] = '\0';
    ind+=3;
    innerInd = 0;
    elementInd++;
  }
  if(hasInt){
    ind--;
  }
  ind=innerInd=elementInd=0;
  c =line[ind];
  while(c != "\""){
    buffer[elementInd][innerInd] = c;
    innerInd++;
    ind++;
    c = line[ind];
  }
  buffer[elementInd][innerInd + 1] = '\0';
  ind+=3;
  innerInd = 0;
  elementInd++;
  return;
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
      scanf("%d", startTime);
    }
  }
  freeList(&lists[0], true);
  freeList(&lists[1], true);
 return 0;
}
