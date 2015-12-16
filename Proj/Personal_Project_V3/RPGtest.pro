#-------------------------------------------------
#
# Project created by QtCreator 2015-12-05T12:41:46
#
#-------------------------------------------------

QT       += core gui sql\
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RPGtest
TEMPLATE = app


SOURCES += main.cpp \
    game.cpp \
    room.cpp \
    player.cpp \
    gamewindow.cpp \
    button.cpp \
    things.cpp \
    switchdialog.cpp \
    database.cpp

HEADERS  += \
    game.h \
    room.h \
    player.h \
    gamewindow.h \
    button.h \
    things.h \
    switchdialog.h \
    database.h

FORMS    +=

RESOURCES += \
    res.qrc
