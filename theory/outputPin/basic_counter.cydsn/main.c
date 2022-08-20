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

/*CY_ISR( Counter_Int_Handler )
{
    led_blue_Write( ~led_blue_Read() );
    
    Counter_ClearInterrupt( Counter_INTR_MASK_TC );
}*/


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    gnd_Write(0);
    
    /*
    Counter_Start();
    Counter_Int_StartEx( Counter_Int_Handler );     
    */
    
    PWM_Start();
    
    for(;;)
    {
        /* Place your application code here. */   
        PWM_WriteCompare( 500 );
        CyDelay( 1000);
        PWM_WriteCompare( 9500 );
        CyDelay( 1000);             
    }
}


/* [] END OF FILE */
