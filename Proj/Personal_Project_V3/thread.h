/*
 * File:    thread.h
 * Author:  Enrique Najera
 * Purpose: Thread to print DB names
 * 16 December 2015
 */

#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <QDebug>

class Thread : public QThread
{
    Q_OBJECT
public:
    Thread();

    void setMessage(const QString &message)
         { messageStr = message; }
    void stop();
protected:
    void run();
private:
    QString messageStr;
    volatile bool stopped;
};

#endif // THREAD_H
