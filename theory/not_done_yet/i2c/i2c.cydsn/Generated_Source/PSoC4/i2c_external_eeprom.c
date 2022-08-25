/***************************************************************************//**
* \file i2c_external_eeprom.c
* \version 4.0
*
* \brief
*  This file provides the source code to the API for the SCB Component.
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

#include "i2c_external_eeprom_PVT.h"

#if (i2c_external_eeprom_SCB_MODE_I2C_INC)
    #include "i2c_external_eeprom_I2C_PVT.h"
#endif /* (i2c_external_eeprom_SCB_MODE_I2C_INC) */

#if (i2c_external_eeprom_SCB_MODE_EZI2C_INC)
    #include "i2c_external_eeprom_EZI2C_PVT.h"
#endif /* (i2c_external_eeprom_SCB_MODE_EZI2C_INC) */

#if (i2c_external_eeprom_SCB_MODE_SPI_INC || i2c_external_eeprom_SCB_MODE_UART_INC)
    #include "i2c_external_eeprom_SPI_UART_PVT.h"
#endif /* (i2c_external_eeprom_SCB_MODE_SPI_INC || i2c_external_eeprom_SCB_MODE_UART_INC) */


/***************************************
*    Run Time Configuration Vars
***************************************/

/* Stores internal component configuration for Unconfigured mode */
#if (i2c_external_eeprom_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Common configuration variables */
    uint8 i2c_external_eeprom_scbMode = i2c_external_eeprom_SCB_MODE_UNCONFIG;
    uint8 i2c_external_eeprom_scbEnableWake;
    uint8 i2c_external_eeprom_scbEnableIntr;

    /* I2C configuration variables */
    uint8 i2c_external_eeprom_mode;
    uint8 i2c_external_eeprom_acceptAddr;

    /* SPI/UART configuration variables */
    volatile uint8 * i2c_external_eeprom_rxBuffer;
    uint8  i2c_external_eeprom_rxDataBits;
    uint32 i2c_external_eeprom_rxBufferSize;

    volatile uint8 * i2c_external_eeprom_txBuffer;
    uint8  i2c_external_eeprom_txDataBits;
    uint32 i2c_external_eeprom_txBufferSize;

    /* EZI2C configuration variables */
    uint8 i2c_external_eeprom_numberOfAddr;
    uint8 i2c_external_eeprom_subAddrSize;
#endif /* (i2c_external_eeprom_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*     Common SCB Vars
***************************************/
/**
* \addtogroup group_general
* \{
*/

/** i2c_external_eeprom_initVar indicates whether the i2c_external_eeprom 
*  component has been initialized. The variable is initialized to 0 
*  and set to 1 the first time SCB_Start() is called. This allows 
*  the component to restart without reinitialization after the first 
*  call to the i2c_external_eeprom_Start() routine.
*
*  If re-initialization of the component is required, then the 
*  i2c_external_eeprom_Init() function can be called before the 
*  i2c_external_eeprom_Start() or i2c_external_eeprom_Enable() function.
*/
uint8 i2c_external_eeprom_initVar = 0u;


#if (! (i2c_external_eeprom_SCB_MODE_I2C_CONST_CFG || \
        i2c_external_eeprom_SCB_MODE_EZI2C_CONST_CFG))
    /** This global variable stores TX interrupt sources after 
    * i2c_external_eeprom_Stop() is called. Only these TX interrupt sources 
    * will be restored on a subsequent i2c_external_eeprom_Enable() call.
    */
    uint16 i2c_external_eeprom_IntrTxMask = 0u;
#endif /* (! (i2c_external_eeprom_SCB_MODE_I2C_CONST_CFG || \
              i2c_external_eeprom_SCB_MODE_EZI2C_CONST_CFG)) */
/** \} globals */

#if (i2c_external_eeprom_SCB_IRQ_INTERNAL)
#if !defined (CY_REMOVE_i2c_external_eeprom_CUSTOM_INTR_HANDLER)
    void (*i2c_external_eeprom_customIntrHandler)(void) = NULL;
#endif /* !defined (CY_REMOVE_i2c_external_eeprom_CUSTOM_INTR_HANDLER) */
#endif /* (i2c_external_eeprom_SCB_IRQ_INTERNAL) */


/***************************************
*    Private Function Prototypes
***************************************/

static void i2c_external_eeprom_ScbEnableIntr(void);
static void i2c_external_eeprom_ScbModeStop(void);
static void i2c_external_eeprom_ScbModePostEnable(void);


/*******************************************************************************
* Function Name: i2c_external_eeprom_Init
****************************************************************************//**
*
*  Initializes the i2c_external_eeprom component to operate in one of the selected
*  configurations: I2C, SPI, UART or EZI2C.
*  When the configuration is set to "Unconfigured SCB", this function does
*  not do any initialization. Use mode-specific initialization APIs instead:
*  i2c_external_eeprom_I2CInit, i2c_external_eeprom_SpiInit, 
*  i2c_external_eeprom_UartInit or i2c_external_eeprom_EzI2CInit.
*
*******************************************************************************/
void i2c_external_eeprom_Init(void)
{
#if (i2c_external_eeprom_SCB_MODE_UNCONFIG_CONST_CFG)
    if (i2c_external_eeprom_SCB_MODE_UNCONFIG_RUNTM_CFG)
    {
        i2c_external_eeprom_initVar = 0u;
    }
    else
    {
        /* Initialization was done before this function call */
    }

#elif (i2c_external_eeprom_SCB_MODE_I2C_CONST_CFG)
    i2c_external_eeprom_I2CInit();

#elif (i2c_external_eeprom_SCB_MODE_SPI_CONST_CFG)
    i2c_external_eeprom_SpiInit();

#elif (i2c_external_eeprom_SCB_MODE_UART_CONST_CFG)
    i2c_external_eeprom_UartInit();

#elif (i2c_external_eeprom_SCB_MODE_EZI2C_CONST_CFG)
    i2c_external_eeprom_EzI2CInit();

#endif /* (i2c_external_eeprom_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: i2c_external_eeprom_Enable
****************************************************************************//**
*
*  Enables i2c_external_eeprom component operation: activates the hardware and 
*  internal interrupt. It also restores TX interrupt sources disabled after the 
*  i2c_external_eeprom_Stop() function was called (note that level-triggered TX 
*  interrupt sources remain disabled to not cause code lock-up).
*  For I2C and EZI2C modes the interrupt is internal and mandatory for 
*  operation. For SPI and UART modes the interrupt can be configured as none, 
*  internal or external.
*  The i2c_external_eeprom configuration should be not changed when the component
*  is enabled. Any configuration changes should be made after disabling the 
*  component.
*  When configuration is set to “Unconfigured i2c_external_eeprom”, the component 
*  must first be initialized to operate in one of the following configurations: 
*  I2C, SPI, UART or EZ I2C, using the mode-specific initialization API. 
*  Otherwise this function does not enable the component.
*
*******************************************************************************/
void i2c_external_eeprom_Enable(void)
{
#if (i2c_external_eeprom_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Enable SCB block, only if it is already configured */
    if (!i2c_external_eeprom_SCB_MODE_UNCONFIG_RUNTM_CFG)
    {
        i2c_external_eeprom_CTRL_REG |= i2c_external_eeprom_CTRL_ENABLED;

        i2c_external_eeprom_ScbEnableIntr();

        /* Call PostEnable function specific to current operation mode */
        i2c_external_eeprom_ScbModePostEnable();
    }
#else
    i2c_external_eeprom_CTRL_REG |= i2c_external_eeprom_CTRL_ENABLED;

    i2c_external_eeprom_ScbEnableIntr();

    /* Call PostEnable function specific to current operation mode */
    i2c_external_eeprom_ScbModePostEnable();
#endif /* (i2c_external_eeprom_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: i2c_external_eeprom_Start
****************************************************************************//**
*
*  Invokes i2c_external_eeprom_Init() and i2c_external_eeprom_Enable().
*  After this function call, the component is enabled and ready for operation.
*  When configuration is set to "Unconfigured SCB", the component must first be
*  initialized to operate in one of the following configurations: I2C, SPI, UART
*  or EZI2C. Otherwise this function does not enable the component.
*
* \globalvars
*  i2c_external_eeprom_initVar - used to check initial configuration, modified
*  on first function call.
*
*******************************************************************************/
void i2c_external_eeprom_Start(void)
{
    if (0u == i2c_external_eeprom_initVar)
    {
        i2c_external_eeprom_Init();
        i2c_external_eeprom_initVar = 1u; /* Component was initialized */
    }

    i2c_external_eeprom_Enable();
}


/*******************************************************************************
* Function Name: i2c_external_eeprom_Stop
****************************************************************************//**
*
*  Disables the i2c_external_eeprom component: disable the hardware and internal 
*  interrupt. It also disables all TX interrupt sources so as not to cause an 
*  unexpected interrupt trigger because after the component is enabled, the 
*  TX FIFO is empty.
*  Refer to the function i2c_external_eeprom_Enable() for the interrupt 
*  configuration details.
*  This function disables the SCB component without checking to see if 
*  communication is in progress. Before calling this function it may be 
*  necessary to check the status of communication to make sure communication 
*  is complete. If this is not done then communication could be stopped mid 
*  byte and corrupted data could result.
*
*******************************************************************************/
void i2c_external_eeprom_Stop(void)
{
#if (i2c_external_eeprom_SCB_IRQ_INTERNAL)
    i2c_external_eeprom_DisableInt();
#endif /* (i2c_external_eeprom_SCB_IRQ_INTERNAL) */

    /* Call Stop function specific to current operation mode */
    i2c_external_eeprom_ScbModeStop();

    /* Disable SCB IP */
    i2c_external_eeprom_CTRL_REG &= (uint32) ~i2c_external_eeprom_CTRL_ENABLED;

    /* Disable all TX interrupt sources so as not to cause an unexpected
    * interrupt trigger after the component will be enabled because the 
    * TX FIFO is empty.
    * For SCB IP v0, it is critical as it does not mask-out interrupt
    * sources when it is disabled. This can cause a code lock-up in the
    * interrupt handler because TX FIFO cannot be loaded after the block
    * is disabled.
    */
    i2c_external_eeprom_SetTxInterruptMode(i2c_external_eeprom_NO_INTR_SOURCES);

#if (i2c_external_eeprom_SCB_IRQ_INTERNAL)
    i2c_external_eeprom_ClearPendingInt();
#endif /* (i2c_external_eeprom_SCB_IRQ_INTERNAL) */
}


/*******************************************************************************
* Function Name: i2c_external_eeprom_SetRxFifoLevel
****************************************************************************//**
*
*  Sets level in the RX FIFO to generate a RX level interrupt.
*  When the RX FIFO has more entries than the RX FIFO level an RX level
*  interrupt request is generated.
*
*  \param level: Level in the RX FIFO to generate RX level interrupt.
*   The range of valid level values is between 0 and RX FIFO depth - 1.
*
*******************************************************************************/
void i2c_external_eeprom_SetRxFifoLevel(uint32 level)
{
    uint32 rxFifoCtrl;

    rxFifoCtrl = i2c_external_eeprom_RX_FIFO_CTRL_REG;

    rxFifoCtrl &= ((uint32) ~i2c_external_eeprom_RX_FIFO_CTRL_TRIGGER_LEVEL_MASK); /* Clear level mask bits */
    rxFifoCtrl |= ((uint32) (i2c_external_eeprom_RX_FIFO_CTRL_TRIGGER_LEVEL_MASK & level));

    i2c_external_eeprom_RX_FIFO_CTRL_REG = rxFifoCtrl;
}


/*******************************************************************************
* Function Name: i2c_external_eeprom_SetTxFifoLevel
****************************************************************************//**
*
*  Sets level in the TX FIFO to generate a TX level interrupt.
*  When the TX FIFO has less entries than the TX FIFO level an TX level
*  interrupt request is generated.
*
*  \param level: Level in the TX FIFO to generate TX level interrupt.
*   The range of valid level values is between 0 and TX FIFO depth - 1.
*
*******************************************************************************/
void i2c_external_eeprom_SetTxFifoLevel(uint32 level)
{
    uint32 txFifoCtrl;

    txFifoCtrl = i2c_external_eeprom_TX_FIFO_CTRL_REG;

    txFifoCtrl &= ((uint32) ~i2c_external_eeprom_TX_FIFO_CTRL_TRIGGER_LEVEL_MASK); /* Clear level mask bits */
    txFifoCtrl |= ((uint32) (i2c_external_eeprom_TX_FIFO_CTRL_TRIGGER_LEVEL_MASK & level));

    i2c_external_eeprom_TX_FIFO_CTRL_REG = txFifoCtrl;
}


#if (i2c_external_eeprom_SCB_IRQ_INTERNAL)
    /*******************************************************************************
    * Function Name: i2c_external_eeprom_SetCustomInterruptHandler
    ****************************************************************************//**
    *
    *  Registers a function to be called by the internal interrupt handler.
    *  First the function that is registered is called, then the internal interrupt
    *  handler performs any operation such as software buffer management functions
    *  before the interrupt returns.  It is the user's responsibility not to break
    *  the software buffer operations. Only one custom handler is supported, which
    *  is the function provided by the most recent call.
    *  At the initialization time no custom handler is registered.
    *
    *  \param func: Pointer to the function to register.
    *        The value NULL indicates to remove the current custom interrupt
    *        handler.
    *
    *******************************************************************************/
    void i2c_external_eeprom_SetCustomInterruptHandler(void (*func)(void))
    {
    #if !defined (CY_REMOVE_i2c_external_eeprom_CUSTOM_INTR_HANDLER)
        i2c_external_eeprom_customIntrHandler = func; /* Register interrupt handler */
    #else
        if (NULL != func)
        {
            /* Suppress compiler warning */
        }
    #endif /* !defined (CY_REMOVE_i2c_external_eeprom_CUSTOM_INTR_HANDLER) */
    }
#endif /* (i2c_external_eeprom_SCB_IRQ_INTERNAL) */


/*******************************************************************************
* Function Name: i2c_external_eeprom_ScbModeEnableIntr
****************************************************************************//**
*
*  Enables an interrupt for a specific mode.
*
*******************************************************************************/
static void i2c_external_eeprom_ScbEnableIntr(void)
{
#if (i2c_external_eeprom_SCB_IRQ_INTERNAL)
    /* Enable interrupt in NVIC */
    #if (i2c_external_eeprom_SCB_MODE_UNCONFIG_CONST_CFG)
        if (0u != i2c_external_eeprom_scbEnableIntr)
        {
            i2c_external_eeprom_EnableInt();
        }

    #else
        i2c_external_eeprom_EnableInt();

    #endif /* (i2c_external_eeprom_SCB_MODE_UNCONFIG_CONST_CFG) */
#endif /* (i2c_external_eeprom_SCB_IRQ_INTERNAL) */
}


/*******************************************************************************
* Function Name: i2c_external_eeprom_ScbModePostEnable
****************************************************************************//**
*
*  Calls the PostEnable function for a specific operation mode.
*
*******************************************************************************/
static void i2c_external_eeprom_ScbModePostEnable(void)
{
#if (i2c_external_eeprom_SCB_MODE_UNCONFIG_CONST_CFG)
#if (!i2c_external_eeprom_CY_SCBIP_V1)
    if (i2c_external_eeprom_SCB_MODE_SPI_RUNTM_CFG)
    {
        i2c_external_eeprom_SpiPostEnable();
    }
    else if (i2c_external_eeprom_SCB_MODE_UART_RUNTM_CFG)
    {
        i2c_external_eeprom_UartPostEnable();
    }
    else
    {
        /* Unknown mode: do nothing */
    }
#endif /* (!i2c_external_eeprom_CY_SCBIP_V1) */

#elif (i2c_external_eeprom_SCB_MODE_SPI_CONST_CFG)
    i2c_external_eeprom_SpiPostEnable();

#elif (i2c_external_eeprom_SCB_MODE_UART_CONST_CFG)
    i2c_external_eeprom_UartPostEnable();

#else
    /* Unknown mode: do nothing */
#endif /* (i2c_external_eeprom_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: i2c_external_eeprom_ScbModeStop
****************************************************************************//**
*
*  Calls the Stop function for a specific operation mode.
*
*******************************************************************************/
static void i2c_external_eeprom_ScbModeStop(void)
{
#if (i2c_external_eeprom_SCB_MODE_UNCONFIG_CONST_CFG)
    if (i2c_external_eeprom_SCB_MODE_I2C_RUNTM_CFG)
    {
        i2c_external_eeprom_I2CStop();
    }
    else if (i2c_external_eeprom_SCB_MODE_EZI2C_RUNTM_CFG)
    {
        i2c_external_eeprom_EzI2CStop();
    }
#if (!i2c_external_eeprom_CY_SCBIP_V1)
    else if (i2c_external_eeprom_SCB_MODE_SPI_RUNTM_CFG)
    {
        i2c_external_eeprom_SpiStop();
    }
    else if (i2c_external_eeprom_SCB_MODE_UART_RUNTM_CFG)
    {
        i2c_external_eeprom_UartStop();
    }
#endif /* (!i2c_external_eeprom_CY_SCBIP_V1) */
    else
    {
        /* Unknown mode: do nothing */
    }
#elif (i2c_external_eeprom_SCB_MODE_I2C_CONST_CFG)
    i2c_external_eeprom_I2CStop();

#elif (i2c_external_eeprom_SCB_MODE_EZI2C_CONST_CFG)
    i2c_external_eeprom_EzI2CStop();

#elif (i2c_external_eeprom_SCB_MODE_SPI_CONST_CFG)
    i2c_external_eeprom_SpiStop();

#elif (i2c_external_eeprom_SCB_MODE_UART_CONST_CFG)
    i2c_external_eeprom_UartStop();

#else
    /* Unknown mode: do nothing */
#endif /* (i2c_external_eeprom_SCB_MODE_UNCONFIG_CONST_CFG) */
}


#if (i2c_external_eeprom_SCB_MODE_UNCONFIG_CONST_CFG)
    /*******************************************************************************
    * Function Name: i2c_external_eeprom_SetPins
    ****************************************************************************//**
    *
    *  Sets the pins settings accordingly to the selected operation mode.
    *  Only available in the Unconfigured operation mode. The mode specific
    *  initialization function calls it.
    *  Pins configuration is set by PSoC Creator when a specific mode of operation
    *  is selected in design time.
    *
    *  \param mode:      Mode of SCB operation.
    *  \param subMode:   Sub-mode of SCB operation. It is only required for SPI and UART
    *             modes.
    *  \param uartEnableMask: enables TX or RX direction and RTS and CTS signals.
    *
    *******************************************************************************/
    void i2c_external_eeprom_SetPins(uint32 mode, uint32 subMode, uint32 uartEnableMask)
    {
        uint32 pinsDm[i2c_external_eeprom_SCB_PINS_NUMBER];
        uint32 i;
        
    #if (!i2c_external_eeprom_CY_SCBIP_V1)
        uint32 pinsInBuf = 0u;
    #endif /* (!i2c_external_eeprom_CY_SCBIP_V1) */
        
        uint32 hsiomSel[i2c_external_eeprom_SCB_PINS_NUMBER] = 
        {
            i2c_external_eeprom_RX_SCL_MOSI_HSIOM_SEL_GPIO,
            i2c_external_eeprom_TX_SDA_MISO_HSIOM_SEL_GPIO,
            0u,
            0u,
            0u,
            0u,
            0u,
        };

    #if (i2c_external_eeprom_CY_SCBIP_V1)
        /* Supress compiler warning. */
        if ((0u == subMode) || (0u == uartEnableMask))
        {
        }
    #endif /* (i2c_external_eeprom_CY_SCBIP_V1) */

        /* Set default HSIOM to GPIO and Drive Mode to Analog Hi-Z */
        for (i = 0u; i < i2c_external_eeprom_SCB_PINS_NUMBER; i++)
        {
            pinsDm[i] = i2c_external_eeprom_PIN_DM_ALG_HIZ;
        }

        if ((i2c_external_eeprom_SCB_MODE_I2C   == mode) ||
            (i2c_external_eeprom_SCB_MODE_EZI2C == mode))
        {
        #if (i2c_external_eeprom_RX_SCL_MOSI_PIN)
            hsiomSel[i2c_external_eeprom_RX_SCL_MOSI_PIN_INDEX] = i2c_external_eeprom_RX_SCL_MOSI_HSIOM_SEL_I2C;
            pinsDm  [i2c_external_eeprom_RX_SCL_MOSI_PIN_INDEX] = i2c_external_eeprom_PIN_DM_OD_LO;
        #elif (i2c_external_eeprom_RX_WAKE_SCL_MOSI_PIN)
            hsiomSel[i2c_external_eeprom_RX_WAKE_SCL_MOSI_PIN_INDEX] = i2c_external_eeprom_RX_WAKE_SCL_MOSI_HSIOM_SEL_I2C;
            pinsDm  [i2c_external_eeprom_RX_WAKE_SCL_MOSI_PIN_INDEX] = i2c_external_eeprom_PIN_DM_OD_LO;
        #else
        #endif /* (i2c_external_eeprom_RX_SCL_MOSI_PIN) */
        
        #if (i2c_external_eeprom_TX_SDA_MISO_PIN)
            hsiomSel[i2c_external_eeprom_TX_SDA_MISO_PIN_INDEX] = i2c_external_eeprom_TX_SDA_MISO_HSIOM_SEL_I2C;
            pinsDm  [i2c_external_eeprom_TX_SDA_MISO_PIN_INDEX] = i2c_external_eeprom_PIN_DM_OD_LO;
        #endif /* (i2c_external_eeprom_TX_SDA_MISO_PIN) */
        }
    #if (!i2c_external_eeprom_CY_SCBIP_V1)
        else if (i2c_external_eeprom_SCB_MODE_SPI == mode)
        {
        #if (i2c_external_eeprom_RX_SCL_MOSI_PIN)
            hsiomSel[i2c_external_eeprom_RX_SCL_MOSI_PIN_INDEX] = i2c_external_eeprom_RX_SCL_MOSI_HSIOM_SEL_SPI;
        #elif (i2c_external_eeprom_RX_WAKE_SCL_MOSI_PIN)
            hsiomSel[i2c_external_eeprom_RX_WAKE_SCL_MOSI_PIN_INDEX] = i2c_external_eeprom_RX_WAKE_SCL_MOSI_HSIOM_SEL_SPI;
        #else
        #endif /* (i2c_external_eeprom_RX_SCL_MOSI_PIN) */
        
        #if (i2c_external_eeprom_TX_SDA_MISO_PIN)
            hsiomSel[i2c_external_eeprom_TX_SDA_MISO_PIN_INDEX] = i2c_external_eeprom_TX_SDA_MISO_HSIOM_SEL_SPI;
        #endif /* (i2c_external_eeprom_TX_SDA_MISO_PIN) */
        
        #if (i2c_external_eeprom_SCLK_PIN)
            hsiomSel[i2c_external_eeprom_SCLK_PIN_INDEX] = i2c_external_eeprom_SCLK_HSIOM_SEL_SPI;
        #endif /* (i2c_external_eeprom_SCLK_PIN) */

            if (i2c_external_eeprom_SPI_SLAVE == subMode)
            {
                /* Slave */
                pinsDm[i2c_external_eeprom_RX_SCL_MOSI_PIN_INDEX] = i2c_external_eeprom_PIN_DM_DIG_HIZ;
                pinsDm[i2c_external_eeprom_TX_SDA_MISO_PIN_INDEX] = i2c_external_eeprom_PIN_DM_STRONG;
                pinsDm[i2c_external_eeprom_SCLK_PIN_INDEX] = i2c_external_eeprom_PIN_DM_DIG_HIZ;

            #if (i2c_external_eeprom_SS0_PIN)
                /* Only SS0 is valid choice for Slave */
                hsiomSel[i2c_external_eeprom_SS0_PIN_INDEX] = i2c_external_eeprom_SS0_HSIOM_SEL_SPI;
                pinsDm  [i2c_external_eeprom_SS0_PIN_INDEX] = i2c_external_eeprom_PIN_DM_DIG_HIZ;
            #endif /* (i2c_external_eeprom_SS0_PIN) */

            #if (i2c_external_eeprom_TX_SDA_MISO_PIN)
                /* Disable input buffer */
                 pinsInBuf |= i2c_external_eeprom_TX_SDA_MISO_PIN_MASK;
            #endif /* (i2c_external_eeprom_TX_SDA_MISO_PIN) */
            }
            else 
            {
                /* (Master) */
                pinsDm[i2c_external_eeprom_RX_SCL_MOSI_PIN_INDEX] = i2c_external_eeprom_PIN_DM_STRONG;
                pinsDm[i2c_external_eeprom_TX_SDA_MISO_PIN_INDEX] = i2c_external_eeprom_PIN_DM_DIG_HIZ;
                pinsDm[i2c_external_eeprom_SCLK_PIN_INDEX] = i2c_external_eeprom_PIN_DM_STRONG;

            #if (i2c_external_eeprom_SS0_PIN)
                hsiomSel [i2c_external_eeprom_SS0_PIN_INDEX] = i2c_external_eeprom_SS0_HSIOM_SEL_SPI;
                pinsDm   [i2c_external_eeprom_SS0_PIN_INDEX] = i2c_external_eeprom_PIN_DM_STRONG;
                pinsInBuf |= i2c_external_eeprom_SS0_PIN_MASK;
            #endif /* (i2c_external_eeprom_SS0_PIN) */

            #if (i2c_external_eeprom_SS1_PIN)
                hsiomSel [i2c_external_eeprom_SS1_PIN_INDEX] = i2c_external_eeprom_SS1_HSIOM_SEL_SPI;
                pinsDm   [i2c_external_eeprom_SS1_PIN_INDEX] = i2c_external_eeprom_PIN_DM_STRONG;
                pinsInBuf |= i2c_external_eeprom_SS1_PIN_MASK;
            #endif /* (i2c_external_eeprom_SS1_PIN) */

            #if (i2c_external_eeprom_SS2_PIN)
                hsiomSel [i2c_external_eeprom_SS2_PIN_INDEX] = i2c_external_eeprom_SS2_HSIOM_SEL_SPI;
                pinsDm   [i2c_external_eeprom_SS2_PIN_INDEX] = i2c_external_eeprom_PIN_DM_STRONG;
                pinsInBuf |= i2c_external_eeprom_SS2_PIN_MASK;
            #endif /* (i2c_external_eeprom_SS2_PIN) */

            #if (i2c_external_eeprom_SS3_PIN)
                hsiomSel [i2c_external_eeprom_SS3_PIN_INDEX] = i2c_external_eeprom_SS3_HSIOM_SEL_SPI;
                pinsDm   [i2c_external_eeprom_SS3_PIN_INDEX] = i2c_external_eeprom_PIN_DM_STRONG;
                pinsInBuf |= i2c_external_eeprom_SS3_PIN_MASK;
            #endif /* (i2c_external_eeprom_SS3_PIN) */

                /* Disable input buffers */
            #if (i2c_external_eeprom_RX_SCL_MOSI_PIN)
                pinsInBuf |= i2c_external_eeprom_RX_SCL_MOSI_PIN_MASK;
            #elif (i2c_external_eeprom_RX_WAKE_SCL_MOSI_PIN)
                pinsInBuf |= i2c_external_eeprom_RX_WAKE_SCL_MOSI_PIN_MASK;
            #else
            #endif /* (i2c_external_eeprom_RX_SCL_MOSI_PIN) */

            #if (i2c_external_eeprom_SCLK_PIN)
                pinsInBuf |= i2c_external_eeprom_SCLK_PIN_MASK;
            #endif /* (i2c_external_eeprom_SCLK_PIN) */
            }
        }
        else /* UART */
        {
            if (i2c_external_eeprom_UART_MODE_SMARTCARD == subMode)
            {
                /* SmartCard */
            #if (i2c_external_eeprom_TX_SDA_MISO_PIN)
                hsiomSel[i2c_external_eeprom_TX_SDA_MISO_PIN_INDEX] = i2c_external_eeprom_TX_SDA_MISO_HSIOM_SEL_UART;
                pinsDm  [i2c_external_eeprom_TX_SDA_MISO_PIN_INDEX] = i2c_external_eeprom_PIN_DM_OD_LO;
            #endif /* (i2c_external_eeprom_TX_SDA_MISO_PIN) */
            }
            else /* Standard or IrDA */
            {
                if (0u != (i2c_external_eeprom_UART_RX_PIN_ENABLE & uartEnableMask))
                {
                #if (i2c_external_eeprom_RX_SCL_MOSI_PIN)
                    hsiomSel[i2c_external_eeprom_RX_SCL_MOSI_PIN_INDEX] = i2c_external_eeprom_RX_SCL_MOSI_HSIOM_SEL_UART;
                    pinsDm  [i2c_external_eeprom_RX_SCL_MOSI_PIN_INDEX] = i2c_external_eeprom_PIN_DM_DIG_HIZ;
                #elif (i2c_external_eeprom_RX_WAKE_SCL_MOSI_PIN)
                    hsiomSel[i2c_external_eeprom_RX_WAKE_SCL_MOSI_PIN_INDEX] = i2c_external_eeprom_RX_WAKE_SCL_MOSI_HSIOM_SEL_UART;
                    pinsDm  [i2c_external_eeprom_RX_WAKE_SCL_MOSI_PIN_INDEX] = i2c_external_eeprom_PIN_DM_DIG_HIZ;
                #else
                #endif /* (i2c_external_eeprom_RX_SCL_MOSI_PIN) */
                }

                if (0u != (i2c_external_eeprom_UART_TX_PIN_ENABLE & uartEnableMask))
                {
                #if (i2c_external_eeprom_TX_SDA_MISO_PIN)
                    hsiomSel[i2c_external_eeprom_TX_SDA_MISO_PIN_INDEX] = i2c_external_eeprom_TX_SDA_MISO_HSIOM_SEL_UART;
                    pinsDm  [i2c_external_eeprom_TX_SDA_MISO_PIN_INDEX] = i2c_external_eeprom_PIN_DM_STRONG;
                    
                    /* Disable input buffer */
                    pinsInBuf |= i2c_external_eeprom_TX_SDA_MISO_PIN_MASK;
                #endif /* (i2c_external_eeprom_TX_SDA_MISO_PIN) */
                }

            #if !(i2c_external_eeprom_CY_SCBIP_V0 || i2c_external_eeprom_CY_SCBIP_V1)
                if (i2c_external_eeprom_UART_MODE_STD == subMode)
                {
                    if (0u != (i2c_external_eeprom_UART_CTS_PIN_ENABLE & uartEnableMask))
                    {
                        /* CTS input is multiplexed with SCLK */
                    #if (i2c_external_eeprom_SCLK_PIN)
                        hsiomSel[i2c_external_eeprom_SCLK_PIN_INDEX] = i2c_external_eeprom_SCLK_HSIOM_SEL_UART;
                        pinsDm  [i2c_external_eeprom_SCLK_PIN_INDEX] = i2c_external_eeprom_PIN_DM_DIG_HIZ;
                    #endif /* (i2c_external_eeprom_SCLK_PIN) */
                    }

                    if (0u != (i2c_external_eeprom_UART_RTS_PIN_ENABLE & uartEnableMask))
                    {
                        /* RTS output is multiplexed with SS0 */
                    #if (i2c_external_eeprom_SS0_PIN)
                        hsiomSel[i2c_external_eeprom_SS0_PIN_INDEX] = i2c_external_eeprom_SS0_HSIOM_SEL_UART;
                        pinsDm  [i2c_external_eeprom_SS0_PIN_INDEX] = i2c_external_eeprom_PIN_DM_STRONG;
                        
                        /* Disable input buffer */
                        pinsInBuf |= i2c_external_eeprom_SS0_PIN_MASK;
                    #endif /* (i2c_external_eeprom_SS0_PIN) */
                    }
                }
            #endif /* !(i2c_external_eeprom_CY_SCBIP_V0 || i2c_external_eeprom_CY_SCBIP_V1) */
            }
        }
    #endif /* (!i2c_external_eeprom_CY_SCBIP_V1) */

    /* Configure pins: set HSIOM, DM and InputBufEnable */
    /* Note: the DR register settings do not effect the pin output if HSIOM is other than GPIO */

    #if (i2c_external_eeprom_RX_SCL_MOSI_PIN)
        i2c_external_eeprom_SET_HSIOM_SEL(i2c_external_eeprom_RX_SCL_MOSI_HSIOM_REG,
                                       i2c_external_eeprom_RX_SCL_MOSI_HSIOM_MASK,
                                       i2c_external_eeprom_RX_SCL_MOSI_HSIOM_POS,
                                        hsiomSel[i2c_external_eeprom_RX_SCL_MOSI_PIN_INDEX]);

        i2c_external_eeprom_uart_rx_i2c_scl_spi_mosi_SetDriveMode((uint8) pinsDm[i2c_external_eeprom_RX_SCL_MOSI_PIN_INDEX]);

        #if (!i2c_external_eeprom_CY_SCBIP_V1)
            i2c_external_eeprom_SET_INP_DIS(i2c_external_eeprom_uart_rx_i2c_scl_spi_mosi_INP_DIS,
                                         i2c_external_eeprom_uart_rx_i2c_scl_spi_mosi_MASK,
                                         (0u != (pinsInBuf & i2c_external_eeprom_RX_SCL_MOSI_PIN_MASK)));
        #endif /* (!i2c_external_eeprom_CY_SCBIP_V1) */
    
    #elif (i2c_external_eeprom_RX_WAKE_SCL_MOSI_PIN)
        i2c_external_eeprom_SET_HSIOM_SEL(i2c_external_eeprom_RX_WAKE_SCL_MOSI_HSIOM_REG,
                                       i2c_external_eeprom_RX_WAKE_SCL_MOSI_HSIOM_MASK,
                                       i2c_external_eeprom_RX_WAKE_SCL_MOSI_HSIOM_POS,
                                       hsiomSel[i2c_external_eeprom_RX_WAKE_SCL_MOSI_PIN_INDEX]);

        i2c_external_eeprom_uart_rx_wake_i2c_scl_spi_mosi_SetDriveMode((uint8)
                                                               pinsDm[i2c_external_eeprom_RX_WAKE_SCL_MOSI_PIN_INDEX]);

        i2c_external_eeprom_SET_INP_DIS(i2c_external_eeprom_uart_rx_wake_i2c_scl_spi_mosi_INP_DIS,
                                     i2c_external_eeprom_uart_rx_wake_i2c_scl_spi_mosi_MASK,
                                     (0u != (pinsInBuf & i2c_external_eeprom_RX_WAKE_SCL_MOSI_PIN_MASK)));

         /* Set interrupt on falling edge */
        i2c_external_eeprom_SET_INCFG_TYPE(i2c_external_eeprom_RX_WAKE_SCL_MOSI_INTCFG_REG,
                                        i2c_external_eeprom_RX_WAKE_SCL_MOSI_INTCFG_TYPE_MASK,
                                        i2c_external_eeprom_RX_WAKE_SCL_MOSI_INTCFG_TYPE_POS,
                                        i2c_external_eeprom_INTCFG_TYPE_FALLING_EDGE);
    #else
    #endif /* (i2c_external_eeprom_RX_WAKE_SCL_MOSI_PIN) */

    #if (i2c_external_eeprom_TX_SDA_MISO_PIN)
        i2c_external_eeprom_SET_HSIOM_SEL(i2c_external_eeprom_TX_SDA_MISO_HSIOM_REG,
                                       i2c_external_eeprom_TX_SDA_MISO_HSIOM_MASK,
                                       i2c_external_eeprom_TX_SDA_MISO_HSIOM_POS,
                                        hsiomSel[i2c_external_eeprom_TX_SDA_MISO_PIN_INDEX]);

        i2c_external_eeprom_uart_tx_i2c_sda_spi_miso_SetDriveMode((uint8) pinsDm[i2c_external_eeprom_TX_SDA_MISO_PIN_INDEX]);

    #if (!i2c_external_eeprom_CY_SCBIP_V1)
        i2c_external_eeprom_SET_INP_DIS(i2c_external_eeprom_uart_tx_i2c_sda_spi_miso_INP_DIS,
                                     i2c_external_eeprom_uart_tx_i2c_sda_spi_miso_MASK,
                                    (0u != (pinsInBuf & i2c_external_eeprom_TX_SDA_MISO_PIN_MASK)));
    #endif /* (!i2c_external_eeprom_CY_SCBIP_V1) */
    #endif /* (i2c_external_eeprom_RX_SCL_MOSI_PIN) */

    #if (i2c_external_eeprom_SCLK_PIN)
        i2c_external_eeprom_SET_HSIOM_SEL(i2c_external_eeprom_SCLK_HSIOM_REG,
                                       i2c_external_eeprom_SCLK_HSIOM_MASK,
                                       i2c_external_eeprom_SCLK_HSIOM_POS,
                                       hsiomSel[i2c_external_eeprom_SCLK_PIN_INDEX]);

        i2c_external_eeprom_spi_sclk_SetDriveMode((uint8) pinsDm[i2c_external_eeprom_SCLK_PIN_INDEX]);

        i2c_external_eeprom_SET_INP_DIS(i2c_external_eeprom_spi_sclk_INP_DIS,
                                     i2c_external_eeprom_spi_sclk_MASK,
                                     (0u != (pinsInBuf & i2c_external_eeprom_SCLK_PIN_MASK)));
    #endif /* (i2c_external_eeprom_SCLK_PIN) */

    #if (i2c_external_eeprom_SS0_PIN)
        i2c_external_eeprom_SET_HSIOM_SEL(i2c_external_eeprom_SS0_HSIOM_REG,
                                       i2c_external_eeprom_SS0_HSIOM_MASK,
                                       i2c_external_eeprom_SS0_HSIOM_POS,
                                       hsiomSel[i2c_external_eeprom_SS0_PIN_INDEX]);

        i2c_external_eeprom_spi_ss0_SetDriveMode((uint8) pinsDm[i2c_external_eeprom_SS0_PIN_INDEX]);

        i2c_external_eeprom_SET_INP_DIS(i2c_external_eeprom_spi_ss0_INP_DIS,
                                     i2c_external_eeprom_spi_ss0_MASK,
                                     (0u != (pinsInBuf & i2c_external_eeprom_SS0_PIN_MASK)));
    #endif /* (i2c_external_eeprom_SS0_PIN) */

    #if (i2c_external_eeprom_SS1_PIN)
        i2c_external_eeprom_SET_HSIOM_SEL(i2c_external_eeprom_SS1_HSIOM_REG,
                                       i2c_external_eeprom_SS1_HSIOM_MASK,
                                       i2c_external_eeprom_SS1_HSIOM_POS,
                                       hsiomSel[i2c_external_eeprom_SS1_PIN_INDEX]);

        i2c_external_eeprom_spi_ss1_SetDriveMode((uint8) pinsDm[i2c_external_eeprom_SS1_PIN_INDEX]);

        i2c_external_eeprom_SET_INP_DIS(i2c_external_eeprom_spi_ss1_INP_DIS,
                                     i2c_external_eeprom_spi_ss1_MASK,
                                     (0u != (pinsInBuf & i2c_external_eeprom_SS1_PIN_MASK)));
    #endif /* (i2c_external_eeprom_SS1_PIN) */

    #if (i2c_external_eeprom_SS2_PIN)
        i2c_external_eeprom_SET_HSIOM_SEL(i2c_external_eeprom_SS2_HSIOM_REG,
                                       i2c_external_eeprom_SS2_HSIOM_MASK,
                                       i2c_external_eeprom_SS2_HSIOM_POS,
                                       hsiomSel[i2c_external_eeprom_SS2_PIN_INDEX]);

        i2c_external_eeprom_spi_ss2_SetDriveMode((uint8) pinsDm[i2c_external_eeprom_SS2_PIN_INDEX]);

        i2c_external_eeprom_SET_INP_DIS(i2c_external_eeprom_spi_ss2_INP_DIS,
                                     i2c_external_eeprom_spi_ss2_MASK,
                                     (0u != (pinsInBuf & i2c_external_eeprom_SS2_PIN_MASK)));
    #endif /* (i2c_external_eeprom_SS2_PIN) */

    #if (i2c_external_eeprom_SS3_PIN)
        i2c_external_eeprom_SET_HSIOM_SEL(i2c_external_eeprom_SS3_HSIOM_REG,
                                       i2c_external_eeprom_SS3_HSIOM_MASK,
                                       i2c_external_eeprom_SS3_HSIOM_POS,
                                       hsiomSel[i2c_external_eeprom_SS3_PIN_INDEX]);

        i2c_external_eeprom_spi_ss3_SetDriveMode((uint8) pinsDm[i2c_external_eeprom_SS3_PIN_INDEX]);

        i2c_external_eeprom_SET_INP_DIS(i2c_external_eeprom_spi_ss3_INP_DIS,
                                     i2c_external_eeprom_spi_ss3_MASK,
                                     (0u != (pinsInBuf & i2c_external_eeprom_SS3_PIN_MASK)));
    #endif /* (i2c_external_eeprom_SS3_PIN) */
    }

#endif /* (i2c_external_eeprom_SCB_MODE_UNCONFIG_CONST_CFG) */


#if (i2c_external_eeprom_CY_SCBIP_V0 || i2c_external_eeprom_CY_SCBIP_V1)
    /*******************************************************************************
    * Function Name: i2c_external_eeprom_I2CSlaveNackGeneration
    ****************************************************************************//**
    *
    *  Sets command to generate NACK to the address or data.
    *
    *******************************************************************************/
    void i2c_external_eeprom_I2CSlaveNackGeneration(void)
    {
        /* Check for EC_AM toggle condition: EC_AM and clock stretching for address are enabled */
        if ((0u != (i2c_external_eeprom_CTRL_REG & i2c_external_eeprom_CTRL_EC_AM_MODE)) &&
            (0u == (i2c_external_eeprom_I2C_CTRL_REG & i2c_external_eeprom_I2C_CTRL_S_NOT_READY_ADDR_NACK)))
        {
            /* Toggle EC_AM before NACK generation */
            i2c_external_eeprom_CTRL_REG &= ~i2c_external_eeprom_CTRL_EC_AM_MODE;
            i2c_external_eeprom_CTRL_REG |=  i2c_external_eeprom_CTRL_EC_AM_MODE;
        }

        i2c_external_eeprom_I2C_SLAVE_CMD_REG = i2c_external_eeprom_I2C_SLAVE_CMD_S_NACK;
    }
#endif /* (i2c_external_eeprom_CY_SCBIP_V0 || i2c_external_eeprom_CY_SCBIP_V1) */


/* [] END OF FILE */
