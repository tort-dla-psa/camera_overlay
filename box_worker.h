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
    explicit box_worker(QObject *parent = 0)
        :QObject(parent)
    {}
    virtual ~box_worker(){}
public slots:
    virtual void process(QImage img)=0;
    virtual void set_network(QString path)=0;
signals:
    void computed(QQueue<box> boxes);
    void compute_started();
    void compute_finished();
};
