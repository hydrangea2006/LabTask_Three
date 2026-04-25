#include "cointosspage.h"
#include "ui_cointosspage.h"
#include <QMessageBox>

cointosspage::cointosspage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cointosspage)
{
    ui->setupUi(this);
}

cointosspage::~cointosspage()
{
    delete ui;
}

void cointosspage::on_tossButton_clicked()
{
    QString timesStr = ui->lineEditTimes->text();

    if (timesStr.isEmpty()) {
        QMessageBox::warning(this, "输入错误", "请输入抛硬币次数！");
        return;
    }

    bool ok;
    int times = timesStr.toInt(&ok);

    if (!ok) {
        QMessageBox::warning(this, "输入错误", "请输入有效的整数！");
        return;
    }

    QString errorMsg;
    if (!logic.validateInput(times, errorMsg)) {
        QMessageBox::warning(this, "输入错误", errorMsg);
        return;
    }

    QVector<QString> results = logic.tossCoin(times);
    ui->resultArea->setText(logic.formatResults(times, results));
}