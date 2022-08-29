/***************************************************************************//**
* \file uartUser_UART.c
* \version 4.0
*
* \brief
*  This file provides the source code to the API for the SCB Component in
*  UART mode.
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
#include "uartUser_SPI_UART_PVT.h"
#include "cyapicallbacks.h"

#if (uartUser_UART_WAKE_ENABLE_CONST && uartUser_UART_RX_WAKEUP_IRQ)
    /**
    * \addtogroup group_globals
    * \{
    */
    /** This global variable determines whether to enable Skip Start
    * functionality when uartUser_Sleep() function is called:
    * 0 – disable, other values – enable. Default value is 1.
    * It is only available when Enable wakeup from Deep Sleep Mode is enabled.
    */
    uint8 uartUser_skipStart = 1u;
    /** \} globals */
#endif /* (uartUser_UART_WAKE_ENABLE_CONST && uartUser_UART_RX_WAKEUP_IRQ) */

#if(uartUser_SCB_MODE_UNCONFIG_CONST_CFG)

    /***************************************
    *  Configuration Structure Initialization
    ***************************************/

    const uartUser_UART_INIT_STRUCT uartUser_configUart =
    {
        uartUser_UART_SUB_MODE,
        uartUser_UART_DIRECTION,
        uartUser_UART_DATA_BITS_NUM,
        uartUser_UART_PARITY_TYPE,
        uartUser_UART_STOP_BITS_NUM,
        uartUser_UART_OVS_FACTOR,
        uartUser_UART_IRDA_LOW_POWER,
        uartUser_UART_MEDIAN_FILTER_ENABLE,
        uartUser_UART_RETRY_ON_NACK,
        uartUser_UART_IRDA_POLARITY,
        uartUser_UART_DROP_ON_PARITY_ERR,
        uartUser_UART_DROP_ON_FRAME_ERR,
        uartUser_UART_WAKE_ENABLE,
        0u,
        NULL,
        0u,
        NULL,
        uartUser_UART_MP_MODE_ENABLE,
        uartUser_UART_MP_ACCEPT_ADDRESS,
        uartUser_UART_MP_RX_ADDRESS,
        uartUser_UART_MP_RX_ADDRESS_MASK,
        (uint32) uartUser_SCB_IRQ_INTERNAL,
        uartUser_UART_INTR_RX_MASK,
        uartUser_UART_RX_TRIGGER_LEVEL,
        uartUser_UART_INTR_TX_MASK,
        uartUser_UART_TX_TRIGGER_LEVEL,
        (uint8) uartUser_UART_BYTE_MODE_ENABLE,
        (uint8) uartUser_UART_CTS_ENABLE,
        (uint8) uartUser_UART_CTS_POLARITY,
        (uint8) uartUser_UART_RTS_POLARITY,
        (uint8) uartUser_UART_RTS_FIFO_LEVEL,
        (uint8) uartUser_UART_RX_BREAK_WIDTH
    };


    /*******************************************************************************
    * Function Name: uartUser_UartInit
    ****************************************************************************//**
    *
    *  Configures the uartUser for UART operation.
    *
    *  This function is intended specifically to be used when the uartUser
    *  configuration is set to “Unconfigured uartUser” in the customizer.
    *  After initializing the uartUser in UART mode using this function,
    *  the component can be enabled using the uartUser_Start() or
    * uartUser_Enable() function.
    *  This function uses a pointer to a structure that provides the configuration
    *  settings. This structure contains the same information that would otherwise
    *  be provided by the customizer settings.
    *
    *  \param config: pointer to a structure that contains the following list of
    *   fields. These fields match the selections available in the customizer.
    *   Refer to the customizer for further description of the settings.
    *
    *******************************************************************************/
    void uartUser_UartInit(const uartUser_UART_INIT_STRUCT *config)
    {
        uint32 pinsConfig;

        if (NULL == config)
        {
            CYASSERT(0u != 0u); /* Halt execution due to bad function parameter */
        }
        else
        {
            /* Get direction to configure UART pins: TX, RX or TX+RX */
            pinsConfig  = config->direction;

        #if !(uartUser_CY_SCBIP_V0 || uartUser_CY_SCBIP_V1)
            /* Add RTS and CTS pins to configure */
            pinsConfig |= (0u != config->rtsRxFifoLevel) ? (uartUser_UART_RTS_PIN_ENABLE) : (0u);
            pinsConfig |= (0u != config->enableCts)      ? (uartUser_UART_CTS_PIN_ENABLE) : (0u);
        #endif /* !(uartUser_CY_SCBIP_V0 || uartUser_CY_SCBIP_V1) */

            /* Configure pins */
            uartUser_SetPins(uartUser_SCB_MODE_UART, config->mode, pinsConfig);

            /* Store internal configuration */
            uartUser_scbMode       = (uint8) uartUser_SCB_MODE_UART;
            uartUser_scbEnableWake = (uint8) config->enableWake;
            uartUser_scbEnableIntr = (uint8) config->enableInterrupt;

            /* Set RX direction internal variables */
            uartUser_rxBuffer      =         config->rxBuffer;
            uartUser_rxDataBits    = (uint8) config->dataBits;
            uartUser_rxBufferSize  =         config->rxBufferSize;

            /* Set TX direction internal variables */
            uartUser_txBuffer      =         config->txBuffer;
            uartUser_txDataBits    = (uint8) config->dataBits;
            uartUser_txBufferSize  =         config->txBufferSize;

            /* Configure UART interface */
            if(uartUser_UART_MODE_IRDA == config->mode)
            {
                /* OVS settings: IrDA */
                uartUser_CTRL_REG  = ((0u != config->enableIrdaLowPower) ?
                                                (uartUser_UART_GET_CTRL_OVS_IRDA_LP(config->oversample)) :
                                                (uartUser_CTRL_OVS_IRDA_OVS16));
            }
            else
            {
                /* OVS settings: UART and SmartCard */
                uartUser_CTRL_REG  = uartUser_GET_CTRL_OVS(config->oversample);
            }

            uartUser_CTRL_REG     |= uartUser_GET_CTRL_BYTE_MODE  (config->enableByteMode)      |
                                             uartUser_GET_CTRL_ADDR_ACCEPT(config->multiprocAcceptAddr) |
                                             uartUser_CTRL_UART;

            /* Configure sub-mode: UART, SmartCard or IrDA */
            uartUser_UART_CTRL_REG = uartUser_GET_UART_CTRL_MODE(config->mode);

            /* Configure RX direction */
            uartUser_UART_RX_CTRL_REG = uartUser_GET_UART_RX_CTRL_MODE(config->stopBits)              |
                                        uartUser_GET_UART_RX_CTRL_POLARITY(config->enableInvertedRx)          |
                                        uartUser_GET_UART_RX_CTRL_MP_MODE(config->enableMultiproc)            |
                                        uartUser_GET_UART_RX_CTRL_DROP_ON_PARITY_ERR(config->dropOnParityErr) |
                                        uartUser_GET_UART_RX_CTRL_DROP_ON_FRAME_ERR(config->dropOnFrameErr)   |
                                        uartUser_GET_UART_RX_CTRL_BREAK_WIDTH(config->breakWidth);

            if(uartUser_UART_PARITY_NONE != config->parity)
            {
               uartUser_UART_RX_CTRL_REG |= uartUser_GET_UART_RX_CTRL_PARITY(config->parity) |
                                                    uartUser_UART_RX_CTRL_PARITY_ENABLED;
            }

            uartUser_RX_CTRL_REG      = uartUser_GET_RX_CTRL_DATA_WIDTH(config->dataBits)       |
                                                uartUser_GET_RX_CTRL_MEDIAN(config->enableMedianFilter) |
                                                uartUser_GET_UART_RX_CTRL_ENABLED(config->direction);

            uartUser_RX_FIFO_CTRL_REG = uartUser_GET_RX_FIFO_CTRL_TRIGGER_LEVEL(config->rxTriggerLevel);

            /* Configure MP address */
            uartUser_RX_MATCH_REG     = uartUser_GET_RX_MATCH_ADDR(config->multiprocAddr) |
                                                uartUser_GET_RX_MATCH_MASK(config->multiprocAddrMask);

            /* Configure RX direction */
            uartUser_UART_TX_CTRL_REG = uartUser_GET_UART_TX_CTRL_MODE(config->stopBits) |
                                                uartUser_GET_UART_TX_CTRL_RETRY_NACK(config->enableRetryNack);

            if(uartUser_UART_PARITY_NONE != config->parity)
            {
               uartUser_UART_TX_CTRL_REG |= uartUser_GET_UART_TX_CTRL_PARITY(config->parity) |
                                                    uartUser_UART_TX_CTRL_PARITY_ENABLED;
            }

            uartUser_TX_CTRL_REG      = uartUser_GET_TX_CTRL_DATA_WIDTH(config->dataBits)    |
                                                uartUser_GET_UART_TX_CTRL_ENABLED(config->direction);

            uartUser_TX_FIFO_CTRL_REG = uartUser_GET_TX_FIFO_CTRL_TRIGGER_LEVEL(config->txTriggerLevel);

        #if !(uartUser_CY_SCBIP_V0 || uartUser_CY_SCBIP_V1)
            uartUser_UART_FLOW_CTRL_REG = uartUser_GET_UART_FLOW_CTRL_CTS_ENABLE(config->enableCts) | \
                                            uartUser_GET_UART_FLOW_CTRL_CTS_POLARITY (config->ctsPolarity)  | \
                                            uartUser_GET_UART_FLOW_CTRL_RTS_POLARITY (config->rtsPolarity)  | \
                                            uartUser_GET_UART_FLOW_CTRL_TRIGGER_LEVEL(config->rtsRxFifoLevel);
        #endif /* !(uartUser_CY_SCBIP_V0 || uartUser_CY_SCBIP_V1) */

            /* Configure interrupt with UART handler but do not enable it */
            CyIntDisable    (uartUser_ISR_NUMBER);
            CyIntSetPriority(uartUser_ISR_NUMBER, uartUser_ISR_PRIORITY);
            (void) CyIntSetVector(uartUser_ISR_NUMBER, &uartUser_SPI_UART_ISR);

            /* Configure WAKE interrupt */
        #if(uartUser_UART_RX_WAKEUP_IRQ)
            CyIntDisable    (uartUser_RX_WAKE_ISR_NUMBER);
            CyIntSetPriority(uartUser_RX_WAKE_ISR_NUMBER, uartUser_RX_WAKE_ISR_PRIORITY);
            (void) CyIntSetVector(uartUser_RX_WAKE_ISR_NUMBER, &uartUser_UART_WAKEUP_ISR);
        #endif /* (uartUser_UART_RX_WAKEUP_IRQ) */

            /* Configure interrupt sources */
            uartUser_INTR_I2C_EC_MASK_REG = uartUser_NO_INTR_SOURCES;
            uartUser_INTR_SPI_EC_MASK_REG = uartUser_NO_INTR_SOURCES;
            uartUser_INTR_SLAVE_MASK_REG  = uartUser_NO_INTR_SOURCES;
            uartUser_INTR_MASTER_MASK_REG = uartUser_NO_INTR_SOURCES;
            uartUser_INTR_RX_MASK_REG     = config->rxInterruptMask;
            uartUser_INTR_TX_MASK_REG     = config->txInterruptMask;

            /* Configure TX interrupt sources to restore. */
            uartUser_IntrTxMask = LO16(uartUser_INTR_TX_MASK_REG);

            /* Clear RX buffer indexes */
            uartUser_rxBufferHead     = 0u;
            uartUser_rxBufferTail     = 0u;
            uartUser_rxBufferOverflow = 0u;

            /* Clear TX buffer indexes */
            uartUser_txBufferHead = 0u;
            uartUser_txBufferTail = 0u;
        }
    }

#else

    /*******************************************************************************
    * Function Name: uartUser_UartInit
    ****************************************************************************//**
    *
    *  Configures the SCB for the UART operation.
    *
    *******************************************************************************/
    void uartUser_UartInit(void)
    {
        /* Configure UART interface */
        uartUser_CTRL_REG = uartUser_UART_DEFAULT_CTRL;

        /* Configure sub-mode: UART, SmartCard or IrDA */
        uartUser_UART_CTRL_REG = uartUser_UART_DEFAULT_UART_CTRL;

        /* Configure RX direction */
        uartUser_UART_RX_CTRL_REG = uartUser_UART_DEFAULT_UART_RX_CTRL;
        uartUser_RX_CTRL_REG      = uartUser_UART_DEFAULT_RX_CTRL;
        uartUser_RX_FIFO_CTRL_REG = uartUser_UART_DEFAULT_RX_FIFO_CTRL;
        uartUser_RX_MATCH_REG     = uartUser_UART_DEFAULT_RX_MATCH_REG;

        /* Configure TX direction */
        uartUser_UART_TX_CTRL_REG = uartUser_UART_DEFAULT_UART_TX_CTRL;
        uartUser_TX_CTRL_REG      = uartUser_UART_DEFAULT_TX_CTRL;
        uartUser_TX_FIFO_CTRL_REG = uartUser_UART_DEFAULT_TX_FIFO_CTRL;

    #if !(uartUser_CY_SCBIP_V0 || uartUser_CY_SCBIP_V1)
        uartUser_UART_FLOW_CTRL_REG = uartUser_UART_DEFAULT_FLOW_CTRL;
    #endif /* !(uartUser_CY_SCBIP_V0 || uartUser_CY_SCBIP_V1) */

        /* Configure interrupt with UART handler but do not enable it */
    #if(uartUser_SCB_IRQ_INTERNAL)
        CyIntDisable    (uartUser_ISR_NUMBER);
        CyIntSetPriority(uartUser_ISR_NUMBER, uartUser_ISR_PRIORITY);
        (void) CyIntSetVector(uartUser_ISR_NUMBER, &uartUser_SPI_UART_ISR);
    #endif /* (uartUser_SCB_IRQ_INTERNAL) */

        /* Configure WAKE interrupt */
    #if(uartUser_UART_RX_WAKEUP_IRQ)
        CyIntDisable    (uartUser_RX_WAKE_ISR_NUMBER);
        CyIntSetPriority(uartUser_RX_WAKE_ISR_NUMBER, uartUser_RX_WAKE_ISR_PRIORITY);
        (void) CyIntSetVector(uartUser_RX_WAKE_ISR_NUMBER, &uartUser_UART_WAKEUP_ISR);
    #endif /* (uartUser_UART_RX_WAKEUP_IRQ) */

        /* Configure interrupt sources */
        uartUser_INTR_I2C_EC_MASK_REG = uartUser_UART_DEFAULT_INTR_I2C_EC_MASK;
        uartUser_INTR_SPI_EC_MASK_REG = uartUser_UART_DEFAULT_INTR_SPI_EC_MASK;
        uartUser_INTR_SLAVE_MASK_REG  = uartUser_UART_DEFAULT_INTR_SLAVE_MASK;
        uartUser_INTR_MASTER_MASK_REG = uartUser_UART_DEFAULT_INTR_MASTER_MASK;
        uartUser_INTR_RX_MASK_REG     = uartUser_UART_DEFAULT_INTR_RX_MASK;
        uartUser_INTR_TX_MASK_REG     = uartUser_UART_DEFAULT_INTR_TX_MASK;

        /* Configure TX interrupt sources to restore. */
        uartUser_IntrTxMask = LO16(uartUser_INTR_TX_MASK_REG);

    #if(uartUser_INTERNAL_RX_SW_BUFFER_CONST)
        uartUser_rxBufferHead     = 0u;
        uartUser_rxBufferTail     = 0u;
        uartUser_rxBufferOverflow = 0u;
    #endif /* (uartUser_INTERNAL_RX_SW_BUFFER_CONST) */

    #if(uartUser_INTERNAL_TX_SW_BUFFER_CONST)
        uartUser_txBufferHead = 0u;
        uartUser_txBufferTail = 0u;
    #endif /* (uartUser_INTERNAL_TX_SW_BUFFER_CONST) */
    }
#endif /* (uartUser_SCB_MODE_UNCONFIG_CONST_CFG) */


/*******************************************************************************
* Function Name: uartUser_UartPostEnable
****************************************************************************//**
*
*  Restores HSIOM settings for the UART output pins (TX and/or RTS) to be
*  controlled by the SCB UART.
*
*******************************************************************************/
void uartUser_UartPostEnable(void)
{
#if (uartUser_SCB_MODE_UNCONFIG_CONST_CFG)
    #if (uartUser_TX_SDA_MISO_PIN)
        if (uartUser_CHECK_TX_SDA_MISO_PIN_USED)
        {
            /* Set SCB UART to drive the output pin */
            uartUser_SET_HSIOM_SEL(uartUser_TX_SDA_MISO_HSIOM_REG, uartUser_TX_SDA_MISO_HSIOM_MASK,
                                           uartUser_TX_SDA_MISO_HSIOM_POS, uartUser_TX_SDA_MISO_HSIOM_SEL_UART);
        }
    #endif /* (uartUser_TX_SDA_MISO_PIN_PIN) */

    #if !(uartUser_CY_SCBIP_V0 || uartUser_CY_SCBIP_V1)
        #if (uartUser_SS0_PIN)
            if (uartUser_CHECK_SS0_PIN_USED)
            {
                /* Set SCB UART to drive the output pin */
                uartUser_SET_HSIOM_SEL(uartUser_SS0_HSIOM_REG, uartUser_SS0_HSIOM_MASK,
                                               uartUser_SS0_HSIOM_POS, uartUser_SS0_HSIOM_SEL_UART);
            }
        #endif /* (uartUser_SS0_PIN) */
    #endif /* !(uartUser_CY_SCBIP_V0 || uartUser_CY_SCBIP_V1) */

#else
    #if (uartUser_UART_TX_PIN)
         /* Set SCB UART to drive the output pin */
        uartUser_SET_HSIOM_SEL(uartUser_TX_HSIOM_REG, uartUser_TX_HSIOM_MASK,
                                       uartUser_TX_HSIOM_POS, uartUser_TX_HSIOM_SEL_UART);
    #endif /* (uartUser_UART_TX_PIN) */

    #if (uartUser_UART_RTS_PIN)
        /* Set SCB UART to drive the output pin */
        uartUser_SET_HSIOM_SEL(uartUser_RTS_HSIOM_REG, uartUser_RTS_HSIOM_MASK,
                                       uartUser_RTS_HSIOM_POS, uartUser_RTS_HSIOM_SEL_UART);
    #endif /* (uartUser_UART_RTS_PIN) */
#endif /* (uartUser_SCB_MODE_UNCONFIG_CONST_CFG) */

    /* Restore TX interrupt sources. */
    uartUser_SetTxInterruptMode(uartUser_IntrTxMask);
}


/*******************************************************************************
* Function Name: uartUser_UartStop
****************************************************************************//**
*
*  Changes the HSIOM settings for the UART output pins (TX and/or RTS) to keep
*  them inactive after the block is disabled. The output pins are controlled by
*  the GPIO data register. Also, the function disables the skip start feature
*  to not cause it to trigger after the component is enabled.
*
*******************************************************************************/
void uartUser_UartStop(void)
{
#if(uartUser_SCB_MODE_UNCONFIG_CONST_CFG)
    #if (uartUser_TX_SDA_MISO_PIN)
        if (uartUser_CHECK_TX_SDA_MISO_PIN_USED)
        {
            /* Set GPIO to drive output pin */
            uartUser_SET_HSIOM_SEL(uartUser_TX_SDA_MISO_HSIOM_REG, uartUser_TX_SDA_MISO_HSIOM_MASK,
                                           uartUser_TX_SDA_MISO_HSIOM_POS, uartUser_TX_SDA_MISO_HSIOM_SEL_GPIO);
        }
    #endif /* (uartUser_TX_SDA_MISO_PIN_PIN) */

    #if !(uartUser_CY_SCBIP_V0 || uartUser_CY_SCBIP_V1)
        #if (uartUser_SS0_PIN)
            if (uartUser_CHECK_SS0_PIN_USED)
            {
                /* Set output pin state after block is disabled */
                uartUser_spi_ss0_Write(uartUser_GET_UART_RTS_INACTIVE);

                /* Set GPIO to drive output pin */
                uartUser_SET_HSIOM_SEL(uartUser_SS0_HSIOM_REG, uartUser_SS0_HSIOM_MASK,
                                               uartUser_SS0_HSIOM_POS, uartUser_SS0_HSIOM_SEL_GPIO);
            }
        #endif /* (uartUser_SS0_PIN) */
    #endif /* !(uartUser_CY_SCBIP_V0 || uartUser_CY_SCBIP_V1) */

#else
    #if (uartUser_UART_TX_PIN)
        /* Set GPIO to drive output pin */
        uartUser_SET_HSIOM_SEL(uartUser_TX_HSIOM_REG, uartUser_TX_HSIOM_MASK,
                                       uartUser_TX_HSIOM_POS, uartUser_TX_HSIOM_SEL_GPIO);
    #endif /* (uartUser_UART_TX_PIN) */

    #if (uartUser_UART_RTS_PIN)
        /* Set output pin state after block is disabled */
        uartUser_rts_Write(uartUser_GET_UART_RTS_INACTIVE);

        /* Set GPIO to drive output pin */
        uartUser_SET_HSIOM_SEL(uartUser_RTS_HSIOM_REG, uartUser_RTS_HSIOM_MASK,
                                       uartUser_RTS_HSIOM_POS, uartUser_RTS_HSIOM_SEL_GPIO);
    #endif /* (uartUser_UART_RTS_PIN) */

#endif /* (uartUser_SCB_MODE_UNCONFIG_CONST_CFG) */

#if (uartUser_UART_WAKE_ENABLE_CONST)
    /* Disable skip start feature used for wakeup */
    uartUser_UART_RX_CTRL_REG &= (uint32) ~uartUser_UART_RX_CTRL_SKIP_START;
#endif /* (uartUser_UART_WAKE_ENABLE_CONST) */

    /* Store TX interrupt sources (exclude level triggered). */
    uartUser_IntrTxMask = LO16(uartUser_GetTxInterruptMode() & uartUser_INTR_UART_TX_RESTORE);
}


/*******************************************************************************
* Function Name: uartUser_UartSetRxAddress
****************************************************************************//**
*
*  Sets the hardware detectable receiver address for the UART in the
*  Multiprocessor mode.
*
*  \param address: Address for hardware address detection.
*
*******************************************************************************/
void uartUser_UartSetRxAddress(uint32 address)
{
     uint32 matchReg;

    matchReg = uartUser_RX_MATCH_REG;

    matchReg &= ((uint32) ~uartUser_RX_MATCH_ADDR_MASK); /* Clear address bits */
    matchReg |= ((uint32)  (address & uartUser_RX_MATCH_ADDR_MASK)); /* Set address  */

    uartUser_RX_MATCH_REG = matchReg;
}


/*******************************************************************************
* Function Name: uartUser_UartSetRxAddressMask
****************************************************************************//**
*
*  Sets the hardware address mask for the UART in the Multiprocessor mode.
*
*  \param addressMask: Address mask.
*   - Bit value 0 – excludes bit from address comparison.
*   - Bit value 1 – the bit needs to match with the corresponding bit
*     of the address.
*
*******************************************************************************/
void uartUser_UartSetRxAddressMask(uint32 addressMask)
{
    uint32 matchReg;

    matchReg = uartUser_RX_MATCH_REG;

    matchReg &= ((uint32) ~uartUser_RX_MATCH_MASK_MASK); /* Clear address mask bits */
    matchReg |= ((uint32) (addressMask << uartUser_RX_MATCH_MASK_POS));

    uartUser_RX_MATCH_REG = matchReg;
}


#if(uartUser_UART_RX_DIRECTION)
    /*******************************************************************************
    * Function Name: uartUser_UartGetChar
    ****************************************************************************//**
    *
    *  Retrieves next data element from receive buffer.
    *  This function is designed for ASCII characters and returns a char where
    *  1 to 255 are valid characters and 0 indicates an error occurred or no data
    *  is present.
    *  - RX software buffer is disabled: Returns data element retrieved from RX
    *    FIFO.
    *  - RX software buffer is enabled: Returns data element from the software
    *    receive buffer.
    *
    *  \return
    *   Next data element from the receive buffer. ASCII character values from
    *   1 to 255 are valid. A returned zero signifies an error condition or no
    *   data available.
    *
    *  \sideeffect
    *   The errors bits may not correspond with reading characters due to
    *   RX FIFO and software buffer usage.
    *   RX software buffer is enabled: The internal software buffer overflow
    *   is not treated as an error condition.
    *   Check uartUser_rxBufferOverflow to capture that error condition.
    *
    *******************************************************************************/
    uint32 uartUser_UartGetChar(void)
    {
        uint32 rxData = 0u;

        /* Reads data only if there is data to read */
        if (0u != uartUser_SpiUartGetRxBufferSize())
        {
            rxData = uartUser_SpiUartReadRxData();
        }

        if (uartUser_CHECK_INTR_RX(uartUser_INTR_RX_ERR))
        {
            rxData = 0u; /* Error occurred: returns zero */
            uartUser_ClearRxInterruptSource(uartUser_INTR_RX_ERR);
        }

        return (rxData);
    }


    /*******************************************************************************
    * Function Name: uartUser_UartGetByte
    ****************************************************************************//**
    *
    *  Retrieves the next data element from the receive buffer, returns the
    *  received byte and error condition.
    *   - The RX software buffer is disabled: returns the data element retrieved
    *     from the RX FIFO. Undefined data will be returned if the RX FIFO is
    *     empty.
    *   - The RX software buffer is enabled: returns data element from the
    *     software receive buffer.
    *
    *  \return
    *   Bits 7-0 contain the next data element from the receive buffer and
    *   other bits contain the error condition.
    *   - uartUser_UART_RX_OVERFLOW - Attempt to write to a full
    *     receiver FIFO.
    *   - uartUser_UART_RX_UNDERFLOW    Attempt to read from an empty
    *     receiver FIFO.
    *   - uartUser_UART_RX_FRAME_ERROR - UART framing error detected.
    *   - uartUser_UART_RX_PARITY_ERROR - UART parity error detected.
    *
    *  \sideeffect
    *   The errors bits may not correspond with reading characters due to
    *   RX FIFO and software buffer usage.
    *   RX software buffer is enabled: The internal software buffer overflow
    *   is not treated as an error condition.
    *   Check uartUser_rxBufferOverflow to capture that error condition.
    *
    *******************************************************************************/
    uint32 uartUser_UartGetByte(void)
    {
        uint32 rxData;
        uint32 tmpStatus;

        #if (uartUser_CHECK_RX_SW_BUFFER)
        {
            uartUser_DisableInt();
        }
        #endif

        if (0u != uartUser_SpiUartGetRxBufferSize())
        {
            /* Enables interrupt to receive more bytes: at least one byte is in
            * buffer.
            */
            #if (uartUser_CHECK_RX_SW_BUFFER)
            {
                uartUser_EnableInt();
            }
            #endif

            /* Get received byte */
            rxData = uartUser_SpiUartReadRxData();
        }
        else
        {
            /* Reads a byte directly from RX FIFO: underflow is raised in the
            * case of empty. Otherwise the first received byte will be read.
            */
            rxData = uartUser_RX_FIFO_RD_REG;


            /* Enables interrupt to receive more bytes. */
            #if (uartUser_CHECK_RX_SW_BUFFER)
            {

                /* The byte has been read from RX FIFO. Clear RX interrupt to
                * not involve interrupt handler when RX FIFO is empty.
                */
                uartUser_ClearRxInterruptSource(uartUser_INTR_RX_NOT_EMPTY);

                uartUser_EnableInt();
            }
            #endif
        }

        /* Get and clear RX error mask */
        tmpStatus = (uartUser_GetRxInterruptSource() & uartUser_INTR_RX_ERR);
        uartUser_ClearRxInterruptSource(uartUser_INTR_RX_ERR);

        /* Puts together data and error status:
        * MP mode and accept address: 9th bit is set to notify mark.
        */
        rxData |= ((uint32) (tmpStatus << 8u));

        return (rxData);
    }


    #if !(uartUser_CY_SCBIP_V0 || uartUser_CY_SCBIP_V1)
        /*******************************************************************************
        * Function Name: uartUser_UartSetRtsPolarity
        ****************************************************************************//**
        *
        *  Sets active polarity of RTS output signal.
        *  Only available for PSoC 4100 BLE / PSoC 4200 BLE / PSoC 4100M / PSoC 4200M /
        *  PSoC 4200L / PSoC 4000S / PSoC 4100S / PSoC Analog Coprocessor devices.
        *
        *  \param polarity: Active polarity of RTS output signal.
        *   - uartUser_UART_RTS_ACTIVE_LOW  - RTS signal is active low.
        *   - uartUser_UART_RTS_ACTIVE_HIGH - RTS signal is active high.
        *
        *******************************************************************************/
        void uartUser_UartSetRtsPolarity(uint32 polarity)
        {
            if(0u != polarity)
            {
                uartUser_UART_FLOW_CTRL_REG |= (uint32)  uartUser_UART_FLOW_CTRL_RTS_POLARITY;
            }
            else
            {
                uartUser_UART_FLOW_CTRL_REG &= (uint32) ~uartUser_UART_FLOW_CTRL_RTS_POLARITY;
            }
        }


        /*******************************************************************************
        * Function Name: uartUser_UartSetRtsFifoLevel
        ****************************************************************************//**
        *
        *  Sets level in the RX FIFO for RTS signal activation.
        *  While the RX FIFO has fewer entries than the RX FIFO level the RTS signal
        *  remains active, otherwise the RTS signal becomes inactive.
        *  Only available for PSoC 4100 BLE / PSoC 4200 BLE / PSoC 4100M / PSoC 4200M /
        *  PSoC 4200L / PSoC 4000S / PSoC 4100S / PSoC Analog Coprocessor devices.
        *
        *  \param level: Level in the RX FIFO for RTS signal activation.
        *   The range of valid level values is between 0 and RX FIFO depth - 1.
        *   Setting level value to 0 disables RTS signal activation.
        *
        *******************************************************************************/
        void uartUser_UartSetRtsFifoLevel(uint32 level)
        {
            uint32 uartFlowCtrl;

            uartFlowCtrl = uartUser_UART_FLOW_CTRL_REG;

            uartFlowCtrl &= ((uint32) ~uartUser_UART_FLOW_CTRL_TRIGGER_LEVEL_MASK); /* Clear level mask bits */
            uartFlowCtrl |= ((uint32) (uartUser_UART_FLOW_CTRL_TRIGGER_LEVEL_MASK & level));

            uartUser_UART_FLOW_CTRL_REG = uartFlowCtrl;
        }
    #endif /* !(uartUser_CY_SCBIP_V0 || uartUser_CY_SCBIP_V1) */

#endif /* (uartUser_UART_RX_DIRECTION) */


#if(uartUser_UART_TX_DIRECTION)
    /*******************************************************************************
    * Function Name: uartUser_UartPutString
    ****************************************************************************//**
    *
    *  Places a NULL terminated string in the transmit buffer to be sent at the
    *  next available bus time.
    *  This function is blocking and waits until there is a space available to put
    *  requested data in transmit buffer.
    *
    *  \param string: pointer to the null terminated string array to be placed in the
    *   transmit buffer.
    *
    *******************************************************************************/
    void uartUser_UartPutString(const char8 string[])
    {
        uint32 bufIndex;

        bufIndex = 0u;

        /* Blocks the control flow until all data has been sent */
        while(string[bufIndex] != ((char8) 0))
        {
            uartUser_UartPutChar((uint32) string[bufIndex]);
            bufIndex++;
        }
    }


    /*******************************************************************************
    * Function Name: uartUser_UartPutCRLF
    ****************************************************************************//**
    *
    *  Places byte of data followed by a carriage return (0x0D) and line feed
    *  (0x0A) in the transmit buffer.
    *  This function is blocking and waits until there is a space available to put
    *  all requested data in transmit buffer.
    *
    *  \param txDataByte: the data to be transmitted.
    *
    *******************************************************************************/
    void uartUser_UartPutCRLF(uint32 txDataByte)
    {
        uartUser_UartPutChar(txDataByte);  /* Blocks control flow until all data has been sent */
        uartUser_UartPutChar(0x0Du);       /* Blocks control flow until all data has been sent */
        uartUser_UartPutChar(0x0Au);       /* Blocks control flow until all data has been sent */
    }


    #if !(uartUser_CY_SCBIP_V0 || uartUser_CY_SCBIP_V1)
        /*******************************************************************************
        * Function Name: uartUserSCB_UartEnableCts
        ****************************************************************************//**
        *
        *  Enables usage of CTS input signal by the UART transmitter.
        *  Only available for PSoC 4100 BLE / PSoC 4200 BLE / PSoC 4100M / PSoC 4200M /
        *  PSoC 4200L / PSoC 4000S / PSoC 4100S / PSoC Analog Coprocessor devices.
        *
        *******************************************************************************/
        void uartUser_UartEnableCts(void)
        {
            uartUser_UART_FLOW_CTRL_REG |= (uint32)  uartUser_UART_FLOW_CTRL_CTS_ENABLE;
        }


        /*******************************************************************************
        * Function Name: uartUser_UartDisableCts
        ****************************************************************************//**
        *
        *  Disables usage of CTS input signal by the UART transmitter.
        *  Only available for PSoC 4100 BLE / PSoC 4200 BLE / PSoC 4100M / PSoC 4200M /
        *  PSoC 4200L / PSoC 4000S / PSoC 4100S / PSoC Analog Coprocessor devices.
        *
        *******************************************************************************/
        void uartUser_UartDisableCts(void)
        {
            uartUser_UART_FLOW_CTRL_REG &= (uint32) ~uartUser_UART_FLOW_CTRL_CTS_ENABLE;
        }


        /*******************************************************************************
        * Function Name: uartUser_UartSetCtsPolarity
        ****************************************************************************//**
        *
        *  Sets active polarity of CTS input signal.
        *  Only available for PSoC 4100 BLE / PSoC 4200 BLE / PSoC 4100M / PSoC 4200M /
        *  PSoC 4200L / PSoC 4000S / PSoC 4100S / PSoC Analog Coprocessor devices.
        *
        * \param
        * polarity: Active polarity of CTS output signal.
        *   - uartUser_UART_CTS_ACTIVE_LOW  - CTS signal is active low.
        *   - uartUser_UART_CTS_ACTIVE_HIGH - CTS signal is active high.
        *
        *******************************************************************************/
        void uartUser_UartSetCtsPolarity(uint32 polarity)
        {
            if (0u != polarity)
            {
                uartUser_UART_FLOW_CTRL_REG |= (uint32)  uartUser_UART_FLOW_CTRL_CTS_POLARITY;
            }
            else
            {
                uartUser_UART_FLOW_CTRL_REG &= (uint32) ~uartUser_UART_FLOW_CTRL_CTS_POLARITY;
            }
        }
    #endif /* !(uartUser_CY_SCBIP_V0 || uartUser_CY_SCBIP_V1) */


    /*******************************************************************************
    * Function Name: uartUser_UartSendBreakBlocking
    ****************************************************************************//**
    *
    * Sends a break condition (logic low) of specified width on UART TX line.
    * Blocks until break is completed. Only call this function when UART TX FIFO
    * and shifter are empty.
    *
    * \param breakWidth
    * Width of break condition. Valid range is 4 to 16 bits.
    *
    * \note
    * Before sending break all UART TX interrupt sources are disabled. The state
    * of UART TX interrupt sources is restored before function returns.
    *
    * \sideeffect
    * If this function is called while there is data in the TX FIFO or shifter that
    * data will be shifted out in packets the size of breakWidth.
    *
    *******************************************************************************/
    void uartUser_UartSendBreakBlocking(uint32 breakWidth)
    {
        uint32 txCtrlReg;
        uint32 txIntrReg;

        /* Disable all UART TX interrupt source and clear UART TX Done history */
        txIntrReg = uartUser_GetTxInterruptMode();
        uartUser_SetTxInterruptMode(0u);
        uartUser_ClearTxInterruptSource(uartUser_INTR_TX_UART_DONE);

        /* Store TX CTRL configuration */
        txCtrlReg = uartUser_TX_CTRL_REG;

        /* Set break width */
        uartUser_TX_CTRL_REG = (uartUser_TX_CTRL_REG & (uint32) ~uartUser_TX_CTRL_DATA_WIDTH_MASK) |
                                        uartUser_GET_TX_CTRL_DATA_WIDTH(breakWidth);

        /* Generate break */
        uartUser_TX_FIFO_WR_REG = 0u;

        /* Wait for break completion */
        while (0u == (uartUser_GetTxInterruptSource() & uartUser_INTR_TX_UART_DONE))
        {
        }

        /* Clear all UART TX interrupt sources to  */
        uartUser_ClearTxInterruptSource(uartUser_INTR_TX_ALL);

        /* Restore TX interrupt sources and data width */
        uartUser_TX_CTRL_REG = txCtrlReg;
        uartUser_SetTxInterruptMode(txIntrReg);
    }
#endif /* (uartUser_UART_TX_DIRECTION) */


#if (uartUser_UART_WAKE_ENABLE_CONST)
    /*******************************************************************************
    * Function Name: uartUser_UartSaveConfig
    ****************************************************************************//**
    *
    *  Clears and enables an interrupt on a falling edge of the Rx input. The GPIO
    *  interrupt does not track in the active mode, therefore requires to be
    *  cleared by this API.
    *
    *******************************************************************************/
    void uartUser_UartSaveConfig(void)
    {
    #if (uartUser_UART_RX_WAKEUP_IRQ)
        /* Set SKIP_START if requested (set by default). */
        if (0u != uartUser_skipStart)
        {
            uartUser_UART_RX_CTRL_REG |= (uint32)  uartUser_UART_RX_CTRL_SKIP_START;
        }
        else
        {
            uartUser_UART_RX_CTRL_REG &= (uint32) ~uartUser_UART_RX_CTRL_SKIP_START;
        }

        /* Clear RX GPIO interrupt status and pending interrupt in NVIC because
        * falling edge on RX line occurs while UART communication in active mode.
        * Enable interrupt: next interrupt trigger should wakeup device.
        */
        uartUser_CLEAR_UART_RX_WAKE_INTR;
        uartUser_RxWakeClearPendingInt();
        uartUser_RxWakeEnableInt();
    #endif /* (uartUser_UART_RX_WAKEUP_IRQ) */
    }


    /*******************************************************************************
    * Function Name: uartUser_UartRestoreConfig
    ****************************************************************************//**
    *
    *  Disables the RX GPIO interrupt. Until this function is called the interrupt
    *  remains active and triggers on every falling edge of the UART RX line.
    *
    *******************************************************************************/
    void uartUser_UartRestoreConfig(void)
    {
    #if (uartUser_UART_RX_WAKEUP_IRQ)
        /* Disable interrupt: no more triggers in active mode */
        uartUser_RxWakeDisableInt();
    #endif /* (uartUser_UART_RX_WAKEUP_IRQ) */
    }


    #if (uartUser_UART_RX_WAKEUP_IRQ)
        /*******************************************************************************
        * Function Name: uartUser_UART_WAKEUP_ISR
        ****************************************************************************//**
        *
        *  Handles the Interrupt Service Routine for the SCB UART mode GPIO wakeup
        *  event. This event is configured to trigger on a falling edge of the RX line.
        *
        *******************************************************************************/
        CY_ISR(uartUser_UART_WAKEUP_ISR)
        {
        #ifdef uartUser_UART_WAKEUP_ISR_ENTRY_CALLBACK
            uartUser_UART_WAKEUP_ISR_EntryCallback();
        #endif /* uartUser_UART_WAKEUP_ISR_ENTRY_CALLBACK */

            uartUser_CLEAR_UART_RX_WAKE_INTR;

        #ifdef uartUser_UART_WAKEUP_ISR_EXIT_CALLBACK
            uartUser_UART_WAKEUP_ISR_ExitCallback();
        #endif /* uartUser_UART_WAKEUP_ISR_EXIT_CALLBACK */
        }
    #endif /* (uartUser_UART_RX_WAKEUP_IRQ) */
#endif /* (uartUser_UART_RX_WAKEUP_IRQ) */


/* [] END OF FILE */
