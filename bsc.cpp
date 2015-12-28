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

    ui->planar->setChecked(true);
    //connect(ACQ, SIGNAL(error(QString)), ui->statusMsg, SLOT(ui->setText(errorString(QString))));
    connect(ui->acquireData, SIGNAL(clicked()), this, SLOT(startAcquisition()));
    connect(ui->moveMotor, SIGNAL(clicked()), this, SLOT(movMotor()));
    connect(ui->killMotor, SIGNAL(clicked()), this, SLOT(killMotor()));
    connect(ui->acquireWaveform, SIGNAL(clicked()), this, SLOT(updateWaveform()));
   // connect(ui->killMotor, SIGNAL(clicked()), this, SLOT(killMotor()));
    connect(ui->quitProg, SIGNAL(clicked()), this, SLOT(stopAcquisition()));
   //connect(ACQ, SIGNAL())
    //ui->statusMsg->setText(QString("ideal thread count is %1").arg(QThread::idealThreadCount()));
   // addRandomGraph();
   //updateWaveform();
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


void bsc::addRandomGraph()
{
    int n = 50; // number of points in graph
    double xScale = (rand()/(double)RAND_MAX + 0.5)*2;
    double yScale = (rand()/(double)RAND_MAX + 0.5)*2;
    double xOffset = (rand()/(double)RAND_MAX - 0.5)*4;
    double yOffset = (rand()/(double)RAND_MAX - 0.5)*5;
    double r1 = (rand()/(double)RAND_MAX - 0.5)*2;
    double r2 = (rand()/(double)RAND_MAX - 0.5)*2;
    double r3 = (rand()/(double)RAND_MAX - 0.5)*2;
    double r4 = (rand()/(double)RAND_MAX - 0.5)*2;
    QVector<double> x(n), y(n);
    for (int i=0; i<n; i++)
    {
        x[i] = (i/(double)n-0.5)*10.0*xScale + xOffset;
        y[i] = (qSin(x[i]*r1*5)*qSin(qCos(x[i]*r2)*r4*3)+r3*qCos(qSin(x[i])*r4*2))*yScale + yOffset;
    }

    ui->WaveformPlot->addGraph();
    ui->WaveformPlot->graph()->setName(QString("New graph %1").arg(ui->WaveformPlot->graphCount()-1));
    ui->WaveformPlot->graph()->setData(x, y);
    ui->WaveformPlot->graph()->setLineStyle((QCPGraph::LineStyle)(rand()%5+1));
    if (rand()%100 > 50)
    ui->WaveformPlot->graph()->setScatterStyle(QCPScatterStyle((QCPScatterStyle::ScatterShape)(rand()%14+1)));
    QPen graphPen;
    graphPen.setColor(QColor(rand()%245+10, rand()%245+10, rand()%245+10));
    graphPen.setWidthF(rand()/(double)RAND_MAX*2+1);
    ui->WaveformPlot->graph()->setPen(graphPen);
    ui->WaveformPlot->replot();
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
    qRegisterMetaType<QVector<double> >("QVector<double>");
     // for signals and slots to work with QVector
    ACQ->moveToThread(thread);
    connect(ACQ, SIGNAL(waveformUpdateRequested()), thread, SLOT(start()));
    connect(ACQ, SIGNAL(finished()), thread, SLOT(quit()), Qt::DirectConnection);
    connect(thread, SIGNAL(started()), ACQ, SLOT(acquire()));
    connect(ACQ, SIGNAL(statusChanged(QString)), ui->statusMsg, SLOT(setText(QString)));
    connect(ACQ,
            SIGNAL(waveformUpdated(QVector<double>, QVector<double>)),
            this,
            SLOT(displayWaveform(QVector<double>, QVector<double>)));
   // connect(ACQ, SIGNAL(finished()), ui->statusMsg, SLOT(setText("fuck this!")));
   //connect(ACQ, SIGNAL(finished()), this, SLOT(addRandomGraph()));



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
