#ifndef BLACKJACKRULES_H
#define BLACKJACKRULES_H

#include "AnalyzeHand.h"

class BlackjackRules : public AnalyzeHand{
  public:
    bool isWon();
  
  private:
    vector<Card> hand;
    int numOfCards;
};
#endif
