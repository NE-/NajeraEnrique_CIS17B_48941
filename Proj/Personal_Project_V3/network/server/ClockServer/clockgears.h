/*
 * File:    clockgears.h
 * Author:  Enrique Najera
 * Purpose: Return time to client
 * 16 December 2015
 */

#ifndef CLOCKGEARS_H
#define CLOCKGEARS_H

// Q_LIBS
#include <QPushButton>
#include <QUdpSocket>
#include <QTimer>
#include <QDateTime>

// Start class ClockGears
class ClockGears : public QPushButton
{
    Q_OBJECT
public:
    ClockGears(QWidget *parent=0);

    int monsterResponse() const; // Send number as monster response
                                 // to player noise

private slots:
    void sendDatagram();

private:
    QUdpSocket udpSocket;
    QTimer     timer;
};// End class ClockGears

#endif // CLOCKGEARS_H
