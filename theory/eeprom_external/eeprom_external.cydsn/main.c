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
    int data_read_eeprom = 0x01;
    //int i=0;
    char stringss[10];
    
    // output status before turn off power
    //data_read_eeprom = eeprom_read_a_byte(0x01);
    
    for(;;)
    {        
        //eeprom_write_a_byte(0x01, counter_shift_led);
        //shift_left( counter_shift_led );
        //flicker_8_led(1);
        
        //eeprom_write_a_byte_08(0x04, 0x10);
        
        //eeprom_write_a_byte_128(0x04, 0x05);
        CyDelay(1000);
        data_read_eeprom = eeprom_read_a_byte(0x04);
        
        
        sprintf(stringss, "%u\n", data_read_eeprom);
        uart_UartPutString(stringss);
        
        
        LedYellow_0_Write(~LedYellow_0_Read());
        CyDelay(1000);
    }
}

void system_init()
{
    i2c_Start();
    
    timer_Start();
    
    init_time_interrupt();
    
    uart_Start();
    
    turn_off_all_led();
}



/* [] END OF FILE */
