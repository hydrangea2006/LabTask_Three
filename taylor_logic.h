#ifndef TAYLOR_LOGIC_H
#define TAYLOR_LOGIC_H

#include <QString>

class Taylor_Logic
{
public:
    Taylor_Logic();

    // 三个递归函数
    double factorial(int num);
    double power(int x, int exp);
    double taylorSeries(int x, int n, int currentTerm);

    // 验证输入
    bool validateInput(int x, int n, QString &errorMsg);

    // 格式化结果
    QString formatResult(int x, int n, double result, double exactValue, double error);

    // 显示递归过程
    QString showTaylorSteps(int x, int n, int currentTerm);
    QString showPowerSteps(int x, int exp);
    QString showFactorialSteps(int num);
};

#endif