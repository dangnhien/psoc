/*******************************************************************************
* File Name: ledRedd.h  
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

#if !defined(CY_PINS_ledRedd_ALIASES_H) /* Pins ledRedd_ALIASES_H */
#define CY_PINS_ledRedd_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define ledRedd_0			(ledRedd__0__PC)
#define ledRedd_0_PS		(ledRedd__0__PS)
#define ledRedd_0_PC		(ledRedd__0__PC)
#define ledRedd_0_DR		(ledRedd__0__DR)
#define ledRedd_0_SHIFT	(ledRedd__0__SHIFT)
#define ledRedd_0_INTR	((uint16)((uint16)0x0003u << (ledRedd__0__SHIFT*2u)))

#define ledRedd_INTR_ALL	 ((uint16)(ledRedd_0_INTR))


#endif /* End Pins ledRedd_ALIASES_H */


/* [] END OF FILE */
