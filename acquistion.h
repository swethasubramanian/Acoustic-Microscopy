#ifndef ACQUISTION_H
#define ACQUISTION_H
#include <QObject>

#include "motor.h"
#include "scope.h"
//#include "bsc.h"
#include "settingsMotorScope.h"
class bsc; // forward declaration
class acquistion : public QObject
{
    Q_OBJECT
    public:
        explicit acquistion(QObject *parent = 0);
        void getDataFromScope(int value);
        void stopAcquistion();
        void requestWork(const QString &, const struct SCOPESETTINGS&, const struct MOTORSETTINGS&);
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

    signals:
        void workRequested();
        void runIndexChanged();
        void finished();
        void statusChanged(const QString &status);
};

#endif // ACQUISTION_H
