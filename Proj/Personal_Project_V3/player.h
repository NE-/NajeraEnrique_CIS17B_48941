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
    // Constructor
    Player();

    // Key events
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    // Function Prototypes
    void collisions(); // Checks collisions with Things

    // Mutator and Accessor functions
    void setName(QString n){ name = n; }
    QString getName() const{ return name; }

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
private:
    QString name;

};// End class Player

#endif // PLAYER_H
