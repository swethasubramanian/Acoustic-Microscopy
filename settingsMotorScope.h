#ifndef SETTINGSMOTORSCOPE_H_INCLUDED
#define SETTINGSMOTORSCOPE_H_INCLUDED

    // MOTORSETTINGS
    struct MOTORSETTINGS
    {
        double stepSizeX;
        double stepSizeY;
        double windowSizeX;
        double windowSizeY;
        int pitch = 400;
        int velX;
        int velY;
        int pauseTime;
    };

    struct SCOPESETTINGS
    {
        char probeAttn[10] = "10";
        int numOfPoints;
        int numOfAverages;
        char channel[10] = "CHANNEL1";
        char coupling[10] = "AC";
    };

#endif // SETTINGSMOTORSCOPE_H_INCLUDED
