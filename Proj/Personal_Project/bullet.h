/*
 * File:    bullet.h
 * Author:  Enrique Najera
 * Purpose: CSC 17 B Personal Project
 *          Creates bullet for killing enemies
 * DUE DATE GOES HERE
 */

#ifndef BULLET_H
#define BULLET_H

// Q_LIBS
#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>

// SYS_LIBS
#include <typeinfo>

// USER_LIBS
#include "enemy.h"

// Start class Bullet
class Bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    // Constructors
    Bullet();

    //Enemy *enemy;
public slots:
    void move(); // Moves bullet right
};// End class Bullet

#endif // BULLET_H
