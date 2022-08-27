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
    
    data_time time;
    char txString[50];
    
    system_Initialization();
    
    Pin_Led_Write(0);
    
    uart_UartPutString("\nStart\n");
    
    /*
    init_Timer_Start(&time);
    time_String_Concatenation(time, txString);
    uart_UartPutString(txString);
    CyDelay(1000);
    
    ds1307_write_data(&time); 
    time_String_Concatenation(time, txString);
    uart_UartPutString(txString);
    uart_UartPutString("\n\nStop Start\n");
    CyDelay(1000);
    
    Pin_Led_Write(0);
    
    CyDelay(1000);
    */
    
    for(;;)
    {
        
        Pin_Led_Write(1);
        ds1307_read_data(&time); 
        
        time_String_Concatenation(time, txString);
        
        
        /*
        uart_UartPutString(txString);
        
        CyDelay(1000);
        */
    }
}

void system_Initialization()
{
    uart_Start();
    
    i2c_master_Start();
}


/* [] END OF FILE */
