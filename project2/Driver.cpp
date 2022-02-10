//Chris Caldwell
//CPSC 1070: 1
//10/15/21

#include "Simulation.h"
#include "WorkPay.h"

#include <iostream>

using namespace std;

int main(){
  //run Simulation
  Simulation fableSim;

  fableSim.runOneGame();

  //run WorkPay
  int hours;

  while(true){
    cout<<endl;
    cout<<"How many hours have you worked? (enter '9000' to quit) ";
    cin>>hours;

    while(!cin || hours <= 0){
      if(!cin){	
        cin.clear();
	cin.ignore(10000, '\n');
	cout<<"Invalid input, please re-enter: ";
	cin>>hours;
      } else if(hours <= 0){
        cout<<"Value cannot be 0 or less, please re-enter: ";
	cin>>hours;
      }
    }

    if(hours == 9000)
      exit(0);

    WorkPay workPay = WorkPay(hours);

    double h, d;

    h = workPay.retrieveHours();
    d = workPay.retrieveDays();

    cout<<"Hours worked: "<<h<<endl;
    cout<<"Days worked: "<<d<<endl;
  } 
}
