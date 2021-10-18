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
  printf("%2d:%2d %s\n",x->time / 60,x->time % 60,x->name);
  return;
}
void freeData(void *a){
  free(a);
  return;
}

void parseLine(char *line, char buffer[200][200], int elements, bool hasInt){
  int ind, innerInd,elementInd;
  char c;
  ind=innerInd=elementInd=0;
  c =line[ind];
  while(c != ' '){
    buffer[elementInd][innerInd] = c;
    innerInd++;
    ind++;
    c = line[ind];
  }
  buffer[elementInd][innerInd + 1] = '\0';
  ind+=2;
  innerInd = 0;
  elementInd++;
  if(elements == 1){
    return;
  }
  for(int i = 1; i < elements - 1; i++){
    c =line[ind];
    while(c != '"'){
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
  c =line[ind];
  char a = hasInt ? '\0' : '"';
  while(c != a){
    buffer[elementInd][innerInd] = c;
    innerInd++;
    ind++;
    c = line[ind];
  }
  buffer[elementInd][innerInd + 1] = '\0';
  return;
}
void add(ListPtr lists[2], char names[2][200], char buffer[200][200]){
  int index = -1;
  if(strcmp(names[0], buffer[1]) == 0){
    index = 0;
  }
  if(strcmp(names[1], buffer[1]) == 0){
    index = 1;
  }
  if(index == -1 && *names[0] == '\0'){
    index = 0;
  }
  if(index == -1 && *names[1] == '\0'){
    index = 1;
  }
  if(index == -1){
   printf("ERROR: Agenda not found\n");
   return;
  }
  strcpy(names[index], buffer[1]);
  EventPtr e = (EventPtr) malloc(sizeof(EventObj));
  e->name = buffer[2];
  e->time = 60 * atoi(buffer[3]);
  if(lists[index]->length == 0){
    appendList(lists[index], e);
    return;
  }
  int ind = 0;
  NodePtr temp = lists[index]->head;
  while(temp){
    EventPtr tempEvent = (EventPtr) temp;
    if(strcmp(tempEvent->name,e->name) == 0){
      printf("ERROR: Already an event with that name\n");
      return;
    }
    if(tempEvent->time == e->time){
      printf("ERROR: Already an event at that time\n");
      return;
    }
    if(e->time > tempEvent->time){
      ind++;
    }
    temp = temp->next;
  }
  insertElement(lists[index], ind, e);
  return;
}
void delete(ListPtr lists[2], char names[2][200], char buffer[200][200]){
  int index = -1;
  if((strcmp(names[0], buffer[1]) == 0) && (strcmp(names[0],"") != 0)){
    index = 0;
  }
  if((strcmp(names[1], buffer[1]) == 0) && (strcmp(names[1],"") != 0)){
    index = 1;
  }
  if(index == -1){
   printf("ERROR: Agenda not found\n");
   return;
  }
  int eventIndex = -1;
  int tempIndex = 0;
  NodePtr temp = lists[index]->head;
  while(temp){
    EventPtr tempEvent = (EventPtr) temp->data;
    if(strcmp(buffer[2], tempEvent->name) == 0){
      eventIndex = tempIndex;
      break;
    }
    tempIndex++;
    temp=temp->next;
  }
  if(eventIndex == -1){
    printf("ERROR: Event not found\n");
    return;
  }
  delElement(lists[index], eventIndex);
  if(lists[index]->length == 0){
    *names[index] = '\0';
  }
  return;
}
void swap(ListPtr lists[2], char names[2][200], char buffer[200][200]){
  return;
}
void merge(ListPtr lists[2], char names[2][200], char buffer[200][200]){
  return;
}
void printProperList(ListPtr lists[2], char names[2][200], char buffer[200][200]){
  int index = -1;
  if((strcmp(names[0], buffer[1]) == 0) && (strcmp(names[0],"") != 0)){
    index = 0;
  }
  if((strcmp(names[1], buffer[1]) == 0) && (strcmp(names[1],"") != 0)){
    index = 1;
  }
  if(index == -1){
   printf("ERROR: Agenda not found\n");
   return;
  }
  print(lists[index], names[index]);
  return;
}
int main(int argc, char **argv) {
  ListPtr lists[2];
  char names[2][200] = {"", ""};
  char line[200];
  lists[0] = newList(&dataEqual, &dataPrinter, &freeData);
  lists[1] = newList(&dataEqual, &dataPrinter, &freeData);
  char buffer[200][200];
  while(fgets(line, 200, stdin) != NULL){
    switch(*line){
      case 'A':
        parseLine(line,buffer, 4, true);
        add(lists, names, buffer);
        break;
      case 'D':
        parseLine(line,buffer, 3, false);
        delete(lists, names, buffer);
        break;
      case 'S':
        parseLine(line,buffer, 4, false);
        swap(lists, names, buffer);
        break;
      case 'P':
        parseLine(line,buffer, 2, false);
        printProperList(lists, names, buffer);
        break;
      case 'M':
        parseLine(line,buffer, 3, false);
        merge(lists, names, buffer);
        break;
      default:
        break;
    }
  }
  freeList(&lists[0], true);
  freeList(&lists[1], true);
 return 0;
}
