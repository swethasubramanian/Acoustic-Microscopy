#include "bsc.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    bsc w;
    w.show();

    return a.exec();
}
