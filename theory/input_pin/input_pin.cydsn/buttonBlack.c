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
#include "buttonBlack.h"

enum Status_Button
{
    BTN_PRESSED,
    BTN_RELEASE
};

//value return: [1,4];
int valuePressedButton()
{
    static int status=0, remember=0;

    if(button1_Read() == BTN_PRESSED)
        remember = 1;
    
    if(button1_Read() == BTN_RELEASE && remember == 1)
    {
        remember = 0;
        
        status++;
        if( status > 4 )
            status = 1;
    }    
    
    return status;
}



/* [] END OF FILE */
