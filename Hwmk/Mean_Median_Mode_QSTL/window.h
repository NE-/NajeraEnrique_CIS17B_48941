/*
 * File:    window.h
 * Author:  Enrique Najera
 * Purpose: Holds & creates window gadgets
 *          Solves for mean, median mode
 *          Implement QVector, QSet, QMap to solve.
 * 04 November 2015
 */

#ifndef WINDOW_H
#define WINDOW_H


// Q_LIBS
#include <QWidget>
#include <QObject>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QVector>
#include <QSet>

// SYS_LIBS
#include <ctime>

// Start class Window
class Window : public QWidget
{
    Q_OBJECT
public:
    Window();
private slots:
    void mean();   // Solves for mean   using QVector
    void median(); // Solves for median using QSet
    void mode();   // Solves for mode   using QMap
private:
    // Declare Variables
    int arySize; // Holds array size
    int modNum;  // Holds mod number for randomization

    // Create Objects
    QLabel      *lbl_arySize;
    QLabel      *lbl_modNum;
    QLabel      *lbl_initAry;
    QLabel      *lbl_output;
    QLineEdit   *aryTxtBox;
    QLineEdit   *modTxtBox;
    QLineEdit   *initTxtBox;
    QLineEdit   *outTxtBox;

    QVBoxLayout *layout_main;
    QHBoxLayout *layout_topAry;
    QHBoxLayout *layout_topMod;
    QVBoxLayout *layout_middle;
    QHBoxLayout *layout_bottomInit;
    QHBoxLayout *layout_bottomOut;

    QPushButton *btn_mean;
    QPushButton *btn_median;
    QPushButton *btn_mode;
    QPushButton *btn_cancel;
};// End class Window

#endif // WINDOW_H
