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

    #ifndef MAIN_H
    #define MAIN_H
        
        enum _StatusButton
        {
            Button_Pressed,
            Button_Releace
        };
        
        #include "project.h"
        #include "ds1308.h"
        #include "uart.h"
        
        void system_initialization();
    
    #endif

/* [] END OF FILE */
