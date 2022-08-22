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

    void ledTurnOff(int digit)
    {
        switch(digit)
        {
            case 1:
                ledBlue_Write(1);
                break;
            case 2:
                ledGreen_Write(1);
                break;
            case 3:
                ledRed_Write(1);
                break;
            case 4:
                ledYellow_Write(1);
                break;
        }
    }


    void ledTurnOn(int digit)
    {
        switch(digit)
        {
            case 1:
                ledBlue_Write(0);
                break;
            case 2:
                ledGreen_Write(0);
                break;
            case 3:
                ledRed_Write(0);
                break;
            case 4:
                ledYellow_Write(0);
                break;
        }
    }

/* [] END OF FILE */
