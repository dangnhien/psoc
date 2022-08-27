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

#if !defined(CY_SCB_PVT_i2c_master_H)
#define CY_SCB_PVT_i2c_master_H

#include "i2c_master.h"


/***************************************
*     Private Function Prototypes
***************************************/

/* APIs to service INTR_I2C_EC register */
#define i2c_master_SetI2CExtClkInterruptMode(interruptMask) i2c_master_WRITE_INTR_I2C_EC_MASK(interruptMask)
#define i2c_master_ClearI2CExtClkInterruptSource(interruptMask) i2c_master_CLEAR_INTR_I2C_EC(interruptMask)
#define i2c_master_GetI2CExtClkInterruptSource()                (i2c_master_INTR_I2C_EC_REG)
#define i2c_master_GetI2CExtClkInterruptMode()                  (i2c_master_INTR_I2C_EC_MASK_REG)
#define i2c_master_GetI2CExtClkInterruptSourceMasked()          (i2c_master_INTR_I2C_EC_MASKED_REG)

#if (!i2c_master_CY_SCBIP_V1)
    /* APIs to service INTR_SPI_EC register */
    #define i2c_master_SetSpiExtClkInterruptMode(interruptMask) \
                                                                i2c_master_WRITE_INTR_SPI_EC_MASK(interruptMask)
    #define i2c_master_ClearSpiExtClkInterruptSource(interruptMask) \
                                                                i2c_master_CLEAR_INTR_SPI_EC(interruptMask)
    #define i2c_master_GetExtSpiClkInterruptSource()                 (i2c_master_INTR_SPI_EC_REG)
    #define i2c_master_GetExtSpiClkInterruptMode()                   (i2c_master_INTR_SPI_EC_MASK_REG)
    #define i2c_master_GetExtSpiClkInterruptSourceMasked()           (i2c_master_INTR_SPI_EC_MASKED_REG)
#endif /* (!i2c_master_CY_SCBIP_V1) */

#if(i2c_master_SCB_MODE_UNCONFIG_CONST_CFG)
    extern void i2c_master_SetPins(uint32 mode, uint32 subMode, uint32 uartEnableMask);
#endif /* (i2c_master_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*     Vars with External Linkage
***************************************/

#if (i2c_master_SCB_IRQ_INTERNAL)
#if !defined (CY_REMOVE_i2c_master_CUSTOM_INTR_HANDLER)
    extern cyisraddress i2c_master_customIntrHandler;
#endif /* !defined (CY_REMOVE_i2c_master_CUSTOM_INTR_HANDLER) */
#endif /* (i2c_master_SCB_IRQ_INTERNAL) */

extern i2c_master_BACKUP_STRUCT i2c_master_backup;

#if(i2c_master_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Common configuration variables */
    extern uint8 i2c_master_scbMode;
    extern uint8 i2c_master_scbEnableWake;
    extern uint8 i2c_master_scbEnableIntr;

    /* I2C configuration variables */
    extern uint8 i2c_master_mode;
    extern uint8 i2c_master_acceptAddr;

    /* SPI/UART configuration variables */
    extern volatile uint8 * i2c_master_rxBuffer;
    extern uint8   i2c_master_rxDataBits;
    extern uint32  i2c_master_rxBufferSize;

    extern volatile uint8 * i2c_master_txBuffer;
    extern uint8   i2c_master_txDataBits;
    extern uint32  i2c_master_txBufferSize;

    /* EZI2C configuration variables */
    extern uint8 i2c_master_numberOfAddr;
    extern uint8 i2c_master_subAddrSize;
#endif /* (i2c_master_SCB_MODE_UNCONFIG_CONST_CFG) */

#if (! (i2c_master_SCB_MODE_I2C_CONST_CFG || \
        i2c_master_SCB_MODE_EZI2C_CONST_CFG))
    extern uint16 i2c_master_IntrTxMask;
#endif /* (! (i2c_master_SCB_MODE_I2C_CONST_CFG || \
              i2c_master_SCB_MODE_EZI2C_CONST_CFG)) */


/***************************************
*        Conditional Macro
****************************************/

#if(i2c_master_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Defines run time operation mode */
    #define i2c_master_SCB_MODE_I2C_RUNTM_CFG     (i2c_master_SCB_MODE_I2C      == i2c_master_scbMode)
    #define i2c_master_SCB_MODE_SPI_RUNTM_CFG     (i2c_master_SCB_MODE_SPI      == i2c_master_scbMode)
    #define i2c_master_SCB_MODE_UART_RUNTM_CFG    (i2c_master_SCB_MODE_UART     == i2c_master_scbMode)
    #define i2c_master_SCB_MODE_EZI2C_RUNTM_CFG   (i2c_master_SCB_MODE_EZI2C    == i2c_master_scbMode)
    #define i2c_master_SCB_MODE_UNCONFIG_RUNTM_CFG \
                                                        (i2c_master_SCB_MODE_UNCONFIG == i2c_master_scbMode)

    /* Defines wakeup enable */
    #define i2c_master_SCB_WAKE_ENABLE_CHECK       (0u != i2c_master_scbEnableWake)
#endif /* (i2c_master_SCB_MODE_UNCONFIG_CONST_CFG) */

/* Defines maximum number of SCB pins */
#if (!i2c_master_CY_SCBIP_V1)
    #define i2c_master_SCB_PINS_NUMBER    (7u)
#else
    #define i2c_master_SCB_PINS_NUMBER    (2u)
#endif /* (!i2c_master_CY_SCBIP_V1) */

#endif /* (CY_SCB_PVT_i2c_master_H) */


/* [] END OF FILE */
