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

#if !defined(CY_SCB_PVT_uartUser_H)
#define CY_SCB_PVT_uartUser_H

#include "uartUser.h"


/***************************************
*     Private Function Prototypes
***************************************/

/* APIs to service INTR_I2C_EC register */
#define uartUser_SetI2CExtClkInterruptMode(interruptMask) uartUser_WRITE_INTR_I2C_EC_MASK(interruptMask)
#define uartUser_ClearI2CExtClkInterruptSource(interruptMask) uartUser_CLEAR_INTR_I2C_EC(interruptMask)
#define uartUser_GetI2CExtClkInterruptSource()                (uartUser_INTR_I2C_EC_REG)
#define uartUser_GetI2CExtClkInterruptMode()                  (uartUser_INTR_I2C_EC_MASK_REG)
#define uartUser_GetI2CExtClkInterruptSourceMasked()          (uartUser_INTR_I2C_EC_MASKED_REG)

#if (!uartUser_CY_SCBIP_V1)
    /* APIs to service INTR_SPI_EC register */
    #define uartUser_SetSpiExtClkInterruptMode(interruptMask) \
                                                                uartUser_WRITE_INTR_SPI_EC_MASK(interruptMask)
    #define uartUser_ClearSpiExtClkInterruptSource(interruptMask) \
                                                                uartUser_CLEAR_INTR_SPI_EC(interruptMask)
    #define uartUser_GetExtSpiClkInterruptSource()                 (uartUser_INTR_SPI_EC_REG)
    #define uartUser_GetExtSpiClkInterruptMode()                   (uartUser_INTR_SPI_EC_MASK_REG)
    #define uartUser_GetExtSpiClkInterruptSourceMasked()           (uartUser_INTR_SPI_EC_MASKED_REG)
#endif /* (!uartUser_CY_SCBIP_V1) */

#if(uartUser_SCB_MODE_UNCONFIG_CONST_CFG)
    extern void uartUser_SetPins(uint32 mode, uint32 subMode, uint32 uartEnableMask);
#endif /* (uartUser_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*     Vars with External Linkage
***************************************/

#if (uartUser_SCB_IRQ_INTERNAL)
#if !defined (CY_REMOVE_uartUser_CUSTOM_INTR_HANDLER)
    extern cyisraddress uartUser_customIntrHandler;
#endif /* !defined (CY_REMOVE_uartUser_CUSTOM_INTR_HANDLER) */
#endif /* (uartUser_SCB_IRQ_INTERNAL) */

extern uartUser_BACKUP_STRUCT uartUser_backup;

#if(uartUser_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Common configuration variables */
    extern uint8 uartUser_scbMode;
    extern uint8 uartUser_scbEnableWake;
    extern uint8 uartUser_scbEnableIntr;

    /* I2C configuration variables */
    extern uint8 uartUser_mode;
    extern uint8 uartUser_acceptAddr;

    /* SPI/UART configuration variables */
    extern volatile uint8 * uartUser_rxBuffer;
    extern uint8   uartUser_rxDataBits;
    extern uint32  uartUser_rxBufferSize;

    extern volatile uint8 * uartUser_txBuffer;
    extern uint8   uartUser_txDataBits;
    extern uint32  uartUser_txBufferSize;

    /* EZI2C configuration variables */
    extern uint8 uartUser_numberOfAddr;
    extern uint8 uartUser_subAddrSize;
#endif /* (uartUser_SCB_MODE_UNCONFIG_CONST_CFG) */

#if (! (uartUser_SCB_MODE_I2C_CONST_CFG || \
        uartUser_SCB_MODE_EZI2C_CONST_CFG))
    extern uint16 uartUser_IntrTxMask;
#endif /* (! (uartUser_SCB_MODE_I2C_CONST_CFG || \
              uartUser_SCB_MODE_EZI2C_CONST_CFG)) */


/***************************************
*        Conditional Macro
****************************************/

#if(uartUser_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Defines run time operation mode */
    #define uartUser_SCB_MODE_I2C_RUNTM_CFG     (uartUser_SCB_MODE_I2C      == uartUser_scbMode)
    #define uartUser_SCB_MODE_SPI_RUNTM_CFG     (uartUser_SCB_MODE_SPI      == uartUser_scbMode)
    #define uartUser_SCB_MODE_UART_RUNTM_CFG    (uartUser_SCB_MODE_UART     == uartUser_scbMode)
    #define uartUser_SCB_MODE_EZI2C_RUNTM_CFG   (uartUser_SCB_MODE_EZI2C    == uartUser_scbMode)
    #define uartUser_SCB_MODE_UNCONFIG_RUNTM_CFG \
                                                        (uartUser_SCB_MODE_UNCONFIG == uartUser_scbMode)

    /* Defines wakeup enable */
    #define uartUser_SCB_WAKE_ENABLE_CHECK       (0u != uartUser_scbEnableWake)
#endif /* (uartUser_SCB_MODE_UNCONFIG_CONST_CFG) */

/* Defines maximum number of SCB pins */
#if (!uartUser_CY_SCBIP_V1)
    #define uartUser_SCB_PINS_NUMBER    (7u)
#else
    #define uartUser_SCB_PINS_NUMBER    (2u)
#endif /* (!uartUser_CY_SCBIP_V1) */

#endif /* (CY_SCB_PVT_uartUser_H) */


/* [] END OF FILE */
