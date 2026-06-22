 #ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stopwatch_sig.h"


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

    qint64 parseTimeString(const QString &str);
    QString msToString(qint64 totalMs);

private slots:
    void on_PB_start_and_stop_clicked();

    void on_PB_reset_and_circle_clicked();

public slots:
    void slots_update_lcd(QString val_update);

private:
    Ui::MainWindow *ui;
    stopwatch_sig *stopwatch;
    QString update_val_for_circle;
    QString val_circles;
    int counter_circles = 0;

    const QString start_ = "Старт";
    const QString stop_ = "Стоп";
    const QString reset_ = "Сброс";
    const QString circle_ = "Круг";
};
#endif // MAINWINDOW_H
