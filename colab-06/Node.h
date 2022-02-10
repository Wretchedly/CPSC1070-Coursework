#ifndef NODE_H
#define NODE_H

#include <stdio.h>

typedef struct node{
  struct node* nextPtr;
  char phrase[];
} node;

#endif
