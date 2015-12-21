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
    //abort = false;

    // The thread and the worker are created in the constructor so it is always safe to delete them.
    thread = new QThread();
    ACQ = new acquisition();

    // Load up defaults here
    // Default parent directory
    QString parentDir = "C:/Documents and Settings/wetlab/My Documents/MATLAB/Data/";
    ui->dirName->setText(parentDir);

    // Set default experiment name (timestamp)
    QString timeStamp = QDateTime::currentDateTime().toString("MMddyyyy_hhmmss");
    ui->expName->setText(timeStamp);

    // Setting default motor and ocilloscope settings
    ui->stepSizeX->setText("2");
    ui->stepSizeY->setText("2");
    ui->windowSizeX->setText("18");
    ui->windowSizeY->setText("18");
    ui->numOfAverages->setText("2048");
    ui->numOfPoints->setText("1000");
    ui->displacement->setText("1");
    ui->motorSpeed->setText("1.25");

    ui->planar->setChecked(true);
    //connect(ACQ, SIGNAL(error(QString)), ui->statusMsg, SLOT(ui->setText(errorString(QString))));
    connect(ui->acquireData, SIGNAL(clicked()), this, SLOT(startAcquisition()));
    connect(ui->moveMotor, SIGNAL(clicked()), this, SLOT(movMotor()));
    connect(ui->killMotor, SIGNAL(clicked()), this, SLOT(killMotor()));
   // connect(ui->killMotor, SIGNAL(clicked()), this, SLOT(killMotor()));
    connect(ui->quitProg, SIGNAL(clicked()), this, SLOT(stopAcquisition()));

    //ui->statusMsg->setText(QString("ideal thread count is %1").arg(QThread::idealThreadCount()));
}

void bsc::startAcquisition(void)
{
    ui->statusMsg->setText("Starting Acquisition...");
    ACQ->moveToThread(thread);
    connect(ACQ, SIGNAL(runIndexChanged()), this, SLOT(getCurrentRun()));
    connect(ACQ, SIGNAL(statusChanged(QString)), ui->statusMsg, SLOT(setText(QString)));
    connect(ACQ, SIGNAL(workRequested()), thread, SLOT(start()));
    connect(ACQ, SIGNAL(finished()), thread, SLOT(quit()), Qt::DirectConnection);
    // setup scan settings
    getParameters();
    if (ui->planar->isChecked())
    {
        connect(thread, SIGNAL(started()), ACQ, SLOT(getPlanarData()));
        QApplication::processEvents();
        ui->statusMsg->setText("Acquiring Planar data...");
        ACQ->requestWork(saveDir(), scopeSettings, motorSettings);
    }
    else if (ui->sample->isChecked())
    {
        connect(thread, SIGNAL(started()), ACQ, SLOT(getSampleData()));
        QApplication::processEvents();
        ui->statusMsg->setText("Acquiring Sample data...");
        ACQ->requestWork(saveDir(), scopeSettings, motorSettings);
    }
}

void bsc::getCurrentRun()
{
    ui->statusMsg->setText("Saved to:" + ACQ->getSaveDir() + QString("//%1.dat").arg(ACQ->runIndex()));
}



void bsc::stopAcquisition(void)
{
    abort = true;
    thread->quit();
    ACQ->stopAcquisition();
    thread->wait();
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
        stopAcquisition();
    }
}

// To kill motor movement
void bsc::killMotor(void)
{
    abort = true;
    thread->quit();
    ACQ->stopAcquisition();
    thread->wait();
    ui->statusMsg->setText("Ready!");
}

// Set up motor and scope settings
void bsc::getParameters(void)
{
    QString tmp;
    double motorVel;
    tmp = ui->stepSizeX->text();
    motorSettings.stepSizeX = tmp.toDouble();
    tmp = ui->stepSizeY->text();
    motorSettings.stepSizeY = tmp.toDouble();
    tmp = ui->windowSizeX->text();
    motorSettings.windowSizeX = tmp.toDouble();
    tmp = ui->windowSizeY->text();
    motorSettings.windowSizeY = tmp.toDouble();
    tmp = ui->motorSpeed->text();
    motorVel = tmp.toDouble(); // mm/s
    // convert mm/s to steps/2sec
    motorSettings.velX = (int) motorSettings.pitch*motorVel*2;
    motorSettings.velY = (int) motorSettings.pitch*motorVel*2;
    motorSettings.velZ = (int) motorSettings.pitch*motorVel*2;

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
    ACQ->stopAcquisition();
    thread->wait();
    delete thread;
    delete ACQ;
    delete ui;
}
