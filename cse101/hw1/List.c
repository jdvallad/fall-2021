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
  if(res){
  res->head = NULL;
  res->length = 0;
  }
  return res;
}

void freeList(ListPtr* pL){
  if(pL){
    NodePtr temp = (*pL)->head;
    while(temp){
     NodePtr a = temp;
     temp = temp->next;
     free(a);
    }
    free(*pL);
    pL = NULL;
  }
  return;
}

int length(ListPtr L){
  return L->length;
}

int max(ListPtr L){
  if(L->length == 0){
    return -1;
  }
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
  if(L->length == 0){
    return -1;
  }
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
  if(L->length == 0){
    return -1;
  }
  int index = 0;
  NodePtr prev = NULL;
  NodePtr temp = L->head;
  while(index != i){
    prev = temp;
    temp = temp->next;
    index++;
  }
  if(prev){
    prev->next = temp->next;
  }
  int res = temp->data;
  free(temp);
  L->length--;
  return res;
}

void appendList(ListPtr L, int i){
  NodePtr temp = L->head;
  if(temp == NULL){
    L->head = (NodePtr) malloc(sizeof(NodeObj));
    L->head->data = i;
    L->length = 1;
    return;
  }
  while(temp->next){
    temp = temp->next;
  }
  NodePtr res = (NodePtr) malloc(sizeof(NodeObj));
  if(res == NULL){
    return;
  }
  res->data = i;
  temp->next = res;
  L->length++;
  return;
}

void printList(ListPtr L){
  if(L->length == 0){
    return;
  }
  NodePtr temp = L->head;
  printf("%d", temp->data);
  while(temp->next){
    temp = temp->next;
    printf(", %d", temp->data);
  }
  printf("\n");
  return;
}
