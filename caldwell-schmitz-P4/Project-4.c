// Zachary Jewel Schmitz
// Chris Caldwell
// CPSC 1071: Section 001
// 22 November 2021

// Academic Honesty Statment: We verify that we have neither given nor received any outside 
//help or information other than from the perscribes sources for this project.
//The only source of reference for this project was extensive use of cplusplus.com.
//No TAs helped on this assignment.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Prototype for the primary method
void findHeader(FILE *);

//following the previosly outlined format, main takes in the arguments given to the command
//line, then excecutes the findHeader function with the file from command line input.
int main(int argc, char *argv[]){
  FILE *file = fopen(argv[1], "r");

  //makes sure valid file is used before continuing
  if(file == NULL){
    printf("%s is an invald file, please try again.\n", argv[1]);
    return 1;
  }

  findHeader(file);
}

//Findheader cycles through the file reading in 512 character blocks as perscribed in the directions
//Then checks the first 4 characters of each block for the designated header for an image.
//It then iterates the sections of code with that header designation into the appropriate 
//picture file, the closes them and then the main file accordingly.
void findHeader(FILE *file){

  //Variable assignments
  unsigned char block[512];
  int count = 0;
  char *title="";
  fseek(file, 0, SEEK_SET);
  FILE *picture = NULL;

  //while reading through file, checks first 4 characters for designated header sequence.
  while(fread(block,512,1,file) == 1){
    if((block[0]==0xFF && block[1]==0xD8 && block[2]==0xFF && block[3]==0xE1)
      ||(block[0]==0xFF && block[1]==0xD8 && block[2]==0xFF && block[3]==0xE0)){

      //closes open picture files and assigns memory for title array.
      if(picture!=NULL){fclose(picture);}
      title=(char*)malloc(sizeof(char));

      //assigns variable integer naming scheme to title array.
      sprintf(title,"recovered_image_%d.jpg",count);
      printf("Filename is %s\n", title);
      
      //opens picture in write format with previously declared name.
      picture = fopen(title, "w");     
  	  
  	  //iterates count for picture counting purposes.
      count++;          
    }
    //If header sequence is not yet found, continues writing blocks to the file after
    //first header sequence is found, and until next sequence is found.
    if(picture!=NULL){
      fwrite(block, 512, 1, picture);
    }
  }
  fclose(file);
}
