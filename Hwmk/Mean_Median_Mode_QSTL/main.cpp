/*
 * File:    main.cpp
 * Author:  Enrique Najera
 * Purpose: Creates window object and shows it
 * 04 November 2015
 */

#include <QApplication>
#include "window.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Window *window = new Window();
    window->show();

    return a.exec();
}
