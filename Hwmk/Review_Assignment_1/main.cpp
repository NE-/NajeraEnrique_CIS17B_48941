/*
 * File:    main.cpp
 * Author:  Enrique Najera
 * Purpose: Review classes
 * Date:    09 September 2015
 */

// Q_LIBS
#include <QApplication>
#include <QLabel>
#include <QString>
#include <QDebug>

// SYS_LIBS
#include <string>

// USER_LIBS
#include "Array.h"

// Start Method main
int main(int argc, char *argv[])
{
    // Declare Variables
    //char **charArray;
    const char *address;

    QApplication a(argc, argv);

    // Create Array
    Array array(10,10);

    qDebug() << array.getArray();

    address = (char *)array.getArray();

    /* Assign int Array to char Array
    // -Dynamic Allocation
    charArray = new char*[array.getNrows()];

    // -Fill Array
    for (int i = 0; i < array.getNrows(); ++i)
        for (int j = 0; j < array.getNcols(); ++j)
            charArray[i][j] = (int)array.getArray();
    */

    QString classArray = address;

    QLabel *label = new QLabel(classArray);
    label->show();

    /* Deallocate Memory
    for (int i = 0; i < array.getNrows; ++i)
        delete [] charArray[i];
    delete [] charArray;
    */

    return a.exec();
} // End Method main
