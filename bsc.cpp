#include "bsc.h"
#include "ui_bsc.h"
#include <QtGui>
#include <QFileDialog>
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
    ui->displacement->setText("1");

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

// Moving motor for aligning things
void bsc::movMotor(void)
{
    QString tmp;
    tmp = ui->displacement->text();
    double dist = tmp.toDouble();
    MOTOR.openMotor(motorSettings);
    if (ui->XDir->isChecked())
    {
        Sleep(1000);
        MOTOR.mov(motorSettings, "X", dist);
        ui->statusMsg->setText(QString("Moved in X direction by %1 mm").arg(dist));
    }
    if (ui->YDir->isChecked())
    {
        Sleep(1000);
        MOTOR.mov(motorSettings, "Y", dist);
        ui->statusMsg->setText(QString("Moved in Y direction by %1 mm").arg(dist));
    }
    if (ui->ZDir->isChecked())
    {
        Sleep(1000);
        MOTOR.mov(motorSettings, "Z", dist);
        ui->statusMsg->setText(QString("Moved in Z direction by %1 mm").arg(dist));
    }
    MOTOR.closeMotor();
}

void bsc::killMotor(void)
{
    MOTOR.killMotor();
}

void bsc::getDataFromScope(int k)
{
    // Setup scan
        qFilename = savePath + QString("//%1.dat").arg(k) ;
        std::string filename = qFilename.toUtf8().constData();
        SCOPE.getScopeData(filename.c_str(), scopeSettings);
        ui->statusMsg->setText("saving to: " + qFilename);
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

    // Oscilloscope Settings
    tmp = ui->numOfAverages->text();
    scopeSettings.numOfAverages = tmp.toInt();
    tmp = ui->numOfPoints->text();
    scopeSettings.numOfPoints = tmp.toInt();
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
    if (i%2==0) MOTOR.mov(motorSettings, "Y", -windowY/2);
    else MOTOR.mov(motorSettings, "Y", windowY/2);
    MOTOR.closeMotor();
    SCOPE.closeScope();
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

bsc::~bsc()
{
    delete ui;
}
