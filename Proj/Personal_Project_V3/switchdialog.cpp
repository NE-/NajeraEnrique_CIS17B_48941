/*
 * File:    switchdialog.cpp
 * Author:  Enrique Najera
 * Purpose: Prompts if player wants to flip object
 * 16 December 2015
 */

// USER_LIBS
#include "switchdialog.h"

// Start constructor SwitchDialog
SwitchDialog::SwitchDialog(QWidget *parent)
{
    // INIT vars
    isClicked = false;

    // Create buttons
    label = new QLabel(tr("Change/flip object? "));
    btn_yes = new QPushButton(tr("Yes"));
    btn_no = new QPushButton(tr("No"));
    btn_no->setDefault(true);

    // If clicked connections
    connect(btn_yes, SIGNAL(clicked()), this, SLOT(yesClicked()));
    connect(btn_no,  SIGNAL(clicked()), this, SLOT(close()));

    // Layout
    layout_text = new QHBoxLayout();
    layout_text->addWidget(label);

    layout_btn = new QVBoxLayout();
    layout_btn->addWidget(btn_yes);
    layout_btn->addWidget(btn_no);
    layout_btn->addStretch();

    layout_main = new QHBoxLayout();
    layout_main->addLayout(layout_text);
    layout_main->addLayout(layout_btn);

    setLayout(layout_main);

    setWindowTitle("Change?");
    setFixedHeight(sizeHint().height());
}// End constructor SwitchDialog

// Start method yesClicked
void SwitchDialog::yesClicked()
{
    setYesClicked(true);
    close();
}// End method yesClicked

// Start method setYesClicked
void SwitchDialog::setYesClicked(bool c)
{
    isClicked = c;
}// End method setYesClicked

// Start method getYesClicked
bool SwitchDialog::getYesClicked() const
{
    return isClicked;
}// End method getYesClicked
