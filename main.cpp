#include "mainwindow.h"
#include <QApplication>
#include <QQueue>
#include "box.h"

int main(int argc, char *argv[])
{
    qRegisterMetaType<QQueue<box>>("box_queue");
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
