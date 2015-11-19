/*
 * File:    login.h
 * Author:  Enrique Najera
 * Purpose: Creates login dialog
 * 18 November 2015
 */

#ifndef LOGIN_H
#define LOGIN_H

// Q_LIBS
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QGridLayout>
#include <QRegExp>

class Login : public QDialog
{
    Q_OBJECT
public:
    Login();

    // Public for save access
    QLabel    *lbl_username;

    // Mutator Functions
    void setUsername(QString &username);
    void setPassword(QString &password);
private:
    void setup();

    // Create Obj
    QLabel    *lbl_password;
    QLineEdit *line_user;
    QLineEdit *line_pswd;

    QDialogButtonBox *buttons;

    QGridLayout *formLayout;

    QRegExp *reg_user;
    QRegExp *reg_pswd;
signals:
    void acceptLogin(QString &username, QString &password);
public slots:
    void slotAcceptLogin();
};

#endif // LOGIN_H
