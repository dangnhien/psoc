/*******************************************************************************
* File Name: led_orange.h  
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

#if !defined(CY_PINS_led_orange_ALIASES_H) /* Pins led_orange_ALIASES_H */
#define CY_PINS_led_orange_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define led_orange_0			(led_orange__0__PC)
#define led_orange_0_PS		(led_orange__0__PS)
#define led_orange_0_PC		(led_orange__0__PC)
#define led_orange_0_DR		(led_orange__0__DR)
#define led_orange_0_SHIFT	(led_orange__0__SHIFT)
#define led_orange_0_INTR	((uint16)((uint16)0x0003u << (led_orange__0__SHIFT*2u)))

#define led_orange_INTR_ALL	 ((uint16)(led_orange_0_INTR))


#endif /* End Pins led_orange_ALIASES_H */


/* [] END OF FILE */
