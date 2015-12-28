/**
* Code to handle motor and oscilloscope
  Swetha Subramanian
*/

// GUI stuff here
#include <QtGui>
#include <QMetaType>
#include <QVector>
#include <QApplication>
#include "bsc.h"
int main(int argc, char *argv[])
{
    // Setting up GUI here
    QApplication app(argc, argv);
    bsc BSCGUI;
    BSCGUI.show();

    qRegisterMetaType<QVector<double> >("QVector<double>"); // for signals and slots to work with QVector
    return app.exec();
}
