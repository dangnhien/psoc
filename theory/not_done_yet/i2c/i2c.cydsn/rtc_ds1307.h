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
#ifndef RTC_DS1307_H
#define RTC_DS1307_H
    
    #ifndef PROJECT_H
    #define PROJECT_H
        #include "project.h" 
    #endif   
    
    #include <stdio.h>
    
    #define DS1307_I2C_ADDR         0x68
    #define DS1307_REG_SECOND       0x00
    #define DS1307_REG_MINUTE       0x01
    #define DS1307_REG_HOUR         0x02
    #define DS1307_REG_DOW          0x03
    #define DS1307_REG_DATE         0x04
    #define DS1307_REG_MONTH        0x05
    #define DS1307_REG_YEAR         0x06
    #define DS1307_REG_CONTROL      0x07
    #define DS1307_REG_UTC_HR       0x08
    #define DS1307_REG_UTC_MIN      0x09
    #define DS1307_REG_CENT         0x10
    #define DS1307_TIMEOUT          1000
    
    typedef struct 
    {
        uint8_t sec;
        uint8_t min;
        uint8_t hour;
        uint8_t dayWeek;
        uint8_t date;
        uint8_t month;
        uint16_t year;
    }ds1307_struct;
    
    
    void readRtc();
    
    void writeRtc();
    
    
    
    
   
    

#endif

/* [] END OF FILE */
