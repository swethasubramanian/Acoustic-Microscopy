#include "bsc.h"
#include "ui_bsc.h"
#include <QtGui>
#include <QFileDialog>
#include <QApplication>
#include <iostream>
#include <math.h>



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
    QString parentDir = "C:/Data/";
    ui->dirName->setText(parentDir);

    // Set default experiment name (timestamp)
    QString timeStamp = QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss");
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
    ui->waterTemperature->setText("23");
    ui->cSample->setText("1540");

    ui->planar->setChecked(true);
    //connect(ACQ, SIGNAL(error(QString)), ui->statusMsg, SLOT(ui->setText(errorString(QString))));
    connect(ui->acquireData, SIGNAL(clicked()), this, SLOT(startAcquisition()));
    connect(ui->moveMotor, SIGNAL(clicked()), this, SLOT(movMotor()));
    connect(ui->killMotor, SIGNAL(clicked()), this, SLOT(killMotor()));
    connect(ui->acquireWaveform, SIGNAL(clicked()), this, SLOT(updateWaveform()));
    connect(ui->quitProg, SIGNAL(clicked()), this, SLOT(stopAcquisition()));
    connect(ui->calTimeDelay, SIGNAL(clicked()), this, SLOT(calculateTimeDelay()));
    connect(ui->setTimeDelay, SIGNAL(clicked()), this, SLOT(setTimeDelay()));

    getSOSWater();
}

double bsc::maxVal(const QVector<double> &vect)
{
    const double *data = vect.constData();
    double tmp = data[0];
    for (int i=0; i<vect.length(); i++)
    {
        if (tmp < data[i]) tmp = data[i];
    }
    return tmp;
}

double bsc::minVal(const QVector<double> &vect)
{
    const double *data = vect.data();
    double tmp = data[0];
    for (int i=0; i<vect.length(); i++)
    {
        if (tmp > data[i]) tmp = data[i];
    }
    return tmp;
}

void bsc::calculateTimeDelay(void)
{
    QString tmp;

    tmp = ui->cSample->text();
    double csample = tmp.toDouble();

    tmp = ui->cWater->text();
    double cwater = tmp.toDouble();

    tmp = ui->t_focus->text();
    double tdFocus = tmp.toDouble();

    tmp = ui->t_frontEdge->text();
    double tdSampleFrontEdge = tmp.toDouble();

    double td_window = tdSampleFrontEdge + (tdFocus - tdSampleFrontEdge)*cwater/csample;
    ui->timeDelay->setText(QString::number(td_window));
}

void bsc::setTimeDelay(void)
{
    QString tmp;
    tmp = ui->timeDelay->text();
    double timeDelay = tmp.toDouble();

    SCOPE.initializeScope();
    SCOPE.setTimeDelay(timeDelay);
    SCOPE.closeScope();
    ui->statusMsg->setText("time delay set to");
}

void bsc::getSOSWater(void)
{
    QString tmp = ui->waterTemperature->text();
    double temperature = tmp.toDouble();
    double cwater = 1.402385*pow(10,3) + 5.038813*temperature -
    5.799136*pow(10,-2)*pow(temperature,2) + 3.287156*pow(10,-4)*pow(temperature,3) -
    1.398845*pow(10,-6)*pow(temperature,4) + 2.787860*pow(10,-9)*pow(temperature, 5);
    ui->cWater->setText(QString::number(cwater));
}


void bsc::displayWaveform(const QVector<double> &volts, const QVector<double> &time)
{
    ui->WaveformPlot->addGraph();
    ui->WaveformPlot->graph(0)->setData(time, volts);
    ui->WaveformPlot->xAxis->setLabel("Time (s)");
    ui->WaveformPlot->yAxis->setLabel("Voltage (V)");
    ui->WaveformPlot->xAxis->setRange(minVal(time), maxVal(time));
    ui->WaveformPlot->yAxis->setRange(minVal(volts),maxVal(volts));
    ui->WaveformPlot->replot();

    // get time duration
   // ui->timeDuration->setText(QString("Time Duration (s) = %1").arg((maxVal(time)-minVal(time)));
}

void bsc::startAcquisition(void)
{
    qRegisterMetaType<QVector<double> >("QVector<double>");
    ui->statusMsg->setText("Starting Acquisition...");

    ACQ->moveToThread(thread);
    connect(ACQ, SIGNAL(runIndexChanged()), this, SLOT(getCurrentRun()));
    connect(ACQ, SIGNAL(statusChanged(QString)), ui->statusMsg, SLOT(setText(QString)));
    connect(ACQ, SIGNAL(workRequested()), thread, SLOT(start()));
    connect(ACQ, SIGNAL(finished()), thread, SLOT(quit()), Qt::DirectConnection);
    connect(ACQ,
        SIGNAL(waveformUpdated(QVector<double>, QVector<double>)),
        this,
        SLOT(displayWaveform(QVector<double>, QVector<double>)));
    // setup scan settings
    getParameters();
    if (ui->planar->isChecked())
    {
        connect(thread, SIGNAL(started()), ACQ, SLOT(getPlanarData()));
        QApplication::processEvents();
        ui->statusMsg->setText("Acquiring Planar data...");
        ACQ->requestWork(saveDir(), scopeSettings, motorSettings);
    }
    if (ui->sample->isChecked())
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

void bsc::updateWaveform()
{

    qRegisterMetaType<QVector<double> >("QVector<double>"); // for signals and slots to work with QVector

    ACQ->moveToThread(thread);
    connect(ACQ, SIGNAL(waveformUpdateRequested()), thread, SLOT(start()));
    connect(ACQ, SIGNAL(finished()), thread, SLOT(quit()), Qt::DirectConnection);
    connect(thread, SIGNAL(started()), ACQ, SLOT(acquire()));
    connect(ACQ, SIGNAL(statusChanged(QString)), ui->statusMsg, SLOT(setText(QString)));
    connect(ACQ,
            SIGNAL(waveformUpdated(QVector<double>, QVector<double>)),
            this,
            SLOT(displayWaveform(QVector<double>, QVector<double>)));

    getParameters();
    ACQ->requestWaveformUpdate(scopeSettings);
    //addRandomGraph();

}

bsc::~bsc()
{
    ACQ->stopAcquisition();
    thread->wait();
    delete thread;
    delete ACQ;
    delete ui;
}
