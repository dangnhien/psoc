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
#include "project.h"
#include "ledSingle.h"

void lightIncrement()
{
    static unsigned int compear_value = 0;
    compear_value += 1000;
    if(compear_value>=20000)
        compear_value = 0;
      
    pwm_WriteCompare(compear_value);
}

/* [] END OF FILE */
