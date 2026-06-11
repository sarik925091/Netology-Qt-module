#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "dialog.h"
#include "linkdb.h"
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
    void on_createLinkDB_clicked();

    void on_query_clicked();

private:
    Ui::MainWindow *ui;
    linkDb* newWindow;
    Dialog* newWindow_2;
};
#endif // MAINWINDOW_H
