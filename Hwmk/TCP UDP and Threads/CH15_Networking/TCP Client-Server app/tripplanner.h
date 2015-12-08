/*
 * File:    tripplanner.h
 * Author:  Enrique Najera (copied from book)
 * Purpose: Rewrite thread application
 *          for Qt 5.5.x
 * 15 December 2015
 */

#ifndef TRIPPLANNER_H
#define TRIPPLANNER_H

#include <QDialog>
#include <QTcpSocket>
#include <QPushButton>

#include "ui_tripplanner.h"

class QPushButton;

class TripPlanner : public QDialog, private Ui::TripPlanner
{
    Q_OBJECT

public:
    TripPlanner(QWidget *parent = 0);

private slots:
    void connectToServer();
    void sendRequest();
    void updateTableWidget();
    void stopSearch();
    void connectionClosedByServer();
    void error();

private:
    void closeConnection();

    QPushButton *searchButton;
    QPushButton *stopButton;
    QTcpSocket tcpSocket;
    quint16 nextBlockSize;
};

#endif
