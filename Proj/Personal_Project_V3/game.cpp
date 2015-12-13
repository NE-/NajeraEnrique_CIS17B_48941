/*
 * File:    game.cpp
 * Author:  Enrique Najera
 * Purpose: Holds main game window & logic
 * 16 December 2015
 */

// USER_LIBS
#include "game.h"

#include <QDebug>

// Start constructor Game
Game::Game()
{
    // Create scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,384,384); // 256 x 256
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setBackgroundBrush(QPixmap(""));

    // Create buttons
    btn_new = new Button(0);   // New Game
    connect(btn_new, SIGNAL(click()), this, SLOT(newGame()));
    btn_cont = new Button(32); // Continue
    connect(btn_cont, SIGNAL(click()), this, SLOT(newGame()));
    btn_quit = new Button(64); // Quit
    //connect(btn_quit, SIGNAL(click()), , SLOT());

    // Add buttons
    scene->addItem(btn_new);
    scene->addItem(btn_cont);
    scene->addItem(btn_quit);


    // Layout buttons
    btn_new->setPos(50,50);
    btn_cont->setPos(50,100);
    btn_quit->setPos(50,150);

}// End constructor Game

// Start method newGame
void Game::newGame()
{
    // Remove buttons
    scene->removeItem(btn_new);
    scene->removeItem(btn_cont);
    scene->removeItem(btn_quit);

    setBackgroundBrush(QBrush(Qt::black));

    // Create room
    // -Background
    room = new Room();
    scene->addItem(room);

    // -Things
    table1_L    = new Things(0,    0);
    table1_R    = new Things(0,    0);
    table2_L    = new Things(32,   0);
    table2_R    = new Things(32,   0);
    flower1_L   = new Things(0,   32);
    flower1_R   = new Things(0,   32);
    flower2_L   = new Things(32,  32);
    flower2_R   = new Things(32,  32);
    window1_L   = new Things(0,   64);
    window1_R   = new Things(0,   64);
    window2_L   = new Things(32,  64);
    window2_R   = new Things(32,  64);
    chair1_L    = new Things(0,   96);
    chair2_L    = new Things(0,   96);
    chair1_R    = new Things(0,   96);
    chair2_R    = new Things(0,   96);
    picture1_L  = new Things(0,  128);
    picture1_R  = new Things(0,  128);
    picture2_L  = new Things(32,  128);
    picture2_R  = new Things(32,  128);
    carpet_L    = new Things(0,  160);
    carpet_R    = new Things(0,  160);
    cupboard1_L = new Things(0,  192);
    cupboard1_R = new Things(0,  192);
    cupboard2_L = new Things(32,  192);
    cupboard2_R = new Things(32,  192);
    cupboard3_L = new Things(64,  192);
    cupboard3_R = new Things(64,  192);
    cupboard4_L = new Things(96,  192);
    cupboard4_R = new Things(96,  192);
    couch1_L    = new Things(0,  224);
    couch2_L    = new Things(32, 224);
    couch3_L    = new Things(64, 224);
    couch1_R    = new Things(64,  224);
    couch2_R    = new Things(32, 224);
    couch3_R    = new Things(0, 224);

    // Rotate right couch
    couch1_R->setTransformOriginPoint(couch1_R->boundingRect().center());
    couch2_R->setTransformOriginPoint(couch2_R->boundingRect().center());
    couch3_R->setTransformOriginPoint(couch3_R->boundingRect().center());
    couch1_R->setRotation(180);
    couch2_R->setRotation(180);
    couch3_R->setRotation(180);

    // Add all the things
    // -left
    scene->addItem(table1_L);
    scene->addItem(flower1_L);
    scene->addItem(window1_L);
    scene->addItem(chair1_L);
    scene->addItem(chair2_L);
    scene->addItem(picture1_L);
    scene->addItem(carpet_L);
    scene->addItem(cupboard1_L);
    scene->addItem(couch1_L);
    scene->addItem(couch2_L);
    scene->addItem(couch3_L);

    // -right
    scene->addItem(table1_R);
    scene->addItem(flower1_R);
    scene->addItem(window1_R);
    scene->addItem(chair1_R);
    scene->addItem(chair2_R);
    scene->addItem(picture1_R);
    scene->addItem(carpet_R);
    scene->addItem(cupboard1_R);
    scene->addItem(couch1_R);
    scene->addItem(couch2_R);
    scene->addItem(couch3_R);

    // Create player
    player = new Player();
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    // Create dialogs
    switchDialog = new SwitchDialog();

    // Create collision detector
    //collisions = new Collisions();

    // Timer calls game update
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(10);

    // Create and play background music
    snd_bkgdMusic = new QMediaPlayer();
    snd_bkgdMusic->setMedia(QUrl(""));
    snd_bkgdMusic->play();

    setFixedSize(384,384);
}// End method newGame

// Start method update
void Game::update()
{
    // Hide cursor
    setCursor(QCursor(QPixmap(":/img/images/cursor.png")));

    // Check colliding items
    //collisions->checkCollisions();

    // Restart frame every 4 + 4 frames
    if (player->frame > 8)
        player->frame = 0;

    // Moves BKGND image based on player position
    room->setPos(player->posX - 127, player->posY - 127);

    // Move the things based on room position
    // -left
    table1_L->setPos(   room->x() +  80, room->y() + 352);
    table2_L->setPos(   room->x() +  80, room->y() + 352);
    flower1_L->setPos(  room->x() + 144, room->y() + 352);
    flower2_L->setPos(  room->x() + 144, room->y() + 352);
    window1_L->setPos(  room->x() + 112, room->y() +   0);
    window2_L->setPos(  room->x() + 112, room->y() +   0);
    chair1_L->setPos(   room->x() +  48, room->y() +  64);
    chair2_L->setPos(   room->x() + 112, room->y() +  64);
    picture1_L->setPos( room->x() +  48, room->y() +   0);
    picture2_L->setPos( room->x() +  48, room->y() +   0);
    carpet_L->setPos(   room->x() +  80, room->y() +  96);
    cupboard1_L->setPos(room->x() + 144, room->y() +  32);
    cupboard2_L->setPos(room->x() + 144, room->y() +  32);
    cupboard3_L->setPos(room->x() + 144, room->y() +  32);
    couch1_L->setPos(   room->x() +  16, room->y() + 256);
    couch2_L->setPos(   room->x() +  16, room->y() + 224);
    couch3_L->setPos(   room->x() +  16, room->y() + 192);

    // -right
    table1_R->setPos(   room->x() + 272, room->y() + 352);
    table2_R->setPos(   room->x() + 272, room->y() + 352);
    flower1_R->setPos(  room->x() + 208, room->y() + 352);
    flower2_R->setPos(  room->x() + 208, room->y() + 352);
    window1_R->setPos(  room->x() + 240, room->y() +   0);
    window2_R->setPos(  room->x() + 240, room->y() +   0);
    chair1_R->setPos(   room->x() + 240, room->y() +  64);
    chair2_R->setPos(   room->x() + 304, room->y() +  64);
    picture1_R->setPos( room->x() + 304, room->y() +   0);
    picture2_R->setPos( room->x() + 304, room->y() +   0);
    carpet_R->setPos(   room->x() + 272, room->y() +  96);
    cupboard1_R->setPos(room->x() + 208, room->y() +  32);
    cupboard2_R->setPos(room->x() + 208, room->y() +  32);
    cupboard3_R->setPos(room->x() + 208, room->y() +  32);
    couch1_R->setPos(   room->x() + 336, room->y() + 256);
    couch2_R->setPos(   room->x() + 336, room->y() + 224);
    couch3_R->setPos(   room->x() + 336, room->y() + 192);

    // Check interactions
    // -cupboard
    if (player->pState == 'I' && player->facing == 'C')
    {
        switchDialog->show();
        if (switchDialog->getYesClicked() == true)
        {
            scene->removeItem(cupboard1_L);
            scene->removeItem(player);
            scene->addItem(cupboard2_L);
            scene->addItem(player);
            player->setFocus();
        }else{}
    }
    // -chair
    else if (player->pState == 'I' && player->facing == 'c')
    {

    }
    // -couch
    else if (player->pState == 'I' && player->facing == 'Q')
    {

    }
    // -window
    else if (player->pState == 'I' && player->facing == 'W')
    {

    }
    // -picture
    else if (player->pState == 'I' && player->facing == 'P')
    {
        switchDialog->show();
    }
    // -table
    else if (player->pState == 'I' && player->facing == 'T')
    {
        switchDialog->show();
    }
    // -plant
    else if (player->pState == 'I' && player->facing == 'p')
    {
        switchDialog->show();
    }
    // end check interactions

    // Sprite animation
    // -if player is idle
    if (player->pState == 'A')
        player->setPixmap(player->sheet_player->copy(0, player->left, 32, 32));
    else if (player->pState == 'S')
        player->setPixmap(player->sheet_player->copy(0, player->forward, 32, 32));
    else if (player->pState == 'F')
        player->setPixmap(player->sheet_player->copy(0, player->right, 32, 32));
    else if (player->pState == 'W')
        player->setPixmap(player->sheet_player->copy(0, player->backward, 32, 32));

    // If player is moving
    // -frame 1
    if (player->frame == 4 && player->pState != 'X')
    {
        if (player->pState == 'L')
            player->setPixmap(player->sheet_player->copy(32, player->left, 32, 32));
        else if (player->pState == 'D')
            player->setPixmap(player->sheet_player->copy(32, player->forward, 32, 32));
        else if (player->pState == 'R')
            player->setPixmap(player->sheet_player->copy(32, player->right, 32, 32));
        else if (player->pState == 'U')
            player->setPixmap(player->sheet_player->copy(32, player->backward, 32, 32));
    }
    // -frame 2
    else if (player->frame < 4 && player->pState != 'X')
    {
        if (player->pState == 'L')
            player->setPixmap(player->sheet_player->copy(64, player->left, 32, 32));
        else if (player->pState == 'D')
            player->setPixmap(player->sheet_player->copy(64, player->forward, 32, 32));
        else if (player->pState == 'R')
            player->setPixmap(player->sheet_player->copy(64, player->right, 32, 32));
        else if (player->pState == 'U')
            player->setPixmap(player->sheet_player->copy(64, player->backward, 32, 32));
    }// End sprite animation

    // Check collisions
    player->collisions();

}// End method update
