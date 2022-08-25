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

    configSystem();
        
    for(;;)
    {
        /* Place your application code here. */
        receive_After_Transmit_Char_Type(); 
        //  receive_After_Transmit_String();
        CyDelay(1000);
    }
}

void configSystem()
{
       uart_Start();
}

void uartHandle()
{
    printNumberIncrement();
    CyDelay(1000);
}


/* [] END OF FILE */
