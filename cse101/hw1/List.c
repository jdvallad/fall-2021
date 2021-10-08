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


