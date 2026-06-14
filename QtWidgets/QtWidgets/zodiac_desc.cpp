#include "zodiac_desc.h"
#include "ui_zodiac_desc.h"

zodiac_desc::zodiac_desc(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::zodiac_desc)
{
    ui->setupUi(this);
}

zodiac_desc::~zodiac_desc()
{
    delete ui;
}

void zodiac_desc::setDescription(const QString &text)
{
    ui->description->setText(text);
}
