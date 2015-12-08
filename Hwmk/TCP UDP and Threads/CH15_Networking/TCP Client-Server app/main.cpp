/*
 * File:    main.cpp
 * Author:  Enrique Najera (copied from book)
 * Purpose: Rewrite thread application
 *          for Qt 5.5.x
 * 15 December 2015
 */

#include <QApplication>

#include "tripplanner.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    TripPlanner tripPlanner;
    tripPlanner.show();
    return app.exec();
}
