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
#include "Timer_Delay.h"

#include "project.h"

volatile int timer_flag = 0;

CY_ISR(interrupt_timer)
{
    timer_flag = 1;
    timer_ClearInterrupt(timer_INTR_MASK_TC);
    timer_int_ClearPending();
}

void start_timer_int()
{
    timer_int_StartEx(interrupt_timer);
}

void ms_delay(unsigned long ms)
{
    uint32 period = TIMER_CLOCK/1000*ms;
    timer_WritePeriod(period);
    timer_Enable();// start the timeout counter
    while(!timer_flag);
    timer_Stop();
    timer_flag = 0;
}


/* [] END OF FILE */
