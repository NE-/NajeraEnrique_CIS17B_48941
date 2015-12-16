/*
 * File:    gamewindow.cpp
 * Author:  Enrique Najera
 * Purpose: Creates menu items/actions
 * 16 December 2015
 */

// Q_LIBS
#include <QtGui>
#include <QDebug> // Shows if connect worked --[[DELETE]]

// USER_LIBS
#include "gamewindow.h"

// Start constructor GameWindow
GameWindow::GameWindow()
{
    // Call creation methods
    createActions();
    createMenus();

    setAttribute(Qt::WA_DeleteOnClose);

    // Window properties
    setWindowIcon(QIcon(":/img/images/icon.png"));
    setWindowTitle(tr("Room 3"));
    setFixedSize(200,200); // 200 x 200
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


    playersAction = new QAction(tr("&Players List"), this);
    playersAction->setStatusTip(tr("List of all players"));
    connect(playersAction, SIGNAL(triggered()),this,SLOT(players()));

    aboutAction = new QAction(tr("&About Game"), this);
    aboutAction->setStatusTip(tr("About the game"));
    connect(aboutAction, SIGNAL(triggered()),this,SLOT(about()));

}// End method createActions

// Start method createMenus
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
    helpMenu->addAction(playersAction);
    helpMenu->addAction(aboutAction);
}// End method createMenus

// Start method newGame INIT main window
void GameWindow::newGame()
{
    Game *game = new Game();
    game->newGame();
} // End method newGame

// Start mehtod saveGame saves game state
bool GameWindow::saveGame()
{
    Game *game = new Game();

    QString fileName = QFileDialog::getSaveFileName(NULL, "Save Game", QString(), "Save File (*.sav);;All Files (*)");

    QFile file(fileName);
    file.open(QIODevice::ReadWrite);

    QTextStream out(&file);

    //accept newline
    file.setTextModeEnabled(true);

    out << "Name " << game->name << "\n"; // Doesn't output name
    out << "Time " << "\n";

    file.close();

    return true;

}// End mehtod saveGame

// Start mehtod loadGame loads saved file
void GameWindow::loadGame()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Load Saved Game", QString(), "Save File (*.sav);;All Files (*)");

    QFile file(fileName);
    file.open(QIODevice::ReadWrite);

    QTextStream in(&file);
    file.setTextModeEnabled(true);

    QString inText;

    newGame();

    inText = in.readLine();

    inText = in.readLine();

    inText = in.readLine();


    file.close();

}// End method saveGame

// Start mehtod mulitplayer
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
    qApp->quit();
}// End method closeEvent

// Start method players

void GameWindow::players()
{
    QSqlQuery query;
    query.exec("SELECT * FROM names");

    if(!query.isActive())
        QMessageBox::warning(this, tr("Database Error"),
                             query.lastError().text());

    while(query.next())
    {
        QString dbLastName = query.value(1).toString();
        QString dbFirstName = query.value(2).toString();
        qDebug() << "Name: " << qPrintable(dbLastName) << ", "
                             << qPrintable(dbFirstName);
    }
}// End method players

// Start method about
void GameWindow::about()
{
    QMessageBox::about(this, tr("About Game"),
            tr("<h2>Room 3</h2>"
               "<h3>GAME DETAILS</h3>"
               " "
               "<p>Try to leave the room by solving <font color=#00F><i>puzzles</i></font> before the <font color=#F00>TIME </font>runs out!</p>"
               " "
               "<h3>GAME CONTROLS</h3>"
               " "
               "<ul style = 'list-style-image: url('icon.png')'>       "
               "    <li><b>Right arrow key</b>: Move Right        </li>"
               "    <li><b>Left arrow key</b>:  Move Left         </li>"
               "    <li><b>Up arrow key</b>:    Move Up           </li>"
               "    <li><b>Down arrow key</b>:  Move Down         </li>"
               "    <li><b>Z key</b>:           Interact          </li>"
               "    <li><b>X key</b>:           In-Game Menu      </li>"
               ""
               "</ul>"));
}// End method about
