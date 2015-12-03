#include "bsc.h"
#include "ui_bsc.h"
#include <QtGui>
#include <QFileDialog>

bsc::bsc(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::bsc)
{
    ui->setupUi(this);
    scanSettings();
}

void bsc::scanSettings()
{
    QString tmp;
    tmp = ui->stepSizeX->text();
    //int stepSizeX = tmp.toInt();
    tmp = ui->stepSizeY->text();
    //int stepSizeY = tmp.toInt();
   // getSaveDirectory();
    connect(ui->getDirName, SIGNAL(clicked()), this, SLOT(getFolderName()));
    connect(ui->planar, SIGNAL(clicked()), this, SLOT(getPlanarData()));
    connect(ui->sample, SIGNAL(clicked()), this, SLOT(getSampleData()));
}

QString bsc::getFolderName()
{
   //
    QString someDirName = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                 "C:/Documents and Settings/wetlab/My Documents/MATLAB/Data/",
                 QFileDialog::ShowDirsOnly);
    ui->dirName->setText(someDirName);
    return someDirName;
}

void bsc::getPlanarData()
{
    ui->statusMsg->setText("Planar Code will run");
}

void bsc::getSampleData()
{
    ui->statusMsg->setText("Sample Code will run");
}



bsc::~bsc()
{
    delete ui;
}

