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

#include <stdio.h>
#include "project.h"
#include "timer_system.h"
#include "eeprom_external.h"
#include "ledYellow.h"

extern volatile int counter_shift_led;

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    system_init();
    
    for(;;)
    {          
        //write_and_read_a_byte_24c08();
        
        write_and_read_page_24c08();
        
        //write_and_read_a_byte_24c256();
        
        //write_and_read_page_24c256();
        

        LedYellow_0_Write(~LedYellow_0_Read());
        CyDelay(1000);
    }
}

void system_init()
{
    i2c_Start();
    
    timer_Start();
    
    initTimeInterrupt();
    
    uart_Start();
    
    turn_off_all_led();
}

void write_and_read_a_byte_24c08()
{
    char stringss[10];
    int data_read_eeprom = 0x00;
    
    /*
        After write data to eeprom --> must delay,
        if not delay --> program stop, not run
    */
    eeprom_write_a_byte_08(0x03, 0x15);
    CyDelay(100);
    
    data_read_eeprom = eeprom_read_a_byte_08(0x03);
    
    sprintf(stringss, "%u\n", data_read_eeprom);
    uart_UartPutString(stringss);
}

void write_and_read_page_24c08()
{
    int i, length = 10;
    char string_convert[30];
    uint8 string_read[11];
    uint32 string_write[] = {0x11, 0x01, 0x02, 0x02, 0x03, 0x03, 0x03, 0x03, 0x03, 0xFF};
    
    eeprom_write_page_08(0x03, string_write, length);
    CyDelay(1000);
    
    eeprom_read_page_08(0x03, string_read, length);
    
    for(i=0; i<length; i++)
    {
        if(i==0)
            sprintf(string_convert, "\nStart\n%u\n", string_read[i]);
        else
            sprintf(string_convert, "%u\n", string_read[i]);
            
        uart_UartPutString(string_convert);
    } 
}


void write_and_read_a_byte_24c256()
{
    char stringss[10];
    int data_read_eeprom = 0x00;
    
    /*
        After write data to eeprom --> must delay,
        if not delay --> program stop, not run
    */
    eeprom_write_a_byte_256(0x03, 0x0F);
    CyDelay(100);
    
    data_read_eeprom = eeprom_read_a_byte_256(0x03);
    
    sprintf(stringss, "%u\n", data_read_eeprom);
    uart_UartPutString(stringss);
}

void write_and_read_page_24c256()
{
    int i;
    char string_convert[30];
    uint8 string_read[11];
    uint32 string_write[] = {0x1, 0x01, 0x02, 0x02, 0x05, 0x06, 0x07, 0x08, 0x09, 0xFF};
    
    eeprom_write_page_256(0x01, string_write, 10);
    CyDelay(1000);
    
    eeprom_read_page_256(0x01, string_read, 10);
    
    for(i=0; i<10; i++)
    {
        if(i==0)
            sprintf(string_convert, "\nStart\n%u\n", string_read[i]);
        else
            sprintf(string_convert, "%u\n", string_read[i]);
            
        uart_UartPutString(string_convert);   
    }
}

/* [] END OF FILE */
