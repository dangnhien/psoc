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

#include "eeprom.h"

void eeprom_Init()
{
    i2c_Start();
}

/*
void eeprom_Write_Single_Byte(uint8 address, uint8 data)
{
    i2c_Start();
    
    //i2c_I2CMasterStatus( i2c_I2C_MSTAT_WR_CMPLT );
    
    
        
}
*/


/* [] END OF FILE */
