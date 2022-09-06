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

#include "ledSingle.h"

enum Status_Led
{
    TURN_ON,
    TURN_OFF
};

void ledBlink()
{
    ledRed_Write( ~ledRed_Read());
    CyDelay(300);
}

void ledTurnOn()
{
    ledRed_Write(TURN_ON);
}

void ledTurnOff()
{
    ledRed_Write(TURN_OFF);    
}

/* [] END OF FILE */
