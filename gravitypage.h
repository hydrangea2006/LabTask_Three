#ifndef GRAVITYPAGE_H
#define GRAVITYPAGE_H

#include <QWidget>
#include "gravity_logic.h"

namespace Ui {
class gravitypage;
}

class gravitypage : public QWidget
{
    Q_OBJECT

public:
    explicit gravitypage(QWidget *parent = nullptr);
    ~gravitypage();

private slots:
    void on_calculateButton_clicked();

private:
    Ui::gravitypage *ui;
    Gravity_Logic logic;
};

#endif // GRAVITYPAGE_H