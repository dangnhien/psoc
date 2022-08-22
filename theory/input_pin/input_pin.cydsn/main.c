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

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    gnd_Write(0);

    for(;;)
    {
        /* Place your application code here. */
        buttonHandle();
    }
}

void buttonHandle()
{
    
    ledTurnOn( valuePressButton() );
    
    CyDelay(2000);
    
    ledTurnOff( valuePressButton() );    
}

/* [] END OF FILE */
