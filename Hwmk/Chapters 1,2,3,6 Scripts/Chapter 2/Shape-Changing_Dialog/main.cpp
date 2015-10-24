/*
 * File:    main.cpp
 * Author:  Enrique Najera
 * Purpose: Convert the QT 4 examples to QT 5
 * 28 October 2015
 */


#include <QApplication>

#include "sortdialog.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    SortDialog *dialog = new SortDialog;
    dialog->setColumnRange('C', 'F');
    dialog->show();
    return app.exec();
}
