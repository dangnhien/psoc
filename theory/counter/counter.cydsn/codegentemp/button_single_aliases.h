/*******************************************************************************
* File Name: button_single.h  
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

#if !defined(CY_PINS_button_single_ALIASES_H) /* Pins button_single_ALIASES_H */
#define CY_PINS_button_single_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define button_single_0			(button_single__0__PC)
#define button_single_0_PS		(button_single__0__PS)
#define button_single_0_PC		(button_single__0__PC)
#define button_single_0_DR		(button_single__0__DR)
#define button_single_0_SHIFT	(button_single__0__SHIFT)
#define button_single_0_INTR	((uint16)((uint16)0x0003u << (button_single__0__SHIFT*2u)))

#define button_single_INTR_ALL	 ((uint16)(button_single_0_INTR))


#endif /* End Pins button_single_ALIASES_H */


/* [] END OF FILE */
