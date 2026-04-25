#ifndef CIRCLECALPAGE_H
#define CIRCLECALPAGE_H

#include <QWidget>
#include "circlecal_logic.h"

namespace Ui {
class circlecalpage;
}

class circlecalpage : public QWidget
{
    Q_OBJECT

public:
    explicit circlecalpage(QWidget *parent = nullptr);
    ~circlecalpage();

private slots:
    void on_calculateBtn_clicked();

private:
    Ui::circlecalpage *ui;
    Circlecal_Logic *logic;  // ========== 修改：改为指针，用于动态内存分配 ==========
};

#endif // CIRCLECALPAGE_H