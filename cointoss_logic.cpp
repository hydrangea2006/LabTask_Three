#include "cointoss_logic.h"
#include <QRandomGenerator>

// 仿函数实现
QString TossFunctor::operator()() const {
    int randomNum = QRandomGenerator::global()->bounded(1, 3);
    return (randomNum == 1) ? "heads" : "tails";
}

// 构造函数
CoinToss_Logic::CoinToss_Logic()
    : m_resultsArray(nullptr), m_lastTimes(0)
{
}

// 析构函数：释放动态内存
CoinToss_Logic::~CoinToss_Logic() {
    delete[] m_resultsArray;
}

// 使用仿函数实现单次抛硬币
QString CoinToss_Logic::singleToss() {
    TossFunctor tf;
    return tf();
}

QVector<QString> CoinToss_Logic::tossCoin(int times) {
    QVector<QString> results;
    if (times <= 0) return results;

    // 释放旧的动态数组，并重新分配
    delete[] m_resultsArray;
    m_resultsArray = new bool[times];
    m_lastTimes = times;

    for (int i = 0; i < times; ++i) {
        QString result = singleToss();
        results.append(result);
        m_resultsArray[i] = (result == "heads");   // 存入动态数组
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

// 友元函数实现：访问私有动态数组，生成统计字符串
QString getStatistics(const CoinToss_Logic &logic) {
    if (logic.m_resultsArray == nullptr || logic.m_lastTimes == 0) {
        return "无抛硬币数据（请先进行一次抛硬币）";
    }
    int heads = 0;
    for (int i = 0; i < logic.m_lastTimes; ++i) {
        if (logic.m_resultsArray[i]) heads++;
    }
    int tails = logic.m_lastTimes - heads;
    return QString("【友元函数统计】总次数: %1, 正面: %2, 反面: %3")
        .arg(logic.m_lastTimes).arg(heads).arg(tails);
}