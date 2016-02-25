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
    };

    struct SCOPESETTINGS
    {
        char channel[10] = "CHANNEL1";
    };

#endif // SETTINGSMOTORSCOPE_H_INCLUDED
