#ifndef GRAVITY_LOGIC_H
#define GRAVITY_LOGIC_H

#include <QString>

class Gravity_Logic
{
public:
    Gravity_Logic();
    double calculateDistance(double time);
    QString generateTable();
};

#endif