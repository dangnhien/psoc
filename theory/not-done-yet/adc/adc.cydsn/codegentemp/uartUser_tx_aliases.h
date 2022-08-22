/*******************************************************************************
* File Name: uartUser_tx.h  
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

#if !defined(CY_PINS_uartUser_tx_ALIASES_H) /* Pins uartUser_tx_ALIASES_H */
#define CY_PINS_uartUser_tx_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define uartUser_tx_0			(uartUser_tx__0__PC)
#define uartUser_tx_0_PS		(uartUser_tx__0__PS)
#define uartUser_tx_0_PC		(uartUser_tx__0__PC)
#define uartUser_tx_0_DR		(uartUser_tx__0__DR)
#define uartUser_tx_0_SHIFT	(uartUser_tx__0__SHIFT)
#define uartUser_tx_0_INTR	((uint16)((uint16)0x0003u << (uartUser_tx__0__SHIFT*2u)))

#define uartUser_tx_INTR_ALL	 ((uint16)(uartUser_tx_0_INTR))


#endif /* End Pins uartUser_tx_ALIASES_H */


/* [] END OF FILE */
