#include "bsc.h"
#include "ui_bsc.h"
#include <QtGui>

bsc::bsc(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::bsc)
{
    ui->setupUi(this);
}

void bsc::scanSettings(void)
{
    QString tmp;
    tmp = ui->stepSizeX->text();
    int stepSizeX = tmp.toInt();
    tmp = ui->stepSizeY->text();
    int stepSizeY = tmp.toInt();
}

bsc::~bsc()
{
    delete ui;
}
