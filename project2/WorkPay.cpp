#include "WorkPay.h"
#include "iostream"

using namespace std;

WorkPay::WorkPay(int hoursWorked){
  storeData(hoursWorked);
}

double WorkPay::retrieveHours(){
  return hours;
}

double WorkPay::retrieveDays(){
  return days;
}

void WorkPay::storeData(int hoursWorked){
  hours = (double)hoursWorked;
  days = hours/8;
}

//overloaded operators
WorkPay operator+(const WorkPay& i, const WorkPay& j){
  WorkPay day(0);
  day.hours = i.hours + j.hours;
  return day;
}

WorkPay operator-(const WorkPay& i, const WorkPay& j){
  WorkPay day(0);
  day.hours = i.hours - j.hours;
  return day;
}

WorkPay WorkPay::operator++(int){
  WorkPay day = *this;
  ++this->hours;
  return day;
}

WorkPay WorkPay::operator--(int){
  WorkPay day = *this;
  --this->hours;
  return day;
}
