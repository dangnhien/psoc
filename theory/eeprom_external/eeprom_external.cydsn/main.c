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

    system_init();

    for(;;)
    {
        /* Place your application code here. */
    }
}

void system_init()
{
    i2c_Start();
    
    
}

/* [] END OF FILE */
