//Chris Caldwell
//CPSC 1071: 1
//Mission: Possible
//10/25/21

#include "Card.h"
#include "DeckOfCards.h"

#include <iostream>
#include <vector>

using namespace std;

int main(){
  DeckOfCards deck;

  cout<<"Card(12,0).toString is "<<Card(12,0).toString()<<endl;
  cout<<"Card(0,3).toString is "<<Card(0,3).toString()<<endl;

  cout<<"deck.dealCard().toString() is "<<deck.dealCard().toString()<<endl;
  cout<<"deck.dealCard().toString() is "<<deck.dealCard().toString()<<endl;
  cout<<"Running deck.shuffle()"<<endl;
  deck.shuffle();
  cout<<"deck.dealCard().toString() is "<<deck.dealCard().toString()<<endl;
  cout<<"deck.dealCard().toString() is "<<deck.dealCard().toString()<<endl;
}
