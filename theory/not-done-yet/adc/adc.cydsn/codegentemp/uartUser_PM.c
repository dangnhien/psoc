/***************************************************************************//**
* \file uartUser_PM.c
* \version 4.0
*
* \brief
*  This file provides the source code to the Power Management support for
*  the SCB Component.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2013-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "uartUser.h"
#include "uartUser_PVT.h"

#if(uartUser_SCB_MODE_I2C_INC)
    #include "uartUser_I2C_PVT.h"
#endif /* (uartUser_SCB_MODE_I2C_INC) */

#if(uartUser_SCB_MODE_EZI2C_INC)
    #include "uartUser_EZI2C_PVT.h"
#endif /* (uartUser_SCB_MODE_EZI2C_INC) */

#if(uartUser_SCB_MODE_SPI_INC || uartUser_SCB_MODE_UART_INC)
    #include "uartUser_SPI_UART_PVT.h"
#endif /* (uartUser_SCB_MODE_SPI_INC || uartUser_SCB_MODE_UART_INC) */


/***************************************
*   Backup Structure declaration
***************************************/

#if(uartUser_SCB_MODE_UNCONFIG_CONST_CFG || \
   (uartUser_SCB_MODE_I2C_CONST_CFG   && (!uartUser_I2C_WAKE_ENABLE_CONST))   || \
   (uartUser_SCB_MODE_EZI2C_CONST_CFG && (!uartUser_EZI2C_WAKE_ENABLE_CONST)) || \
   (uartUser_SCB_MODE_SPI_CONST_CFG   && (!uartUser_SPI_WAKE_ENABLE_CONST))   || \
   (uartUser_SCB_MODE_UART_CONST_CFG  && (!uartUser_UART_WAKE_ENABLE_CONST)))

    uartUser_BACKUP_STRUCT uartUser_backup =
    {
        0u, /* enableState */
    };
#endif


/*******************************************************************************
* Function Name: uartUser_Sleep
****************************************************************************//**
*
*  Prepares the uartUser component to enter Deep Sleep.
*  The “Enable wakeup from Deep Sleep Mode” selection has an influence on this 
*  function implementation:
*  - Checked: configures the component to be wakeup source from Deep Sleep.
*  - Unchecked: stores the current component state (enabled or disabled) and 
*    disables the component. See SCB_Stop() function for details about component 
*    disabling.
*
*  Call the uartUser_Sleep() function before calling the 
*  CyPmSysDeepSleep() function. 
*  Refer to the PSoC Creator System Reference Guide for more information about 
*  power management functions and Low power section of this document for the 
*  selected mode.
*
*  This function should not be called before entering Sleep.
*
*******************************************************************************/
void uartUser_Sleep(void)
{
#if(uartUser_SCB_MODE_UNCONFIG_CONST_CFG)

    if(uartUser_SCB_WAKE_ENABLE_CHECK)
    {
        if(uartUser_SCB_MODE_I2C_RUNTM_CFG)
        {
            uartUser_I2CSaveConfig();
        }
        else if(uartUser_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            uartUser_EzI2CSaveConfig();
        }
    #if(!uartUser_CY_SCBIP_V1)
        else if(uartUser_SCB_MODE_SPI_RUNTM_CFG)
        {
            uartUser_SpiSaveConfig();
        }
        else if(uartUser_SCB_MODE_UART_RUNTM_CFG)
        {
            uartUser_UartSaveConfig();
        }
    #endif /* (!uartUser_CY_SCBIP_V1) */
        else
        {
            /* Unknown mode */
        }
    }
    else
    {
        uartUser_backup.enableState = (uint8) uartUser_GET_CTRL_ENABLED;

        if(0u != uartUser_backup.enableState)
        {
            uartUser_Stop();
        }
    }

#else

    #if (uartUser_SCB_MODE_I2C_CONST_CFG && uartUser_I2C_WAKE_ENABLE_CONST)
        uartUser_I2CSaveConfig();

    #elif (uartUser_SCB_MODE_EZI2C_CONST_CFG && uartUser_EZI2C_WAKE_ENABLE_CONST)
        uartUser_EzI2CSaveConfig();

    #elif (uartUser_SCB_MODE_SPI_CONST_CFG && uartUser_SPI_WAKE_ENABLE_CONST)
        uartUser_SpiSaveConfig();

    #elif (uartUser_SCB_MODE_UART_CONST_CFG && uartUser_UART_WAKE_ENABLE_CONST)
        uartUser_UartSaveConfig();

    #else

        uartUser_backup.enableState = (uint8) uartUser_GET_CTRL_ENABLED;

        if(0u != uartUser_backup.enableState)
        {
            uartUser_Stop();
        }

    #endif /* defined (uartUser_SCB_MODE_I2C_CONST_CFG) && (uartUser_I2C_WAKE_ENABLE_CONST) */

#endif /* (uartUser_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: uartUser_Wakeup
****************************************************************************//**
*
*  Prepares the uartUser component for Active mode operation after 
*  Deep Sleep.
*  The “Enable wakeup from Deep Sleep Mode” selection has influence on this 
*  function implementation:
*  - Checked: restores the component Active mode configuration.
*  - Unchecked: enables the component if it was enabled before enter Deep Sleep.
*
*  This function should not be called after exiting Sleep.
*
*  \sideeffect
*   Calling the uartUser_Wakeup() function without first calling the 
*   uartUser_Sleep() function may produce unexpected behavior.
*
*******************************************************************************/
void uartUser_Wakeup(void)
{
#if(uartUser_SCB_MODE_UNCONFIG_CONST_CFG)

    if(uartUser_SCB_WAKE_ENABLE_CHECK)
    {
        if(uartUser_SCB_MODE_I2C_RUNTM_CFG)
        {
            uartUser_I2CRestoreConfig();
        }
        else if(uartUser_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            uartUser_EzI2CRestoreConfig();
        }
    #if(!uartUser_CY_SCBIP_V1)
        else if(uartUser_SCB_MODE_SPI_RUNTM_CFG)
        {
            uartUser_SpiRestoreConfig();
        }
        else if(uartUser_SCB_MODE_UART_RUNTM_CFG)
        {
            uartUser_UartRestoreConfig();
        }
    #endif /* (!uartUser_CY_SCBIP_V1) */
        else
        {
            /* Unknown mode */
        }
    }
    else
    {
        if(0u != uartUser_backup.enableState)
        {
            uartUser_Enable();
        }
    }

#else

    #if (uartUser_SCB_MODE_I2C_CONST_CFG  && uartUser_I2C_WAKE_ENABLE_CONST)
        uartUser_I2CRestoreConfig();

    #elif (uartUser_SCB_MODE_EZI2C_CONST_CFG && uartUser_EZI2C_WAKE_ENABLE_CONST)
        uartUser_EzI2CRestoreConfig();

    #elif (uartUser_SCB_MODE_SPI_CONST_CFG && uartUser_SPI_WAKE_ENABLE_CONST)
        uartUser_SpiRestoreConfig();

    #elif (uartUser_SCB_MODE_UART_CONST_CFG && uartUser_UART_WAKE_ENABLE_CONST)
        uartUser_UartRestoreConfig();

    #else

        if(0u != uartUser_backup.enableState)
        {
            uartUser_Enable();
        }

    #endif /* (uartUser_I2C_WAKE_ENABLE_CONST) */

#endif /* (uartUser_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/* [] END OF FILE */
