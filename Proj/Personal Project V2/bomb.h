/*
 * File:    bomb.h
 * Author:  Enrique Najera
 * Purpose: Holds bomb logic, collisions
 * 18 November 2015
 */

#ifndef EQUIPMENT_H
#define EQUIPMENT_H

// Q_LIBS
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>
#include <QTimer>
#include <QList>

// SYS_LIBS
#include <typeinfo>

// USER_LIBS
#include "enemy.h"
//#include "game.h" messes with player obj

class Bomb : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bomb();
private:
    QTimer *timer;
public slots:
    void move(); // Moves bomb up
};

#endif // EQUIPMENT_H
