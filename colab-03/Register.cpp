#include "Register.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

enum Transactions{RESTAURANT, MERCHANDISE, UTLITY, COFFEESHOP, AUTOMOTIVE, DEPOSIT, OTHER};
vector<string> data;

Register::Register(){}

string Register::getFileName(){
  string name;

  while(true){
    cout<<"\tPlease enter the filename: ";
    cin>>name;
    cout<<"\tOpening the file <"<<name<<">"<<endl;

    ifstream regFile;
    regFile.open(name);
    if(regFile){
      return name;
    } else {
      cout<<"Error opening file. Please retry"<<endl;
    }
  }
}

void Register::setFileName(string name_){
  name = name_;
}

bool Register::processTransaction(){
  bool success;
  char runAgain;

  setFileName(getFileName());

  if(readFromFile()){
    success = true;
  } else {
    success = false;
  }

  printFile();

  while(true){
    cout<<"Process another transaction register? (y/n): ";
    cin>>runAgain;

    //prompt user to run register again
    switch(runAgain){
      case 'y':
        processTransaction();
	break;
      case 'n':
	return false;
	break;
      default:
	break;
    }
  }

  return success;
}

bool Register::readFromFile(){
  bool success = true;
  string word;
  fstream regFile;

  regFile.open(name);

  while(regFile >> word){
    data.push_back(word);
  }

  return success;
}

void Register::printFile(){
  int i = 0, j = 0;

  cout<<"Printing Transaction Ledger"<<endl;

  while(i < data.size()){
    for(j = 0; j < data.size()/4; j++){
      cout<<data.at(i)<<" |"; i++;
      cout<<setw(15)<<data[i]<<" |"; i++;
      cout<<setw(11)<<data[i]<<" |"; i++;
      cout<<setw(20)<<data[i]<<endl; i++;
    }
  }

  cout<<"\n";
}
