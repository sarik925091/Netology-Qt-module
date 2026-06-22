#ifndef STOPWATCH_SIG_H
#define STOPWATCH_SIG_H

#include <QMainWindow>
#include <QTimer>
#include <QElapsedTimer>

namespace Ui {
class stopwatch_sig;
}

class stopwatch_sig : public QMainWindow
{
    Q_OBJECT

public:
    explicit stopwatch_sig(QWidget *parent = nullptr);
    ~stopwatch_sig();

    void updateDisplay();
    void start();
    void stop();
    void reset();

signals:
    void sig_updateDisplay(QString val_update);

private:
    Ui::stopwatch_sig *ui;
    QTimer *updatetimer_;
    QElapsedTimer elapsedTimer;
    qint64 accumulated = 0;
};

#endif // STOPWATCH_SIG_H
