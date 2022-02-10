#ifndef CARD_H
#define CARD_H

#include <string>

using namespace std;

class Card{

  public:
    //lab-required methods
    Card(int, int);
    string toString();

    //accessor methods
    int getFace();
    int getSuit();
    //mutator methods
    void setFace(int);
    void setSuit(int);

  private:
    //lab-required enums/arrays
    enum Face{ACE, DEUCE, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
    enum Suit{HEARTS, DIAMONDS, CLUBS, SPADES};

    string faces[13] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    string suits[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};

    //additional variables
    Face face;
    Suit suit;

};
#endif
