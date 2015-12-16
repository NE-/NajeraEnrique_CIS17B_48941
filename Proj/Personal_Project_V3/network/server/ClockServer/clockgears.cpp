/*
 * File:    clockgears.cpp
 * Author:  Enrique Najera
 * Purpose: Return time to client
 * 16 December 2015
 */

// USER_LIBS
#include "clockgears.h"

// Start constructor ClockGears
ClockGears::ClockGears(QWidget *parent) : QPushButton(tr("Stop"), parent)
{
    connect(this, SIGNAL(clicked()), this, SLOT(close()));
    connect(&timer, SIGNAL(timeout()), this, SLOT(sendDatagram()));

    timer.start(1000);
    setWindowTitle(tr("Clock"));
}// End constructor ClockGears

// Start method monster response
int ClockGears::monsterResponse() const
{
    return 240;
}// End method monsterResponse

// Start method sendDatagram
void ClockGears::sendDatagram()
{
    QByteArray datagram;
    QDataStream out(&datagram, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_0);
    out << QDateTime::currentDateTime() << monsterResponse();

    udpSocket.writeDatagram(datagram, QHostAddress::LocalHost, 5824);
}// End method sendDatagram
