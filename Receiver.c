
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "Receiver.h"

float ComputeSMA(float data[])
{
    int sum;
    float average;
    for(int i=0; i<NO_OF_READINGS; i++)
        {
            sum += data[i];
        }
        average = sum/NO_OF_READINGS;
        return average;
}
float ComputeMax(float data[])
{
    float Maximum = data[0];
    for(int i=1; i<NO_OF_READINGS; i++)
    {
        if(Maximum < data[i])
        {
            Maximum = data[i];
        }
    }
    return Maximum;
}
float ComputeMin(float data[])
{
    float Minimum = data[0];
    for(int i=1; i<NO_OF_READINGS; i++)
    {
        if(Minimum > data[i])
        {
            Minimum = data[i];
        }
    }
    return Minimum;
}

void ReadBatteryReadingsfromConsole(float* Temperature, float* SOC, float* ChargeRate)
{
    for(int i=0; i<NO_OF_READINGS; i++)
    {
        scanf("%f ,%f ,%f",&ChargeRate[i],&SOC[i],&Temperature[i]);
    }
}

void PrintOnConsole(float *BMSParameter, float MaxValue, float Minvalue, float SMA)
{
  int readingIndex = 0;
  printf("Data received from sender\n");
  
  for(readingIndex = 0; readingIndex < NO_OF_READINGS; readingIndex++)
  {
    printf("%f\n",BMSParameter[readingIndex]);
  }
  printf("Max value: %f, Min value: %f, SMA: %f\n",MaxValue,Minvalue,SMA);
  
}

void Receiver(float* Temperature, float* SOC, float* ChargeRate)
{
  ReadBatteryReadingsfromConsole(Temperature,SOC,ChargeRate);
  PrintOnConsole(Temperature,ComputeMax(Temperature),ComputeMin(Temperature),ComputeSMA(Temperature));
  PrintOnConsole(SOC,ComputeMax(SOC),ComputeMin(SOC),ComputeSMA(SOC));
  PrintOnConsole(ChargeRate,ComputeMax(ChargeRate),ComputeMin(ChargeRate),ComputeSMA(ChargeRate));
}
