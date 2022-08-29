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
#include "uart_transmit.h"

void test_transmit_data()
{
    char data_test[] = "\nTransmit OK\n";
    uart_UartPutString(data_test);
}


void transmit_data_to_computer(float data_need_convert,int location)
{
    char string_result[40];
    
    switch(location)
    {
        case 0:
            sprintf(string_result, "Value1:%0.3f\n", data_need_convert);
            break;
        case 1:
            sprintf(string_result, "Value2:%0.3f\n", data_need_convert);
            break;
        case 2:
            sprintf(string_result, "Value3:%0.3f\n", data_need_convert);
            break;
        case 3:
            sprintf(string_result, "Value4:%0.3f\n", data_need_convert);
    }
    
    uart_UartPutString(string_result);
}



/* [] END OF FILE */
