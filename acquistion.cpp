#include "acquistion.h"
#include "motor.h"
#include "scope.h"
#include "settingsMotorScope.h"
#include <QtGui>

acquistion::acquistion(QObject *parent):
    QObject(parent)
{
    //QObject::connect(acquistion, SIGNAL(acquireScopeData(int)), acquistion, SLOT(getDataFromScope(int)));
}



void acquistion::setMotorSettings(const MOTORSETTINGS& motorSettings)
{
    Nx = motorSettings.windowSizeX/motorSettings.stepSizeX;
    Ny = motorSettings.windowSizeY/motorSettings.stepSizeY;
}

void acquistion::setScopeSettings(const SCOPESETTINGS& scopeSettings)
{
    //
}

void acquistion::getPlanarData(QString saveDir, const SCOPESETTINGS& scopeSettings)
{
    //qDebug("saveDir");
    // Create a directory for saving planar data
    savePath = saveDir+"/Planar";
    QDir dir(savePath);
    if(!dir.exists()) dir.mkpath(".");

    //Set up scan
//    SCOPE.initializeScope(scopeSettings);
//    for (int k=1; k<Nx*Ny; k++)
//    {
//        getDataFromScope(k);
//    }
//    //ui->statusMsg->setText(QString("Done! %1").arg(Nx*Ny));
//    SCOPE.closeScope();
    emit finished();
}



void acquistion::getSampleData(QString saveDir)
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

    // move motor to bottom left of the ROI (from computer perspective) and get scope data
    MOTOR.mov(motorSettings, "X", -windowX/2); //(minus is left)
    MOTOR.mov(motorSettings, "Y", windowY/2); //(minus is up)
    int k=1;
    int i,j;
    getDataFromScope(k);

    for (int i=0; i<=Nx; i++)
    {
        if (i>0)
        {
            MOTOR.mov(motorSettings, "X", stepXmm);
            k++;
            getDataFromScope(k);
        }
        if (i%2 == 0)
        {
            for (j=0; j<=Ny; j++)
            {
                if (j>0)
                {
                    MOTOR.mov(motorSettings, "Y", -stepYmm);
                    k++;
                    getDataFromScope(k);
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
                    getDataFromScope(k);
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
    emit finished();
   // stopAcquistion();

}

void acquistion::getDataFromScope(int k)
{
    //if (!abort) stopAcquistion();
  //  QApplication::processEvents();
    qFilename = savePath + QString("//%1.dat").arg(k) ;
    std::string filename = qFilename.toUtf8().constData();
    SCOPE.getScopeData(filename.c_str(), scopeSettings);
//    ui->statusMsg->setText("saving to: " + qFilename);
}

void acquistion::stopAcquistion(void)
{
    //ui->statusMsg->setText("Ready!");
}

acquistion::~acquistion()
{
    //
}
