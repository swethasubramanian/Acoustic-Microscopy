#include "acquisition.h"
#include "motor.h"
#include "scope.h"
#include "settingsMotorScope.h"
#include <QtGui>
#include "bsc.h"


acquisition::acquisition(QObject *parent):
    QObject(parent)
{
    abort = false;
    acquiring = false;
}

void acquisition::requestWork(const QString &param, const SCOPESETTINGS& scopeSet, const MOTORSETTINGS& motorSet)
{
    mutex.lock();
    acquiring = true;
    abort = false;
    saveDir = param;
    scopeSettings = scopeSet;
    motorSettings = motorSet;
    Nx = motorSettings.windowSizeX/motorSettings.stepSizeX;
    Ny = motorSettings.windowSizeY/motorSettings.stepSizeY;
    mutex.unlock();
    emit workRequested();
}

void acquisition::requestWaveformUpdate(const SCOPESETTINGS& scopeSet)
{
    mutex.lock();
    acquiring = true;
    abort = false;
    scopeSettings = scopeSet;
    mutex.unlock();
    emit waveformUpdateRequested();
}

void acquisition::getPlanarData()
{
    // Create a directory for saving planar data
   savePath = saveDir+"/Planar";
   QDir dir(savePath);
   if(!dir.exists()) dir.mkpath(".");

    //Set up scan
   SCOPE.initializeScope(scopeSettings);
   for (int k=1; k<=(Nx+1)*(Ny+1); k++)
    {
        // Checks if the process should be aborted
        mutex.lock();
        bool _abort = abort;
        mutex.unlock();
        if (_abort) break;

        // This will stupidly wait 1 sec doing nothing...
        QEventLoop loop;
        QTimer::singleShot(1000, &loop, SLOT(quit()));
        loop.exec();

        QString statusMsg = QString("Acquiring planar data set #%1 ...").arg(k);
        emit statusChanged(statusMsg);

        index = k;
        getDataFromScope(k);

        emit runIndexChanged();
        emit waveformUpdated(SCOPE.getVoltageData(), SCOPE.getTimeData());
    }
   SCOPE.closeScope();

    // Set _working to false, meaning the process can't be aborted anymore.
    mutex.lock();
    acquiring = false;
    mutex.unlock();
    emit finished();
}



void acquisition::getSampleData()
{
    // Create a directory for saving planar data
    savePath = saveDir+"/Sample";
    QDir dir(savePath);
    if(!dir.exists()) dir.mkpath(".");

    // Setup scan
    SCOPE.initializeScope(scopeSettings);
    double windowX = motorSettings.windowSizeX;
    double windowY = motorSettings.windowSizeY;
    double stepXmm = motorSettings.stepSizeX;
    double stepYmm = motorSettings.stepSizeY;
    MOTOR.openMotor(motorSettings);

    // This will stupidly wait 1 sec doing nothing...
    QEventLoop loop;
    QTimer::singleShot(1000, &loop, SLOT(quit()));
    loop.exec();

    // move motor to bottom left of the ROI (from computer perspective) and get scope data
    emit statusChanged("Preparing for take off ...");
    MOTOR.mov(motorSettings, "X", -windowX/2); //(minus is left)
    MOTOR.mov(motorSettings, "Y", windowY/2); //(minus is up)
    int k=1;
    int i,j;
    index = k;
    emit statusChanged(QString("Acquiring sample data set #%1 ...").arg(k));
    getDataFromScope(k);
    emit runIndexChanged();
    emit waveformUpdated(SCOPE.getVoltageData(), SCOPE.getTimeData());

    for (int i=0; i<=Nx; i++)
    {
        // Checks if the process should be aborted
        mutex.lock();
        bool _abort = abort;
        mutex.unlock();
        if (_abort) break;

        // This will stupidly wait 1 sec doing nothing...
        QTimer::singleShot(1000, &loop, SLOT(quit()));
        loop.exec();

        if (i>0)
        {
            MOTOR.mov(motorSettings, "X", stepXmm);
            k++;
            index = k;
            emit statusChanged(QString("Acquiring sample data set #%1 ...").arg(k));
            getDataFromScope(k);
            emit runIndexChanged();
            emit waveformUpdated(SCOPE.getVoltageData(), SCOPE.getTimeData());
        }
        if (i%2 == 0)
        {
            for (j=0; j<=Ny; j++)
            {
                // Checks if the process should be aborted
                mutex.lock();
                bool _abort = abort;
                mutex.unlock();
                if (_abort) break;

                // This will stupidly wait 1 sec doing nothing...
                QTimer::singleShot(1000, &loop, SLOT(quit()));
                loop.exec();

                if (j>0)
                {
                    MOTOR.mov(motorSettings, "Y", -stepYmm);
                    k++;
                    index = k;
                    emit statusChanged(QString("Acquiring sample data set #%1 ...").arg(k));
                    getDataFromScope(k);
                    emit runIndexChanged();
                    emit waveformUpdated(SCOPE.getVoltageData(), SCOPE.getTimeData());
                }
            }
            if (_abort) break;
        }
        if (i%2==1)
        {
            for (j=0; j<=Ny; j++)
            {
                // Checks if the process should be aborted
                mutex.lock();
                bool _abort = abort;
                mutex.unlock();
                if (_abort) break;

                // This will stupidly wait 1 sec doing nothing...
                QTimer::singleShot(1000, &loop, SLOT(quit()));
                loop.exec();

                if (j>0)
                {
                    MOTOR.mov(motorSettings, "Y", stepYmm);
                    k++;
                    index = k;
                    emit statusChanged(QString("Acquiring sample data set #%1 ...").arg(k));
                    getDataFromScope(k);
                    emit runIndexChanged();
                    emit waveformUpdated(SCOPE.getVoltageData(), SCOPE.getTimeData());
                }
            }
            if (_abort) break;
        }
        if (_abort) break;
    }
    Sleep(1000);
    emit statusChanged("Data acquisition complete. Moving back to center of ROI ...");
    // Move motor back to center of the ROI
    MOTOR.mov(motorSettings, "X", -windowX/2);
    // This will stupidly wait 1 sec doing nothing...
    Sleep(1000);
    if ((Ny+1)%2==0)
    {
        MOTOR.mov(motorSettings, "Y", -windowY/2);
    }
    else
    {
        MOTOR.mov(motorSettings, "Y", windowY/2);
    }
    MOTOR.closeMotor();
    SCOPE.closeScope();
    // Set acquiring to false, meaning the process can't be aborted anymore.
    mutex.lock();
    acquiring = false;
    mutex.unlock();
    emit statusChanged("Done!");

    emit finished();
}

void acquisition::getDataFromScope(int k)
{

    // This will stupidly wait 1 sec doing nothing...
    QEventLoop loop;
    QTimer::singleShot(1000, &loop, SLOT(quit()));
    loop.exec();

    qFilename = savePath + QString("//%1.dat").arg(k) ;
    std::string filename = qFilename.toUtf8().constData();
    SCOPE.getScopeData(filename.c_str(), scopeSettings);
   // emit waveformUpdated(SCOPE.getVoltageData(), SCOPE.getTimeData());
}

void acquisition::acquire()
{
    // This will stupidly wait 1 sec doing nothing...
    QEventLoop loop;
    QTimer::singleShot(1000, &loop, SLOT(quit()));
    loop.exec();
    std :: string filename = "tmp.dat";
    SCOPE.initializeScope(scopeSettings);
    SCOPE.getScopeData(filename.c_str(), scopeSettings);
    emit statusChanged("got data!");
    emit waveformUpdated(SCOPE.getVoltageData(), SCOPE.getTimeData());
    SCOPE.closeScope();
    emit finished();


}

void acquisition::stopAcquisition(void)
{
    mutex.lock();
    if (acquiring) abort = true;
    mutex.unlock();
}

int acquisition::runIndex(void)
{
    return index;
}

