#include "palindromepage.h"
#include "ui_palindromepage.h"
#include "palindrome_logic.h"

PalindromePage::PalindromePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PalindromePage)
{
    ui->setupUi(this);
}

PalindromePage::~PalindromePage()
{
    delete ui;
}

void PalindromePage::on_checkBtn_clicked()
{
    Palindrome_Logic *logicPtr = new Palindrome_Logic(ui->inputEdit->text());

    // 调用逻辑
    if (logicPtr->testPalindrome()) {
        ui->resultLabel->setText("Result: True");
        ui->resultLabel->setStyleSheet("color: green;");
    } else {
        ui->resultLabel->setText("Result: False");
        ui->resultLabel->setStyleSheet("color: red;");
    }

    reportStatus(*logicPtr);

    delete logicPtr;
}

void PalindromePage::on_resetBtn_clicked()
{
    ui->inputEdit->clear();
    ui->resultLabel->setText("Output");
    ui->resultLabel->setStyleSheet("color: black;");
}