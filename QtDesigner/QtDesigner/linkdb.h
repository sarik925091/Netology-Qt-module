#ifndef LINKDB_H
#define LINKDB_H

#include <QDialog>

namespace Ui {
class linkDb;
}

class linkDb : public QDialog
{
    Q_OBJECT

public:
    explicit linkDb(QWidget *parent = nullptr);
    ~linkDb();

private:
    Ui::linkDb *ui;
};

#endif // LINKDB_H
