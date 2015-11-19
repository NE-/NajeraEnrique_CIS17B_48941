/*
 * File:    bomb.cpp
 * Author:  Enrique Najera
 * Purpose: Holds bomb logic, collisions
 * 18 November 2015
 */

#include "bomb.h"

//extern Game *game; // For score update

// Start constructor Bomb
Bomb::Bomb()
{
    setPixmap(QPixmap(":/images/bomb.png"));

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}// End constructor Bomb

// Start method move
void Bomb::move()
{
    // Check Collisions
    QList<QGraphicsItem *>colliding_items = collidingItems();
    for (int i = 0, s = colliding_items.size(); i < s; ++i)
    {
        if (typeid(*(colliding_items[i])) == typeid(Enemy))
        {
            // Increase score
            //game->score->increase();

            // If bomb hits enemy, remove both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }
    // Move Up
    setPos(x(), y()-10);

    if (y() < -10)
    {
        scene()->removeItem(this);
        delete this;
    }
}// End method move

