#pragma once
#include <QMetaType>
#include <QQueue>

struct box{
    int x,y,w,h;
    QString label;
};

Q_DECLARE_METATYPE(QQueue<box>);
