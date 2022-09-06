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
#include "servo.h"

/*
    20ms  --> 0.02s  --> 50Hz --> clock 50kHz
                              --> period 1000
                              --> compear 500 --> 500/1000 = 50%
*/
void from90DegreeTo180Degree(int *value_compare)
{
    (*value_compare == 75) ? (*value_compare = 100) : (*value_compare = 75);
    
    pwm_WriteCompare(*value_compare);
}

void from0DegreeTo180Degree(int *value_compare)
{
    (*value_compare == 50) ? (*value_compare = 100) : (*value_compare = 50);
    
    pwm_WriteCompare(*value_compare);
}
/*
    Location 180 degree of circle:
    1ms of 20ms --> (1/20)*period = (1/20)*1000 = 50;
*/
void location0Degree()
{
    int value_compare = 50; 
    
    pwm_WriteCompare(value_compare);
}

/*
    Location 90 degree of circle:
    1.5ms  of 20ms  -->  (1.5/20)*period = (1.5/20)*1000 = 75

*/
void location90Degree()
{
    int value_compare = 75;
    
    pwm_WriteCompare(value_compare);
}

/*
    Location 0 degree of circle:
    2ms of 20ms  --> (2/20)*period = (2/20)*1000 = 100
*/
void location180Degree()
{
    int value_compare = 100;
    
     pwm_WriteCompare(value_compare);
}


/* [] END OF FILE */
