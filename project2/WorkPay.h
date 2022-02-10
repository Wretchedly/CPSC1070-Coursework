#ifndef WORKPAY_H
#define WORKPAY_H

class WorkPay {
  public:
    WorkPay(int);
    double retrieveHours(void);
    double retrieveDays(void);

    friend WorkPay operator+(const WorkPay& i, const WorkPay& j);
    friend WorkPay operator-(const WorkPay& i, const WorkPay& j);
    WorkPay operator++(int);
    WorkPay operator--(int);

  private:
    double hours, days;
    void storeData(int);
};
#endif
