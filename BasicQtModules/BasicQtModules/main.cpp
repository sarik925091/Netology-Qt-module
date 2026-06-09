#include <QCoreApplication>


#include <QtSql/QSqlDatabase>

#include <QtNetwork/QAbstractNetworkCache>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QAbstractNetworkCache* cache;       // interface!!

    //QSqlDatabase db = QSqlDatabase::addDatabase("test");
    // db.setHostName("host");
    // db.setDatabaseName("customdb");
    // db.setUserName("seriy");
    // db.setPassword("netology123");
    return QCoreApplication::exec();
}
