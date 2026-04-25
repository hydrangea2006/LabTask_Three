#ifndef COINTOSS_LOGIC_H
#define COINTOSS_LOGIC_H

#include <QString>
#include <QVector>

// 函数对象（Functor）：单次抛硬币
class TossFunctor {
public:
    QString operator()() const;
};

class CoinToss_Logic
{
public:
    CoinToss_Logic();
    ~CoinToss_Logic();                      // 释放动态内存

    QString singleToss();                   // 内部使用仿函数
    QVector<QString> tossCoin(int times);   // 返回结果，同时存入动态数组
    int countHeads(const QVector<QString> &results);
    int countTails(const QVector<QString> &results);
    bool validateInput(int times, QString &errorMsg);
    QString formatResults(int times, const QVector<QString> &results);

    // 友元函数声明（可访问私有成员）
    friend QString getStatistics(const CoinToss_Logic &logic);

private:
    bool* m_resultsArray;        // 动态分配的bool数组，true=heads, false=tails
    int   m_lastTimes;           // 最近一次抛硬币的次数
};

#endif