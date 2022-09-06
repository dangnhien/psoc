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

#include "servo.h"
#include "ledSingle.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    configSystem();
    
    for(;;)
    {
        location0Degree();
    }
}


void configSystem()
{
    pwm_Start();
}




/* [] END OF FILE */
