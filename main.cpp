#include "mainwindow.h"
#include <iostream>
#include <QApplication>
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    cout << "Hello World!" << endl;
    return QCoreApplication::exec();
}
