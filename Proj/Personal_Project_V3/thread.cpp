/*
 * File:    thread.cpp
 * Author:  Enrique Najera
 * Purpose: Thread to print DB names
 * 16 December 2015
 */

// USER_LIBS
#include "thread.h"

// Start constructor Thread
Thread::Thread()
{
    stopped = false;
}// End constructor Thread

// Start method stop
void Thread::stop()
{
    stopped = true;
}// End method stop

// Start method run
void Thread::run()
{
    while (!stopped)
        qDebug() << qPrintable(messageStr);
    stopped = false;
}// End method run
