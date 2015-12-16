/*
 * File:    database.cpp
 * Author:  Enrique Najera
 * Purpose: Connect to database to retrieve names
 * 16 December 2015
 */

// USER_LIBS
#include "database.h"

// Start constructor Database
Database::Database()
{

}// End constructor Database

// Start method createConnection
bool Database::createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("db_room3");
    db.setUserName("root");
    db.setPassword("");

    if (!db.open())
    {
        QMessageBox::critical(0, QObject::tr("Database Error"),
                              db.lastError().text());
        return false;
    }

    return true;
}// End method createConnections

