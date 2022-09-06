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
uint8 eeprom_read_a_byte( uint32  address_read)
{
    uint8 data_read,  result = 0, i, find_OK = not_found;
    /*
    Replaced by for loop below
        do{
            result = i2c_I2CMasterSendStart(EEPROM_ADDRESS, i2c_I2C_WRITE_XFER_MODE, 1);
        }while(result != i2c_I2C_MSTR_NO_ERROR);
    */
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
        return 0;
    
    
    i2c_I2CMasterWriteByte( address_read, 1 );
    
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

//eeprom 24c128 --> error
void eeprom_write_a_byte_128(uint32 address, uint8 data_need_write)
{
    uint8 result = 0;
    
    do{
        result = i2c_I2CMasterSendStart(EEPROM_ADDRESS, i2c_I2C_WRITE_XFER_MODE, 1);
    }while(result != i2c_I2C_MSTR_NO_ERROR);
    
    i2c_I2CMasterWriteByte( (int)(address >> 8), 1 );   //MSB
    
    i2c_I2CMasterWriteByte( (int)(address & 0xff) , 1 );    //LSB
    
    i2c_I2CMasterWriteByte( data_need_write, 1 );
    
    i2c_I2CMasterSendStop(5);
}

//eeprom 24c08
void eeprom_write_a_byte_08(uint32 address, uint8 data_need_write)
{
    uint8 result = 0,i, find_OK = not_found;
    
    /*
    Replaced by for loop below
        do{
            result = i2c_I2CMasterSendStart(EEPROM_ADDRESS, i2c_I2C_WRITE_XFER_MODE, 1);
        }while(result != i2c_I2C_MSTR_NO_ERROR);
    */
    
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
/*
    removal reason: unrealistic!!!!
uint8 find_address_eeprom()
{
    static int counter=0;
    uint8 result = 0;
    static uint8 address = 0x40;   //0x50-1
    
    do{
        counter++;
        result = i2c_I2CMasterSendStart(address, i2c_I2C_WRITE_XFER_MODE, 1);
    }while( (result != i2c_I2C_MSTR_NO_ERROR) && (counter<=5) );
    
    counter = 0;
   
    if( result != i2c_I2C_MSTR_NO_ERROR )
        return address;
    else 
    {
        address++;
        return 0x01; 
    }
}
*/

/* [] END OF FILE */
