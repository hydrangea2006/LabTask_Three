#ifndef CIRCLECAL_LOGIC_H
#define CIRCLECAL_LOGIC_H

#include <QString>
#include <functional>

// 前置声明友元类
class CircleFormatter;

class Circlecal_Logic
{
    // 友元声明：CircleFormatter 可以访问私有成员
    friend class CircleFormatter;

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
    double PI = 3.14159265358979323846;  // 非const，允许友元访问（逻辑层不会修改）
};

// ========== 新增：函数对象（仿函数）==========
// 用于按指定精度四舍五入
class PrecisionRounder
{
public:
    explicit PrecisionRounder(int decimals) : m_decimals(decimals) {}

    // 重载 operator()，使其成为函数对象
    double operator()(double value) const
    {
        double factor = 1.0;
        for (int i = 0; i < m_decimals; ++i) factor *= 10.0;
        return std::round(value * factor) / factor;
    }

private:
    int m_decimals;
};

#endif