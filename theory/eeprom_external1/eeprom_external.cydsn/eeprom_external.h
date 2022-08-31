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
    
    uint8 find_address_eeprom();
    
    uint8 eeprom_read_a_byte( unsigned long  address_read);
    void eeprom_read_page(uint8 address, uint8 *data_read, uint8 length);
    
    
    void eeprom_write_a_byte_08(uint32 address, uint8 data_need_write);
    void eeprom_write_a_byte_128(uint32 address, uint8 data_need_write);
    
    
    void eeprom_write_page(uint8 address, uint32 *data_need_write, uint8 length);
      
#endif




/* [] END OF FILE */
