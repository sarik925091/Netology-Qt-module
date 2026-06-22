#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QString>
#include <QStringList>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , stopwatch(new stopwatch_sig(this))
{
    ui->setupUi(this);

    this->setWindowTitle("Stopwatch");

    ui->PB_reset_and_circle->setText(reset_);
    ui->PB_start_and_stop->setText(start_);

    ui->lcdNumber->setDigitCount(9);
    ui->lcdNumber->display("00:00.000");

    connect(stopwatch, &stopwatch_sig::sig_updateDisplay, this, &MainWindow::slots_update_lcd);
}

MainWindow::~MainWindow()
{
    delete ui;
}

qint64 MainWindow::parseTimeString(const QString &str)
{
    QStringList parts = str.split(':');
    if (parts.size() != 2) return -1;
    QString minutesPart = parts[0];
    QString secondsPart = parts[1]; // "SS.mmm"

    QStringList secParts = secondsPart.split('.');
    if (secParts.size() != 2) return -1;
    QString secStr = secParts[0];
    QString msStr = secParts[1];

    bool ok;
    int min = minutesPart.toInt(&ok);  if (!ok) return -1;
    int sec = secStr.toInt(&ok);       if (!ok) return -1;
    int ms  = msStr.toInt(&ok);        if (!ok) return -1;
    return min * 60000LL + sec * 1000LL + ms;
}

QString MainWindow::msToString(qint64 totalMs)
{
    int ms = totalMs % 1000;
    int sec = (totalMs / 1000) % 60;
    int min = totalMs / 60000; // минуты могут быть любыми
    return QString("%1:%2.%3")
        .arg(min, 2, 10, QChar('0'))
        .arg(sec, 2, 10, QChar('0'))
        .arg(ms, 3, 10, QChar('0'));
}

void MainWindow::on_PB_start_and_stop_clicked()
{
    if (ui->PB_start_and_stop->text() == stop_)
    {
        ui->PB_start_and_stop->setText(start_);
        ui->PB_reset_and_circle->setText(reset_);
        stopwatch->stop();
    }
    else
    {
        ui->PB_start_and_stop->setText(stop_);
        ui->PB_reset_and_circle->setText(circle_);
        stopwatch->start();
    }
}


void MainWindow::on_PB_reset_and_circle_clicked()
{
    if(ui->PB_reset_and_circle->text() == reset_)
    {
        stopwatch->reset();
        ui->TB_result_ofCircle->clear();
    }
    else
    {
        if (ui->TB_result_ofCircle->toPlainText().isEmpty())
        {
            val_circles = update_val_for_circle;
            counter_circles++;
            ui->TB_result_ofCircle->append("Круг          Время          Общее время");
            ui->TB_result_ofCircle->append(QString::number(counter_circles) + "             " + val_circles + "             " + update_val_for_circle);
        }
        else
        {
            qint64 circles_val = parseTimeString(val_circles);
            qint64 update_val = parseTimeString(update_val_for_circle);
            qint64 diff = update_val - circles_val;
            val_circles = msToString(diff);
            counter_circles++;
            ui->TB_result_ofCircle->append(QString::number(counter_circles) + "             " + val_circles + "             " + update_val_for_circle);
        }
    }
}

void MainWindow::slots_update_lcd(QString val_update)
{
    update_val_for_circle = val_update;
    ui->lcdNumber->display(val_update);
}

