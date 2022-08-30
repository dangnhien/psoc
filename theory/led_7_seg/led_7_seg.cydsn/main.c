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


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */


    for(;;)
    {
        scanLed(7896);
    }
}
    


/* [] END OF FILE */


