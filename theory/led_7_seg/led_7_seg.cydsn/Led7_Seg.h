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
    #ifndef LED7_SEG_H
    #define LED7_SEG_H
        
        #include <stdio.h>
        #include "project.h"        
        
        enum Status_pin
        {
            low = 0,
            hight
        };

        void scanLed();
        void check_Led_Live_Or_Die(uint8 location, uint8 data);
        
    
    #endif

/* [] END OF FILE */
