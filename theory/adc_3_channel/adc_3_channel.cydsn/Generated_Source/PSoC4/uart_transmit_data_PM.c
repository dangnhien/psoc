/***************************************************************************//**
* \file uart_transmit_data_PM.c
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

#include "uart_transmit_data.h"
#include "uart_transmit_data_PVT.h"

#if(uart_transmit_data_SCB_MODE_I2C_INC)
    #include "uart_transmit_data_I2C_PVT.h"
#endif /* (uart_transmit_data_SCB_MODE_I2C_INC) */

#if(uart_transmit_data_SCB_MODE_EZI2C_INC)
    #include "uart_transmit_data_EZI2C_PVT.h"
#endif /* (uart_transmit_data_SCB_MODE_EZI2C_INC) */

#if(uart_transmit_data_SCB_MODE_SPI_INC || uart_transmit_data_SCB_MODE_UART_INC)
    #include "uart_transmit_data_SPI_UART_PVT.h"
#endif /* (uart_transmit_data_SCB_MODE_SPI_INC || uart_transmit_data_SCB_MODE_UART_INC) */


/***************************************
*   Backup Structure declaration
***************************************/

#if(uart_transmit_data_SCB_MODE_UNCONFIG_CONST_CFG || \
   (uart_transmit_data_SCB_MODE_I2C_CONST_CFG   && (!uart_transmit_data_I2C_WAKE_ENABLE_CONST))   || \
   (uart_transmit_data_SCB_MODE_EZI2C_CONST_CFG && (!uart_transmit_data_EZI2C_WAKE_ENABLE_CONST)) || \
   (uart_transmit_data_SCB_MODE_SPI_CONST_CFG   && (!uart_transmit_data_SPI_WAKE_ENABLE_CONST))   || \
   (uart_transmit_data_SCB_MODE_UART_CONST_CFG  && (!uart_transmit_data_UART_WAKE_ENABLE_CONST)))

    uart_transmit_data_BACKUP_STRUCT uart_transmit_data_backup =
    {
        0u, /* enableState */
    };
#endif


/*******************************************************************************
* Function Name: uart_transmit_data_Sleep
****************************************************************************//**
*
*  Prepares the uart_transmit_data component to enter Deep Sleep.
*  The “Enable wakeup from Deep Sleep Mode” selection has an influence on this 
*  function implementation:
*  - Checked: configures the component to be wakeup source from Deep Sleep.
*  - Unchecked: stores the current component state (enabled or disabled) and 
*    disables the component. See SCB_Stop() function for details about component 
*    disabling.
*
*  Call the uart_transmit_data_Sleep() function before calling the 
*  CyPmSysDeepSleep() function. 
*  Refer to the PSoC Creator System Reference Guide for more information about 
*  power management functions and Low power section of this document for the 
*  selected mode.
*
*  This function should not be called before entering Sleep.
*
*******************************************************************************/
void uart_transmit_data_Sleep(void)
{
#if(uart_transmit_data_SCB_MODE_UNCONFIG_CONST_CFG)

    if(uart_transmit_data_SCB_WAKE_ENABLE_CHECK)
    {
        if(uart_transmit_data_SCB_MODE_I2C_RUNTM_CFG)
        {
            uart_transmit_data_I2CSaveConfig();
        }
        else if(uart_transmit_data_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            uart_transmit_data_EzI2CSaveConfig();
        }
    #if(!uart_transmit_data_CY_SCBIP_V1)
        else if(uart_transmit_data_SCB_MODE_SPI_RUNTM_CFG)
        {
            uart_transmit_data_SpiSaveConfig();
        }
        else if(uart_transmit_data_SCB_MODE_UART_RUNTM_CFG)
        {
            uart_transmit_data_UartSaveConfig();
        }
    #endif /* (!uart_transmit_data_CY_SCBIP_V1) */
        else
        {
            /* Unknown mode */
        }
    }
    else
    {
        uart_transmit_data_backup.enableState = (uint8) uart_transmit_data_GET_CTRL_ENABLED;

        if(0u != uart_transmit_data_backup.enableState)
        {
            uart_transmit_data_Stop();
        }
    }

#else

    #if (uart_transmit_data_SCB_MODE_I2C_CONST_CFG && uart_transmit_data_I2C_WAKE_ENABLE_CONST)
        uart_transmit_data_I2CSaveConfig();

    #elif (uart_transmit_data_SCB_MODE_EZI2C_CONST_CFG && uart_transmit_data_EZI2C_WAKE_ENABLE_CONST)
        uart_transmit_data_EzI2CSaveConfig();

    #elif (uart_transmit_data_SCB_MODE_SPI_CONST_CFG && uart_transmit_data_SPI_WAKE_ENABLE_CONST)
        uart_transmit_data_SpiSaveConfig();

    #elif (uart_transmit_data_SCB_MODE_UART_CONST_CFG && uart_transmit_data_UART_WAKE_ENABLE_CONST)
        uart_transmit_data_UartSaveConfig();

    #else

        uart_transmit_data_backup.enableState = (uint8) uart_transmit_data_GET_CTRL_ENABLED;

        if(0u != uart_transmit_data_backup.enableState)
        {
            uart_transmit_data_Stop();
        }

    #endif /* defined (uart_transmit_data_SCB_MODE_I2C_CONST_CFG) && (uart_transmit_data_I2C_WAKE_ENABLE_CONST) */

#endif /* (uart_transmit_data_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: uart_transmit_data_Wakeup
****************************************************************************//**
*
*  Prepares the uart_transmit_data component for Active mode operation after 
*  Deep Sleep.
*  The “Enable wakeup from Deep Sleep Mode” selection has influence on this 
*  function implementation:
*  - Checked: restores the component Active mode configuration.
*  - Unchecked: enables the component if it was enabled before enter Deep Sleep.
*
*  This function should not be called after exiting Sleep.
*
*  \sideeffect
*   Calling the uart_transmit_data_Wakeup() function without first calling the 
*   uart_transmit_data_Sleep() function may produce unexpected behavior.
*
*******************************************************************************/
void uart_transmit_data_Wakeup(void)
{
#if(uart_transmit_data_SCB_MODE_UNCONFIG_CONST_CFG)

    if(uart_transmit_data_SCB_WAKE_ENABLE_CHECK)
    {
        if(uart_transmit_data_SCB_MODE_I2C_RUNTM_CFG)
        {
            uart_transmit_data_I2CRestoreConfig();
        }
        else if(uart_transmit_data_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            uart_transmit_data_EzI2CRestoreConfig();
        }
    #if(!uart_transmit_data_CY_SCBIP_V1)
        else if(uart_transmit_data_SCB_MODE_SPI_RUNTM_CFG)
        {
            uart_transmit_data_SpiRestoreConfig();
        }
        else if(uart_transmit_data_SCB_MODE_UART_RUNTM_CFG)
        {
            uart_transmit_data_UartRestoreConfig();
        }
    #endif /* (!uart_transmit_data_CY_SCBIP_V1) */
        else
        {
            /* Unknown mode */
        }
    }
    else
    {
        if(0u != uart_transmit_data_backup.enableState)
        {
            uart_transmit_data_Enable();
        }
    }

#else

    #if (uart_transmit_data_SCB_MODE_I2C_CONST_CFG  && uart_transmit_data_I2C_WAKE_ENABLE_CONST)
        uart_transmit_data_I2CRestoreConfig();

    #elif (uart_transmit_data_SCB_MODE_EZI2C_CONST_CFG && uart_transmit_data_EZI2C_WAKE_ENABLE_CONST)
        uart_transmit_data_EzI2CRestoreConfig();

    #elif (uart_transmit_data_SCB_MODE_SPI_CONST_CFG && uart_transmit_data_SPI_WAKE_ENABLE_CONST)
        uart_transmit_data_SpiRestoreConfig();

    #elif (uart_transmit_data_SCB_MODE_UART_CONST_CFG && uart_transmit_data_UART_WAKE_ENABLE_CONST)
        uart_transmit_data_UartRestoreConfig();

    #else

        if(0u != uart_transmit_data_backup.enableState)
        {
            uart_transmit_data_Enable();
        }

    #endif /* (uart_transmit_data_I2C_WAKE_ENABLE_CONST) */

#endif /* (uart_transmit_data_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/* [] END OF FILE */
