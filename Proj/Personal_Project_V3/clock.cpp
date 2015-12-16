/*
 * File:    clock.cpp
 * Author:  Enrique Najera
 * Purpose: Get time from server
 * 16 December 2015
 */

// USER_LIBS
#include "clock.h"

// Start constructor Clock
Clock::Clock(QWidget *parent) : QDialog(parent)
{
    udpSocket.bind(5824);

    connect(&udpSocket, SIGNAL(readyRead()), this, SLOT(processPendingDatagrams()));
    lbl_time = new QLabel(tr("Time: "));
    line_time = new QLineEdit;

    line_time->setReadOnly(true);

    layout_main = new QGridLayout;
    layout_main->addWidget(lbl_time, 0, 0);
    layout_main->addWidget(line_time, 0, 1);
    setLayout(layout_main);

    setWindowTitle("Clock");
}// End constructor Clock

// Start method processPendingDatagrams
void Clock::processPendingDatagrams()
{
    QByteArray datagram;

    do
    {
        datagram.resize(udpSocket.pendingDatagramSize());
        udpSocket.readDatagram(datagram.data(), datagram.size());
    }while(udpSocket.hasPendingDatagrams());

    QDateTime dateTime;

    int monsterResp;

    QDataStream in(&datagram, QIODevice::ReadOnly);
    in.setVersion(QDataStream::Qt_5_0);
    in >> monsterResp;

    line_time->setText(tr("%1").arg(monsterResp));

}// End method processPendingDatagrams
