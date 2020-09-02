#include "mainwindow.h"
#include "customwindow.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CustomWIndow c;
    c.show();

   // MainWindow w;
   // w.show();

    qApp->setStyleSheet("QLineEdit { background-color: green}");
    return a.exec();
}

