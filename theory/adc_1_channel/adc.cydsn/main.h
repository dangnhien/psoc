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
    
    #include <stdio.h>
    #include "project.h"

    void Init_System();
    float readADC();
    void transmitToPC(float adcData);
    
    float readLM35();
    
#endif

/* [] END OF FILE */
