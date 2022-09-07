/***************************************************************************//**
* \file uart_transmit_data_SPI_UART_INT.c
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

#include "uart_transmit_data_PVT.h"
#include "uart_transmit_data_SPI_UART_PVT.h"
#include "cyapicallbacks.h"

#if (uart_transmit_data_SCB_IRQ_INTERNAL)
/*******************************************************************************
* Function Name: uart_transmit_data_SPI_UART_ISR
****************************************************************************//**
*
*  Handles the Interrupt Service Routine for the SCB SPI or UART modes.
*
*******************************************************************************/
CY_ISR(uart_transmit_data_SPI_UART_ISR)
{
#if (uart_transmit_data_INTERNAL_RX_SW_BUFFER_CONST)
    uint32 locHead;
#endif /* (uart_transmit_data_INTERNAL_RX_SW_BUFFER_CONST) */

#if (uart_transmit_data_INTERNAL_TX_SW_BUFFER_CONST)
    uint32 locTail;
#endif /* (uart_transmit_data_INTERNAL_TX_SW_BUFFER_CONST) */

#ifdef uart_transmit_data_SPI_UART_ISR_ENTRY_CALLBACK
    uart_transmit_data_SPI_UART_ISR_EntryCallback();
#endif /* uart_transmit_data_SPI_UART_ISR_ENTRY_CALLBACK */

    if (NULL != uart_transmit_data_customIntrHandler)
    {
        uart_transmit_data_customIntrHandler();
    }

    #if(uart_transmit_data_CHECK_SPI_WAKE_ENABLE)
    {
        /* Clear SPI wakeup source */
        uart_transmit_data_ClearSpiExtClkInterruptSource(uart_transmit_data_INTR_SPI_EC_WAKE_UP);
    }
    #endif

    #if (uart_transmit_data_CHECK_RX_SW_BUFFER)
    {
        if (uart_transmit_data_CHECK_INTR_RX_MASKED(uart_transmit_data_INTR_RX_NOT_EMPTY))
        {
            do
            {
                /* Move local head index */
                locHead = (uart_transmit_data_rxBufferHead + 1u);

                /* Adjust local head index */
                if (uart_transmit_data_INTERNAL_RX_BUFFER_SIZE == locHead)
                {
                    locHead = 0u;
                }

                if (locHead == uart_transmit_data_rxBufferTail)
                {
                    #if (uart_transmit_data_CHECK_UART_RTS_CONTROL_FLOW)
                    {
                        /* There is no space in the software buffer - disable the
                        * RX Not Empty interrupt source. The data elements are
                        * still being received into the RX FIFO until the RTS signal
                        * stops the transmitter. After the data element is read from the
                        * buffer, the RX Not Empty interrupt source is enabled to
                        * move the next data element in the software buffer.
                        */
                        uart_transmit_data_INTR_RX_MASK_REG &= ~uart_transmit_data_INTR_RX_NOT_EMPTY;
                        break;
                    }
                    #else
                    {
                        /* Overflow: through away received data element */
                        (void) uart_transmit_data_RX_FIFO_RD_REG;
                        uart_transmit_data_rxBufferOverflow = (uint8) uart_transmit_data_INTR_RX_OVERFLOW;
                    }
                    #endif
                }
                else
                {
                    /* Store received data */
                    uart_transmit_data_PutWordInRxBuffer(locHead, uart_transmit_data_RX_FIFO_RD_REG);

                    /* Move head index */
                    uart_transmit_data_rxBufferHead = locHead;
                }
            }
            while(0u != uart_transmit_data_GET_RX_FIFO_ENTRIES);

            uart_transmit_data_ClearRxInterruptSource(uart_transmit_data_INTR_RX_NOT_EMPTY);
        }
    }
    #endif


    #if (uart_transmit_data_CHECK_TX_SW_BUFFER)
    {
        if (uart_transmit_data_CHECK_INTR_TX_MASKED(uart_transmit_data_INTR_TX_NOT_FULL))
        {
            do
            {
                /* Check for room in TX software buffer */
                if (uart_transmit_data_txBufferHead != uart_transmit_data_txBufferTail)
                {
                    /* Move local tail index */
                    locTail = (uart_transmit_data_txBufferTail + 1u);

                    /* Adjust local tail index */
                    if (uart_transmit_data_TX_BUFFER_SIZE == locTail)
                    {
                        locTail = 0u;
                    }

                    /* Put data into TX FIFO */
                    uart_transmit_data_TX_FIFO_WR_REG = uart_transmit_data_GetWordFromTxBuffer(locTail);

                    /* Move tail index */
                    uart_transmit_data_txBufferTail = locTail;
                }
                else
                {
                    /* TX software buffer is empty: complete transfer */
                    uart_transmit_data_DISABLE_INTR_TX(uart_transmit_data_INTR_TX_NOT_FULL);
                    break;
                }
            }
            while (uart_transmit_data_SPI_UART_FIFO_SIZE != uart_transmit_data_GET_TX_FIFO_ENTRIES);

            uart_transmit_data_ClearTxInterruptSource(uart_transmit_data_INTR_TX_NOT_FULL);
        }
    }
    #endif

#ifdef uart_transmit_data_SPI_UART_ISR_EXIT_CALLBACK
    uart_transmit_data_SPI_UART_ISR_ExitCallback();
#endif /* uart_transmit_data_SPI_UART_ISR_EXIT_CALLBACK */

}

#endif /* (uart_transmit_data_SCB_IRQ_INTERNAL) */


/* [] END OF FILE */
