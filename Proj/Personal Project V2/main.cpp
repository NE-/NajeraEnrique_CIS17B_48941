/*
 * File:    main.cpp
 * Author:  Enrique Najera
 * Purpose: Creates splashscreen and main game window
 * 18 November 2015
 */

#include <QApplication>
#include <QSplashScreen>

#include "gamewindow.h"
#include "game.h"

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
}
