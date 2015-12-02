#include "bsc.h"
#include "ui_bsc.h"
#include <QtGui>
#include <QFileDialog>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <QtConcurrent/QtConcurrent>
//#include <sstream>

#include "motor.h"
#include "scope.h"
#include "settingsMotorScope.h"

bsc::bsc(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::bsc)
{
    ui->setupUi(this);

    // Load up defaults here
    // Default parent directory
    QString parentDir = "C:/Documents and Settings/wetlab/My Documents/MATLAB/Data/";
    ui->dirName->setText(parentDir);

    // Set default experiment name (timestamp)
    QString timeStamp = QDateTime::currentDateTime().toString("MMddyyyy_hhmmss");
    ui->expName->setText(timeStamp);

    // Setting default motor and ocilloscope settings
    ui->stepSizeX->setText("3");
    ui->stepSizeY->setText("3");
    ui->windowSizeX->setText("18");
    ui->windowSizeY->setText("18");
    ui->numOfAverages->setText("1000");
    ui->numOfPoints->setText("1000");

    ui->planar->setChecked(true);
    connect(ui->acquireData, SIGNAL(clicked()), this, SLOT(acquire()));
}


// This will read in scan parameters and run the scan
void bsc::acquire(void)
{
    getParameters();
    Nx = motorSettings.windowSizeX/motorSettings.stepSizeX;
    Ny = motorSettings.windowSizeY/motorSettings.stepSizeY;
    if (ui->planar->isChecked())
    {
    ui->statusMsg->setText("Acquiring planar reflector data...");

    // Create a directory for saving planar data
    savePath = saveDir()+"/Planar";
    QDir dir(savePath);
    if(!dir.exists()) dir.mkpath(".");
        SCOPE.initializeScope(scopeSettings);
        connect(this, SIGNAL(acquireScopeData(int)), this, SLOT(getData(int)));
        getPlanar(0);
        ui->statusMsg->setText("Done!");
        SCOPE.closeScope();
    }
    if (ui->sample->isChecked()) getSampleData();
}

void bsc::getPlanar(int counter)
{
    counter++;
    if (counter<5) acquireScopeData(counter);
}

void bsc::getData(int i)
{
    // Setup scan
        ui->statusMsg->setText("saving to: " + savePath);
        qFilename = savePath + QString("//%1.dat").arg(i) ;
        std::string filename = qFilename.toUtf8().constData();
        SCOPE.getScopeData(filename.c_str(), scopeSettings);
        ui->statusMsg->setText("saving to: " + qFilename);
        getPlanar(i);
}

// Set up motor and scope settings
void bsc::getParameters(void)
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

    // Oscilloscope Settings
    tmp = ui->numOfAverages->text();
    scopeSettings.numOfAverages = tmp.toInt();
    tmp = ui->numOfPoints->text();
    scopeSettings.numOfPoints = tmp.toInt();
}

QString bsc::saveDir()
{
    // Set File name settings here
    // Select parent directory (optional)
    connect(ui->getDirName, SIGNAL(clicked()), this, SLOT(getParentDir()));
    QString parentDir = ui->dirName->text();

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




void bsc::getSampleData()
{
    getParameters();
    ui->statusMsg->setText("Acquiring sample data...");

    // Create a directory for saving planar data
    QString savePath = saveDir()+"/Sample";
    QDir dir(savePath);
    if(!dir.exists()) dir.mkpath(".");
    ui->statusMsg->setText("saving to: " + savePath);

    // Setup scan
    scope SCOPE;
    SCOPE.initializeScope(scopeSettings);
    int Nx = motorSettings.windowSizeX/motorSettings.stepSizeX;
    int Ny = motorSettings.windowSizeY/motorSettings.stepSizeY;

    int i;
    QString qFilename;
    for (i = 0; i <= Nx*Ny; i++)
    {
        qFilename = savePath + QString("/%1.dat").arg(i);
        std::string filename = qFilename.toLocal8Bit().constData();
        SCOPE.getScopeData(filename.c_str(), scopeSettings);
        ui->statusMsg->setText("saving to: " + qFilename);
    }
    ui->statusMsg->setText(QString("%1").arg(Nx));
}

bsc::~bsc()
{
    delete ui;
}
