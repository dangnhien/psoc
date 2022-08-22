/*******************************************************************************
* File Name: ledYellow.h  
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

#if !defined(CY_PINS_ledYellow_ALIASES_H) /* Pins ledYellow_ALIASES_H */
#define CY_PINS_ledYellow_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define ledYellow_0			(ledYellow__0__PC)
#define ledYellow_0_PS		(ledYellow__0__PS)
#define ledYellow_0_PC		(ledYellow__0__PC)
#define ledYellow_0_DR		(ledYellow__0__DR)
#define ledYellow_0_SHIFT	(ledYellow__0__SHIFT)
#define ledYellow_0_INTR	((uint16)((uint16)0x0003u << (ledYellow__0__SHIFT*2u)))

#define ledYellow_INTR_ALL	 ((uint16)(ledYellow_0_INTR))


#endif /* End Pins ledYellow_ALIASES_H */


/* [] END OF FILE */
