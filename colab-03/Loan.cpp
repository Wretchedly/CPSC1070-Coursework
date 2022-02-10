#include "Loan.h"

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void Loan::paymentDriver() {
  double principle, interest, monthlyPay;
  char runAgain;
  
  cout<<"Loan Payment Calculator\n"<<endl;
  cout<<"Enter the principal amount: ";
  cin>>principle;

  cout<<"Enter the annual interest rate (in %): ";
  cin>>interest;

  cout<<"Enter the monthly payment: ";
  cin>>monthlyPay;

  cout<<"\nCalculating...\n"<<endl;

  paymentMonths(principle, interest, monthlyPay);

  while(true){
    cout<<"Calculate another loan payoff? (y/n): ";
    cin>>runAgain;

    //prompt user to run calculator again
    switch(runAgain){
      case 'y':
        paymentDriver();
	break;
      case 'n':
	return;
	break;
      default:
	break;
    }
  }
}

int Loan::paymentMonths(double principle, double interest, double monthlyPay){
  int months;
  double years, intPaid, totalPaid;

  months = round((log(monthlyPay)-log(monthlyPay-((interest/monthlyPay)*principle)))/log((interest/monthlyPay)+1));
  years = months/12.0;

  cout<<months<<" {"<<fixed<<setprecision(1)<<years<<" years) needed to pay your loan off."<<endl;

  monthlyPay += 10;
  int hypoMonths = months;
  hypoMonths -= round((log(monthlyPay)-log(monthlyPay-((interest/monthlyPay)*principle)))/log((interest/monthlyPay)+1));

  cout<<"\nDid you know if you paid an additional $10 per month, you would pay off your loan "<<hypoMonths<<" months earlier?"<<endl;

  monthlyPay -= 10;
  intPaid = ((monthlyPay*(interest/100))*months);
  totalPaid = intPaid+principle;

  cout<<"\nThe total interest paid is $"<<fixed<<setprecision(2)<<intPaid<<" and the total amount you'll pay is $"<<fixed<<setprecision(2)<<totalPaid<<"."<<endl;

  return months;
}
