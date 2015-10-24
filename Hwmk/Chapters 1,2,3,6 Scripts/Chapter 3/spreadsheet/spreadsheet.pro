#-------------------------------------------------
#
# Project created by QtCreator 2015-10-23T19:38:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = spreadsheet
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cell.cpp \
    finddialog.cpp \
    gotocelldialog.cpp \
    sortdialog.cpp \
    spreadsheet.cpp

HEADERS  += mainwindow.h \
    cell.h \
    finddialog.h \
    gotocelldialog.h \
    sortdialog.h \
    spreadsheet.h

FORMS    += \
    gotocelldialog.ui \
    sortdialog.ui \

RESOURCES += \
    spreadsheet.qrc

