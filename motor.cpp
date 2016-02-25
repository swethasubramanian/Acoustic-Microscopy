#include "motor.h"
#include <stdio.h>
#include "settingsMotorScope.h"
#include <QtGui>


motor::motor(QObject *parent) : QObject(parent)
{
    motorSocket = new QTcpSocket(this);
   // motorSocket->connectToHost("172.25.1.3", 5002);
}

QString motor::openMotor()
{
    motorSocket->connectToHost("172.25.1.3", 5002);
    QString errMsg;
    if (motorSocket->waitForConnected(15000))
    {
        errMsg = "Connected" ;
        motorSocket->write("SETUP\r\n\r\n");// Sets up pitch, velocities and pitch etc
        //setup();
    }
    else errMsg = "Not Connected";
    return errMsg;
}

QString motor::mov(const QString &motID, double dist)
{
    QString errMsg;
    char foo[100];
    if (motorSocket->waitForConnected(15000))
    {
        errMsg = "movConnected"+motID;

        if (motID == "X")
        {
            motorSocket->write("DRIVE01000\r\n\r\n");
            sprintf(foo, "D0,%d,0,0,0\r\n\r\n", (int)dist);
            motorSocket->write(foo);
            motorSocket->write("GO01000\r\n\r\n");
            //motorSocket->write("T2\r\n\r\n");
            Sleep(2000);
            motorSocket->write("DRIVE00000\r\n\r\n");
        }

        if (motID == "Y")
        {

            motorSocket->write("DRIVE10000\r\n\r\n");
            sprintf(foo, "D%d,0,0,0,0\r\n\r\n", (int)dist);
            motorSocket->write(foo);
            motorSocket->write("GO10000\r\n\r\n");
            //motorSocket->write("T2\r\n\r\n");
            Sleep(2000);
            motorSocket->write("DRIVE00000\r\n\r\n");
        }

        if (motID == "Z")
        {
            motorSocket->write("DRIVE00100\r\n\r\n");
            sprintf(foo, "D0,0,%d,0,0\r\n\r\n", (int)dist);
            motorSocket->write(foo);
            motorSocket->write("GO00100\r\n\r\n");
            //motorSocket->write("T2\r\n\r\n");
            Sleep(2000);
            motorSocket->write("DRIVE00000\r\n\r\n");
        }

        if (motID == "PHI")
        {
            motorSocket->write("DRIVE00010\r\n\r\n");
            sprintf(foo, "D0,0,0,%d,0\r\n\r\n", (int)dist);
            motorSocket->write(foo);
            motorSocket->write("GO00010\r\n\r\n");
            //motorSocket->write("T10\r\n\r\n");
            Sleep(10000);
            motorSocket->write("DRIVE00000\r\n\r\n");
        }

        if (motID == "THETA")
        {
            motorSocket->write("DRIVE00001\r\n\r\n");
            sprintf(foo, "D0,0,0,0,%d\r\n\r\n", (int)dist);
            motorSocket->write("D0,0,0,0,%d\r\n\r\n");
            motorSocket->write("GO00001\r\n\r\n");
            //motorSocket->write("T10\r\n\r\n");
            Sleep(10000);
            motorSocket->write("DRIVE00000\r\n\r\n");
        }
    }
    else errMsg = "Not Connected";
    return errMsg;
}

QString motor::closeMotor(void)
{
    QString errMsg;
    if (motorSocket->waitForConnected(3000))
    {
        errMsg = "is connected";
        motorSocket->close();
        errMsg = "connection closed";
    }
   else errMsg = "Not Connected";
   return errMsg;
}



