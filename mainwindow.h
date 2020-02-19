#pragma once

#include <QMainWindow>
#include <QtMultimedia/QCamera>
#include <QThread>
#include <QLabel>
#include "frame_grabber.h"
#include "box_computer.h"

namespace Ui {
class MainWindow;
}

class MainWindow:public QMainWindow{
    Q_OBJECT

    quint64 prev_draw_msec, prev_comp_msec;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void draw_image(QImage img);
    void compute_started();
    void compute_finished();
private:
    QLabel* image_lbl, *compute_fps_lbl, *draw_fps_lbl;
    Ui::MainWindow *ui;

    frame_grabber* fgrb;
    box_worker* box_comp;
    QThread* worker_thr;

    QCamera* cam;
};
