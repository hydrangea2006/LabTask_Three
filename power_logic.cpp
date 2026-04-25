#include "power_logic.h"
#include <QDebug>

Power_Logic::Power_Logic()
    : lastResultPtr(nullptr), lastBasePtr(nullptr), lastExponentPtr(nullptr)
{
    // 原有构造函数，只新增了指针初始化
}

// 新增：析构函数
Power_Logic::~Power_Logic()
{
    // 释放动态分配的内存
    delete lastResultPtr;
    delete lastBasePtr;
    delete lastExponentPtr;
}

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

// ========== 新增功能实现 ==========

// 1. 友元函数实现（可以访问类的私有成员）
void showPowerInfo(const Power_Logic& logic)
{
    qDebug() << "========== Power_Logic 信息 ==========";
    if (logic.lastResultPtr && logic.lastBasePtr && logic.lastExponentPtr) {
        qDebug() << "上次计算:" << *logic.lastBasePtr << "^" << *logic.lastExponentPtr
                 << "=" << *logic.lastResultPtr;
    } else {
        qDebug() << "暂无历史计算记录";
    }
    qDebug() << "======================================";
}

// 2. 函数对象的使用方法
int Power_Logic::calculateWithFunctor(int base, int exponent)
{
    PowerCalculator calculator;  // 创建函数对象
    return calculator(base, exponent);  // 像函数一样调用
}

// 3. 动态内存分配：保存计算结果
void Power_Logic::saveResult(int base, int exponent, int result)
{
    // 释放旧的内存
    delete lastResultPtr;
    delete lastBasePtr;
    delete lastExponentPtr;

    // 动态分配新内存
    lastResultPtr = new int(result);
    lastBasePtr = new int(base);
    lastExponentPtr = new int(exponent);
}

// 获取最后一次保存的结果
QString Power_Logic::getLastResult() const
{
    if (lastResultPtr && lastBasePtr && lastExponentPtr) {
        return QString("保存的记录: %1^%2 = %3")
            .arg(*lastBasePtr).arg(*lastExponentPtr).arg(*lastResultPtr);
    }
    return QString("暂无保存的记录");
}

// ========== 函数对象（仿函数）的实现 ==========
int PowerCalculator::operator()(int base, int exponent) const
{
    // 使用循环实现幂运算（不改变原有递归逻辑）
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}