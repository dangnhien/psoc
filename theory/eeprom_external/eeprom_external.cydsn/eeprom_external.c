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
#include "project.h"
#include <stdio.h>

enum Status_Eeprom
{
    not_found,
    find
};

#include "eeprom_external.h"

//0 1010 B2B1B0 --> B2=B1=B0=0 --> 0101 000 --> 0x50
#define EEPROM_ADDRESS 0x50

/*
    Random a byte read
*/
uint8 eeprom_read_a_byte_08( uint32  address_read)
{
    uint8 data_read,  result = 0;
    
    do{
        result = i2c_I2CMasterSendStart(EEPROM_ADDRESS, i2c_I2C_WRITE_XFER_MODE, 1);
    }while(result != i2c_I2C_MSTR_NO_ERROR);
    

    i2c_I2CMasterWriteByte( address_read, 1 );
    
    i2c_I2CMasterSendRestart(EEPROM_ADDRESS, i2c_I2C_READ_XFER_MODE, 1);
    
    i2c_I2CMasterReadByte( i2c_I2C_NAK_DATA, &data_read , 1);
    
    i2c_I2CMasterSendStop(5);
    
    return data_read;
}


/*
   Sequential( page) read
*/
void eeprom_read_page_08(uint8 address, uint8 *data_read, uint8 length)
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


//eeprom 24c08
void eeprom_write_a_byte_08(uint32 address, uint8 data_need_write)
{
    uint8 result = 0,i, find_OK = not_found;
    
    for(i=0; i<3; i++)
    {
        result = i2c_I2CMasterSendStart(EEPROM_ADDRESS, i2c_I2C_WRITE_XFER_MODE, 1);
        
        if(result == i2c_I2C_MSTR_NO_ERROR) 
        {
            find_OK = find;
            break;
        }
    }
    if(find_OK == not_found)
        return;
    
    
    i2c_I2CMasterWriteByte( address , 1 );
    
    i2c_I2CMasterWriteByte( data_need_write, 1 );
    
    i2c_I2CMasterSendStop(5);
    
    return;
}
void eeprom_write_page_08(uint8 address, uint32 *data_need_write, uint8 length)
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

//==============================Eeprom 24c256======================================

//Random Read 
uint8 eeprom_read_a_byte_256( uint32  address_read)
{
    uint8 data_read,  result = 0;
    
    do{
        result = i2c_I2CMasterSendStart(EEPROM_ADDRESS, i2c_I2C_WRITE_XFER_MODE, 5);
    }while(result != i2c_I2C_MSTR_NO_ERROR);
    

     i2c_I2CMasterWriteByte( (address_read >> 8), 5 );   //MSB
    
    i2c_I2CMasterWriteByte( (address_read & 0xff) , 5 );    //LSB
    
    i2c_I2CMasterSendRestart(EEPROM_ADDRESS, i2c_I2C_READ_XFER_MODE, 1);
    
    i2c_I2CMasterReadByte( i2c_I2C_NAK_DATA, &data_read , 5);
    
    i2c_I2CMasterSendStop(5);
    
    return data_read;
}

//Sequential Read
void eeprom_read_page_256(uint8 address, uint8 *data_read, uint8 length)
{
     uint8 result = 0, i;
    
    do{
        result = i2c_I2CMasterSendStart(EEPROM_ADDRESS, i2c_I2C_WRITE_XFER_MODE, 5);
    }while(result != i2c_I2C_MSTR_NO_ERROR);
    

     i2c_I2CMasterWriteByte( (address >> 8), 5 );   //MSB
    
    i2c_I2CMasterWriteByte( (address & 0xff) , 5 );    //LSB
    
    i2c_I2CMasterSendRestart(EEPROM_ADDRESS, i2c_I2C_READ_XFER_MODE, 1);
    
    for(i=0; i< length; i++)
    {
        if(i!= (length-1))
            i2c_I2CMasterReadByte( i2c_I2C_ACK_DATA, &data_read[i] , 5);
        else
            i2c_I2CMasterReadByte( i2c_I2C_NAK_DATA, &data_read[i] , 5);
    }
    
    i2c_I2CMasterSendStop(5);
}

void eeprom_write_a_byte_256(uint32 address, uint8 data_need_write)
{
    uint8 result = 0;
    
    do{
        result = i2c_I2CMasterSendStart(EEPROM_ADDRESS, i2c_I2C_WRITE_XFER_MODE, 5);
    }while(result != i2c_I2C_MSTR_NO_ERROR);
    
    i2c_I2CMasterWriteByte( (address >> 8), 5 );   //MSB
    
    i2c_I2CMasterWriteByte( (address & 0xff) , 5 );    //LSB
    
    i2c_I2CMasterWriteByte( data_need_write, 5 );
    
    i2c_I2CMasterSendStop(5);
}

void eeprom_write_page_256(uint8 address, uint32 *data_need_write, uint8 length)
{
    uint8 result = 0, i;
    
    do{
        result = i2c_I2CMasterSendStart(EEPROM_ADDRESS, i2c_I2C_WRITE_XFER_MODE, 5);
    }while(result != i2c_I2C_MSTR_NO_ERROR);
    
    i2c_I2CMasterWriteByte( (address >> 8), 5 );   //MSB
    
    i2c_I2CMasterWriteByte( (address & 0xff) , 5 );    //LSB
    
    for(i=0; i<length; i++)
        i2c_I2CMasterWriteByte( data_need_write[i], 5 );
    
    i2c_I2CMasterSendStop(5);
}



/* [] END OF FILE */
