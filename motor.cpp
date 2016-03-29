#include "motor.h"
#include <stdio.h>
#include "settingsMotorScope.h"
#include <QtGui>


motor::motor(QObject *parent) : QObject(parent)
{
    motorSocket = new QTcpSocket(this);
    connected = false;
   // motorSocket->connectToHost("172.25.1.3", 5002);
}

bool motor::setup()
{
    if (motorSocket->waitForConnected(3000))
    {
        mutex.lock();
        connected = true;
        mutex.unlock();
        //motorSocket->write("SETUP\r\n\r\n");// Directly uses setup program that Janelle wrote?
        // Scaling velocity and acceleration
//        motorSocket->write("SCALE1\r\n\r\n");
//        motorSocket->write("SCLD 10000,10000,10000,25400,141\r\n\r\n");
//        motorSocket->write("SCLV 50800,50800,50800,50800,50800\r\n\r\n");
//        motorSocket->write("SCLA 50800,50800,50800,50800,50800\r\n\r\n");
//
//
//        motorSocket->write("ERES 50800,50800,5000,200,1000\r\n\r\n");
//        motorSocket->write("DRES 50800,50800,50800,50800,200\r\n\r\n"); //encoder resolution post quadrature
//        motorSocket->write("A10,10,10,10,10\r\n\r\n"); //Default Acceleration (mm/sec^2 for axes 1-3
//        motorSocket->write("V5,5,5,2,2\r\n\r\n"); //Default Velocity (mm/sec^2 for axes 1-3
//
//        //Sets up pitch, velocities and pitch etc
//        //setup();
//        motorSocket->write("CMDDIR1\r\n\r\n");
//        motorSocket->write("ENCCNT11111\r\n\r\n");
//
//        motorSocket->write("LH3,3,3,0,3\r\n\r\n"); //Enable/disable hard end-of-travel limits
//        motorSocket->write("COMEXC1\r\n\r\n"); //Turn continuous command execution on
//        motorSocket->write("OUT00\r\n\r\n"); // applies brake on Y axis
//
        // Define setup programs fpr the lousy machine
        motorSocket->write("SETUP\r\n\r\n");

        motorSocket->write("VAR7=0\r\n\r\n");
       // motorSocket->write("OUT11\r\n\r\n");

        motorSocket->write("DEL XSCANS\r\n\r\n");
        motorSocket->write("DEF XSCANS\r\n\r\n");
        motorSocket->write("DRIVE01000\r\n\r\n");
        motorSocket->write("D0,(VAR4),0,0,0\r\n\r\n");
        motorSocket->write("GO01000\r\n\r\n");
        motorSocket->write("T(VAR7)\r\n\r\n");
        motorSocket->write("DRIVE00000\r\n\r\n");
        motorSocket->write("END\r\n\r\n");

        // Y axis
        motorSocket->write("DEL YSCANS\r\n\r\n");
        motorSocket->write("DEF YSCANS\r\n\r\n");
        motorSocket->write("DRIVE10000\r\n\r\n");
        motorSocket->write("D(VAR5),0,0,0,0\r\n\r\n");
        motorSocket->write("GO10000\r\n\r\n");
        motorSocket->write("T(VAR7)\r\n\r\n");
        motorSocket->write("DRIVE00000\r\n\r\n");
        motorSocket->write("END\r\n\r\n");

        // Z axis
        motorSocket->write("DEL ALIGNZS\r\n\r\n");
        motorSocket->write("DEF ALIGNZS\r\n\r\n");
        motorSocket->write("DRIVE00100\r\n\r\n");
        motorSocket->write("D0,0,(VAR3),0,0\r\n\r\n");
        motorSocket->write("OUT11\r\n\r\n");
        motorSocket->write("GO00100\r\n\r\n");
        motorSocket->write("T(VAR7)\r\n\r\n");
        motorSocket->write("OUT00\r\n\r\n");
        motorSocket->write("DRIVE00000\r\n\r\n");
        motorSocket->write("END\r\n\r\n");
    }
    return connected;

}

bool motor::openMotor()
{
    motorSocket->connectToHost("172.25.1.3", 5002);
    if (motorSocket->waitForConnected(3000))
    {
        mutex.lock();
        connected = true;
        mutex.unlock();
        // Directly uses setup program that Janelle wrote?
        //Sets up pitch, velocities and pitch etc
        //setup();
    }
    return connected;
}

bool motor::movAlign(const QString &motID, double dist)
{
    if (motorSocket->waitForConnected(3000))
    {
        mutex.lock();
        connected = true;
        mutex.unlock();

        char foo[100];
        int pausetime = (int) abs(1000*(dist)) + 3000; //in millisecs
        sprintf(foo, "VAR7=%d\r\n\r\n", pausetime);
        motorSocket->write(foo);

        if (motID == "X")
        {
            sprintf(foo, "VAR4=%d\r\n\r\n", (int)dist);
            motorSocket->write(foo);
            motorSocket->write("XSCANS\r\n\r\n");
        }

        else if (motID == "Y")
        {
            sprintf(foo, "VAR5=%d\r\n\r\n", (int)dist);
            motorSocket->write(foo);
            motorSocket->write("YSCANS\r\n\r\n");
        }

        else if (motID == "Z")
        {
           // motorSocket->write("OUT11\r\n\r\n");
            sprintf(foo, "VAR3=%d\r\n\r\n", (int)dist);
            motorSocket->write(foo);
            motorSocket->write("ALIGNZS\r\n\r\n");
//            motorSocket->write("DRIVE00100\r\n\r\n");
//            sprintf(foo, "D0,0,%d,0,0\r\n\r\n", (int)dist);
//            motorSocket->write(foo);
//            motorSocket->write("OUT11\r\n\r\n"); // disable the bloody brake
//            motorSocket->write("GO00100\r\n\r\n");
//            //motorSocket->write("T2\r\n\r\n");
//            Sleep(pausetime);
//            //motorSocket->write("OUT00\r\n\r\n"); // applying brake again previous person did?
//            motorSocket->write("DRIVE00000\r\n\r\n");
        }
    }
    return connected;
}

bool motor::mov(const QString &motID, double dist)
{
    char foo[100];
    //default value for velocity is 1
    int pausetime = (int) abs(1000*(dist)) + 3000; //in millisecs
    if (motorSocket->waitForConnected(3000))
    {
        mutex.lock();
        connected = true;
        mutex.unlock();
        if (motID == "X")
        {
            motorSocket->write("DRIVE01000\r\n\r\n");
            sprintf(foo, "D0,%d,0,0,0\r\n\r\n", (int)dist);
            motorSocket->write(foo);
            motorSocket->write("GO01000\r\n\r\n");
            //motorSocket->write("T2\r\n\r\n");
            Sleep(pausetime);
            motorSocket->write("DRIVE00000\r\n\r\n");
        }

        else if (motID == "Y")
        {

            motorSocket->write("DRIVE10000\r\n\r\n");
            sprintf(foo, "D%d,0,0,0,0\r\n\r\n", (int)dist);
            motorSocket->write(foo);
            motorSocket->write("GO10000\r\n\r\n");
            //motorSocket->write("T2\r\n\r\n");
            Sleep(pausetime);
            motorSocket->write("DRIVE00000\r\n\r\n");
        }

        else if (motID == "Z")
        {
            motorSocket->write("DRIVE00100\r\n\r\n");
            sprintf(foo, "D0,0,%d,0,0\r\n\r\n", (int)dist);
            motorSocket->write(foo);
            motorSocket->write("OUT11\r\n\r\n"); // disable the bloody brake
            motorSocket->write("GO00100\r\n\r\n");
            //motorSocket->write("T2\r\n\r\n");
            Sleep(pausetime);
            //motorSocket->write("OUT00\r\n\r\n"); // applying brake again previous person did?
            motorSocket->write("DRIVE00000\r\n\r\n");
        }

        else if (motID == "PHI")
        {
            motorSocket->write("DRIVE00010\r\n\r\n");
            sprintf(foo, "D0,0,0,%d,0\r\n\r\n", (int)dist);
            motorSocket->write(foo);
            motorSocket->write("GO00010\r\n\r\n");
            //motorSocket->write("T10\r\n\r\n");
            Sleep(10000);
            motorSocket->write("DRIVE00000\r\n\r\n");
        }

        else if (motID == "THETA")
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
    return connected;
}

bool motor::closeMotor(void)
{
    if (motorSocket->waitForConnected(3000))
    {
        motorSocket->close();
        mutex.lock();
        connected = false;
        mutex.unlock();
    }
   return connected;
}



