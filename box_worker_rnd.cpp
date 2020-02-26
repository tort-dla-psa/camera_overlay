#include "box_worker_rnd.h"
#include <QDateTime>
#include <QThread>
#include <random>

box_worker_rnd::box_worker_rnd(QObject *parent)
    :box_worker(parent)
{}

void box_worker_rnd::set_network(QString path){
}

void box_worker_rnd::process(QImage img){
    emit compute_started();
    const int w = img.width(), h = img.height();
    unsigned int ms = static_cast<unsigned>(QDateTime::currentMSecsSinceEpoch());
    std::mt19937 gen(ms);
    std::uniform_int_distribution<> x_gen(0, w), y_gen(0, h), sleep_gen(0,100);

    const QString chars("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
    const int max_len=16;
    const int box_count = 5;
    std::uniform_int_distribution<> ch_gen(0, chars.size()-1);

    QQueue<box> boxes;
    for(size_t i=0; i<box_count; i++){
        //emit calc_start();
        int x_ = x_gen(gen);
        int y_ = y_gen(gen);
        std::uniform_int_distribution<> w_gen(x_, w), h_gen(y_, h);
        int w_ = w_gen(gen);
        int h_ = h_gen(gen);

        QString lbl;
        for(size_t i=0; i<max_len; i++){
            lbl.append(chars.at(ch_gen(gen)));
        }
        //emit calc_stop();
        box b{x_,y_,w_,h_,lbl};
        boxes.push_back(b);
    }
    QThread::currentThread()->msleep(100);
    emit compute_finished();
    emit computed(boxes);
}
