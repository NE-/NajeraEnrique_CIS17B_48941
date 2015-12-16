/*
 * File:    database.cpp
 * Author:  Enrique Najera
 * Purpose: Connect to database to retrieve names
 * 16 December 2015
 */

#ifndef DATABASE_H
#define DATABASE_H

// Q_LIBS
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>

// Start class Database
class Database
{
public:
    Database();
    bool createConnection();
};// End class Database

#endif // DATABASE_H
