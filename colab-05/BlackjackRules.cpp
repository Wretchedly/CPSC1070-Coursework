#include "BlackjackRules.h"

//win parameter
bool BlackjackRules::isWon(){
  int sum = 0;
  bool won = false;

  vector<Card> hand = this->getHand();

  for(int i = 0; i < hand.size(); i++){
    sum += (hand[i].getFace() + 1);
  }

  if(sum <= 21){
    won = true;
  }
  
  return won;
}
