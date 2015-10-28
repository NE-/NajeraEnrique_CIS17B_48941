/*
 * File:    game.h
 * Author:  Enrique Najera
 * Purpose: CSC 17 B Personal Project
 *          Main game logic/setup
 * DUE DATE GOES HERE
 */

#ifndef GAME_H
#define GAME_H

// Q_LIBS
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QToolButton>
#include <QTimer>
#include <QMediaPlayer>

// USER_LIBS
#include "player.h"

// Start class Game
class Game : public QGraphicsView
{
    Q_OBJECT
public:
    // Constructors
    Game(QWidget *parent = 0);

    // Create objects
    QGraphicsScene *scene;
    QToolButton    *toolButton;

    Player         *player;
};// End class Game

#endif // GAME_H
