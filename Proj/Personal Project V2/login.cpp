/*
 * File:    login.cpp
 * Author:  Enrique Najera
 * Purpose: Creates login dialog
 * 18 November 2015
 */

#include "login.h"

// Start constructor Login
Login::Login()
{
    setup();
    setWindowTitle(tr("Save Game"));
    setModal(true);
}// End constructor Login

// Start methos setup
void Login::setup()
{
    // Layout
    formLayout = new QGridLayout(this);

    // Labels
    lbl_username = new QLabel(this);
    lbl_username->setText(tr("Username"));
    lbl_password = new QLabel(this);
    lbl_password->setText(tr("Password"));

    // Line Edits
    line_user = new QLineEdit(this);
    line_user->setToolTip(tr("Must be at least 4 characters"));
    line_pswd = new QLineEdit(this);
    line_pswd->setToolTip(tr("Must contain at least 2 numbers and 1 special character"));

    // Buttons
    buttons = new QDialogButtonBox(this);
    buttons->addButton(QDialogButtonBox::Ok);
    buttons->addButton(QDialogButtonBox::Cancel);

    /*connect(buttons->button(QDialogButtonBox::Ok),
            SIGNAL(clicked()), this, SLOT(slotAcceptLogin()));
    connect(buttons->button(QDialogButtonBox::Cancel),
            SIGNAL(clicked()), this, SLOT(close()));*/

    // Add widgets to dialog
    formLayout->addWidget(lbl_username,  0, 0);
    formLayout->addWidget(line_user,     0, 1);
    formLayout->addWidget(lbl_password,  1, 0);
    formLayout->addWidget(line_pswd,     1, 1);
    formLayout->addWidget(buttons, 2, 0, 1, 2);

    setLayout(formLayout);
}// End method setup

// Start method setUsername
void Login::setUsername(QString &username)
{
    // Check if at least 4 chars
    reg_user = new QRegExp("(/^[a-zA-Z]{4,}$/)");
    if (reg_user->matchedLength())
        lbl_password->setFocus();
}// End method setUsername

// Start method setPassword
void Login::setPassword(QString &password)
{
    // Check if 2 numbers and 1 special character
    reg_pswd = new QRegExp("(/^(.*[0-9].*)(.*[!@#$%^&*]).*$)");
    if (reg_pswd->matchedLength())
        lbl_password->setText(password);
}// End method setPassword

// Start method slotAcceptLogin
void Login::slotAcceptLogin()
{
    //emit acceptLogin(username, password);
    close();
}// End method slotAcceptLogin
