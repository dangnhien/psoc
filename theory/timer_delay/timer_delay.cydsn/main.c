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

#include "project.h"
#include "Timer_Delay.h"
#include "Led_Yellow.h"


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    init_system();

    for(;;)
    {
        led_blink(100);
    }
}

void init_system(void)
{
    timer_Start();
    
    start_timer_int();
}

/* [] END OF FILE */
