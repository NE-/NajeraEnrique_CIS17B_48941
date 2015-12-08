/*
 * File:    thread.h
 * Author:  Enrique Najera (copied from book)
 * Purpose: Rewrite thread application
 *          for Qt 5.5.x
 * 15 December 2015
 */

#ifndef THREAD_H
#define THREAD_H

// Q_LIBS
#include <QThread>

class Thread : public QThread
{
    Q_OBJECT
public:
    Thread();

    void setMessage(const QString &message);
    void stop();

protected:
    void run();

private:
    QString messageStr;
    volatile bool stopped;
};

#endif
