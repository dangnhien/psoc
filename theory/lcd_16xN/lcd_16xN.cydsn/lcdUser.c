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

#include "lcdUser.h"

void displayString(char8 const *strings)
{
    lcd_Position(0,0);
    lcd_PrintString(strings);
}





/* [] END OF FILE */
