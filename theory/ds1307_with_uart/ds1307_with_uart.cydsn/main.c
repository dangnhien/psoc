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
    char txString[50];
    
    system_initialization(); 
    
    ds1307_time_init(&time);
    //ds1307_write_data(&time);
    time_string_concatenation(time, txString);
    uart_transmit_UartPutString(txString); 
    CyDelay(1000);
    
    
    for(;;)
    {
        Pin_Led_Yellow_Write( ~Pin_Led_Yellow_Read() );   
        
        ds1307_read_data(&time); 
        time_string_concatenation(time, txString);
        uart_transmit_UartPutString(txString);   
        
        CyDelay(500);
    }
}

void system_initialization()
{
    uart_transmit_Start();
    
    i2c_ds1307_Start();
    
    Pin_Led_Yellow_Write(0);
}


/* [] END OF FILE */
