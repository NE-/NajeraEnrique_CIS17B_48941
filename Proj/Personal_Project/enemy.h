/*
 * File:    enemy.h
 * Author:  Enrique Najera
 * Purpose: CSC 17 B Personal Project
 *          Creates enemies to kill
 * DUE DATE GOES HERE
 */

#ifndef ENEMY_H
#define ENEMY_H

// Q_LIBS
#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>

// SYS_LIBS
#include <stdlib.h> // rand()

// Start class Enemy
class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    // Constructors
    Enemy();

    /* NON WORKING ATM
    void setHealth();
    int getHealth() const { return health; }
    void decHealth(int hP) { health - hP; }*/
public slots:
    void move();    // Moves enemy left
private:
    int speed;      // Speed of enemy
    int difficulty; // Difficulty increases speed
    int health;     // Health of new Enemy
};// End class Enemy

#endif // ENEMY_H
