#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"

node* head = NULL;

//add new node into list
void insert(char newPhrase[]){
  if(head == NULL){
    head = (node*)malloc(sizeof(node));
    strcpy(head->phrase, newPhrase);
  } else {
  //allocate memory
  node* temp = head;

  while(temp->nextPtr != NULL){
    temp = temp->nextPtr;
  }

  temp->nextPtr = (node*)malloc(sizeof(node));

  //copy parameter into new node
  strcpy(temp->nextPtr->phrase, newPhrase);
  }
}

//remove next node from list
void deleteNode(){
  node* temp = head;

  head = head->nextPtr;

  //free memory
  free(temp);
}

void printList(struct node* n){
  if(n != NULL){
    //case: one input
    if(n->nextPtr == NULL){
      printf("You've entered the following node: %s\n", n->phrase);
    //case: two inputs
    } else if(n->nextPtr != NULL && n->nextPtr->nextPtr == NULL){
      printf("You've entered the following nodes: %s", n->phrase);
      n = n->nextPtr;
      printf(" and %s\n", n->phrase);
    //case: >two inputs
    } else {
      printf("You've entered the following nodes: ");

      while(n->nextPtr != NULL){
      printf("%s, ", n->phrase);
      n = n->nextPtr;
      }

      printf("and %s\n", n->phrase);
    }
  }
}

void print(){
  printList(head);
}

struct node* makeList(){
  struct node* test;

  return test;
}

