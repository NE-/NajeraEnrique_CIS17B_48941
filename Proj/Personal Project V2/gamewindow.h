/*
 * File:    gamewindow.h
 * Author:  Enrique Najera
 * Purpose: CSC 17 B Personal Project
 *          Creates menu items/actions
 * 18 November 2015
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
#include <QFile>
#include <QFileDialog>
#include <QIODevice>

// SYS_LIBS
#include <iostream>

// User_lIBS
#include "login.h"
#include "enemy.h"

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
    void about();

private:
    void createActions();
    void createMenus();
    bool loadFile(const QString &fileName); // Takes in file name
    bool saveFile(const QString &fileName); // Takes in file name

    // Create objects
    QMenu   *fileMenu;
    QMenu   *helpMenu;
    QMenu   *xtraMenu;
    QAction *newAction;
    QAction *loadAction;
    QAction *saveAction;
    QAction *multiplayerAction;
    QAction *exitAction;
    QAction *aboutAction;
    QAction *speedAction;

    Login *login;
    Enemy *enemy;
}; // End class GameWindow

#endif // GAMEWINDOW_H
