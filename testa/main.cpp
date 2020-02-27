#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();



    qApp->setStyleSheet("QLineEdit { background-color: yellow}");
    return a.exec();
}
