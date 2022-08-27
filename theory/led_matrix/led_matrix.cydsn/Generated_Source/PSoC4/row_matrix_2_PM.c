/*******************************************************************************
* File Name: row_matrix_2.c  
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
#include "row_matrix_2.h"

static row_matrix_2_BACKUP_STRUCT  row_matrix_2_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: row_matrix_2_Sleep
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
*  \snippet row_matrix_2_SUT.c usage_row_matrix_2_Sleep_Wakeup
*******************************************************************************/
void row_matrix_2_Sleep(void)
{
    #if defined(row_matrix_2__PC)
        row_matrix_2_backup.pcState = row_matrix_2_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            row_matrix_2_backup.usbState = row_matrix_2_CR1_REG;
            row_matrix_2_USB_POWER_REG |= row_matrix_2_USBIO_ENTER_SLEEP;
            row_matrix_2_CR1_REG &= row_matrix_2_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(row_matrix_2__SIO)
        row_matrix_2_backup.sioState = row_matrix_2_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        row_matrix_2_SIO_REG &= (uint32)(~row_matrix_2_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: row_matrix_2_Wakeup
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
*  Refer to row_matrix_2_Sleep() for an example usage.
*******************************************************************************/
void row_matrix_2_Wakeup(void)
{
    #if defined(row_matrix_2__PC)
        row_matrix_2_PC = row_matrix_2_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            row_matrix_2_USB_POWER_REG &= row_matrix_2_USBIO_EXIT_SLEEP_PH1;
            row_matrix_2_CR1_REG = row_matrix_2_backup.usbState;
            row_matrix_2_USB_POWER_REG &= row_matrix_2_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(row_matrix_2__SIO)
        row_matrix_2_SIO_REG = row_matrix_2_backup.sioState;
    #endif
}


/* [] END OF FILE */
