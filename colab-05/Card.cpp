#include "Card.h"

//constructor
Card::Card(int face, int suit){
  setFace(face);
  setSuit(suit);
}

//gets the name of the face and suit of a card
string Card::toString(){
  string output = faces[face] + " of " + suits[suit];

  return output;
}

//accessor methods
int Card::getFace(){
  return face;
}

int Card::getSuit(){
  return suit;
}

//mutator methods
void Card::setFace(int face_){
  face = static_cast<Face>(face_);
}

void Card::setSuit(int suit_){
  suit = static_cast<Suit>(suit_);
}
