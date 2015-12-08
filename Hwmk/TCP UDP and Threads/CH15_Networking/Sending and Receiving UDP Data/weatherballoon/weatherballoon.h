/*
 * File:    weatherballoon.h
 * Author:  Enrique Najera (copied from book)
 * Purpose: Rewrite thread application
 *          for Qt 5.5.x
 * 15 December 2015
 */

#ifndef WEATHERBALLOON_H
#define WEATHERBALLOON_H

#include <QPushButton>
#include <QTimer>
#include <QUdpSocket>

class WeatherBalloon : public QPushButton
{
    Q_OBJECT

public:
    WeatherBalloon(QWidget *parent = 0);

    double temperature() const;
    double humidity() const;
    double altitude() const;

private slots:
    void sendDatagram();

private:
    QUdpSocket udpSocket;
    QTimer timer;
};

#endif
