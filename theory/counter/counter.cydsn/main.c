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

CY_ISR( timer_counter_Int_Handler )
{
    ledRedd_Write( ~ledRedd_Read() );
    
    timer_counter_ClearInterrupt( timer_counter_INTR_MASK_TC);
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    timer_counter_Start();
    timer_counter_Int_StartEx( timer_counter_Int_Handler );

    for(;;)
    {
        
    }
}


/* [] END OF FILE */
