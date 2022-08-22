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

void initSystem();

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    uint8 commpare = 0;    
    uint8 i2cBuffer[1];
    
    i2cBuffer[0] = 0;
    
    initSystem();
    
    i2c_user_EzI2CSetBuffer1(1, 1, i2cBuffer); 

    for(;;)
    {
        /* Place your application code here. */
        if(commpare != i2cBuffer[0])
        {
            commpare = i2cBuffer[0];
        }        
    }
}

void initSystem()
{
       i2c_user_Start();
}

/* [] END OF FILE */
