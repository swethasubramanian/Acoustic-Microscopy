#ifndef BSC_H
#define BSC_H


#include <QMainWindow>
#include "settingsMotorScope.h"
#include "scope.h"
namespace Ui {
class bsc;
}

class bsc : public QMainWindow
{
   Q_OBJECT

public:
    explicit bsc(QWidget *parent = 0);
    void getPlanar(int i);
    QString savePath;
    QString qFilename;
    scope SCOPE;
    ~bsc();

private:
    Ui::bsc *ui;
    MOTORSETTINGS motorSettings;
    SCOPESETTINGS scopeSettings;
    int Nx;
    int Ny;

public slots:
    void acquire();
    void getParentDir();
    void getParameters();
    void getSampleData();
    void getData(int value);
    QString saveDir();

signals:
    void acquireScopeData(int newValue);
};

#endif // BSC_H

