#ifndef BSC_H
#define BSC_H

#include <QMainWindow>
#include "settingsMotorScope.h"
#include "scope.h"
#include "motor.h"
#include "acquisition.h"

namespace Ui {
class bsc;
}

class bsc : public QMainWindow
{
   Q_OBJECT

public:
    explicit bsc(QWidget *parent = 0);
    void acquire();
    void getParameters();
    QString saveDir();
    QString savePath;
    QString qFilename;
    scope SCOPE;
    motor MOTOR;
    ~bsc();


private:
    Ui::bsc *ui;
    MOTORSETTINGS motorSettings;
    SCOPESETTINGS scopeSettings;
    bool abort;
    QThread *thread;
    acquisition *ACQ;
    bool threadAbort;
    QMutex mutex;
    double maxVal(const QVector<double> &);
    double minVal(const QVector<double> &);

public slots:
    void startAcquisition();
    void getParentDir();
    void movMotor();
    void killMotor();
    void stopAcquisition();
    void getCurrentRun();
    void updateWaveform();
    void displayWaveform(const QVector<double> &, const QVector<double> &);
    void addRandomGraph();


signals:
    void planarDataRequested();//, const struct SCOPESETTINGS&);
    void sampleDataRequested();
   // void finished();
};

#endif // BSC_H

