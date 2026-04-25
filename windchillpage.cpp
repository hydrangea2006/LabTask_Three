#include "WindchillPage.h"
#include "ui_WindchillPage.h"
#include "windchill_logic.h"

windchillpage::windchillpage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::windchillpage)
{
    ui->setupUi(this);
}

windchillpage::~windchillpage()
{
    delete ui;
}

void windchillpage::on_Convert_button_clicked()
{
    // 3. 动态内存分配：在堆上创建对象
    // 这种方式需要手动管理生命周期（delete），但在处理大型对象或需要跨函数传递时非常有用
    Windchill_Logic *logicPtr = new Windchill_Logic();

    QString tempStr = ui->temp_input->text();
    QString windStr = ui->wind_input->text();

    // 使用 1. 友元函数 进行验证（替代原有的 logic.validateInput）
    if (!globalValidator(*logicPtr, tempStr, windStr)) {
        ui->Output->setText("Invalid input!");
        delete logicPtr; // 退出前必须释放内存
        return;
    }

    // 使用 2. 函数对象 进行计算
    WindchillCalculator calculator;
    double tVal = tempStr.toDouble();
    double vVal = windStr.toDouble();
    double result = calculator(tVal, vVal); // 像调用函数一样使用对象

    ui->Output->setText(QString("Result: %1").arg(result));

    // 释放动态分配的内存
    delete logicPtr;
}

void windchillpage::on_Reset_Button_clicked()
{
    ui->Output->clear();
    ui->temp_input->clear();
    ui->wind_input->clear();
}