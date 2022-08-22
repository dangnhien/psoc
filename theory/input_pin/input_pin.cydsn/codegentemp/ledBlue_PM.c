/*******************************************************************************
* File Name: ledBlue.c  
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
#include "ledBlue.h"

static ledBlue_BACKUP_STRUCT  ledBlue_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: ledBlue_Sleep
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
*  \snippet ledBlue_SUT.c usage_ledBlue_Sleep_Wakeup
*******************************************************************************/
void ledBlue_Sleep(void)
{
    #if defined(ledBlue__PC)
        ledBlue_backup.pcState = ledBlue_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            ledBlue_backup.usbState = ledBlue_CR1_REG;
            ledBlue_USB_POWER_REG |= ledBlue_USBIO_ENTER_SLEEP;
            ledBlue_CR1_REG &= ledBlue_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(ledBlue__SIO)
        ledBlue_backup.sioState = ledBlue_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        ledBlue_SIO_REG &= (uint32)(~ledBlue_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: ledBlue_Wakeup
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
*  Refer to ledBlue_Sleep() for an example usage.
*******************************************************************************/
void ledBlue_Wakeup(void)
{
    #if defined(ledBlue__PC)
        ledBlue_PC = ledBlue_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            ledBlue_USB_POWER_REG &= ledBlue_USBIO_EXIT_SLEEP_PH1;
            ledBlue_CR1_REG = ledBlue_backup.usbState;
            ledBlue_USB_POWER_REG &= ledBlue_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(ledBlue__SIO)
        ledBlue_SIO_REG = ledBlue_backup.sioState;
    #endif
}


/* [] END OF FILE */
