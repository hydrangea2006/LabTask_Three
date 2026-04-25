#ifndef COINTOSS_LOGIC_H
#define COINTOSS_LOGIC_H

#include <QString>
#include <QVector>

class CoinToss_Logic
{
public:
    CoinToss_Logic();
    QString singleToss();
    QVector<QString> tossCoin(int times);
    int countHeads(const QVector<QString> &results);
    int countTails(const QVector<QString> &results);
    bool validateInput(int times, QString &errorMsg);
    QString formatResults(int times, const QVector<QString> &results);
};

#endif