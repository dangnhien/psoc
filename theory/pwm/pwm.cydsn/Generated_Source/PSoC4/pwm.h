/*******************************************************************************
* File Name: pwm.h
* Version 2.10
*
* Description:
*  This file provides constants and parameter values for the pwm
*  component.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_TCPWM_pwm_H)
#define CY_TCPWM_pwm_H


#include "CyLib.h"
#include "cytypes.h"
#include "cyfitter.h"


/*******************************************************************************
* Internal Type defines
*******************************************************************************/

/* Structure to save state before go to sleep */
typedef struct
{
    uint8  enableState;
} pwm_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  pwm_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define pwm_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define pwm_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define pwm_CONFIG                         (7lu)

/* Quad Mode */
/* Parameters */
#define pwm_QUAD_ENCODING_MODES            (0lu)
#define pwm_QUAD_AUTO_START                (1lu)

/* Signal modes */
#define pwm_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define pwm_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define pwm_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define pwm_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define pwm_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define pwm_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define pwm_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define pwm_TC_RUN_MODE                    (0lu)
#define pwm_TC_COUNTER_MODE                (0lu)
#define pwm_TC_COMP_CAP_MODE               (2lu)
#define pwm_TC_PRESCALER                   (0lu)

/* Signal modes */
#define pwm_TC_RELOAD_SIGNAL_MODE          (0lu)
#define pwm_TC_COUNT_SIGNAL_MODE           (3lu)
#define pwm_TC_START_SIGNAL_MODE           (0lu)
#define pwm_TC_STOP_SIGNAL_MODE            (0lu)
#define pwm_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define pwm_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define pwm_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define pwm_TC_START_SIGNAL_PRESENT        (0lu)
#define pwm_TC_STOP_SIGNAL_PRESENT         (0lu)
#define pwm_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define pwm_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define pwm_PWM_KILL_EVENT                 (0lu)
#define pwm_PWM_STOP_EVENT                 (0lu)
#define pwm_PWM_MODE                       (4lu)
#define pwm_PWM_OUT_N_INVERT               (0lu)
#define pwm_PWM_OUT_INVERT                 (0lu)
#define pwm_PWM_ALIGN                      (0lu)
#define pwm_PWM_RUN_MODE                   (0lu)
#define pwm_PWM_DEAD_TIME_CYCLE            (0lu)
#define pwm_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define pwm_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define pwm_PWM_COUNT_SIGNAL_MODE          (3lu)
#define pwm_PWM_START_SIGNAL_MODE          (0lu)
#define pwm_PWM_STOP_SIGNAL_MODE           (0lu)
#define pwm_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define pwm_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define pwm_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define pwm_PWM_START_SIGNAL_PRESENT       (0lu)
#define pwm_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define pwm_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define pwm_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define pwm_TC_PERIOD_VALUE                (65535lu)
#define pwm_TC_COMPARE_VALUE               (65535lu)
#define pwm_TC_COMPARE_BUF_VALUE           (65535lu)
#define pwm_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define pwm_PWM_PERIOD_VALUE               (20000lu)
#define pwm_PWM_PERIOD_BUF_VALUE           (65535lu)
#define pwm_PWM_PERIOD_SWAP                (0lu)
#define pwm_PWM_COMPARE_VALUE              (1000lu)
#define pwm_PWM_COMPARE_BUF_VALUE          (65535lu)
#define pwm_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define pwm__LEFT 0
#define pwm__RIGHT 1
#define pwm__CENTER 2
#define pwm__ASYMMETRIC 3

#define pwm__X1 0
#define pwm__X2 1
#define pwm__X4 2

#define pwm__PWM 4
#define pwm__PWM_DT 5
#define pwm__PWM_PR 6

#define pwm__INVERSE 1
#define pwm__DIRECT 0

#define pwm__CAPTURE 2
#define pwm__COMPARE 0

#define pwm__TRIG_LEVEL 3
#define pwm__TRIG_RISING 0
#define pwm__TRIG_FALLING 1
#define pwm__TRIG_BOTH 2

#define pwm__INTR_MASK_TC 1
#define pwm__INTR_MASK_CC_MATCH 2
#define pwm__INTR_MASK_NONE 0
#define pwm__INTR_MASK_TC_CC 3

#define pwm__UNCONFIG 8
#define pwm__TIMER 1
#define pwm__QUAD 3
#define pwm__PWM_SEL 7

#define pwm__COUNT_UP 0
#define pwm__COUNT_DOWN 1
#define pwm__COUNT_UPDOWN0 2
#define pwm__COUNT_UPDOWN1 3


/* Prescaler */
#define pwm_PRESCALE_DIVBY1                ((uint32)(0u << pwm_PRESCALER_SHIFT))
#define pwm_PRESCALE_DIVBY2                ((uint32)(1u << pwm_PRESCALER_SHIFT))
#define pwm_PRESCALE_DIVBY4                ((uint32)(2u << pwm_PRESCALER_SHIFT))
#define pwm_PRESCALE_DIVBY8                ((uint32)(3u << pwm_PRESCALER_SHIFT))
#define pwm_PRESCALE_DIVBY16               ((uint32)(4u << pwm_PRESCALER_SHIFT))
#define pwm_PRESCALE_DIVBY32               ((uint32)(5u << pwm_PRESCALER_SHIFT))
#define pwm_PRESCALE_DIVBY64               ((uint32)(6u << pwm_PRESCALER_SHIFT))
#define pwm_PRESCALE_DIVBY128              ((uint32)(7u << pwm_PRESCALER_SHIFT))

/* TCPWM set modes */
#define pwm_MODE_TIMER_COMPARE             ((uint32)(pwm__COMPARE         <<  \
                                                                  pwm_MODE_SHIFT))
#define pwm_MODE_TIMER_CAPTURE             ((uint32)(pwm__CAPTURE         <<  \
                                                                  pwm_MODE_SHIFT))
#define pwm_MODE_QUAD                      ((uint32)(pwm__QUAD            <<  \
                                                                  pwm_MODE_SHIFT))
#define pwm_MODE_PWM                       ((uint32)(pwm__PWM             <<  \
                                                                  pwm_MODE_SHIFT))
#define pwm_MODE_PWM_DT                    ((uint32)(pwm__PWM_DT          <<  \
                                                                  pwm_MODE_SHIFT))
#define pwm_MODE_PWM_PR                    ((uint32)(pwm__PWM_PR          <<  \
                                                                  pwm_MODE_SHIFT))

/* Quad Modes */
#define pwm_MODE_X1                        ((uint32)(pwm__X1              <<  \
                                                                  pwm_QUAD_MODE_SHIFT))
#define pwm_MODE_X2                        ((uint32)(pwm__X2              <<  \
                                                                  pwm_QUAD_MODE_SHIFT))
#define pwm_MODE_X4                        ((uint32)(pwm__X4              <<  \
                                                                  pwm_QUAD_MODE_SHIFT))

/* Counter modes */
#define pwm_COUNT_UP                       ((uint32)(pwm__COUNT_UP        <<  \
                                                                  pwm_UPDOWN_SHIFT))
#define pwm_COUNT_DOWN                     ((uint32)(pwm__COUNT_DOWN      <<  \
                                                                  pwm_UPDOWN_SHIFT))
#define pwm_COUNT_UPDOWN0                  ((uint32)(pwm__COUNT_UPDOWN0   <<  \
                                                                  pwm_UPDOWN_SHIFT))
#define pwm_COUNT_UPDOWN1                  ((uint32)(pwm__COUNT_UPDOWN1   <<  \
                                                                  pwm_UPDOWN_SHIFT))

/* PWM output invert */
#define pwm_INVERT_LINE                    ((uint32)(pwm__INVERSE         <<  \
                                                                  pwm_INV_OUT_SHIFT))
#define pwm_INVERT_LINE_N                  ((uint32)(pwm__INVERSE         <<  \
                                                                  pwm_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define pwm_TRIG_RISING                    ((uint32)pwm__TRIG_RISING)
#define pwm_TRIG_FALLING                   ((uint32)pwm__TRIG_FALLING)
#define pwm_TRIG_BOTH                      ((uint32)pwm__TRIG_BOTH)
#define pwm_TRIG_LEVEL                     ((uint32)pwm__TRIG_LEVEL)

/* Interrupt mask */
#define pwm_INTR_MASK_TC                   ((uint32)pwm__INTR_MASK_TC)
#define pwm_INTR_MASK_CC_MATCH             ((uint32)pwm__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define pwm_CC_MATCH_SET                   (0x00u)
#define pwm_CC_MATCH_CLEAR                 (0x01u)
#define pwm_CC_MATCH_INVERT                (0x02u)
#define pwm_CC_MATCH_NO_CHANGE             (0x03u)
#define pwm_OVERLOW_SET                    (0x00u)
#define pwm_OVERLOW_CLEAR                  (0x04u)
#define pwm_OVERLOW_INVERT                 (0x08u)
#define pwm_OVERLOW_NO_CHANGE              (0x0Cu)
#define pwm_UNDERFLOW_SET                  (0x00u)
#define pwm_UNDERFLOW_CLEAR                (0x10u)
#define pwm_UNDERFLOW_INVERT               (0x20u)
#define pwm_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define pwm_PWM_MODE_LEFT                  (pwm_CC_MATCH_CLEAR        |   \
                                                         pwm_OVERLOW_SET           |   \
                                                         pwm_UNDERFLOW_NO_CHANGE)
#define pwm_PWM_MODE_RIGHT                 (pwm_CC_MATCH_SET          |   \
                                                         pwm_OVERLOW_NO_CHANGE     |   \
                                                         pwm_UNDERFLOW_CLEAR)
#define pwm_PWM_MODE_ASYM                  (pwm_CC_MATCH_INVERT       |   \
                                                         pwm_OVERLOW_SET           |   \
                                                         pwm_UNDERFLOW_CLEAR)

#if (pwm_CY_TCPWM_V2)
    #if(pwm_CY_TCPWM_4000)
        #define pwm_PWM_MODE_CENTER                (pwm_CC_MATCH_INVERT       |   \
                                                                 pwm_OVERLOW_NO_CHANGE     |   \
                                                                 pwm_UNDERFLOW_CLEAR)
    #else
        #define pwm_PWM_MODE_CENTER                (pwm_CC_MATCH_INVERT       |   \
                                                                 pwm_OVERLOW_SET           |   \
                                                                 pwm_UNDERFLOW_CLEAR)
    #endif /* (pwm_CY_TCPWM_4000) */
#else
    #define pwm_PWM_MODE_CENTER                (pwm_CC_MATCH_INVERT       |   \
                                                             pwm_OVERLOW_NO_CHANGE     |   \
                                                             pwm_UNDERFLOW_CLEAR)
#endif /* (pwm_CY_TCPWM_NEW) */

/* Command operations without condition */
#define pwm_CMD_CAPTURE                    (0u)
#define pwm_CMD_RELOAD                     (8u)
#define pwm_CMD_STOP                       (16u)
#define pwm_CMD_START                      (24u)

/* Status */
#define pwm_STATUS_DOWN                    (1u)
#define pwm_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   pwm_Init(void);
void   pwm_Enable(void);
void   pwm_Start(void);
void   pwm_Stop(void);

void   pwm_SetMode(uint32 mode);
void   pwm_SetCounterMode(uint32 counterMode);
void   pwm_SetPWMMode(uint32 modeMask);
void   pwm_SetQDMode(uint32 qdMode);

void   pwm_SetPrescaler(uint32 prescaler);
void   pwm_TriggerCommand(uint32 mask, uint32 command);
void   pwm_SetOneShot(uint32 oneShotEnable);
uint32 pwm_ReadStatus(void);

void   pwm_SetPWMSyncKill(uint32 syncKillEnable);
void   pwm_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   pwm_SetPWMDeadTime(uint32 deadTime);
void   pwm_SetPWMInvert(uint32 mask);

void   pwm_SetInterruptMode(uint32 interruptMask);
uint32 pwm_GetInterruptSourceMasked(void);
uint32 pwm_GetInterruptSource(void);
void   pwm_ClearInterrupt(uint32 interruptMask);
void   pwm_SetInterrupt(uint32 interruptMask);

void   pwm_WriteCounter(uint32 count);
uint32 pwm_ReadCounter(void);

uint32 pwm_ReadCapture(void);
uint32 pwm_ReadCaptureBuf(void);

void   pwm_WritePeriod(uint32 period);
uint32 pwm_ReadPeriod(void);
void   pwm_WritePeriodBuf(uint32 periodBuf);
uint32 pwm_ReadPeriodBuf(void);

void   pwm_WriteCompare(uint32 compare);
uint32 pwm_ReadCompare(void);
void   pwm_WriteCompareBuf(uint32 compareBuf);
uint32 pwm_ReadCompareBuf(void);

void   pwm_SetPeriodSwap(uint32 swapEnable);
void   pwm_SetCompareSwap(uint32 swapEnable);

void   pwm_SetCaptureMode(uint32 triggerMode);
void   pwm_SetReloadMode(uint32 triggerMode);
void   pwm_SetStartMode(uint32 triggerMode);
void   pwm_SetStopMode(uint32 triggerMode);
void   pwm_SetCountMode(uint32 triggerMode);

void   pwm_SaveConfig(void);
void   pwm_RestoreConfig(void);
void   pwm_Sleep(void);
void   pwm_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define pwm_BLOCK_CONTROL_REG              (*(reg32 *) pwm_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define pwm_BLOCK_CONTROL_PTR              ( (reg32 *) pwm_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define pwm_COMMAND_REG                    (*(reg32 *) pwm_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define pwm_COMMAND_PTR                    ( (reg32 *) pwm_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define pwm_INTRRUPT_CAUSE_REG             (*(reg32 *) pwm_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define pwm_INTRRUPT_CAUSE_PTR             ( (reg32 *) pwm_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define pwm_CONTROL_REG                    (*(reg32 *) pwm_cy_m0s8_tcpwm_1__CTRL )
#define pwm_CONTROL_PTR                    ( (reg32 *) pwm_cy_m0s8_tcpwm_1__CTRL )
#define pwm_STATUS_REG                     (*(reg32 *) pwm_cy_m0s8_tcpwm_1__STATUS )
#define pwm_STATUS_PTR                     ( (reg32 *) pwm_cy_m0s8_tcpwm_1__STATUS )
#define pwm_COUNTER_REG                    (*(reg32 *) pwm_cy_m0s8_tcpwm_1__COUNTER )
#define pwm_COUNTER_PTR                    ( (reg32 *) pwm_cy_m0s8_tcpwm_1__COUNTER )
#define pwm_COMP_CAP_REG                   (*(reg32 *) pwm_cy_m0s8_tcpwm_1__CC )
#define pwm_COMP_CAP_PTR                   ( (reg32 *) pwm_cy_m0s8_tcpwm_1__CC )
#define pwm_COMP_CAP_BUF_REG               (*(reg32 *) pwm_cy_m0s8_tcpwm_1__CC_BUFF )
#define pwm_COMP_CAP_BUF_PTR               ( (reg32 *) pwm_cy_m0s8_tcpwm_1__CC_BUFF )
#define pwm_PERIOD_REG                     (*(reg32 *) pwm_cy_m0s8_tcpwm_1__PERIOD )
#define pwm_PERIOD_PTR                     ( (reg32 *) pwm_cy_m0s8_tcpwm_1__PERIOD )
#define pwm_PERIOD_BUF_REG                 (*(reg32 *) pwm_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define pwm_PERIOD_BUF_PTR                 ( (reg32 *) pwm_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define pwm_TRIG_CONTROL0_REG              (*(reg32 *) pwm_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define pwm_TRIG_CONTROL0_PTR              ( (reg32 *) pwm_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define pwm_TRIG_CONTROL1_REG              (*(reg32 *) pwm_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define pwm_TRIG_CONTROL1_PTR              ( (reg32 *) pwm_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define pwm_TRIG_CONTROL2_REG              (*(reg32 *) pwm_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define pwm_TRIG_CONTROL2_PTR              ( (reg32 *) pwm_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define pwm_INTERRUPT_REQ_REG              (*(reg32 *) pwm_cy_m0s8_tcpwm_1__INTR )
#define pwm_INTERRUPT_REQ_PTR              ( (reg32 *) pwm_cy_m0s8_tcpwm_1__INTR )
#define pwm_INTERRUPT_SET_REG              (*(reg32 *) pwm_cy_m0s8_tcpwm_1__INTR_SET )
#define pwm_INTERRUPT_SET_PTR              ( (reg32 *) pwm_cy_m0s8_tcpwm_1__INTR_SET )
#define pwm_INTERRUPT_MASK_REG             (*(reg32 *) pwm_cy_m0s8_tcpwm_1__INTR_MASK )
#define pwm_INTERRUPT_MASK_PTR             ( (reg32 *) pwm_cy_m0s8_tcpwm_1__INTR_MASK )
#define pwm_INTERRUPT_MASKED_REG           (*(reg32 *) pwm_cy_m0s8_tcpwm_1__INTR_MASKED )
#define pwm_INTERRUPT_MASKED_PTR           ( (reg32 *) pwm_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define pwm_MASK                           ((uint32)pwm_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define pwm_RELOAD_CC_SHIFT                (0u)
#define pwm_RELOAD_PERIOD_SHIFT            (1u)
#define pwm_PWM_SYNC_KILL_SHIFT            (2u)
#define pwm_PWM_STOP_KILL_SHIFT            (3u)
#define pwm_PRESCALER_SHIFT                (8u)
#define pwm_UPDOWN_SHIFT                   (16u)
#define pwm_ONESHOT_SHIFT                  (18u)
#define pwm_QUAD_MODE_SHIFT                (20u)
#define pwm_INV_OUT_SHIFT                  (20u)
#define pwm_INV_COMPL_OUT_SHIFT            (21u)
#define pwm_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define pwm_RELOAD_CC_MASK                 ((uint32)(pwm_1BIT_MASK        <<  \
                                                                            pwm_RELOAD_CC_SHIFT))
#define pwm_RELOAD_PERIOD_MASK             ((uint32)(pwm_1BIT_MASK        <<  \
                                                                            pwm_RELOAD_PERIOD_SHIFT))
#define pwm_PWM_SYNC_KILL_MASK             ((uint32)(pwm_1BIT_MASK        <<  \
                                                                            pwm_PWM_SYNC_KILL_SHIFT))
#define pwm_PWM_STOP_KILL_MASK             ((uint32)(pwm_1BIT_MASK        <<  \
                                                                            pwm_PWM_STOP_KILL_SHIFT))
#define pwm_PRESCALER_MASK                 ((uint32)(pwm_8BIT_MASK        <<  \
                                                                            pwm_PRESCALER_SHIFT))
#define pwm_UPDOWN_MASK                    ((uint32)(pwm_2BIT_MASK        <<  \
                                                                            pwm_UPDOWN_SHIFT))
#define pwm_ONESHOT_MASK                   ((uint32)(pwm_1BIT_MASK        <<  \
                                                                            pwm_ONESHOT_SHIFT))
#define pwm_QUAD_MODE_MASK                 ((uint32)(pwm_3BIT_MASK        <<  \
                                                                            pwm_QUAD_MODE_SHIFT))
#define pwm_INV_OUT_MASK                   ((uint32)(pwm_2BIT_MASK        <<  \
                                                                            pwm_INV_OUT_SHIFT))
#define pwm_MODE_MASK                      ((uint32)(pwm_3BIT_MASK        <<  \
                                                                            pwm_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define pwm_CAPTURE_SHIFT                  (0u)
#define pwm_COUNT_SHIFT                    (2u)
#define pwm_RELOAD_SHIFT                   (4u)
#define pwm_STOP_SHIFT                     (6u)
#define pwm_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define pwm_CAPTURE_MASK                   ((uint32)(pwm_2BIT_MASK        <<  \
                                                                  pwm_CAPTURE_SHIFT))
#define pwm_COUNT_MASK                     ((uint32)(pwm_2BIT_MASK        <<  \
                                                                  pwm_COUNT_SHIFT))
#define pwm_RELOAD_MASK                    ((uint32)(pwm_2BIT_MASK        <<  \
                                                                  pwm_RELOAD_SHIFT))
#define pwm_STOP_MASK                      ((uint32)(pwm_2BIT_MASK        <<  \
                                                                  pwm_STOP_SHIFT))
#define pwm_START_MASK                     ((uint32)(pwm_2BIT_MASK        <<  \
                                                                  pwm_START_SHIFT))

/* MASK */
#define pwm_1BIT_MASK                      ((uint32)0x01u)
#define pwm_2BIT_MASK                      ((uint32)0x03u)
#define pwm_3BIT_MASK                      ((uint32)0x07u)
#define pwm_6BIT_MASK                      ((uint32)0x3Fu)
#define pwm_8BIT_MASK                      ((uint32)0xFFu)
#define pwm_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define pwm_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define pwm_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(pwm_QUAD_ENCODING_MODES     << pwm_QUAD_MODE_SHIFT))       |\
         ((uint32)(pwm_CONFIG                  << pwm_MODE_SHIFT)))

#define pwm_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(pwm_PWM_STOP_EVENT          << pwm_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(pwm_PWM_OUT_INVERT          << pwm_INV_OUT_SHIFT))         |\
         ((uint32)(pwm_PWM_OUT_N_INVERT        << pwm_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(pwm_PWM_MODE                << pwm_MODE_SHIFT)))

#define pwm_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(pwm_PWM_RUN_MODE         << pwm_ONESHOT_SHIFT))
            
#define pwm_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(pwm_PWM_ALIGN            << pwm_UPDOWN_SHIFT))

#define pwm_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(pwm_PWM_KILL_EVENT      << pwm_PWM_SYNC_KILL_SHIFT))

#define pwm_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(pwm_PWM_DEAD_TIME_CYCLE  << pwm_PRESCALER_SHIFT))

#define pwm_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(pwm_PWM_PRESCALER        << pwm_PRESCALER_SHIFT))

#define pwm_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(pwm_TC_PRESCALER            << pwm_PRESCALER_SHIFT))       |\
         ((uint32)(pwm_TC_COUNTER_MODE         << pwm_UPDOWN_SHIFT))          |\
         ((uint32)(pwm_TC_RUN_MODE             << pwm_ONESHOT_SHIFT))         |\
         ((uint32)(pwm_TC_COMP_CAP_MODE        << pwm_MODE_SHIFT)))
        
#define pwm_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(pwm_QUAD_PHIA_SIGNAL_MODE   << pwm_COUNT_SHIFT))           |\
         ((uint32)(pwm_QUAD_INDEX_SIGNAL_MODE  << pwm_RELOAD_SHIFT))          |\
         ((uint32)(pwm_QUAD_STOP_SIGNAL_MODE   << pwm_STOP_SHIFT))            |\
         ((uint32)(pwm_QUAD_PHIB_SIGNAL_MODE   << pwm_START_SHIFT)))

#define pwm_PWM_SIGNALS_MODES                                                              \
        (((uint32)(pwm_PWM_SWITCH_SIGNAL_MODE  << pwm_CAPTURE_SHIFT))         |\
         ((uint32)(pwm_PWM_COUNT_SIGNAL_MODE   << pwm_COUNT_SHIFT))           |\
         ((uint32)(pwm_PWM_RELOAD_SIGNAL_MODE  << pwm_RELOAD_SHIFT))          |\
         ((uint32)(pwm_PWM_STOP_SIGNAL_MODE    << pwm_STOP_SHIFT))            |\
         ((uint32)(pwm_PWM_START_SIGNAL_MODE   << pwm_START_SHIFT)))

#define pwm_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(pwm_TC_CAPTURE_SIGNAL_MODE  << pwm_CAPTURE_SHIFT))         |\
         ((uint32)(pwm_TC_COUNT_SIGNAL_MODE    << pwm_COUNT_SHIFT))           |\
         ((uint32)(pwm_TC_RELOAD_SIGNAL_MODE   << pwm_RELOAD_SHIFT))          |\
         ((uint32)(pwm_TC_STOP_SIGNAL_MODE     << pwm_STOP_SHIFT))            |\
         ((uint32)(pwm_TC_START_SIGNAL_MODE    << pwm_START_SHIFT)))
        
#define pwm_TIMER_UPDOWN_CNT_USED                                                          \
                ((pwm__COUNT_UPDOWN0 == pwm_TC_COUNTER_MODE)                  ||\
                 (pwm__COUNT_UPDOWN1 == pwm_TC_COUNTER_MODE))

#define pwm_PWM_UPDOWN_CNT_USED                                                            \
                ((pwm__CENTER == pwm_PWM_ALIGN)                               ||\
                 (pwm__ASYMMETRIC == pwm_PWM_ALIGN))               
        
#define pwm_PWM_PR_INIT_VALUE              (1u)
#define pwm_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_pwm_H */

/* [] END OF FILE */
