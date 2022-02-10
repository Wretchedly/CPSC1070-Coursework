#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

#include "Card.h"
#include <vector>

using namespace std;

class DeckOfCards{

  public:
    //lab specified methods
    DeckOfCards();
    void shuffle();
    Card dealCard();
    bool moreCards();

  private:
    int currentCard = 0;

    vector<Card> cards;

};
#endif
