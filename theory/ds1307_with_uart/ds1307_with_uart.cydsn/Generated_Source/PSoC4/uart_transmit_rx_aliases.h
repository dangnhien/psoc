/*******************************************************************************
* File Name: uart_transmit_rx.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_uart_transmit_rx_ALIASES_H) /* Pins uart_transmit_rx_ALIASES_H */
#define CY_PINS_uart_transmit_rx_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define uart_transmit_rx_0			(uart_transmit_rx__0__PC)
#define uart_transmit_rx_0_PS		(uart_transmit_rx__0__PS)
#define uart_transmit_rx_0_PC		(uart_transmit_rx__0__PC)
#define uart_transmit_rx_0_DR		(uart_transmit_rx__0__DR)
#define uart_transmit_rx_0_SHIFT	(uart_transmit_rx__0__SHIFT)
#define uart_transmit_rx_0_INTR	((uint16)((uint16)0x0003u << (uart_transmit_rx__0__SHIFT*2u)))

#define uart_transmit_rx_INTR_ALL	 ((uint16)(uart_transmit_rx_0_INTR))


#endif /* End Pins uart_transmit_rx_ALIASES_H */


/* [] END OF FILE */
