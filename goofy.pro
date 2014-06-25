#-------------------------------------------------
#
# Project created by QtCreator 2014-06-23T19:47:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = goofy
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    goofy.cpp \
    frame.cpp \
    drawer.cpp \
    sprite.cpp

HEADERS  += mainwindow.h \
    goofy.h \
    frame.h \
    drawer.h \
    sprite.h \
    Structs.h

FORMS    += mainwindow.ui

RESOURCES += \
    sprites.qrc
