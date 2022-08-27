;
; File Name: cyfitterrv.inc
; 
; PSoC Creator  4.4
;
; Description:
; 
;
;-------------------------------------------------------------------------------
; Copyright (c) 2007-2020 Cypress Semiconductor.  All rights reserved.
; You may use this file only in accordance with the license, terms, conditions, 
; disclaimers, and limitations in the end user license agreement accompanying 
; the software package with which this file was provided.
;-------------------------------------------------------------------------------

    IF :LNOT::DEF:INCLUDED_CYFITTERRV_INC
INCLUDED_CYFITTERRV_INC EQU 1
    GET cydevicerv_trm.inc

; PWM
PWM_cy_m0s8_tcpwm_1__CC EQU CYREG_TCPWM_CNT0_CC
PWM_cy_m0s8_tcpwm_1__CC_BUFF EQU CYREG_TCPWM_CNT0_CC_BUFF
PWM_cy_m0s8_tcpwm_1__COUNTER EQU CYREG_TCPWM_CNT0_COUNTER
PWM_cy_m0s8_tcpwm_1__CTRL EQU CYREG_TCPWM_CNT0_CTRL
PWM_cy_m0s8_tcpwm_1__INTR EQU CYREG_TCPWM_CNT0_INTR
PWM_cy_m0s8_tcpwm_1__INTR_MASK EQU CYREG_TCPWM_CNT0_INTR_MASK
PWM_cy_m0s8_tcpwm_1__INTR_MASKED EQU CYREG_TCPWM_CNT0_INTR_MASKED
PWM_cy_m0s8_tcpwm_1__INTR_SET EQU CYREG_TCPWM_CNT0_INTR_SET
PWM_cy_m0s8_tcpwm_1__PERIOD EQU CYREG_TCPWM_CNT0_PERIOD
PWM_cy_m0s8_tcpwm_1__PERIOD_BUFF EQU CYREG_TCPWM_CNT0_PERIOD_BUFF
PWM_cy_m0s8_tcpwm_1__STATUS EQU CYREG_TCPWM_CNT0_STATUS
PWM_cy_m0s8_tcpwm_1__TCPWM_CMD EQU CYREG_TCPWM_CMD
PWM_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_MASK EQU 0x01
PWM_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_SHIFT EQU 0
PWM_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_MASK EQU 0x100
PWM_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_SHIFT EQU 8
PWM_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_MASK EQU 0x1000000
PWM_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_SHIFT EQU 24
PWM_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_MASK EQU 0x10000
PWM_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_SHIFT EQU 16
PWM_cy_m0s8_tcpwm_1__TCPWM_CTRL EQU CYREG_TCPWM_CTRL
PWM_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK EQU 0x01
PWM_cy_m0s8_tcpwm_1__TCPWM_CTRL_SHIFT EQU 0
PWM_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE EQU CYREG_TCPWM_INTR_CAUSE
PWM_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_MASK EQU 0x01
PWM_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_SHIFT EQU 0
PWM_cy_m0s8_tcpwm_1__TCPWM_NUMBER EQU 0
PWM_cy_m0s8_tcpwm_1__TR_CTRL0 EQU CYREG_TCPWM_CNT0_TR_CTRL0
PWM_cy_m0s8_tcpwm_1__TR_CTRL1 EQU CYREG_TCPWM_CNT0_TR_CTRL1
PWM_cy_m0s8_tcpwm_1__TR_CTRL2 EQU CYREG_TCPWM_CNT0_TR_CTRL2

; Timer
Timer_cy_m0s8_tcpwm_1__CC EQU CYREG_TCPWM_CNT1_CC
Timer_cy_m0s8_tcpwm_1__CC_BUFF EQU CYREG_TCPWM_CNT1_CC_BUFF
Timer_cy_m0s8_tcpwm_1__COUNTER EQU CYREG_TCPWM_CNT1_COUNTER
Timer_cy_m0s8_tcpwm_1__CTRL EQU CYREG_TCPWM_CNT1_CTRL
Timer_cy_m0s8_tcpwm_1__INTR EQU CYREG_TCPWM_CNT1_INTR
Timer_cy_m0s8_tcpwm_1__INTR_MASK EQU CYREG_TCPWM_CNT1_INTR_MASK
Timer_cy_m0s8_tcpwm_1__INTR_MASKED EQU CYREG_TCPWM_CNT1_INTR_MASKED
Timer_cy_m0s8_tcpwm_1__INTR_SET EQU CYREG_TCPWM_CNT1_INTR_SET
Timer_cy_m0s8_tcpwm_1__PERIOD EQU CYREG_TCPWM_CNT1_PERIOD
Timer_cy_m0s8_tcpwm_1__PERIOD_BUFF EQU CYREG_TCPWM_CNT1_PERIOD_BUFF
Timer_cy_m0s8_tcpwm_1__STATUS EQU CYREG_TCPWM_CNT1_STATUS
Timer_cy_m0s8_tcpwm_1__TCPWM_CMD EQU CYREG_TCPWM_CMD
Timer_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_MASK EQU 0x02
Timer_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_SHIFT EQU 1
Timer_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_MASK EQU 0x200
Timer_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_SHIFT EQU 9
Timer_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_MASK EQU 0x2000000
Timer_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_SHIFT EQU 25
Timer_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_MASK EQU 0x20000
Timer_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_SHIFT EQU 17
Timer_cy_m0s8_tcpwm_1__TCPWM_CTRL EQU CYREG_TCPWM_CTRL
Timer_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK EQU 0x02
Timer_cy_m0s8_tcpwm_1__TCPWM_CTRL_SHIFT EQU 1
Timer_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE EQU CYREG_TCPWM_INTR_CAUSE
Timer_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_MASK EQU 0x02
Timer_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_SHIFT EQU 1
Timer_cy_m0s8_tcpwm_1__TCPWM_NUMBER EQU 1
Timer_cy_m0s8_tcpwm_1__TR_CTRL0 EQU CYREG_TCPWM_CNT1_TR_CTRL0
Timer_cy_m0s8_tcpwm_1__TR_CTRL1 EQU CYREG_TCPWM_CNT1_TR_CTRL1
Timer_cy_m0s8_tcpwm_1__TR_CTRL2 EQU CYREG_TCPWM_CNT1_TR_CTRL2
Timer_Int__INTC_CLR_EN_REG EQU CYREG_CM0_ICER
Timer_Int__INTC_CLR_PD_REG EQU CYREG_CM0_ICPR
Timer_Int__INTC_MASK EQU 0x20000
Timer_Int__INTC_NUMBER EQU 17
Timer_Int__INTC_PRIOR_MASK EQU 0xC000
Timer_Int__INTC_PRIOR_NUM EQU 3
Timer_Int__INTC_PRIOR_REG EQU CYREG_CM0_IPR4
Timer_Int__INTC_SET_EN_REG EQU CYREG_CM0_ISER
Timer_Int__INTC_SET_PD_REG EQU CYREG_CM0_ISPR

; Clock_1
Clock_1__DIVIDER_MASK EQU 0x0000FFFF
Clock_1__ENABLE EQU CYREG_CLK_DIVIDER_A00
Clock_1__ENABLE_MASK EQU 0x80000000
Clock_1__MASK EQU 0x80000000
Clock_1__REGISTER EQU CYREG_CLK_DIVIDER_A00

; Clock_2
Clock_2__DIVIDER_MASK EQU 0x0000FFFF
Clock_2__ENABLE EQU CYREG_CLK_DIVIDER_B00
Clock_2__ENABLE_MASK EQU 0x80000000
Clock_2__MASK EQU 0x80000000
Clock_2__REGISTER EQU CYREG_CLK_DIVIDER_B00

; Pin_Button
Pin_Button__0__DM__MASK EQU 0x07
Pin_Button__0__DM__SHIFT EQU 0
Pin_Button__0__DR EQU CYREG_PRT0_DR
Pin_Button__0__HSIOM EQU CYREG_HSIOM_PORT_SEL0
Pin_Button__0__HSIOM_MASK EQU 0x0000000F
Pin_Button__0__HSIOM_SHIFT EQU 0
Pin_Button__0__INTCFG EQU CYREG_PRT0_INTCFG
Pin_Button__0__INTSTAT EQU CYREG_PRT0_INTSTAT
Pin_Button__0__MASK EQU 0x01
Pin_Button__0__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
Pin_Button__0__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
Pin_Button__0__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
Pin_Button__0__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
Pin_Button__0__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
Pin_Button__0__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
Pin_Button__0__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
Pin_Button__0__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
Pin_Button__0__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
Pin_Button__0__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
Pin_Button__0__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
Pin_Button__0__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
Pin_Button__0__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
Pin_Button__0__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
Pin_Button__0__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
Pin_Button__0__PC EQU CYREG_PRT0_PC
Pin_Button__0__PC2 EQU CYREG_PRT0_PC2
Pin_Button__0__PORT EQU 0
Pin_Button__0__PS EQU CYREG_PRT0_PS
Pin_Button__0__SHIFT EQU 0
Pin_Button__DR EQU CYREG_PRT0_DR
Pin_Button__INTCFG EQU CYREG_PRT0_INTCFG
Pin_Button__INTSTAT EQU CYREG_PRT0_INTSTAT
Pin_Button__MASK EQU 0x01
Pin_Button__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
Pin_Button__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
Pin_Button__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
Pin_Button__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
Pin_Button__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
Pin_Button__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
Pin_Button__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
Pin_Button__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
Pin_Button__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
Pin_Button__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
Pin_Button__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
Pin_Button__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
Pin_Button__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
Pin_Button__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
Pin_Button__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
Pin_Button__PC EQU CYREG_PRT0_PC
Pin_Button__PC2 EQU CYREG_PRT0_PC2
Pin_Button__PORT EQU 0
Pin_Button__PS EQU CYREG_PRT0_PS
Pin_Button__SHIFT EQU 0

; Pin_LedRed
Pin_LedRed__0__DM__MASK EQU 0x7000
Pin_LedRed__0__DM__SHIFT EQU 12
Pin_LedRed__0__DR EQU CYREG_PRT2_DR
Pin_LedRed__0__HSIOM EQU CYREG_HSIOM_PORT_SEL2
Pin_LedRed__0__HSIOM_MASK EQU 0x000F0000
Pin_LedRed__0__HSIOM_SHIFT EQU 16
Pin_LedRed__0__INTCFG EQU CYREG_PRT2_INTCFG
Pin_LedRed__0__INTSTAT EQU CYREG_PRT2_INTSTAT
Pin_LedRed__0__MASK EQU 0x10
Pin_LedRed__0__OUT_SEL EQU CYREG_UDB_PA2_CFG10
Pin_LedRed__0__OUT_SEL_SHIFT EQU 8
Pin_LedRed__0__OUT_SEL_VAL EQU -1
Pin_LedRed__0__PA__CFG0 EQU CYREG_UDB_PA2_CFG0
Pin_LedRed__0__PA__CFG1 EQU CYREG_UDB_PA2_CFG1
Pin_LedRed__0__PA__CFG10 EQU CYREG_UDB_PA2_CFG10
Pin_LedRed__0__PA__CFG11 EQU CYREG_UDB_PA2_CFG11
Pin_LedRed__0__PA__CFG12 EQU CYREG_UDB_PA2_CFG12
Pin_LedRed__0__PA__CFG13 EQU CYREG_UDB_PA2_CFG13
Pin_LedRed__0__PA__CFG14 EQU CYREG_UDB_PA2_CFG14
Pin_LedRed__0__PA__CFG2 EQU CYREG_UDB_PA2_CFG2
Pin_LedRed__0__PA__CFG3 EQU CYREG_UDB_PA2_CFG3
Pin_LedRed__0__PA__CFG4 EQU CYREG_UDB_PA2_CFG4
Pin_LedRed__0__PA__CFG5 EQU CYREG_UDB_PA2_CFG5
Pin_LedRed__0__PA__CFG6 EQU CYREG_UDB_PA2_CFG6
Pin_LedRed__0__PA__CFG7 EQU CYREG_UDB_PA2_CFG7
Pin_LedRed__0__PA__CFG8 EQU CYREG_UDB_PA2_CFG8
Pin_LedRed__0__PA__CFG9 EQU CYREG_UDB_PA2_CFG9
Pin_LedRed__0__PC EQU CYREG_PRT2_PC
Pin_LedRed__0__PC2 EQU CYREG_PRT2_PC2
Pin_LedRed__0__PORT EQU 2
Pin_LedRed__0__PS EQU CYREG_PRT2_PS
Pin_LedRed__0__SHIFT EQU 4
Pin_LedRed__DR EQU CYREG_PRT2_DR
Pin_LedRed__INTCFG EQU CYREG_PRT2_INTCFG
Pin_LedRed__INTSTAT EQU CYREG_PRT2_INTSTAT
Pin_LedRed__MASK EQU 0x10
Pin_LedRed__PA__CFG0 EQU CYREG_UDB_PA2_CFG0
Pin_LedRed__PA__CFG1 EQU CYREG_UDB_PA2_CFG1
Pin_LedRed__PA__CFG10 EQU CYREG_UDB_PA2_CFG10
Pin_LedRed__PA__CFG11 EQU CYREG_UDB_PA2_CFG11
Pin_LedRed__PA__CFG12 EQU CYREG_UDB_PA2_CFG12
Pin_LedRed__PA__CFG13 EQU CYREG_UDB_PA2_CFG13
Pin_LedRed__PA__CFG14 EQU CYREG_UDB_PA2_CFG14
Pin_LedRed__PA__CFG2 EQU CYREG_UDB_PA2_CFG2
Pin_LedRed__PA__CFG3 EQU CYREG_UDB_PA2_CFG3
Pin_LedRed__PA__CFG4 EQU CYREG_UDB_PA2_CFG4
Pin_LedRed__PA__CFG5 EQU CYREG_UDB_PA2_CFG5
Pin_LedRed__PA__CFG6 EQU CYREG_UDB_PA2_CFG6
Pin_LedRed__PA__CFG7 EQU CYREG_UDB_PA2_CFG7
Pin_LedRed__PA__CFG8 EQU CYREG_UDB_PA2_CFG8
Pin_LedRed__PA__CFG9 EQU CYREG_UDB_PA2_CFG9
Pin_LedRed__PC EQU CYREG_PRT2_PC
Pin_LedRed__PC2 EQU CYREG_PRT2_PC2
Pin_LedRed__PORT EQU 2
Pin_LedRed__PS EQU CYREG_PRT2_PS
Pin_LedRed__SHIFT EQU 4

; Miscellaneous
CYDEV_BCLK__HFCLK__HZ EQU 24000000
CYDEV_BCLK__HFCLK__KHZ EQU 24000
CYDEV_BCLK__HFCLK__MHZ EQU 24
CYDEV_BCLK__SYSCLK__HZ EQU 24000000
CYDEV_BCLK__SYSCLK__KHZ EQU 24000
CYDEV_BCLK__SYSCLK__MHZ EQU 24
CYDEV_CHIP_DIE_LEOPARD EQU 1
CYDEV_CHIP_DIE_PSOC4A EQU 26
CYDEV_CHIP_DIE_PSOC5LP EQU 2
CYDEV_CHIP_DIE_PSOC5TM EQU 3
CYDEV_CHIP_DIE_TMA4 EQU 4
CYDEV_CHIP_DIE_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_FM0P EQU 5
CYDEV_CHIP_FAMILY_FM3 EQU 6
CYDEV_CHIP_FAMILY_FM4 EQU 7
CYDEV_CHIP_FAMILY_PSOC3 EQU 1
CYDEV_CHIP_FAMILY_PSOC4 EQU 2
CYDEV_CHIP_FAMILY_PSOC5 EQU 3
CYDEV_CHIP_FAMILY_PSOC6 EQU 4
CYDEV_CHIP_FAMILY_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_USED EQU CYDEV_CHIP_FAMILY_PSOC4
CYDEV_CHIP_JTAG_ID EQU 0x04161193
CYDEV_CHIP_MEMBER_3A EQU 1
CYDEV_CHIP_MEMBER_4A EQU 26
CYDEV_CHIP_MEMBER_4AA EQU 25
CYDEV_CHIP_MEMBER_4AB EQU 30
CYDEV_CHIP_MEMBER_4AC EQU 14
CYDEV_CHIP_MEMBER_4AD EQU 15
CYDEV_CHIP_MEMBER_4AE EQU 16
CYDEV_CHIP_MEMBER_4D EQU 20
CYDEV_CHIP_MEMBER_4E EQU 6
CYDEV_CHIP_MEMBER_4F EQU 27
CYDEV_CHIP_MEMBER_4G EQU 4
CYDEV_CHIP_MEMBER_4H EQU 24
CYDEV_CHIP_MEMBER_4I EQU 32
CYDEV_CHIP_MEMBER_4J EQU 21
CYDEV_CHIP_MEMBER_4K EQU 22
CYDEV_CHIP_MEMBER_4L EQU 31
CYDEV_CHIP_MEMBER_4M EQU 29
CYDEV_CHIP_MEMBER_4N EQU 11
CYDEV_CHIP_MEMBER_4O EQU 8
CYDEV_CHIP_MEMBER_4P EQU 28
CYDEV_CHIP_MEMBER_4Q EQU 17
CYDEV_CHIP_MEMBER_4R EQU 9
CYDEV_CHIP_MEMBER_4S EQU 12
CYDEV_CHIP_MEMBER_4T EQU 10
CYDEV_CHIP_MEMBER_4U EQU 5
CYDEV_CHIP_MEMBER_4V EQU 23
CYDEV_CHIP_MEMBER_4W EQU 13
CYDEV_CHIP_MEMBER_4X EQU 7
CYDEV_CHIP_MEMBER_4Y EQU 18
CYDEV_CHIP_MEMBER_4Z EQU 19
CYDEV_CHIP_MEMBER_5A EQU 3
CYDEV_CHIP_MEMBER_5B EQU 2
CYDEV_CHIP_MEMBER_6A EQU 33
CYDEV_CHIP_MEMBER_FM3 EQU 37
CYDEV_CHIP_MEMBER_FM4 EQU 38
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 EQU 34
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 EQU 35
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 EQU 36
CYDEV_CHIP_MEMBER_UNKNOWN EQU 0
CYDEV_CHIP_MEMBER_USED EQU CYDEV_CHIP_MEMBER_4A
CYDEV_CHIP_DIE_EXPECT EQU CYDEV_CHIP_MEMBER_USED
CYDEV_CHIP_DIE_ACTUAL EQU CYDEV_CHIP_DIE_EXPECT
CYDEV_CHIP_REV_LEOPARD_ES1 EQU 0
CYDEV_CHIP_REV_LEOPARD_ES2 EQU 1
CYDEV_CHIP_REV_LEOPARD_ES3 EQU 3
CYDEV_CHIP_REV_LEOPARD_PRODUCTION EQU 3
CYDEV_CHIP_REV_PSOC4A_ES0 EQU 17
CYDEV_CHIP_REV_PSOC4A_PRODUCTION EQU 17
CYDEV_CHIP_REV_PSOC5LP_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5LP_PRODUCTION EQU 0
CYDEV_CHIP_REV_PSOC5TM_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5TM_ES1 EQU 1
CYDEV_CHIP_REV_PSOC5TM_PRODUCTION EQU 1
CYDEV_CHIP_REV_TMA4_ES EQU 17
CYDEV_CHIP_REV_TMA4_ES2 EQU 33
CYDEV_CHIP_REV_TMA4_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_3A_ES1 EQU 0
CYDEV_CHIP_REVISION_3A_ES2 EQU 1
CYDEV_CHIP_REVISION_3A_ES3 EQU 3
CYDEV_CHIP_REVISION_3A_PRODUCTION EQU 3
CYDEV_CHIP_REVISION_4A_ES0 EQU 17
CYDEV_CHIP_REVISION_4A_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4AA_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4AB_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4AC_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4AD_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4AE_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4D_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD EQU 0
CYDEV_CHIP_REVISION_4E_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256K EQU 0
CYDEV_CHIP_REVISION_4G_ES EQU 17
CYDEV_CHIP_REVISION_4G_ES2 EQU 33
CYDEV_CHIP_REVISION_4G_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4H_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4I_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4J_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4K_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4L_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4M_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4N_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4O_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4P_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4Q_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4R_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4S_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4T_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4U_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4V_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4W_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4X_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4Y_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4Z_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_5A_ES0 EQU 0
CYDEV_CHIP_REVISION_5A_ES1 EQU 1
CYDEV_CHIP_REVISION_5A_PRODUCTION EQU 1
CYDEV_CHIP_REVISION_5B_ES0 EQU 0
CYDEV_CHIP_REVISION_5B_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_6A_ES EQU 17
CYDEV_CHIP_REVISION_6A_NO_UDB EQU 33
CYDEV_CHIP_REVISION_6A_PRODUCTION EQU 33
CYDEV_CHIP_REVISION_FM3_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_FM4_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_USED EQU CYDEV_CHIP_REVISION_4A_PRODUCTION
CYDEV_CHIP_REV_EXPECT EQU CYDEV_CHIP_REVISION_USED
CYDEV_CONFIG_READ_ACCELERATOR EQU 1
CYDEV_CONFIG_UNUSED_IO_AllowButWarn EQU 0
CYDEV_CONFIG_UNUSED_IO_AllowWithInfo EQU 1
CYDEV_CONFIG_UNUSED_IO_Disallowed EQU 2
CYDEV_CONFIG_UNUSED_IO EQU CYDEV_CONFIG_UNUSED_IO_Disallowed
CYDEV_CONFIGURATION_COMPRESSED EQU 1
CYDEV_CONFIGURATION_MODE_COMPRESSED EQU 0
CYDEV_CONFIGURATION_MODE EQU CYDEV_CONFIGURATION_MODE_COMPRESSED
CYDEV_CONFIGURATION_MODE_DMA EQU 2
CYDEV_CONFIGURATION_MODE_UNCOMPRESSED EQU 1
CYDEV_DEBUG_PROTECT_KILL EQU 4
CYDEV_DEBUG_PROTECT_OPEN EQU 1
CYDEV_DEBUG_PROTECT EQU CYDEV_DEBUG_PROTECT_OPEN
CYDEV_DEBUG_PROTECT_PROTECTED EQU 2
CYDEV_DEBUGGING_DPS_Disable EQU 3
CYDEV_DEBUGGING_DPS_SWD EQU 2
CYDEV_DEBUGGING_DPS EQU CYDEV_DEBUGGING_DPS_SWD
CYDEV_DEBUGGING_ENABLE EQU 1
CYDEV_DFT_SELECT_CLK0 EQU 1
CYDEV_DFT_SELECT_CLK1 EQU 2
CYDEV_HEAP_SIZE EQU 0x80
CYDEV_IMO_TRIMMED_BY_USB EQU 0
CYDEV_IMO_TRIMMED_BY_WCO EQU 0
CYDEV_IS_EXPORTING_CODE EQU 0
CYDEV_IS_IMPORTING_CODE EQU 0
CYDEV_PROJ_TYPE EQU 0
CYDEV_PROJ_TYPE_BOOTLOADER EQU 1
CYDEV_PROJ_TYPE_LAUNCHER EQU 5
CYDEV_PROJ_TYPE_LOADABLE EQU 2
CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER EQU 4
CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER EQU 3
CYDEV_PROJ_TYPE_STANDARD EQU 0
CYDEV_STACK_SIZE EQU 0x0400
CYDEV_USE_BUNDLED_CMSIS EQU 1
CYDEV_VARIABLE_VDDA EQU 1
CYDEV_VDDA_MV EQU 3300
CYDEV_VDDD_MV EQU 3300
CYDEV_WDT_GENERATE_ISR EQU 1
CYIPBLOCK_M0S8_CTBM_VERSION EQU 0
CYIPBLOCK_m0s8cpuss_VERSION EQU 0
CYIPBLOCK_m0s8csd_VERSION EQU 0
CYIPBLOCK_m0s8gpio2_VERSION EQU 0
CYIPBLOCK_m0s8hsiom4a_VERSION EQU 0
CYIPBLOCK_m0s8lcd_VERSION EQU 0
CYIPBLOCK_m0s8lpcomp_VERSION EQU 0
CYIPBLOCK_m0s8pclk_VERSION EQU 0
CYIPBLOCK_m0s8sar_VERSION EQU 0
CYIPBLOCK_m0s8scb_VERSION EQU 0
CYIPBLOCK_m0s8srssv2_VERSION EQU 1
CYIPBLOCK_m0s8tcpwm_VERSION EQU 0
CYIPBLOCK_m0s8udbif_VERSION EQU 0
CYIPBLOCK_S8_GPIO_VERSION EQU 2
CYDEV_BOOTLOADER_ENABLE EQU 0
    ENDIF
    END