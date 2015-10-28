/*
 * File:    main.cpp
 * Author:  Enrique Najera
 * Purpose: CSC 17 B Personal Project
 *          Creates splashscreen, gamewindow,
 *          game logic view
 * DUE DATE GOES HERE
 */

/******************************************************************
 * GLOBAL TODO                                                    *
 * GAME: Health (player & enemy), sword, ammo spawn, speed button *
 * Qt: layouts, more buttons, slider maybe                        *
 ******************************************************************/

// Q_LIBS
#include <QApplication>
#include <QSplashScreen>

// USER_LIBS
#include "gamewindow.h"
#include "game.h"

// Start method main
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create splashscreen object
    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/images/splash.png"));
    splash->show();

    Qt::Alignment topRight = Qt::AlignRight | Qt::AlignTop;

    splash->showMessage(QObject::tr("Setting up main window..."),
                        topRight, Qt::white);
    GameWindow gameWindow;

    splash->showMessage(QObject::tr("Setting up game..."),
                        topRight, Qt::white);
    Game *game = new Game();

    gameWindow.setCentralWidget(game);
    gameWindow.show();
    splash->finish(&gameWindow);

    delete splash;

    return a.exec();
}// End method main
