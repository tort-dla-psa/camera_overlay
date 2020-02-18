#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMultimedia/QCamera>
#include <QtMultimedia/QCameraInfo>
#include <QtMultimediaWidgets/QCameraViewfinder>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    if(QCameraInfo::availableCameras().count() == 0){
        throw std::runtime_error("no cameras!");
    }
    this->camera_view = ui->widget;
    cam = new QCamera(QCamera::FrontFace);
    cam->setViewfinder(this->ui->widget);

    box_comp = new box_computer();
    box_comp_thr = new QThread();
    box_comp->moveToThread(box_comp_thr);
    connect(box_comp_thr, &QThread::started, box_comp, &box_computer::run);
    connect(box_comp, &box_computer::emit_box, camera_view, &camera_view::draw_box);
    box_comp_thr->start();

    cam->start();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete cam;
}
