#ifndef MOTOR_H
#define MOTOR_H

#include <windows.h>

class motor
{
    public:
        motor();
        int openMotor(const struct MOTORSETTINGS&);
        int mov(const struct MOTORSETTINGS&, const char* motID);
        void closeMotor(void);
       // initializeMotor(const struct &MOTORSETTINGS);
       // mov(const struct &MOTORSETTINGS);
    private:
        DCB dcb;
        HANDLE hCom;
        BOOL fSuccess;
        char *pcCommPort = "COM1";
        DWORD buffer_size_w;
        char foo[100];
};

#endif // MOTOR_H
