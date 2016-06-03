#include <stdio.h> // For printf function to work
#include <string.h> // to make directories etc
#include "scope.h" // includes a header file
#include "settingsMotorScope.h"
#include <visa.h> # Agilent stuff
#include <windows.h>

#define RESOURCE "GPIB0::7::INSTR"
#define WAVE_DATA_SIZE 30000
#define TIMEOUT 5000
#define SETUP_STR_SIZE 3000


ViSession defaultRM, vi;
char buf[256] = { 0 };
double preamble[10];
ViInt8 waveform_data_lecroy[WAVE_DATA_SIZE];
unsigned char waveform_data_agilent[WAVE_DATA_SIZE];
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
    // set timeout to 15 sec
    viSetAttribute(vi, VI_ATTR_TMO_VALUE, 15000);


}

// Get data from the oscilloscope
void scope::getScopeData(const char* filename, const SCOPESETTINGS& scopeSettings)
{

    // printf("something:%s", scopeSettings.probeAttn);

    float voltage[WAVE_DATA_SIZE], t[WAVE_DATA_SIZE];
    int waveform_size = WAVE_DATA_SIZE;
    char foo[100];



    if (strcmp(scopeSettings.whichScope, "LeCroy") == 0)
    {
        double vert_offset, horiz_offset, horiz_interval, vertical_gain;
        double max_value, min_value;
            // Find the voltage values (in volts)
        viPrintf(vi, "C1:INSPECT? 'VERTICAL_OFFSET'\n");
        viScanf(vi, "%t", &buf);
        sscanf(buf, "%*[^0123456789]%lf", &vert_offset);

        viPrintf(vi, "C1:INSPECT? 'VERTICAL_GAIN'\n");
        viScanf(vi, "%t", &buf);
        sscanf(buf, "%*[^0123456789]%le", &vertical_gain);

        // Get range for voltage values
        viPrintf(vi, "C1:INSPECT? 'MAX_VALUE'\n");
        viScanf(vi, "%t", &buf);
        sscanf(buf, "%*[^0123456789]%le", &max_value);

        viPrintf(vi, "C1:INSPECT? 'MIN_VALUE'\n");
        viScanf(vi, "%t", &buf);
        sscanf(buf, "%*[^0123456789]%le", &min_value);

        // Scale for time (in secs)
        viPrintf(vi, "C1:INSPECT? 'HORIZ_OFFSET'\n");
        viScanf(vi, "%t", &buf);
        sscanf(buf, "%*[^-0123456789]%le", &horiz_offset);

        viPrintf(vi, "C1:INSPECT? 'HORIZ_INTERVAL'\n");
        viScanf(vi, "%t", &buf);
        sscanf(buf, "%*[^-0123456789]%le", &horiz_interval);

        // manually averaging because the stupid system does not
        float tempData[WAVE_DATA_SIZE];
        int N = scopeSettings.numOfAvgs;
        for (int n=0; n<N; n++)
        {
            // Turn echo off
            viPrintf(vi, "CHDR OFF\n");
            viPrintf(vi, "COMM_FORMAT OFF,BYTE,BIN\n");
            //viPrintf(instr, "CFMT DEF9,BYTE,BIN\n");
            // viPrintf(vi, "A:DEF EQN,'AVG(C1)',AVGTYPE,SUMMED,SWEEPS,200");
            viPrintf(vi, "C1:WAVEFORM? DAT1\n");
            // viQueryf( instr, "C1:WF? DAT1\n", "%#t", &waveform_size, waveform_data);
            //viScanf(instr, "%#b\n", &waveform_size, waveform_data);

           viScanf(vi, "%#y\n", &waveform_size, waveform_data_lecroy);
            int i;
            for (i=0; i<waveform_size; i++)
            {
                voltage[i] = (float)vertical_gain*waveform_data_lecroy[i]-vert_offset;
                if (n==0) tempData[i] = voltage[i];
                else tempData[i] = tempData[i]+voltage[i];
            }
        }

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

            volts.resize(waveform_size);
            time.resize(waveform_size);
            for (int i=0; i<waveform_size; i++)
            {
                //voltage[i] = (float)vertical_gain*waveform_data[i]-vert_offset;
                t[i] = horiz_interval*i + horiz_offset;
                volts[i] = tempData[i]/N; // after averaging
                time[i] = t[i];
                fprintf(fp, "%12.24f\t%0.24f\n", tempData[i]/N, t[i]);
            }
            fclose(fp);
        }
    }

    else if (strcmp(scopeSettings.whichScope, "Agilent") == 0)
    {
        viPrintf(vi, ":ACQUIRE:TYPE AVERAGE\n");
        sprintf(foo, ":ACQUIRE:COUNT %d\n", scopeSettings.numOfAvgs);
        viPrintf(vi, foo);

        //Write data out
        sprintf(foo, ":DIGITIZE %s\n", "CHANNEL1");
        viPrintf(vi, foo);
        sprintf(foo, ":WAVEFORM:SOURCE %s\n", "CHANNEL1");
        viPrintf(vi, foo);

        // Set format for waveform data
        viPrintf(vi, ":WAVEFORM:FORMAT BYTE\n");
        //viPrintf(vi, ":WAVEFORM:BYTEORDER LSBFIRST\n");

        // Get the preamble block
        viQueryf(vi, ":WAVEFORM:PREAMBLE?\n", "%,10lf\n", preamble);
        //Sleep(1000);
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


        // Set number of points
        //viPrintf(vi, ":WAVEFORM:POINTS:MODE NORMAL\n");
        sprintf(foo, ":WAVEFORM:POINTS %d\n", scopeSettings.numOfPoints);
        viPrintf(vi, foo);

        //Read data from the scope
        viPrintf(vi, ":WAVEFORM:DATA?\n");
        //Sleep(1000);
        viScanf(vi, "%#b\n", &waveform_size, waveform_data_agilent);
       // Sleep(1000);

        if (waveform_size == WAVE_DATA_SIZE)
        {
            printf("Waveform data buffer full:");
            printf("May not have received all points \n");
        }
        else
        {
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
                voltage[i] = ((float)waveform_data_agilent[i] -preamble[9])*preamble[7] + preamble[8];
                t[i] = ((float)i - preamble[6])*preamble[4] + preamble[5];
                volts[i] = voltage[i];
                time[i] = t[i];
                fprintf(fp, "%12.24f\t%0.24f\n", voltage[i], t[i]);
            }
            fclose(fp);
        }
    }
}

void scope::setTimeDelay(double timeDelay)
{
    char foo[100];
   // viPrintf(vi, ":TIMEBASE:REFERENCE CENTER\n");
    //viPrintf(vi, ":TIMEBASE:POSITION 20e-6\n");
    sprintf(foo, "TRig_DeLay %fe-9\n", timeDelay);
    viPrintf(vi, foo);
}


//double scope::getNumPoints(void)
//{
 //   double points;
  //  viQuery(vi, "")
//}








