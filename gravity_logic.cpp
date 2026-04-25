#include "gravity_logic.h"
#include <cmath>

const double G = 9.8;

Gravity_Logic::Gravity_Logic() {}

double Gravity_Logic::calculateDistance(double time)
{
    return 0.5 * G * time * time;
}

QString Gravity_Logic::generateTable()
{
    QString result;
    result.append("Time (seconds)\tDistance (meters)\n");
    result.append("================================\n");

    for (int t = 1; t <= 10; t++)
    {
        double distance = calculateDistance(t);
        result.append(QString("%1\t\t%2\n").arg(t).arg(distance, 0, 'f', 2));
    }

    return result;
}