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
#include "ds1307_i2c.h"


uint8 BCD_to_DEC(uint8 data);
uint8 DEC_to_BCD(uint8 data);

uint8 BCD_to_DEC(uint8 data)
{
	return (data>>4)*10 + (data&0x0f);
}

uint8 DEC_to_BCD(uint8 data)
{
	return (data/10)<<4 | (data%10);
}

/*
    - Dựa vào bảng Timekeeper registers, chúng ta sẽ thấy thanh ghi second có bit 7 CH (dùng để tạm dừng dao động), 
    chúng ta sẽ không đọc bit này nên sẽ cần biểu thức ( temp[0] & 0x7F ) để loại đi bit 7 này.

    - Thanh ghi hour có bit 6 để chọn chế độ 12/24h, nếu bit 6 = 1, chế độ 12h sẽ được chọn. 
    Chúng ta sẽ không đọc bit 6 nên cần biểu thức temp[0] & 0x3F để loại bit 6 này.
*/
void ds1307_read_data(data_time *time)
{
    uint8 result, i;    
    uint8 temp[8];
    
    do{
        result = i2c_ds1307_I2CMasterSendStart(ADDRESS_SLAVE_DS1307, i2c_ds1307_I2C_WRITE_XFER_MODE, 1);
    }while(result != i2c_ds1307_I2C_MSTR_NO_ERROR);
    
    i2c_ds1307_I2CMasterWriteByte(0x00, 1);
    
    i2c_ds1307_I2CMasterSendRestart(ADDRESS_SLAVE_DS1307, i2c_ds1307_I2C_READ_XFER_MODE, 1);
    
    for(i=0; i<6; i++)
        i2c_ds1307_I2CMasterReadByte( i2c_ds1307_I2C_ACK_DATA, &temp[i] , 1);
        
    i2c_ds1307_I2CMasterReadByte( i2c_ds1307_I2C_NAK_DATA, &temp[i] , 1);
    
   i2c_ds1307_I2CMasterSendStop(1); 
    
    // Convert BCD to DEC
    time->second = BCD_to_DEC(temp[0] & 0x7F);
    time->minute = BCD_to_DEC(temp[1]);
    time->hour = BCD_to_DEC(temp[2] & 0x3F); // 24h mode
    time->day = BCD_to_DEC(temp[3]);
    time->date = BCD_to_DEC(temp[4]);
    time->month = BCD_to_DEC(temp[5]);
    time->year = BCD_to_DEC(temp[6]);     
}


void ds1307_write_data(data_time *time)
{
    uint8 result, i;
    uint32 temp[8];
    
    // Convert DEC to BCD
    temp[0] = DEC_to_BCD(time->second);
    temp[1] = DEC_to_BCD(time->minute);
    temp[2] = DEC_to_BCD(time->hour);
    temp[3] = DEC_to_BCD(time->day);
    temp[4] = DEC_to_BCD(time->date);
    temp[5] = DEC_to_BCD(time->minute);
    temp[6] = DEC_to_BCD(time->year);   
    
    do{
        result = i2c_ds1307_I2CMasterSendStart(ADDRESS_SLAVE_DS1307, i2c_ds1307_I2C_WRITE_XFER_MODE, 1);
    }while(result != i2c_ds1307_I2C_MSTR_NO_ERROR);
    
   i2c_ds1307_I2CMasterWriteByte((uint32)0x00, 1);
    
    for(i=0; i<=6; i++)
    {
        i2c_ds1307_I2CMasterWriteByte(temp[i], 1);
    }
    
    i2c_ds1307_I2CMasterSendStop(5);
}

void ds1307_time_init(data_time *time)
{
    time->second = 12;
    time->minute = 12;
    time->hour = 12;
    time->day = 1;
    time->date = 29;
    time->month = 8;
    time->year = 22;
}


/* [] END OF FILE */
