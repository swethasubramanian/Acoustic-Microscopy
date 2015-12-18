#include "motor.h"
//#include <boost/asio/serial_port.hpp>
#include <windows.h>
#include <stdio.h>
#include <unistd.h>
#include "settingsMotorScope.h"
#include <QtGui>
#include <iostream>


motor::motor()
{
    DCB dcb;
    HANDLE hCom;
    BOOL fSuccess;
    char *pcCommPort = "COM1";
    DWORD buffer_size_w, buffer_size_r;
    char foo[100];
}


void motor::openMotor(const MOTORSETTINGS& motorSettings)
{

    hCom = CreateFile(pcCommPort,
                      GENERIC_READ | GENERIC_WRITE,
                      0,
                      NULL,
                      OPEN_EXISTING,
                      0,
                      NULL);
    // Get communication state
    fSuccess = GetCommState(hCom, &dcb);
    if (!fSuccess)
    {
      // Handle the error.
      printf ("GetCommState failed with error %d.\n", GetLastError());
    }

    // Initialize DCB structure
    dcb.BaudRate = CBR_9600;
    dcb.Parity = EVENPARITY;
    dcb.StopBits = 2;
    dcb.ByteSize = 7;

    // setup communication settings
    fSuccess = SetCommState(hCom, &dcb);


    COMMTIMEOUTS timeouts;
    timeouts.ReadIntervalTimeout = 1;
    timeouts.ReadTotalTimeoutMultiplier = 1;
    timeouts.ReadTotalTimeoutConstant = 1;
    timeouts.WriteTotalTimeoutMultiplier = 1;
    timeouts.WriteTotalTimeoutConstant = 1;
    fSuccess = SetCommTimeouts(hCom, &timeouts);

    if (!fSuccess)
    {
      // Handle the error.
      printf ("SetCommState failed with error %d.\n", GetLastError());
    }
    printf ("Serial port %s successfully reconfigured.\n", pcCommPort);


    // Enables On-line mode with Echo off and sets position to 0
    sprintf(foo, "FN");
    fSuccess = WriteFile(hCom, foo, strlen(foo), &buffer_size_w, 0);
    // Clears off previous commands, otherwise new command will just append to previous command
    sprintf(foo, "C");
    fSuccess = WriteFile(hCom, foo, strlen(foo), &buffer_size_w, 0);
    //Setup velocity in X, Y and Z directions
    sprintf(foo, "C S1M%d,R", motorSettings.velY); // Y dir
    fSuccess = WriteFile(hCom, foo, strlen(foo), &buffer_size_w, 0);
    sprintf(foo, "C S2M%d,R", motorSettings.velX); // X dir
    fSuccess = WriteFile(hCom, foo, strlen(foo), &buffer_size_w, 0);
    sprintf(foo, "C S3M%d,R", motorSettings.velZ); // Z dir
    fSuccess = WriteFile(hCom, foo, strlen(foo), &buffer_size_w, 0);
    if (!fSuccess)
    {
        printf ("fail WriteFile: %d\n", GetLastError ());
    }
}


int motor::mov(const MOTORSETTINGS& motorSettings, const char* motID, double dist)
{
    // convert dist to mm
    char idx[2];
    if (!strcmp(motID,"X")) sprintf(idx, "2");
    else if (!strcmp(motID, "Y")) sprintf(idx, "1");
    else if (!strcmp(motID, "Z")) sprintf(idx, "3");
    int distInSteps = (int) (motorSettings.pitch*dist);

    // calculate pausetime
    int pausetime = (int) abs(2000*(distInSteps/motorSettings.velX)) + 2000;

    // Move the infernal motor
    sprintf(foo, "C I%sM%d,R", idx, distInSteps);
    fSuccess = WriteFile(hCom, foo, strlen(foo), &buffer_size_w, 0);
    Sleep(pausetime);
    if (!fSuccess)
    {
        printf ("fail WriteFile: %d\n", GetLastError ());
        return 3;
    }
    return 0;
}

void motor::closeMotor(void)
{
    sprintf(foo, "Q"); // Close the offline mode so you can operate the dongle
    fSuccess = WriteFile(hCom, foo, strlen(foo), &buffer_size_w, 0);
    CloseHandle(hCom);
}

void motor::killMotor(void)
{
    sprintf(foo, "K"); // sends kill command to motor
    fSuccess = WriteFile(hCom, foo, strlen(foo), &buffer_size_w, 0);
    closeMotor();
}

void motor::setZero(void)
{
    sprintf(foo, "N");
    fSuccess = WriteFile(hCom, foo, strlen(foo), &buffer_size_w, 0);
}

QString motor::getX(void)
{
    sprintf(foo, "X");
    fSuccess = WriteFile(hCom, foo, strlen(foo), &buffer_size_w, 0);
    char foobar[10];
    fSuccess = ReadFile(hCom, &foobar, strlen(foobar), &buffer_size_r, 0);
    std::string str(foobar);
    return QString::fromStdString(str);
}
