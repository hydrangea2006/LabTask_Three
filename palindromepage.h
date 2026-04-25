#ifndef PALINDROMEPAGE_H
#define PALINDROMEPAGE_H

#include <QWidget>

namespace Ui {
class PalindromePage;
}

class PalindromePage : public QWidget
{
    Q_OBJECT

public:
    explicit PalindromePage(QWidget *parent = nullptr);
    ~PalindromePage();

private slots:
    void on_checkBtn_clicked();
    void on_resetBtn_clicked();

private:
    Ui::PalindromePage *ui;
};

#endif