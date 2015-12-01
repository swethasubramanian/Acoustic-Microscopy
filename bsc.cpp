#include "bsc.h"
#include "ui_bsc.h"
#include <QtGui>
#include <QFileDialog>

#include "motor.h"
#include "scope.h"
#include "settingsMotorScope.h"

bsc::bsc(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::bsc)
{
    ui->setupUi(this);
    connect(ui->acquireData, SIGNAL(clicked()), this, SLOT(acquireData()));
}

// This will read in scan parameters run the scan
void bsc::acquireData(void)
{
    connect(ui->planar, SIGNAL(clicked()), this, SLOT(getPlanarData()));
    connect(ui->sample, SIGNAL(clicked()), this, SLOT(getSampleData()));
}

// Set up motor and scope settings
void bsc::scanSettings(void)
{
    QString tmp;
    tmp = ui->stepSizeX->text();
    motorSettings.stepSizeX = tmp.toInt();
    tmp = ui->stepSizeY->text();
    motorSettings.stepSizeY = tmp.toInt();
    tmp = ui->windowSizeX->text();
    motorSettings.windowSizeX = tmp.toInt();
    tmp = ui->windowSizeY->text();
    motorSettings.windowSizeX = tmp.toInt();
    motorSettings.velX = 1000;
    motorSettings.velY = 1000;

    // Copy this to raster scan later
    //int Nx = motorSettings.windowSizeX/motorSettings.stepSizeX;
    //int Ny = motorSettings.windowSizeY/motorSettings.stepSizeY;

    // Oscilloscope Settings
    tmp = ui->numOfAverages->text();
    scopeSettings.numOfAverages = tmp.toInt();
    tmp = ui->numOfPoints->text();
    scopeSettings.numOfPoints = tmp.toInt();
}

QString bsc::saveDir()
{
    // Set File name settings here
    // Defaults
    QString parentDir = "C:/Documents and Settings/wetlab/My Documents/MATLAB/Data/";
    ui->dirName->setText(parentDir);

    // Select parent directory (optional)
    connect(ui->getDirName, SIGNAL(clicked()), this, SLOT(getParentDir()));
    parentDir = ui->dirName->text();

    // Set default experiment name (timestamp)
    QString timeStamp = QDateTime::currentDateTime().toString("MMddyyyy_hhmmss");
    ui->expName->setText(timeStamp);

    // Ask for experiment name
    QString saveDirName;
    saveDirName = ui->expName->text();

    // Create a directory for every experiment
    QString savePath = parentDir+"/"+saveDirName;
    QDir dir(savePath);
    if(!dir.exists()) dir.mkpath(".");
    return savePath;
}

void bsc::getParentDir()
{
   //
    QString parentDirName = QFileDialog::getExistingDirectory(this, tr("Select Experiment Directory"),
                 "C:/Documents and Settings/wetlab/My Documents/MATLAB/Data/",
                 QFileDialog::ShowDirsOnly);
    ui->dirName->setText(parentDirName);
}

// Motor will not move
void bsc::getPlanarData()
{
    ui->statusMsg->setText("Acquiring planar reflector data...");

    // Create a directory for saving planar data
    QString savePath = saveDir()+"/Planar";
    QDir dir(savePath);
    if(!dir.exists()) dir.mkpath(".");
    ui->statusMsg->setText("saving to: " + savePath);
}

void bsc::getSampleData()
{
    ui->statusMsg->setText("Sample Code will run");
        // Create a directory for saving planar data
    QString savePath = saveDir()+"/Sample";
    QDir dir(savePath);
    if(!dir.exists()) dir.mkpath(".");
    ui->statusMsg->setText("saving to: " + savePath);
}

bsc::~bsc()
{
    delete ui;
}
