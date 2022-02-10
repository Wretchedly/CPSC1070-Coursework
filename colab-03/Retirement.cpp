#include "Retirement.h"

#include <iostream>
#include <iomanip>

using namespace std;

void Retirement::estimateDriver(){
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
  cout<<"\tEnter the estimate annual return on investent (in percent): ";
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
	return;
      default:
	break;
    }
  }
}

double Retirement::estimateEarnings(int age, int retAge, double retSave, double 	contrib, double percent){
  double earnings, monthlyGrowth, totalGrowth;

  for(int i = age*12; i < retAge*12; i++){
    monthlyGrowth = retSave*((percent/100)/12);
    totalGrowth += monthlyGrowth;
    retSave += contrib + monthlyGrowth;
    earnings = retSave;
  }

  cout<<"Estimated Retirement Savings: $"<<fixed<<setprecision(2)<<earnings<<endl;
  cout<<"Estimated Retirement Growth: $"<<fixed<<setprecision(2)<<totalGrowth<<endl;

  return earnings;
}

//input validation. Ensure value is a positive integer
int Retirement::validate(int input){
  while(!cin || input <= 0){
    if(!cin){
      cin.clear();
      cin.ignore(10000, '\n');
      cout<<"\tInvalid input, please re-enter: ";
      cin>>input;
    } else if(input <= 0){
      cout<<"\tAge cannot be 0 or less\n\tRe-enter age in years: ";
      cin>>input;
    }
  }

  return input;
}

//overloaded function with the same functionality, just for doubles
double Retirement::validate(double input){
  while(!cin || input <=0){
    if(!cin){
      cin.clear();
      cin.ignore(10000, '\n');
      cout<<"\tInvalid input, please re-enter: ";
      cin>>input;
    } else if(input <= 0){
      cout<<"\tValue cannot be 0 or less\n\tRe-enter value: ";
      cin>>input;
    }
  }

  return input;
}
