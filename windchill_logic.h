#ifndef WINDCHILL_LOGIC_H
#define WINDCHILL_LOGIC_H

#include <QString>

// 声明逻辑类
class Windchill_Logic;

// 1. 友元函数声明：用于在类外部执行特定的校验逻辑
bool globalValidator(const Windchill_Logic& logic, const QString &temp, const QString &wind);

// 2. 函数对象 (Functor)：将计算逻辑封装成一个对象
class WindchillCalculator {
public:
    double operator()(double T, double V); // 重载括号运算符
};

class Windchill_Logic
{
public:
    Windchill_Logic();
    bool validateInput(const QString &tempInput, const QString &windInput);
    double calculateWindChill(double T, double V);

    // 声明友元，允许 globalValidator 访问私有成员 isValidNumber
    friend bool globalValidator(const Windchill_Logic& logic, const QString &temp, const QString &wind);

private:
    bool isValidNumber(const QString &input, bool isWindSpeed);
};

#endif