/*
 * File:    main.cpp
 * Author:  Enrique Najera
 * Purpose: Convert the QT 4 examples to QT 5
 * 28 October 2015
 */

#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow mainWin;
    mainWin.show();
    return app.exec();
}
