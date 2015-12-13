/*
 * File:    game.h
 * Author:  Enrique Najera
 * Purpose: Holds main game window & logic
 * 16 December 2015
 */

#ifndef GAME_H
#define GAME_H

// Q_LIBS
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>

#include <QObject>
#include <QTimer>

#include <QMediaPlayer>

#include <QIcon>
#include <QInputDialog>
#include <QRegExp>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

// USER_LIBS
#include "gamewindow.h"
#include "button.h"
#include "switchdialog.h"
#include "player.h"
#include "room.h"
#include "things.h"
//#include "collisions.h"

// Start class Game
class Game : public QGraphicsView
{
    Q_OBJECT
public:
    Game();

    QString name; // Public for I/O
                  // No mutator/Accessor for speed

private:
    int frame; // Holds frame number

    // Create Objects
    QGraphicsScene *scene;
    QMediaPlayer   *snd_bkgdMusic;
    QTimer         *timer;
    QInputDialog   *dialog_form;


    Button *btn_new;
    Button *btn_cont;
    Button *btn_quit;

    SwitchDialog *switchDialog;

    Player *player;
    Room   *room;

    Things *table1_L;
    Things *table2_L;
    Things *table1_R;
    Things *table2_R;
    Things *flower1_L;
    Things *flower2_L;
    Things *flower1_R;
    Things *flower2_R;
    Things *window1_L;
    Things *window2_L;
    Things *window1_R;
    Things *window2_R;
    Things *chair1_L;
    Things *chair2_L;
    Things *chair1_R;
    Things *chair2_R;
    Things *picture1_L;
    Things *picture2_L;
    Things *picture1_R;
    Things *picture2_R;
    Things *carpet_L;
    Things *carpet_R;
    Things *cupboard1_L;
    Things *cupboard2_L;
    Things *cupboard3_L;
    Things *cupboard4_L;
    Things *cupboard1_R;
    Things *cupboard2_R;
    Things *cupboard3_R;
    Things *cupboard4_R;
    Things *couch1_L;
    Things *couch2_L;
    Things *couch3_L;
    Things *couch1_R;
    Things *couch2_R;
    Things *couch3_R;

public slots:
    void update();  // Updates graphics
    void newGame(); // Creates all game obj
    void form();    // Takes in user's info
};// End class Game

#endif // GAME_H
