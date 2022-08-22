/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * =========================================
*/
#include "project.h"
#include <stdio.h>

void configSystem();

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    configSystem();
    

    for(;;)
    {
        /* Place your application code here. */
    }
}

void configSystem()
{
    uartUser_Start();
    adcUser_Start();    /* Initialize ADC */
    
    adcUser_StartConvert();    /* Start ADC conversions */
    
}

int16 readADC()
{
    int16 value_adc=0;
    value_adc = adcUser_GetResult16(0);
    
    return value_adc;
}

void transmitToPC(int16 adcData)
{
    char8 res[10];
    
    sprintf(res,"%d", adcData); 
    
    uartUser_UartPutString(res);
    uartUser_UartPutCRLF(0x20); /* Printf space between string*/
    CyDelay(5);
}





/* [] END OF FILE */
