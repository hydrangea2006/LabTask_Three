#ifndef WINDCHILLPAGE_H
#define WINDCHILLPAGE_H

#include <QWidget>

namespace Ui { class windchillpage; }

class windchillpage : public QWidget
{
    Q_OBJECT

public:
    explicit windchillpage(QWidget *parent = nullptr);
    ~windchillpage();

private slots:
    void on_Convert_button_clicked();
    void on_Reset_Button_clicked();

private:
    Ui::windchillpage *ui;
};

#endif