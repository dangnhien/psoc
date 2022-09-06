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

void ledTurnOff(int digit)
{
    switch(digit)
    {
        case 1:
            ledBlue_Write(TURN_OFF);
            break;
        case 2:
            ledGreen_Write(TURN_OFF);
            break;
        case 3:
            ledRed_Write(TURN_OFF);
            break;
        case 4:
            ledYellow_Write(TURN_OFF);
            break;
    }
}

void ledTurnOn(int digit)
{
    switch(digit)
    {
        case 1:
            ledBlue_Write(TURN_ON);
            break;
        case 2:
            ledGreen_Write(TURN_ON);
            break;
        case 3:
            ledRed_Write(TURN_ON);
            break;
        case 4:
            ledYellow_Write(TURN_ON);
            break;
    }
}

/* [] END OF FILE */
