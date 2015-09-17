/*
 * File:    main.cpp
 * Author:  Enrique Najera
 * Purpose: Abstract, Base and Derived class
 *          Practice
 * Date:    20 September 2015
 */

// Q_LIBS
#include <QApplication>
#include <QLabel>
#include <QString>
#include <QDebug>

// SYS_LIBS
#include <string>

// USER_LIBS
#include "AbstractArray.h"
#include "BaseArray.h"
#include "DerivedArray.h"

// Start Method main
int main(int argc, char *argv[])
{
    // Declare Variables
    const char *address;
    QString output;

    QApplication a(argc, argv);

    // Create Array
    BaseArray ba(10,10);

    // Fill array
    ba.fillArray();

    address = ba.toString(); // Get address

    output = address;        // Assign var output to address

    // Output results in a label
    QLabel *label = new QLabel(output);
    label->show();

    // EXIT_SUCCESS
    return a.exec();
} // End Method main
