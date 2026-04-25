#include "cointoss_logic.h"
#include <QRandomGenerator>

CoinToss_Logic::CoinToss_Logic() {}

QString CoinToss_Logic::singleToss() {
    int randomNum = QRandomGenerator::global()->bounded(1, 3);
    return (randomNum == 1) ? "heads" : "tails";
}

QVector<QString> CoinToss_Logic::tossCoin(int times) {
    QVector<QString> results;
    if (times <= 0) return results;

    for (int i = 0; i < times; ++i) {
        results.append(singleToss());
    }
    return results;
}

int CoinToss_Logic::countHeads(const QVector<QString> &results) {
    int count = 0;
    for (const QString &result : results) {
        if (result == "heads") count++;
    }
    return count;
}

int CoinToss_Logic::countTails(const QVector<QString> &results) {
    int count = 0;
    for (const QString &result : results) {
        if (result == "tails") count++;
    }
    return count;
}

bool CoinToss_Logic::validateInput(int times, QString &errorMsg) {
    if (times <= 0) {
        errorMsg = "请输入大于0的次数！";
        return false;
    }
    if (times > 1000) {
        errorMsg = "次数不能超过1000！";
        return false;
    }
    return true;
}

QString CoinToss_Logic::formatResults(int times, const QVector<QString> &results) {
    QString output;
    output += QString("抛硬币 %1 次的结果：\n").arg(times);
    output += "========================\n";

    for (int i = 0; i < results.size(); ++i) {
        output += QString("第 %1 次：%2\n").arg(i + 1).arg(results[i]);
    }

    output += "========================\n";
    output += QString("正面(Heads)次数：%1\n").arg(countHeads(results));
    output += QString("反面(Tails)次数：%1\n").arg(countTails(results));

    return output;
}