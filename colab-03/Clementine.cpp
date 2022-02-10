//Chris Caldwell
//CPSC 1070: 1
//Mission: Possible
//10/4/21

#include "Loan.h"
#include "Retirement.h"
#include "Register.h"

#include <iostream>

using namespace std;

void runMenuSystem();

int main(){
  cout<<"Starting Clementine Financial Bank"<<endl;
  
  while(true){
    runMenuSystem();
  }
}

//prompts the user to select a function of/quit the program
void runMenuSystem(){
  char choice;

  do{
    cout<<"******* Welcome to Clementine Financial *********\n\nMenu:\n\t[E] Estimate how much money at retirement\n\t[L] Loan payoff calculator\n\t[R] Run transaction classifier\n\t[Q] Quit program\n\nEnter your choice and press enter: ";
    cin>>choice;
  }while(!isalpha(choice));

  Retirement retire;
  Loan loan;
  Register reg;

  switch(choice){
    case 'e':
    case 'E':
      retire.estimateDriver();
      break;
    case 'l':
    case 'L':
      loan.paymentDriver();
      break;
    case 'r':
    case 'R':
      reg.processTransaction();
      break;
    case 'q':
    case 'Q':
      exit(1);
    default:
      return;
  }
}
