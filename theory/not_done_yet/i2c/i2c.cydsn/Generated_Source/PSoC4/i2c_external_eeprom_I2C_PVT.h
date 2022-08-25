/***************************************************************************//**
* \file .h
* \version 4.0
*
* \brief
*  This private file provides constants and parameter values for the
*  SCB Component in I2C mode.
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

#if !defined(CY_SCB_I2C_PVT_i2c_external_eeprom_H)
#define CY_SCB_I2C_PVT_i2c_external_eeprom_H

#include "i2c_external_eeprom_I2C.h"


/***************************************
*     Private Global Vars
***************************************/

extern volatile uint8 i2c_external_eeprom_state; /* Current state of I2C FSM */

#if(i2c_external_eeprom_I2C_SLAVE_CONST)
    extern volatile uint8 i2c_external_eeprom_slStatus;          /* Slave Status */

    /* Receive buffer variables */
    extern volatile uint8 * i2c_external_eeprom_slWrBufPtr;      /* Pointer to Receive buffer  */
    extern volatile uint32  i2c_external_eeprom_slWrBufSize;     /* Slave Receive buffer size  */
    extern volatile uint32  i2c_external_eeprom_slWrBufIndex;    /* Slave Receive buffer Index */

    /* Transmit buffer variables */
    extern volatile uint8 * i2c_external_eeprom_slRdBufPtr;      /* Pointer to Transmit buffer  */
    extern volatile uint32  i2c_external_eeprom_slRdBufSize;     /* Slave Transmit buffer size  */
    extern volatile uint32  i2c_external_eeprom_slRdBufIndex;    /* Slave Transmit buffer Index */
    extern volatile uint32  i2c_external_eeprom_slRdBufIndexTmp; /* Slave Transmit buffer Index Tmp */
    extern volatile uint8   i2c_external_eeprom_slOverFlowCount; /* Slave Transmit Overflow counter */
#endif /* (i2c_external_eeprom_I2C_SLAVE_CONST) */

#if(i2c_external_eeprom_I2C_MASTER_CONST)
    extern volatile uint16 i2c_external_eeprom_mstrStatus;      /* Master Status byte  */
    extern volatile uint8  i2c_external_eeprom_mstrControl;     /* Master Control byte */

    /* Receive buffer variables */
    extern volatile uint8 * i2c_external_eeprom_mstrRdBufPtr;   /* Pointer to Master Read buffer */
    extern volatile uint32  i2c_external_eeprom_mstrRdBufSize;  /* Master Read buffer size       */
    extern volatile uint32  i2c_external_eeprom_mstrRdBufIndex; /* Master Read buffer Index      */

    /* Transmit buffer variables */
    extern volatile uint8 * i2c_external_eeprom_mstrWrBufPtr;   /* Pointer to Master Write buffer */
    extern volatile uint32  i2c_external_eeprom_mstrWrBufSize;  /* Master Write buffer size       */
    extern volatile uint32  i2c_external_eeprom_mstrWrBufIndex; /* Master Write buffer Index      */
    extern volatile uint32  i2c_external_eeprom_mstrWrBufIndexTmp; /* Master Write buffer Index Tmp */
#endif /* (i2c_external_eeprom_I2C_MASTER_CONST) */

#if (i2c_external_eeprom_I2C_CUSTOM_ADDRESS_HANDLER_CONST)
    extern uint32 (*i2c_external_eeprom_customAddressHandler) (void);
#endif /* (i2c_external_eeprom_I2C_CUSTOM_ADDRESS_HANDLER_CONST) */

/***************************************
*     Private Function Prototypes
***************************************/

#if(i2c_external_eeprom_SCB_MODE_I2C_CONST_CFG)
    void i2c_external_eeprom_I2CInit(void);
#endif /* (i2c_external_eeprom_SCB_MODE_I2C_CONST_CFG) */

void i2c_external_eeprom_I2CStop(void);
void i2c_external_eeprom_I2CFwBlockReset(void);

void i2c_external_eeprom_I2CSaveConfig(void);
void i2c_external_eeprom_I2CRestoreConfig(void);

#if(i2c_external_eeprom_I2C_MASTER_CONST)
    void i2c_external_eeprom_I2CReStartGeneration(void);
#endif /* (i2c_external_eeprom_I2C_MASTER_CONST) */

#endif /* (CY_SCB_I2C_PVT_i2c_external_eeprom_H) */


/* [] END OF FILE */
