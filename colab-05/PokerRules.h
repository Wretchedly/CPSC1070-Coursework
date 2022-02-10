#ifndef POKERRULES_H
#define POKERRULES_H

#include "AnalyzeHand.h"

class PokerRules : public AnalyzeHand{
  public:
    bool isWon();

  private:
    vector<Card> hand;
    int numOfCards;

    bool pair();
    bool twoPairs();
    bool threeOfAKind();
    bool fourOfAKind();
    bool straight();
    bool flush();
    
};
#endif
