QT += opengl

CONFIG ''= serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
unix|win32: LIBS += -lQtSerialPort

HEADERS += \
    mainwindow.h \
    mainscene.h \
    sensor.h

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    mainscene.cpp \
    sensor.cpp

RESOURCES += \
    resource.qrc

FORMS += \
    mainwindow.ui
