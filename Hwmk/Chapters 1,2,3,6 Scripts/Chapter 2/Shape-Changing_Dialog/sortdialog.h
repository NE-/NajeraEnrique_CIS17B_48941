/*
 * File:    main.cpp
 * Author:  Enrique Najera
 * Purpose: Convert the QT 4 examples to QT 5
 * 28 October 2015
 */

#ifndef SORTDIALOG_H
#define SORTDIALOG_H


#include <QDialog>

#include "ui_sortdialog.h"

class SortDialog : public QDialog, public Ui::SortDialog
{
    Q_OBJECT

public:
    SortDialog(QWidget *parent = 0);

    void setColumnRange(QChar first, QChar last);
};

#endif // SORTDIALOG_H
