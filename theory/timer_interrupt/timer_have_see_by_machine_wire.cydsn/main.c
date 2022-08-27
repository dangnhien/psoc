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

void dem_counter();


CY_ISR(handle_interrupt)
{
    Pin_Led_Write( ~ Pin_Led_Read());
    
    timer1_ClearInterrupt( timer1_INTR_MASK_TC );  // clear timer  
    timer_int_ClearPending();   // clear interrupt timer
}


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    timer1_Start();
    timer_int_StartEx(handle_interrupt);

    for(;;)
    {
        /* Place your application code here. */
    }
}


/* [] END OF FILE */
