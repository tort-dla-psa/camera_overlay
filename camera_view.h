#ifndef CAMERA_VIEW_H
#define CAMERA_VIEW_H

#include <QObject>
#include <QWidget>
#include <QQueue>
#include <QtMultimediaWidgets/QCameraViewfinder>
#include "camera_view.h"

class camera_view : public QCameraViewfinder
{
    Q_OBJECT
    struct box{
        int x,y,w,h;
        QString label;
    };
    QQueue<box> boxes;
public:
    explicit camera_view(QWidget *parent = 0);
protected:
    virtual void paintEvent(QPaintEvent *event)override;
signals:
    void picture_drawn();
public slots:
    void draw_box(int x, int y, int w, int h, QString label);
};

#endif // CAMERA_VIEW_H
