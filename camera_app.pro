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
    frame_grabber.cpp \
    box_worker_rnd.cpp \
    box_worker_tf.cpp

HEADERS  += mainwindow.h \
    frame_grabber.h \
    box.h \
    box_worker.h \
    box_worker_rnd.h \
    box_worker_tf.h

FORMS    += mainwindow.ui
