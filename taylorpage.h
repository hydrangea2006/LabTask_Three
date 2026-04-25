#ifndef TAYLORPAGE_H
#define TAYLORPAGE_H

#include <QWidget>
#include "taylor_logic.h"

namespace Ui {
class taylorpage;
}

class taylorpage : public QWidget
{
    Q_OBJECT

public:
    explicit taylorpage(QWidget *parent = nullptr);
    ~taylorpage();

private slots:
    void on_btn_calculate_clicked();

private:
    Ui::taylorpage *ui;
    Taylor_Logic logic;
};

#endif