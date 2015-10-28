/*
 * File:    player.h
 * Author:  Enrique Najera
 * Purpose: CSC 17 B Personal Project
 *          Creates player properties
 * DUE DATE GOES HERE
 */

#ifndef PLAYER_H
#define PLAYER_H

// Q_LIBS
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QObject>
#include <QMediaPlayer>
#include <QDebug> // For outputting values --[[DELETE]]

// SYS_LIBS
#include "bullet.h"
#include "enemy.h"

// Start class Player
class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    // Constructors
    Player();

    // Events
    void keyPressEvent(QKeyEvent *event);

    // Create objects
    QTimer *timer;
public slots:
    bool jump();
    void spawn(); // Spawns enemies
private:
    // Declare Variables
    int jumpSpeed;
    int timerMs;
    int ammo;

    // Create objects
    QMediaPlayer *snd_bullet;
    QMediaPlayer *snd_jump;
};// End class Player

#endif // PLAYER_H
