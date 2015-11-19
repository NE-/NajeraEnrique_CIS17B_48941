/*
 * File:    gamewindow.cpp
 * Author:  Enrique Najera
 * Purpose: CSC 17 B Personal Project
 *          Creates menu items/actions
 * 18 November 2015
 */

// Q_LIBS
#include <QtGui>
#include <QDebug> // Shows if connect worked --[[DELETE]]

// USER_LIBS
#include "gamewindow.h"

// Start constructor GameWindow construct window
GameWindow::GameWindow()
{
    // Call creation methods
    createActions();
    createMenus();

    setAttribute(Qt::WA_DeleteOnClose);

    // Window properties
    setWindowIcon(QIcon(":/images/icon.png"));
    setWindowTitle(tr("Personal Project"));
    setFixedSize(310,310);
    setWindowFlags(Qt::WindowTitleHint);
}// End method GameWindow

// Start method createActions creates menu actions
void GameWindow::createActions()
{
    newAction = new QAction(tr("&New Game"), this);
    newAction->setShortcut(tr("Ctrl+N"));
    newAction->setStatusTip(tr("Restarts the game"));
    connect(newAction, SIGNAL(triggered()),this,SLOT(newGame()));

    loadAction = new QAction(tr("&Load Game"), this);
    loadAction->setShortcut(tr("Ctrl+O"));
    loadAction->setStatusTip(tr("Loads a saved game"));
    connect(loadAction, SIGNAL(triggered()),this,SLOT(loadGame()));

    saveAction = new QAction(tr("&Save Game"), this);
    saveAction->setShortcut(tr("Ctrl+S"));
    saveAction->setStatusTip(tr("Saves current game status"));
    connect(saveAction, SIGNAL(triggered()),this,SLOT(saveGame()));

    multiplayerAction = new QAction(tr("&Multiplayer"), this);
    multiplayerAction->setShortcut(tr("Ctrl+M"));
    multiplayerAction->setStatusTip(tr("Play with others on same network"));
    connect(multiplayerAction, SIGNAL(triggered()),this,SLOT(multiplayer()));

    exitAction = new QAction(tr("&Exit"), this);
    exitAction->setShortcut(tr("Ctrl+Q"));
    exitAction->setStatusTip("Quits current game");
    connect(exitAction, SIGNAL(triggered()), qApp, SLOT(quit()));


    aboutAction = new QAction(tr("&About Game"), this);
    aboutAction->setStatusTip(tr("About the game"));
    connect(aboutAction, SIGNAL(triggered()),this,SLOT(about()));
}// End method createActions

// Start method createMenus creates menus for actions
void GameWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAction);
    fileMenu->addAction(loadAction);
    fileMenu->addAction(saveAction);
    fileMenu->addSeparator();
    fileMenu->addAction(multiplayerAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAction);

}// End method createMenus

// Start method newGame INIT main window
void GameWindow::newGame()
{
    qDebug() << "NEW GAME";
} // End method newGame

// Start mehtod saveGame saves game state
bool GameWindow::saveGame()
{

    qDebug() << "SAVING GAME";

    // Create login dialog
    login = new Login();
    login->exec();

    // Save values in a file
    QString fileName = QFileDialog::getSaveFileName(this, "Save Game", QString(), "Save Game (*.sav );;All Files (*)");

    QFile file(fileName);
    file.open(QIODevice::ReadWrite);

    QTextStream out(&file);

    //accept newline
    file.setTextModeEnabled(true);

    out << login->lbl_username->text() << "\n";
    //out << game->score->getScore << "\n";

    file.close();

    return true;

}// End mehtod saveGame

// Start mehtod loadGame loads saved file
void GameWindow::loadGame()
{
    /*************************************
     * TODO: LOAD VALUES OF SAVE FILE TO *
     *       APPROPRIATE VAR             *
     *************************************/

    qDebug() << "LOADING GAME";

    QString fileName = QFileDialog::getOpenFileName(this, "Load Saved Game", QString(), "Save Game (*.sav );;All Files (*)");

    QFile file(fileName);
    file.open(QIODevice::ReadWrite);

    QTextStream in(&file);
    file.setTextModeEnabled(true);

    QString inText;

    inText = in.readLine();
    //login->username->setUsername(inText.toInt());

    inText = in.readLine();
    //game->score->setScore(inText.toInt());

    file.close();

}// End mehtod saveGame

// Start mehtod mulitplayer connects to app on other machine
void GameWindow::multiplayer()
{
    /**************
     * TODO: QTcp *
     **************/

    qDebug() << "WAITING FOR OTHER PLAYERS...";

}// End method multiplayer

// Start mehtod closeEvent closes window
void GameWindow::closeEvent(QCloseEvent *event)
{
    qDebug() << "SHUTTING DOWN";
    qApp->quit();

}// End method closeEvent

// Start method about construct about dialog
void GameWindow::about()
{
    QMessageBox::about(this, tr("About Game"),
            tr("<h2>Game v1     </h2>"
               "<h3>GAME DETAILS</h3>"
               " "
               "<p>Kill enemies using your <font color=#0FF>bombs</font></p>"
               " "
               "<p>If an enemy passes you, you<font color=red><i>LOSE</i></font> points</p>"
               "<p>If an enemy touches you, you <font color=red><i>LOSE</i></font> health!</p>"
               "<h3>GAME CONTROLS</h3>"
               " "
               "<ul style = 'list-style-image: url('icon.png')'>       "
               "    <li><b>Right arrow key</b>: move right        </li>"
               "    <li><b>Left arrow key</b>:  move left         </li>"
               "    <li><b>Spacebar</b>:        shoot             </li>"
               "    <li><b>'Faster!' button</b>: enemies speed up!</li>"
               "</ul>"));
}// End method about
