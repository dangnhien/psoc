/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "main.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    Init_System();  
    
    float result_Read_Adc;
   

    for(;;)
    {
        /* Place your application code here. */
        
        result_Read_Adc = readADC();
        
        transmitToPC( result_Read_Adc );
        
        CyDelay( 1000 );
    }
}

void Init_System()
{
    uartUser_Start();
    
    adcUser_Start();    /* Initialize ADC */  
}

float readADC()
{
    float value_Adc_Volt=0;
    
    adcUser_StartConvert();    /* Start ADC conversions */
    
    adcUser_IsEndConversion(  adcUser_WAIT_FOR_RESULT );
    
    value_Adc_Volt = adcUser_GetResult16(0);
    
    float value_Adc_mVolt = adcUser_CountsTo_mVolts(0, value_Adc_Volt);
    //  float32 value_Adc_mVolt = (value_Adc_Volt*5)/4095;
    
    //return value_Adc_Volt;
    return value_Adc_mVolt;
}

void transmitToPC(float adcData)
{
    char buffer_value_transmit[10];
    
    sprintf(buffer_value_transmit,"%0.3f\n", adcData); 
    
    uartUser_UartPutString(buffer_value_transmit);
    
    //uartUser_UartPutCRLF(0x20); /* Printf down line between string ( ~'\n')*/
}



/* [] END OF FILE */
