#include <stdio.h>
#include <stdlib.h>
#include "List.h"

// Code to implement the functions in List.h
ListPtr newList(bool (*dataEqual)(void *obj1, void*obj2), void (*dataPrinter)(void *data), void (*freeData)(void *data)){
  ListPtr result = (ListPtr) malloc(sizeof(ListObj));
  if(result){
    result->head = NULL;
    result->dataEqual = dataEqual;
    result->dataPrinter = dataPrinter;
    result->freeData = freeData;
    result->length = 0;
  }
  return result;
}

void freeList( ListPtr *pL, bool freeData){
  NodePtr temp = (*pL)->head;
  while(temp){
    if(freeData){
      (*pL)->freeData(temp->data);
    }
   free(temp);
   temp = temp->next;
  }
  free(*pL);
  *pL = NULL;
  return;
}
int length( ListPtr L ){
  return L->length;
}

int findElement(ListPtr L, void *comp){
 int index = -1;
 NodePtr temp = L->head;
 while(temp){
   index++;
   if(L->dataEqual(comp, temp->data)){
     return index;
   }
   temp = temp->next;
 }
 return index;
}
void *getElement( ListPtr L, int i){
  if(L->length > i){
    return NULL;
  }
  int index = 0;
  NodePtr temp = L->head;
  while(temp && index < i){
    temp = temp->next;
    index++;
  }
  if(temp && index == i){
    return (void *) temp;
  }
  return NULL;
}
void *delElement( ListPtr L, int i ){
  if(L->length > i){
    return NULL;
  }
  int index = 0;
  NodePtr temp = L->head;
  NodePtr before = NULL;
  while(temp && index < i){
    before = temp;
    temp = temp->next;
    index++;
  }
  if(temp && index == i){
   if(before){
     before->next = temp->next;
   }
   L->length--;
   return temp;
  }
  return NULL;
}
bool appendList( ListPtr L, void *data ){
  return insertElement(L, L->length - 1, data);
}
bool insertElement(ListPtr L, int pos, void *data){
  if(L->length > pos){
    return false;
  }
  int index = 0;
  NodePtr before = NULL;
  NodePtr temp = L->head;
  while(temp && index < pos){
    before = temp;
    temp = temp->next;
    index++;
  }
  if(temp && index==pos){
    NodePtr insert = (NodePtr) malloc(sizeof(NodeObj));
    insert->data = data;
    insert->next = temp;
    if(before){
      before->next = insert;
    }
    L->length++;
    return true;
  }
  return false;
}
void printList(ListPtr L){
  NodePtr temp = L->head;
  while(temp){
    L->dataPrinter(temp->data);
  }
  return;
}
