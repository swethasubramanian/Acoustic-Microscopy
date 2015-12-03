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

QT_BEGIN_NAMESPACE

class Ui_bsc
{
public:
    QWidget *centralWidget;
    QLabel *label_9;
    QLabel *label_12;
    QLabel *statusMsg;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_11;
    QLineEdit *expName;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label_10;
    QLineEdit *dirName;
    QToolButton *getDirName;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *sample;
    QRadioButton *planar;
    QWidget *widget3;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *stepSizeX;
    QLineEdit *stepSizeY;
    QLabel *label_4;
    QLineEdit *windowSizeX;
    QLineEdit *windowSizeY;
    QWidget *widget4;
    QGridLayout *gridLayout_2;
    QLabel *label_7;
    QLineEdit *numOfAverages;
    QLineEdit *numOfPoints;
    QLabel *label_6;
    QWidget *widget5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLabel *label_8;
    QLabel *label_13;
    QWidget *widget6;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *killMotor;
    QPushButton *quitProg;
    QPushButton *acquireData;
    QWidget *widget7;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *XDir;
    QRadioButton *YDir;
    QRadioButton *ZDir;
    QPushButton *moveMotor;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_14;
    QLineEdit *displacement;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QButtonGroup *buttonGroup;
    QButtonGroup *buttonGroup_2;

    void setupUi(QMainWindow *bsc)
    {
        if (bsc->objectName().isEmpty())
            bsc->setObjectName(QStringLiteral("bsc"));
        bsc->resize(596, 449);
        centralWidget = new QWidget(bsc);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(190, 20, 201, 20));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(30, 200, 91, 16));
        statusMsg = new QLabel(centralWidget);
        statusMsg->setObjectName(QStringLiteral("statusMsg"));
        statusMsg->setGeometry(QRect(30, 340, 531, 16));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(30, 260, 225, 22));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(widget);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_2->addWidget(label_11);

        expName = new QLineEdit(widget);
        expName->setObjectName(QStringLiteral("expName"));

        horizontalLayout_2->addWidget(expName);

        widget1 = new QWidget(centralWidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(30, 290, 461, 22));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(widget1);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout->addWidget(label_10);

        dirName = new QLineEdit(widget1);
        dirName->setObjectName(QStringLiteral("dirName"));

        horizontalLayout->addWidget(dirName);

        getDirName = new QToolButton(widget1);
        getDirName->setObjectName(QStringLiteral("getDirName"));

        horizontalLayout->addWidget(getDirName);

        widget2 = new QWidget(centralWidget);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(30, 230, 172, 19));
        horizontalLayout_3 = new QHBoxLayout(widget2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        sample = new QRadioButton(widget2);
        buttonGroup = new QButtonGroup(bsc);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(sample);
        sample->setObjectName(QStringLiteral("sample"));

        horizontalLayout_3->addWidget(sample);

        planar = new QRadioButton(widget2);
        buttonGroup->addButton(planar);
        planar->setObjectName(QStringLiteral("planar"));

        horizontalLayout_3->addWidget(planar);

        widget3 = new QWidget(centralWidget);
        widget3->setObjectName(QStringLiteral("widget3"));
        widget3->setGeometry(QRect(10, 100, 171, 67));
        gridLayout = new QGridLayout(widget3);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget3);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        label_2 = new QLabel(widget3);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        label_3 = new QLabel(widget3);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        stepSizeX = new QLineEdit(widget3);
        stepSizeX->setObjectName(QStringLiteral("stepSizeX"));

        gridLayout->addWidget(stepSizeX, 1, 1, 1, 1);

        stepSizeY = new QLineEdit(widget3);
        stepSizeY->setObjectName(QStringLiteral("stepSizeY"));

        gridLayout->addWidget(stepSizeY, 1, 2, 1, 1);

        label_4 = new QLabel(widget3);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        windowSizeX = new QLineEdit(widget3);
        windowSizeX->setObjectName(QStringLiteral("windowSizeX"));

        gridLayout->addWidget(windowSizeX, 2, 1, 1, 1);

        windowSizeY = new QLineEdit(widget3);
        windowSizeY->setObjectName(QStringLiteral("windowSizeY"));

        gridLayout->addWidget(windowSizeY, 2, 2, 1, 1);

        widget4 = new QWidget(centralWidget);
        widget4->setObjectName(QStringLiteral("widget4"));
        widget4->setGeometry(QRect(200, 116, 171, 51));
        gridLayout_2 = new QGridLayout(widget4);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(widget4);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_2->addWidget(label_7, 1, 0, 1, 1);

        numOfAverages = new QLineEdit(widget4);
        numOfAverages->setObjectName(QStringLiteral("numOfAverages"));

        gridLayout_2->addWidget(numOfAverages, 0, 1, 1, 1);

        numOfPoints = new QLineEdit(widget4);
        numOfPoints->setObjectName(QStringLiteral("numOfPoints"));

        gridLayout_2->addWidget(numOfPoints, 1, 1, 1, 1);

        label_6 = new QLabel(widget4);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 0, 0, 1, 1);

        widget5 = new QWidget(centralWidget);
        widget5->setObjectName(QStringLiteral("widget5"));
        widget5->setGeometry(QRect(50, 70, 541, 16));
        horizontalLayout_5 = new QHBoxLayout(widget5);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(widget5);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        label_8 = new QLabel(widget5);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_5->addWidget(label_8);

        label_13 = new QLabel(widget5);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_5->addWidget(label_13);

        widget6 = new QWidget(centralWidget);
        widget6->setObjectName(QStringLiteral("widget6"));
        widget6->setGeometry(QRect(290, 370, 239, 25));
        horizontalLayout_7 = new QHBoxLayout(widget6);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        killMotor = new QPushButton(widget6);
        killMotor->setObjectName(QStringLiteral("killMotor"));

        horizontalLayout_7->addWidget(killMotor);

        quitProg = new QPushButton(widget6);
        quitProg->setObjectName(QStringLiteral("quitProg"));

        horizontalLayout_7->addWidget(quitProg);

        acquireData = new QPushButton(widget6);
        acquireData->setObjectName(QStringLiteral("acquireData"));

        horizontalLayout_7->addWidget(acquireData);

        widget7 = new QWidget(centralWidget);
        widget7->setObjectName(QStringLiteral("widget7"));
        widget7->setGeometry(QRect(390, 120, 191, 51));
        verticalLayout = new QVBoxLayout(widget7);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        XDir = new QRadioButton(widget7);
        buttonGroup_2 = new QButtonGroup(bsc);
        buttonGroup_2->setObjectName(QStringLiteral("buttonGroup_2"));
        buttonGroup_2->addButton(XDir);
        XDir->setObjectName(QStringLiteral("XDir"));

        horizontalLayout_4->addWidget(XDir);

        YDir = new QRadioButton(widget7);
        buttonGroup_2->addButton(YDir);
        YDir->setObjectName(QStringLiteral("YDir"));

        horizontalLayout_4->addWidget(YDir);

        ZDir = new QRadioButton(widget7);
        buttonGroup_2->addButton(ZDir);
        ZDir->setObjectName(QStringLiteral("ZDir"));

        horizontalLayout_4->addWidget(ZDir);


        horizontalLayout_8->addLayout(horizontalLayout_4);

        moveMotor = new QPushButton(widget7);
        moveMotor->setObjectName(QStringLiteral("moveMotor"));

        horizontalLayout_8->addWidget(moveMotor);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_14 = new QLabel(widget7);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_6->addWidget(label_14);

        displacement = new QLineEdit(widget7);
        displacement->setObjectName(QStringLiteral("displacement"));

        horizontalLayout_6->addWidget(displacement);


        verticalLayout->addLayout(horizontalLayout_6);

        bsc->setCentralWidget(centralWidget);
        label->raise();
        label_2->raise();
        label_3->raise();
        stepSizeX->raise();
        stepSizeY->raise();
        label_4->raise();
        windowSizeX->raise();
        windowSizeY->raise();
        label_5->raise();
        label_6->raise();
        label_7->raise();
        numOfAverages->raise();
        numOfPoints->raise();
        label_8->raise();
        label_9->raise();
        dirName->raise();
        expName->raise();
        label_10->raise();
        label_11->raise();
        getDirName->raise();
        label_12->raise();
        planar->raise();
        sample->raise();
        statusMsg->raise();
        acquireData->raise();
        killMotor->raise();
        quitProg->raise();
        XDir->raise();
        label_13->raise();
        ZDir->raise();
        YDir->raise();
        displacement->raise();
        label_14->raise();
        moveMotor->raise();
        label_14->raise();
        menuBar = new QMenuBar(bsc);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 596, 20));
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
        label_9->setText(QApplication::translate("bsc", "        BSC Measurement Tool", 0));
        label_12->setText(QApplication::translate("bsc", "Experiment Type", 0));
        statusMsg->setText(QApplication::translate("bsc", "Status Message: ", 0));
        label_11->setText(QApplication::translate("bsc", "Experiment Name", 0));
        label_10->setText(QApplication::translate("bsc", "Select Directory", 0));
        getDirName->setText(QApplication::translate("bsc", "...", 0));
        sample->setText(QApplication::translate("bsc", "Sample", 0));
        planar->setText(QApplication::translate("bsc", "Planar (no motor)", 0));
        label->setText(QApplication::translate("bsc", "X (mm)", 0));
        label_2->setText(QApplication::translate("bsc", "Y (mm)", 0));
        label_3->setText(QApplication::translate("bsc", "Step Size", 0));
        stepSizeX->setText(QString());
        stepSizeY->setText(QString());
        label_4->setText(QApplication::translate("bsc", "Window Size", 0));
        label_7->setText(QApplication::translate("bsc", "Number of Points", 0));
        label_6->setText(QApplication::translate("bsc", "Number of Averages", 0));
        label_5->setText(QApplication::translate("bsc", "Motor Settings", 0));
        label_8->setText(QApplication::translate("bsc", "Oscilloscope Settings", 0));
        label_13->setText(QApplication::translate("bsc", "Motor Controls", 0));
        killMotor->setText(QApplication::translate("bsc", "Kill Motors", 0));
        quitProg->setText(QApplication::translate("bsc", "Quit", 0));
        acquireData->setText(QApplication::translate("bsc", "Run", 0));
        XDir->setText(QApplication::translate("bsc", "X ", 0));
        YDir->setText(QApplication::translate("bsc", " Y", 0));
        ZDir->setText(QApplication::translate("bsc", "Z", 0));
        moveMotor->setText(QApplication::translate("bsc", "Move ", 0));
        label_14->setText(QApplication::translate("bsc", "Displacement (mm)", 0));
    } // retranslateUi

};

namespace Ui {
    class bsc: public Ui_bsc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BSC_H
