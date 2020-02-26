#pragma once
#include "box_worker.h"

class box_worker_rnd:public box_worker{
    Q_OBJECT

public:
    explicit box_worker_rnd(QObject *parent=0);
    void process(QImage img)override;
    void set_network(QString path)override;
};
