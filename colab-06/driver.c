//Chris Caldwell
//CPSC 1071:001
//Mission: Possible
//11/22/21

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"

int main(){

  char phrase[100];

  while(strcmp("-99", phrase) != 0){
    printf("Enter a word or phrase, or -99 to end: ");
    scanf("%s", phrase);
    if(strcmp("-99", phrase) != 0){
      insert(phrase);
    }
  }

  print();

}
