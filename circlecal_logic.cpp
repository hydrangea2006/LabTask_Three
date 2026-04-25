#include "circlecal_logic.h"
#include <cmath>

Circlecal_Logic::Circlecal_Logic() {}

double Circlecal_Logic::calculateDistance(double x1, double y1, double x2, double y2)
{
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

double Circlecal_Logic::calculateRadius(double x1, double y1, double x2, double y2)
{
    return calculateDistance(x1, y1, x2, y2);
}

double Circlecal_Logic::calculateDiameter(double radius)
{
    return 2 * radius;
}

double Circlecal_Logic::calculateCircumference(double radius)
{
    return 2 * PI * radius;
}

double Circlecal_Logic::calculateArea(double radius)
{
    return PI * radius * radius;
}

bool Circlecal_Logic::validateInputs(double x1, double y1, double x2, double y2)
{
    if (std::isnan(x1) || std::isnan(y1) || std::isnan(x2) || std::isnan(y2))
        return false;
    if (std::isinf(x1) || std::isinf(y1) || std::isinf(x2) || std::isinf(y2))
        return false;
    return true;
}

QString Circlecal_Logic::formatResult(double radius, double diameter, double circumference, double area)
{
    // ========== 新增：使用函数对象 PrecisionRounder 处理精度 ==========
    PrecisionRounder rounder(2);  // 创建函数对象，保留2位小数

    QString result;
    result.append(QString("Radius: %1\n").arg(rounder(radius), 0, 'f', 2));
    result.append(QString("Diameter: %1\n").arg(rounder(diameter), 0, 'f', 2));
    result.append(QString("Circumference: %1\n").arg(rounder(circumference), 0, 'f', 2));
    result.append(QString("Area: %1").arg(rounder(area), 0, 'f', 2));
    return result;
}