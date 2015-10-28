/*
 * File:    player.cpp
 * Author:  Enrique Najera
 * Purpose: CSC 17 B Personal Project
 *          Creates player properties
 * DUE DATE GOES HERE
 */

#include "player.h"

// Start constructor Player
Player::Player()
{
    // Set graphics
    setPixmap(QPixmap(":/images/player.png"));

    // Create sounds
    snd_bullet = new QMediaPlayer();
    snd_bullet->setMedia(QUrl("qrc:/sounds/bullet.wav"));
    snd_jump = new QMediaPlayer();
    snd_jump->setMedia(QUrl("qrc:/sounds/jump.wav"));

    // INIT vars
    jumpSpeed = 10;
    timerMs = 60;
    ammo = 8;

}// End constructor Player

// Start method keyPressEvent
void Player::keyPressEvent(QKeyEvent *event)
{
    // Right moves right
    if (event->key() == Qt::Key_Right)
    {
        // Bound detection
        if (pos().x() < 138)
            setPos(x()+10,y());
    }
    // Left moves left
    else if (event->key() == Qt::Key_Left)
    {
        // Bound detection
        if (pos().x() > 1)
            setPos(x()-10,y());
    }
    // Up jumps
    else if (event->key() == Qt::Key_Up)
    {
        // Timer for animation
        timer = new QTimer();
        connect(timer, SIGNAL(timeout()), this, SLOT(jump()));
        timer->start(timerMs);

        // Stop timer and INIT jumpspeed if jump complete
        if (jump() == false)
        {
            jumpSpeed = 10;
            //timer->stop();
            delete timer;
        }

        // Play jump sound
        if (snd_jump->state() == QMediaPlayer::PlayingState)
        {
            snd_jump->setPosition(0);
        }
        else if (snd_jump->state() == QMediaPlayer::StoppedState)
        {
            snd_jump->play();

        }
    }
    // Space shoots bullet
    else if (event->key() == Qt::Key_Space)
    {
        // If has ammo, shoot
        if (ammo > 0)
        {
            // Create a bullet
            Bullet *bullet = new Bullet();
            bullet->setPos(x(),y());
            scene()->addItem(bullet);

            // Remove 1 bullet from inventory
            ammo--;
        }

        // Play bullet sound
        if (snd_bullet->state() == QMediaPlayer::PlayingState)
        {
            snd_bullet->setPosition(0);
        }
        else if (snd_bullet->state() == QMediaPlayer::StoppedState)
        {
            snd_bullet->play();

        }
    }
}// End method keyPressEvent

// Start method jump
bool Player::jump()
{
    // Move up
    setPos(x(),y()-jumpSpeed);

    // If player pos y reaches pixel 88, go down
    if (y() == 88)
    {
        jumpSpeed = -10;
    }
    // If player hits floor, dont move
    else if (y() == 128)
    {
        jumpSpeed = 0;

        return false;  // No longer jumping
        timer->stop(); // Stop timer
    }

    return true; // Is jumping
}// End method jump

// Start method spawn
void Player::spawn()
{
    Enemy *enemy = new Enemy();
    //enemy->setHealth();
    scene()->addItem(enemy);
}// End method spawn

