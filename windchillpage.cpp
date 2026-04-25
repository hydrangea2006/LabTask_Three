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
    Windchill_Logic logic;

    QString tempStr = ui->temp_input->text();
    QString windStr = ui->wind_input->text();

    if (!logic.validateInput(tempStr, windStr)) {
        ui->Output->setText("Invalid input!");
        return;
    }

    double result = logic.calculateWindChill(tempStr.toDouble(), windStr.toDouble());

    ui->Output->setText(QString("Result: %1").arg(result));
}


void windchillpage::on_Reset_Button_clicked()
{
    ui->Output->clear();
    ui->temp_input->clear();
    ui->wind_input->clear();
}

