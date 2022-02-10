//Chris Caldwell
//CPSC 1071: 1
//Mission Possible
//9/6/21
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
  int months;
  double principal, interest, monthlyPay, years;

  //prompt the user for input for calculation
  cout << "\n** Welcome to the CPSC 1071 Payment Calculator **\n";

  cout << "\nEnter the principal amount: ";
  cin >> principal;

  cout << "Enter the annual interest rate (in %): ";
  cin >> interest;

  cout << "Enter the monthly payment: ";
  cin >> monthlyPay;

  cout << "\nCalculating...\n\n";

  if(principal<0||interest<0||monthlyPay<0){
    cout << "ERROR: One or more negative values entered!"<<endl;
    return 1;
  }

  //calculate time to pay off loan
  months = round((log(monthlyPay)-log(monthlyPay-((interest/1200.0)*principal))
	)/log((interest/1200.0)+1.0));

  years = months/12.0;

  //print output
  cout << months;
  cout << " months (";
  //round years to 1 decimal place
  cout << setprecision(2) << years;
  cout << " years) are needed to pay your loan off.\n\n";

  monthlyPay += 10.0;
  months -= round((log(monthlyPay)-log(monthlyPay-((interest/1200.0)*principal)
	))/log((interest/1200.0)+1.0));

  cout << "Did you know if you paid an additional $10 per month, you would" << 
	  " pay off your loan ";
  cout << months;
  cout << " months earlier?\n";
}
