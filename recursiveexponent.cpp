#include "recursiveexponent.h"
#include "ui_recursiveexponent.h"
#include <QMessageBox>
#include <QDebug>  // 新增：用于友元函数输出

recursiveexponent::recursiveexponent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::recursiveexponent)
{
    ui->setupUi(this);
}

recursiveexponent::~recursiveexponent()
{
    delete ui;
}

void recursiveexponent::on_btn_calculate_clicked()
{
    QString baseStr = ui->lineEdit_base->text();
    QString expStr = ui->lineEdit_exponent->text();

    if (baseStr.isEmpty() || expStr.isEmpty()) {
        QMessageBox::warning(this, "输入错误", "请填写底数和指数！");
        return;
    }

    bool baseOk, expOk;
    int base = baseStr.toInt(&baseOk);
    int exponent = expStr.toInt(&expOk);

    if (!baseOk || !expOk) {
        QMessageBox::warning(this, "输入错误", "请输入有效的整数！");
        return;
    }

    QString errorMsg;
    if (!logic.validateInput(base, exponent, errorMsg)) {
        QMessageBox::warning(this, "输入错误", errorMsg);
        return;
    }

    int result = logic.power(base, exponent);

    // ========== 新增：演示新增功能（不影响原有显示） ==========

    // 1. 保存结果到动态内存
    logic.saveResult(base, exponent, result);

    // 2. 使用函数对象计算（仅用于演示，不影响原有结果）
    int functorResult = logic.calculateWithFunctor(base, exponent);

    // 3. 友元函数输出调试信息（控制台可见）
    showPowerInfo(logic);

    // ========== 原有显示逻辑完全不变 ==========
    ui->label_result->setText(logic.formatResult(base, exponent, result));

    // 可选：在显示过程中追加新增功能的演示信息（不改变原有格式）
    QString process = logic.showProcess(base, exponent, result);
    process += "\n【新增功能演示】\n";
    process += "-------------------------------------------\n";
    process += "函数对象计算结果: " + QString::number(functorResult) + "\n";
    process += logic.getLastResult() + "\n";
    process += "（友元函数信息已输出到控制台）\n";

    ui->textEdit_process->setPlainText(process);
}

void recursiveexponent::on_btn_clear_clicked()
{
    ui->lineEdit_base->clear();
    ui->lineEdit_exponent->clear();
    ui->label_result->setText("等待计算...");
    ui->textEdit_process->clear();
    ui->lineEdit_base->setFocus();
}