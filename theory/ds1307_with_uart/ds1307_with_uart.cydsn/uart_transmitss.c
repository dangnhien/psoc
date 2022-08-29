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
#include "uart_transmitss.h"

void time_string_concatenation(data_time time, char *strings)
{
    char dayInWeek[10];
    
    switch(time.day)
    {
        case Sun:
            strcpy(dayInWeek, "Sun");  
            break;
        case Mon:
            strcpy(dayInWeek, "Mon");  
            break;            
        case Tue:
            strcpy(dayInWeek, "Tue");  
            break;   
        case Web:
            strcpy(dayInWeek, "Wed");  
            break;    
        case Thur:
            strcpy(dayInWeek, "Thur");  
            break; 
        case Fri:
            strcpy(dayInWeek, "Fri");  
            break;
        case Sat:
            strcpy(dayInWeek, "Sat");  
            break;  
        default:
             strcpy(dayInWeek, "Error!");  
    }
    
    sprintf(strings, "\n%d%c%d%c%d  %s, %d%c%d%c%d",time.hour, ':', time.minute, ':', time.second, \
        dayInWeek, time.date, '/', time.month, '/', 2000 + time.year );
    
    return;
}

void test_uart_transmit()
{
    data_time time;
    char txString[50];
    
    time.second = 15;
    time.minute = 15;
    time.hour = 15;
    time.day = 15;
    time.date = 15;
    time.month = 15;
    time.year = 15;
    
    time_string_concatenation(time, txString);
    uart_transmit_UartPutString( txString );    
    
    CyDelay(1000);
}



/* [] END OF FILE */
