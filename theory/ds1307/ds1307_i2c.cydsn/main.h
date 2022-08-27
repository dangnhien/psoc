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
        
        #include "project.h"
        #include "ds1307.h"
        #include "uart.h"
        
        enum _StatusButton
        {
            Button_Pressed,
            Button_Releace
        };        
        
        
        void system_Initialization();
        void init_Timer_Start(data_time *time);
        
        
    
    #endif

/* [] END OF FILE */
