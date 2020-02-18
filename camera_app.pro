#-------------------------------------------------
#
# Project created by QtCreator 2020-02-18T17:30:50
#
#-------------------------------------------------

QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = camera_app
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    box_computer.cpp \
    camera_view.cpp

HEADERS  += mainwindow.h \
    box_computer.h \
    camera_view.h

FORMS    += mainwindow.ui
