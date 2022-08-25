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
    
    data_time time;
    char txString[30];
    
    system_initialization();

    for(;;)
    {
        /* Place your application code here. */
        int status_button = Pin_Button_Read();
        
        if(status_button == Button_Pressed)
        {
            ds1307_write_data(&time);   
        }
        else
        {
            ds1307_read_data(&time);        
            time_string_concatenation(time, txString);
            uart_UartPutString(txString);
        }
    }
}


void system_initialization()
{
    uart_Start();
    
    i2c_master_Start();
}


/* [] END OF FILE */
