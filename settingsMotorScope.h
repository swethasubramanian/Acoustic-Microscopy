#ifndef SETTINGSMOTORSCOPE_H_INCLUDED
#define SETTINGSMOTORSCOPE_H_INCLUDED

    // MOTORSETTINGS
    struct MOTORSETTINGS
    {
        double stepSizeX;
        double stepSizeY;
        double stepSizeZ;
        double windowSizeX;
        double windowSizeY;
        double windowSizeZ;
        // using default values given in Janelle's Program
        double velX = 1; // mm/s
        double velY = 1; // mm/s
        double velZ = 1; // mm/s
    };

    struct SCOPESETTINGS
    {
        char channel[10] = "C1";
        char whichScope[100];
        int numOfAvgs;
        int numOfPoints;
    };

#endif // SETTINGSMOTORSCOPE_H_INCLUDED
