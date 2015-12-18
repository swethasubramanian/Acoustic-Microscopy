#ifndef MOTOR_H
#define MOTOR_H

#include <windows.h>
#include <QtGui>

class motor
{
    public:
        motor();
        void openMotor(const struct MOTORSETTINGS&);
        int mov(const struct MOTORSETTINGS&, const char* motID, double dist);
        void closeMotor(void);
        void killMotor(void);
        QString getX(void);
        void setZero(void);
       // initializeMotor(const struct &MOTORSETTINGS);
       // mov(const struct &MOTORSETTINGS);
    private:
        DCB dcb;
        HANDLE hCom;
        BOOL fSuccess;
        char *pcCommPort = "COM1";
        DWORD buffer_size_w, buffer_size_r;
        char foo[100];
};

#endif // MOTOR_H
