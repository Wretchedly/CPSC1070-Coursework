#ifndef LOAN_H
#define LOAN_H

class Loan {
 public:
  void paymentDriver();

 private:
  int paymentMonths(double, double, double);
  int validate(int);
  double validate(double);

};
#endif
