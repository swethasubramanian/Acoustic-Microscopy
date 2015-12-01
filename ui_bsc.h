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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_bsc
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *stepSizeX;
    QLineEdit *stepSizeY;
    QLabel *label_4;
    QLineEdit *windowSizeX;
    QLineEdit *windowSizeY;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *numOfAverages;
    QLineEdit *numOfPoints;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *dirName;
    QLineEdit *expName;
    QLabel *label_10;
    QLabel *label_11;
    QToolButton *getDirName;
    QLabel *label_12;
    QRadioButton *planar;
    QRadioButton *sample;
    QLabel *statusMsg;
    QPushButton *acquireData;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *bsc)
    {
        if (bsc->objectName().isEmpty())
            bsc->setObjectName(QStringLiteral("bsc"));
        bsc->resize(645, 494);
        centralWidget = new QWidget(bsc);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 100, 46, 13));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(190, 100, 46, 13));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 120, 46, 13));
        stepSizeX = new QLineEdit(centralWidget);
        stepSizeX->setObjectName(QStringLiteral("stepSizeX"));
        stepSizeX->setGeometry(QRect(100, 120, 61, 20));
        stepSizeY = new QLineEdit(centralWidget);
        stepSizeY->setObjectName(QStringLiteral("stepSizeY"));
        stepSizeY->setGeometry(QRect(180, 120, 61, 20));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 160, 71, 16));
        windowSizeX = new QLineEdit(centralWidget);
        windowSizeX->setObjectName(QStringLiteral("windowSizeX"));
        windowSizeX->setGeometry(QRect(100, 160, 61, 20));
        windowSizeY = new QLineEdit(centralWidget);
        windowSizeY->setObjectName(QStringLiteral("windowSizeY"));
        windowSizeY->setGeometry(QRect(180, 160, 61, 20));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(140, 70, 71, 16));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(330, 120, 101, 16));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(330, 150, 91, 20));
        numOfAverages = new QLineEdit(centralWidget);
        numOfAverages->setObjectName(QStringLiteral("numOfAverages"));
        numOfAverages->setGeometry(QRect(440, 120, 113, 20));
        numOfPoints = new QLineEdit(centralWidget);
        numOfPoints->setObjectName(QStringLiteral("numOfPoints"));
        numOfPoints->setGeometry(QRect(440, 150, 113, 20));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(400, 70, 101, 16));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(230, 30, 141, 20));
        dirName = new QLineEdit(centralWidget);
        dirName->setObjectName(QStringLiteral("dirName"));
        dirName->setGeometry(QRect(120, 260, 371, 20));
        expName = new QLineEdit(centralWidget);
        expName->setObjectName(QStringLiteral("expName"));
        expName->setGeometry(QRect(120, 230, 211, 20));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(30, 260, 81, 20));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(30, 230, 91, 20));
        getDirName = new QToolButton(centralWidget);
        getDirName->setObjectName(QStringLiteral("getDirName"));
        getDirName->setGeometry(QRect(500, 260, 25, 19));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(450, 200, 91, 16));
        planar = new QRadioButton(centralWidget);
        planar->setObjectName(QStringLiteral("planar"));
        planar->setGeometry(QRect(420, 230, 82, 17));
        sample = new QRadioButton(centralWidget);
        sample->setObjectName(QStringLiteral("sample"));
        sample->setGeometry(QRect(500, 230, 82, 17));
        statusMsg = new QLabel(centralWidget);
        statusMsg->setObjectName(QStringLiteral("statusMsg"));
        statusMsg->setGeometry(QRect(30, 320, 241, 16));
        acquireData = new QPushButton(centralWidget);
        acquireData->setObjectName(QStringLiteral("acquireData"));
        acquireData->setGeometry(QRect(530, 380, 75, 23));
        bsc->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(bsc);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 645, 20));
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
        label->setText(QApplication::translate("bsc", "X (mm)", 0));
        label_2->setText(QApplication::translate("bsc", "Y (mm)", 0));
        label_3->setText(QApplication::translate("bsc", "Step Size", 0));
        stepSizeX->setText(QString());
        stepSizeY->setText(QString());
        label_4->setText(QApplication::translate("bsc", "Window Size", 0));
        label_5->setText(QApplication::translate("bsc", "Motor Settings", 0));
        label_6->setText(QApplication::translate("bsc", "Number of averages", 0));
        label_7->setText(QApplication::translate("bsc", "Number of Points", 0));
        label_8->setText(QApplication::translate("bsc", "Oscilloscope Settings", 0));
        label_9->setText(QApplication::translate("bsc", "Backscatter Measurements", 0));
        label_10->setText(QApplication::translate("bsc", "Select Directory", 0));
        label_11->setText(QApplication::translate("bsc", "Experiment Name", 0));
        getDirName->setText(QApplication::translate("bsc", "...", 0));
        label_12->setText(QApplication::translate("bsc", "Experiment Type", 0));
        planar->setText(QApplication::translate("bsc", "Planar", 0));
        sample->setText(QApplication::translate("bsc", "Sample", 0));
        statusMsg->setText(QApplication::translate("bsc", "Status Message", 0));
        acquireData->setText(QApplication::translate("bsc", "Run", 0));
    } // retranslateUi

};

namespace Ui {
    class bsc: public Ui_bsc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BSC_H
