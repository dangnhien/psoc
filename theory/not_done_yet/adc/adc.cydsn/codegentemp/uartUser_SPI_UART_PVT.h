/***************************************************************************//**
* \file uartUser_SPI_UART_PVT.h
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

#if !defined(CY_SCB_SPI_UART_PVT_uartUser_H)
#define CY_SCB_SPI_UART_PVT_uartUser_H

#include "uartUser_SPI_UART.h"


/***************************************
*     Internal Global Vars
***************************************/

#if (uartUser_INTERNAL_RX_SW_BUFFER_CONST)
    extern volatile uint32  uartUser_rxBufferHead;
    extern volatile uint32  uartUser_rxBufferTail;
    
    /**
    * \addtogroup group_globals
    * @{
    */
    
    /** Sets when internal software receive buffer overflow
     *  was occurred.
    */  
    extern volatile uint8   uartUser_rxBufferOverflow;
    /** @} globals */
#endif /* (uartUser_INTERNAL_RX_SW_BUFFER_CONST) */

#if (uartUser_INTERNAL_TX_SW_BUFFER_CONST)
    extern volatile uint32  uartUser_txBufferHead;
    extern volatile uint32  uartUser_txBufferTail;
#endif /* (uartUser_INTERNAL_TX_SW_BUFFER_CONST) */

#if (uartUser_INTERNAL_RX_SW_BUFFER)
    extern volatile uint8 uartUser_rxBufferInternal[uartUser_INTERNAL_RX_BUFFER_SIZE];
#endif /* (uartUser_INTERNAL_RX_SW_BUFFER) */

#if (uartUser_INTERNAL_TX_SW_BUFFER)
    extern volatile uint8 uartUser_txBufferInternal[uartUser_TX_BUFFER_SIZE];
#endif /* (uartUser_INTERNAL_TX_SW_BUFFER) */


/***************************************
*     Private Function Prototypes
***************************************/

void uartUser_SpiPostEnable(void);
void uartUser_SpiStop(void);

#if (uartUser_SCB_MODE_SPI_CONST_CFG)
    void uartUser_SpiInit(void);
#endif /* (uartUser_SCB_MODE_SPI_CONST_CFG) */

#if (uartUser_SPI_WAKE_ENABLE_CONST)
    void uartUser_SpiSaveConfig(void);
    void uartUser_SpiRestoreConfig(void);
#endif /* (uartUser_SPI_WAKE_ENABLE_CONST) */

void uartUser_UartPostEnable(void);
void uartUser_UartStop(void);

#if (uartUser_SCB_MODE_UART_CONST_CFG)
    void uartUser_UartInit(void);
#endif /* (uartUser_SCB_MODE_UART_CONST_CFG) */

#if (uartUser_UART_WAKE_ENABLE_CONST)
    void uartUser_UartSaveConfig(void);
    void uartUser_UartRestoreConfig(void);
#endif /* (uartUser_UART_WAKE_ENABLE_CONST) */


/***************************************
*         UART API Constants
***************************************/

/* UART RX and TX position to be used in uartUser_SetPins() */
#define uartUser_UART_RX_PIN_ENABLE    (uartUser_UART_RX)
#define uartUser_UART_TX_PIN_ENABLE    (uartUser_UART_TX)

/* UART RTS and CTS position to be used in  uartUser_SetPins() */
#define uartUser_UART_RTS_PIN_ENABLE    (0x10u)
#define uartUser_UART_CTS_PIN_ENABLE    (0x20u)


/***************************************
* The following code is DEPRECATED and
* must not be used.
***************************************/

/* Interrupt processing */
#define uartUser_SpiUartEnableIntRx(intSourceMask)  uartUser_SetRxInterruptMode(intSourceMask)
#define uartUser_SpiUartEnableIntTx(intSourceMask)  uartUser_SetTxInterruptMode(intSourceMask)
uint32  uartUser_SpiUartDisableIntRx(void);
uint32  uartUser_SpiUartDisableIntTx(void);


#endif /* (CY_SCB_SPI_UART_PVT_uartUser_H) */


/* [] END OF FILE */
