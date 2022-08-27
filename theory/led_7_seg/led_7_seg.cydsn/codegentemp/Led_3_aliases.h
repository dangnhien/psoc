/*******************************************************************************
* File Name: Led_3.h  
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

#if !defined(CY_PINS_Led_3_ALIASES_H) /* Pins Led_3_ALIASES_H */
#define CY_PINS_Led_3_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Led_3_0			(Led_3__0__PC)
#define Led_3_0_PS		(Led_3__0__PS)
#define Led_3_0_PC		(Led_3__0__PC)
#define Led_3_0_DR		(Led_3__0__DR)
#define Led_3_0_SHIFT	(Led_3__0__SHIFT)
#define Led_3_0_INTR	((uint16)((uint16)0x0003u << (Led_3__0__SHIFT*2u)))

#define Led_3_INTR_ALL	 ((uint16)(Led_3_0_INTR))


#endif /* End Pins Led_3_ALIASES_H */


/* [] END OF FILE */
