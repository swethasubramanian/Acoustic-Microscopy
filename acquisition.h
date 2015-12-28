#ifndef ACQUISITION_H
#define ACQUISITION_H
#include <QObject>

#include "motor.h"
#include "scope.h"
//#include "bsc.h"
#include "settingsMotorScope.h"
class bsc; // forward declaration
class acquisition : public QObject
{
    Q_OBJECT
    public:
        explicit acquisition(QObject *parent = 0);
        void getDataFromScope(int value);
        void stopAcquisition();
        void requestWork(const QString &, const struct SCOPESETTINGS&, const struct MOTORSETTINGS&);
        void requestWaveformUpdate(const struct SCOPESETTINGS&);
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
        QMutex mutex;
        int Nx, Ny;
        QString savePath, qFilename;
        int index=0;
        QString saveDir;

    public slots:
        void getPlanarData();
        void getSampleData();
        void acquire();

    signals:
        void workRequested();
        void waveformUpdateRequested();
        void runIndexChanged();
        void finished();
        void statusChanged(const QString &status);
        void waveformUpdated(const QVector<double> &, const QVector<double> &);
        void somethingHappened();
};
#endif // ACQUISTION_H
