#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    palPage = new PalindromePage(this);
    ui->stackedWidget->addWidget(palPage);
    connect(ui->actionPalindrome, &QAction::triggered, this, [=](){
        ui->stackedWidget->setCurrentWidget(palPage);
    });

    wcPage = new windchillpage(this);
    ui->stackedWidget->addWidget(wcPage);
    connect(ui->actionWindChill, &QAction::triggered, this, [=](){
        ui->stackedWidget->setCurrentWidget(wcPage);
    });

    csPage = new coffeeshoppage(this);
    ui->stackedWidget->addWidget(csPage);
    connect(ui->actionCoffeeShop, &QAction::triggered, this, [=](){
        ui->stackedWidget->setCurrentWidget(csPage);
    });

    gPage = new gravitypage(this);
    ui->stackedWidget->addWidget(gPage);
    connect(ui->actionGravity, &QAction::triggered, this, [=](){
        ui->stackedWidget->setCurrentWidget(gPage);
    });

    ccpage = new circlecalpage(this);
    ui->stackedWidget->addWidget(ccpage);
    connect(ui->actionCirclecal, &QAction::triggered, this, [=](){
        ui->stackedWidget->setCurrentWidget(ccpage);
    });

    tpage = new taylorpage(this);
    ui->stackedWidget->addWidget(tpage);
    connect(ui->actionTaylor_2, &QAction::triggered, this, [=](){
        ui->stackedWidget->setCurrentWidget(tpage);
    });

    ppage = new recursiveexponent(this);
    ui->stackedWidget->addWidget(ppage);
    connect(ui->actionRecursiveExponent, &QAction::triggered, this, [=](){
        ui->stackedWidget->setCurrentWidget(ppage);
    });

    ctPage = new cointosspage(this);
    ui->stackedWidget->addWidget(ctPage);
    connect(ui->actionCoinToss, &QAction::triggered, this, [=](){
        ui->stackedWidget->setCurrentWidget(ctPage);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}