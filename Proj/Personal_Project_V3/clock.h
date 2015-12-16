/*
 * File:    clock.h
 * Author:  Enrique Najera
 * Purpose: Get time from server
 * 16 December 2015
 */

#ifndef CLOCK_H
#define CLOCK_H

// Q_LIBS
#include <QDialog>
#include <QUdpSocket>
#include <QDateTime>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QtGui>
#include <QtNetwork>

// Start class Clock
class Clock : public QDialog
{
    Q_OBJECT
public:
    Clock(QWidget *parent=0);

private slots:
    void processPendingDatagrams();

private:
    QUdpSocket udpSocket;

    QLabel    *lbl_time;
    QLineEdit *line_time;

    QGridLayout *layout_main;
};// End class Clock

#endif // CLOCK_H
