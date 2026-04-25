#include "coffeeshoppage.h"
#include "ui_coffeeshoppage.h"
#include <QString>

coffeeshoppage::coffeeshoppage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::coffeeshoppage),
    shop(new coffeeshop()),  // ========== 新增：动态内存分配 ==========
    smallSold(0),
    mediumSold(0),
    largeSold(0)
{
    ui->setupUi(this);
    setWindowTitle("Coffee Shop");
    updateDisplay();
}

coffeeshoppage::~coffeeshoppage()
{
    delete ui;
    delete shop;  // ========== 新增：释放动态分配的内存 ==========
}

void coffeeshoppage::on_buyBtn_clicked()
{
    // 获取输入
    int small = ui->smallInput->text().toInt();
    int medium = ui->mediumInput->text().toInt();
    int large = ui->largeInput->text().toInt();

    // 验证输入
    // ========== 修改：shop. 改为 shop-> ==========
    if (!shop->validateInput(small, medium, large)) {
        ui->messageLabel->setText("Message: Invalid input! Please enter positive numbers and at least one coffee.");
        return;
    }

    // 销售咖啡
    shop->sellCoffee(smallSold, mediumSold, largeSold, small, medium, large);

    // 清空输入框
    ui->smallInput->clear();
    ui->mediumInput->clear();
    ui->largeInput->clear();

    // 更新显示
    updateDisplay();
    ui->messageLabel->setText("Message: Purchase successful!");
}

void coffeeshoppage::on_pushButton_clicked()
{
    // 重置所有数据
    smallSold = 0;
    mediumSold = 0;
    largeSold = 0;

    // 清空输入框
    ui->smallInput->clear();
    ui->mediumInput->clear();
    ui->largeInput->clear();

    // 更新显示
    updateDisplay();
    ui->messageLabel->setText("Message: All data reset.");
}

void coffeeshoppage::updateDisplay()
{
    // 更新总杯数
    int totalCups = smallSold + mediumSold + largeSold;
    ui->cupCountLabel->setText(QString("Total Cups Sold: %1").arg(totalCups));

    // 更新总盎司数
    int totalOunces = shop->getTotalOunces(smallSold, mediumSold, largeSold);
    ui->totalOuncesLabel->setText(QString("Total Ounces Sold: %1 oz").arg(totalOunces));

    // 更新总金额
    double totalMoney = shop->getTotalMoney(smallSold, mediumSold, largeSold);
    ui->totalMoneyLabel->setText(QString("Total Revenue: $%1").arg(totalMoney, 0, 'f', 2));
}