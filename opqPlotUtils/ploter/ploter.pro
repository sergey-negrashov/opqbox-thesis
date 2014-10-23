#-------------------------------------------------
#
# Project created by QtCreator 2014-10-21T01:33:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ploter
TEMPLATE = app


SOURCES += main.cpp\
        plotter.cpp

HEADERS  += plotter.h

FORMS    += plotter.ui

INCLUDEPATH += /usr/include/qwt/
LIBS += -lqwt
