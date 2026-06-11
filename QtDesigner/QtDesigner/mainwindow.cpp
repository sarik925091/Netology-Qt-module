#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , newWindow(new linkDb(this))
    , newWindow_2(new Dialog(this))
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_createLinkDB_clicked()
{
    newWindow->show();
}

void MainWindow::on_query_clicked()
{
    newWindow_2->show();
}