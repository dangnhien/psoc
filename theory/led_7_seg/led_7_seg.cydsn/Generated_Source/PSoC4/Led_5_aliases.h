/*******************************************************************************
* File Name: Led_5.h  
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

#if !defined(CY_PINS_Led_5_ALIASES_H) /* Pins Led_5_ALIASES_H */
#define CY_PINS_Led_5_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Led_5_0			(Led_5__0__PC)
#define Led_5_0_PS		(Led_5__0__PS)
#define Led_5_0_PC		(Led_5__0__PC)
#define Led_5_0_DR		(Led_5__0__DR)
#define Led_5_0_SHIFT	(Led_5__0__SHIFT)
#define Led_5_0_INTR	((uint16)((uint16)0x0003u << (Led_5__0__SHIFT*2u)))

#define Led_5_INTR_ALL	 ((uint16)(Led_5_0_INTR))


#endif /* End Pins Led_5_ALIASES_H */


/* [] END OF FILE */
