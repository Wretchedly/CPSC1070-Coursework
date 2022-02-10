//Chris Caldwell
//CPSC 1070:1
//Mission:Possible
//11/8/21

#include "Card.h"
#include "AnalyzeHand.h"
#include "BlackjackRules.h"
#include "PokerRules.h"

#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
  //check for proper usage of program
  if(argc != 2){
    cout<<"Improper usage! Please use an int 0 or 1 as an arg."<<endl;
    exit(1);
  }

  //create a new hand
  vector<Card> newHand;

  newHand.push_back(Card(8,0));
  newHand.push_back(Card(1,0));
  newHand.push_back(Card(1,0));
  newHand.push_back(Card(1,0));
  newHand.push_back(Card(1,1));

  //takes the cmd line argument and checks what the user did
  switch(stoi(argv[1])){
    case 0: {
      cout<<"******* Welcome to Blackjack Rules *******\n"<<endl;

      BlackjackRules blackjack;
      blackjack.setHand(newHand);

      cout<<"We are checking the Hand:\n\t"<<blackjack.toString()<<endl;
      cout<<"\n...Checking\n"<<endl;

      //checks for a win
      if(blackjack.isWon())
        cout<<"This is a Winning hand!\n"<<endl;
      else
        cout<<"This is not a Winning hand.\n"<<endl;
    } break;
    case 1: {
      cout<<"******* Welcome to Poker Rules *******\n"<<endl;

      PokerRules poker;
      poker.setHand(newHand);

      cout<<"We are checking the Hand:\n\t"<<poker.toString()<<endl;
      cout<<"\n...Checking\n"<<endl;

      //checks for a win
      if(poker.isWon())
        cout<<"This is a Winning hand!\n"<<endl;
      else
        cout<<"This is not a Winning hand.\n"<<endl;      
    } break;
    default: {
      cout<<"Invalid choice, please enter 0 or 1!"<<endl;
      exit(1);
    }
  }

}
