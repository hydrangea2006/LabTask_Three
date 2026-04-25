#include "gravitypage.h"
#include "ui_gravitypage.h"

gravitypage::gravitypage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gravitypage)
{
    ui->setupUi(this);
}

gravitypage::~gravitypage()
{
    delete ui;
}

void gravitypage::on_calculateButton_clicked()
{
    ui->outputTextEdit->setText(logic.generateTable());
}