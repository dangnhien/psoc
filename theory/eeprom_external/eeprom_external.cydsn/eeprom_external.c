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

#include "eeprom_external.h"


/*
    Random a byte read
*/
uint8 eeprom_read_a_byte(uint8 address_read)
{
    uint8 data_read;
    uint8 result = 0;
    
    do{
        result = i2c_I2CMasterSendStart(EEPROM_ADDRESS, i2c_I2C_WRITE_XFER_MODE, 1);
    }while(result != i2c_I2C_MSTR_NO_ERROR);
    
    i2c_I2CMasterWriteByte( (uint32)address_read, 1 );
    
    i2c_I2CMasterSendRestart(EEPROM_ADDRESS, i2c_I2C_READ_XFER_MODE, 1);
    
    i2c_I2CMasterReadByte( i2c_I2C_NAK_DATA, &data_read , 1);
    
    i2c_I2CMasterSendStop(5);
    
    return data_read;
}


/*
   Sequential( page) read
*/
void eeprom_read_page(uint8 address, uint8 *data_read, uint8 length)
{
    uint8 result = 0, i;
    
    do{
        result = i2c_I2CMasterSendStart(EEPROM_ADDRESS, i2c_I2C_WRITE_XFER_MODE, 1);
    }while(result != i2c_I2C_MSTR_NO_ERROR);
    
     i2c_I2CMasterWriteByte( (uint32)address, 1 );
    
    i2c_I2CMasterSendRestart(EEPROM_ADDRESS, i2c_I2C_READ_XFER_MODE, 1);
    
    for(i=0; i<length-1; i++)
    {
         i2c_I2CMasterReadByte( i2c_I2C_ACK_DATA, &data_read[i] , 1);
    }
    i2c_I2CMasterReadByte( i2c_I2C_NAK_DATA, &data_read[i] , 1);
    
    i2c_I2CMasterSendStop(5);
}

void eeprom_write_a_byte(uint8 address, uint8 data_nedd_write)
{
    uint8 result = 0;
    
    do{
        result = i2c_I2CMasterSendStart(EEPROM_ADDRESS, i2c_I2C_WRITE_XFER_MODE, 1);
    }while(result != i2c_I2C_MSTR_NO_ERROR);
    
    i2c_I2CMasterWriteByte( (uint32)address, 1 );
    i2c_I2CMasterWriteByte( (uint32)data_nedd_write, 1 );
    
    i2c_I2CMasterSendStop(5);
}

void eeprom_write_page(uint8 address, uint32 *data_need_write, uint8 length)
{
    uint8 result = 0, i;
     do{
        result = i2c_I2CMasterSendStart(EEPROM_ADDRESS, i2c_I2C_WRITE_XFER_MODE, 1);
    }while(result != i2c_I2C_MSTR_NO_ERROR);
    
    i2c_I2CMasterWriteByte( (uint32)address, 1 );
    
    for(i=0; i<length; i++)
         i2c_I2CMasterWriteByte( data_need_write[i], 1 );
        
    i2c_I2CMasterSendStop(5);
}

uint8 find_address_eeprom()
{
    uint8 result = 0;
    uint8 address = 0x4F;   //0x50-1
    do{
        address++;
        result = i2c_I2CMasterSendStart(address, i2c_I2C_WRITE_XFER_MODE, 1);
    }while(result != i2c_I2C_MSTR_NO_ERROR);
    
    return address;
}

/* [] END OF FILE */
