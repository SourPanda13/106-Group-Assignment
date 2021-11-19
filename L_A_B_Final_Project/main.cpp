#include "mainwindow.h"

#include <QApplication>

//Main cpp where the program starts

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
