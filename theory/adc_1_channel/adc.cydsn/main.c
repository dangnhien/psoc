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
        //result_Read_Adc = readADC();
        result_Read_Adc = readLM35();
        
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
    float value_read_adc=0;
    
    adcUser_StartConvert();    /* Start ADC conversions */
    
    adcUser_IsEndConversion( adcUser_WAIT_FOR_RESULT );
    
    value_read_adc = adcUser_GetResult16(0);
    
    adcUser_StopConvert();
    
    // Choose --> data format justification: right
    //float value_Adc_mVolt = adcUser_CountsTo_mVolts(0, value_read_adc);
    //float value_Adc_mVolt = (value_Adc_Volt/127)*5*1000;
    
    // Choose --> data format justification: left
    float value_Adc_mVolt = (value_read_adc/32767)*5*1000;
    
    return value_Adc_mVolt;
}

void transmitToPC(float adcData)
{
    char buffer_value_transmit[20];
    
    sprintf(buffer_value_transmit,"%f\n", adcData); 
    
    uartUser_UartPutString(buffer_value_transmit);
}

float readLM35()
{
    float value_read_adc=0;
    
    adcUser_StartConvert();    /* Start ADC conversions */
    
    adcUser_IsEndConversion( adcUser_WAIT_FOR_RESULT );
    
    value_read_adc = adcUser_GetResult16(0);
    
    adcUser_StopConvert();
    
    // Choose --> data format justification: right
    //float value_Adc_mVolt = adcUser_CountsTo_mVolts(0, value_read_adc);
    //float value_Adc_mVolt = (value_Adc_Volt/127)*5*1000;
    
    // Choose --> data format justification: left
    float value_Adc_mVolt = (value_read_adc/32767)*5*1000;
    
    //1*c == 10mv
    // --> temprature = value_Adc_mVolt/10;
    
    value_Adc_mVolt /=10;
    return value_Adc_mVolt;
}


/* [] END OF FILE */
