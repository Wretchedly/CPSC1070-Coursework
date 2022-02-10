#include "PokerRules.h"

//check for win
bool PokerRules::isWon(){
  bool won = false;
  
  if(pair()||twoPairs()||threeOfAKind()||fourOfAKind()||straight()||flush())
    won = true;

  return won;
}

//methods for winning hands
//check for 2 cards of equal value
bool PokerRules::pair(){
  vector<Card> hand = this->getHand();

  for(int i = 0; i < hand.size(); i++){
    for(int j = 0; j < hand.size(); j++){
      if(i != j){
        if(hand[i].getFace() == hand[j].getFace())
          return true;
      }
    }
  }

  return false;
}

//check for 2 pairs of equal value cards
bool PokerRules::twoPairs(){
  vector<Card> hand = this->getHand();
  int firstPair = -1, numPairs = 0;

  for(int i = 0; i < hand.size(); i++){
    for(int j = 0; j < hand.size(); j++){
      if(i != j){
        if(hand[i].getFace()==hand[j].getFace() && numPairs==0){
          firstPair = hand[i].getFace();
          numPairs++;
        } else if(hand[i].getFace()==hand[j].getFace() && numPairs==1 && hand[i].getFace() != firstPair){
          return true;
        }
      }
    }
  }

  return false;
}

//check for 3 cards of equal value
bool PokerRules::threeOfAKind(){
  vector<Card> hand = this->getHand();

  for(int i = 0; i < hand.size(); i++){
    for(int j = 0; j < hand.size(); j++){
      for(int k = 0; k < hand.size(); k++){
        if(i != j && j != k){
          if(hand[i].getFace()==hand[j].getFace() && hand[j].getFace() == hand[k].getFace()){}
            
        }
      }
    }
  }

  return false;
}

//check for 4 cards of equal value
bool PokerRules::fourOfAKind(){
  vector<Card> hand = this->getHand();
  int numEqual = 0;

  for(int i = 0; i < hand.size(); i++){
    for(int j = 0; j < 12; j++){
      if(hand[i].getFace() == j){
        numEqual++;
      }
    }
    if(numEqual == 4)
      return true;
    else
      numEqual = 0;
  }

  return false;
}

//check for 5 cards in a sequence
bool PokerRules::straight(){
  return false;
}

//check for 5 cards of equal suit
bool PokerRules::flush(){
  return false;
}
