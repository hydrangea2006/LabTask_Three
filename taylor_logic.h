#ifndef TAYLOR_LOGIC_H
#define TAYLOR_LOGIC_H

#include <QString>

class Taylor_Logic
{
public:
    Taylor_Logic();

    // 三个递归函数 - 保持原样，不加 const
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

    // ========== 新增 ==========
    // 注意：这里不是 const 引用
    friend double calculateErrorRate(Taylor_Logic& logic, int x, int n);

    double calculateWithFunctor(int x, int n);
    void addToHistory(int x, int n, double result);
    QString getHistory() const;
    void clearHistory();

private:
    struct HistoryRecord {
        int x;
        int n;
        double result;
        double exactValue;
        HistoryRecord* next;
    };
    HistoryRecord* head;
};

// 函数对象
class FactorialFunctor {
public:
    double operator()(int num);
};

class PowerFunctor {
private:
    int base;
public:
    explicit PowerFunctor(int b);
    double operator()(int exp);
};

class PrecisionComparator {
public:
    QString operator()(double result, double exactValue);
};

// 友元函数声明 - 注意：没有 const
double calculateErrorRate(Taylor_Logic& logic, int x, int n);

#endif