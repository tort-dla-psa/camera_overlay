#pragma once

#include <QQueue>
#include <QWidget>
#include <QtMultimedia/QAbstractVideoSurface>
#include "box.h"

class frame_grabber:public QAbstractVideoSurface{
    Q_OBJECT
    QQueue<box> boxes;
public:
    frame_grabber(QWidget* parent = nullptr);

    bool present(const QVideoFrame &frame)override;
    QList<QVideoFrame::PixelFormat> supportedPixelFormats(
            QAbstractVideoBuffer::HandleType handleType) const override;
public slots:
    void draw_boxes(QQueue<box> boxes);
signals:
    void has_image_to_draw(QImage img);
    void has_image_to_process(QImage img);
};
