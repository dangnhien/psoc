/***************************************************************************//**
* \file .h
* \version 4.0
*
* \brief
*  This private file provides constants and parameter values for the
*  SCB Component in _EZI2C mode.
*  Do not use this file or its content in your project.
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

#if !defined(CY_SCB_EZI2C_PVT_i2c_user_H)
#define CY_SCB_EZI2C_PVT_i2c_user_H

#include "i2c_user_EZI2C.h"


/***************************************
*      EZI2C Private Vars
***************************************/

extern volatile uint8 i2c_user_curStatus;
extern uint8 i2c_user_fsmState;

/* Variables intended to be used with Buffer 1: Primary slave address */
extern volatile uint8 * i2c_user_dataBuffer1;
extern uint16 i2c_user_bufSizeBuf1;
extern uint16 i2c_user_protectBuf1;
extern uint8 i2c_user_offsetBuf1;
extern uint16 i2c_user_indexBuf1;

#if(i2c_user_SECONDARY_ADDRESS_ENABLE_CONST)
    extern uint8 i2c_user_addrBuf1;
    extern uint8 i2c_user_addrBuf2;

    /* Variables intended to be used with Buffer 2: Primary slave address */
    extern volatile uint8 * i2c_user_dataBuffer2;
    extern uint16 i2c_user_bufSizeBuf2;
    extern uint16 i2c_user_protectBuf2;
    extern uint8 i2c_user_offsetBuf2;
    extern uint16 i2c_user_indexBuf2;
#endif /* (i2c_user_SECONDARY_ADDRESS_ENABLE_CONST) */


/***************************************
*     Private Function Prototypes
***************************************/

#if(i2c_user_SCB_MODE_EZI2C_CONST_CFG)
    void i2c_user_EzI2CInit(void);
#endif /* (i2c_user_SCB_MODE_EZI2C_CONST_CFG) */

void i2c_user_EzI2CStop(void);
#if(i2c_user_EZI2C_WAKE_ENABLE_CONST)
    void i2c_user_EzI2CSaveConfig(void);
    void i2c_user_EzI2CRestoreConfig(void);
#endif /* (i2c_user_EZI2C_WAKE_ENABLE_CONST) */

#endif /* (CY_SCB__EZI2C_PVT_i2c_user_H) */


/* [] END OF FILE */
