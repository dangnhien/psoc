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

#include "buttonBlack.h"
#include "ledSingle.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    gnd_Write(0);

    for(;;)
    {
        buttonHandle();
    }
}

void buttonHandle()
{
    ledTurnOn( valuePressedButton() );
    CyDelay(2000);
    ledTurnOff( valuePressedButton() );  
    CyDelay(2000);
}

/* [] END OF FILE */
