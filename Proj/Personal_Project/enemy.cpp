/*
 * File:    enemy.cpp
 * Author:  Enrique Najera
 * Purpose: CSC 17 B Personal Project
 *          Creates enemies to kill
 * DUE DATE GOES HERE
 */

#include "enemy.h"

// Start constructor Enemy
Enemy::Enemy()
{
    // Randomize speed for each enemy
    speed = rand() % 5;

    // Spawn outside viewable area
    setPos(200,134);

    // Set graphics
    setPixmap(QPixmap(":/images/enemy.png"));

    // Timer to make enemy move left
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(60);
}// End constructor Enemy

/*void Enemy::setHealth()
{
    health = rand() % 5;
}*/

// Start method move
void Enemy::move()
{
    // Move left
    setPos(x()-speed, y());

    // If enemy passed player, delete and decrease score
    if (pos().x() < 0)
    {
        // Decrease score

        // Delete
        scene()->removeItem(this);
        delete this;
    }
}// End method move
