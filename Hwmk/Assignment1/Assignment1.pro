TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Rectangle.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    Rectangle.h

