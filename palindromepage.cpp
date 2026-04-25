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
    Palindrome_Logic logic;
    if (logic.testPalindrome(ui->inputEdit->text())) {
        ui->resultLabel->setText("Result: True");
        ui->resultLabel->setStyleSheet("color: green;");
    } else {
        ui->resultLabel->setText("Result: False");
        ui->resultLabel->setStyleSheet("color: red;");
    }
}

void PalindromePage::on_resetBtn_clicked()
{
    ui->inputEdit->clear();
    ui->resultLabel->setText("Output");
    ui->resultLabel->setStyleSheet("color: black;");
}