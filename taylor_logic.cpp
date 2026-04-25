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

// ==================== 新增代码从这里开始 ====================

// 函数对象实现
double FactorialFunctor::operator()(int num)
{
    if (num <= 1) return 1;
    return num * (*this)(num - 1);
}

PowerFunctor::PowerFunctor(int b) : base(b) {}

double PowerFunctor::operator()(int exp)
{
    if (exp == 0) return 1;
    return base * (*this)(exp - 1);
}

QString PrecisionComparator::operator()(double result, double exactValue)
{
    double error = std::abs(exactValue - result);
    double errorRate = (exactValue != 0) ? (error / std::abs(exactValue)) * 100 : 0;

    QString output;
    output += "───────────────────────────────────────\n";
    output += "📊 精度分析 (使用函数对象):\n";
    output += QString("   绝对误差: %1\n").arg(error, 0, 'f', 10);
    output += QString("   相对误差: %1%\n").arg(errorRate, 0, 'f', 6);

    if (errorRate < 0.001) {
        output += "   精度评级: 🌟🌟🌟 极高精度\n";
    } else if (errorRate < 0.1) {
        output += "   精度评级: 🌟🌟 高精度\n";
    } else if (errorRate < 1) {
        output += "   精度评级: 🌟 中等精度\n";
    } else {
        output += "   精度评级: ⚠️ 低精度，建议增加项数 n\n";
    }
    return output;
}
// 友元函数实现 - 不使用 const
double calculateErrorRate(Taylor_Logic& logic, int x, int n)
{
    double result = logic.taylorSeries(x, n, 0);  // 现在没问题了
    double exactValue = std::exp(x);
    if (exactValue == 0) return 0;
    return std::abs(exactValue - result) / std::abs(exactValue) * 100;
}

// 新增成员函数实现
double Taylor_Logic::calculateWithFunctor(int x, int n)
{
    FactorialFunctor factFunc;
    PowerFunctor powerFunc(x);
    double sum = 0;

    for (int term = 0; term < n; ++term) {
        double powerResult = powerFunc(term);
        double factResult = factFunc(term);
        if (factResult != 0) {
            sum += powerResult / factResult;
        }
    }
    return sum;
}

void Taylor_Logic::addToHistory(int x, int n, double result)
{
    HistoryRecord* newRecord = new HistoryRecord;
    newRecord->x = x;
    newRecord->n = n;
    newRecord->result = result;
    newRecord->exactValue = std::exp(x);
    newRecord->next = head;
    head = newRecord;
}

QString Taylor_Logic::getHistory() const
{
    QString historyText;
    historyText += "═══════════════════════════════════════\n";
    historyText += "           计算历史记录\n";
    historyText += "═══════════════════════════════════════\n\n";

    HistoryRecord* current = head;
    int count = 0;

    while (current != nullptr) {
        count++;
        historyText += QString("[%1] e^%2 ≈ %3  (精确值: %4, n=%5)\n")
                           .arg(count)
                           .arg(current->x)
                           .arg(current->result, 0, 'f', 8)
                           .arg(current->exactValue, 0, 'f', 8)
                           .arg(current->n);
        current = current->next;
    }

    if (count == 0) {
        historyText += "暂无历史记录\n";
    } else {
        historyText += QString("\n共 %1 条记录\n").arg(count);
    }
    return historyText;
}

void Taylor_Logic::clearHistory()
{
    while (head != nullptr) {
        HistoryRecord* temp = head;
        head = head->next;
        delete temp;
    }
}