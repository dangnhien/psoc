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
#include "uart.h"

void time_string_concatenation(data_time time, char *strings)
{
    char dayInWeek[4];
    
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
    }
    
    sprintf(strings, "%d%c%d%c%d %c%s %d%c%d%c%d",time.hour, ':', time.minute, ':', time.second, '\n' , \
        dayInWeek, time.date, '/', time.month, '/', time.year );
}
/* [] END OF FILE */
