/*
 * File:    game.cpp
 * Author:  Enrique Najera
 * Purpose: Creates game scene and entities
 * 18 November 2015
 */

#include "game.h"

// Start constructor Game
Game::Game(QWidget *parent)
{
    // Create scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,308,300);
    setBackgroundBrush(QBrush(QImage(":/images/bkgd.png")));

    // Scene properties
    setScene(scene);
    setFixedSize(308,300);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Create player
    player = new Player();
    player->setPos(10,250);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    scene->addItem(player);

    //score = new Score();
    //scene->addItem(score);

    // Enemy Spawner
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000);

    // Create music object then play
    QMediaPlayer *music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/bkgd.mp3"));
    music->play();

    show();
}// End constructor Game

