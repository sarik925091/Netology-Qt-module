#ifndef ZODIAC_DESC_H
#define ZODIAC_DESC_H

#include <QDialog>

namespace Ui {
class zodiac_desc;
}

class zodiac_desc : public QDialog
{
    Q_OBJECT

public:
    explicit zodiac_desc(QWidget *parent = nullptr);
    ~zodiac_desc();

    void setDescription(const QString &text);

private:
    Ui::zodiac_desc *ui;
};

#endif // ZODIAC_DESC_H
