/*******************************************************************************
* File Name: button_single.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "button_single.h"

static button_single_BACKUP_STRUCT  button_single_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: button_single_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function applies only to SIO and USBIO pins.
*  It should not be called for GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet button_single_SUT.c usage_button_single_Sleep_Wakeup
*******************************************************************************/
void button_single_Sleep(void)
{
    #if defined(button_single__PC)
        button_single_backup.pcState = button_single_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            button_single_backup.usbState = button_single_CR1_REG;
            button_single_USB_POWER_REG |= button_single_USBIO_ENTER_SLEEP;
            button_single_CR1_REG &= button_single_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(button_single__SIO)
        button_single_backup.sioState = button_single_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        button_single_SIO_REG &= (uint32)(~button_single_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: button_single_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep(). This 
* function applies only to SIO and USBIO pins. It should not be called for
* GPIO or GPIO_OVT pins.
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to button_single_Sleep() for an example usage.
*******************************************************************************/
void button_single_Wakeup(void)
{
    #if defined(button_single__PC)
        button_single_PC = button_single_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            button_single_USB_POWER_REG &= button_single_USBIO_EXIT_SLEEP_PH1;
            button_single_CR1_REG = button_single_backup.usbState;
            button_single_USB_POWER_REG &= button_single_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(button_single__SIO)
        button_single_SIO_REG = button_single_backup.sioState;
    #endif
}


/* [] END OF FILE */
