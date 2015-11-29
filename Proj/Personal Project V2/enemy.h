/*
 * File:    enemy.h
 * Author:  Enrique Najera
 * Purpose: Holds enemy logic
 * 18 November 2015
 */

#ifndef ENEMY_H
#define ENEMY_H

// Q_LIBS
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QFont>

// SYS_LIBS
#include <stdlib.h>

class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy();

    // Accessor Functions
    int getEnemySpeed() const;
private:
    // Declare Variables
    int randNum;
    int enemySpeed;

    // Declare Objects
    QTimer *timer;
public slots:
    void move(); // Moves enemy down
    // Mutator Functions
    void setEnemySpeed(int); // Speed enemy
};

#endif // ENEMY_H
