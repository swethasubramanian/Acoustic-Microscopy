#include "bsc.h"
#include "ui_bsc.h"
#include <QtGui>
#include <QFileDialog>
#include <QApplication>
#include <iostream>



bsc::bsc(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::bsc)
{
    ui->setupUi(this);
    abort = false;

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
    //connect(ACQ, SIGNAL(error(QString)), ui->statusMsg, SLOT(ui->setText(errorString(QString))));
    connect(ui->acquireData, SIGNAL(clicked()), this, SLOT(startAcquistion()));
    connect(ui->moveMotor, SIGNAL(clicked()), this, SLOT(movMotor()));
    connect(ui->killMotor, SIGNAL(clicked()), this, SLOT(killMotor()));
    connect(ui->quitProg, SIGNAL(clicked()), this, SLOT(stopAcquistion()));
    //ui->statusMsg->setText(QString("ideal thread count is %1").arg(QThread::idealThreadCount()));
}

void bsc::startAcquistion(void)
{
    QThread *thread;
    acquistion *ACQ;

    ui->statusMsg->setText("Starting Acquistion...");

    thread = new QThread;
    ACQ = new acquistion();
    ACQ->moveToThread(thread);

    // setup scan settings
    getParameters();
    QString tmp = saveDir();

    connect(this, SIGNAL(planarDataRequested()), ACQ, SLOT(getPlanarData(tmp, scopeSettings)));
    connect(ACQ, SIGNAL(finished()), thread, SLOT(quit()));
    connect(ACQ, SIGNAL(finished()), ACQ, SLOT(deleteLater()));
    connect(ACQ, SIGNAL(finished()), this, SLOT(stopAcquistion()));
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

    if (ui->planar->isChecked())
    {
        ui->statusMsg->setText("Acquiring Planar data...");
        //thread->start();
        ui->statusMsg->setText(QString("Run #: %1").arg(ACQ->runIndex()));
    }
    //if (ui->sample->isChecked())  sampleDataRequested();
}

void bsc::stopAcquistion(void)
{
    abort = true;
    ui->statusMsg->setText("Ready!");
}

// Moving motor for aligning things
void bsc::movMotor(void)
{
    if (abort)
    {
        abort = false;
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
        stopAcquistion();
    }
}

// To kill motor movement
void bsc::killMotor(void)
{
    MOTOR.killMotor();
    MOTOR.closeMotor();
    SCOPE.closeScope();
}

// Set up motor and scope settings
void bsc::getParameters(void)
{
    QString tmp;
    tmp = ui->stepSizeX->text();
    motorSettings.stepSizeX = tmp.toDouble();
    tmp = ui->stepSizeY->text();
    motorSettings.stepSizeY = tmp.toDouble();
    tmp = ui->windowSizeX->text();
    motorSettings.windowSizeX = tmp.toDouble();
    tmp = ui->windowSizeY->text();
    motorSettings.windowSizeY = tmp.toDouble();

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
    //ACQ->stopAcquistion();
    //thread->wait();
    //delete thread;
    //delete ACQ;
    delete ui;
}
