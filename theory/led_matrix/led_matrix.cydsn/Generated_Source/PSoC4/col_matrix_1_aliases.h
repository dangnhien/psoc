/*******************************************************************************
* File Name: col_matrix_1.h  
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

#if !defined(CY_PINS_col_matrix_1_ALIASES_H) /* Pins col_matrix_1_ALIASES_H */
#define CY_PINS_col_matrix_1_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define col_matrix_1_0			(col_matrix_1__0__PC)
#define col_matrix_1_0_PS		(col_matrix_1__0__PS)
#define col_matrix_1_0_PC		(col_matrix_1__0__PC)
#define col_matrix_1_0_DR		(col_matrix_1__0__DR)
#define col_matrix_1_0_SHIFT	(col_matrix_1__0__SHIFT)
#define col_matrix_1_0_INTR	((uint16)((uint16)0x0003u << (col_matrix_1__0__SHIFT*2u)))

#define col_matrix_1_INTR_ALL	 ((uint16)(col_matrix_1_0_INTR))


#endif /* End Pins col_matrix_1_ALIASES_H */


/* [] END OF FILE */
