#include "Simulation.h"

#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

using namespace std;

void Simulation::runOneGame(){
  bool racing = true;
  unsigned int posTurtle=1, posHare=1;

  srand(time(0));
  //usleep(1000000);

  while(racing){
    usleep(1000000);

    moveTortoise(&posTurtle);
    moveHare(&posHare);

    //logic for printing position map
    for(int i = 0; i < 70; i++){
      if(i == posTurtle && i != posHare){
        cout<<"T";
      } else if(i != posTurtle && i == posHare){
        cout<<"H";
      } else if(i == posTurtle && i == posHare){
        cout<<"OUCH!";
      } else {
        cout<<"-";
      }
    } cout<<endl;

    //check for win
    if(posTurtle >= 70 && posHare <= 70){
      cout<<"TORTOISE WINS!!!"<<endl;
      racing = false;
    } else if (posTurtle <= 70 && posHare >= 70){
      cout<<"HARE WINS!!!"<<endl;
      racing = false;
    } else if (posTurtle >= 70 && posHare >= 70){
      cout<<"WOW!!! A TIE!!!"<<endl;
      racing = false;
    }
  }
}

void Simulation::moveTortoise(unsigned int *ptrTurtle){
  int roll = (rand() % 100) + 1;

  //checks to see what action the tortoise takes
  if(roll <= 50){
    *ptrTurtle += 3;	//fast pace
  } else if(roll > 50 && roll <= 75){
    if(*ptrTurtle < 6){
      *ptrTurtle = 0;	//uints are evil, so this checks for underflow
    } else {
      *ptrTurtle -= 6;	//slip
    }
  } else if(roll > 75 && roll <= 100){
    *ptrTurtle += 1;	//slow pace
  }
}

void Simulation::moveHare(unsigned int *ptrHare){
  int roll = (rand() % 100) + 1;

  //checks to see what action the hare takes
  if(roll <= 25){
    *ptrHare += 0;	//sleep
  } else if(roll > 25 && roll <= 45){
    *ptrHare += 9;	//big hop
  } else if(roll > 45 && roll <= 50){
    if(*ptrHare < 12){
      *ptrHare = 0;	//underflow safeguard
    } else {
      *ptrHare -= 12;	//big slip
    }
  } else if(roll > 50 && roll <= 80){
    *ptrHare += 1;	//small hop
  } else if(roll > 80 && roll <= 100){
    if(*ptrHare < 2){
      *ptrHare = 0;	//underflow safeguard
    } else {
      *ptrHare -= 2;	//small slip
    }
  }
}
