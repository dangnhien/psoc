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

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    configSystem();

    for(;;)
    {
        display();
    }
}

void configSystem()
{
    lcd_Start();    
    
    lcd_Position(0u,0u);
    lcd_PrintString("Hello world.");
    lcd_Position(1u,0u);
    lcd_PrintString("I am Dat.");
    CyDelay(10000);
    lcd_ClearDisplay();
}

void display()
{
    lcd_Position(0u,0u);
    lcd_PrintString("lcd 16x2");
}


/* [] END OF FILE */
