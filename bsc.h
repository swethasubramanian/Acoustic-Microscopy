#ifndef BSC_H
#define BSC_H


#include <QMainWindow>
#include "settingsMotorScope.h"
#include "scope.h"
#include "motor.h"
namespace Ui {
class bsc;
}

class bsc : public QMainWindow
{
   Q_OBJECT

public:
    explicit bsc(QWidget *parent = 0);
    void getPlanarData();
    void getSampleData();
    QString saveDir();
    QString savePath;
    QString qFilename;
    scope SCOPE;
    motor MOTOR;
    double Nx, Ny;

    ~bsc();

private:
    Ui::bsc *ui;
    MOTORSETTINGS motorSettings;
    SCOPESETTINGS scopeSettings;
    bool abort;

public slots:
    void acquire();
    void getParentDir();
    void getParameters();
    void getDataFromScope(int value);
    void movMotor();
    void killMotor();

signals:
    void acquireScopeData(int newValue);
};

#endif // BSC_H

