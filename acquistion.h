#ifndef ACQUISTION_H
#define ACQUISTION_H

#include <QObject>


#include "motor.h"
#include "scope.h"
#include "settingsMotorScope.h"

class acquistion : public QObject
{
    Q_OBJECT
    public:
        explicit acquistion(QObject *parent = 0);
        void setMotorSettings(const struct MOTORSETTINGS&);
        void setScopeSettings(const struct SCOPESETTINGS&);
        void getDataFromScope(int value);
        void stopAcquistion();
        int runIndex()
        {
            return index;
        }
        ~acquistion();

    protected:
    private:
        motor MOTOR;
        scope SCOPE;
        MOTORSETTINGS motorSettings;
        SCOPESETTINGS scopeSettings;
        bool abort;
        int Nx, Ny;
        QString savePath, qFilename;
        int index=0;

    public slots:
        void getPlanarData(QString savedir, const struct SCOPESETTINGS&);
        void getSampleData(QString savedir);

    signals:
        void finished();
        //void error(QString err);
};

#endif // ACQUISTION_H
