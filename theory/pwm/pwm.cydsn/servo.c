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
#include "servo.h"

void from90DegreeTo180Degree(int *value_compare)
{
    (*value_compare == 1000) ? (*value_compare = 2000) : (*value_compare = 1000);
    
    pwm_WriteCompare(*value_compare);
}

void from0DegreeTo180Degree(int *value_compare)
{
    (*value_compare == 900) ? (*value_compare = 2000) : (*value_compare = 900);
    
    pwm_WriteCompare(*value_compare);
}

// Location 180 degree of circle
void location0Degree()
{
    int value_compare = 900;
    
    pwm_WriteCompare(value_compare);
}

// Location 90 degree of circle
void location90Degree()
{
    int value_compare = 1500;
    
    pwm_WriteCompare(value_compare);
}

// Location 0 degree of circle
void location180Degree()
{
    int value_compare = 2000;
    
    (value_compare);
}






/* [] END OF FILE */
