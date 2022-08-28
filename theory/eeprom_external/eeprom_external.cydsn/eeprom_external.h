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
    #ifndef EEPROM_EXTERNAL
    #define EEPROM_EXTERNAL
        
        #include "project.h"
        
        //0 1010 B2B1B0 --> B2=B1=B0=0 --> 0101 000 --> 0x50
        #define EEPROM_ADDRESS 0x50 
        
        uint8 find_address_eeprom();
        
        uint8 eeprom_read_a_byte(uint8 address_read);
        void eeprom_read_page(uint8 address, uint8 *data_read, uint8 length);
        
        void eeprom_write_a_byte(uint8 address, uint8 data_nedd_write);
        void eeprom_write_page(uint8 address, uint32 *data_need_write, uint8 length);
        
        
    #endif




/* [] END OF FILE */
