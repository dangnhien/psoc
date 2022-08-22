/*******************************************************************************
* File Name: uartUser_SCBCLK.h
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

#if !defined(CY_CLOCK_uartUser_SCBCLK_H)
#define CY_CLOCK_uartUser_SCBCLK_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void uartUser_SCBCLK_StartEx(uint32 alignClkDiv);
#define uartUser_SCBCLK_Start() \
    uartUser_SCBCLK_StartEx(uartUser_SCBCLK__PA_DIV_ID)

#else

void uartUser_SCBCLK_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void uartUser_SCBCLK_Stop(void);

void uartUser_SCBCLK_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 uartUser_SCBCLK_GetDividerRegister(void);
uint8  uartUser_SCBCLK_GetFractionalDividerRegister(void);

#define uartUser_SCBCLK_Enable()                         uartUser_SCBCLK_Start()
#define uartUser_SCBCLK_Disable()                        uartUser_SCBCLK_Stop()
#define uartUser_SCBCLK_SetDividerRegister(clkDivider, reset)  \
    uartUser_SCBCLK_SetFractionalDividerRegister((clkDivider), 0u)
#define uartUser_SCBCLK_SetDivider(clkDivider)           uartUser_SCBCLK_SetDividerRegister((clkDivider), 1u)
#define uartUser_SCBCLK_SetDividerValue(clkDivider)      uartUser_SCBCLK_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define uartUser_SCBCLK_DIV_ID     uartUser_SCBCLK__DIV_ID

#define uartUser_SCBCLK_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define uartUser_SCBCLK_CTRL_REG   (*(reg32 *)uartUser_SCBCLK__CTRL_REGISTER)
#define uartUser_SCBCLK_DIV_REG    (*(reg32 *)uartUser_SCBCLK__DIV_REGISTER)

#define uartUser_SCBCLK_CMD_DIV_SHIFT          (0u)
#define uartUser_SCBCLK_CMD_PA_DIV_SHIFT       (8u)
#define uartUser_SCBCLK_CMD_DISABLE_SHIFT      (30u)
#define uartUser_SCBCLK_CMD_ENABLE_SHIFT       (31u)

#define uartUser_SCBCLK_CMD_DISABLE_MASK       ((uint32)((uint32)1u << uartUser_SCBCLK_CMD_DISABLE_SHIFT))
#define uartUser_SCBCLK_CMD_ENABLE_MASK        ((uint32)((uint32)1u << uartUser_SCBCLK_CMD_ENABLE_SHIFT))

#define uartUser_SCBCLK_DIV_FRAC_MASK  (0x000000F8u)
#define uartUser_SCBCLK_DIV_FRAC_SHIFT (3u)
#define uartUser_SCBCLK_DIV_INT_MASK   (0xFFFFFF00u)
#define uartUser_SCBCLK_DIV_INT_SHIFT  (8u)

#else 

#define uartUser_SCBCLK_DIV_REG        (*(reg32 *)uartUser_SCBCLK__REGISTER)
#define uartUser_SCBCLK_ENABLE_REG     uartUser_SCBCLK_DIV_REG
#define uartUser_SCBCLK_DIV_FRAC_MASK  uartUser_SCBCLK__FRAC_MASK
#define uartUser_SCBCLK_DIV_FRAC_SHIFT (16u)
#define uartUser_SCBCLK_DIV_INT_MASK   uartUser_SCBCLK__DIVIDER_MASK
#define uartUser_SCBCLK_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_uartUser_SCBCLK_H) */

/* [] END OF FILE */
