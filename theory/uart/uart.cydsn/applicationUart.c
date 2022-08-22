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
#include "applicationUart.h"


void printNumber(int number)
{
    char strings[30];
    
    sprintf(strings, "%d\n", number);
    
    uart_UartPutString(strings);    
} 

void printNumberIncrement()
{
    char strings[30];
    static int number = 10;
    
    number++;
    if(number > 15)
        number = 5;   
    
    sprintf(strings, "%d\n", number);
    
    uart_UartPutString(strings); 
}



/* [] END OF FILE */
