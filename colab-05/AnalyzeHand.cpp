#include "AnalyzeHand.h"

//returns a formatted string of the hand
string AnalyzeHand::toString(){
  string result;
  result += "[";

  for(int i = 0; i < numOfCards; i++){
    result += hand[i].toString();
    if(!(i == (numOfCards - 1)))
      result += ", "; //does not add comma to last card
  }

  result += "]";

  return result;
}

//mutator method for the hand
void AnalyzeHand::setHand(vector<Card> hand_){
  hand = hand_;
  numOfCards = hand.size();
}

vector<Card> AnalyzeHand::getHand(){
  return hand;
}
