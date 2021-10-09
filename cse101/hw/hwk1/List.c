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

/*
 * Creates a new list object in memory.
 * Returns pointer to object, otherwise NULL.
 */
ListPtr newList(){
  ListPtr res = (ListPtr) malloc(sizeof(ListObj));
  if(res){
  res->head = NULL;
  res->length = 0;
  }
  return res;
}

/*
 * Frees memory associated with pL.
 * sets pL to NULL.
 */
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
/*
 * returs length of L.
 */
int length(ListPtr L){
  return L->length;
}

/*
 * returns index of max element in L.
 */
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

/*
 * returns index of first element in L
 * with data value of i.
 */
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

/*
 * deletes element at index i from L.
 * Prints value of node deleted with newline.
 */
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
  if(temp == L->head){
    L->head = temp->next;
  }
  free(temp);
  L->length--;
  return res;
}

/*
 * Appends new node with value i
 * at the end of the List.
 */
void appendList(ListPtr L, int i){
  NodePtr temp = L->head;
  if(temp == NULL){
    L->head = (NodePtr) malloc(sizeof(NodeObj));
    if(L->head){
    L->head->data = i;
    L->head->next = NULL;
    L->length = 1;
    }
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
  res->next = NULL;
  temp->next = res;
  L->length++;
  return;
}

/*
 * prints contents of L
 * as comma seperated values.
 */
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
