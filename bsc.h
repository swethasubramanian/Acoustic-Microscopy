#ifndef BSC_H
#define BSC_H


#include <QMainWindow>
#include "settingsMotorScope.h"
namespace Ui {
class bsc;
}

class bsc : public QMainWindow
{
   Q_OBJECT

public:
    explicit bsc(QWidget *parent = 0);
    ~bsc();

private:
    Ui::bsc *ui;
    MOTORSETTINGS motorSettings;
    SCOPESETTINGS scopeSettings;

public slots:
    void acquireData();
    void getParentDir();
    void scanSettings();
    void getSampleData();
    void getPlanarData();
    QString saveDir();
};

#endif // BSC_H

