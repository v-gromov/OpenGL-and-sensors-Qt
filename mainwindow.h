#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mainscene.h"
#include <QString>
//#include "qtimer.h"
//#include <QTimer>

#include "sensor.h"

namespace Ui {
class MainWindow;
}

class MainWindow:public QMainWindow
{
    Q_OBJECT
public:

    explicit MainWindow(QWidget *parent = 0);

    QElapsedTimer CurSec;
    ~MainWindow();
    mySensor sensors;
    float coordCubeOX;//координата куба ось х
    float coordCubeOY;//координата куба ось у
    float coordCubeOZ;//координата куба ось z

    float sizeCubeOX;//размер грани куба по оси x
    float sizeCubeOY;//размер грани куба по оси y
    float sizeCubeOZ;//размер грани куба по оси z

    float rotateCubeOX;//поворот куба на градусы ось x
    float rotateCubeOY;//поворот куба на градусы ось y
    float rotateCubeOZ;//поворот куба на градусы ось z

    float scaleCameraOX;//масштаб всей сцены ось x
    float scaleCameraOY;//масштаб всей сцены ось y
    float scaleCameraOZ;//масштаб всей сцены ось z

    float rotateCameraOX;//поворот всей сцены на градусы ось x
    float rotateCameraOY;//поворот всей сцены на градусы ось y
    float rotateCameraOZ;//поворот всей сцены на градусы ось z

    int oldValueSensors[4];
    int peremSensors[4];
    int myCoordSensor[4];

    int revers;

private:
    Ui::MainWindow* ui;
    QTimer *timer;
    QString tempStr;

public slots:
    void onTimerTick();
private slots:

    void on_port_button_clicked();
};


#endif // MAINWINDOW_H
