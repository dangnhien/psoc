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
#include <stdio.h>
#include "project.h"
#include "ds1307_i2c.h"
#include "uart_transmitss.h"
    
#include "main.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    data_time time;
    char txString[50];
    
    system_initialization(); 
    
    uart_transmit_UartPutString("Write data to DS1307.\n");
    CyDelay(1000);
    
    ds1307_time_init(&time);
    ds1307_write_data(&time);
    time_string_concatenation(time, txString);
    uart_transmit_UartPutString(txString); 
    CyDelay(1000);
    
    uart_transmit_UartPutString("\nRead data to DS1307.\n");
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
