#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMultimedia/QCamera>
#include <QtMultimedia/QCameraInfo>
#include <QtMultimediaWidgets/QCameraViewfinder>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    :QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    if(QCameraInfo::availableCameras().count() == 0){
        throw std::runtime_error("no cameras!");
    }

    this->compute_fps_lbl = ui->label_2;
    this->draw_fps_lbl = ui->label_3;
    this->image_lbl = ui->label;
    image_lbl->setBackgroundRole(QPalette::Base);
    image_lbl->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    image_lbl->setScaledContents(true);

    prev_draw_msec = QDateTime::currentMSecsSinceEpoch();
    prev_comp_msec = prev_draw_msec;

    this->fgrb = new frame_grabber();
    connect(fgrb, &frame_grabber::has_image_to_draw, this, &MainWindow::draw_image);

    cam = new QCamera(QCamera::FrontFace);
    cam->setViewfinder(this->fgrb);

    box_comp = new box_worker_rnd();
    worker_thr = new QThread();
    box_comp->moveToThread(worker_thr);
    connect(box_comp, &box_worker::computed, fgrb, &frame_grabber::draw_boxes);
    connect(box_comp, &box_worker::compute_finished, this, &MainWindow::compute_finished);
    connect(fgrb, &frame_grabber::has_image_to_process, box_comp, &box_worker::process);
    worker_thr->start();

    cam->start();
}

MainWindow::~MainWindow() {
    delete ui;
    delete cam;
    delete fgrb;
}

void MainWindow::draw_image(QImage img){
    auto pixmap = QPixmap::fromImage(img);
    //image_lbl->resize(pixmap.size());
    image_lbl->setPixmap(pixmap);
    auto time = QDateTime::currentMSecsSinceEpoch();
    auto delta = time - prev_draw_msec;
    prev_draw_msec = time;

    float fps = 1000./delta;
    this->draw_fps_lbl->setText("draw:"+QString::number(fps));
}

void MainWindow::compute_started(){}

void MainWindow::compute_finished(){
    auto time = QDateTime::currentMSecsSinceEpoch();
    auto delta = time - prev_comp_msec;
    prev_comp_msec = time;

    float fps = 1000./delta;
    this->compute_fps_lbl->setText("comp:"+QString::number(fps));
}
