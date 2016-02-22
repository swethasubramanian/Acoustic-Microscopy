#include <stdio.h> // For printf function to work
#include <string.h> // to make directories etc
#include "scope.h" // includes a header file
#include "settingsMotorScope.h"
#include <visa.h> # Agilent stuff
#include <windows.h>

#define RESOURCE "GPIB0::5::INSTR"
#define WAVE_DATA_SIZE 160000
#define TIMEOUT 5000
#define SETUP_STR_SIZE 3000
#define IMG_SIZE 30000

ViSession defaultRM, vi;
char buf[256] = { 0 };
ViInt8 waveform_data[WAVE_DATA_SIZE];

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

    // Turn echo off
    viPrintf(vi, "CHDR OFF\n");
    viPrintf(vi, "COMM_FORMAT OFF,BYTE,BIN\n");
    //viPrintf(instr, "CFMT DEF9,BYTE,BIN\n");
    viPrintf(vi, "C1:WAVEFORM? DAT1\n");
   // viQueryf( instr, "C1:WF? DAT1\n", "%#t", &waveform_size, waveform_data);
    //viScanf(instr, "%#b\n", &waveform_size, waveform_data);

    viScanf(vi, "%#y\n", &waveform_size, waveform_data);


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
        volts.resize(waveform_size);
        time.resize(waveform_size);
        for (i=0; i<waveform_size; i++)
        {
            voltage[i] = (float)vertical_gain*waveform_data[i]-vert_offset;
            t[i] = horiz_interval*i + horiz_offset;
            volts[i] = voltage[i];
            time[i] = t[i];
            fprintf(fp, "%12.24f\t%0.24f\n", voltage[i], t[i]);
        }
        fclose(fp);
    }
}



//double scope::getNumPoints(void)
//{
 //   double points;
  //  viQuery(vi, "")
//}








