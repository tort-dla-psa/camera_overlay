#include "frame_grabber.h"
#include <QPainter>

frame_grabber::frame_grabber(QWidget* parent)
    :QAbstractVideoSurface(parent)
{}

void frame_grabber::draw_boxes(QQueue<box> boxes){
    this->boxes = boxes;
}

QList<QVideoFrame::PixelFormat> frame_grabber::supportedPixelFormats(
        QAbstractVideoBuffer::HandleType handleType) const
{
    if (handleType == QAbstractVideoBuffer::NoHandle) {
        return QList<QVideoFrame::PixelFormat>()<<QVideoFrame::Format_RGB24;
    } else {
        return QList<QVideoFrame::PixelFormat>();
    }
}

bool frame_grabber::present(const QVideoFrame &frame){
    /*if (notMyFormat(frame.pixelFormat())) {
       setError(IncorrectFormatError);
       return false;
    } else { */

    QVideoFrame frametodraw(frame);
    if(!frametodraw.map(QAbstractVideoBuffer::ReadOnly)){
       setError(ResourceError);
       return false;
    }

    //this is a shallow operation. it just refer the frame buffer
    QImage image(
       frametodraw.bits(),
       frametodraw.width(),
       frametodraw.height(),
       frametodraw.bytesPerLine(),
       QImage::Format_RGB888);

    emit has_image_to_process(image);

    //mylabel->setPixmap(QPixmap::fromImage(image));
    //mylabel->update();

    frametodraw.unmap();

    QPainter pntr(&image);
    pntr.setPen(Qt::black);
    for(const auto &box:boxes){
        pntr.drawRect(box.x, box.y, box.w, box.h);
        pntr.drawText(box.x, box.y, box.label);
    }
    emit has_image_to_draw(image);
    return true;
}
