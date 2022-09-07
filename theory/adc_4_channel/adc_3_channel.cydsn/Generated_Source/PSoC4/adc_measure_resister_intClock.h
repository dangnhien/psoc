/*******************************************************************************
* File Name: adc_measure_resister_intClock.h
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

#if !defined(CY_CLOCK_adc_measure_resister_intClock_H)
#define CY_CLOCK_adc_measure_resister_intClock_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void adc_measure_resister_intClock_StartEx(uint32 alignClkDiv);
#define adc_measure_resister_intClock_Start() \
    adc_measure_resister_intClock_StartEx(adc_measure_resister_intClock__PA_DIV_ID)

#else

void adc_measure_resister_intClock_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void adc_measure_resister_intClock_Stop(void);

void adc_measure_resister_intClock_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 adc_measure_resister_intClock_GetDividerRegister(void);
uint8  adc_measure_resister_intClock_GetFractionalDividerRegister(void);

#define adc_measure_resister_intClock_Enable()                         adc_measure_resister_intClock_Start()
#define adc_measure_resister_intClock_Disable()                        adc_measure_resister_intClock_Stop()
#define adc_measure_resister_intClock_SetDividerRegister(clkDivider, reset)  \
    adc_measure_resister_intClock_SetFractionalDividerRegister((clkDivider), 0u)
#define adc_measure_resister_intClock_SetDivider(clkDivider)           adc_measure_resister_intClock_SetDividerRegister((clkDivider), 1u)
#define adc_measure_resister_intClock_SetDividerValue(clkDivider)      adc_measure_resister_intClock_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define adc_measure_resister_intClock_DIV_ID     adc_measure_resister_intClock__DIV_ID

#define adc_measure_resister_intClock_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define adc_measure_resister_intClock_CTRL_REG   (*(reg32 *)adc_measure_resister_intClock__CTRL_REGISTER)
#define adc_measure_resister_intClock_DIV_REG    (*(reg32 *)adc_measure_resister_intClock__DIV_REGISTER)

#define adc_measure_resister_intClock_CMD_DIV_SHIFT          (0u)
#define adc_measure_resister_intClock_CMD_PA_DIV_SHIFT       (8u)
#define adc_measure_resister_intClock_CMD_DISABLE_SHIFT      (30u)
#define adc_measure_resister_intClock_CMD_ENABLE_SHIFT       (31u)

#define adc_measure_resister_intClock_CMD_DISABLE_MASK       ((uint32)((uint32)1u << adc_measure_resister_intClock_CMD_DISABLE_SHIFT))
#define adc_measure_resister_intClock_CMD_ENABLE_MASK        ((uint32)((uint32)1u << adc_measure_resister_intClock_CMD_ENABLE_SHIFT))

#define adc_measure_resister_intClock_DIV_FRAC_MASK  (0x000000F8u)
#define adc_measure_resister_intClock_DIV_FRAC_SHIFT (3u)
#define adc_measure_resister_intClock_DIV_INT_MASK   (0xFFFFFF00u)
#define adc_measure_resister_intClock_DIV_INT_SHIFT  (8u)

#else 

#define adc_measure_resister_intClock_DIV_REG        (*(reg32 *)adc_measure_resister_intClock__REGISTER)
#define adc_measure_resister_intClock_ENABLE_REG     adc_measure_resister_intClock_DIV_REG
#define adc_measure_resister_intClock_DIV_FRAC_MASK  adc_measure_resister_intClock__FRAC_MASK
#define adc_measure_resister_intClock_DIV_FRAC_SHIFT (16u)
#define adc_measure_resister_intClock_DIV_INT_MASK   adc_measure_resister_intClock__DIVIDER_MASK
#define adc_measure_resister_intClock_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_adc_measure_resister_intClock_H) */

/* [] END OF FILE */
