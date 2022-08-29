/***************************************************************************//**
* \file uartUser_BOOT.h
* \version 4.0
*
* \brief
*  This file provides constants and parameter values of the bootloader
*  communication APIs for the SCB Component.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2014-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_BOOT_uartUser_H)
#define CY_SCB_BOOT_uartUser_H

#include "uartUser_PVT.h"

#if (uartUser_SCB_MODE_I2C_INC)
    #include "uartUser_I2C.h"
#endif /* (uartUser_SCB_MODE_I2C_INC) */

#if (uartUser_SCB_MODE_EZI2C_INC)
    #include "uartUser_EZI2C.h"
#endif /* (uartUser_SCB_MODE_EZI2C_INC) */

#if (uartUser_SCB_MODE_SPI_INC || uartUser_SCB_MODE_UART_INC)
    #include "uartUser_SPI_UART.h"
#endif /* (uartUser_SCB_MODE_SPI_INC || uartUser_SCB_MODE_UART_INC) */


/***************************************
*  Conditional Compilation Parameters
****************************************/

/* Bootloader communication interface enable */
#define uartUser_BTLDR_COMM_ENABLED ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_uartUser) || \
                                             (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface))

/* Enable I2C bootloader communication */
#if (uartUser_SCB_MODE_I2C_INC)
    #define uartUser_I2C_BTLDR_COMM_ENABLED     (uartUser_BTLDR_COMM_ENABLED && \
                                                            (uartUser_SCB_MODE_UNCONFIG_CONST_CFG || \
                                                             uartUser_I2C_SLAVE_CONST))
#else
     #define uartUser_I2C_BTLDR_COMM_ENABLED    (0u)
#endif /* (uartUser_SCB_MODE_I2C_INC) */

/* EZI2C does not support bootloader communication. Provide empty APIs */
#if (uartUser_SCB_MODE_EZI2C_INC)
    #define uartUser_EZI2C_BTLDR_COMM_ENABLED   (uartUser_BTLDR_COMM_ENABLED && \
                                                         uartUser_SCB_MODE_UNCONFIG_CONST_CFG)
#else
    #define uartUser_EZI2C_BTLDR_COMM_ENABLED   (0u)
#endif /* (uartUser_EZI2C_BTLDR_COMM_ENABLED) */

/* Enable SPI bootloader communication */
#if (uartUser_SCB_MODE_SPI_INC)
    #define uartUser_SPI_BTLDR_COMM_ENABLED     (uartUser_BTLDR_COMM_ENABLED && \
                                                            (uartUser_SCB_MODE_UNCONFIG_CONST_CFG || \
                                                             uartUser_SPI_SLAVE_CONST))
#else
        #define uartUser_SPI_BTLDR_COMM_ENABLED (0u)
#endif /* (uartUser_SPI_BTLDR_COMM_ENABLED) */

/* Enable UART bootloader communication */
#if (uartUser_SCB_MODE_UART_INC)
       #define uartUser_UART_BTLDR_COMM_ENABLED    (uartUser_BTLDR_COMM_ENABLED && \
                                                            (uartUser_SCB_MODE_UNCONFIG_CONST_CFG || \
                                                             (uartUser_UART_RX_DIRECTION && \
                                                              uartUser_UART_TX_DIRECTION)))
#else
     #define uartUser_UART_BTLDR_COMM_ENABLED   (0u)
#endif /* (uartUser_UART_BTLDR_COMM_ENABLED) */

/* Enable bootloader communication */
#define uartUser_BTLDR_COMM_MODE_ENABLED    (uartUser_I2C_BTLDR_COMM_ENABLED   || \
                                                     uartUser_SPI_BTLDR_COMM_ENABLED   || \
                                                     uartUser_EZI2C_BTLDR_COMM_ENABLED || \
                                                     uartUser_UART_BTLDR_COMM_ENABLED)


/***************************************
*        Function Prototypes
***************************************/

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (uartUser_I2C_BTLDR_COMM_ENABLED)
    /* I2C Bootloader physical layer functions */
    void uartUser_I2CCyBtldrCommStart(void);
    void uartUser_I2CCyBtldrCommStop (void);
    void uartUser_I2CCyBtldrCommReset(void);
    cystatus uartUser_I2CCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus uartUser_I2CCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map I2C specific bootloader communication APIs to SCB specific APIs */
    #if (uartUser_SCB_MODE_I2C_CONST_CFG)
        #define uartUser_CyBtldrCommStart   uartUser_I2CCyBtldrCommStart
        #define uartUser_CyBtldrCommStop    uartUser_I2CCyBtldrCommStop
        #define uartUser_CyBtldrCommReset   uartUser_I2CCyBtldrCommReset
        #define uartUser_CyBtldrCommRead    uartUser_I2CCyBtldrCommRead
        #define uartUser_CyBtldrCommWrite   uartUser_I2CCyBtldrCommWrite
    #endif /* (uartUser_SCB_MODE_I2C_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (uartUser_I2C_BTLDR_COMM_ENABLED) */


#if defined(CYDEV_BOOTLOADER_IO_COMP) && (uartUser_EZI2C_BTLDR_COMM_ENABLED)
    /* Bootloader physical layer functions */
    void uartUser_EzI2CCyBtldrCommStart(void);
    void uartUser_EzI2CCyBtldrCommStop (void);
    void uartUser_EzI2CCyBtldrCommReset(void);
    cystatus uartUser_EzI2CCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus uartUser_EzI2CCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map EZI2C specific bootloader communication APIs to SCB specific APIs */
    #if (uartUser_SCB_MODE_EZI2C_CONST_CFG)
        #define uartUser_CyBtldrCommStart   uartUser_EzI2CCyBtldrCommStart
        #define uartUser_CyBtldrCommStop    uartUser_EzI2CCyBtldrCommStop
        #define uartUser_CyBtldrCommReset   uartUser_EzI2CCyBtldrCommReset
        #define uartUser_CyBtldrCommRead    uartUser_EzI2CCyBtldrCommRead
        #define uartUser_CyBtldrCommWrite   uartUser_EzI2CCyBtldrCommWrite
    #endif /* (uartUser_SCB_MODE_EZI2C_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (uartUser_EZI2C_BTLDR_COMM_ENABLED) */

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (uartUser_SPI_BTLDR_COMM_ENABLED)
    /* SPI Bootloader physical layer functions */
    void uartUser_SpiCyBtldrCommStart(void);
    void uartUser_SpiCyBtldrCommStop (void);
    void uartUser_SpiCyBtldrCommReset(void);
    cystatus uartUser_SpiCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus uartUser_SpiCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map SPI specific bootloader communication APIs to SCB specific APIs */
    #if (uartUser_SCB_MODE_SPI_CONST_CFG)
        #define uartUser_CyBtldrCommStart   uartUser_SpiCyBtldrCommStart
        #define uartUser_CyBtldrCommStop    uartUser_SpiCyBtldrCommStop
        #define uartUser_CyBtldrCommReset   uartUser_SpiCyBtldrCommReset
        #define uartUser_CyBtldrCommRead    uartUser_SpiCyBtldrCommRead
        #define uartUser_CyBtldrCommWrite   uartUser_SpiCyBtldrCommWrite
    #endif /* (uartUser_SCB_MODE_SPI_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (uartUser_SPI_BTLDR_COMM_ENABLED) */

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (uartUser_UART_BTLDR_COMM_ENABLED)
    /* UART Bootloader physical layer functions */
    void uartUser_UartCyBtldrCommStart(void);
    void uartUser_UartCyBtldrCommStop (void);
    void uartUser_UartCyBtldrCommReset(void);
    cystatus uartUser_UartCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus uartUser_UartCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map UART specific bootloader communication APIs to SCB specific APIs */
    #if (uartUser_SCB_MODE_UART_CONST_CFG)
        #define uartUser_CyBtldrCommStart   uartUser_UartCyBtldrCommStart
        #define uartUser_CyBtldrCommStop    uartUser_UartCyBtldrCommStop
        #define uartUser_CyBtldrCommReset   uartUser_UartCyBtldrCommReset
        #define uartUser_CyBtldrCommRead    uartUser_UartCyBtldrCommRead
        #define uartUser_CyBtldrCommWrite   uartUser_UartCyBtldrCommWrite
    #endif /* (uartUser_SCB_MODE_UART_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (uartUser_UART_BTLDR_COMM_ENABLED) */

/**
* \addtogroup group_bootloader
* @{
*/

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (uartUser_BTLDR_COMM_ENABLED)
    #if (uartUser_SCB_MODE_UNCONFIG_CONST_CFG)
        /* Bootloader physical layer functions */
        void uartUser_CyBtldrCommStart(void);
        void uartUser_CyBtldrCommStop (void);
        void uartUser_CyBtldrCommReset(void);
        cystatus uartUser_CyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
        cystatus uartUser_CyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    #endif /* (uartUser_SCB_MODE_UNCONFIG_CONST_CFG) */

    /* Map SCB specific bootloader communication APIs to common APIs */
    #if (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_uartUser)
        #define CyBtldrCommStart    uartUser_CyBtldrCommStart
        #define CyBtldrCommStop     uartUser_CyBtldrCommStop
        #define CyBtldrCommReset    uartUser_CyBtldrCommReset
        #define CyBtldrCommWrite    uartUser_CyBtldrCommWrite
        #define CyBtldrCommRead     uartUser_CyBtldrCommRead
    #endif /* (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_uartUser) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (uartUser_BTLDR_COMM_ENABLED) */

/** @} group_bootloader */

/***************************************
*           API Constants
***************************************/

/* Timeout unit in milliseconds */
#define uartUser_WAIT_1_MS  (1u)

/* Return number of bytes to copy into bootloader buffer */
#define uartUser_BYTES_TO_COPY(actBufSize, bufSize) \
                            ( ((uint32)(actBufSize) < (uint32)(bufSize)) ? \
                                ((uint32) (actBufSize)) : ((uint32) (bufSize)) )

/* Size of Read/Write buffers for I2C bootloader  */
#define uartUser_I2C_BTLDR_SIZEOF_READ_BUFFER   (64u)
#define uartUser_I2C_BTLDR_SIZEOF_WRITE_BUFFER  (64u)

/* Byte to byte time interval: calculated basing on current component
* data rate configuration, can be defined in project if required.
*/
#ifndef uartUser_SPI_BYTE_TO_BYTE
    #define uartUser_SPI_BYTE_TO_BYTE   (160u)
#endif

/* Byte to byte time interval: calculated basing on current component
* baud rate configuration, can be defined in the project if required.
*/
#ifndef uartUser_UART_BYTE_TO_BYTE
    #define uartUser_UART_BYTE_TO_BYTE  (171u)
#endif /* uartUser_UART_BYTE_TO_BYTE */

#endif /* (CY_SCB_BOOT_uartUser_H) */


/* [] END OF FILE */
