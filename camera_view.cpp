#include "camera_view.h"
#include <QPainter>
#include <QThread>
#include <QDebug>

camera_view::camera_view(QWidget *parent)
    :QCameraViewfinder(parent)
{}

void camera_view::draw_box(int x, int y, int w, int h, QString label){
    box b{x,y,w,h,label};
    boxes.push_back(b);
}

void camera_view::paintEvent(QPaintEvent *event){
    //this->QCameraViewfinder::paintEvent(event);
    QPainter pntr;
    pntr.begin(this);
    pntr.setPen(Qt::black);
    int msleep = 100;
    while(boxes.size() > 0){
        auto box = boxes.front();
        pntr.drawRect(box.x, box.y, box.w, box.h);
        pntr.drawText(box.x, box.y, box.label);
        boxes.pop_front();
        qDebug()<<box.x<<" "
               <<box.y<<" "
               <<box.w<<" "
               <<box.h<<" "
               <<box.label;
    }
    pntr.end();
    QThread::currentThread()->msleep(msleep);
}
