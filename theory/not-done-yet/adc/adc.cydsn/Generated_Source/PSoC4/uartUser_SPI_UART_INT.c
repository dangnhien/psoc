/***************************************************************************//**
* \file uartUser_SPI_UART_INT.c
* \version 4.0
*
* \brief
*  This file provides the source code to the Interrupt Service Routine for
*  the SCB Component in SPI and UART modes.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2013-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "uartUser_PVT.h"
#include "uartUser_SPI_UART_PVT.h"
#include "cyapicallbacks.h"

#if (uartUser_SCB_IRQ_INTERNAL)
/*******************************************************************************
* Function Name: uartUser_SPI_UART_ISR
****************************************************************************//**
*
*  Handles the Interrupt Service Routine for the SCB SPI or UART modes.
*
*******************************************************************************/
CY_ISR(uartUser_SPI_UART_ISR)
{
#if (uartUser_INTERNAL_RX_SW_BUFFER_CONST)
    uint32 locHead;
#endif /* (uartUser_INTERNAL_RX_SW_BUFFER_CONST) */

#if (uartUser_INTERNAL_TX_SW_BUFFER_CONST)
    uint32 locTail;
#endif /* (uartUser_INTERNAL_TX_SW_BUFFER_CONST) */

#ifdef uartUser_SPI_UART_ISR_ENTRY_CALLBACK
    uartUser_SPI_UART_ISR_EntryCallback();
#endif /* uartUser_SPI_UART_ISR_ENTRY_CALLBACK */

    if (NULL != uartUser_customIntrHandler)
    {
        uartUser_customIntrHandler();
    }

    #if(uartUser_CHECK_SPI_WAKE_ENABLE)
    {
        /* Clear SPI wakeup source */
        uartUser_ClearSpiExtClkInterruptSource(uartUser_INTR_SPI_EC_WAKE_UP);
    }
    #endif

    #if (uartUser_CHECK_RX_SW_BUFFER)
    {
        if (uartUser_CHECK_INTR_RX_MASKED(uartUser_INTR_RX_NOT_EMPTY))
        {
            do
            {
                /* Move local head index */
                locHead = (uartUser_rxBufferHead + 1u);

                /* Adjust local head index */
                if (uartUser_INTERNAL_RX_BUFFER_SIZE == locHead)
                {
                    locHead = 0u;
                }

                if (locHead == uartUser_rxBufferTail)
                {
                    #if (uartUser_CHECK_UART_RTS_CONTROL_FLOW)
                    {
                        /* There is no space in the software buffer - disable the
                        * RX Not Empty interrupt source. The data elements are
                        * still being received into the RX FIFO until the RTS signal
                        * stops the transmitter. After the data element is read from the
                        * buffer, the RX Not Empty interrupt source is enabled to
                        * move the next data element in the software buffer.
                        */
                        uartUser_INTR_RX_MASK_REG &= ~uartUser_INTR_RX_NOT_EMPTY;
                        break;
                    }
                    #else
                    {
                        /* Overflow: through away received data element */
                        (void) uartUser_RX_FIFO_RD_REG;
                        uartUser_rxBufferOverflow = (uint8) uartUser_INTR_RX_OVERFLOW;
                    }
                    #endif
                }
                else
                {
                    /* Store received data */
                    uartUser_PutWordInRxBuffer(locHead, uartUser_RX_FIFO_RD_REG);

                    /* Move head index */
                    uartUser_rxBufferHead = locHead;
                }
            }
            while(0u != uartUser_GET_RX_FIFO_ENTRIES);

            uartUser_ClearRxInterruptSource(uartUser_INTR_RX_NOT_EMPTY);
        }
    }
    #endif


    #if (uartUser_CHECK_TX_SW_BUFFER)
    {
        if (uartUser_CHECK_INTR_TX_MASKED(uartUser_INTR_TX_NOT_FULL))
        {
            do
            {
                /* Check for room in TX software buffer */
                if (uartUser_txBufferHead != uartUser_txBufferTail)
                {
                    /* Move local tail index */
                    locTail = (uartUser_txBufferTail + 1u);

                    /* Adjust local tail index */
                    if (uartUser_TX_BUFFER_SIZE == locTail)
                    {
                        locTail = 0u;
                    }

                    /* Put data into TX FIFO */
                    uartUser_TX_FIFO_WR_REG = uartUser_GetWordFromTxBuffer(locTail);

                    /* Move tail index */
                    uartUser_txBufferTail = locTail;
                }
                else
                {
                    /* TX software buffer is empty: complete transfer */
                    uartUser_DISABLE_INTR_TX(uartUser_INTR_TX_NOT_FULL);
                    break;
                }
            }
            while (uartUser_SPI_UART_FIFO_SIZE != uartUser_GET_TX_FIFO_ENTRIES);

            uartUser_ClearTxInterruptSource(uartUser_INTR_TX_NOT_FULL);
        }
    }
    #endif

#ifdef uartUser_SPI_UART_ISR_EXIT_CALLBACK
    uartUser_SPI_UART_ISR_ExitCallback();
#endif /* uartUser_SPI_UART_ISR_EXIT_CALLBACK */

}

#endif /* (uartUser_SCB_IRQ_INTERNAL) */


/* [] END OF FILE */
