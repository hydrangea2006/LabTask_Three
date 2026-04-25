#ifndef CIRCLECAL_LOGIC_H
#define CIRCLECAL_LOGIC_H

#include <QString>

class Circlecal_Logic
{
public:
    Circlecal_Logic();
    double calculateDistance(double x1, double y1, double x2, double y2);
    double calculateRadius(double x1, double y1, double x2, double y2);
    double calculateDiameter(double radius);
    double calculateCircumference(double radius);
    double calculateArea(double radius);
    bool validateInputs(double x1, double y1, double x2, double y2);
    QString formatResult(double radius, double diameter, double circumference, double area);

private:
    const double PI = 3.14159265358979323846;
};

#endif