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

#include "measureResister.h"

float read_adc(int channel)
{
    float value_read_adc = 0;
    
    switch(channel)
    {
        case 0:
            adc_StartConvert();
            adc_IsEndConversion(adc_WAIT_FOR_RESULT);
            value_read_adc = adc_GetResult16(0);
            adc_StopConvert();
            break;
        case 1:
            adc_StartConvert();
            adc_IsEndConversion(adc_WAIT_FOR_RESULT);
            value_read_adc = adc_GetResult16(1);
            adc_StopConvert();
            break;
        case 2:
            adc_StartConvert();
            adc_IsEndConversion(adc_WAIT_FOR_RESULT);
            value_read_adc = adc_GetResult16(2);
            adc_StopConvert();
            break;
        case 3:
            adc_StartConvert();
            adc_IsEndConversion(adc_WAIT_FOR_RESULT);
            value_read_adc = adc_GetResult16(3);
            adc_StopConvert();
    }
                
    // Choose --> data format justification: right
    float value_Adc_mVolt = adc_CountsTo_mVolts(0, value_read_adc);
    //float value_Adc_mVolt = (value_read_adc/127)*5*1000;
    
    return value_Adc_mVolt;
}

/* [] END OF FILE */
