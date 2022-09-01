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

#include "Led_Yellow.h"

#include "Timer_Delay.h"

enum led_status
{
    turn_on,
    turn_off
};


void led_blink(uint32 ms)
{
    Pin_Led_Yellow_Write(turn_on);
    ms_delay(ms);
    Pin_Led_Yellow_Write(turn_off);
    ms_delay(ms);
}

/* [] END OF FILE */
