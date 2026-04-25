#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "palindromepage.h"
#include "WindchillPage.h"
#include "coffeeshoppage.h"
#include "gravitypage.h"
#include "circlecalpage.h"
#include "taylorpage.h"
#include "recursiveexponent.h"
#include "cointosspage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    PalindromePage *palPage;
    windchillpage *wcPage;
    coffeeshoppage *csPage;
    gravitypage *gPage;
    circlecalpage *ccpage;
    taylorpage *tpage;
    recursiveexponent *ppage;
    cointosspage *ctPage;
};

#endif