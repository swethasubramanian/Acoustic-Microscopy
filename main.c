/**
* Code to handle motor and oscilloscope
  Swetha Subramanian
*/

// GUI stuff here
#include <QtGui>
#include <QApplication>
#include "bsc.h"
int main(int argc, char *argv[])
{
    // Setting up GUI here
    QApplication app(argc, argv);
    bsc gooey;
    gooey.show();
    return app.exec();
}
