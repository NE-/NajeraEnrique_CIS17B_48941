/*
 * File:    weatherstation.h
 * Author:  Enrique Najera (copied from book)
 * Purpose: Rewrite thread application
 *          for Qt 5.5.x
 * 15 December 2015
 */

#ifndef WEATHERSTATION_H
#define WEATHERSTATION_H

#include <QDialog>
#include <QUdpSocket>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>

class WeatherStation : public QDialog
{
    Q_OBJECT

public:
    WeatherStation(QWidget *parent = 0);

private slots:
    void processPendingDatagrams();

private:
    QUdpSocket udpSocket;

    QLabel *dateLabel;
    QLabel *timeLabel;
    QLabel *temperatureLabel;
    QLabel *humidityLabel;
    QLabel *altitudeLabel;
    QLineEdit *dateLineEdit;
    QLineEdit *timeLineEdit;
    QLineEdit *temperatureLineEdit;
    QLineEdit *humidityLineEdit;
    QLineEdit *altitudeLineEdit;
};

#endif
