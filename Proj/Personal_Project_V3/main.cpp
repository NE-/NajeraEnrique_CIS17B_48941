/*
 * File:    main.cpp
 * Author:  Enrique Najera
 * Purpose: Create splashscreen, game window, Game object
 * 16 December 2015
 */

// Q_LIBS
#include <QApplication>
#include <QSplashScreen>

// USER_LIBS
#include "database.h"
#include "gamewindow.h"
#include "game.h"

// Start method main
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create splashscreen object
    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/img/images/splash.png"));
    splash->show();

    // Create database object
    Database *db = new Database();

    Qt::Alignment topRight = Qt::AlignRight | Qt::AlignTop;

    splash->showMessage(QObject::tr("Establishing connections..."),
                        topRight, Qt::white);
    if(!db->createConnection())
        return 1;

    splash->showMessage(QObject::tr("Setting up main window..."),
                        topRight, Qt::white);
    // Create game window
    GameWindow gameWindow;

    splash->showMessage(QObject::tr("Setting up game..."),
                            topRight, Qt::white);
    // create game
    Game *game = new Game();

    gameWindow.setCentralWidget(game);
    gameWindow.show();
    splash->finish(&gameWindow);

    delete splash;

    return a.exec();
}// End method main
