/*******************************************************************************
* File Name: lcd_LCDPort.c  
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
#include "lcd_LCDPort.h"

static lcd_LCDPort_BACKUP_STRUCT  lcd_LCDPort_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: lcd_LCDPort_Sleep
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
*  \snippet lcd_LCDPort_SUT.c usage_lcd_LCDPort_Sleep_Wakeup
*******************************************************************************/
void lcd_LCDPort_Sleep(void)
{
    #if defined(lcd_LCDPort__PC)
        lcd_LCDPort_backup.pcState = lcd_LCDPort_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            lcd_LCDPort_backup.usbState = lcd_LCDPort_CR1_REG;
            lcd_LCDPort_USB_POWER_REG |= lcd_LCDPort_USBIO_ENTER_SLEEP;
            lcd_LCDPort_CR1_REG &= lcd_LCDPort_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(lcd_LCDPort__SIO)
        lcd_LCDPort_backup.sioState = lcd_LCDPort_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        lcd_LCDPort_SIO_REG &= (uint32)(~lcd_LCDPort_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: lcd_LCDPort_Wakeup
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
*  Refer to lcd_LCDPort_Sleep() for an example usage.
*******************************************************************************/
void lcd_LCDPort_Wakeup(void)
{
    #if defined(lcd_LCDPort__PC)
        lcd_LCDPort_PC = lcd_LCDPort_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            lcd_LCDPort_USB_POWER_REG &= lcd_LCDPort_USBIO_EXIT_SLEEP_PH1;
            lcd_LCDPort_CR1_REG = lcd_LCDPort_backup.usbState;
            lcd_LCDPort_USB_POWER_REG &= lcd_LCDPort_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(lcd_LCDPort__SIO)
        lcd_LCDPort_SIO_REG = lcd_LCDPort_backup.sioState;
    #endif
}


/* [] END OF FILE */
