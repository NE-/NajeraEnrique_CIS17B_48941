/*
 * File:    player.cpp
 * Author:  Enrique Najera
 * Purpose: Constructs entities
 * 18 November 2015
 */

#include "player.h"

// Start constructor Player
Player::Player()
{
    setPixmap(QPixmap(":/images/player.png"));

}// End constructor Player

// Start method keyPressEvent
void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left)
    {
        if (x() > 10)
            setPos(x()-10, y());
    }
    else if (event->key() == Qt::Key_Right)
    {
        if (x() < 260)
            setPos(x()+10, y());
    }
    else if (event->key() == Qt::Key_Space)
    {
        bomb = new Bomb();
        bomb->setPos(x()+12, y());
        scene()->addItem(bomb);
    }
}// End method KeyPressEvent

// Start method spawn
void Player::spawn()
{
    enemy = new Enemy();
    scene()->addItem(enemy);
}// End method spawn
