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

CY_ISR(SwitchInterrupt)
{
    CyDelay(50);
    Pin_Led_Write(OFF);
    while(Pin_Led_Read() == PRESSED);
    CyDelay(50);
    Pin_Led_Write(ON);
    Pin_Switch_ClearInterrupt();
    Sw_Isr_ClearPending();
    
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    Config_System(); 

    for(;;)
    {
        /* Place your application code here. */
        CySysPmDeepSleep();
    }
}

void Config_System()
{
    Sw_Isr_StartEx( SwitchInterrupt );
}



/* [] END OF FILE */
