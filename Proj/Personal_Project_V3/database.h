#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>

class Database
{
public:
    Database();
    bool createConnection();
};

#endif // DATABASE_H
