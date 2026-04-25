#include "circlecalpage.h"
#include "ui_circlecalpage.h"
#include <QMessageBox>

circlecalpage::circlecalpage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::circlecalpage)
{
    ui->setupUi(this);
}

circlecalpage::~circlecalpage()
{
    delete ui;
}

void circlecalpage::on_calculateBtn_clicked()
{
    bool ok1, ok2, ok3, ok4;
    double x1 = ui->x1Edit->text().toDouble(&ok1);
    double y1 = ui->y1Edit->text().toDouble(&ok2);
    double x2 = ui->x2Edit->text().toDouble(&ok3);
    double y2 = ui->y2Edit->text().toDouble(&ok4);

    if (!ok1 || !ok2 || !ok3 || !ok4) {
        QMessageBox::warning(this, "Input Error", "Please enter valid numbers!");
        return;
    }

    if (!logic.validateInputs(x1, y1, x2, y2)) {
        QMessageBox::warning(this, "Input Error", "Invalid input values!");
        return;
    }

    double radius = logic.calculateRadius(x1, y1, x2, y2);
    double diameter = logic.calculateDiameter(radius);
    double circumference = logic.calculateCircumference(radius);
    double area = logic.calculateArea(radius);

    ui->radiusLabel->setText(QString("Radius: %1").arg(radius, 0, 'f', 2));
    ui->diameterLabel->setText(QString("Diameter: %1").arg(diameter, 0, 'f', 2));
    ui->circumferenceLabel->setText(QString("Circumference: %1").arg(circumference, 0, 'f', 2));
    ui->areaLabel->setText(QString("Area: %1").arg(area, 0, 'f', 2));
}