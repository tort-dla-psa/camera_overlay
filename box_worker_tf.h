#pragma once
#include "box_worker.h"

class box_worker_tf:public box_worker{
    Q_OBJECT

public:
    explicit box_worker_tf(QObject* parent=0);
    void process(QImage img)override;
    void set_network(QString path)override;
};
