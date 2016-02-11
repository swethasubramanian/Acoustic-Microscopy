#include "motor.h"
#include <stdio.h>
#include "settingsMotorScope.h"
#include <QtGui>
#include <QTcpSocket>


motor::motor(QObject *parent) : QObject(parent)
{
    motorSocket = new QTcpSocket(this);
}


void motor::openMotor()
{
    motorSocket->connectToHost("172.25.1.3", 5002);
    if (motorSocket->waitForConnected(3000))
    {
        qDebug() << "Connected" ;
        motorSocket->write("SETUP\r\n\r\n"); // Sets up pitch, velocities and pitch etc
    }
    else
    {
        qDebug() << "Not Connected";
    }
}

void motor::setup()
{
     //copied from Janelle's code
    if (motorSocket->waitForConnected(3000))
    {
        // Setup X Scans
        motorSocket->write("DEL XSCAN\r\n\r\n");
        motorSocket->write("DEF XSCAN\r\n\r\n");
        motorSocket->write("DRIVE01000\r\n\r\n");
        motorSocket->write("D0,(VAR4),0,0,0\r\n\r\n");
        motorSocket->write("GO01000\r\n\r\n");
        motorSocket->write("T2\r\n\r\n");
        motorSocket->write("DRIVE00000\r\n\r\n");
        motorSocket->write("END\r\n\r\n");

        // Y axis
        motorSocket->write("DEL YSCAN\r\n\r\n");
        motorSocket->write("DEF YSCAN\r\n\r\n");
        motorSocket->write("DRIVE10000\r\n\r\n");
        motorSocket->write("D(VAR5),0,0,0,0\r\n\r\n");
        motorSocket->write("GO10000\r\n\r\n");
        motorSocket->write("T2\r\n\r\n");
        motorSocket->write("DRIVE00000\r\n\r\n");
        motorSocket->write("END\r\n\r\n");

        // Z axis
        motorSocket->write("DEL ZSCAN\r\n\r\n");
        motorSocket->write("DEF ZSCAN\r\n\r\n");
        motorSocket->write("DRIVE00100\r\n\r\n");
        motorSocket->write("D0,0,(VAR3),0,0\r\n\r\n");
        motorSocket->write("GO00100\r\n\r\n");
        motorSocket->write("T2\r\n\r\n");
        motorSocket->write("DRIVE00000\r\n\r\n");
        motorSocket->write("END\r\n\r\n");

        // phi axis control
        motorSocket->write("DEL PHISCAN\r\n\r\n");
        motorSocket->write("DEF PHISCAN\r\n\r\n");
        motorSocket->write("DRIVE00010\r\n\r\n");
        motorSocket->write("D0,0,0,(VAR1),0\r\n\r\n");
        motorSocket->write("GO00010\r\n\r\n");
        motorSocket->write("T10\r\n\r\n");
        motorSocket->write("DRIVE00000\r\n\r\n");
        motorSocket->write("END\r\n\r\n");

        // theta axis
        motorSocket->write("DEL THETASCAN\r\n\r\n");
        motorSocket->write("DEF THETASCAN\r\n\r\n");
        motorSocket->write("DRIVE00001\r\n\r\n");
        motorSocket->write("D0,0,0,0,(VAR2)\r\n\r\n");
        motorSocket->write("GO00001\r\n\r\n");
        motorSocket->write("T10\r\n\r\n");
        motorSocket->write("DRIVE00000\r\n\r\n");
        motorSocket->write("END\r\n\r\n");
    }
    else
    {
     qDebug() << "Not Connected";
    }
}

int motor::mov(const char* motID, double dist)
{
    // convert dist
    if (motID == "X")
    {
        if (motorSocket->waitForConnected(3000))
        {
            motorSocket->write("VAR4=-10\r\n\r\n");
            motorSocket->write("XSCAN\r\n\r\n");
        }
        else qDebug() << "Not Connected";
    }

    else if (motID == "Y")
    {
        if (motorSocket->waitForConnected(3000))
        {
            motorSocket->write("VAR5=-10\r\n\r\n");
            motorSocket->write("YSCAN\r\n\r\n");
        }
        else qDebug() << "Not Connected";
    }

    else if (motID == "Z")
    {
        if (motorSocket->waitForConnected(3000))
        {
            motorSocket->write("VAR3=-10\r\n\r\n");
            motorSocket->write("ZSCAN\r\n\r\n");
        }
        else
            qDebug() << "Not Connected";
    }

    else if (motID == "PHI")
    {
        if (motorSocket->waitForConnected(3000))
        {
            motorSocket->write("VAR1=-10\r\n\r\n");
            motorSocket->write("PHISCAN\r\n\r\n");
        }
        else
            qDebug() << "Not Connected";
    }

    else if (motID == "THETA")
    {
        if (motorSocket->waitForConnected(3000))
        {
            motorSocket->write("VAR2=-10\r\n\r\n");
            motorSocket->write("THETASCAN\r\n\r\n");
        }
        else
            qDebug() << "Not Connected";
    }
}

void motor::closeMotor(void)
{
    if (motorSocket->waitForConnected(3000))
    {
        motorSocket->close();
        qDebug() << "disconnected";
    }
    else
        qDebug() << "Not Connected";
}



