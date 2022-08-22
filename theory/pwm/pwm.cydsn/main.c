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
    
    configSystem();
    
    //int compare_value = 1000;

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        /* Place your application code here. */
        //from0DegreeTo180Degree( &compare_value );
        
        lightIncrement();
        CyDelay(200);
    }
}


void configSystem()
{
    pwm_Start();
}

/* [] END OF FILE */
