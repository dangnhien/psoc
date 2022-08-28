/***************************************************************************//**
* \file i2c_BOOT.c
* \version 4.0
*
* \brief
*  This file provides the source code of the bootloader communication APIs
*  for the SCB Component Unconfigured mode.
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

#include "i2c_BOOT.h"

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (i2c_BTLDR_COMM_ENABLED) && \
                                (i2c_SCB_MODE_UNCONFIG_CONST_CFG)

/*******************************************************************************
* Function Name: i2c_CyBtldrCommStart
****************************************************************************//**
*
*  Starts i2c component. After this function call the component is 
*  ready for communication.
*
*******************************************************************************/
void i2c_CyBtldrCommStart(void)
{
    if (i2c_SCB_MODE_I2C_RUNTM_CFG)
    {
        i2c_I2CCyBtldrCommStart();
    }
    else if (i2c_SCB_MODE_EZI2C_RUNTM_CFG)
    {
        i2c_EzI2CCyBtldrCommStart();
    }
#if (!i2c_CY_SCBIP_V1)
    else if (i2c_SCB_MODE_SPI_RUNTM_CFG)
    {
        i2c_SpiCyBtldrCommStart();
    }
    else if (i2c_SCB_MODE_UART_RUNTM_CFG)
    {
        i2c_UartCyBtldrCommStart();
    }
#endif /* (!i2c_CY_SCBIP_V1) */
    else
    {
        /* Unknown mode: do nothing */
    }
}


/*******************************************************************************
* Function Name: i2c_CyBtldrCommStop
****************************************************************************//**
*
*  Stops i2c component.
*
*******************************************************************************/
void i2c_CyBtldrCommStop(void)
{
    if (i2c_SCB_MODE_I2C_RUNTM_CFG)
    {
        i2c_I2CCyBtldrCommStop();
    }
    else if (i2c_SCB_MODE_EZI2C_RUNTM_CFG)
    {
        i2c_EzI2CCyBtldrCommStop();
    }
#if (!i2c_CY_SCBIP_V1)
    else if (i2c_SCB_MODE_SPI_RUNTM_CFG)
    {
        i2c_SpiCyBtldrCommStop();
    }
    else if (i2c_SCB_MODE_UART_RUNTM_CFG)
    {
        i2c_UartCyBtldrCommStop();
    }
#endif /* (!i2c_CY_SCBIP_V1) */
    else
    {
        /* Unknown mode: do nothing */
    }
}


/*******************************************************************************
* Function Name: i2c_CyBtldrCommReset
****************************************************************************//**
*
*  Clears i2c component buffers.
*
*******************************************************************************/
void i2c_CyBtldrCommReset(void)
{
    if(i2c_SCB_MODE_I2C_RUNTM_CFG)
    {
        i2c_I2CCyBtldrCommReset();
    }
    else if(i2c_SCB_MODE_EZI2C_RUNTM_CFG)
    {
        i2c_EzI2CCyBtldrCommReset();
    }
#if (!i2c_CY_SCBIP_V1)
    else if(i2c_SCB_MODE_SPI_RUNTM_CFG)
    {
        i2c_SpiCyBtldrCommReset();
    }
    else if(i2c_SCB_MODE_UART_RUNTM_CFG)
    {
        i2c_UartCyBtldrCommReset();
    }
#endif /* (!i2c_CY_SCBIP_V1) */
    else
    {
        /* Unknown mode: do nothing */
    }
}


/*******************************************************************************
* Function Name: i2c_CyBtldrCommRead
****************************************************************************//**
*
*  Allows the caller to read data from the bootloader host (the host writes the 
*  data). The function handles polling to allow a block of data to be completely
*  received from the host device.
*
*  \param pData: Pointer to storage for the block of data to be read from the
*   bootloader host.
*  \param size: Number of bytes to be read.
*  \param count: Pointer to the variable to write the number of bytes actually
*   read.
*  \param timeOut: Number of units in 10 ms to wait before returning because of a
*   timeout.
*
* \return
*  \return
*  cystatus: Returns CYRET_SUCCESS if no problem was encountered or returns the
*  value that best describes the problem. For more information refer to 
*  the “Return Codes” section of the System Reference Guide.
*
*******************************************************************************/
cystatus i2c_CyBtldrCommRead(uint8 pData[], uint16 size, uint16 * count, uint8 timeOut)
{
    cystatus status;

    if(i2c_SCB_MODE_I2C_RUNTM_CFG)
    {
        status = i2c_I2CCyBtldrCommRead(pData, size, count, timeOut);
    }
    else if(i2c_SCB_MODE_EZI2C_RUNTM_CFG)
    {
        status = i2c_EzI2CCyBtldrCommRead(pData, size, count, timeOut);
    }
#if (!i2c_CY_SCBIP_V1)
    else if(i2c_SCB_MODE_SPI_RUNTM_CFG)
    {
        status = i2c_SpiCyBtldrCommRead(pData, size, count, timeOut);
    }
    else if(i2c_SCB_MODE_UART_RUNTM_CFG)
    {
        status = i2c_UartCyBtldrCommRead(pData, size, count, timeOut);
    }
#endif /* (!i2c_CY_SCBIP_V1) */
    else
    {
        status = CYRET_INVALID_STATE; /* Unknown mode: return invalid status */
    }

    return(status);
}


/*******************************************************************************
* Function Name: i2c_CyBtldrCommWrite
****************************************************************************//**
*
*  Allows the caller to write data to the bootloader host (the host reads the 
*  data). The function does not use timeout and returns after data has been copied
*  into the slave read buffer. This data available to be read by the bootloader
*  host until following host data write.
*
*  \param pData: Pointer to the block of data to be written to the bootloader host.
*  \param size: Number of bytes to be written.
*  \param count: Pointer to the variable to write the number of bytes actually
*   written.
*  \param timeOut: Number of units in 10 ms to wait before returning because of a
*   timeout.
*
*  \return
*  cystatus: Returns CYRET_SUCCESS if no problem was encountered or returns the
*  value that best describes the problem. For more information refer to 
*  the “Return Codes” section of the System Reference Guide.
*
*******************************************************************************/
cystatus i2c_CyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut)
{
    cystatus status;

    if(i2c_SCB_MODE_I2C_RUNTM_CFG)
    {
        status = i2c_I2CCyBtldrCommWrite(pData, size, count, timeOut);
    }
    else if(i2c_SCB_MODE_EZI2C_RUNTM_CFG)
    {
        status = i2c_EzI2CCyBtldrCommWrite(pData, size, count, timeOut);
    }
#if (!i2c_CY_SCBIP_V1)
    else if(i2c_SCB_MODE_SPI_RUNTM_CFG)
    {
        status = i2c_SpiCyBtldrCommWrite(pData, size, count, timeOut);
    }
    else if(i2c_SCB_MODE_UART_RUNTM_CFG)
    {
        status = i2c_UartCyBtldrCommWrite(pData, size, count, timeOut);
    }
#endif /* (!i2c_CY_SCBIP_V1) */
    else
    {
        status = CYRET_INVALID_STATE; /* Unknown mode: return invalid status */
    }

    return(status);
}

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (i2c_BTLDR_COMM_MODE_ENABLED) */


/* [] END OF FILE */
