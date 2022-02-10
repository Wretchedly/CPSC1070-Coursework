//Chris Caldwell
//Project 1
//CPSC 1070
//9/17/21

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>

using namespace std;

//function prototypes
void calculateCharges(double[]);
void putCarInfo();

int flip();
void printCoinToss(int);
void runCoinToss(int);
void promptCoinToss();

int main(){
  putCarInfo();
  promptCoinToss();
}

//calculate/display hours and charge for each car
void calculateCharges(double times[]){
  double hSum, cSum;

  cout<<"Car\tHours\tCharge ($)"<<endl;

  for(int i = 0; i < 10; i++){
    double charge;

    //see what charge must be, or if it needs to end loop
    if(times[i] == -999){
      break;	//sorry for break statement
    } else if(times[i] < 0.5){
      charge = 0;
    } else if(times[i] < 1){
      charge = 2;
    } else if(times[i] >= 1 && times[i] < 14){
      charge = 2 + floor(times[i]);
    } else {
      charge = 15;
    }

    //accumulate time and charges, then print individually
    hSum += times[i];
    cSum += charge;

    cout<<fixed;
    cout<<i+1<<"\t"<<setprecision(2)<<times[i]<<"\t"<<setprecision(1)<<charge<<endl;
  }

  //display totals
  cout<<fixed;
  cout<<"Total:\t"<<setprecision(2)<<hSum<<"\t"<<setprecision(1)<<cSum<<endl;
}

void putCarInfo(){
  double times[10];

  cout<<"Enter 10 customer's times:"<<endl;
  for(int i=0; i < 10; i++){
    double input;
    cin>>input;

    //input validation
    if(input == -999){
      times[i] = -999;
      break;	//sorry for using break... again...
    } else if(input <= 0){
      cout<<"Time cannot be less than/equal to 0, please try again!"<<endl;
      i--;
    }else if(cin.fail()){
      cout<<"Invalid input, please try again."<<endl;
      i--;
    } else {
      times[i] = input;
    }
  }

  calculateCharges(times);
}

//randomizer
int flip(){
  int value = rand() % 2;
  return value;
}

//checks if heads or tails
void printCoinToss(int value){
  switch(value){
    case 0:
      cout<<"Heads"<<endl;
      break;
    case 1:
      cout<<"Tails"<<endl;
      break;
  }
}

void runCoinToss(int runs){
  for(int i = 0; i < runs; i++) {
    printCoinToss(flip());
  }
}

//additional driver function for coin toss
void promptCoinToss(){
  int runs;

  cout<<"How many coin flips would you like?: "<<endl;
  cin>>runs;
  if(cin.fail() || runs <= 0) {
    cout<<"Invalid input, please enter a valid integer."<<endl;
  }

  runCoinToss(runs);
}
