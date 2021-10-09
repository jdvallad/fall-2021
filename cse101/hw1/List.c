#include <stdio.h>
#include <stdlib.h>
#include "List.h"

// Type 1: List is a list with extra node structure
typedef struct NodeObj{
    int data;
    struct NodeObj* next;
}NodeObj;
typedef NodeObj* NodePtr;

typedef struct ListObj{
    NodePtr head;
    int length;
}ListObj;

ListPtr newList(){
  ListPtr res = (ListPtr) malloc(sizeof(ListObj));
  res->data = 0;
  res->next = NULL;
  return res;
}

void freeList(ListPtr* pL){
  if(pL){
    NodePtr temp = *pl->head;
    while(temp){
     free(temp);
     temp = temp->next;
    }
    free(*pl);
    pl = NULL;
  }
  return;
}

int length(ListPtr L){
  return L->length;
}

int max(ListPtr L){
  int index = 0;
  int max_index = 0;
  NodePtr temp = L->head;
  int max = temp->data;
  while(temp){
    if(temp->data>max){
      max = temp->data;
      max_index = index;
    }
    index++;
    temp = temp->next;
  }
  return max_index;
}

int find(ListPtr L, int i){
  int index = 0;
  NodePtr temp = L->head;
  while(temp){
    if(temp->data == i){
      return index;
    }
    index++;
    temp = temp->next;
  }
  return -1;
}

int delElement(ListPtr L, int i){
  int index = 0;
  NodePtr prev = NULL;
  NodePtr temp = L->head;
  while(index != i){
    prev = second;
    temp = second->head;
    index++;
  }
  if(prev){
    prev->next = temp->next;
  }
  int res = temp->data;
  free(temp);
  return res;
}

void appendList(ListPtr L, int i){
  NodePtr temp = L->head;
  while(temp->next){
    temp = temp->next;
  }
  NodePtr res = (NodePtr) malloc(sizeof(NodeObj));
  res.data = i;
  temp->next = &res;
  return;
}

void printList(ListPtr L){
  NodePtr temp = L->head;
  printf("%d ", temp->data);
  while(temp->next){
    temp = temp->next;
    printf("%d ", temp->data);
  }
  printf("\n");
  return;
}
