/*
 * File:    player.h
 * Author:  Enrique Najera
 * Purpose: Constructs entities
 * 18 November 2015
 */

#ifndef PLAYER_H
#define PLAYER_H

// Q_LIBS
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QObject>

// USER_LIBS
#include "bomb.h"
#include "enemy.h"

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player();

    void keyPressEvent(QKeyEvent *event);
private:
    // Create Obj
    Bomb  *bomb;
    Enemy *enemy;
public slots:
    void spawn();
};

#endif // PLAYER_H
