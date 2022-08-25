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
    #include "rtc_ds1307.h"
    
    
    int BCD_Convert_DEC(int BCD)
    {
        int low, hight;
        low = BCD & 0x0F;
        hight = (BCD>>4)*10;
        return (hight+low);
    }
    
    int DEC_Convert_BCD(int DEC)
    {
        int low, hight;
        low = DEC%10;
        hight = (DEC/10)<<4;
        return (hight+low);
    }
    
    //void dislayTime(int hour, int minute, int second, int dayOfWeek, int day, int month, int year)
    void dislayTime(ds1307_struct rtc)
    {
        char time[25] = {'\0'};
        char dayOfWeeks[4] = {'\0'};
        
        switch(rtc.dayWeek)
        {
            case 1:
                strcpy(dayOfWeeks, "Sun\0");
                break;
            case 2: 
                strcpy(dayOfWeeks, "Mon\0");
                break;
            case 3: 
                strcpy(dayOfWeeks, "Tue\0");
                break;                
            case 4: 
                strcpy(dayOfWeeks, "Web\0");
                break;
            case 5: 
                strcpy(dayOfWeeks, "Thu\0");
                break;
            case 6: 
                strcpy(dayOfWeeks, "Fri\0");
                break;
            case 7: 
                strcpy(dayOfWeeks, "Sat\0");
                break;                           
        }
            
        
        sprintf(time, "%d%c%d%c%d %c %s %c %d%c%d%c%d", rtc.hour, ':', rtc.min, ':', rtc.sec, ' ',dayOfWeeks, ' ', rtc.date, '/', rtc.month, '/', rtc.year);
        
        uart_UartPutString( time );
    }
    
    void readRtc()
    {
         
    }
    
    void writeRtc(ds1307_struct rtc)
    {
        uint8 rxData[9] = {'\0'};
        
        rxData[0] = 0;
        rxData[1] = DEC_Convert_BCD(rtc.sec);
        rxData[2] = DEC_Convert_BCD(rtc.min);
        rxData[3] = DEC_Convert_BCD(rtc.hour);  //24h mode
        rxData[4] = DEC_Convert_BCD(rtc.dayWeek);
        rxData[5] = DEC_Convert_BCD(rtc.date);
        rxData[6] = DEC_Convert_BCD(rtc.month);
        rxData[7] = DEC_Convert_BCD(rtc.year);
        rxData[8] = '\0';    
        
        i2c_I2CMasterWriteBuf(0xD0>>1, rxData, 8, i2c_I2C_MODE_COMPLETE_XFER );   
    }
    
    

/* [] END OF FILE */
