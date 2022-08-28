/***************************************************************************//**
* \file uart_transmit_SPI_UART_PVT.h
* \version 4.0
*
* \brief
*  This private file provides constants and parameter values for the
*  SCB Component in SPI and UART modes.
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

#if !defined(CY_SCB_SPI_UART_PVT_uart_transmit_H)
#define CY_SCB_SPI_UART_PVT_uart_transmit_H

#include "uart_transmit_SPI_UART.h"


/***************************************
*     Internal Global Vars
***************************************/

#if (uart_transmit_INTERNAL_RX_SW_BUFFER_CONST)
    extern volatile uint32  uart_transmit_rxBufferHead;
    extern volatile uint32  uart_transmit_rxBufferTail;
    
    /**
    * \addtogroup group_globals
    * @{
    */
    
    /** Sets when internal software receive buffer overflow
     *  was occurred.
    */  
    extern volatile uint8   uart_transmit_rxBufferOverflow;
    /** @} globals */
#endif /* (uart_transmit_INTERNAL_RX_SW_BUFFER_CONST) */

#if (uart_transmit_INTERNAL_TX_SW_BUFFER_CONST)
    extern volatile uint32  uart_transmit_txBufferHead;
    extern volatile uint32  uart_transmit_txBufferTail;
#endif /* (uart_transmit_INTERNAL_TX_SW_BUFFER_CONST) */

#if (uart_transmit_INTERNAL_RX_SW_BUFFER)
    extern volatile uint8 uart_transmit_rxBufferInternal[uart_transmit_INTERNAL_RX_BUFFER_SIZE];
#endif /* (uart_transmit_INTERNAL_RX_SW_BUFFER) */

#if (uart_transmit_INTERNAL_TX_SW_BUFFER)
    extern volatile uint8 uart_transmit_txBufferInternal[uart_transmit_TX_BUFFER_SIZE];
#endif /* (uart_transmit_INTERNAL_TX_SW_BUFFER) */


/***************************************
*     Private Function Prototypes
***************************************/

void uart_transmit_SpiPostEnable(void);
void uart_transmit_SpiStop(void);

#if (uart_transmit_SCB_MODE_SPI_CONST_CFG)
    void uart_transmit_SpiInit(void);
#endif /* (uart_transmit_SCB_MODE_SPI_CONST_CFG) */

#if (uart_transmit_SPI_WAKE_ENABLE_CONST)
    void uart_transmit_SpiSaveConfig(void);
    void uart_transmit_SpiRestoreConfig(void);
#endif /* (uart_transmit_SPI_WAKE_ENABLE_CONST) */

void uart_transmit_UartPostEnable(void);
void uart_transmit_UartStop(void);

#if (uart_transmit_SCB_MODE_UART_CONST_CFG)
    void uart_transmit_UartInit(void);
#endif /* (uart_transmit_SCB_MODE_UART_CONST_CFG) */

#if (uart_transmit_UART_WAKE_ENABLE_CONST)
    void uart_transmit_UartSaveConfig(void);
    void uart_transmit_UartRestoreConfig(void);
#endif /* (uart_transmit_UART_WAKE_ENABLE_CONST) */


/***************************************
*         UART API Constants
***************************************/

/* UART RX and TX position to be used in uart_transmit_SetPins() */
#define uart_transmit_UART_RX_PIN_ENABLE    (uart_transmit_UART_RX)
#define uart_transmit_UART_TX_PIN_ENABLE    (uart_transmit_UART_TX)

/* UART RTS and CTS position to be used in  uart_transmit_SetPins() */
#define uart_transmit_UART_RTS_PIN_ENABLE    (0x10u)
#define uart_transmit_UART_CTS_PIN_ENABLE    (0x20u)


/***************************************
* The following code is DEPRECATED and
* must not be used.
***************************************/

/* Interrupt processing */
#define uart_transmit_SpiUartEnableIntRx(intSourceMask)  uart_transmit_SetRxInterruptMode(intSourceMask)
#define uart_transmit_SpiUartEnableIntTx(intSourceMask)  uart_transmit_SetTxInterruptMode(intSourceMask)
uint32  uart_transmit_SpiUartDisableIntRx(void);
uint32  uart_transmit_SpiUartDisableIntTx(void);


#endif /* (CY_SCB_SPI_UART_PVT_uart_transmit_H) */


/* [] END OF FILE */
