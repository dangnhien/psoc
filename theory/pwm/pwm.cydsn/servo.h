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

    #ifndef SERVO_H
    #define SERVO_H
        
        #ifndef PROJECT_H
        #define PROJECT_H
        
            #include "project.h"
            
        #endif
        
        void from0DegreeTo180Degree(int *value_compare);
        void from90DegreeTo180Degree(int *value_compare);        
        
        void location0Degree();
        void location90Degree();
        void location180Degree();     
          
    #endif

/* [] END OF FILE */
