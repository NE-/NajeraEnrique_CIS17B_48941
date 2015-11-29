/*
 * File:    enemy.cpp
 * Author:  Enrique Najera
 * Purpose: Holds enemy logic
 * 18 November 2015
 */

#include "enemy.h"

// Start constructor Enemy
Enemy::Enemy()
{
    setEnemySpeed(50);

    // Place randomly
    randNum = rand() % 280;
    setPos(randNum, 0);

    setPixmap(QPixmap(":/images/enemy.png"));

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(this->getEnemySpeed());
}// End constructor Enemy

// Start method setSpeed
void Enemy::setEnemySpeed(int speed)
{
    enemySpeed = speed;
}// End method setSpeed

// Start method getEnemySpeed
int Enemy::getEnemySpeed() const
{
    return enemySpeed;
}// End method getEnemySpeed

// Start method move
void Enemy::move()
{
    setPos(x(), y() + 5);
    if (y() < 0)
    {
        //game->score->decrease(); bugs with player object
        scene()->removeItem(this);
        delete this;
    }
}// End method move
