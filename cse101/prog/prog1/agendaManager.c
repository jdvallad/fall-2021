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
void add(ListPtr lists[2], char *names[2], char buffer[200][200]){
  int index = -1;
  if(strcmp(names[0], "") == 0){
    index = 0;
  }
  if(strcmp(names[1], "") == 0){
    index = 1;
  }
  if(strcmp(names[0], buffer[1]) == 0){
    index = 0;
  }
  if(strcmp(names[1], buffer[1]) == 0){
    index = 1;
  }
  if(index == -1){
   printf("ERROR: Agenda not found\n");
   return;
  }
  names[index] = buffer[1];
  EventPtr e = (EventPtr) malloc(sizeof(EventObj));
  e->name = buffer[2];
  e->time = atoi(buffer[3]);
  if(lists[index]->length == 0){
    lists[index]->head = e;
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
  }
  return;
}
void delete(ListPtr lists[2], char *names[2], char buffer[200][200]){
  return;
}
void swap(ListPtr lists[2], char *names[2], char buffer[200][200]){
  return;
}
void merge(ListPtr lists[2], char *names[2], char buffer[200][200]){
  return;
}
void printProperList(ListPtr lists[2], char *names[2], char buffer[200][200]){
  return;
}
int main(int argc, char **argv) {

  ListPtr lists[2];
  char *names[2] = {"", ""};
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
        parseLine(line,buffer, 2, false);
        delete(lists, names, buffer);
        break;
      case 'S':
        parseLine(line,buffer, 3, false);
        swap(lists, names, buffer);
        break;
      case 'P':
        parseLine(line,buffer, 1, false);
        printProperList(lists, names, buffer);
        break;
      case 'M':
        parseLine(line,buffer, 2, false);
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
