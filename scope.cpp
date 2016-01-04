#include <stdio.h> // For printf function to work
#include <string.h> // to make directories etc
#include "scope.h" // includes a header file
#include "settingsMotorScope.h"
#include <visa.h> # Agilent stuff
#include <windows.h>

#define RESOURCE "GPIB0::7::INSTR"
#define WAVE_DATA_SIZE 5000
#define TIMEOUT 5000
#define SETUP_STR_SIZE 3000
#define IMG_SIZE 30000

ViSession defaultRM, vi;
char buf[256] = { 0 };
unsigned char waveform_data[WAVE_DATA_SIZE];

double preamble[10];

scope::scope()
{
}

void scope::closeScope(void)
{
    viClose(vi);
    viClose(defaultRM);
}

// Initialize oscilloscope
void scope::initializeScope(void)

{
    // Opens visa interface for communication with scope
    viOpenDefaultRM(&defaultRM);
    viOpen(defaultRM, RESOURCE, VI_NULL, VI_NULL, &vi);

    // Trigger settings
    //sprintf(foo, ":TRIGGER:EDGE:SOURCE CHANNEL1\n");
    //viPrintf(vi, foo);
    //viPrintf(vi, ":TRIGGER:MODE EDGE\n");
    //viPrintf(vi, ":TRIGGER:EDGE:SLOPE POSITIVE\n");
   // viPrintf(vi, ":TRIGGER:EDGE:LEVEL 0.50\n");



    // Set probe attenuation setting
    //sprintf(foo, ":CHAN1:PROBE %s\n", scopeSettings.probeAttn);
    //viPrintf(vi, foo);
    //sprintf(foo, ":CHAN1:COUPLING %s\n", scopeSettings.coupling);
    //viPrintf(vi, foo);
}

// Get data from the oscilloscope
void scope::getScopeData(const char* filename, const SCOPESETTINGS& scopeSettings)
{

    // printf("something:%s", scopeSettings.probeAttn);
    float voltage[WAVE_DATA_SIZE], t[WAVE_DATA_SIZE];
    int waveform_size = WAVE_DATA_SIZE;
    char foo[100];

    // Acquistion settings
    viPrintf(vi, ":ACQUIRE:TYPE AVERAGE\n");
    sprintf(foo, ":ACQUIRE:COUNT %d\n", scopeSettings.numOfAverages);
    viPrintf(vi, foo);

    //Write data out
    sprintf(foo, ":DIGITIZE %s\n", scopeSettings.channel);
    viPrintf(vi, foo);
    sprintf(foo, ":WAVEFORM:SOURCE %s\n", scopeSettings.channel);
    viPrintf(vi, foo);

    // Set format for waveform data
    viPrintf(vi, ":WAVEFORM:FORMAT BYTE\n");
    //viPrintf(vi, ":WAVEFORM:BYTEORDER LSBFIRST\n");

    // Get the preamble block
    viQueryf(vi, ":WAVEFORM:PREAMBLE?\n", "%,10lf\n", preamble);
    /* GET_PREAMBLE - The preamble contains all of the current WAVEFORM
    * settings returned in the form <preamble block><NL> where the
    * <preamble block> is:
    * FORMAT : int16 - 0 = BYTE, 1 = WORD, 4 = ASCII.
    * TYPE : int16 - 0 = NORMAL, 1 = PEAK DETECT, 2 = AVERAGE.
    * POINTS : int32 - number of data points transferred.
    * COUNT : int32 - 1 and is always 1.
    * XINCREMENT : float64 - time difference between data points.
    * XORIGIN : float64 - always the first data point in memory.
    * XREFERENCE : int32 - specifies the data point associated
    * with the x-origin.
    * YINCREMENT : float32 - voltage difference between data points.
    * YORIGIN : int waveformSize;float32 - value of the voltage at center screen. */

  //  printf("Preamble FORMAT: %e\n", preamble[0]);
   // printf("Preamble TYPE: %e\n", preamble[1]);
   // printf("Preamble POINTS: %e\n", preamble[2]);
   // printf("Preamble COUNT: %e\n", preamble[3]);
   // printf("Preamble XINCREMENT: %e\n", preamble[4]);
   // printf("Preamble XORIGIN: %e\n", preamble[5]);
   // printf("Preamble XREFERENCE: %e\n", preamble[6]);
   // printf("Preamble YINCREMENT: %e\n", preamble[7]);
   // printf("Preamble YORIGIN: %e\n", preamble[8]);
   // printf("Preamble YREFERENCE: %e\n", preamble[9]);

    // Set number of points
    sprintf(foo, ":WAVEFORM:POINTS %d\n", scopeSettings.numOfPoints);
    viPrintf(vi, foo);

    //Read data from the scope
    viPrintf(vi, ":WAVEFORM:DATA?\n");
    Sleep(2000);
    viScanf(vi, "%#b\n", &waveform_size, waveform_data);
    Sleep(2000);
    if (waveform_size == WAVE_DATA_SIZE)
    {
        printf("Waveform data buffer full:");
        printf("May not have received all points \n");
    }
    else{
        // save the data
        printf("Reading oscilloscope data... \n\n");
        FILE *fp;
        fp = fopen(filename, "w");
        // Write preamble first
        //fwrite(preamble, sizeof(preamble[0]), 10, fp);
        // Write data
        //fwrite(waveform_data, sizeof(waveform_data[0]), (int)preamble[2], fp);
        int i;
        volts.resize(scopeSettings.numOfPoints);
        time.resize(scopeSettings.numOfPoints);
        for (i=0; i<waveform_size; i++)
        {
            voltage[i] = ((float)waveform_data[i] -preamble[9])*preamble[7] + preamble[8];
            t[i] = ((float)i - preamble[6])*preamble[4] + preamble[5];
            volts[i] = voltage[i];
            time[i] = t[i];
            fprintf(fp, "%12.24f\t%0.24f\n", voltage[i], t[i]);
        }
        fclose(fp);
    }
}

void scope::setTimeDelay(double timeDelay)
{
    char foo[100];
    viPrintf(vi, ":TIMEBASE:REFERENCE CENTER\n");
    //viPrintf(vi, ":TIMEBASE:POSITION 20e-6\n");
    sprintf(foo, ":TIMEBASE:POSITION %fe-9\n", timeDelay);
    viPrintf(vi, foo);

}






