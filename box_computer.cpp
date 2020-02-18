#include "box_computer.h"
#include <QDateTime>
#include <QThread>
#include <random>

box_computer::box_computer(QObject *parent) : QObject(parent)
{

}

void box_computer::run(){
    int w = 1920, h = 1080;
    unsigned int ms = static_cast<unsigned>(QDateTime::currentMSecsSinceEpoch());
    std::mt19937 gen(ms);
    std::uniform_int_distribution<> x_gen(0, w), y_gen(0, h), sleep_gen(0,100);

    const QString chars("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
    const int max_len=16;
    std::uniform_int_distribution<> ch_gen(0, chars.size()-1);

    while(true){
        emit calc_start();
        QThread::currentThread()->msleep(sleep_gen(gen));
        int x_ = x_gen(gen);
        int y_ = y_gen(gen);
        std::uniform_int_distribution<> w_gen(x_, w), h_gen(y_, h);
        int w_ = w_gen(gen);
        int h_ = h_gen(gen);

        QString lbl;
        for(size_t i=0; i<max_len; i++){
            lbl.append(chars.at(ch_gen(gen)));
        }
        emit calc_stop();
        emit emit_box(x_, y_, w_, h_, lbl);
    }
}
