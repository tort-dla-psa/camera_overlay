#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtMultimedia/QCamera>
#include <QThread>
#include "camera_view.h"
#include "box_computer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    class camera_view* camera_view;
    box_computer* box_comp;
    QThread* box_comp_thr;
    QCamera* cam;
};

#endif // MAINWINDOW_H
