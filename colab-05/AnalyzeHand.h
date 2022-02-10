#ifndef ANALYZEHAND_H
#define ANALYZEHAND_H

#include <vector>
#include <string>

#include "Card.h"

using namespace std;

class AnalyzeHand{

  public:
    //lab-specificed functions
    string toString();
    virtual bool isWon() = 0;
    //additional function(s)
    void setHand(vector<Card>);
    vector<Card> getHand();
    
  private:
    //lab-specified data members
    vector<Card> hand;
    int numOfCards;

};
#endif
