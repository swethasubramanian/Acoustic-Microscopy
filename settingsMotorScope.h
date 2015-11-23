#ifndef SETTINGSMOTORSCOPE_H_INCLUDED
#define SETTINGSMOTORSCOPE_H_INCLUDED

    // MOTORSETTINGS
    struct MOTORSETTINGS
    {
        int stepSizeX;
        int stepSizeY;
        int windowSizeX;
        int windowSizeY;
        int pitch = 400;
        int velX;
        int velY;
        int pauseTime;
    };

    struct SCOPESETTINGS
    {
        char probeAttn[10];
        char numOfPoints[10];
        char numOfAverages[10];
        char channel[10];
        char coupling[10];
    };

#endif // SETTINGSMOTORSCOPE_H_INCLUDED
