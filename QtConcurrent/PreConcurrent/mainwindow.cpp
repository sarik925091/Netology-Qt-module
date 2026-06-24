#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->sb_initNum->setValue(200000);
    ui->rb_synchOff->setChecked(true);

   race1 = new Controller(&m);
   race2 = new Controller(&m);

   concurRace1 = new ExampleRace(&m);
   concurRace2 = new ExampleRace(&m);

    //Сигналы по завершению работы потоков
    connect(race1, &Controller::sig_WorkFinish, [&](){
        //отображаем только когда второй поток закончит работу
        if(countFinish == 0){
            countFinish++;
        }
        else{
            ui->te_debug->append("Искомое число равно: " + QString::number(number) + ", а должно быть " +
                                  QString::number(ui->sb_initNum->value()*2));
            ui->pb_start->setEnabled(true);
        }

    });

    connect(race2, &Controller::sig_WorkFinish, [&](){

        if(countFinish == 0){
            countFinish++;
        }
        else{
            ui->te_debug->append("Искомое число равно: " + QString::number(number) + ", а должно быть " +
                                 QString::number(ui->sb_initNum->value()*2));
            ui->pb_start->setEnabled(true);
        }

    });


    connect(concurRace1, &ExampleRace::sig_Finish, [&](){

        if(countFinish == 0){
            countFinish++;
        }
        else{
            ui->te_debug->append("Искомое число равно: " + QString::number(number) + ", а должно быть " +
                                 QString::number(ui->sb_initNum->value()*2));
            ui->pb_start->setEnabled(true);
        }
    });

    connect(concurRace2, &ExampleRace::sig_Finish, [&](){

        if(countFinish == 0){
            countFinish++;
        }
        else{
            ui->te_debug->append("Искомое число равно: " + QString::number(number) + ", а должно быть " +
                                 QString::number(ui->sb_initNum->value()*2));
            ui->pb_start->setEnabled(true);
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
    delete race1;
    delete race2;
    delete concurRace1;
    delete concurRace2;
}

//Метод запускает два потока
void MainWindow::StartRace(void){


    if(ui->rb_qtConcur->isChecked())
    {
        bool mutexOn = ui->rb_mutexOn->isChecked();
        int initNum = ui->sb_initNum->value();
        auto calc1 = [this, mutexOn, initNum] { return concurRace1->DoWork(&number, !mutexOn, initNum); }; // !mutexOn -> ++ не атомарна!!
        auto calc2 = [this, mutexOn, initNum] { return concurRace2->DoWork(&number, !mutexOn, initNum); };

        QFuture<void> result1 = QtConcurrent::run(calc1);
        QFuture<void> result2 = QtConcurrent::run(calc2);
    }
    else{
        race1->operate(&number, ui->rb_mutexOn->isChecked(), ui->sb_initNum->value());
        race2->operate(&number, ui->rb_mutexOn->isChecked(), ui->sb_initNum->value());
    }
}

//Обработка кнопки "Старт"
void MainWindow::on_pb_start_clicked()
{
    ui->pb_start->setEnabled(false);
    countFinish = 0;
    number = 0;
    StartRace( );
}

