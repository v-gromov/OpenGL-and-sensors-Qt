/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Jun 29 15:14:45 2015
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>
#include "mainscene.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    MainScene *cubeWidget;
    QTextEdit *port_message;
    QLineEdit *port_name;
    QPushButton *port_button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1318, 863);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        cubeWidget = new MainScene(centralwidget);
        cubeWidget->setObjectName(QString::fromUtf8("cubeWidget"));
        cubeWidget->setEnabled(true);
        cubeWidget->setGeometry(QRect(250, 20, 801, 801));
        cubeWidget->setCursor(QCursor(Qt::ArrowCursor));
        cubeWidget->setMouseTracking(false);
        port_message = new QTextEdit(centralwidget);
        port_message->setObjectName(QString::fromUtf8("port_message"));
        port_message->setGeometry(QRect(1070, 200, 241, 171));
        port_name = new QLineEdit(centralwidget);
        port_name->setObjectName(QString::fromUtf8("port_name"));
        port_name->setGeometry(QRect(1070, 120, 141, 31));
        port_button = new QPushButton(centralwidget);
        port_button->setObjectName(QString::fromUtf8("port_button"));
        port_button->setGeometry(QRect(1220, 120, 95, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1318, 29));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        port_button->setText(QApplication::translate("MainWindow", "open", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
