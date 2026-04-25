#include "power_logic.h"

Power_Logic::Power_Logic() {}

int Power_Logic::power(int base, int exponent)
{
    if (exponent == 1) {
        return base;
    }
    return base * power(base, exponent - 1);
}

bool Power_Logic::validateInput(int base, int exponent, QString &errorMsg)
{
    if (exponent < 1) {
        errorMsg = "指数必须大于等于 1！";
        return false;
    }
    return true;
}

QString Power_Logic::formatResult(int base, int exponent, int result)
{
    return QString("%1^%2 = %3").arg(base).arg(exponent).arg(result);
}

QString Power_Logic::showProcess(int base, int exponent, int result)
{
    QString process;

    process += "═══════════════════════════════════════\n";
    process += "        递归计算过程详解\n";
    process += "═══════════════════════════════════════\n\n";

    process += QString("计算: %1^%2\n\n").arg(base).arg(exponent);

    // 第一步：展开递归
    process += "【第1步】递归展开（递推阶段）\n";
    process += "-------------------------------------------\n";

    for (int i = exponent; i >= 1; i--) {
        process += QString("  power(%1, %2)").arg(base).arg(i);
        if (i == 1) {
            process += QString(" = %1  ← 终止条件\n").arg(base);
        } else {
            process += QString(" = %1 × power(%2, %3)\n").arg(base).arg(base).arg(i - 1);
        }
    }

    // 第二步：回归计算
    process += "\n【第2步】递归回归（回溯阶段）\n";
    process += "-------------------------------------------\n";

    int tempResult = 1;
    for (int i = 1; i <= exponent; i++) {
        tempResult *= base;
        if (i == 1) {
            process += QString("  power(%1, 1) = %2\n").arg(base).arg(tempResult);
        } else {
            process += QString("  power(%1, %2) = %3 × power(%4, %5) = %3 × %6 = %7\n")
                           .arg(base).arg(i).arg(base).arg(base).arg(i-1)
                           .arg(tempResult / base).arg(tempResult);
        }
    }

    // 第三步：最终结果
    process += "\n═══════════════════════════════════════\n";
    process += QString("【最终结果】%1^%2 = %3\n").arg(base).arg(exponent).arg(result);
    process += "═══════════════════════════════════════\n";

    return process;
}