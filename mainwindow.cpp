#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent):QMainWindow(parent), ui(new Ui::MainWindow)
{
    coordCubeOX = coordCubeOY = coordCubeOZ = 0;
    sizeCubeOX = sizeCubeOY = sizeCubeOZ = 1.5;
    rotateCubeOX = rotateCubeOY = rotateCubeOZ = 0;

    scaleCameraOX = scaleCameraOY = scaleCameraOZ = 1;
    rotateCameraOX = rotateCameraOY = 30;
    rotateCameraOZ = 0;

    for(int i = 0; i < 4; i++)
    {
        oldValueSensors[i] = 0;
        peremSensors[i] = 0;
        myCoordSensor[i] = 0;
    }

    ui->setupUi(this);
    MainWindow::setWindowTitle("Program 3D cube. Projects sensor");
    timer = new QTimer(this);
    timer->setInterval(20);

    revers = 0;
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimerTick()));
}

MainWindow::~MainWindow()
{
    timer->stop();
    delete ui;
    delete timer;
}


void MainWindow::onTimerTick()
{

    for(int i = 0; i < 4; i++)
    {
        peremSensors[i] = sensors.statusSensor[i] - oldValueSensors[i];
    }

    QString portMessage;
    QString tempStr;
    portMessage = QString("Time: ");
    portMessage += tempStr.setNum(sensors.timeSensor) + '\n';
    portMessage += QString("Count sensors: ") + tempStr.setNum(sensors.statusSensor[0]);
    portMessage += QString(" ") + tempStr.setNum(sensors.statusSensor[1]) + QString(" ");
    portMessage += tempStr.setNum(sensors.statusSensor[2]) + QString(" ");
    portMessage += tempStr.setNum(sensors.statusSensor[3]);
    portMessage += '\n';
    portMessage += QString("RPM: ");
    portMessage += tempStr.setNum(sensors.RPM_sensor[2]);
    ui->port_message->setText(portMessage);

    if(peremSensors[0]>0)//если считали фронт
    {
        if(revers == 0)
            myCoordSensor[0] = myCoordSensor[0]+1;
        else
            myCoordSensor[0] = myCoordSensor[0] - 1;

        if(myCoordSensor[0] == 2)
            revers = 1;
        if(myCoordSensor[0] == -2)
            revers = 0;
    }

    if(peremSensors[1] > 0)
    {
        myCoordSensor[0] = 0;
    }

    if(peremSensors[2] > 0)
    {
        rotateCubeOY += 45;
    }

    if(peremSensors[3] > 0)
    {
        rotateCubeOY = 0;
    }

    coordCubeOX = myCoordSensor[0]*2;


    coordCubeOY = tempStr.toFloat();
    coordCubeOZ = tempStr.toFloat();

    ui->cubeWidget->moving(coordCubeOX, coordCubeOY, coordCubeOZ);

    ui->cubeWidget->rotateCube(rotateCubeOX, rotateCubeOY, rotateCubeOZ);

    ui->cubeWidget->sizeCube(sizeCubeOX, sizeCubeOY, sizeCubeOZ);

    ui->cubeWidget->rotateCamera(rotateCameraOX, rotateCameraOY, rotateCameraOZ);

    ui->cubeWidget->sclareCamera(scaleCameraOX, scaleCameraOY, scaleCameraOZ);

    ui->cubeWidget->paintUpdate();

    for(int i = 0; i < 4; i++)
        oldValueSensors[i] = sensors.statusSensor[i];
    qDebug()<<myCoordSensor[0];
}

/*
void MainWindow::on_ButtonReset_clicked()
{
    coordCubeOX = coordCubeOY = coordCubeOZ = 0;
    sizeCubeOX = sizeCubeOY = sizeCubeOZ = 1.5;
    rotateCubeOX = rotateCubeOY = rotateCubeOZ = 0;

    scaleCameraOX = scaleCameraOY = scaleCameraOZ = 1;
    rotateCameraOX = rotateCameraOY = 30;
    rotateCameraOZ = 0;
    timer->stop();
    ui->cubeWidget->reset();
    onTimerTick();
}*/

void MainWindow::on_port_button_clicked()
{
    QString nameport = ui->port_name->text();//"ttyACM0";
    sensors.openPort(nameport);
    timer->start();
}
