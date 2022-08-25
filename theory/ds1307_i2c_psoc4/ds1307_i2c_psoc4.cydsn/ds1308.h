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
#ifndef DS1307_H
#define DS1307_H
    
    #include "project.h"
    #include <stdio.h>
    
    typedef struct DataTime
    {
        uint8 second, minute, hour, day, date, month, year;
    }data_time;
    
    enum DayOfWeek
    {
        Sun = 1,
        Mon, 
        Tue,
        Web,
        Thur,
        Fri,
        Sat
    };    
    
    #define ADDRESS_SLAVE_DS1307 0x68
    
    void ds1307_read_data(data_time *time);
    void ds1307_write_data(data_time *time);
    
#endif

        


/* [] END OF FILE */
