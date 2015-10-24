/*
 * File:    main.cpp
 * Author:  Enrique Najera
 * Purpose: Convert the QT 4 examples to QT 5
 * 28 October 2015
 */

#include <QApplication>

#include "finddialog.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    FindDialog *dialog = new FindDialog;
    dialog->show();
    return app.exec();
}
