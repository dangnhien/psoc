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
   #include "buttonBlack.h"
    
    //value return: [1,4];
   int valuePressButton()
   {
        static int status = 0;
    
        static int remember = 0;
        
        if(button1_Read() == 0)
            remember = 1;
        
        if(button1_Read() == 1 && remember == 1)
        {
            remember = 0;
            
            status++;
            if( status > 4 )
                status = 1;
        }    
        
        return status;
   }



/* [] END OF FILE */
