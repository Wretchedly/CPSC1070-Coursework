//Chris Caldwell
//CPSC 1071: 1
//Mission: Possible
//9/20/21

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//function prototypes
//core functions
void runMenuSystem();
void estimateDriver();
double estimateEarnings(int, int, double, double, double);
void paymentDriver();
int paymentMonths(double, double, double);
//helper functions
int validate(int);
double validate(double);

int main(){

  runMenuSystem();

}

//prompts the user to select a function of the program, or to quit
void runMenuSystem(){
  char choice;

  do{
    cout<<"******* Welcome to Clementine Financial *********"<<endl;
    cout<<"\nMenu:"<<endl;
    cout<<"\t[E] Estimate how much money at retirement"<<endl<<"\t[L] Loan payoff calculator"<<endl<<"\t[Q] Quit program"<<endl<<"\nEnter your choice and press enter: ";
    cin>>choice;
  }while(!isalpha(choice));

  switch(choice){
    case 'e':
    case 'E':
      estimateDriver();
      break;
    case 'l':
    case 'L':
      paymentDriver();
      break;
    case 'q':
    case 'Q':
      exit(1);
      break;
    default:
      runMenuSystem();
  }

}

//prompts user for input to calculate retirement estimate
void estimateDriver(){
  int age, retAge;
  double retSave, contrib, percent;
  char runAgain;

  cout<<"Estimate Savings at Retirement\nDisclaimer: This is only a rough estimate!"<<endl;
  cout<<"\n\tEnter your current age in years: ";
  cin>>age;
  age = validate(age);
  cout<<"\tEnter your target retirement age: ";
  cin>>retAge;
  retAge = validate(retAge);
  cout<<"\tHow much have you saved towards retirement?: $";
  cin>>retSave;
  retSave = validate(retSave);
  cout<<"\tEnter your monthly contribution to retirement: $";
  cin>>contrib;
  contrib = validate(contrib);
  cout<<"\tEntire the estimate annual return on investment (in percent): ";
  cin>>percent;
  percent = validate(percent);
  cout<<"."<<endl<<"."<<endl<<"...calculating\n"<<endl;

  estimateEarnings(age, retAge, retSave, contrib, percent);

  while(true){
    cout<<"\nCalculate another estimate? (y/n): ";
    cin>>runAgain;

    //prompt user to run calculator again
    switch(runAgain){
      case 'y':
        estimateDriver();
	break;
      case 'n':
	cout<<endl;
        runMenuSystem();
	break;
      default:
	break;
    }
  }
}

//calculate earnings and growth, then display to user
double estimateEarnings(int age, int retAge, double retSave, double contrib,
    double percent){
  double earnings, monthlyGrowth, totalGrowth;

  for(int i = age*12; i < retAge*12; i++){
    monthlyGrowth = retSave*(percent/12);
    totalGrowth += monthlyGrowth;
    retSave += contrib + monthlyGrowth;
    earnings = retSave;
  }

  cout<<"Estimated Retirement Savings: $"<<fixed<<setprecision(2)<<earnings<<endl;
  cout<<"Estimated Retirement Growth: $"<<fixed<<setprecision(2)<<totalGrowth<<endl;
  
  return earnings;
}

//prompt user for loan repayment info
void paymentDriver(){
  double prin, intRate, monthlyPay;
  char runAgain;
  
  cout<<"Loan Payment Calculator\n"<<endl;
  cout<<"Enter the principal amount: ";
  cin>>prin;
  prin = validate(prin);
  cout<<"Enter the annual interest rate (in %): ";
  cin>>intRate;
  intRate = validate(intRate);
  cout<<"Enter the monthly payment: ";
  cin>>monthlyPay;
  monthlyPay = validate(monthlyPay);
  cout<<"\nCalculating...\n"<<endl;

  paymentMonths(prin, intRate, monthlyPay);

  while(true){
    cout<<"Calculate another loan payoff? (y/n): ";
    cin>>runAgain;

    //prompt user to run calculator again
    switch(runAgain){
      case 'y':
        paymentDriver();
	break;
      case 'n':
        runMenuSystem();
	break;
      default:
	break;
    }
  }
}

//calculate loan repayment
int paymentMonths(double prin, double intRate, double monthlyPay){
  int months;
  double years, intPaid, totalPaid;

  months = round((log(monthlyPay)-log(monthlyPay-((intRate/1200)*prin)))/log((intRate/1200)+1));
  years = months/12.0;

  cout<<months<<" ("<<fixed<<setprecision(1)<<years<<" years) needed to pay your loan off."<<endl;

  monthlyPay += 10;
  int hypoMonths = months;
  hypoMonths -= round((log(monthlyPay)-log(monthlyPay-((intRate/1200)*prin)))/log((intRate/1200)+1));

  cout<<"\nDid you know if you paid an additional $10 per month, you would pay off your loan "<<hypoMonths<<" months earlier?"<<endl;

  monthlyPay -= 10;
  intPaid = (monthlyPay*months)-prin;
  totalPaid = intPaid+prin;

  cout<<"\nThe total interest paid is $"<<fixed<<setprecision(2)<<intPaid<<" and the total amount you'll pay is $"<<fixed<<setprecision(2)<<totalPaid<<"."<<endl;

  return months;
}

//input validation. Ensure value is a positive integer
int validate(int input){
  while(!cin || input <= 0){
    if(!cin){
      cin.clear();
      cin.ignore(10000, '\n');
      cout<<"\tInvalid input, please re-enter: ";
      cin>>input;
    } else if (input <= 0){
      cout<<"\tAge cannot be 0 or less\n\tRe-enter age in years: ";
      cin>>input;
    }
  }

  return input;
}

//overloaded function with the same functionality, just for doubles
double validate(double input){ 
  while(!cin || input <= 0){
    if(!cin){
      cin.clear();
      cin.ignore(10000, '\n');
      cout<<"\tInvalid input, please re-enter: ";
      cin>>input;
    } else if (input <= 0){
      cout<<"\tValue cannot be 0 or less\n\tRe-enter value: ";
      cin>>input;
    }
  }

  return input;
}
