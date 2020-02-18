#ifndef BOX_COMPUTER_H
#define BOX_COMPUTER_H

#include <QObject>
#include <QString>

class box_computer : public QObject
{
    Q_OBJECT
public:
    explicit box_computer(QObject *parent = 0);
signals:
    void calc_start();
    void calc_stop();
    void emit_box(int x, int y, int w, int h, QString label);
public slots:
    void run();
};

#endif // BOX_COMPUTER_H
