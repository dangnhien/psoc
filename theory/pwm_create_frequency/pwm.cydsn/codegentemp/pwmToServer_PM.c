/*******************************************************************************
* File Name: pwmToServer.c  
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
#include "pwmToServer.h"

static pwmToServer_BACKUP_STRUCT  pwmToServer_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: pwmToServer_Sleep
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
*  \snippet pwmToServer_SUT.c usage_pwmToServer_Sleep_Wakeup
*******************************************************************************/
void pwmToServer_Sleep(void)
{
    #if defined(pwmToServer__PC)
        pwmToServer_backup.pcState = pwmToServer_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            pwmToServer_backup.usbState = pwmToServer_CR1_REG;
            pwmToServer_USB_POWER_REG |= pwmToServer_USBIO_ENTER_SLEEP;
            pwmToServer_CR1_REG &= pwmToServer_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(pwmToServer__SIO)
        pwmToServer_backup.sioState = pwmToServer_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        pwmToServer_SIO_REG &= (uint32)(~pwmToServer_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: pwmToServer_Wakeup
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
*  Refer to pwmToServer_Sleep() for an example usage.
*******************************************************************************/
void pwmToServer_Wakeup(void)
{
    #if defined(pwmToServer__PC)
        pwmToServer_PC = pwmToServer_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            pwmToServer_USB_POWER_REG &= pwmToServer_USBIO_EXIT_SLEEP_PH1;
            pwmToServer_CR1_REG = pwmToServer_backup.usbState;
            pwmToServer_USB_POWER_REG &= pwmToServer_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(pwmToServer__SIO)
        pwmToServer_SIO_REG = pwmToServer_backup.sioState;
    #endif
}


/* [] END OF FILE */
