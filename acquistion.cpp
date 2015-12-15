#include "acquistion.h"
#include "motor.h"
#include "scope.h"
#include "settingsMotorScope.h"
#include <QtGui>
#include "bsc.h"


acquistion::acquistion(QObject *parent):
    QObject(parent)
{
    abort = false;
    acquiring = false;
}

void acquistion::requestWork(const QString &param, const SCOPESETTINGS& scopeSet, const MOTORSETTINGS& motorSet)
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

void acquistion::getPlanarData()
{
    // Create a directory for saving planar data
   savePath = saveDir+"/Planar";
   QDir dir(savePath);
   if(!dir.exists()) dir.mkpath(".");

    //Set up scan
   SCOPE.initializeScope(scopeSettings);
   for (int k=1; k<Nx*Ny; k++)
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

        index = k;
        getDataFromScope(k);

        emit runIndexChanged();
    }
   SCOPE.closeScope();

    // Set _working to false, meaning the process can't be aborted anymore.
    mutex.lock();
    acquiring = false;
    mutex.unlock();
    emit finished();
}



void acquistion::getSampleData()
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
    MOTOR.mov(motorSettings, "X", -windowX/2); //(minus is left)
    MOTOR.mov(motorSettings, "Y", windowY/2); //(minus is up)
    int k=1;
    int i,j;
    getDataFromScope(k);

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
            getDataFromScope(k);
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
                    getDataFromScope(k);
                }
            }
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
                    getDataFromScope(k);
                }
            }
        }
    }
    // This will stupidly wait 1 sec doing nothing...
    QTimer::singleShot(1000, &loop, SLOT(quit()));
    loop.exec();

    // Move motor back to center of the ROI
    MOTOR.mov(motorSettings, "X", -windowX/2);
    if (i%2==0) MOTOR.mov(motorSettings, "Y", -windowY/2);
    if (i%2==1) MOTOR.mov(motorSettings, "Y", windowY/2);
    MOTOR.closeMotor();
    SCOPE.closeScope();
    // Set acquiring to false, meaning the process can't be aborted anymore.
    mutex.lock();
    acquiring = false;
    mutex.unlock();
    emit finished();
}

void acquistion::getDataFromScope(int k)
{

    // This will stupidly wait 1 sec doing nothing...
    QEventLoop loop;
    QTimer::singleShot(1000, &loop, SLOT(quit()));
    loop.exec();

    qFilename = savePath + QString("//%1.dat").arg(k) ;
    std::string filename = qFilename.toUtf8().constData();
    SCOPE.getScopeData(filename.c_str(), scopeSettings);
}

void acquistion::stopAcquistion(void)
{
    mutex.lock();
    if (acquiring) abort = true;
    mutex.unlock();
}

int acquistion::runIndex(void)
{
    return index;
}

