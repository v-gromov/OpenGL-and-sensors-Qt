#ifndef SENSOR_H
#define SENSOR_H


#include <qt4/QtSerialPort/QSerialPort>
#include <qt4/QtSerialPort/QSerialPortInfo>
#include <qt4/Qt/qstringlist.h>


class mySensor:public QObject
{//QObject нужен для коннекта прерываний
    Q_OBJECT    //если включать/выключать Q_OBJECT, то нужно сделать qmake
public:
    mySensor();
    ~mySensor();
    QSerialPort *serial;
    void initSerial(); // Инициализации посл. порта
    void deinitSerial(); // И деинициализация (закрытие) порта
    void openPort(QString namePort);
    void commandSend(QString command);
    void search();
    QString controller_message;
    int statusSensor[4];
    int oldStatusSensor[4];
    int detStatusSensor[4];
    int RPM_sensor[4];
    bool flag;
    long int timeSensor;
private slots:
    void serialRecieve();
private:
    void convert_data(QString);
};

#endif // SENSOR_H
