/*
 * File:    main.cpp
 * Author:  Enrique Najera (copied from book)
 * Purpose: Rewrite thread application
 *          for Qt 5.5.x
 * 15 December 2015
 */

// Q_LIBS
#include <QApplication>

// USER_LIBS
#include "threaddialog.h"

// Start method main
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    ThreadDialog dialog;
    dialog.show();

    return app.exec();
}// End method main
