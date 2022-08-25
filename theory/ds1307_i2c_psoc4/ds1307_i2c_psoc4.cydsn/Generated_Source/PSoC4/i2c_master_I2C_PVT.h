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

#if !defined(CY_SCB_I2C_PVT_i2c_master_H)
#define CY_SCB_I2C_PVT_i2c_master_H

#include "i2c_master_I2C.h"


/***************************************
*     Private Global Vars
***************************************/

extern volatile uint8 i2c_master_state; /* Current state of I2C FSM */

#if(i2c_master_I2C_SLAVE_CONST)
    extern volatile uint8 i2c_master_slStatus;          /* Slave Status */

    /* Receive buffer variables */
    extern volatile uint8 * i2c_master_slWrBufPtr;      /* Pointer to Receive buffer  */
    extern volatile uint32  i2c_master_slWrBufSize;     /* Slave Receive buffer size  */
    extern volatile uint32  i2c_master_slWrBufIndex;    /* Slave Receive buffer Index */

    /* Transmit buffer variables */
    extern volatile uint8 * i2c_master_slRdBufPtr;      /* Pointer to Transmit buffer  */
    extern volatile uint32  i2c_master_slRdBufSize;     /* Slave Transmit buffer size  */
    extern volatile uint32  i2c_master_slRdBufIndex;    /* Slave Transmit buffer Index */
    extern volatile uint32  i2c_master_slRdBufIndexTmp; /* Slave Transmit buffer Index Tmp */
    extern volatile uint8   i2c_master_slOverFlowCount; /* Slave Transmit Overflow counter */
#endif /* (i2c_master_I2C_SLAVE_CONST) */

#if(i2c_master_I2C_MASTER_CONST)
    extern volatile uint16 i2c_master_mstrStatus;      /* Master Status byte  */
    extern volatile uint8  i2c_master_mstrControl;     /* Master Control byte */

    /* Receive buffer variables */
    extern volatile uint8 * i2c_master_mstrRdBufPtr;   /* Pointer to Master Read buffer */
    extern volatile uint32  i2c_master_mstrRdBufSize;  /* Master Read buffer size       */
    extern volatile uint32  i2c_master_mstrRdBufIndex; /* Master Read buffer Index      */

    /* Transmit buffer variables */
    extern volatile uint8 * i2c_master_mstrWrBufPtr;   /* Pointer to Master Write buffer */
    extern volatile uint32  i2c_master_mstrWrBufSize;  /* Master Write buffer size       */
    extern volatile uint32  i2c_master_mstrWrBufIndex; /* Master Write buffer Index      */
    extern volatile uint32  i2c_master_mstrWrBufIndexTmp; /* Master Write buffer Index Tmp */
#endif /* (i2c_master_I2C_MASTER_CONST) */

#if (i2c_master_I2C_CUSTOM_ADDRESS_HANDLER_CONST)
    extern uint32 (*i2c_master_customAddressHandler) (void);
#endif /* (i2c_master_I2C_CUSTOM_ADDRESS_HANDLER_CONST) */

/***************************************
*     Private Function Prototypes
***************************************/

#if(i2c_master_SCB_MODE_I2C_CONST_CFG)
    void i2c_master_I2CInit(void);
#endif /* (i2c_master_SCB_MODE_I2C_CONST_CFG) */

void i2c_master_I2CStop(void);
void i2c_master_I2CFwBlockReset(void);

void i2c_master_I2CSaveConfig(void);
void i2c_master_I2CRestoreConfig(void);

#if(i2c_master_I2C_MASTER_CONST)
    void i2c_master_I2CReStartGeneration(void);
#endif /* (i2c_master_I2C_MASTER_CONST) */

#endif /* (CY_SCB_I2C_PVT_i2c_master_H) */


/* [] END OF FILE */
