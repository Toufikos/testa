#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_calendarWidget_clicked(const QDate &date)
{
    //qDebug() << date.day();

    //qDebug() << date.year();




}

void MainWindow::on_calendarWidget_windowIconTextChanged(const QString &iconText)
{
   qDebug() << iconText.isUpper();
}

void MainWindow::on_pushButton_clicked()
{

}
