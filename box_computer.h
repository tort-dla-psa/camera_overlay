#pragma once

#include <QObject>
#include <QString>
#include <QImage>
#include <QQueue>
#include <QThread>
#include "box.h"

class box_worker:public QObject{
    Q_OBJECT
public:
    explicit box_worker(QObject *parent = 0);
public slots:
    void process(QImage img);
signals:
    void computed(QQueue<box> boxes);
    void compute_started();
    void compute_finished();
};
