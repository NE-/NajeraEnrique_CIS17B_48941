/*
 * File:    thread.cpp
 * Author:  Enrique Najera (copied from book)
 * Purpose: Rewrite thread application
 *          for Qt 5.5.x
 * 15 December 2015
 */

#include <QtCore>
#include <iostream>

#include "thread.h"

Thread::Thread()
{
    stopped = false;
}

void Thread::setMessage(const QString &message)
{
    messageStr = message;
}

void Thread::run()
{
    while (!stopped)
        std::cerr << qPrintable(messageStr);
    stopped = false;
    std::cerr << std::endl;
}

void Thread::stop()
{
    stopped = true;
}
