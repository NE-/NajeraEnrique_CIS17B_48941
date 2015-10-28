/*
 * File:    bullet.cpp
 * Author:  Enrique Najera
 * Purpose: CSC 17 B Personal Project
 *          Creates bullet for killing enemies
 * DUE DATE GOES HERE
 */

#include "bullet.h"

// Start constructor Bullet
Bullet::Bullet()
{
    // Set graphics
    setPixmap(QPixmap(":/images/bullet.png"));

    // Timer to make bullet move right
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);

}// End constructor Bullet

// Start method move
void Bullet::move()
{
    // Check for collisions
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if (typeid(*(colliding_items[i])) == typeid(Enemy))
        {
            // Increase score

            // Decrease Enemy health by 1
            //enemy->decHealth(1);

            //if (enemy->getHealth() == 0)
            //{
                // Remove both
                scene()->removeItem(colliding_items[i]);
                scene()->removeItem(this);

                // Delete from memory
                delete colliding_items[i];
                delete this;

                return;
            /*}
            delete this;

            return;*/
        }
    }// End collision checking

    // Move bullet right
    setPos(x()+10,y());

    // Delete if bullet off scene
    if (pos().x() > 200)
    {
        scene()->removeItem(this);
        delete this;
    }
}// End method move
