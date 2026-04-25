#ifndef POWER_LOGIC_H
#define POWER_LOGIC_H

#include <QString>

class Power_Logic
{
public:
    Power_Logic();
    int power(int base, int exponent);
    bool validateInput(int base, int exponent, QString &errorMsg);
    QString showProcess(int base, int exponent, int result);
    QString formatResult(int base, int exponent, int result);
};

#endif