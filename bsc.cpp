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

    // The acq thread and the worker are created in the constructor so it is always safe to delete them.
    planarThread = new QThread();
    ACQp = new acquisition();
    sampleThread = new QThread();
    ACQs = new acquisition();

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
    ui->displacement->setText("1");
    ui->waterTemperature->setText("23");
    ui->cSample->setText("1540");



    ui->planar->setChecked(true);


    QApplication::processEvents();
    //connect(ACQ, SIGNAL(error(QString)), ui->statusMsg, SLOT(ui->setText(errorString(QString))));
    connect(ui->acquireData, SIGNAL(clicked()), this, SLOT(startAcquisition()));
    connect(ui->moveMotor, SIGNAL(clicked()), this, SLOT(movMotor()));
    connect(ui->acquireWaveform, SIGNAL(clicked()), this, SLOT(updateWaveform()));
    connect(ui->quitProg, SIGNAL(clicked()), this, SLOT(stopAcquisition()));
    connect(ui->calTimeDelay, SIGNAL(clicked()), this, SLOT(calculateTimeDelay()));
    connect(ui->setTimeDelay, SIGNAL(clicked()), this, SLOT(setTimeDelay()));

    getSOSWater();
}

void bsc::calculateTimeDelay(void)
{
    getSOSWater();
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
    SCOPE.setTimeDelay(-timeDelay);
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
    QApplication::processEvents();
    qRegisterMetaType<QVector<double> >("QVector<double>");
    ui->statusMsg->setText("Starting Acquisition...");

    // setup scan settings
    getParameters();
    if (ui->planar->isChecked())
    {
        //QThread* planarThread = new QThread;
        //acquisition* ACQp = new acquisition();

        ACQp->moveToThread(planarThread);
        connect(ACQp, SIGNAL(workRequested()), planarThread, SLOT(start()));
        connect(ACQp, SIGNAL(finished()), planarThread, SLOT(quit()), Qt::DirectConnection);
        connect(ACQp, SIGNAL(runIndexChanged()), this, SLOT(getCurrentRun()));
        connect(ACQp, SIGNAL(statusChanged(QString)), ui->statusMsg, SLOT(setText(QString)));
        connect(ACQp,
            SIGNAL(waveformUpdated(QVector<double>, QVector<double>)),
            this,
            SLOT(displayWaveform(QVector<double>, QVector<double>)));
        connect(planarThread, SIGNAL(started()), ACQp, SLOT(getPlanarData()));
       // connect(ui->quitProg, SIGNAL(clicked()), ACQp, SLOT(stopAcquisition()));
        //connect(ACQp, SIGNAL(finished()), ACQp, SLOT (deleteLater()));
        //connect(planarThread, SIGNAL (finished()), planarThread, SLOT (deleteLater()));

        ui->statusMsg->setText("Acquiring Planar data...");
        QCoreApplication::processEvents();
        ACQp->requestWork(saveDir(), scopeSettings, motorSettings);
    }
    else if (ui->sample->isChecked())
    {
      //  QThread* sampleThread = new QThread;
       // acquisition* ACQs = new acquisition();

        ACQs->moveToThread(sampleThread);
        connect(ACQs, SIGNAL(workRequested()), sampleThread, SLOT(start()));
        connect(ACQs, SIGNAL(finished()), sampleThread, SLOT(quit()), Qt::DirectConnection);
        connect(ACQs, SIGNAL(runIndexChanged()), this, SLOT(getCurrentRun()));
        connect(ACQs, SIGNAL(statusChanged(QString)), ui->statusMsg, SLOT(setText(QString)));
        connect(ACQs,
            SIGNAL(waveformUpdated(QVector<double>, QVector<double>)),
            this,
            SLOT(displayWaveform(QVector<double>, QVector<double>)));

        connect(sampleThread, SIGNAL(started()), ACQs, SLOT(getSampleData()));
       // connect(ui->quitProg, SIGNAL(clicked()), ACQs, SLOT(stopAcquisition()));
        //connect(ACQs, SIGNAL(finished()), ACQs, SLOT (deleteLater()));
        //connect(sampleThread, SIGNAL (finished()), sampleThread, SLOT (deleteLater()));

        ui->statusMsg->setText("Acquiring Sample data...");
        QCoreApplication::processEvents();
        ACQs->requestWork(saveDir(), scopeSettings, motorSettings);
    }
}

void bsc::getCurrentRun()
{
    if (ui-> planar->isChecked())
        ui->statusMsg->setText("Saved to:" + ACQp->getSaveDir() + QString("//%1.dat").arg(ACQp->runIndex()));
    else
        ui->statusMsg->setText("Saved to:" + ACQs->getSaveDir() + QString("//%1.dat").arg(ACQs->runIndex()));
}

void bsc::stopAcquisition(void)
{
    abort = true;
    if(ui->planar->isChecked())
    {
        planarThread->quit();
        ACQp->stopAcquisition();
        planarThread->wait();
        ui->statusMsg->setText("Ready!");
        return;
    }
    else if (ui->sample->isChecked())
    {
        sampleThread->quit();
        ACQs->stopAcquisition();
        sampleThread->wait();
        ui->statusMsg->setText("Ready!");
        return;
    }
}

/*void bsc::movMotor(void)
{
    acquisition* ACQ2 = new acquisition();
    ACQ2->moveMotor();
}*/


// Moving motor for aligning things
void bsc::movMotor(void)
{
    QString tmp;
    tmp = ui->displacement->text();
    double dist = tmp.toDouble();

    QThread* motorCtrlThread = new QThread;
    acquisition* ACQ2 = new acquisition();

    getParameters();
    ACQ2->moveToThread(motorCtrlThread);
    connect(ACQ2, SIGNAL(motorMovementRequested()), motorCtrlThread, SLOT(start()));
    connect(ACQ2, SIGNAL(finished()), motorCtrlThread, SLOT(quit()), Qt::DirectConnection);
    connect(motorCtrlThread, SIGNAL(started()), ACQ2, SLOT(moveMotor()));
    connect(ACQ2, SIGNAL(statusChanged(QString)), ui->statusMsg, SLOT(setText(QString)));
    connect(ACQ2, SIGNAL (finished()), ACQ2, SLOT (deleteLater()));
    connect(motorCtrlThread, SIGNAL (finished()), motorCtrlThread, SLOT (deleteLater()));


    if (ui->XDir->isChecked())
    {
        ACQ2->requestMotorMovement("X", dist, motorSettings);
        //ui->statusMsg->setText(QString("Moved in X direction by %1 mm").arg(dist));
        return;
    }
    if (ui->YDir->isChecked())
    {
        ACQ2->requestMotorMovement("Y", dist, motorSettings);
       // ui->statusMsg->setText(QString("Moved in Y direction by %1 mm").arg(dist));
        return;
    }
    if (ui->ZDir->isChecked())
    {
        ACQ2->requestMotorMovement("Z", dist, motorSettings);
       // ui->statusMsg->setText(QString("Moved in Z direction by %1 mm").arg(dist));
        return;
    }
}



// To kill motor movement
void bsc::killMotor(void)
{
   // abort = true;
   // thread->quit();
    //ACQ->stopAcquisition();
    //thread->wait();
    //ui->statusMsg->setText("Ready!");
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
    tmp = ui->stepSizeZ->text();
    motorSettings.stepSizeZ = tmp.toDouble();
    tmp = ui->windowSizeX->text();
    motorSettings.windowSizeX = tmp.toDouble();
    tmp = ui->windowSizeY->text();
    motorSettings.windowSizeY = tmp.toDouble();
    tmp = ui->windowSizeZ->text();
    motorSettings.windowSizeZ = tmp.toDouble();
}

void bsc::getParentDir()
{
   //
    QString parentDirName = QFileDialog::getExistingDirectory(this, tr("Select Experiment Directory"),
                 "C:/Data/",
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

    QThread* waveformUpdateThread = new QThread;
    acquisition* ACQ1 = new acquisition();

    ACQ1->moveToThread(waveformUpdateThread);
    connect(ACQ1, SIGNAL(waveformUpdateRequested()), waveformUpdateThread, SLOT(start()));
    connect(ACQ1, SIGNAL(finished()), waveformUpdateThread, SLOT(quit()), Qt::DirectConnection);
    connect(waveformUpdateThread, SIGNAL(started()), ACQ1, SLOT(acquire()));
    connect(ACQ1, SIGNAL (finished()), ACQ1, SLOT (deleteLater()));
    connect(waveformUpdateThread, SIGNAL (finished()), waveformUpdateThread, SLOT (deleteLater()));
    connect(ACQ1, SIGNAL(statusChanged(QString)), ui->statusMsg, SLOT(setText(QString)));
    connect(ACQ1,
            SIGNAL(waveformUpdated(QVector<double>, QVector<double>)),
            this,
            SLOT(displayWaveform(QVector<double>, QVector<double>)));

    getParameters();
    ACQ1->requestWaveformUpdate(scopeSettings);
    //addRandomGraph();
}

bsc::~bsc()
{
    ACQp->stopAcquisition();
    planarThread->wait();
    ACQs->stopAcquisition();
    sampleThread->wait();
    delete planarThread, sampleThread;
    delete ACQp, ACQs;
    delete ui;
}
