/***************************************************************************//**
* \file uart_transmit_data_SPI_UART_PVT.h
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

#if !defined(CY_SCB_SPI_UART_PVT_uart_transmit_data_H)
#define CY_SCB_SPI_UART_PVT_uart_transmit_data_H

#include "uart_transmit_data_SPI_UART.h"


/***************************************
*     Internal Global Vars
***************************************/

#if (uart_transmit_data_INTERNAL_RX_SW_BUFFER_CONST)
    extern volatile uint32  uart_transmit_data_rxBufferHead;
    extern volatile uint32  uart_transmit_data_rxBufferTail;
    
    /**
    * \addtogroup group_globals
    * @{
    */
    
    /** Sets when internal software receive buffer overflow
     *  was occurred.
    */  
    extern volatile uint8   uart_transmit_data_rxBufferOverflow;
    /** @} globals */
#endif /* (uart_transmit_data_INTERNAL_RX_SW_BUFFER_CONST) */

#if (uart_transmit_data_INTERNAL_TX_SW_BUFFER_CONST)
    extern volatile uint32  uart_transmit_data_txBufferHead;
    extern volatile uint32  uart_transmit_data_txBufferTail;
#endif /* (uart_transmit_data_INTERNAL_TX_SW_BUFFER_CONST) */

#if (uart_transmit_data_INTERNAL_RX_SW_BUFFER)
    extern volatile uint8 uart_transmit_data_rxBufferInternal[uart_transmit_data_INTERNAL_RX_BUFFER_SIZE];
#endif /* (uart_transmit_data_INTERNAL_RX_SW_BUFFER) */

#if (uart_transmit_data_INTERNAL_TX_SW_BUFFER)
    extern volatile uint8 uart_transmit_data_txBufferInternal[uart_transmit_data_TX_BUFFER_SIZE];
#endif /* (uart_transmit_data_INTERNAL_TX_SW_BUFFER) */


/***************************************
*     Private Function Prototypes
***************************************/

void uart_transmit_data_SpiPostEnable(void);
void uart_transmit_data_SpiStop(void);

#if (uart_transmit_data_SCB_MODE_SPI_CONST_CFG)
    void uart_transmit_data_SpiInit(void);
#endif /* (uart_transmit_data_SCB_MODE_SPI_CONST_CFG) */

#if (uart_transmit_data_SPI_WAKE_ENABLE_CONST)
    void uart_transmit_data_SpiSaveConfig(void);
    void uart_transmit_data_SpiRestoreConfig(void);
#endif /* (uart_transmit_data_SPI_WAKE_ENABLE_CONST) */

void uart_transmit_data_UartPostEnable(void);
void uart_transmit_data_UartStop(void);

#if (uart_transmit_data_SCB_MODE_UART_CONST_CFG)
    void uart_transmit_data_UartInit(void);
#endif /* (uart_transmit_data_SCB_MODE_UART_CONST_CFG) */

#if (uart_transmit_data_UART_WAKE_ENABLE_CONST)
    void uart_transmit_data_UartSaveConfig(void);
    void uart_transmit_data_UartRestoreConfig(void);
#endif /* (uart_transmit_data_UART_WAKE_ENABLE_CONST) */


/***************************************
*         UART API Constants
***************************************/

/* UART RX and TX position to be used in uart_transmit_data_SetPins() */
#define uart_transmit_data_UART_RX_PIN_ENABLE    (uart_transmit_data_UART_RX)
#define uart_transmit_data_UART_TX_PIN_ENABLE    (uart_transmit_data_UART_TX)

/* UART RTS and CTS position to be used in  uart_transmit_data_SetPins() */
#define uart_transmit_data_UART_RTS_PIN_ENABLE    (0x10u)
#define uart_transmit_data_UART_CTS_PIN_ENABLE    (0x20u)


/***************************************
* The following code is DEPRECATED and
* must not be used.
***************************************/

/* Interrupt processing */
#define uart_transmit_data_SpiUartEnableIntRx(intSourceMask)  uart_transmit_data_SetRxInterruptMode(intSourceMask)
#define uart_transmit_data_SpiUartEnableIntTx(intSourceMask)  uart_transmit_data_SetTxInterruptMode(intSourceMask)
uint32  uart_transmit_data_SpiUartDisableIntRx(void);
uint32  uart_transmit_data_SpiUartDisableIntTx(void);


#endif /* (CY_SCB_SPI_UART_PVT_uart_transmit_data_H) */


/* [] END OF FILE */
