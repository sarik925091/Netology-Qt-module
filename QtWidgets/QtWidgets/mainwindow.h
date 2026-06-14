#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "zodiac_desc.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;


private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    zodiac_desc* ZD_ui;
    const int set_max_PB = 100;
    const int set_min_PB = 0;
    QStringList CB_name_zodiac;
    int PB_counter = 0;
};
#endif // MAINWINDOW_H
