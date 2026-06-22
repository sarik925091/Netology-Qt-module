#include "stopwatch_sig.h"
#include "ui_stopwatch_sig.h"

stopwatch_sig::stopwatch_sig(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::stopwatch_sig)
{
    ui->setupUi(this);

    updatetimer_ = new QTimer(this);

    updatetimer_->setInterval(10);
    updatetimer_->setSingleShot(false);
    connect(updatetimer_, &QTimer::timeout, this, &stopwatch_sig::updateDisplay);

}

stopwatch_sig::~stopwatch_sig()
{
    delete ui;
}

void stopwatch_sig::updateDisplay()
{
    qint64 totalMs = accumulated + elapsedTimer.elapsed();
    int ms_ = totalMs % 1000;
    int sec_ = (totalMs / 1000) % 60;
    int min_ = (totalMs / 60000) % 60;
    sig_updateDisplay(QString("%1:%2.%3")
                          .arg(min_, 2, 10, QChar('0'))
                          .arg(sec_, 2, 10, QChar('0'))
                          .arg(ms_, 3, 10, QChar('0')));
}

void stopwatch_sig::start()
{
    elapsedTimer.start();
    updatetimer_->start();
}

void stopwatch_sig::stop()
{
    updatetimer_->stop();
    accumulated += elapsedTimer.elapsed();
}

void stopwatch_sig::reset()
{
    updatetimer_->stop();
    accumulated = 0;
}

