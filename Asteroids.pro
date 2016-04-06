#-------------------------------------------------
#
# Project created by QtCreator 2016-04-03T22:12:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Asteroids
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    scene.cpp \
    station.cpp

HEADERS  += mainwindow.h \
    scene.h \
    station.h

FORMS    += mainwindow.ui
