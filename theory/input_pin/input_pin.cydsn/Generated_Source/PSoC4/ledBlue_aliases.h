/*******************************************************************************
* File Name: ledBlue.h  
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

#if !defined(CY_PINS_ledBlue_ALIASES_H) /* Pins ledBlue_ALIASES_H */
#define CY_PINS_ledBlue_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define ledBlue_0			(ledBlue__0__PC)
#define ledBlue_0_PS		(ledBlue__0__PS)
#define ledBlue_0_PC		(ledBlue__0__PC)
#define ledBlue_0_DR		(ledBlue__0__DR)
#define ledBlue_0_SHIFT	(ledBlue__0__SHIFT)
#define ledBlue_0_INTR	((uint16)((uint16)0x0003u << (ledBlue__0__SHIFT*2u)))

#define ledBlue_INTR_ALL	 ((uint16)(ledBlue_0_INTR))


#endif /* End Pins ledBlue_ALIASES_H */


/* [] END OF FILE */
