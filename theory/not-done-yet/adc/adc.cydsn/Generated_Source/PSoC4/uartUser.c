/***************************************************************************//**
* \file uartUser.c
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

#include "uartUser_PVT.h"

#if (uartUser_SCB_MODE_I2C_INC)
    #include "uartUser_I2C_PVT.h"
#endif /* (uartUser_SCB_MODE_I2C_INC) */

#if (uartUser_SCB_MODE_EZI2C_INC)
    #include "uartUser_EZI2C_PVT.h"
#endif /* (uartUser_SCB_MODE_EZI2C_INC) */

#if (uartUser_SCB_MODE_SPI_INC || uartUser_SCB_MODE_UART_INC)
    #include "uartUser_SPI_UART_PVT.h"
#endif /* (uartUser_SCB_MODE_SPI_INC || uartUser_SCB_MODE_UART_INC) */


/***************************************
*    Run Time Configuration Vars
***************************************/

/* Stores internal component configuration for Unconfigured mode */
#if (uartUser_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Common configuration variables */
    uint8 uartUser_scbMode = uartUser_SCB_MODE_UNCONFIG;
    uint8 uartUser_scbEnableWake;
    uint8 uartUser_scbEnableIntr;

    /* I2C configuration variables */
    uint8 uartUser_mode;
    uint8 uartUser_acceptAddr;

    /* SPI/UART configuration variables */
    volatile uint8 * uartUser_rxBuffer;
    uint8  uartUser_rxDataBits;
    uint32 uartUser_rxBufferSize;

    volatile uint8 * uartUser_txBuffer;
    uint8  uartUser_txDataBits;
    uint32 uartUser_txBufferSize;

    /* EZI2C configuration variables */
    uint8 uartUser_numberOfAddr;
    uint8 uartUser_subAddrSize;
#endif /* (uartUser_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*     Common SCB Vars
***************************************/
/**
* \addtogroup group_general
* \{
*/

/** uartUser_initVar indicates whether the uartUser 
*  component has been initialized. The variable is initialized to 0 
*  and set to 1 the first time SCB_Start() is called. This allows 
*  the component to restart without reinitialization after the first 
*  call to the uartUser_Start() routine.
*
*  If re-initialization of the component is required, then the 
*  uartUser_Init() function can be called before the 
*  uartUser_Start() or uartUser_Enable() function.
*/
uint8 uartUser_initVar = 0u;


#if (! (uartUser_SCB_MODE_I2C_CONST_CFG || \
        uartUser_SCB_MODE_EZI2C_CONST_CFG))
    /** This global variable stores TX interrupt sources after 
    * uartUser_Stop() is called. Only these TX interrupt sources 
    * will be restored on a subsequent uartUser_Enable() call.
    */
    uint16 uartUser_IntrTxMask = 0u;
#endif /* (! (uartUser_SCB_MODE_I2C_CONST_CFG || \
              uartUser_SCB_MODE_EZI2C_CONST_CFG)) */
/** \} globals */

#if (uartUser_SCB_IRQ_INTERNAL)
#if !defined (CY_REMOVE_uartUser_CUSTOM_INTR_HANDLER)
    void (*uartUser_customIntrHandler)(void) = NULL;
#endif /* !defined (CY_REMOVE_uartUser_CUSTOM_INTR_HANDLER) */
#endif /* (uartUser_SCB_IRQ_INTERNAL) */


/***************************************
*    Private Function Prototypes
***************************************/

static void uartUser_ScbEnableIntr(void);
static void uartUser_ScbModeStop(void);
static void uartUser_ScbModePostEnable(void);


/*******************************************************************************
* Function Name: uartUser_Init
****************************************************************************//**
*
*  Initializes the uartUser component to operate in one of the selected
*  configurations: I2C, SPI, UART or EZI2C.
*  When the configuration is set to "Unconfigured SCB", this function does
*  not do any initialization. Use mode-specific initialization APIs instead:
*  uartUser_I2CInit, uartUser_SpiInit, 
*  uartUser_UartInit or uartUser_EzI2CInit.
*
*******************************************************************************/
void uartUser_Init(void)
{
#if (uartUser_SCB_MODE_UNCONFIG_CONST_CFG)
    if (uartUser_SCB_MODE_UNCONFIG_RUNTM_CFG)
    {
        uartUser_initVar = 0u;
    }
    else
    {
        /* Initialization was done before this function call */
    }

#elif (uartUser_SCB_MODE_I2C_CONST_CFG)
    uartUser_I2CInit();

#elif (uartUser_SCB_MODE_SPI_CONST_CFG)
    uartUser_SpiInit();

#elif (uartUser_SCB_MODE_UART_CONST_CFG)
    uartUser_UartInit();

#elif (uartUser_SCB_MODE_EZI2C_CONST_CFG)
    uartUser_EzI2CInit();

#endif /* (uartUser_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: uartUser_Enable
****************************************************************************//**
*
*  Enables uartUser component operation: activates the hardware and 
*  internal interrupt. It also restores TX interrupt sources disabled after the 
*  uartUser_Stop() function was called (note that level-triggered TX 
*  interrupt sources remain disabled to not cause code lock-up).
*  For I2C and EZI2C modes the interrupt is internal and mandatory for 
*  operation. For SPI and UART modes the interrupt can be configured as none, 
*  internal or external.
*  The uartUser configuration should be not changed when the component
*  is enabled. Any configuration changes should be made after disabling the 
*  component.
*  When configuration is set to “Unconfigured uartUser”, the component 
*  must first be initialized to operate in one of the following configurations: 
*  I2C, SPI, UART or EZ I2C, using the mode-specific initialization API. 
*  Otherwise this function does not enable the component.
*
*******************************************************************************/
void uartUser_Enable(void)
{
#if (uartUser_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Enable SCB block, only if it is already configured */
    if (!uartUser_SCB_MODE_UNCONFIG_RUNTM_CFG)
    {
        uartUser_CTRL_REG |= uartUser_CTRL_ENABLED;

        uartUser_ScbEnableIntr();

        /* Call PostEnable function specific to current operation mode */
        uartUser_ScbModePostEnable();
    }
#else
    uartUser_CTRL_REG |= uartUser_CTRL_ENABLED;

    uartUser_ScbEnableIntr();

    /* Call PostEnable function specific to current operation mode */
    uartUser_ScbModePostEnable();
#endif /* (uartUser_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: uartUser_Start
****************************************************************************//**
*
*  Invokes uartUser_Init() and uartUser_Enable().
*  After this function call, the component is enabled and ready for operation.
*  When configuration is set to "Unconfigured SCB", the component must first be
*  initialized to operate in one of the following configurations: I2C, SPI, UART
*  or EZI2C. Otherwise this function does not enable the component.
*
* \globalvars
*  uartUser_initVar - used to check initial configuration, modified
*  on first function call.
*
*******************************************************************************/
void uartUser_Start(void)
{
    if (0u == uartUser_initVar)
    {
        uartUser_Init();
        uartUser_initVar = 1u; /* Component was initialized */
    }

    uartUser_Enable();
}


/*******************************************************************************
* Function Name: uartUser_Stop
****************************************************************************//**
*
*  Disables the uartUser component: disable the hardware and internal 
*  interrupt. It also disables all TX interrupt sources so as not to cause an 
*  unexpected interrupt trigger because after the component is enabled, the 
*  TX FIFO is empty.
*  Refer to the function uartUser_Enable() for the interrupt 
*  configuration details.
*  This function disables the SCB component without checking to see if 
*  communication is in progress. Before calling this function it may be 
*  necessary to check the status of communication to make sure communication 
*  is complete. If this is not done then communication could be stopped mid 
*  byte and corrupted data could result.
*
*******************************************************************************/
void uartUser_Stop(void)
{
#if (uartUser_SCB_IRQ_INTERNAL)
    uartUser_DisableInt();
#endif /* (uartUser_SCB_IRQ_INTERNAL) */

    /* Call Stop function specific to current operation mode */
    uartUser_ScbModeStop();

    /* Disable SCB IP */
    uartUser_CTRL_REG &= (uint32) ~uartUser_CTRL_ENABLED;

    /* Disable all TX interrupt sources so as not to cause an unexpected
    * interrupt trigger after the component will be enabled because the 
    * TX FIFO is empty.
    * For SCB IP v0, it is critical as it does not mask-out interrupt
    * sources when it is disabled. This can cause a code lock-up in the
    * interrupt handler because TX FIFO cannot be loaded after the block
    * is disabled.
    */
    uartUser_SetTxInterruptMode(uartUser_NO_INTR_SOURCES);

#if (uartUser_SCB_IRQ_INTERNAL)
    uartUser_ClearPendingInt();
#endif /* (uartUser_SCB_IRQ_INTERNAL) */
}


/*******************************************************************************
* Function Name: uartUser_SetRxFifoLevel
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
void uartUser_SetRxFifoLevel(uint32 level)
{
    uint32 rxFifoCtrl;

    rxFifoCtrl = uartUser_RX_FIFO_CTRL_REG;

    rxFifoCtrl &= ((uint32) ~uartUser_RX_FIFO_CTRL_TRIGGER_LEVEL_MASK); /* Clear level mask bits */
    rxFifoCtrl |= ((uint32) (uartUser_RX_FIFO_CTRL_TRIGGER_LEVEL_MASK & level));

    uartUser_RX_FIFO_CTRL_REG = rxFifoCtrl;
}


/*******************************************************************************
* Function Name: uartUser_SetTxFifoLevel
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
void uartUser_SetTxFifoLevel(uint32 level)
{
    uint32 txFifoCtrl;

    txFifoCtrl = uartUser_TX_FIFO_CTRL_REG;

    txFifoCtrl &= ((uint32) ~uartUser_TX_FIFO_CTRL_TRIGGER_LEVEL_MASK); /* Clear level mask bits */
    txFifoCtrl |= ((uint32) (uartUser_TX_FIFO_CTRL_TRIGGER_LEVEL_MASK & level));

    uartUser_TX_FIFO_CTRL_REG = txFifoCtrl;
}


#if (uartUser_SCB_IRQ_INTERNAL)
    /*******************************************************************************
    * Function Name: uartUser_SetCustomInterruptHandler
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
    void uartUser_SetCustomInterruptHandler(void (*func)(void))
    {
    #if !defined (CY_REMOVE_uartUser_CUSTOM_INTR_HANDLER)
        uartUser_customIntrHandler = func; /* Register interrupt handler */
    #else
        if (NULL != func)
        {
            /* Suppress compiler warning */
        }
    #endif /* !defined (CY_REMOVE_uartUser_CUSTOM_INTR_HANDLER) */
    }
#endif /* (uartUser_SCB_IRQ_INTERNAL) */


/*******************************************************************************
* Function Name: uartUser_ScbModeEnableIntr
****************************************************************************//**
*
*  Enables an interrupt for a specific mode.
*
*******************************************************************************/
static void uartUser_ScbEnableIntr(void)
{
#if (uartUser_SCB_IRQ_INTERNAL)
    /* Enable interrupt in NVIC */
    #if (uartUser_SCB_MODE_UNCONFIG_CONST_CFG)
        if (0u != uartUser_scbEnableIntr)
        {
            uartUser_EnableInt();
        }

    #else
        uartUser_EnableInt();

    #endif /* (uartUser_SCB_MODE_UNCONFIG_CONST_CFG) */
#endif /* (uartUser_SCB_IRQ_INTERNAL) */
}


/*******************************************************************************
* Function Name: uartUser_ScbModePostEnable
****************************************************************************//**
*
*  Calls the PostEnable function for a specific operation mode.
*
*******************************************************************************/
static void uartUser_ScbModePostEnable(void)
{
#if (uartUser_SCB_MODE_UNCONFIG_CONST_CFG)
#if (!uartUser_CY_SCBIP_V1)
    if (uartUser_SCB_MODE_SPI_RUNTM_CFG)
    {
        uartUser_SpiPostEnable();
    }
    else if (uartUser_SCB_MODE_UART_RUNTM_CFG)
    {
        uartUser_UartPostEnable();
    }
    else
    {
        /* Unknown mode: do nothing */
    }
#endif /* (!uartUser_CY_SCBIP_V1) */

#elif (uartUser_SCB_MODE_SPI_CONST_CFG)
    uartUser_SpiPostEnable();

#elif (uartUser_SCB_MODE_UART_CONST_CFG)
    uartUser_UartPostEnable();

#else
    /* Unknown mode: do nothing */
#endif /* (uartUser_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: uartUser_ScbModeStop
****************************************************************************//**
*
*  Calls the Stop function for a specific operation mode.
*
*******************************************************************************/
static void uartUser_ScbModeStop(void)
{
#if (uartUser_SCB_MODE_UNCONFIG_CONST_CFG)
    if (uartUser_SCB_MODE_I2C_RUNTM_CFG)
    {
        uartUser_I2CStop();
    }
    else if (uartUser_SCB_MODE_EZI2C_RUNTM_CFG)
    {
        uartUser_EzI2CStop();
    }
#if (!uartUser_CY_SCBIP_V1)
    else if (uartUser_SCB_MODE_SPI_RUNTM_CFG)
    {
        uartUser_SpiStop();
    }
    else if (uartUser_SCB_MODE_UART_RUNTM_CFG)
    {
        uartUser_UartStop();
    }
#endif /* (!uartUser_CY_SCBIP_V1) */
    else
    {
        /* Unknown mode: do nothing */
    }
#elif (uartUser_SCB_MODE_I2C_CONST_CFG)
    uartUser_I2CStop();

#elif (uartUser_SCB_MODE_EZI2C_CONST_CFG)
    uartUser_EzI2CStop();

#elif (uartUser_SCB_MODE_SPI_CONST_CFG)
    uartUser_SpiStop();

#elif (uartUser_SCB_MODE_UART_CONST_CFG)
    uartUser_UartStop();

#else
    /* Unknown mode: do nothing */
#endif /* (uartUser_SCB_MODE_UNCONFIG_CONST_CFG) */
}


#if (uartUser_SCB_MODE_UNCONFIG_CONST_CFG)
    /*******************************************************************************
    * Function Name: uartUser_SetPins
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
    void uartUser_SetPins(uint32 mode, uint32 subMode, uint32 uartEnableMask)
    {
        uint32 pinsDm[uartUser_SCB_PINS_NUMBER];
        uint32 i;
        
    #if (!uartUser_CY_SCBIP_V1)
        uint32 pinsInBuf = 0u;
    #endif /* (!uartUser_CY_SCBIP_V1) */
        
        uint32 hsiomSel[uartUser_SCB_PINS_NUMBER] = 
        {
            uartUser_RX_SCL_MOSI_HSIOM_SEL_GPIO,
            uartUser_TX_SDA_MISO_HSIOM_SEL_GPIO,
            0u,
            0u,
            0u,
            0u,
            0u,
        };

    #if (uartUser_CY_SCBIP_V1)
        /* Supress compiler warning. */
        if ((0u == subMode) || (0u == uartEnableMask))
        {
        }
    #endif /* (uartUser_CY_SCBIP_V1) */

        /* Set default HSIOM to GPIO and Drive Mode to Analog Hi-Z */
        for (i = 0u; i < uartUser_SCB_PINS_NUMBER; i++)
        {
            pinsDm[i] = uartUser_PIN_DM_ALG_HIZ;
        }

        if ((uartUser_SCB_MODE_I2C   == mode) ||
            (uartUser_SCB_MODE_EZI2C == mode))
        {
        #if (uartUser_RX_SCL_MOSI_PIN)
            hsiomSel[uartUser_RX_SCL_MOSI_PIN_INDEX] = uartUser_RX_SCL_MOSI_HSIOM_SEL_I2C;
            pinsDm  [uartUser_RX_SCL_MOSI_PIN_INDEX] = uartUser_PIN_DM_OD_LO;
        #elif (uartUser_RX_WAKE_SCL_MOSI_PIN)
            hsiomSel[uartUser_RX_WAKE_SCL_MOSI_PIN_INDEX] = uartUser_RX_WAKE_SCL_MOSI_HSIOM_SEL_I2C;
            pinsDm  [uartUser_RX_WAKE_SCL_MOSI_PIN_INDEX] = uartUser_PIN_DM_OD_LO;
        #else
        #endif /* (uartUser_RX_SCL_MOSI_PIN) */
        
        #if (uartUser_TX_SDA_MISO_PIN)
            hsiomSel[uartUser_TX_SDA_MISO_PIN_INDEX] = uartUser_TX_SDA_MISO_HSIOM_SEL_I2C;
            pinsDm  [uartUser_TX_SDA_MISO_PIN_INDEX] = uartUser_PIN_DM_OD_LO;
        #endif /* (uartUser_TX_SDA_MISO_PIN) */
        }
    #if (!uartUser_CY_SCBIP_V1)
        else if (uartUser_SCB_MODE_SPI == mode)
        {
        #if (uartUser_RX_SCL_MOSI_PIN)
            hsiomSel[uartUser_RX_SCL_MOSI_PIN_INDEX] = uartUser_RX_SCL_MOSI_HSIOM_SEL_SPI;
        #elif (uartUser_RX_WAKE_SCL_MOSI_PIN)
            hsiomSel[uartUser_RX_WAKE_SCL_MOSI_PIN_INDEX] = uartUser_RX_WAKE_SCL_MOSI_HSIOM_SEL_SPI;
        #else
        #endif /* (uartUser_RX_SCL_MOSI_PIN) */
        
        #if (uartUser_TX_SDA_MISO_PIN)
            hsiomSel[uartUser_TX_SDA_MISO_PIN_INDEX] = uartUser_TX_SDA_MISO_HSIOM_SEL_SPI;
        #endif /* (uartUser_TX_SDA_MISO_PIN) */
        
        #if (uartUser_SCLK_PIN)
            hsiomSel[uartUser_SCLK_PIN_INDEX] = uartUser_SCLK_HSIOM_SEL_SPI;
        #endif /* (uartUser_SCLK_PIN) */

            if (uartUser_SPI_SLAVE == subMode)
            {
                /* Slave */
                pinsDm[uartUser_RX_SCL_MOSI_PIN_INDEX] = uartUser_PIN_DM_DIG_HIZ;
                pinsDm[uartUser_TX_SDA_MISO_PIN_INDEX] = uartUser_PIN_DM_STRONG;
                pinsDm[uartUser_SCLK_PIN_INDEX] = uartUser_PIN_DM_DIG_HIZ;

            #if (uartUser_SS0_PIN)
                /* Only SS0 is valid choice for Slave */
                hsiomSel[uartUser_SS0_PIN_INDEX] = uartUser_SS0_HSIOM_SEL_SPI;
                pinsDm  [uartUser_SS0_PIN_INDEX] = uartUser_PIN_DM_DIG_HIZ;
            #endif /* (uartUser_SS0_PIN) */

            #if (uartUser_TX_SDA_MISO_PIN)
                /* Disable input buffer */
                 pinsInBuf |= uartUser_TX_SDA_MISO_PIN_MASK;
            #endif /* (uartUser_TX_SDA_MISO_PIN) */
            }
            else 
            {
                /* (Master) */
                pinsDm[uartUser_RX_SCL_MOSI_PIN_INDEX] = uartUser_PIN_DM_STRONG;
                pinsDm[uartUser_TX_SDA_MISO_PIN_INDEX] = uartUser_PIN_DM_DIG_HIZ;
                pinsDm[uartUser_SCLK_PIN_INDEX] = uartUser_PIN_DM_STRONG;

            #if (uartUser_SS0_PIN)
                hsiomSel [uartUser_SS0_PIN_INDEX] = uartUser_SS0_HSIOM_SEL_SPI;
                pinsDm   [uartUser_SS0_PIN_INDEX] = uartUser_PIN_DM_STRONG;
                pinsInBuf |= uartUser_SS0_PIN_MASK;
            #endif /* (uartUser_SS0_PIN) */

            #if (uartUser_SS1_PIN)
                hsiomSel [uartUser_SS1_PIN_INDEX] = uartUser_SS1_HSIOM_SEL_SPI;
                pinsDm   [uartUser_SS1_PIN_INDEX] = uartUser_PIN_DM_STRONG;
                pinsInBuf |= uartUser_SS1_PIN_MASK;
            #endif /* (uartUser_SS1_PIN) */

            #if (uartUser_SS2_PIN)
                hsiomSel [uartUser_SS2_PIN_INDEX] = uartUser_SS2_HSIOM_SEL_SPI;
                pinsDm   [uartUser_SS2_PIN_INDEX] = uartUser_PIN_DM_STRONG;
                pinsInBuf |= uartUser_SS2_PIN_MASK;
            #endif /* (uartUser_SS2_PIN) */

            #if (uartUser_SS3_PIN)
                hsiomSel [uartUser_SS3_PIN_INDEX] = uartUser_SS3_HSIOM_SEL_SPI;
                pinsDm   [uartUser_SS3_PIN_INDEX] = uartUser_PIN_DM_STRONG;
                pinsInBuf |= uartUser_SS3_PIN_MASK;
            #endif /* (uartUser_SS3_PIN) */

                /* Disable input buffers */
            #if (uartUser_RX_SCL_MOSI_PIN)
                pinsInBuf |= uartUser_RX_SCL_MOSI_PIN_MASK;
            #elif (uartUser_RX_WAKE_SCL_MOSI_PIN)
                pinsInBuf |= uartUser_RX_WAKE_SCL_MOSI_PIN_MASK;
            #else
            #endif /* (uartUser_RX_SCL_MOSI_PIN) */

            #if (uartUser_SCLK_PIN)
                pinsInBuf |= uartUser_SCLK_PIN_MASK;
            #endif /* (uartUser_SCLK_PIN) */
            }
        }
        else /* UART */
        {
            if (uartUser_UART_MODE_SMARTCARD == subMode)
            {
                /* SmartCard */
            #if (uartUser_TX_SDA_MISO_PIN)
                hsiomSel[uartUser_TX_SDA_MISO_PIN_INDEX] = uartUser_TX_SDA_MISO_HSIOM_SEL_UART;
                pinsDm  [uartUser_TX_SDA_MISO_PIN_INDEX] = uartUser_PIN_DM_OD_LO;
            #endif /* (uartUser_TX_SDA_MISO_PIN) */
            }
            else /* Standard or IrDA */
            {
                if (0u != (uartUser_UART_RX_PIN_ENABLE & uartEnableMask))
                {
                #if (uartUser_RX_SCL_MOSI_PIN)
                    hsiomSel[uartUser_RX_SCL_MOSI_PIN_INDEX] = uartUser_RX_SCL_MOSI_HSIOM_SEL_UART;
                    pinsDm  [uartUser_RX_SCL_MOSI_PIN_INDEX] = uartUser_PIN_DM_DIG_HIZ;
                #elif (uartUser_RX_WAKE_SCL_MOSI_PIN)
                    hsiomSel[uartUser_RX_WAKE_SCL_MOSI_PIN_INDEX] = uartUser_RX_WAKE_SCL_MOSI_HSIOM_SEL_UART;
                    pinsDm  [uartUser_RX_WAKE_SCL_MOSI_PIN_INDEX] = uartUser_PIN_DM_DIG_HIZ;
                #else
                #endif /* (uartUser_RX_SCL_MOSI_PIN) */
                }

                if (0u != (uartUser_UART_TX_PIN_ENABLE & uartEnableMask))
                {
                #if (uartUser_TX_SDA_MISO_PIN)
                    hsiomSel[uartUser_TX_SDA_MISO_PIN_INDEX] = uartUser_TX_SDA_MISO_HSIOM_SEL_UART;
                    pinsDm  [uartUser_TX_SDA_MISO_PIN_INDEX] = uartUser_PIN_DM_STRONG;
                    
                    /* Disable input buffer */
                    pinsInBuf |= uartUser_TX_SDA_MISO_PIN_MASK;
                #endif /* (uartUser_TX_SDA_MISO_PIN) */
                }

            #if !(uartUser_CY_SCBIP_V0 || uartUser_CY_SCBIP_V1)
                if (uartUser_UART_MODE_STD == subMode)
                {
                    if (0u != (uartUser_UART_CTS_PIN_ENABLE & uartEnableMask))
                    {
                        /* CTS input is multiplexed with SCLK */
                    #if (uartUser_SCLK_PIN)
                        hsiomSel[uartUser_SCLK_PIN_INDEX] = uartUser_SCLK_HSIOM_SEL_UART;
                        pinsDm  [uartUser_SCLK_PIN_INDEX] = uartUser_PIN_DM_DIG_HIZ;
                    #endif /* (uartUser_SCLK_PIN) */
                    }

                    if (0u != (uartUser_UART_RTS_PIN_ENABLE & uartEnableMask))
                    {
                        /* RTS output is multiplexed with SS0 */
                    #if (uartUser_SS0_PIN)
                        hsiomSel[uartUser_SS0_PIN_INDEX] = uartUser_SS0_HSIOM_SEL_UART;
                        pinsDm  [uartUser_SS0_PIN_INDEX] = uartUser_PIN_DM_STRONG;
                        
                        /* Disable input buffer */
                        pinsInBuf |= uartUser_SS0_PIN_MASK;
                    #endif /* (uartUser_SS0_PIN) */
                    }
                }
            #endif /* !(uartUser_CY_SCBIP_V0 || uartUser_CY_SCBIP_V1) */
            }
        }
    #endif /* (!uartUser_CY_SCBIP_V1) */

    /* Configure pins: set HSIOM, DM and InputBufEnable */
    /* Note: the DR register settings do not effect the pin output if HSIOM is other than GPIO */

    #if (uartUser_RX_SCL_MOSI_PIN)
        uartUser_SET_HSIOM_SEL(uartUser_RX_SCL_MOSI_HSIOM_REG,
                                       uartUser_RX_SCL_MOSI_HSIOM_MASK,
                                       uartUser_RX_SCL_MOSI_HSIOM_POS,
                                        hsiomSel[uartUser_RX_SCL_MOSI_PIN_INDEX]);

        uartUser_uart_rx_i2c_scl_spi_mosi_SetDriveMode((uint8) pinsDm[uartUser_RX_SCL_MOSI_PIN_INDEX]);

        #if (!uartUser_CY_SCBIP_V1)
            uartUser_SET_INP_DIS(uartUser_uart_rx_i2c_scl_spi_mosi_INP_DIS,
                                         uartUser_uart_rx_i2c_scl_spi_mosi_MASK,
                                         (0u != (pinsInBuf & uartUser_RX_SCL_MOSI_PIN_MASK)));
        #endif /* (!uartUser_CY_SCBIP_V1) */
    
    #elif (uartUser_RX_WAKE_SCL_MOSI_PIN)
        uartUser_SET_HSIOM_SEL(uartUser_RX_WAKE_SCL_MOSI_HSIOM_REG,
                                       uartUser_RX_WAKE_SCL_MOSI_HSIOM_MASK,
                                       uartUser_RX_WAKE_SCL_MOSI_HSIOM_POS,
                                       hsiomSel[uartUser_RX_WAKE_SCL_MOSI_PIN_INDEX]);

        uartUser_uart_rx_wake_i2c_scl_spi_mosi_SetDriveMode((uint8)
                                                               pinsDm[uartUser_RX_WAKE_SCL_MOSI_PIN_INDEX]);

        uartUser_SET_INP_DIS(uartUser_uart_rx_wake_i2c_scl_spi_mosi_INP_DIS,
                                     uartUser_uart_rx_wake_i2c_scl_spi_mosi_MASK,
                                     (0u != (pinsInBuf & uartUser_RX_WAKE_SCL_MOSI_PIN_MASK)));

         /* Set interrupt on falling edge */
        uartUser_SET_INCFG_TYPE(uartUser_RX_WAKE_SCL_MOSI_INTCFG_REG,
                                        uartUser_RX_WAKE_SCL_MOSI_INTCFG_TYPE_MASK,
                                        uartUser_RX_WAKE_SCL_MOSI_INTCFG_TYPE_POS,
                                        uartUser_INTCFG_TYPE_FALLING_EDGE);
    #else
    #endif /* (uartUser_RX_WAKE_SCL_MOSI_PIN) */

    #if (uartUser_TX_SDA_MISO_PIN)
        uartUser_SET_HSIOM_SEL(uartUser_TX_SDA_MISO_HSIOM_REG,
                                       uartUser_TX_SDA_MISO_HSIOM_MASK,
                                       uartUser_TX_SDA_MISO_HSIOM_POS,
                                        hsiomSel[uartUser_TX_SDA_MISO_PIN_INDEX]);

        uartUser_uart_tx_i2c_sda_spi_miso_SetDriveMode((uint8) pinsDm[uartUser_TX_SDA_MISO_PIN_INDEX]);

    #if (!uartUser_CY_SCBIP_V1)
        uartUser_SET_INP_DIS(uartUser_uart_tx_i2c_sda_spi_miso_INP_DIS,
                                     uartUser_uart_tx_i2c_sda_spi_miso_MASK,
                                    (0u != (pinsInBuf & uartUser_TX_SDA_MISO_PIN_MASK)));
    #endif /* (!uartUser_CY_SCBIP_V1) */
    #endif /* (uartUser_RX_SCL_MOSI_PIN) */

    #if (uartUser_SCLK_PIN)
        uartUser_SET_HSIOM_SEL(uartUser_SCLK_HSIOM_REG,
                                       uartUser_SCLK_HSIOM_MASK,
                                       uartUser_SCLK_HSIOM_POS,
                                       hsiomSel[uartUser_SCLK_PIN_INDEX]);

        uartUser_spi_sclk_SetDriveMode((uint8) pinsDm[uartUser_SCLK_PIN_INDEX]);

        uartUser_SET_INP_DIS(uartUser_spi_sclk_INP_DIS,
                                     uartUser_spi_sclk_MASK,
                                     (0u != (pinsInBuf & uartUser_SCLK_PIN_MASK)));
    #endif /* (uartUser_SCLK_PIN) */

    #if (uartUser_SS0_PIN)
        uartUser_SET_HSIOM_SEL(uartUser_SS0_HSIOM_REG,
                                       uartUser_SS0_HSIOM_MASK,
                                       uartUser_SS0_HSIOM_POS,
                                       hsiomSel[uartUser_SS0_PIN_INDEX]);

        uartUser_spi_ss0_SetDriveMode((uint8) pinsDm[uartUser_SS0_PIN_INDEX]);

        uartUser_SET_INP_DIS(uartUser_spi_ss0_INP_DIS,
                                     uartUser_spi_ss0_MASK,
                                     (0u != (pinsInBuf & uartUser_SS0_PIN_MASK)));
    #endif /* (uartUser_SS0_PIN) */

    #if (uartUser_SS1_PIN)
        uartUser_SET_HSIOM_SEL(uartUser_SS1_HSIOM_REG,
                                       uartUser_SS1_HSIOM_MASK,
                                       uartUser_SS1_HSIOM_POS,
                                       hsiomSel[uartUser_SS1_PIN_INDEX]);

        uartUser_spi_ss1_SetDriveMode((uint8) pinsDm[uartUser_SS1_PIN_INDEX]);

        uartUser_SET_INP_DIS(uartUser_spi_ss1_INP_DIS,
                                     uartUser_spi_ss1_MASK,
                                     (0u != (pinsInBuf & uartUser_SS1_PIN_MASK)));
    #endif /* (uartUser_SS1_PIN) */

    #if (uartUser_SS2_PIN)
        uartUser_SET_HSIOM_SEL(uartUser_SS2_HSIOM_REG,
                                       uartUser_SS2_HSIOM_MASK,
                                       uartUser_SS2_HSIOM_POS,
                                       hsiomSel[uartUser_SS2_PIN_INDEX]);

        uartUser_spi_ss2_SetDriveMode((uint8) pinsDm[uartUser_SS2_PIN_INDEX]);

        uartUser_SET_INP_DIS(uartUser_spi_ss2_INP_DIS,
                                     uartUser_spi_ss2_MASK,
                                     (0u != (pinsInBuf & uartUser_SS2_PIN_MASK)));
    #endif /* (uartUser_SS2_PIN) */

    #if (uartUser_SS3_PIN)
        uartUser_SET_HSIOM_SEL(uartUser_SS3_HSIOM_REG,
                                       uartUser_SS3_HSIOM_MASK,
                                       uartUser_SS3_HSIOM_POS,
                                       hsiomSel[uartUser_SS3_PIN_INDEX]);

        uartUser_spi_ss3_SetDriveMode((uint8) pinsDm[uartUser_SS3_PIN_INDEX]);

        uartUser_SET_INP_DIS(uartUser_spi_ss3_INP_DIS,
                                     uartUser_spi_ss3_MASK,
                                     (0u != (pinsInBuf & uartUser_SS3_PIN_MASK)));
    #endif /* (uartUser_SS3_PIN) */
    }

#endif /* (uartUser_SCB_MODE_UNCONFIG_CONST_CFG) */


#if (uartUser_CY_SCBIP_V0 || uartUser_CY_SCBIP_V1)
    /*******************************************************************************
    * Function Name: uartUser_I2CSlaveNackGeneration
    ****************************************************************************//**
    *
    *  Sets command to generate NACK to the address or data.
    *
    *******************************************************************************/
    void uartUser_I2CSlaveNackGeneration(void)
    {
        /* Check for EC_AM toggle condition: EC_AM and clock stretching for address are enabled */
        if ((0u != (uartUser_CTRL_REG & uartUser_CTRL_EC_AM_MODE)) &&
            (0u == (uartUser_I2C_CTRL_REG & uartUser_I2C_CTRL_S_NOT_READY_ADDR_NACK)))
        {
            /* Toggle EC_AM before NACK generation */
            uartUser_CTRL_REG &= ~uartUser_CTRL_EC_AM_MODE;
            uartUser_CTRL_REG |=  uartUser_CTRL_EC_AM_MODE;
        }

        uartUser_I2C_SLAVE_CMD_REG = uartUser_I2C_SLAVE_CMD_S_NACK;
    }
#endif /* (uartUser_CY_SCBIP_V0 || uartUser_CY_SCBIP_V1) */


/* [] END OF FILE */
