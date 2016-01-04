#ifndef SCOPE_H
#define SCOPE_H

#include <QVector>

class scope
{
    public:
        scope();
        void closeScope();
        void initializeScope();
        void getScopeData(const char* x, const struct SCOPESETTINGS&);
       // int getNumOfPoints(const struct SCOPESETTINGS&){return &SCOPESETTINGS.numOfPoints;}
        QVector<double> getVoltageData(){return volts;}
        QVector<double> getTimeData(){return time;}
        void setTimeDelay(double value);

    private:
        QVector<double> volts;
        QVector<double> time;
};

#endif // SCOPE_H
