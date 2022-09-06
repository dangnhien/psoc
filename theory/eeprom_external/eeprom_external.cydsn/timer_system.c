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
#include "project.h"
#include <stdio.h>

#include "eeprom_external.h"
#include "ledYellow.h"

volatile int counter_shift_led =  -2;
 
volatile uint32 counter1_ms = 0, counter1_s = 0, counter_uart = 0;

// CY_ISR(handle_interrupt)
void handle_interrupt(void)
{
    // Auto 1ms increase once
    counter1_ms++;
    if(counter1_ms > 4000000000) //4tr
        counter1_ms = 0;
    
    if( (counter1_ms % 1000) == 0 )
    {
        counter1_s++;
        
        counter_shift_led++;
        if(counter_shift_led > 7)
            counter_shift_led = 0;
        
        if( counter_uart > 4000000000)
            counter_uart = 0;
    }
    
    timer_ClearInterrupt(timer_INTR_MASK_TC);
    timer_interrupt_ClearPending();
}


void initTimeInterrupt()
{
    timer_interrupt_StartEx( handle_interrupt );
}



/* [] END OF FILE */
