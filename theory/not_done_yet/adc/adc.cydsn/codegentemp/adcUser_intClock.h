/*******************************************************************************
* File Name: adcUser_intClock.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_adcUser_intClock_H)
#define CY_CLOCK_adcUser_intClock_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void adcUser_intClock_StartEx(uint32 alignClkDiv);
#define adcUser_intClock_Start() \
    adcUser_intClock_StartEx(adcUser_intClock__PA_DIV_ID)

#else

void adcUser_intClock_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void adcUser_intClock_Stop(void);

void adcUser_intClock_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 adcUser_intClock_GetDividerRegister(void);
uint8  adcUser_intClock_GetFractionalDividerRegister(void);

#define adcUser_intClock_Enable()                         adcUser_intClock_Start()
#define adcUser_intClock_Disable()                        adcUser_intClock_Stop()
#define adcUser_intClock_SetDividerRegister(clkDivider, reset)  \
    adcUser_intClock_SetFractionalDividerRegister((clkDivider), 0u)
#define adcUser_intClock_SetDivider(clkDivider)           adcUser_intClock_SetDividerRegister((clkDivider), 1u)
#define adcUser_intClock_SetDividerValue(clkDivider)      adcUser_intClock_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define adcUser_intClock_DIV_ID     adcUser_intClock__DIV_ID

#define adcUser_intClock_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define adcUser_intClock_CTRL_REG   (*(reg32 *)adcUser_intClock__CTRL_REGISTER)
#define adcUser_intClock_DIV_REG    (*(reg32 *)adcUser_intClock__DIV_REGISTER)

#define adcUser_intClock_CMD_DIV_SHIFT          (0u)
#define adcUser_intClock_CMD_PA_DIV_SHIFT       (8u)
#define adcUser_intClock_CMD_DISABLE_SHIFT      (30u)
#define adcUser_intClock_CMD_ENABLE_SHIFT       (31u)

#define adcUser_intClock_CMD_DISABLE_MASK       ((uint32)((uint32)1u << adcUser_intClock_CMD_DISABLE_SHIFT))
#define adcUser_intClock_CMD_ENABLE_MASK        ((uint32)((uint32)1u << adcUser_intClock_CMD_ENABLE_SHIFT))

#define adcUser_intClock_DIV_FRAC_MASK  (0x000000F8u)
#define adcUser_intClock_DIV_FRAC_SHIFT (3u)
#define adcUser_intClock_DIV_INT_MASK   (0xFFFFFF00u)
#define adcUser_intClock_DIV_INT_SHIFT  (8u)

#else 

#define adcUser_intClock_DIV_REG        (*(reg32 *)adcUser_intClock__REGISTER)
#define adcUser_intClock_ENABLE_REG     adcUser_intClock_DIV_REG
#define adcUser_intClock_DIV_FRAC_MASK  adcUser_intClock__FRAC_MASK
#define adcUser_intClock_DIV_FRAC_SHIFT (16u)
#define adcUser_intClock_DIV_INT_MASK   adcUser_intClock__DIVIDER_MASK
#define adcUser_intClock_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_adcUser_intClock_H) */

/* [] END OF FILE */
