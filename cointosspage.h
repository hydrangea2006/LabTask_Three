#ifndef COINTOSSPAGE_H
#define COINTOSSPAGE_H

#include <QWidget>
#include "cointoss_logic.h"

namespace Ui {
class cointosspage;
}

class cointosspage : public QWidget
{
    Q_OBJECT

public:
    explicit cointosspage(QWidget *parent = nullptr);
    ~cointosspage();

private slots:
    void on_tossButton_clicked();

private:
    Ui::cointosspage *ui;
    CoinToss_Logic logic;
};

#endif