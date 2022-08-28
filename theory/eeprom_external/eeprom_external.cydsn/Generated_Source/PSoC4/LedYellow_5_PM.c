/*******************************************************************************
* File Name: LedYellow_5.c  
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
#include "LedYellow_5.h"

static LedYellow_5_BACKUP_STRUCT  LedYellow_5_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: LedYellow_5_Sleep
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
*  \snippet LedYellow_5_SUT.c usage_LedYellow_5_Sleep_Wakeup
*******************************************************************************/
void LedYellow_5_Sleep(void)
{
    #if defined(LedYellow_5__PC)
        LedYellow_5_backup.pcState = LedYellow_5_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            LedYellow_5_backup.usbState = LedYellow_5_CR1_REG;
            LedYellow_5_USB_POWER_REG |= LedYellow_5_USBIO_ENTER_SLEEP;
            LedYellow_5_CR1_REG &= LedYellow_5_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(LedYellow_5__SIO)
        LedYellow_5_backup.sioState = LedYellow_5_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        LedYellow_5_SIO_REG &= (uint32)(~LedYellow_5_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: LedYellow_5_Wakeup
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
*  Refer to LedYellow_5_Sleep() for an example usage.
*******************************************************************************/
void LedYellow_5_Wakeup(void)
{
    #if defined(LedYellow_5__PC)
        LedYellow_5_PC = LedYellow_5_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            LedYellow_5_USB_POWER_REG &= LedYellow_5_USBIO_EXIT_SLEEP_PH1;
            LedYellow_5_CR1_REG = LedYellow_5_backup.usbState;
            LedYellow_5_USB_POWER_REG &= LedYellow_5_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(LedYellow_5__SIO)
        LedYellow_5_SIO_REG = LedYellow_5_backup.sioState;
    #endif
}


/* [] END OF FILE */
