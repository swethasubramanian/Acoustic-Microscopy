/********************************************************************************
** Form generated from reading UI file 'bsc.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BSC_H
#define UI_BSC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_bsc
{
public:
    QWidget *centralWidget;
    QLabel *label_9;
    QLabel *label_12;
    QLabel *statusMsg;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_11;
    QLineEdit *expName;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label_10;
    QLineEdit *dirName;
    QToolButton *getDirName;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *stepSizeX;
    QLineEdit *stepSizeY;
    QLabel *label_4;
    QLineEdit *windowSizeX;
    QLineEdit *windowSizeY;
    QLineEdit *stepSizeZ;
    QLineEdit *windowSizeZ;
    QLabel *label_6;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLabel *label_13;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *quitProg;
    QPushButton *acquireData;
    QWidget *layoutWidget5;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_14;
    QLineEdit *displacement;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *XDir;
    QRadioButton *YDir;
    QRadioButton *ZDir;
    QPushButton *moveMotor;
    QCustomPlot *WaveformPlot;
    QLabel *label_23;
    QPushButton *acquireWaveform;
    QWidget *layoutWidget6;
    QHBoxLayout *horizontalLayout_16;
    QPushButton *calTimeDelay;
    QPushButton *setTimeDelay;
    QWidget *layoutWidget7;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_17;
    QLabel *label_19;
    QLineEdit *waterTemperature;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_20;
    QLineEdit *t_focus;
    QHBoxLayout *horizontalLayout_18;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_24;
    QLabel *label_25;
    QLineEdit *t_frontEdge;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_21;
    QLineEdit *cWater;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_22;
    QLineEdit *cSample;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_18;
    QLineEdit *timeDelay;
    QLabel *tcpipMsg;
    QWidget *layoutWidget8;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *threeD;
    QRadioButton *sample;
    QRadioButton *planar;
    QPushButton *motorSetup;
    QPushButton *killMotor;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QButtonGroup *buttonGroup;
    QButtonGroup *buttonGroup_2;

    void setupUi(QMainWindow *bsc)
    {
        if (bsc->objectName().isEmpty())
            bsc->setObjectName(QStringLiteral("bsc"));
        bsc->resize(775, 834);
        centralWidget = new QWidget(bsc);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(310, 30, 201, 20));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(20, 520, 91, 16));
        statusMsg = new QLabel(centralWidget);
        statusMsg->setObjectName(QStringLiteral("statusMsg"));
        statusMsg->setGeometry(QRect(20, 670, 621, 16));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 600, 225, 22));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_2->addWidget(label_11);

        expName = new QLineEdit(layoutWidget);
        expName->setObjectName(QStringLiteral("expName"));

        horizontalLayout_2->addWidget(expName);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 640, 461, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(layoutWidget1);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout->addWidget(label_10);

        dirName = new QLineEdit(layoutWidget1);
        dirName->setObjectName(QStringLiteral("dirName"));

        horizontalLayout->addWidget(dirName);

        getDirName = new QToolButton(layoutWidget1);
        getDirName->setObjectName(QStringLiteral("getDirName"));

        horizontalLayout->addWidget(getDirName);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(110, 90, 230, 71));
        gridLayout = new QGridLayout(layoutWidget2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget2);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        label_2 = new QLabel(layoutWidget2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        label_3 = new QLabel(layoutWidget2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        stepSizeX = new QLineEdit(layoutWidget2);
        stepSizeX->setObjectName(QStringLiteral("stepSizeX"));

        gridLayout->addWidget(stepSizeX, 1, 1, 1, 1);

        stepSizeY = new QLineEdit(layoutWidget2);
        stepSizeY->setObjectName(QStringLiteral("stepSizeY"));

        gridLayout->addWidget(stepSizeY, 1, 2, 1, 1);

        label_4 = new QLabel(layoutWidget2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        windowSizeX = new QLineEdit(layoutWidget2);
        windowSizeX->setObjectName(QStringLiteral("windowSizeX"));

        gridLayout->addWidget(windowSizeX, 2, 1, 1, 1);

        windowSizeY = new QLineEdit(layoutWidget2);
        windowSizeY->setObjectName(QStringLiteral("windowSizeY"));

        gridLayout->addWidget(windowSizeY, 2, 2, 1, 1);

        stepSizeZ = new QLineEdit(layoutWidget2);
        stepSizeZ->setObjectName(QStringLiteral("stepSizeZ"));

        gridLayout->addWidget(stepSizeZ, 1, 3, 1, 1);

        windowSizeZ = new QLineEdit(layoutWidget2);
        windowSizeZ->setObjectName(QStringLiteral("windowSizeZ"));

        gridLayout->addWidget(windowSizeZ, 2, 3, 1, 1);

        label_6 = new QLabel(layoutWidget2);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 0, 3, 1, 1);

        layoutWidget3 = new QWidget(centralWidget);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(50, 70, 701, 16));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget3);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        label_13 = new QLabel(layoutWidget3);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_5->addWidget(label_13);

        layoutWidget4 = new QWidget(centralWidget);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(490, 710, 239, 25));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        quitProg = new QPushButton(layoutWidget4);
        quitProg->setObjectName(QStringLiteral("quitProg"));

        horizontalLayout_7->addWidget(quitProg);

        acquireData = new QPushButton(layoutWidget4);
        acquireData->setObjectName(QStringLiteral("acquireData"));

        horizontalLayout_7->addWidget(acquireData);

        layoutWidget5 = new QWidget(centralWidget);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(540, 90, 201, 61));
        verticalLayout_2 = new QVBoxLayout(layoutWidget5);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_14 = new QLabel(layoutWidget5);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_6->addWidget(label_14);

        displacement = new QLineEdit(layoutWidget5);
        displacement->setObjectName(QStringLiteral("displacement"));

        horizontalLayout_6->addWidget(displacement);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        XDir = new QRadioButton(layoutWidget5);
        buttonGroup_2 = new QButtonGroup(bsc);
        buttonGroup_2->setObjectName(QStringLiteral("buttonGroup_2"));
        buttonGroup_2->addButton(XDir);
        XDir->setObjectName(QStringLiteral("XDir"));

        horizontalLayout_4->addWidget(XDir);

        YDir = new QRadioButton(layoutWidget5);
        buttonGroup_2->addButton(YDir);
        YDir->setObjectName(QStringLiteral("YDir"));

        horizontalLayout_4->addWidget(YDir);

        ZDir = new QRadioButton(layoutWidget5);
        buttonGroup_2->addButton(ZDir);
        ZDir->setObjectName(QStringLiteral("ZDir"));

        horizontalLayout_4->addWidget(ZDir);

        moveMotor = new QPushButton(layoutWidget5);
        moveMotor->setObjectName(QStringLiteral("moveMotor"));

        horizontalLayout_4->addWidget(moveMotor);


        horizontalLayout_8->addLayout(horizontalLayout_4);


        verticalLayout_2->addLayout(horizontalLayout_8);

        WaveformPlot = new QCustomPlot(centralWidget);
        WaveformPlot->setObjectName(QStringLiteral("WaveformPlot"));
        WaveformPlot->setGeometry(QRect(10, 200, 481, 271));
        label_23 = new QLabel(centralWidget);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(590, 230, 131, 16));
        acquireWaveform = new QPushButton(centralWidget);
        acquireWaveform->setObjectName(QStringLiteral("acquireWaveform"));
        acquireWaveform->setGeometry(QRect(10, 490, 121, 23));
        layoutWidget6 = new QWidget(centralWidget);
        layoutWidget6->setObjectName(QStringLiteral("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(540, 440, 194, 25));
        horizontalLayout_16 = new QHBoxLayout(layoutWidget6);
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        horizontalLayout_16->setContentsMargins(0, 0, 0, 0);
        calTimeDelay = new QPushButton(layoutWidget6);
        calTimeDelay->setObjectName(QStringLiteral("calTimeDelay"));

        horizontalLayout_16->addWidget(calTimeDelay);

        setTimeDelay = new QPushButton(layoutWidget6);
        setTimeDelay->setObjectName(QStringLiteral("setTimeDelay"));

        horizontalLayout_16->addWidget(setTimeDelay);

        layoutWidget7 = new QWidget(centralWidget);
        layoutWidget7->setObjectName(QStringLiteral("layoutWidget7"));
        layoutWidget7->setGeometry(QRect(530, 250, 241, 178));
        verticalLayout = new QVBoxLayout(layoutWidget7);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label_17 = new QLabel(layoutWidget7);
        label_17->setObjectName(QStringLiteral("label_17"));

        horizontalLayout_14->addWidget(label_17);

        label_19 = new QLabel(layoutWidget7);
        label_19->setObjectName(QStringLiteral("label_19"));

        horizontalLayout_14->addWidget(label_19);

        waterTemperature = new QLineEdit(layoutWidget7);
        waterTemperature->setObjectName(QStringLiteral("waterTemperature"));

        horizontalLayout_14->addWidget(waterTemperature);


        verticalLayout->addLayout(horizontalLayout_14);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        label_20 = new QLabel(layoutWidget7);
        label_20->setObjectName(QStringLiteral("label_20"));

        horizontalLayout_17->addWidget(label_20);

        t_focus = new QLineEdit(layoutWidget7);
        t_focus->setObjectName(QStringLiteral("t_focus"));

        horizontalLayout_17->addWidget(t_focus);


        verticalLayout->addLayout(horizontalLayout_17);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_24 = new QLabel(layoutWidget7);
        label_24->setObjectName(QStringLiteral("label_24"));

        verticalLayout_4->addWidget(label_24);

        label_25 = new QLabel(layoutWidget7);
        label_25->setObjectName(QStringLiteral("label_25"));

        verticalLayout_4->addWidget(label_25);


        horizontalLayout_18->addLayout(verticalLayout_4);

        t_frontEdge = new QLineEdit(layoutWidget7);
        t_frontEdge->setObjectName(QStringLiteral("t_frontEdge"));

        horizontalLayout_18->addWidget(t_frontEdge);


        verticalLayout->addLayout(horizontalLayout_18);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_21 = new QLabel(layoutWidget7);
        label_21->setObjectName(QStringLiteral("label_21"));

        horizontalLayout_12->addWidget(label_21);

        cWater = new QLineEdit(layoutWidget7);
        cWater->setObjectName(QStringLiteral("cWater"));

        horizontalLayout_12->addWidget(cWater);


        verticalLayout->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_22 = new QLabel(layoutWidget7);
        label_22->setObjectName(QStringLiteral("label_22"));

        horizontalLayout_13->addWidget(label_22);

        cSample = new QLineEdit(layoutWidget7);
        cSample->setObjectName(QStringLiteral("cSample"));

        horizontalLayout_13->addWidget(cSample);


        verticalLayout->addLayout(horizontalLayout_13);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        label_18 = new QLabel(layoutWidget7);
        label_18->setObjectName(QStringLiteral("label_18"));

        horizontalLayout_15->addWidget(label_18);

        timeDelay = new QLineEdit(layoutWidget7);
        timeDelay->setObjectName(QStringLiteral("timeDelay"));

        horizontalLayout_15->addWidget(timeDelay);


        verticalLayout->addLayout(horizontalLayout_15);

        tcpipMsg = new QLabel(centralWidget);
        tcpipMsg->setObjectName(QStringLiteral("tcpipMsg"));
        tcpipMsg->setGeometry(QRect(10, 180, 391, 16));
        layoutWidget8 = new QWidget(centralWidget);
        layoutWidget8->setObjectName(QStringLiteral("layoutWidget8"));
        layoutWidget8->setGeometry(QRect(21, 561, 193, 19));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget8);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        threeD = new QRadioButton(layoutWidget8);
        buttonGroup = new QButtonGroup(bsc);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(threeD);
        threeD->setObjectName(QStringLiteral("threeD"));

        horizontalLayout_3->addWidget(threeD);

        sample = new QRadioButton(layoutWidget8);
        buttonGroup->addButton(sample);
        sample->setObjectName(QStringLiteral("sample"));

        horizontalLayout_3->addWidget(sample);

        planar = new QRadioButton(layoutWidget8);
        buttonGroup->addButton(planar);
        planar->setObjectName(QStringLiteral("planar"));

        horizontalLayout_3->addWidget(planar);

        motorSetup = new QPushButton(centralWidget);
        motorSetup->setObjectName(QStringLiteral("motorSetup"));
        motorSetup->setGeometry(QRect(540, 160, 75, 23));
        killMotor = new QPushButton(centralWidget);
        killMotor->setObjectName(QStringLiteral("killMotor"));
        killMotor->setGeometry(QRect(630, 160, 75, 23));
        bsc->setCentralWidget(centralWidget);
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        label_9->raise();
        label_12->raise();
        statusMsg->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        WaveformPlot->raise();
        label_23->raise();
        acquireWaveform->raise();
        tcpipMsg->raise();
        layoutWidget->raise();
        motorSetup->raise();
        killMotor->raise();
        menuBar = new QMenuBar(bsc);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 775, 21));
        bsc->setMenuBar(menuBar);
        mainToolBar = new QToolBar(bsc);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        bsc->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(bsc);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        bsc->setStatusBar(statusBar);

        retranslateUi(bsc);

        QMetaObject::connectSlotsByName(bsc);
    } // setupUi

    void retranslateUi(QMainWindow *bsc)
    {
        bsc->setWindowTitle(QApplication::translate("bsc", "bsc", 0));
        label_9->setText(QApplication::translate("bsc", "Scan Tank Software", 0));
        label_12->setText(QApplication::translate("bsc", "Experiment Type", 0));
        statusMsg->setText(QApplication::translate("bsc", "Status Message: ", 0));
        label_11->setText(QApplication::translate("bsc", "Experiment Name", 0));
        label_10->setText(QApplication::translate("bsc", "Select Directory   ", 0));
        getDirName->setText(QApplication::translate("bsc", "...", 0));
        label->setText(QApplication::translate("bsc", "X (mm)", 0));
        label_2->setText(QApplication::translate("bsc", "Y (mm)", 0));
        label_3->setText(QApplication::translate("bsc", "Step Size", 0));
        stepSizeX->setText(QString());
        stepSizeY->setText(QString());
        label_4->setText(QApplication::translate("bsc", "Window Size", 0));
        label_6->setText(QApplication::translate("bsc", "Z (mm)", 0));
        label_5->setText(QApplication::translate("bsc", "                                              Motor Settings", 0));
        label_13->setText(QApplication::translate("bsc", "                                            Motor Controls", 0));
        quitProg->setText(QApplication::translate("bsc", "Quit", 0));
        acquireData->setText(QApplication::translate("bsc", "Run", 0));
        label_14->setText(QApplication::translate("bsc", "Displacement (mm)  ", 0));
        XDir->setText(QApplication::translate("bsc", "X ", 0));
        YDir->setText(QApplication::translate("bsc", " Y", 0));
        ZDir->setText(QApplication::translate("bsc", "Z", 0));
        moveMotor->setText(QApplication::translate("bsc", "Move ", 0));
        label_23->setText(QApplication::translate("bsc", "Sample waveform settings", 0));
        acquireWaveform->setText(QApplication::translate("bsc", "Update Waveform", 0));
        calTimeDelay->setText(QApplication::translate("bsc", "Calculate Time Delay", 0));
        setTimeDelay->setText(QApplication::translate("bsc", "Set Time Delay", 0));
        label_17->setText(QString());
        label_19->setText(QApplication::translate("bsc", "Water temperature =    ", 0));
        label_20->setText(QApplication::translate("bsc", "Time delay at focus (ns) =", 0));
        label_24->setText(QApplication::translate("bsc", "Time delay at front", 0));
        label_25->setText(QApplication::translate("bsc", " edge of sample (ns)", 0));
        label_21->setText(QApplication::translate("bsc", "Speed of Sound in Water (m/s) = ", 0));
        label_22->setText(QApplication::translate("bsc", "Speed of Sound in Sample (m/s)= ", 0));
        label_18->setText(QApplication::translate("bsc", "Time Delay (ns) =                        ", 0));
        tcpipMsg->setText(QApplication::translate("bsc", "TCPIP Status:", 0));
        threeD->setText(QApplication::translate("bsc", "3D", 0));
        sample->setText(QApplication::translate("bsc", "2D", 0));
        planar->setText(QApplication::translate("bsc", "Planar (no motor)", 0));
        motorSetup->setText(QApplication::translate("bsc", "Motor Setup", 0));
        killMotor->setText(QApplication::translate("bsc", "Kill Motor", 0));
    } // retranslateUi

};

namespace Ui {
    class bsc: public Ui_bsc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BSC_H
