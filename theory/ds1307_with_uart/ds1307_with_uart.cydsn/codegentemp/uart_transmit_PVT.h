/***************************************************************************//**
* \file .h
* \version 4.0
*
* \brief
*  This private file provides constants and parameter values for the
*  SCB Component.
*  Please do not use this file or its content in your project.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2013-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_PVT_uart_transmit_H)
#define CY_SCB_PVT_uart_transmit_H

#include "uart_transmit.h"


/***************************************
*     Private Function Prototypes
***************************************/

/* APIs to service INTR_I2C_EC register */
#define uart_transmit_SetI2CExtClkInterruptMode(interruptMask) uart_transmit_WRITE_INTR_I2C_EC_MASK(interruptMask)
#define uart_transmit_ClearI2CExtClkInterruptSource(interruptMask) uart_transmit_CLEAR_INTR_I2C_EC(interruptMask)
#define uart_transmit_GetI2CExtClkInterruptSource()                (uart_transmit_INTR_I2C_EC_REG)
#define uart_transmit_GetI2CExtClkInterruptMode()                  (uart_transmit_INTR_I2C_EC_MASK_REG)
#define uart_transmit_GetI2CExtClkInterruptSourceMasked()          (uart_transmit_INTR_I2C_EC_MASKED_REG)

#if (!uart_transmit_CY_SCBIP_V1)
    /* APIs to service INTR_SPI_EC register */
    #define uart_transmit_SetSpiExtClkInterruptMode(interruptMask) \
                                                                uart_transmit_WRITE_INTR_SPI_EC_MASK(interruptMask)
    #define uart_transmit_ClearSpiExtClkInterruptSource(interruptMask) \
                                                                uart_transmit_CLEAR_INTR_SPI_EC(interruptMask)
    #define uart_transmit_GetExtSpiClkInterruptSource()                 (uart_transmit_INTR_SPI_EC_REG)
    #define uart_transmit_GetExtSpiClkInterruptMode()                   (uart_transmit_INTR_SPI_EC_MASK_REG)
    #define uart_transmit_GetExtSpiClkInterruptSourceMasked()           (uart_transmit_INTR_SPI_EC_MASKED_REG)
#endif /* (!uart_transmit_CY_SCBIP_V1) */

#if(uart_transmit_SCB_MODE_UNCONFIG_CONST_CFG)
    extern void uart_transmit_SetPins(uint32 mode, uint32 subMode, uint32 uartEnableMask);
#endif /* (uart_transmit_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*     Vars with External Linkage
***************************************/

#if (uart_transmit_SCB_IRQ_INTERNAL)
#if !defined (CY_REMOVE_uart_transmit_CUSTOM_INTR_HANDLER)
    extern cyisraddress uart_transmit_customIntrHandler;
#endif /* !defined (CY_REMOVE_uart_transmit_CUSTOM_INTR_HANDLER) */
#endif /* (uart_transmit_SCB_IRQ_INTERNAL) */

extern uart_transmit_BACKUP_STRUCT uart_transmit_backup;

#if(uart_transmit_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Common configuration variables */
    extern uint8 uart_transmit_scbMode;
    extern uint8 uart_transmit_scbEnableWake;
    extern uint8 uart_transmit_scbEnableIntr;

    /* I2C configuration variables */
    extern uint8 uart_transmit_mode;
    extern uint8 uart_transmit_acceptAddr;

    /* SPI/UART configuration variables */
    extern volatile uint8 * uart_transmit_rxBuffer;
    extern uint8   uart_transmit_rxDataBits;
    extern uint32  uart_transmit_rxBufferSize;

    extern volatile uint8 * uart_transmit_txBuffer;
    extern uint8   uart_transmit_txDataBits;
    extern uint32  uart_transmit_txBufferSize;

    /* EZI2C configuration variables */
    extern uint8 uart_transmit_numberOfAddr;
    extern uint8 uart_transmit_subAddrSize;
#endif /* (uart_transmit_SCB_MODE_UNCONFIG_CONST_CFG) */

#if (! (uart_transmit_SCB_MODE_I2C_CONST_CFG || \
        uart_transmit_SCB_MODE_EZI2C_CONST_CFG))
    extern uint16 uart_transmit_IntrTxMask;
#endif /* (! (uart_transmit_SCB_MODE_I2C_CONST_CFG || \
              uart_transmit_SCB_MODE_EZI2C_CONST_CFG)) */


/***************************************
*        Conditional Macro
****************************************/

#if(uart_transmit_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Defines run time operation mode */
    #define uart_transmit_SCB_MODE_I2C_RUNTM_CFG     (uart_transmit_SCB_MODE_I2C      == uart_transmit_scbMode)
    #define uart_transmit_SCB_MODE_SPI_RUNTM_CFG     (uart_transmit_SCB_MODE_SPI      == uart_transmit_scbMode)
    #define uart_transmit_SCB_MODE_UART_RUNTM_CFG    (uart_transmit_SCB_MODE_UART     == uart_transmit_scbMode)
    #define uart_transmit_SCB_MODE_EZI2C_RUNTM_CFG   (uart_transmit_SCB_MODE_EZI2C    == uart_transmit_scbMode)
    #define uart_transmit_SCB_MODE_UNCONFIG_RUNTM_CFG \
                                                        (uart_transmit_SCB_MODE_UNCONFIG == uart_transmit_scbMode)

    /* Defines wakeup enable */
    #define uart_transmit_SCB_WAKE_ENABLE_CHECK       (0u != uart_transmit_scbEnableWake)
#endif /* (uart_transmit_SCB_MODE_UNCONFIG_CONST_CFG) */

/* Defines maximum number of SCB pins */
#if (!uart_transmit_CY_SCBIP_V1)
    #define uart_transmit_SCB_PINS_NUMBER    (7u)
#else
    #define uart_transmit_SCB_PINS_NUMBER    (2u)
#endif /* (!uart_transmit_CY_SCBIP_V1) */

#endif /* (CY_SCB_PVT_uart_transmit_H) */


/* [] END OF FILE */
