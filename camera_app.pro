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
    frame_grabber.cpp

HEADERS  += mainwindow.h \
    box_computer.h \
    frame_grabber.h \
    box.h

FORMS    += mainwindow.ui
