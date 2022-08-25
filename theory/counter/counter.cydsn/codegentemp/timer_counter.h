/*******************************************************************************
* File Name: timer_counter.h
* Version 2.10
*
* Description:
*  This file provides constants and parameter values for the timer_counter
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

#if !defined(CY_TCPWM_timer_counter_H)
#define CY_TCPWM_timer_counter_H


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
} timer_counter_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  timer_counter_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define timer_counter_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define timer_counter_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define timer_counter_CONFIG                         (1lu)

/* Quad Mode */
/* Parameters */
#define timer_counter_QUAD_ENCODING_MODES            (0lu)
#define timer_counter_QUAD_AUTO_START                (1lu)

/* Signal modes */
#define timer_counter_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define timer_counter_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define timer_counter_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define timer_counter_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define timer_counter_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define timer_counter_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define timer_counter_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define timer_counter_TC_RUN_MODE                    (0lu)
#define timer_counter_TC_COUNTER_MODE                (1lu)
#define timer_counter_TC_COMP_CAP_MODE               (2lu)
#define timer_counter_TC_PRESCALER                   (0lu)

/* Signal modes */
#define timer_counter_TC_RELOAD_SIGNAL_MODE          (0lu)
#define timer_counter_TC_COUNT_SIGNAL_MODE           (1lu)
#define timer_counter_TC_START_SIGNAL_MODE           (0lu)
#define timer_counter_TC_STOP_SIGNAL_MODE            (0lu)
#define timer_counter_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define timer_counter_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define timer_counter_TC_COUNT_SIGNAL_PRESENT        (1lu)
#define timer_counter_TC_START_SIGNAL_PRESENT        (0lu)
#define timer_counter_TC_STOP_SIGNAL_PRESENT         (0lu)
#define timer_counter_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define timer_counter_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define timer_counter_PWM_KILL_EVENT                 (0lu)
#define timer_counter_PWM_STOP_EVENT                 (0lu)
#define timer_counter_PWM_MODE                       (4lu)
#define timer_counter_PWM_OUT_N_INVERT               (0lu)
#define timer_counter_PWM_OUT_INVERT                 (0lu)
#define timer_counter_PWM_ALIGN                      (0lu)
#define timer_counter_PWM_RUN_MODE                   (0lu)
#define timer_counter_PWM_DEAD_TIME_CYCLE            (0lu)
#define timer_counter_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define timer_counter_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define timer_counter_PWM_COUNT_SIGNAL_MODE          (3lu)
#define timer_counter_PWM_START_SIGNAL_MODE          (0lu)
#define timer_counter_PWM_STOP_SIGNAL_MODE           (0lu)
#define timer_counter_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define timer_counter_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define timer_counter_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define timer_counter_PWM_START_SIGNAL_PRESENT       (0lu)
#define timer_counter_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define timer_counter_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define timer_counter_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define timer_counter_TC_PERIOD_VALUE                (2lu)
#define timer_counter_TC_COMPARE_VALUE               (65535lu)
#define timer_counter_TC_COMPARE_BUF_VALUE           (65535lu)
#define timer_counter_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define timer_counter_PWM_PERIOD_VALUE               (65535lu)
#define timer_counter_PWM_PERIOD_BUF_VALUE           (65535lu)
#define timer_counter_PWM_PERIOD_SWAP                (0lu)
#define timer_counter_PWM_COMPARE_VALUE              (65535lu)
#define timer_counter_PWM_COMPARE_BUF_VALUE          (65535lu)
#define timer_counter_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define timer_counter__LEFT 0
#define timer_counter__RIGHT 1
#define timer_counter__CENTER 2
#define timer_counter__ASYMMETRIC 3

#define timer_counter__X1 0
#define timer_counter__X2 1
#define timer_counter__X4 2

#define timer_counter__PWM 4
#define timer_counter__PWM_DT 5
#define timer_counter__PWM_PR 6

#define timer_counter__INVERSE 1
#define timer_counter__DIRECT 0

#define timer_counter__CAPTURE 2
#define timer_counter__COMPARE 0

#define timer_counter__TRIG_LEVEL 3
#define timer_counter__TRIG_RISING 0
#define timer_counter__TRIG_FALLING 1
#define timer_counter__TRIG_BOTH 2

#define timer_counter__INTR_MASK_TC 1
#define timer_counter__INTR_MASK_CC_MATCH 2
#define timer_counter__INTR_MASK_NONE 0
#define timer_counter__INTR_MASK_TC_CC 3

#define timer_counter__UNCONFIG 8
#define timer_counter__TIMER 1
#define timer_counter__QUAD 3
#define timer_counter__PWM_SEL 7

#define timer_counter__COUNT_UP 0
#define timer_counter__COUNT_DOWN 1
#define timer_counter__COUNT_UPDOWN0 2
#define timer_counter__COUNT_UPDOWN1 3


/* Prescaler */
#define timer_counter_PRESCALE_DIVBY1                ((uint32)(0u << timer_counter_PRESCALER_SHIFT))
#define timer_counter_PRESCALE_DIVBY2                ((uint32)(1u << timer_counter_PRESCALER_SHIFT))
#define timer_counter_PRESCALE_DIVBY4                ((uint32)(2u << timer_counter_PRESCALER_SHIFT))
#define timer_counter_PRESCALE_DIVBY8                ((uint32)(3u << timer_counter_PRESCALER_SHIFT))
#define timer_counter_PRESCALE_DIVBY16               ((uint32)(4u << timer_counter_PRESCALER_SHIFT))
#define timer_counter_PRESCALE_DIVBY32               ((uint32)(5u << timer_counter_PRESCALER_SHIFT))
#define timer_counter_PRESCALE_DIVBY64               ((uint32)(6u << timer_counter_PRESCALER_SHIFT))
#define timer_counter_PRESCALE_DIVBY128              ((uint32)(7u << timer_counter_PRESCALER_SHIFT))

/* TCPWM set modes */
#define timer_counter_MODE_TIMER_COMPARE             ((uint32)(timer_counter__COMPARE         <<  \
                                                                  timer_counter_MODE_SHIFT))
#define timer_counter_MODE_TIMER_CAPTURE             ((uint32)(timer_counter__CAPTURE         <<  \
                                                                  timer_counter_MODE_SHIFT))
#define timer_counter_MODE_QUAD                      ((uint32)(timer_counter__QUAD            <<  \
                                                                  timer_counter_MODE_SHIFT))
#define timer_counter_MODE_PWM                       ((uint32)(timer_counter__PWM             <<  \
                                                                  timer_counter_MODE_SHIFT))
#define timer_counter_MODE_PWM_DT                    ((uint32)(timer_counter__PWM_DT          <<  \
                                                                  timer_counter_MODE_SHIFT))
#define timer_counter_MODE_PWM_PR                    ((uint32)(timer_counter__PWM_PR          <<  \
                                                                  timer_counter_MODE_SHIFT))

/* Quad Modes */
#define timer_counter_MODE_X1                        ((uint32)(timer_counter__X1              <<  \
                                                                  timer_counter_QUAD_MODE_SHIFT))
#define timer_counter_MODE_X2                        ((uint32)(timer_counter__X2              <<  \
                                                                  timer_counter_QUAD_MODE_SHIFT))
#define timer_counter_MODE_X4                        ((uint32)(timer_counter__X4              <<  \
                                                                  timer_counter_QUAD_MODE_SHIFT))

/* Counter modes */
#define timer_counter_COUNT_UP                       ((uint32)(timer_counter__COUNT_UP        <<  \
                                                                  timer_counter_UPDOWN_SHIFT))
#define timer_counter_COUNT_DOWN                     ((uint32)(timer_counter__COUNT_DOWN      <<  \
                                                                  timer_counter_UPDOWN_SHIFT))
#define timer_counter_COUNT_UPDOWN0                  ((uint32)(timer_counter__COUNT_UPDOWN0   <<  \
                                                                  timer_counter_UPDOWN_SHIFT))
#define timer_counter_COUNT_UPDOWN1                  ((uint32)(timer_counter__COUNT_UPDOWN1   <<  \
                                                                  timer_counter_UPDOWN_SHIFT))

/* PWM output invert */
#define timer_counter_INVERT_LINE                    ((uint32)(timer_counter__INVERSE         <<  \
                                                                  timer_counter_INV_OUT_SHIFT))
#define timer_counter_INVERT_LINE_N                  ((uint32)(timer_counter__INVERSE         <<  \
                                                                  timer_counter_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define timer_counter_TRIG_RISING                    ((uint32)timer_counter__TRIG_RISING)
#define timer_counter_TRIG_FALLING                   ((uint32)timer_counter__TRIG_FALLING)
#define timer_counter_TRIG_BOTH                      ((uint32)timer_counter__TRIG_BOTH)
#define timer_counter_TRIG_LEVEL                     ((uint32)timer_counter__TRIG_LEVEL)

/* Interrupt mask */
#define timer_counter_INTR_MASK_TC                   ((uint32)timer_counter__INTR_MASK_TC)
#define timer_counter_INTR_MASK_CC_MATCH             ((uint32)timer_counter__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define timer_counter_CC_MATCH_SET                   (0x00u)
#define timer_counter_CC_MATCH_CLEAR                 (0x01u)
#define timer_counter_CC_MATCH_INVERT                (0x02u)
#define timer_counter_CC_MATCH_NO_CHANGE             (0x03u)
#define timer_counter_OVERLOW_SET                    (0x00u)
#define timer_counter_OVERLOW_CLEAR                  (0x04u)
#define timer_counter_OVERLOW_INVERT                 (0x08u)
#define timer_counter_OVERLOW_NO_CHANGE              (0x0Cu)
#define timer_counter_UNDERFLOW_SET                  (0x00u)
#define timer_counter_UNDERFLOW_CLEAR                (0x10u)
#define timer_counter_UNDERFLOW_INVERT               (0x20u)
#define timer_counter_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define timer_counter_PWM_MODE_LEFT                  (timer_counter_CC_MATCH_CLEAR        |   \
                                                         timer_counter_OVERLOW_SET           |   \
                                                         timer_counter_UNDERFLOW_NO_CHANGE)
#define timer_counter_PWM_MODE_RIGHT                 (timer_counter_CC_MATCH_SET          |   \
                                                         timer_counter_OVERLOW_NO_CHANGE     |   \
                                                         timer_counter_UNDERFLOW_CLEAR)
#define timer_counter_PWM_MODE_ASYM                  (timer_counter_CC_MATCH_INVERT       |   \
                                                         timer_counter_OVERLOW_SET           |   \
                                                         timer_counter_UNDERFLOW_CLEAR)

#if (timer_counter_CY_TCPWM_V2)
    #if(timer_counter_CY_TCPWM_4000)
        #define timer_counter_PWM_MODE_CENTER                (timer_counter_CC_MATCH_INVERT       |   \
                                                                 timer_counter_OVERLOW_NO_CHANGE     |   \
                                                                 timer_counter_UNDERFLOW_CLEAR)
    #else
        #define timer_counter_PWM_MODE_CENTER                (timer_counter_CC_MATCH_INVERT       |   \
                                                                 timer_counter_OVERLOW_SET           |   \
                                                                 timer_counter_UNDERFLOW_CLEAR)
    #endif /* (timer_counter_CY_TCPWM_4000) */
#else
    #define timer_counter_PWM_MODE_CENTER                (timer_counter_CC_MATCH_INVERT       |   \
                                                             timer_counter_OVERLOW_NO_CHANGE     |   \
                                                             timer_counter_UNDERFLOW_CLEAR)
#endif /* (timer_counter_CY_TCPWM_NEW) */

/* Command operations without condition */
#define timer_counter_CMD_CAPTURE                    (0u)
#define timer_counter_CMD_RELOAD                     (8u)
#define timer_counter_CMD_STOP                       (16u)
#define timer_counter_CMD_START                      (24u)

/* Status */
#define timer_counter_STATUS_DOWN                    (1u)
#define timer_counter_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   timer_counter_Init(void);
void   timer_counter_Enable(void);
void   timer_counter_Start(void);
void   timer_counter_Stop(void);

void   timer_counter_SetMode(uint32 mode);
void   timer_counter_SetCounterMode(uint32 counterMode);
void   timer_counter_SetPWMMode(uint32 modeMask);
void   timer_counter_SetQDMode(uint32 qdMode);

void   timer_counter_SetPrescaler(uint32 prescaler);
void   timer_counter_TriggerCommand(uint32 mask, uint32 command);
void   timer_counter_SetOneShot(uint32 oneShotEnable);
uint32 timer_counter_ReadStatus(void);

void   timer_counter_SetPWMSyncKill(uint32 syncKillEnable);
void   timer_counter_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   timer_counter_SetPWMDeadTime(uint32 deadTime);
void   timer_counter_SetPWMInvert(uint32 mask);

void   timer_counter_SetInterruptMode(uint32 interruptMask);
uint32 timer_counter_GetInterruptSourceMasked(void);
uint32 timer_counter_GetInterruptSource(void);
void   timer_counter_ClearInterrupt(uint32 interruptMask);
void   timer_counter_SetInterrupt(uint32 interruptMask);

void   timer_counter_WriteCounter(uint32 count);
uint32 timer_counter_ReadCounter(void);

uint32 timer_counter_ReadCapture(void);
uint32 timer_counter_ReadCaptureBuf(void);

void   timer_counter_WritePeriod(uint32 period);
uint32 timer_counter_ReadPeriod(void);
void   timer_counter_WritePeriodBuf(uint32 periodBuf);
uint32 timer_counter_ReadPeriodBuf(void);

void   timer_counter_WriteCompare(uint32 compare);
uint32 timer_counter_ReadCompare(void);
void   timer_counter_WriteCompareBuf(uint32 compareBuf);
uint32 timer_counter_ReadCompareBuf(void);

void   timer_counter_SetPeriodSwap(uint32 swapEnable);
void   timer_counter_SetCompareSwap(uint32 swapEnable);

void   timer_counter_SetCaptureMode(uint32 triggerMode);
void   timer_counter_SetReloadMode(uint32 triggerMode);
void   timer_counter_SetStartMode(uint32 triggerMode);
void   timer_counter_SetStopMode(uint32 triggerMode);
void   timer_counter_SetCountMode(uint32 triggerMode);

void   timer_counter_SaveConfig(void);
void   timer_counter_RestoreConfig(void);
void   timer_counter_Sleep(void);
void   timer_counter_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define timer_counter_BLOCK_CONTROL_REG              (*(reg32 *) timer_counter_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define timer_counter_BLOCK_CONTROL_PTR              ( (reg32 *) timer_counter_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define timer_counter_COMMAND_REG                    (*(reg32 *) timer_counter_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define timer_counter_COMMAND_PTR                    ( (reg32 *) timer_counter_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define timer_counter_INTRRUPT_CAUSE_REG             (*(reg32 *) timer_counter_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define timer_counter_INTRRUPT_CAUSE_PTR             ( (reg32 *) timer_counter_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define timer_counter_CONTROL_REG                    (*(reg32 *) timer_counter_cy_m0s8_tcpwm_1__CTRL )
#define timer_counter_CONTROL_PTR                    ( (reg32 *) timer_counter_cy_m0s8_tcpwm_1__CTRL )
#define timer_counter_STATUS_REG                     (*(reg32 *) timer_counter_cy_m0s8_tcpwm_1__STATUS )
#define timer_counter_STATUS_PTR                     ( (reg32 *) timer_counter_cy_m0s8_tcpwm_1__STATUS )
#define timer_counter_COUNTER_REG                    (*(reg32 *) timer_counter_cy_m0s8_tcpwm_1__COUNTER )
#define timer_counter_COUNTER_PTR                    ( (reg32 *) timer_counter_cy_m0s8_tcpwm_1__COUNTER )
#define timer_counter_COMP_CAP_REG                   (*(reg32 *) timer_counter_cy_m0s8_tcpwm_1__CC )
#define timer_counter_COMP_CAP_PTR                   ( (reg32 *) timer_counter_cy_m0s8_tcpwm_1__CC )
#define timer_counter_COMP_CAP_BUF_REG               (*(reg32 *) timer_counter_cy_m0s8_tcpwm_1__CC_BUFF )
#define timer_counter_COMP_CAP_BUF_PTR               ( (reg32 *) timer_counter_cy_m0s8_tcpwm_1__CC_BUFF )
#define timer_counter_PERIOD_REG                     (*(reg32 *) timer_counter_cy_m0s8_tcpwm_1__PERIOD )
#define timer_counter_PERIOD_PTR                     ( (reg32 *) timer_counter_cy_m0s8_tcpwm_1__PERIOD )
#define timer_counter_PERIOD_BUF_REG                 (*(reg32 *) timer_counter_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define timer_counter_PERIOD_BUF_PTR                 ( (reg32 *) timer_counter_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define timer_counter_TRIG_CONTROL0_REG              (*(reg32 *) timer_counter_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define timer_counter_TRIG_CONTROL0_PTR              ( (reg32 *) timer_counter_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define timer_counter_TRIG_CONTROL1_REG              (*(reg32 *) timer_counter_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define timer_counter_TRIG_CONTROL1_PTR              ( (reg32 *) timer_counter_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define timer_counter_TRIG_CONTROL2_REG              (*(reg32 *) timer_counter_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define timer_counter_TRIG_CONTROL2_PTR              ( (reg32 *) timer_counter_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define timer_counter_INTERRUPT_REQ_REG              (*(reg32 *) timer_counter_cy_m0s8_tcpwm_1__INTR )
#define timer_counter_INTERRUPT_REQ_PTR              ( (reg32 *) timer_counter_cy_m0s8_tcpwm_1__INTR )
#define timer_counter_INTERRUPT_SET_REG              (*(reg32 *) timer_counter_cy_m0s8_tcpwm_1__INTR_SET )
#define timer_counter_INTERRUPT_SET_PTR              ( (reg32 *) timer_counter_cy_m0s8_tcpwm_1__INTR_SET )
#define timer_counter_INTERRUPT_MASK_REG             (*(reg32 *) timer_counter_cy_m0s8_tcpwm_1__INTR_MASK )
#define timer_counter_INTERRUPT_MASK_PTR             ( (reg32 *) timer_counter_cy_m0s8_tcpwm_1__INTR_MASK )
#define timer_counter_INTERRUPT_MASKED_REG           (*(reg32 *) timer_counter_cy_m0s8_tcpwm_1__INTR_MASKED )
#define timer_counter_INTERRUPT_MASKED_PTR           ( (reg32 *) timer_counter_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define timer_counter_MASK                           ((uint32)timer_counter_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define timer_counter_RELOAD_CC_SHIFT                (0u)
#define timer_counter_RELOAD_PERIOD_SHIFT            (1u)
#define timer_counter_PWM_SYNC_KILL_SHIFT            (2u)
#define timer_counter_PWM_STOP_KILL_SHIFT            (3u)
#define timer_counter_PRESCALER_SHIFT                (8u)
#define timer_counter_UPDOWN_SHIFT                   (16u)
#define timer_counter_ONESHOT_SHIFT                  (18u)
#define timer_counter_QUAD_MODE_SHIFT                (20u)
#define timer_counter_INV_OUT_SHIFT                  (20u)
#define timer_counter_INV_COMPL_OUT_SHIFT            (21u)
#define timer_counter_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define timer_counter_RELOAD_CC_MASK                 ((uint32)(timer_counter_1BIT_MASK        <<  \
                                                                            timer_counter_RELOAD_CC_SHIFT))
#define timer_counter_RELOAD_PERIOD_MASK             ((uint32)(timer_counter_1BIT_MASK        <<  \
                                                                            timer_counter_RELOAD_PERIOD_SHIFT))
#define timer_counter_PWM_SYNC_KILL_MASK             ((uint32)(timer_counter_1BIT_MASK        <<  \
                                                                            timer_counter_PWM_SYNC_KILL_SHIFT))
#define timer_counter_PWM_STOP_KILL_MASK             ((uint32)(timer_counter_1BIT_MASK        <<  \
                                                                            timer_counter_PWM_STOP_KILL_SHIFT))
#define timer_counter_PRESCALER_MASK                 ((uint32)(timer_counter_8BIT_MASK        <<  \
                                                                            timer_counter_PRESCALER_SHIFT))
#define timer_counter_UPDOWN_MASK                    ((uint32)(timer_counter_2BIT_MASK        <<  \
                                                                            timer_counter_UPDOWN_SHIFT))
#define timer_counter_ONESHOT_MASK                   ((uint32)(timer_counter_1BIT_MASK        <<  \
                                                                            timer_counter_ONESHOT_SHIFT))
#define timer_counter_QUAD_MODE_MASK                 ((uint32)(timer_counter_3BIT_MASK        <<  \
                                                                            timer_counter_QUAD_MODE_SHIFT))
#define timer_counter_INV_OUT_MASK                   ((uint32)(timer_counter_2BIT_MASK        <<  \
                                                                            timer_counter_INV_OUT_SHIFT))
#define timer_counter_MODE_MASK                      ((uint32)(timer_counter_3BIT_MASK        <<  \
                                                                            timer_counter_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define timer_counter_CAPTURE_SHIFT                  (0u)
#define timer_counter_COUNT_SHIFT                    (2u)
#define timer_counter_RELOAD_SHIFT                   (4u)
#define timer_counter_STOP_SHIFT                     (6u)
#define timer_counter_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define timer_counter_CAPTURE_MASK                   ((uint32)(timer_counter_2BIT_MASK        <<  \
                                                                  timer_counter_CAPTURE_SHIFT))
#define timer_counter_COUNT_MASK                     ((uint32)(timer_counter_2BIT_MASK        <<  \
                                                                  timer_counter_COUNT_SHIFT))
#define timer_counter_RELOAD_MASK                    ((uint32)(timer_counter_2BIT_MASK        <<  \
                                                                  timer_counter_RELOAD_SHIFT))
#define timer_counter_STOP_MASK                      ((uint32)(timer_counter_2BIT_MASK        <<  \
                                                                  timer_counter_STOP_SHIFT))
#define timer_counter_START_MASK                     ((uint32)(timer_counter_2BIT_MASK        <<  \
                                                                  timer_counter_START_SHIFT))

/* MASK */
#define timer_counter_1BIT_MASK                      ((uint32)0x01u)
#define timer_counter_2BIT_MASK                      ((uint32)0x03u)
#define timer_counter_3BIT_MASK                      ((uint32)0x07u)
#define timer_counter_6BIT_MASK                      ((uint32)0x3Fu)
#define timer_counter_8BIT_MASK                      ((uint32)0xFFu)
#define timer_counter_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define timer_counter_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define timer_counter_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(timer_counter_QUAD_ENCODING_MODES     << timer_counter_QUAD_MODE_SHIFT))       |\
         ((uint32)(timer_counter_CONFIG                  << timer_counter_MODE_SHIFT)))

#define timer_counter_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(timer_counter_PWM_STOP_EVENT          << timer_counter_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(timer_counter_PWM_OUT_INVERT          << timer_counter_INV_OUT_SHIFT))         |\
         ((uint32)(timer_counter_PWM_OUT_N_INVERT        << timer_counter_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(timer_counter_PWM_MODE                << timer_counter_MODE_SHIFT)))

#define timer_counter_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(timer_counter_PWM_RUN_MODE         << timer_counter_ONESHOT_SHIFT))
            
#define timer_counter_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(timer_counter_PWM_ALIGN            << timer_counter_UPDOWN_SHIFT))

#define timer_counter_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(timer_counter_PWM_KILL_EVENT      << timer_counter_PWM_SYNC_KILL_SHIFT))

#define timer_counter_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(timer_counter_PWM_DEAD_TIME_CYCLE  << timer_counter_PRESCALER_SHIFT))

#define timer_counter_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(timer_counter_PWM_PRESCALER        << timer_counter_PRESCALER_SHIFT))

#define timer_counter_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(timer_counter_TC_PRESCALER            << timer_counter_PRESCALER_SHIFT))       |\
         ((uint32)(timer_counter_TC_COUNTER_MODE         << timer_counter_UPDOWN_SHIFT))          |\
         ((uint32)(timer_counter_TC_RUN_MODE             << timer_counter_ONESHOT_SHIFT))         |\
         ((uint32)(timer_counter_TC_COMP_CAP_MODE        << timer_counter_MODE_SHIFT)))
        
#define timer_counter_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(timer_counter_QUAD_PHIA_SIGNAL_MODE   << timer_counter_COUNT_SHIFT))           |\
         ((uint32)(timer_counter_QUAD_INDEX_SIGNAL_MODE  << timer_counter_RELOAD_SHIFT))          |\
         ((uint32)(timer_counter_QUAD_STOP_SIGNAL_MODE   << timer_counter_STOP_SHIFT))            |\
         ((uint32)(timer_counter_QUAD_PHIB_SIGNAL_MODE   << timer_counter_START_SHIFT)))

#define timer_counter_PWM_SIGNALS_MODES                                                              \
        (((uint32)(timer_counter_PWM_SWITCH_SIGNAL_MODE  << timer_counter_CAPTURE_SHIFT))         |\
         ((uint32)(timer_counter_PWM_COUNT_SIGNAL_MODE   << timer_counter_COUNT_SHIFT))           |\
         ((uint32)(timer_counter_PWM_RELOAD_SIGNAL_MODE  << timer_counter_RELOAD_SHIFT))          |\
         ((uint32)(timer_counter_PWM_STOP_SIGNAL_MODE    << timer_counter_STOP_SHIFT))            |\
         ((uint32)(timer_counter_PWM_START_SIGNAL_MODE   << timer_counter_START_SHIFT)))

#define timer_counter_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(timer_counter_TC_CAPTURE_SIGNAL_MODE  << timer_counter_CAPTURE_SHIFT))         |\
         ((uint32)(timer_counter_TC_COUNT_SIGNAL_MODE    << timer_counter_COUNT_SHIFT))           |\
         ((uint32)(timer_counter_TC_RELOAD_SIGNAL_MODE   << timer_counter_RELOAD_SHIFT))          |\
         ((uint32)(timer_counter_TC_STOP_SIGNAL_MODE     << timer_counter_STOP_SHIFT))            |\
         ((uint32)(timer_counter_TC_START_SIGNAL_MODE    << timer_counter_START_SHIFT)))
        
#define timer_counter_TIMER_UPDOWN_CNT_USED                                                          \
                ((timer_counter__COUNT_UPDOWN0 == timer_counter_TC_COUNTER_MODE)                  ||\
                 (timer_counter__COUNT_UPDOWN1 == timer_counter_TC_COUNTER_MODE))

#define timer_counter_PWM_UPDOWN_CNT_USED                                                            \
                ((timer_counter__CENTER == timer_counter_PWM_ALIGN)                               ||\
                 (timer_counter__ASYMMETRIC == timer_counter_PWM_ALIGN))               
        
#define timer_counter_PWM_PR_INIT_VALUE              (1u)
#define timer_counter_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_timer_counter_H */

/* [] END OF FILE */
