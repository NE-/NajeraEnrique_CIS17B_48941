/*
 * File:    main.cpp
 * Author:  Enrique Najera (copied from book)
 * Purpose: Rewrite thread application
 *          for Qt 5.5.x
 * 15 December 2015
 */

#include <QApplication>

#include "imagewindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    ImageWindow imageWin;
    imageWin.resize(400, 300);
    imageWin.show();
    return app.exec();
}
