/*
 * File:    game.h
 * Author:  Enrique Najera
 * Purpose: Creates game scene and entities
 * 18 November 2015
 */

#ifndef GAME_H
#define GAME_H

// Q_LIBS
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QTimer>
#include <QMediaPlayer>
//#include <QGraphicsTextItem>
//#include <QFont>

// USER_LIBS
#include "player.h"
#include "score.h"

class Game : public QGraphicsView
{
public:
    Game(QWidget *parent=0);
private:
    // Create obj
    QGraphicsScene *scene;
    QTimer *timer;

    Player *player;
    Score  *score;
};

#endif // GAME_H
