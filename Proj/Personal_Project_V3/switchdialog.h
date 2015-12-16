/*
 * File:    switchdialog.h
 * Author:  Enrique Najera
 * Purpose: Prompts if player wants to flip object
 * 16 December 2015
 */

#ifndef SWITCHDIALOG_H
#define SWITCHDIALOG_H

// Q_LIBS
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

// Start class SwitchDialog
class SwitchDialog : public QDialog
{
    Q_OBJECT
public:
    SwitchDialog(QWidget *parent=0);

    void setYesClicked(bool c);
    bool getYesClicked() const;

private:
    bool isClicked;

    QLabel *label;

    QPushButton *btn_yes;
    QPushButton *btn_no;

    QHBoxLayout *layout_text;
    QVBoxLayout *layout_btn;
    QHBoxLayout *layout_main;
private slots:
    void yesClicked();
};// End class SwitchDialog

#endif // SWITCHDIALOG_H
