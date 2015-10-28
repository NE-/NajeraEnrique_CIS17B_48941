/*
 * File:    game.cpp
 * Author:  Enrique Najera
 * Purpose: CSC 17 B Personal Project
 *          Main game logic/setup
 * DUE DATE GOES HERE
 */

#include "game.h"

// Start constructor Game
Game::Game(QWidget *parent)
{
    // Create scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,160,144);
    setBackgroundBrush(QBrush(QImage(":/images/bkgd.png")));

    // View properties
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(160,160);

    // Create player
    player = new Player();
    player->setPos(0,128);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // Add player after creation
    scene->addItem(player);

    // Enemy spawner
    QTimer * timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000);

    // Create music object then play
    QMediaPlayer *music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/bkgd.mp3"));
    music->play();


    /***********************************
     * TODO button to speed up enemies *
     * *********************************/
    toolButton = new QToolButton();
    toolButton->setAutoFillBackground(true);
    toolButton->setIcon(QIcon(":/images/icon.png"));
    toolButton->setToolTip("Click the character to continue!");
    scene->addWidget(toolButton);

    // Show view
    show();
}// End constructor Game
