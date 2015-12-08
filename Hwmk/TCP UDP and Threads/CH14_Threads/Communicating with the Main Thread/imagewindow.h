/*
 * File:    imagewindow.h
 * Author:  Enrique Najera (copied from book)
 * Purpose: Rewrite thread application
 *          for Qt 5.5.x
 * 15 December 2015
 */

#ifndef IMAGEWINDOW_H
#define IMAGEWINDOW_H

#include <QMainWindow>
#include <QStatusBar>
#include <QFileDialog>
#include <QMessageBox>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QLabel>
#include <QLabel>

#include "transactionthread.h"

class ImageWindow : public QMainWindow
{
    Q_OBJECT

public:
    ImageWindow();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void open();
    bool save();
    bool saveAs();
    void flipHorizontally();
    void flipVertically();
    void resizeImage();
    void convertTo32Bit();
    void convertTo8Bit();
    void convertTo1Bit();
    void about();
    void allTransactionsDone();

private:
    void createActions();
    void createMenus();
    bool okToContinue();
    void loadFile(const QString &fileName);
    void saveFile(const QString &fileName);
    void setCurrentFile(const QString &fileName);
    QString strippedName(const QString &fullFileName);
    void addTransaction(Transaction *transact);

    TransactionThread thread;
    QLabel *imageLabel;
    QByteArray imageFormat;
    QString curFile;

    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *convertToSubMenu;
    QMenu *helpMenu;
    QAction *openAction;
    QAction *saveAction;
    QAction *saveAsAction;
    QAction *exitAction;
    QAction *flipHorizontallyAction;
    QAction *flipVerticallyAction;
    QAction *rotateAction;
    QAction *resizeAction;
    QAction *convertTo32BitAction;
    QAction *convertTo8BitAction;
    QAction *convertTo1BitAction;
    QAction *aboutAction;
    QAction *aboutQtAction;
};

#endif
