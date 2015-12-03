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
    connect(ui->moveMotor, SIGNAL(clicked()), this, SLOT(movMotor()));
    connect(ui->killMotor, SIGNAL(clicked()), this, SLOT(killMotor()));
}

// This will read in scan parameters and run the scan
void bsc::acquire(void)
{
    getParameters();
    Nx = motorSettings.windowSizeX/motorSettings.stepSizeX;
    Ny = motorSettings.windowSizeY/motorSettings.stepSizeY;
    connect(this, SIGNAL(acquireScopeData(int)), this, SLOT(getDataFromScope(int)));
    if (ui->planar->isChecked()) getPlanarData();
    if (ui->sample->isChecked()) getSampleData();
}

void bsc::movMotor(void)
{
    QString tmp;
    tmp = ui->displacement->text();
    double dist = tmp.toDouble();
    if (ui->XDir->isChecked())
    {
        MOTOR.openMotor(motorSettings);
        MOTOR.mov(motorSettings, "X", dist);
        MOTOR.closeMotor();
    }
    else if (ui->YDir->isChecked())
    {
        MOTOR.openMotor(motorSettings);
        MOTOR.mov(motorSettings, "Y", dist);
        MOTOR.closeMotor();
    }
    else if (ui->ZDir->isChecked())
    {
        MOTOR.openMotor(motorSettings);
        MOTOR.mov(motorSettings, "Z", dist);
        MOTOR.closeMotor();
    }
}

void bsc::killMotor(void)
{
    MOTOR.killMotor();
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
    motorSettings.windowSizeY = tmp.toInt();
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

void bsc::getPlanarData()
{
    ui->statusMsg->setText("Acquiring planar reflector data...");
    // Create a directory for saving planar data
    savePath = saveDir()+"/Planar";
    QDir dir(savePath);
    if(!dir.exists()) dir.mkpath(".");

    //Set up scan
        SCOPE.initializeScope(scopeSettings);
        for (int k=1;k<Nx*Ny;k++) acquireScopeData(k);
        ui->statusMsg->setText("Done!");
        SCOPE.closeScope();
}

void bsc::getSampleData()
{
    getParameters();
    ui->statusMsg->setText("Acquiring sample data...");
    // Create a directory for saving planar data
    savePath = saveDir()+"/Sample";
    QDir dir(savePath);
    if(!dir.exists()) dir.mkpath(".");

    // Setup scan
    SCOPE.initializeScope(scopeSettings);
    double windowX = motorSettings.windowSizeX;
    double windowY = motorSettings.windowSizeY;
    double stepXmm = motorSettings.stepSizeX;
    double stepYmm = motorSettings.stepSizeY;
    MOTOR.openMotor(motorSettings);

    // move motor to bottom left of the ROI (from computer perspective) and get scope data
    MOTOR.mov(motorSettings, "X", -windowX/2); //(minus is left)
    MOTOR.mov(motorSettings, "Y", windowY/2); //(minus is up)
    int k=1;
    int i,j;
    ui->statusMsg->setText(QString("k is %1").arg(k));
    acquireScopeData(k);

    for (int i=0; i<=Nx; i++)
    {
        if (i>0)
        {
            MOTOR.mov(motorSettings, "X", stepXmm);
            k++;
            acquireScopeData(k);
        }
        if (i%2 == 0)
        {
            for (j=0; j<=Ny; j++)
            {
                if (j>0)
                {
                    MOTOR.mov(motorSettings, "Y", -stepYmm);
                    k++;
                    acquireScopeData(k);
                }
            }
        }
        else
        {
            for (j=0; j<=Ny; j++)
            {
                if (j>0)
                {
                    MOTOR.mov(motorSettings, "Y", stepYmm);
                    k++;
                    acquireScopeData(k);
                }
            }
        }
    }
    // Move motor back to center of the ROI
    MOTOR.mov(motorSettings, "X", -windowX/2);
    if (i%2==0)
    {
        MOTOR.mov(motorSettings, "Y", -windowY/2);
    }
    else
    {
        MOTOR.mov(motorSettings, "Y", windowY/2);
    }
    MOTOR.closeMotor();
    SCOPE.closeScope();
}

void bsc::getDataFromScope(int k)
{
    // Setup scan
        qFilename = savePath + QString("//%1.dat").arg(k) ;
        std::string filename = qFilename.toUtf8().constData();
        SCOPE.getScopeData(filename.c_str(), scopeSettings);
        ui->statusMsg->setText("saving to: " + qFilename);
}

bsc::~bsc()
{
    delete ui;
}
