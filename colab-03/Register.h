#ifndef REGISTER_H
#define REGISTER_H

#include <string>

using namespace std;

class Register{
  private:
    string name;
  public:
    Register();
    string getFileName();
    void setFileName(string);
    bool processTransaction();
    bool readFromFile();
    void printFile();
};

#endif
