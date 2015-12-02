/**
* Code to handle motor and oscilloscope
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <windows.h>
#include "scope.h"
#include "settingsMotorScope.h"
#include "motor.h"
#include "bsc.h"

// GUI stuff here
#include <QtGui>
#include <QApplication>




int main(int argc, char *argv[])
{


    // Setting up GUI here
   //
    QApplication app(argc, argv);
    bsc gooey;
    gooey.show();


   // Read in experiment/scope/motor setting parameters from settings.txt file

    // first make directory for storing files


//    // if planar do as follows
//    scope SCOPE;
//
//    //SCOPE.initializeScope()
//
//    int i;
//    std::ostringstream s;
//    if (strcmp(expType, "Planar") == 0)
//    {
//        for (i = 0; i <= Nx*Ny; i++)
//        {
//            //std::string s = std::to_string(i);
//            s << i;
//            std::string filename = dirLevel+"\\"+s.str()+".dat";
//            SCOPE.getScopeData(filename.c_str(), scopeSettings);
//            s.str("");
//            s.clear();
//        }
//    }
//    else // with motor
//    {
//        int j;
//        motor MOTOR;
//        int windowX = motorSettings.windowSizeX;
//        int windowY = motorSettings.windowSizeY;
//        int stepXmm = motorSettings.stepSizeX;
//        int stepYmm = motorSettings.stepSizeY;
//        MOTOR.openMotor(motorSettings);
//
//        // calculate pause time
//
//        // move motor to bottom left of the ROI (from computer perspective)
//        MOTOR.mov(motorSettings, "X", -windowX/2); //(minus is left)
//        MOTOR.mov(motorSettings, "Y", windowY/2); //(minus is up)
//
//
//        int count = 1;
//        s << count;
//        std::string filename = dirLevel + "\\" + s.str() + ".dat";
//        SCOPE.getScopeData(filename.c_str(), scopeSettings);
//        s.str("");
//        s.clear();
//        for (i=0; i<=Nx; i++)
//        {
//            if (i>0)
//            {
//                MOTOR.mov(motorSettings, "X", stepXmm);
//                count = count+1;
//                s<<count;
//                filename = dirLevel + "\\" + s.str() + ".dat";
//                SCOPE.getScopeData(filename.c_str(), scopeSettings);
//                s.str("");
//                s.clear();
//            }
//            if (i%2 == 0)
//            {
//                for (j=0; j<=Ny; j++)
//                {
//                    if (j>0)
//                    {
//                        MOTOR.mov(motorSettings, "Y", -stepYmm);
//                        count = count+1;
//                        s<<count;
//                        filename = dirLevel + "\\" + s.str() + ".dat";
//                        SCOPE.getScopeData(filename.c_str(), scopeSettings);
//                        s.str("");
//                        s.clear();
//                    }
//                }
//            }
//            else
//            {
//                for (j=0; j<=Ny; j++)
//                {
//                    if (j>0)
//                    {
//                        MOTOR.mov(motorSettings, "Y", stepYmm);
//                        count = count+1;
//                        s<<count;
//                        filename = dirLevel + "\\" + s.str() + ".dat";
//                        SCOPE.getScopeData(filename.c_str(), scopeSettings);
//                        s.str("");
//                        s.clear();
//                    }
//                }
//            }
//        }
//        // Move motor back to center of the ROI
//        MOTOR.mov(motorSettings, "X", -windowX/2);
//        if (i%2==0)
//        {
//            MOTOR.mov(motorSettings, "Y", -windowY/2);
//        }
//        else
//        {
//            MOTOR.mov(motorSettings, "Y", windowY/2);
//        }
//        MOTOR.closeMotor();
//    }
//    SCOPE.closeScope();
    return app.exec();
    //return 0;
}
