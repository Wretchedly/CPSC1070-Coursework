#include "DeckOfCards.h"
#include "Card.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

//constructor
//initializes 52 card objects
DeckOfCards::DeckOfCards(){
  for(int i = 0; i < 4; i++){		//iterates through suits
    for(int j = 0; j < 13; j++){	//iterates through faces
      Card card = Card(j, i);
      cards.push_back(card);
    }
  }
}

//shuffle the cards in the deck
void DeckOfCards::shuffle(){
  srand(time(0));	//random seed
  
  for(int i = 0; i < cards.size(); i++){
    int j = rand() % 51;

    //"take" cards from deck
    Card c1 = cards[i];
    Card c2 = cards[j];

    //temp ints to store data
    int tempS = c1.getSuit(), tempF = c1.getFace();

    c1.setSuit(c2.getSuit());
    c1.setFace(c2.getFace());

    c2.setSuit(tempS);
    c2.setFace(tempF);

    //"return" cards back to deck
    cards[i] = c1;
    cards[j] = c2;
  }
}

//if there are more cards, deal one
Card DeckOfCards::dealCard(){
  if(!moreCards()){
    cout<<"Error: No cards left in deck!";
    exit(0);
  }

  return cards[currentCard++];
}

//check for remaining cards
bool DeckOfCards::moreCards(){
  bool more = true;

  if(!(currentCard < 52))
    more = false;

  return more;
}
