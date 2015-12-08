/*
 * File:    threaddialog.h
 * Author:  Enrique Najera (copied from book)
 * Purpose: Rewrite thread application
 *          for Qt 5.5.x
 * 15 December 2015
 */

#ifndef THREADDIALOG_H
#define THREADDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QHBoxLayout>

#include "thread.h"

class QPushButton;

class ThreadDialog : public QDialog
{
    Q_OBJECT

public:
    ThreadDialog(QWidget *parent = 0);

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void startOrStopThreadA();
    void startOrStopThreadB();

private:
    Thread threadA;
    Thread threadB;
    QPushButton *threadAButton;
    QPushButton *threadBButton;
    QPushButton *quitButton;
};

#endif
