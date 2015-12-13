/*
 * File:    player.h
 * Author:  Enrique Najera
 * Purpose: Player properties
 * 16 December 2015
 */

#ifndef PLAYER_H
#define PLAYER_H

// Q_LIBS
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QPixmap>

// USER_LIBS
#include "room.h"

// Start class Player
class Player : public QGraphicsPixmapItem
{
public:
    Player();

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    void collisions();

    int posX;
    int posY;

    // Sprite position
    int left,
        forward,
        right,
        backward,
        frame,    // For animation
        stopSpam; // Stops interaction dialog spamming
    char pState;  // State of player
    char facing;  // Holds what thing player is facing

    QPixmap *sheet_player;

};// End class Player

#endif // PLAYER_H
