#include "taylorpage.h"
#include "ui_taylorpage.h"
#include <cmath>

taylorpage::taylorpage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::taylorpage)
{
    ui->setupUi(this);
    setWindowTitle("泰勒级数计算 e^x");
}

taylorpage::~taylorpage()
{
    delete ui;
}

void taylorpage::on_btn_calculate_clicked()
{
    int x = ui->lineEdit_x->text().toInt();
    int n = ui->lineEdit_n->text().toInt();

    QString errorMsg;
    if (!logic.validateInput(x, n, errorMsg)) {
        ui->textEdit_result->setPlainText(errorMsg);
        ui->textEdit_process->clear();
        return;
    }

    double result = logic.taylorSeries(x, n, 0);
    double exactValue = std::exp(x);
    double error = std::abs(exactValue - result);

    ui->textEdit_result->setPlainText(logic.formatResult(x, n, result, exactValue, error));

    QString processText;
    processText += "═══════════════════════════════════════\n";
    processText += "        泰勒级数展开过程\n";
    processText += "═══════════════════════════════════════\n\n";
    processText += "公式: e^x = Σ (x^n / n!)\n";
    processText += QString("计算 e^%1 的展开:\n\n").arg(x);
    processText += logic.showTaylorSteps(x, n, 0);
    processText += "\n\n───────────────────────────────────────\n";
    processText += "递归过程演示:\n\n";
    processText += "以计算 x^2 / 2! 为例:\n";
    processText += logic.showPowerSteps(x, 2) + "\n";
    processText += logic.showFactorialSteps(2);

    // ========== 新增演示内容（不影响原有功能）==========
    processText += "\n\n───────────────────────────────────────\n";
    processText += "🔧 新增功能演示:\n\n";

    // 函数对象演示
    FactorialFunctor factFunc;
    processText += "1. 函数对象 (仿函数):\n";
    processText += QString("   5! = %1 (使用FactorialFunctor)\n").arg(factFunc(5));

    PowerFunctor powerFunc(3);
    processText += QString("   3^4 = %1 (使用PowerFunctor)\n\n").arg(powerFunc(4));

    // 友元函数演示
    double errorRate = calculateErrorRate(logic, x, n);
    processText += "2. 友元函数:\n";
    processText += QString("   通过友元函数计算的误差率: %1%\n\n").arg(errorRate, 0, 'f', 6);

    // 精度分析
    PrecisionComparator comparator;
    processText += "3. 精度分析:\n";
    processText += comparator(result, exactValue);

    // 历史记录
    logic.addToHistory(x, n, result);
    processText += "\n4. 动态内存分配 (历史记录):\n";
    processText += logic.getHistory();

    ui->textEdit_process->setPlainText(processText);
}