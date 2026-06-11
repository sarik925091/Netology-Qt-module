#include "linkdb.h"
#include "ui_linkdb.h"

linkDb::linkDb(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::linkDb)
{
    ui->setupUi(this);
}

linkDb::~linkDb()
{
    delete ui;
}
