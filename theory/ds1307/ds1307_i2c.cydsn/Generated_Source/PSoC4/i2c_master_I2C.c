/***************************************************************************//**
* \file i2c_master_I2C.c
* \version 4.0
*
* \brief
*  This file provides the source code to the API for the SCB Component in
*  I2C mode.
*
* Note:
*
*******************************************************************************
* \copyright
* Copyright 2013-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "i2c_master_PVT.h"
#include "i2c_master_I2C_PVT.h"


/***************************************
*      I2C Private Vars
***************************************/

volatile uint8 i2c_master_state;  /* Current state of I2C FSM */

#if(i2c_master_SCB_MODE_UNCONFIG_CONST_CFG)

    /***************************************
    *  Configuration Structure Initialization
    ***************************************/

    /* Constant configuration of I2C */
    const i2c_master_I2C_INIT_STRUCT i2c_master_configI2C =
    {
        i2c_master_I2C_MODE,
        i2c_master_I2C_OVS_FACTOR_LOW,
        i2c_master_I2C_OVS_FACTOR_HIGH,
        i2c_master_I2C_MEDIAN_FILTER_ENABLE,
        i2c_master_I2C_SLAVE_ADDRESS,
        i2c_master_I2C_SLAVE_ADDRESS_MASK,
        i2c_master_I2C_ACCEPT_ADDRESS,
        i2c_master_I2C_WAKE_ENABLE,
        i2c_master_I2C_BYTE_MODE_ENABLE,
        i2c_master_I2C_DATA_RATE,
        i2c_master_I2C_ACCEPT_GENERAL_CALL,
    };

    /*******************************************************************************
    * Function Name: i2c_master_I2CInit
    ****************************************************************************//**
    *
    *
    *  Configures the i2c_master for I2C operation.
    *
    *  This function is intended specifically to be used when the i2c_master 
    *  configuration is set to “Unconfigured i2c_master” in the customizer. 
    *  After initializing the i2c_master in I2C mode using this function, 
    *  the component can be enabled using the i2c_master_Start() or 
    * i2c_master_Enable() function.
    *  This function uses a pointer to a structure that provides the configuration 
    *  settings. This structure contains the same information that would otherwise 
    *  be provided by the customizer settings.
    *
    *  \param config: pointer to a structure that contains the following list of 
    *   fields. These fields match the selections available in the customizer. 
    *   Refer to the customizer for further description of the settings.
    *
    *******************************************************************************/
    void i2c_master_I2CInit(const i2c_master_I2C_INIT_STRUCT *config)
    {
        uint32 medianFilter;
        uint32 locEnableWake;

        if(NULL == config)
        {
            CYASSERT(0u != 0u); /* Halt execution due to bad function parameter */
        }
        else
        {
            /* Configure pins */
            i2c_master_SetPins(i2c_master_SCB_MODE_I2C, i2c_master_DUMMY_PARAM,
                                     i2c_master_DUMMY_PARAM);

            /* Store internal configuration */
            i2c_master_scbMode       = (uint8) i2c_master_SCB_MODE_I2C;
            i2c_master_scbEnableWake = (uint8) config->enableWake;
            i2c_master_scbEnableIntr = (uint8) i2c_master_SCB_IRQ_INTERNAL;

            i2c_master_mode          = (uint8) config->mode;
            i2c_master_acceptAddr    = (uint8) config->acceptAddr;

        #if (i2c_master_CY_SCBIP_V0)
            /* Adjust SDA filter settings. Ticket ID#150521 */
            i2c_master_SET_I2C_CFG_SDA_FILT_TRIM(i2c_master_EC_AM_I2C_CFG_SDA_FILT_TRIM);
        #endif /* (i2c_master_CY_SCBIP_V0) */

            /* Adjust AF and DF filter settings. Ticket ID#176179 */
            if (((i2c_master_I2C_MODE_SLAVE != config->mode) &&
                 (config->dataRate <= i2c_master_I2C_DATA_RATE_FS_MODE_MAX)) ||
                 (i2c_master_I2C_MODE_SLAVE == config->mode))
            {
                /* AF = 1, DF = 0 */
                i2c_master_I2C_CFG_ANALOG_FITER_ENABLE;
                medianFilter = i2c_master_DIGITAL_FILTER_DISABLE;
            }
            else
            {
                /* AF = 0, DF = 1 */
                i2c_master_I2C_CFG_ANALOG_FITER_DISABLE;
                medianFilter = i2c_master_DIGITAL_FILTER_ENABLE;
            }

        #if (!i2c_master_CY_SCBIP_V0)
            locEnableWake = (i2c_master_I2C_MULTI_MASTER_SLAVE) ? (0u) : (config->enableWake);
        #else
            locEnableWake = config->enableWake;
        #endif /* (!i2c_master_CY_SCBIP_V0) */

            /* Configure I2C interface */
            i2c_master_CTRL_REG     = i2c_master_GET_CTRL_BYTE_MODE  (config->enableByteMode) |
                                            i2c_master_GET_CTRL_ADDR_ACCEPT(config->acceptAddr)     |
                                            i2c_master_GET_CTRL_EC_AM_MODE (locEnableWake);

            i2c_master_I2C_CTRL_REG = i2c_master_GET_I2C_CTRL_HIGH_PHASE_OVS(config->oversampleHigh) |
                    i2c_master_GET_I2C_CTRL_LOW_PHASE_OVS (config->oversampleLow)                          |
                    i2c_master_GET_I2C_CTRL_S_GENERAL_IGNORE((uint32)(0u == config->acceptGeneralAddr))    |
                    i2c_master_GET_I2C_CTRL_SL_MSTR_MODE  (config->mode);

            /* Configure RX direction */
            i2c_master_RX_CTRL_REG      = i2c_master_GET_RX_CTRL_MEDIAN(medianFilter) |
                                                i2c_master_I2C_RX_CTRL;
            i2c_master_RX_FIFO_CTRL_REG = i2c_master_CLEAR_REG;

            /* Set default address and mask */
            i2c_master_RX_MATCH_REG    = ((i2c_master_I2C_SLAVE) ?
                                                (i2c_master_GET_I2C_8BIT_ADDRESS(config->slaveAddr) |
                                                 i2c_master_GET_RX_MATCH_MASK(config->slaveAddrMask)) :
                                                (i2c_master_CLEAR_REG));


            /* Configure TX direction */
            i2c_master_TX_CTRL_REG      = i2c_master_I2C_TX_CTRL;
            i2c_master_TX_FIFO_CTRL_REG = i2c_master_CLEAR_REG;

            /* Configure interrupt with I2C handler but do not enable it */
            CyIntDisable    (i2c_master_ISR_NUMBER);
            CyIntSetPriority(i2c_master_ISR_NUMBER, i2c_master_ISR_PRIORITY);
            (void) CyIntSetVector(i2c_master_ISR_NUMBER, &i2c_master_I2C_ISR);

            /* Configure interrupt sources */
        #if(!i2c_master_CY_SCBIP_V1)
            i2c_master_INTR_SPI_EC_MASK_REG = i2c_master_NO_INTR_SOURCES;
        #endif /* (!i2c_master_CY_SCBIP_V1) */

            i2c_master_INTR_I2C_EC_MASK_REG = i2c_master_NO_INTR_SOURCES;
            i2c_master_INTR_RX_MASK_REG     = i2c_master_NO_INTR_SOURCES;
            i2c_master_INTR_TX_MASK_REG     = i2c_master_NO_INTR_SOURCES;

            i2c_master_INTR_SLAVE_MASK_REG  = ((i2c_master_I2C_SLAVE) ?
                            (i2c_master_GET_INTR_SLAVE_I2C_GENERAL(config->acceptGeneralAddr) |
                             i2c_master_I2C_INTR_SLAVE_MASK) : (i2c_master_CLEAR_REG));

            i2c_master_INTR_MASTER_MASK_REG = i2c_master_NO_INTR_SOURCES;

            /* Configure global variables */
            i2c_master_state = i2c_master_I2C_FSM_IDLE;

            /* Internal slave variables */
            i2c_master_slStatus        = 0u;
            i2c_master_slRdBufIndex    = 0u;
            i2c_master_slWrBufIndex    = 0u;
            i2c_master_slOverFlowCount = 0u;

            /* Internal master variables */
            i2c_master_mstrStatus     = 0u;
            i2c_master_mstrRdBufIndex = 0u;
            i2c_master_mstrWrBufIndex = 0u;
        }
    }

#else

    /*******************************************************************************
    * Function Name: i2c_master_I2CInit
    ****************************************************************************//**
    *
    *  Configures the SCB for the I2C operation.
    *
    *******************************************************************************/
    void i2c_master_I2CInit(void)
    {
    #if(i2c_master_CY_SCBIP_V0)
        /* Adjust SDA filter settings. Ticket ID#150521 */
        i2c_master_SET_I2C_CFG_SDA_FILT_TRIM(i2c_master_EC_AM_I2C_CFG_SDA_FILT_TRIM);
    #endif /* (i2c_master_CY_SCBIP_V0) */

        /* Adjust AF and DF filter settings. Ticket ID#176179 */
        i2c_master_I2C_CFG_ANALOG_FITER_ENABLE_ADJ;

        /* Configure I2C interface */
        i2c_master_CTRL_REG     = i2c_master_I2C_DEFAULT_CTRL;
        i2c_master_I2C_CTRL_REG = i2c_master_I2C_DEFAULT_I2C_CTRL;

        /* Configure RX direction */
        i2c_master_RX_CTRL_REG      = i2c_master_I2C_DEFAULT_RX_CTRL;
        i2c_master_RX_FIFO_CTRL_REG = i2c_master_I2C_DEFAULT_RX_FIFO_CTRL;

        /* Set default address and mask */
        i2c_master_RX_MATCH_REG     = i2c_master_I2C_DEFAULT_RX_MATCH;

        /* Configure TX direction */
        i2c_master_TX_CTRL_REG      = i2c_master_I2C_DEFAULT_TX_CTRL;
        i2c_master_TX_FIFO_CTRL_REG = i2c_master_I2C_DEFAULT_TX_FIFO_CTRL;

        /* Configure interrupt with I2C handler but do not enable it */
        CyIntDisable    (i2c_master_ISR_NUMBER);
        CyIntSetPriority(i2c_master_ISR_NUMBER, i2c_master_ISR_PRIORITY);
    #if(!i2c_master_I2C_EXTERN_INTR_HANDLER)
        (void) CyIntSetVector(i2c_master_ISR_NUMBER, &i2c_master_I2C_ISR);
    #endif /* (i2c_master_I2C_EXTERN_INTR_HANDLER) */

        /* Configure interrupt sources */
    #if(!i2c_master_CY_SCBIP_V1)
        i2c_master_INTR_SPI_EC_MASK_REG = i2c_master_I2C_DEFAULT_INTR_SPI_EC_MASK;
    #endif /* (!i2c_master_CY_SCBIP_V1) */

        i2c_master_INTR_I2C_EC_MASK_REG = i2c_master_I2C_DEFAULT_INTR_I2C_EC_MASK;
        i2c_master_INTR_SLAVE_MASK_REG  = i2c_master_I2C_DEFAULT_INTR_SLAVE_MASK;
        i2c_master_INTR_MASTER_MASK_REG = i2c_master_I2C_DEFAULT_INTR_MASTER_MASK;
        i2c_master_INTR_RX_MASK_REG     = i2c_master_I2C_DEFAULT_INTR_RX_MASK;
        i2c_master_INTR_TX_MASK_REG     = i2c_master_I2C_DEFAULT_INTR_TX_MASK;

        /* Configure global variables */
        i2c_master_state = i2c_master_I2C_FSM_IDLE;

    #if(i2c_master_I2C_SLAVE)
        /* Internal slave variable */
        i2c_master_slStatus        = 0u;
        i2c_master_slRdBufIndex    = 0u;
        i2c_master_slWrBufIndex    = 0u;
        i2c_master_slOverFlowCount = 0u;
    #endif /* (i2c_master_I2C_SLAVE) */

    #if(i2c_master_I2C_MASTER)
    /* Internal master variable */
        i2c_master_mstrStatus     = 0u;
        i2c_master_mstrRdBufIndex = 0u;
        i2c_master_mstrWrBufIndex = 0u;
    #endif /* (i2c_master_I2C_MASTER) */
    }
#endif /* (i2c_master_SCB_MODE_UNCONFIG_CONST_CFG) */


/*******************************************************************************
* Function Name: i2c_master_I2CStop
****************************************************************************//**
*
*  Resets the I2C FSM into the default state.
*
*******************************************************************************/
void i2c_master_I2CStop(void)
{
    /* Clear command registers because they keep assigned value after IP block was disabled */
    i2c_master_I2C_MASTER_CMD_REG = 0u;
    i2c_master_I2C_SLAVE_CMD_REG  = 0u;
    
    i2c_master_state = i2c_master_I2C_FSM_IDLE;
}


/*******************************************************************************
* Function Name: i2c_master_I2CFwBlockReset
****************************************************************************//**
*
* Resets the scb IP block and I2C into the known state.
*
*******************************************************************************/
void i2c_master_I2CFwBlockReset(void)
{
    /* Disable scb IP: stop respond to I2C traffic */
    i2c_master_CTRL_REG &= (uint32) ~i2c_master_CTRL_ENABLED;

    /* Clear command registers they are not cleared after scb IP is disabled */
    i2c_master_I2C_MASTER_CMD_REG = 0u;
    i2c_master_I2C_SLAVE_CMD_REG  = 0u;

    i2c_master_DISABLE_AUTO_DATA;

    i2c_master_SetTxInterruptMode(i2c_master_NO_INTR_SOURCES);
    i2c_master_SetRxInterruptMode(i2c_master_NO_INTR_SOURCES);
    
#if(i2c_master_CY_SCBIP_V0)
    /* Clear interrupt sources as they are not cleared after scb IP is disabled */
    i2c_master_ClearTxInterruptSource    (i2c_master_INTR_TX_ALL);
    i2c_master_ClearRxInterruptSource    (i2c_master_INTR_RX_ALL);
    i2c_master_ClearSlaveInterruptSource (i2c_master_INTR_SLAVE_ALL);
    i2c_master_ClearMasterInterruptSource(i2c_master_INTR_MASTER_ALL);
#endif /* (i2c_master_CY_SCBIP_V0) */

    i2c_master_state = i2c_master_I2C_FSM_IDLE;

    /* Enable scb IP: start respond to I2C traffic */
    i2c_master_CTRL_REG |= (uint32) i2c_master_CTRL_ENABLED;
}


#if(i2c_master_I2C_WAKE_ENABLE_CONST)
    /*******************************************************************************
    * Function Name: i2c_master_I2CSaveConfig
    ****************************************************************************//**
    *
    *  Enables i2c_master_INTR_I2C_EC_WAKE_UP interrupt source. This interrupt
    *  triggers on address match and wakes up device.
    *
    *******************************************************************************/
    void i2c_master_I2CSaveConfig(void)
    {
    #if (!i2c_master_CY_SCBIP_V0)
        #if (i2c_master_I2C_MULTI_MASTER_SLAVE_CONST && i2c_master_I2C_WAKE_ENABLE_CONST)
            /* Enable externally clocked address match if it was not enabled before.
            * This applicable only for Multi-Master-Slave. Ticket ID#192742 */
            if (0u == (i2c_master_CTRL_REG & i2c_master_CTRL_EC_AM_MODE))
            {
                /* Enable external address match logic */
                i2c_master_Stop();
                i2c_master_CTRL_REG |= i2c_master_CTRL_EC_AM_MODE;
                i2c_master_Enable();
            }
        #endif /* (i2c_master_I2C_MULTI_MASTER_SLAVE_CONST) */

        #if (i2c_master_SCB_CLK_INTERNAL)
            /* Disable clock to internal address match logic. Ticket ID#187931 */
            i2c_master_SCBCLK_Stop();
        #endif /* (i2c_master_SCB_CLK_INTERNAL) */
    #endif /* (!i2c_master_CY_SCBIP_V0) */

        i2c_master_SetI2CExtClkInterruptMode(i2c_master_INTR_I2C_EC_WAKE_UP);
    }


    /*******************************************************************************
    * Function Name: i2c_master_I2CRestoreConfig
    ****************************************************************************//**
    *
    *  Disables i2c_master_INTR_I2C_EC_WAKE_UP interrupt source. This interrupt
    *  triggers on address match and wakes up device.
    *
    *******************************************************************************/
    void i2c_master_I2CRestoreConfig(void)
    {
        /* Disable wakeup interrupt on address match */
        i2c_master_SetI2CExtClkInterruptMode(i2c_master_NO_INTR_SOURCES);

    #if (!i2c_master_CY_SCBIP_V0)
        #if (i2c_master_SCB_CLK_INTERNAL)
            /* Enable clock to internal address match logic. Ticket ID#187931 */
            i2c_master_SCBCLK_Start();
        #endif /* (i2c_master_SCB_CLK_INTERNAL) */
    #endif /* (!i2c_master_CY_SCBIP_V0) */
    }
#endif /* (i2c_master_I2C_WAKE_ENABLE_CONST) */


/* [] END OF FILE */
