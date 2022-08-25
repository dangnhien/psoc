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
#include "ds1308.h"

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

void ds1307_read_data(data_time *time)
{
    uint8 result, i;    
    data_time tempTime;
    
    // Start read slave ds1307
    do{
        result = i2c_master_I2CMasterSendStart(ADDRESS_SLAVE_DS1307, i2c_master_I2C_WRITE_XFER_MODE, 10);
    }while(result != i2c_master_I2C_MSTR_NO_ERROR);
    
    result = i2c_master_I2CMasterWriteByte(0x00, 10);
    
    result = i2c_master_I2CMasterSendRestart(ADDRESS_SLAVE_DS1307, i2c_master_I2C_READ_XFER_MODE, 10);
    
    result = i2c_master_I2CMasterReadByte(i2c_master_I2C_ACK_DATA, &(tempTime.second) , 10);
    result = i2c_master_I2CMasterReadByte(i2c_master_I2C_ACK_DATA, &(tempTime.minute) , 10);
    result = i2c_master_I2CMasterReadByte(i2c_master_I2C_ACK_DATA, &(tempTime.hour) , 10);
    result = i2c_master_I2CMasterReadByte(i2c_master_I2C_ACK_DATA, &(tempTime.day) , 10);
    result = i2c_master_I2CMasterReadByte(i2c_master_I2C_ACK_DATA, &(tempTime.date) , 10);
    result = i2c_master_I2CMasterReadByte(i2c_master_I2C_ACK_DATA, &(tempTime.month) , 10);
    result = i2c_master_I2CMasterReadByte(i2c_master_I2C_NAK_DATA, &(tempTime.year) , 10);

    result = i2c_master_I2CMasterSendStop(10); 
    // Finist read slave ds1307

    time->second = BCD_to_DEC(tempTime.second);
    time->minute = BCD_to_DEC(tempTime.minute);
    time->hour = BCD_to_DEC(tempTime.hour);
    time->day = BCD_to_DEC(tempTime.day);
    time->date = BCD_to_DEC(tempTime.date);
    time->month = BCD_to_DEC(tempTime.month);
    time->year = BCD_to_DEC(tempTime.year);   
}


void ds1307_write_data(data_time *time)
{
    uint8 result, i;
    data_time tempTimer;
    
    tempTimer.second = DEC_to_BCD(time->second);
    tempTimer.minute = DEC_to_BCD(time->minute);
    tempTimer.hour = DEC_to_BCD(time->hour);
    tempTimer.day = DEC_to_BCD(time->day);
    tempTimer.date = DEC_to_BCD(time->date);
    tempTimer.minute = DEC_to_BCD(time->minute);
    tempTimer.year = DEC_to_BCD(time->year);   
    
    // Start write data to slave ds1307
    do{
        result = i2c_master_I2CMasterSendStart(ADDRESS_SLAVE_DS1307, i2c_master_I2C_WRITE_XFER_MODE, 10);
    }while(result != i2c_master_I2C_MSTR_NO_ERROR);
    
    result = i2c_master_I2CMasterWriteByte((uint8)0x00, 10);
    
    result =  i2c_master_I2CMasterWriteByte(tempTimer.second, 10);
    result =  i2c_master_I2CMasterWriteByte(tempTimer.second, 10);
    result =  i2c_master_I2CMasterWriteByte(tempTimer.second, 10);
    result =  i2c_master_I2CMasterWriteByte(tempTimer.second, 10);
    result =  i2c_master_I2CMasterWriteByte(tempTimer.second, 10);
    result =  i2c_master_I2CMasterWriteByte(tempTimer.second, 10);
    result =  i2c_master_I2CMasterWriteByte(tempTimer.second, 10);
    
    i2c_master_I2CMasterSendStop(10);
    // Finish write data to slave ds1307
}





/* [] END OF FILE */
