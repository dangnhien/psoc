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
    
    #ifndef PROJECT_H
    #define PROJECT_H
        #include "project.h"
    #endif
    
    #include <stdio.h>    
    
    void Init_System();
    
    float readADC();
    
    void transmitToPC(float adcData);
    
#endif

/* [] END OF FILE */
