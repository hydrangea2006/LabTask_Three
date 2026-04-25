#ifndef RECURSIVEEXPONENT_H
#define RECURSIVEEXPONENT_H

#include <QWidget>
#include "power_logic.h"

namespace Ui {
class recursiveexponent;
}

class recursiveexponent : public QWidget
{
    Q_OBJECT

public:
    explicit recursiveexponent(QWidget *parent = nullptr);
    ~recursiveexponent();

private slots:
    void on_btn_calculate_clicked();
    void on_btn_clear_clicked();

private:
    Ui::recursiveexponent *ui;
    Power_Logic logic;
};

#endif