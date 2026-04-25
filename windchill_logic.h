#ifndef WINDCHILL_LOGIC_H
#define WINDCHILL_LOGIC_H

#include <QString>

class Windchill_Logic
{
public:
    Windchill_Logic();
    bool validateInput(const QString &tempInput, const QString &windInput);
    double calculateWindChill(double T, double V);

private:
    bool isValidNumber(const QString &input, bool isWindSpeed);
};

#endif