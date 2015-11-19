#-------------------------------------------------
#
# Project created by QtCreator 2015-11-16T17:27:20
#
#-------------------------------------------------

QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = soundTest
TEMPLATE = app


SOURCES += main.cpp \
    game.cpp \
    player.cpp \
    enemy.cpp \
    bomb.cpp \
    score.cpp \
    gamewindow.cpp \
    login.cpp

HEADERS  += \
    game.h \
    player.h \
    enemy.h \
    bomb.h \
    score.h \
    gamewindow.h \
    login.h

FORMS    +=

RESOURCES += \
    res.qrc
