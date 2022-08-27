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
    #ifndef MATRIX_H
    #define MATRIX_H
        
    #include "project.h"        
        
    enum  row_or_column
    {
        row=0,
        column
    };
    
    enum Status_pin
    {
        low = 0,
        hight
    };
	
	
    void light_character_k(int k);
    void light_from_0_to_9();
    
    #endif
/* [] END OF FILE */
