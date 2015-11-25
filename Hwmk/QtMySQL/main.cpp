/*
 * File: main.cpp
 * Author: Enrique Najera (copied from example in
 *                         'mysql qt drivers.zip')
 * Purpose: Retrieve local SQL database
 * 25 November 2015
 */

// Q_LIBS
#include <QApplication>
#include <QDebug>
#include <QSql>
#include <QSqlQuery>
#include <QSqlDatabase>

struct Connection{
    QSqlDatabase db;
    bool connected;
};


Connection createConnection();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connection connection = createConnection();

    if ( !connection.connected )
    {
        qDebug() << "Not connected!";
        return 1;
    }
    else
    {
        qDebug() << "Connected!";

        QSqlQuery query;

        query.exec("SELECT * FROM data");

        while (query.next())
        {
            QString data = query.value(0).toString();
            qDebug() << "data:" << data;
        }
        connection.db.close();
        return 0;
    }
    return a.exec();
}

Connection createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("qtmysql");
    db.setUserName("root");
    db.setPassword("");

    Connection connection;
    connection.db = db;

    if (!db.open())
    {
        qDebug() << "Database error occurred";
        connection.connected = false;
        return connection;
    }

    connection.connected = true;

    return connection;
}
