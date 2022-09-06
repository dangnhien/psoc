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
#include "main.h"
#include "applicationUart.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    configSystem();
        
    for(;;)
    {
        receive_After_Transmit_Char_Type(); 
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
