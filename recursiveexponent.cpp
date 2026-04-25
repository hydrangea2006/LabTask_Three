#include "recursiveexponent.h"
#include "ui_recursiveexponent.h"
#include <QMessageBox>

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

    ui->label_result->setText(logic.formatResult(base, exponent, result));
    ui->textEdit_process->setPlainText(logic.showProcess(base, exponent, result));
}

void recursiveexponent::on_btn_clear_clicked()
{
    ui->lineEdit_base->clear();
    ui->lineEdit_exponent->clear();
    ui->label_result->setText("等待计算...");
    ui->textEdit_process->clear();
    ui->lineEdit_base->setFocus();
}