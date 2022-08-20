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

void led_glow(uint8 status_1);


//press button to born interrupt
CY_ISR( Pin_SW2_Handler )
{
    led_blue_Write( ~led_blue_Read() );
    
    Pin_SW2_ClearInterrupt();
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    //gnd_Write(0);
    Pin_SW2_Int_StartEx( Pin_SW2_Handler );
    
    for(;;)
    {
        /* Place your application code here. */  
        
        /*
        uint8 result = Pin_SW2_Read();
        
        led_glow(result);  
        */
    }
}

/* press button,led will glow */
void led_glow(uint8 status_1)
{
    status_1 == 0 ?  led_blue_Write(0) : led_blue_Write(1) ;
}


/* [] END OF FILE */
