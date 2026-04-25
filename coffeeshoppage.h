#ifndef COFFEESHOPPAGE_H
#define COFFEESHOPPAGE_H

#include <QWidget>
#include "coffeeshop_logic.h"

namespace Ui {
class coffeeshoppage;
}

class coffeeshoppage : public QWidget
{
    Q_OBJECT

public:
    explicit coffeeshoppage(QWidget *parent = nullptr);
    ~coffeeshoppage();

private slots:
    void on_buyBtn_clicked();
    void on_pushButton_clicked();

private:
    void updateDisplay();

    Ui::coffeeshoppage *ui;
    coffeeshop *shop;
    int smallSold;
    int mediumSold;
    int largeSold;
};

#endif // COFFEESHOPPAGE_H