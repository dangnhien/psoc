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
#include "main.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    init_system();
    
    for(;;)
    {
        /* Place your application code here. */        
        test_transmit_data();
        
        transmit_data_to_computer(read_adc(0), 0);
        transmit_data_to_computer(read_adc(1), 1);
        transmit_data_to_computer(read_adc(2), 2);
        transmit_data_to_computer(read_adc(3), 3);
        
        CyDelay(1000);
    }
}

void init_system()
{
    uart_Start();
    
    adc_Start();
}

/* [] END OF FILE */
