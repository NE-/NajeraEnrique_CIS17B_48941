/*
 * File:    main.cpp
 * Author:  Enrique Najera
 * Purpose: Create ClockGears obj
 * 16 December 2015
 */

// Q_LIBS
#include <QApplication>

// USER_LIBS
#include "clockgears.h"

// Start method main
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ClockGears cGears;
    cGears.show();
    return a.exec();
}// End method main
