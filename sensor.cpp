#include "sensor.h"
#include <qt4/Qt/qdebug.h>
#include <qt4/Qt/qstring.h>
#include <qt4/Qt/qlist.h>

mySensor::mySensor()
{
    this->initSerial();
    for(int i = 0; i < 4; i++)
    {
        statusSensor[i] = 0;
        oldStatusSensor[i] = 0;
        detStatusSensor[i] = 0;
        RPM_sensor[i] = 0;
    }
    flag = false;
}

mySensor::~mySensor()
{
    this->deinitSerial();
}
//

void mySensor::initSerial()
{
    serial = new QSerialPort(); // Новый экземпляр класса AbstractSerial
    connect(this->serial, SIGNAL(readyRead()), this, SLOT(serialRecieve())); // объявляем наше "прерывание" по получении данных
}

void mySensor::deinitSerial()
{
    if (this->serial->isOpen()){
        this->serial->close();
    }
    delete serial;
}


void mySensor::openPort(QString namePort)
{
    if (this->serial->isOpen()) {
        serial->close();
    }
    else
    {
        serial->setPortName(namePort);

        if (serial->open(QIODevice::ReadWrite))
        {
            //Настройка порта
            serial->setBaudRate(38400); // Скорость выбираем из выпадающего списка cbBaud
            serial->setDataBits(QSerialPort::Data8);
            serial->setParity(QSerialPort::NoParity);
            serial->setStopBits(QSerialPort::OneStop);
            serial->setFlowControl(QSerialPort::NoFlowControl);

            //Вывод отладочных сообщений
            qDebug() << "PORT " << serial->portName()<< " open in regim " << serial->openMode();
            qDebug() << "Baud rate:" << serial->baudRate();
            qDebug() << "Data bits:" << serial->dataBits();
            qDebug() << "Stop bits:" << serial->stopBits();
            qDebug() << "Parity:" << serial->parity();
            qDebug() << "Flow control:" << serial->flowControl();
            qDebug() << "Read buffer size:" << serial->readBufferSize();

            qDebug()<<"Close";
        } else {
            qDebug() << "Unable to open port, error code" << serial->error();
        }
    }
}


void mySensor::serialRecieve()
{

    QByteArray data = serial->readAll();
    QString str=QString(data);
    controller_message +=str;
    int i = controller_message.indexOf(QString("BEGIN"));
    if(controller_message.contains(QString("BEGIN"))){
        controller_message.remove(0,i+5);
    }
    if(controller_message.contains(QString("END"))){
        i = controller_message.indexOf(QString("END"));
        QString test;
        test = controller_message.left(i);
        convert_data(test);
        //qDebug() << "This is our package" << test;
        controller_message = controller_message.right(i+3);
    }
    //qDebug()<<"Controller message = " << controller_message;
}

void mySensor::convert_data(QString inputStr)
{
    QStringList list = inputStr.split(" ", QString::SkipEmptyParts);
    timeSensor = list.at(1).toLong();
    statusSensor[0] = list.at(3).toInt();
    statusSensor[1] = list.at(5).toInt();
    statusSensor[2] = list.at(4).toInt();
    statusSensor[3] = list.at(6).toInt();

    for(int i = 0; i < 4; i++)
    {
        statusSensor[i] -= detStatusSensor[i];
        RPM_sensor[i] = statusSensor[i] - oldStatusSensor[i];
        if(statusSensor[i] - oldStatusSensor[i] > 10)
        {
            detStatusSensor[i] += statusSensor[i] - oldStatusSensor[i];
            statusSensor[i] = oldStatusSensor[i];
        }
        oldStatusSensor[i] = statusSensor[i];
    }

    if(flag == 0)
    {
        for(int i = 0; i < 4; i++)
        {
            detStatusSensor[i] = statusSensor[i];
            statusSensor[i] = 0;
        }
        flag = true;
    }
    //qDebug()<<"Time (ms) "<<timeSensor;
    qDebug()<<"Status sensor (numbs):"<<statusSensor[0]<<statusSensor[1]<<statusSensor[2]<<statusSensor[3];
}

void mySensor::commandSend(QString command)
{
    serial->write(QByteArray().append(command));
    serial->waitForBytesWritten(100);
}

void mySensor::search()
{
    QString text;
    text.clear();
    QSerialPortInfo* QSI = new QSerialPortInfo();
    foreach (const QSerialPortInfo &QSI, QSerialPortInfo::availablePorts())
    {
        text.push_back(QSI.portName());
        //ui->PortNameBox->addItem(info.portName());
    }
    qDebug()<<text;
    QSI->~QSerialPortInfo();
}
