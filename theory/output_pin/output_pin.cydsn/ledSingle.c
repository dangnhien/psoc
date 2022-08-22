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
#include "ledSingle.h"

void ledBlink()
{
    ledRed_Write( ~ledRed_Read());
    CyDelay(300);
}

void ledTurnOn()
{
    ledRed_Write(0);
}

void ledTurnOff()
{
    ledRed_Write(1);    
}

/* [] END OF FILE */
