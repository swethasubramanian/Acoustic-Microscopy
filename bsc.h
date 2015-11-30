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
    void scanSettings();
    ~bsc();

private:
    Ui::bsc *ui;
    MOTORSETTINGS motorSettings;
    SCOPESETTINGS scopeSettings;

public slots:
    QString getParentDir();
};

#endif // BSC_H

