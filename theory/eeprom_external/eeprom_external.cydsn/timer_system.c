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
#include "timer_system.h"

volatile uint32 time_present = 0;
volatile uint8 button_flag = 0;
extern volatile int data_wite_to_eeprom;

CY_ISR(timer_hander)
{
    // Auto 1ms increase once
    time_present++;
    
    if(button_Read() == button_pressed)
    {
        button_flag = 1;
    }
    
    if((button_Read() == button_released) && (button_flag == 1))
    {
        button_flag = 0;
        
        data_wite_to_eeprom++;
        if(data_wite_to_eeprom > 8)
            data_wite_to_eeprom = 1;
    }
}




/* [] END OF FILE */
