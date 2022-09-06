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
#ifndef UART_TRANSMITSS_H
#define UART_TRANSMITSS_H
    
    #include <cytypes.h>
    #include "ds1307_i2c.h"  
   
    void time_string_concatenation(data_time time, char *strings);
    void test_uart_transmit();

#endif

/* [] END OF FILE */
