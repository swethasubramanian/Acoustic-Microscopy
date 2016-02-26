#ifndef ACQUISITION_H
#define ACQUISITION_H
#include <QObject>
#include <QMutex>

#include "motor.h"
#include "scope.h"
//#include "bsc.h"
#include "settingsMotorScope.h"
class bsc;
class acquisition : public QObject
{
    Q_OBJECT
    public:
        explicit acquisition(QObject *parent = 0);
        void getDataFromScope(int value);
        void stopAcquisition();
        void requestWork(const QString &, const struct SCOPESETTINGS&, const struct MOTORSETTINGS&);
        void requestWaveformUpdate(const struct SCOPESETTINGS&);
        void requestMotorMovement(const QString &, double d, const struct MOTORSETTINGS&);
        QString getSaveDir()
        {
            return saveDir;
        }
        int runIndex();
        void finishIt()
        {
            mutex.lock();
            if (acquiring) abort = true;
            mutex.unlock();
            emit finished();
        }

    protected:
    private:
        motor MOTOR;
        scope SCOPE;
        MOTORSETTINGS motorSettings;
        SCOPESETTINGS scopeSettings;
        bool abort;
        bool acquiring;
        bool connected;
        QMutex mutex;
        int Nx, Ny, Nz;
        QString savePath, qFilename;
        int index=0;
        QString saveDir;
        double dist;
        QString motorID;

    public slots:
        void getPlanarData();
        void getSampleData();
        void get3DData();
        void acquire();
        void moveMotor();

    signals:
        void workRequested();
        void waveformUpdateRequested();
        void runIndexChanged();
        void finished();
        void statusChanged(const QString &status);
        void connectionStatusChanged(const QString &status);
        void waveformUpdated(const QVector<double> &, const QVector<double> &);
        void somethingHappened();
        void motorMovementRequested();
};
#endif // ACQUISTION_H
