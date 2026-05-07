#ifndef POWER_LOGIC_H
#define POWER_LOGIC_H

#include <QString>

class Power_Logic
{
public:
    Power_Logic();
    ~Power_Logic();  // 新增：析构函数用于释放动态内存

    int power(int base, int exponent);
    bool validateInput(int base, int exponent, QString &errorMsg);
    QString showProcess(int base, int exponent, int result);
    QString formatResult(int base, int exponent, int result);

    // ========== 新增功能（不影响原有代码） ==========

    // 1. 友元函数声明
    friend void showPowerInfo(const Power_Logic& logic);

    // 2. 函数对象的使用示例
    int calculateWithFunctor(int base, int exponent);

    // 3. 动态内存分配示例
    void saveResult(int base, int exponent, int result);
    QString getLastResult() const;

private:
    // 动态内存分配：存储最后一次计算结果的指针
    int* lastResultPtr;
    int* lastBasePtr;
    int* lastExponentPtr;
};

// 4. 函数对象（仿函数）类
class PowerCalculator {
public:
    int operator()(int base, int exponent) const;
};

#endif