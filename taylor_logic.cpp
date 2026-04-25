#include "taylor_logic.h"
#include <cmath>

Taylor_Logic::Taylor_Logic() {}

double Taylor_Logic::factorial(int num)
{
    if (num <= 1) {
        return 1;
    }
    return num * factorial(num - 1);
}

double Taylor_Logic::power(int x, int exp)
{
    if (exp == 0) {
        return 1;
    }
    return x * power(x, exp - 1);
}

double Taylor_Logic::taylorSeries(int x, int n, int currentTerm)
{
    if (currentTerm >= n) {
        return 0;
    }
    double term = power(x, currentTerm) / factorial(currentTerm);
    return term + taylorSeries(x, n, currentTerm + 1);
}

bool Taylor_Logic::validateInput(int x, int n, QString &errorMsg)
{
    if (x < 0) {
        errorMsg = "❌ 错误：x 必须是非负整数！";
        return false;
    }
    if (n < 1) {
        errorMsg = "❌ 错误：项数 n 必须大于等于 1！";
        return false;
    }
    return true;
}

QString Taylor_Logic::formatResult(int x, int n, double result, double exactValue, double error)
{
    QString resultText;
    resultText += "═══════════════════════════════════════\n";
    resultText += QString("        泰勒级数计算 e^%1\n").arg(x);
    resultText += "═══════════════════════════════════════\n\n";
    resultText += QString("📊 计算结果 (使用 %1 项):\n").arg(n);
    resultText += QString("   e^%1 ≈ %2\n\n").arg(x).arg(result, 0, 'f', 10);
    resultText += QString("🎯 精确值 (cmath库):\n");
    resultText += QString("   e^%1 = %2\n\n").arg(x).arg(exactValue, 0, 'f', 10);
    resultText += QString("📈 误差:\n");
    resultText += QString("   %1\n\n").arg(error, 0, 'f', 10);
    resultText += "💡 提示: 项数 n 越大，计算结果越精确！\n";
    return resultText;
}

QString Taylor_Logic::showFactorialSteps(int num)
{
    if (num <= 1) {
        return QString("%1! = 1").arg(num);
    }
    return QString("%1! = %1 × %2!\n%3")
        .arg(num)
        .arg(num - 1)
        .arg(showFactorialSteps(num - 1));
}

QString Taylor_Logic::showPowerSteps(int x, int exp)
{
    if (exp == 0) {
        return QString("%1^0 = 1").arg(x);
    }
    return QString("%1^%2 = %1 × %1^%3\n%4")
        .arg(x)
        .arg(exp)
        .arg(exp - 1)
        .arg(showPowerSteps(x, exp - 1));
}

QString Taylor_Logic::showTaylorSteps(int x, int n, int currentTerm)
{
    if (currentTerm >= n) {
        return "";
    }

    double termValue = power(x, currentTerm) / factorial(currentTerm);
    QString termStr;

    if (currentTerm == 0) {
        termStr = QString("第 %1 项: %2^%3 / %3! = 1 / 1 = %4")
                      .arg(currentTerm + 1)
                      .arg(x)
                      .arg(currentTerm)
                      .arg(termValue);
    } else {
        termStr = QString("第 %1 项: %2^%3 / %3! = %4 / %5 = %6")
                      .arg(currentTerm + 1)
                      .arg(x)
                      .arg(currentTerm)
                      .arg(power(x, currentTerm))
                      .arg(factorial(currentTerm))
                      .arg(termValue);
    }

    QString remaining = showTaylorSteps(x, n, currentTerm + 1);
    if (remaining.isEmpty()) {
        return termStr;
    }
    return termStr + "\n" + remaining;
}