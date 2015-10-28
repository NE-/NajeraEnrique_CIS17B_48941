#-------------------------------------------------
#
# Project created by QtCreator 2015-10-26T18:13:09
#
#-------------------------------------------------

QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Personal_Project
TEMPLATE = app


SOURCES += main.cpp \
    player.cpp \
    bullet.cpp \
    game.cpp \
    gamewindow.cpp \
    enemy.cpp

HEADERS  += \
    player.h \
    bullet.h \
    game.h \
    gamewindow.h \
    enemy.h

FORMS    +=

RESOURCES += \
    res.qrc
