/*
 * File:    gamewindow.h
 * Author:  Enrique Najera
 * Purpose: Creates menu items/actions
 * 16 December 2015
 */

#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

// Q_LIBS
#include <QMainWindow>
#include <QAction>
#include <QLabel>
#include <QMenu>
#include <QMessageBox>
#include <QMenuBar>
#include <QFileDialog>
#include <QSqlQuery>
#include <QSqlError>

// USER_LIBS
#include "game.h"

// Start class GameWindow
class GameWindow : public QMainWindow
{
    Q_OBJECT
public:
    // Constructors
    GameWindow();
protected:
    void closeEvent(QCloseEvent *event);
private slots:
    void newGame();
    void loadGame();
    bool saveGame();
    void multiplayer();

    void players();
    void about();

private:
    void createActions();
    void createMenus();
    bool loadFile(const QString &fileName); // Takes in file name
    bool saveFile(const QString &fileName); // Takes in file name

    // Create objects
    QMenu   *fileMenu;
    QMenu   *helpMenu;
    QAction *newAction;
    QAction *loadAction;
    QAction *saveAction;
    QAction *multiplayerAction;
    QAction *exitAction;
    QAction *playersAction;
    QAction *aboutAction;

};// End class GameWindow

#endif // GAMEWINDOW_H
