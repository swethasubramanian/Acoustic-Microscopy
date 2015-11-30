#include "bsc.h"
#include "ui_bsc.h"
#include <QtGui>
#include <QFileDialog>

#include "settingsMotorScope.h"

bsc::bsc(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::bsc)
{
    ui->setupUi(this);
    scanSettings();
}

// For settings adjustments look here!!
void bsc::scanSettings(void)
{
        //Initialize variables to pull in settings
//    char dataDir[100], expName[100], expType[100];
//    MOTORSETTINGS   motorSettings;
//    //SCOPESETTINGS   scopeSettings;
//    char motorID[1];
//
//    // sptr = &scopeSettings;
//    char foo[1000];
//
//    std::string dirLevel = std::string(dataDir) + std::string(expName) + "\\" ;
//    CreateDirectory(dirLevel.c_str(), NULL);
//    dirLevel = dirLevel + std::string(expType);
//    CreateDirectory(dirLevel.c_str(), NULL);
//
//    FILE * settingsFile;
//    settingsFile = fopen("settings.txt", "r");
//
//    // Read in file storage settings
//    fgets(foo, 10000, settingsFile);
//    sscanf(foo, "dataDir = %[^\n]s\n", dataDir);
//    fgets(foo, 10000, settingsFile);
//    sscanf(foo, "expName = %s\n", expName);
//    fgets(foo, 10000, settingsFile);
//    sscanf(foo, "expType = %s\n", expType);
//
//    fclose(settingsFile);
//


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

    // Set File name settings here
    // Defaults
    QString parentDir = "C:/Documents and Settings/wetlab/My Documents/MATLAB/Data/";
    ui->dirName->setText(parentDir);

    connect(ui->getDirName, SIGNAL(clicked()), this, SLOT(getParentDir()));
}



QString bsc::getParentDir()
{
   //
    QString parentDirName = QFileDialog::getExistingDirectory(this, tr("Select Experiment Directory"),
                 "C:/Documents and Settings/wetlab/My Documents/MATLAB/Data/",
                 QFileDialog::ShowDirsOnly);
    ui->dirName->setText(parentDirName);
    return parentDirName;
}


bsc::~bsc()
{
    delete ui;
}
