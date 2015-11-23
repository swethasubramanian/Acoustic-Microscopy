#include "motor.h"
//#include <boost/asio/serial_port.hpp>
#include <windows.h>
#include <stdio.h>
#include "settingsMotorScope.h"


motor::motor()
{
    DCB dcb;
    HANDLE hCom;
    BOOL fSuccess;
    char *pcCommPort = "COM1";
    DWORD buffer_size_w;
    char foo[100];
}


int motor::openMotor(const MOTORSETTINGS& motorSettings)
{

    hCom = CreateFile(pcCommPort,
                      GENERIC_READ | GENERIC_WRITE,
                      0,
                      NULL,
                      OPEN_EXISTING,
                      0,
                      NULL);

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
      return (3);
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
    if (!fSuccess)
    {
        printf ("fail WriteFile: %d\n", GetLastError ());
        return(3);
    }

    return 0;
}


int motor::mov(const MOTORSETTINGS& motorSettings, const char* motID)
{
    // convert dist to mm

    int distInSteps = motorSettings.stepSizeX*motorSettings.pitch;
    // Convert int to char
    sprintf(foo, "C I%sM%d,R", motID, distInSteps);
    printf("command sent is: %s", foo);
    fSuccess = WriteFile(hCom, foo, strlen(foo), &buffer_size_w, 0);
    Sleep(2000);
    if (!fSuccess)
    {
        printf ("fail WriteFile: %d\n", GetLastError ());
        return(3);
    }
    return 0;
}

void motor::closeMotor(void)
{
    CloseHandle(hCom);
}

