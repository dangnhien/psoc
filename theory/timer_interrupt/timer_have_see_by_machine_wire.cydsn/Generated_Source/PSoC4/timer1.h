/*******************************************************************************
* File Name: timer1.h
* Version 2.10
*
* Description:
*  This file provides constants and parameter values for the timer1
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

#if !defined(CY_TCPWM_timer1_H)
#define CY_TCPWM_timer1_H


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
} timer1_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  timer1_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define timer1_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define timer1_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define timer1_CONFIG                         (1lu)

/* Quad Mode */
/* Parameters */
#define timer1_QUAD_ENCODING_MODES            (0lu)
#define timer1_QUAD_AUTO_START                (1lu)

/* Signal modes */
#define timer1_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define timer1_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define timer1_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define timer1_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define timer1_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define timer1_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define timer1_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define timer1_TC_RUN_MODE                    (0lu)
#define timer1_TC_COUNTER_MODE                (0lu)
#define timer1_TC_COMP_CAP_MODE               (2lu)
#define timer1_TC_PRESCALER                   (0lu)

/* Signal modes */
#define timer1_TC_RELOAD_SIGNAL_MODE          (1lu)
#define timer1_TC_COUNT_SIGNAL_MODE           (3lu)
#define timer1_TC_START_SIGNAL_MODE           (0lu)
#define timer1_TC_STOP_SIGNAL_MODE            (0lu)
#define timer1_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define timer1_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define timer1_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define timer1_TC_START_SIGNAL_PRESENT        (0lu)
#define timer1_TC_STOP_SIGNAL_PRESENT         (0lu)
#define timer1_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define timer1_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define timer1_PWM_KILL_EVENT                 (0lu)
#define timer1_PWM_STOP_EVENT                 (0lu)
#define timer1_PWM_MODE                       (4lu)
#define timer1_PWM_OUT_N_INVERT               (0lu)
#define timer1_PWM_OUT_INVERT                 (0lu)
#define timer1_PWM_ALIGN                      (0lu)
#define timer1_PWM_RUN_MODE                   (0lu)
#define timer1_PWM_DEAD_TIME_CYCLE            (0lu)
#define timer1_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define timer1_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define timer1_PWM_COUNT_SIGNAL_MODE          (3lu)
#define timer1_PWM_START_SIGNAL_MODE          (0lu)
#define timer1_PWM_STOP_SIGNAL_MODE           (0lu)
#define timer1_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define timer1_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define timer1_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define timer1_PWM_START_SIGNAL_PRESENT       (0lu)
#define timer1_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define timer1_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define timer1_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define timer1_TC_PERIOD_VALUE                (9999lu)
#define timer1_TC_COMPARE_VALUE               (65535lu)
#define timer1_TC_COMPARE_BUF_VALUE           (65535lu)
#define timer1_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define timer1_PWM_PERIOD_VALUE               (65535lu)
#define timer1_PWM_PERIOD_BUF_VALUE           (65535lu)
#define timer1_PWM_PERIOD_SWAP                (0lu)
#define timer1_PWM_COMPARE_VALUE              (65535lu)
#define timer1_PWM_COMPARE_BUF_VALUE          (65535lu)
#define timer1_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define timer1__LEFT 0
#define timer1__RIGHT 1
#define timer1__CENTER 2
#define timer1__ASYMMETRIC 3

#define timer1__X1 0
#define timer1__X2 1
#define timer1__X4 2

#define timer1__PWM 4
#define timer1__PWM_DT 5
#define timer1__PWM_PR 6

#define timer1__INVERSE 1
#define timer1__DIRECT 0

#define timer1__CAPTURE 2
#define timer1__COMPARE 0

#define timer1__TRIG_LEVEL 3
#define timer1__TRIG_RISING 0
#define timer1__TRIG_FALLING 1
#define timer1__TRIG_BOTH 2

#define timer1__INTR_MASK_TC 1
#define timer1__INTR_MASK_CC_MATCH 2
#define timer1__INTR_MASK_NONE 0
#define timer1__INTR_MASK_TC_CC 3

#define timer1__UNCONFIG 8
#define timer1__TIMER 1
#define timer1__QUAD 3
#define timer1__PWM_SEL 7

#define timer1__COUNT_UP 0
#define timer1__COUNT_DOWN 1
#define timer1__COUNT_UPDOWN0 2
#define timer1__COUNT_UPDOWN1 3


/* Prescaler */
#define timer1_PRESCALE_DIVBY1                ((uint32)(0u << timer1_PRESCALER_SHIFT))
#define timer1_PRESCALE_DIVBY2                ((uint32)(1u << timer1_PRESCALER_SHIFT))
#define timer1_PRESCALE_DIVBY4                ((uint32)(2u << timer1_PRESCALER_SHIFT))
#define timer1_PRESCALE_DIVBY8                ((uint32)(3u << timer1_PRESCALER_SHIFT))
#define timer1_PRESCALE_DIVBY16               ((uint32)(4u << timer1_PRESCALER_SHIFT))
#define timer1_PRESCALE_DIVBY32               ((uint32)(5u << timer1_PRESCALER_SHIFT))
#define timer1_PRESCALE_DIVBY64               ((uint32)(6u << timer1_PRESCALER_SHIFT))
#define timer1_PRESCALE_DIVBY128              ((uint32)(7u << timer1_PRESCALER_SHIFT))

/* TCPWM set modes */
#define timer1_MODE_TIMER_COMPARE             ((uint32)(timer1__COMPARE         <<  \
                                                                  timer1_MODE_SHIFT))
#define timer1_MODE_TIMER_CAPTURE             ((uint32)(timer1__CAPTURE         <<  \
                                                                  timer1_MODE_SHIFT))
#define timer1_MODE_QUAD                      ((uint32)(timer1__QUAD            <<  \
                                                                  timer1_MODE_SHIFT))
#define timer1_MODE_PWM                       ((uint32)(timer1__PWM             <<  \
                                                                  timer1_MODE_SHIFT))
#define timer1_MODE_PWM_DT                    ((uint32)(timer1__PWM_DT          <<  \
                                                                  timer1_MODE_SHIFT))
#define timer1_MODE_PWM_PR                    ((uint32)(timer1__PWM_PR          <<  \
                                                                  timer1_MODE_SHIFT))

/* Quad Modes */
#define timer1_MODE_X1                        ((uint32)(timer1__X1              <<  \
                                                                  timer1_QUAD_MODE_SHIFT))
#define timer1_MODE_X2                        ((uint32)(timer1__X2              <<  \
                                                                  timer1_QUAD_MODE_SHIFT))
#define timer1_MODE_X4                        ((uint32)(timer1__X4              <<  \
                                                                  timer1_QUAD_MODE_SHIFT))

/* Counter modes */
#define timer1_COUNT_UP                       ((uint32)(timer1__COUNT_UP        <<  \
                                                                  timer1_UPDOWN_SHIFT))
#define timer1_COUNT_DOWN                     ((uint32)(timer1__COUNT_DOWN      <<  \
                                                                  timer1_UPDOWN_SHIFT))
#define timer1_COUNT_UPDOWN0                  ((uint32)(timer1__COUNT_UPDOWN0   <<  \
                                                                  timer1_UPDOWN_SHIFT))
#define timer1_COUNT_UPDOWN1                  ((uint32)(timer1__COUNT_UPDOWN1   <<  \
                                                                  timer1_UPDOWN_SHIFT))

/* PWM output invert */
#define timer1_INVERT_LINE                    ((uint32)(timer1__INVERSE         <<  \
                                                                  timer1_INV_OUT_SHIFT))
#define timer1_INVERT_LINE_N                  ((uint32)(timer1__INVERSE         <<  \
                                                                  timer1_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define timer1_TRIG_RISING                    ((uint32)timer1__TRIG_RISING)
#define timer1_TRIG_FALLING                   ((uint32)timer1__TRIG_FALLING)
#define timer1_TRIG_BOTH                      ((uint32)timer1__TRIG_BOTH)
#define timer1_TRIG_LEVEL                     ((uint32)timer1__TRIG_LEVEL)

/* Interrupt mask */
#define timer1_INTR_MASK_TC                   ((uint32)timer1__INTR_MASK_TC)
#define timer1_INTR_MASK_CC_MATCH             ((uint32)timer1__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define timer1_CC_MATCH_SET                   (0x00u)
#define timer1_CC_MATCH_CLEAR                 (0x01u)
#define timer1_CC_MATCH_INVERT                (0x02u)
#define timer1_CC_MATCH_NO_CHANGE             (0x03u)
#define timer1_OVERLOW_SET                    (0x00u)
#define timer1_OVERLOW_CLEAR                  (0x04u)
#define timer1_OVERLOW_INVERT                 (0x08u)
#define timer1_OVERLOW_NO_CHANGE              (0x0Cu)
#define timer1_UNDERFLOW_SET                  (0x00u)
#define timer1_UNDERFLOW_CLEAR                (0x10u)
#define timer1_UNDERFLOW_INVERT               (0x20u)
#define timer1_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define timer1_PWM_MODE_LEFT                  (timer1_CC_MATCH_CLEAR        |   \
                                                         timer1_OVERLOW_SET           |   \
                                                         timer1_UNDERFLOW_NO_CHANGE)
#define timer1_PWM_MODE_RIGHT                 (timer1_CC_MATCH_SET          |   \
                                                         timer1_OVERLOW_NO_CHANGE     |   \
                                                         timer1_UNDERFLOW_CLEAR)
#define timer1_PWM_MODE_ASYM                  (timer1_CC_MATCH_INVERT       |   \
                                                         timer1_OVERLOW_SET           |   \
                                                         timer1_UNDERFLOW_CLEAR)

#if (timer1_CY_TCPWM_V2)
    #if(timer1_CY_TCPWM_4000)
        #define timer1_PWM_MODE_CENTER                (timer1_CC_MATCH_INVERT       |   \
                                                                 timer1_OVERLOW_NO_CHANGE     |   \
                                                                 timer1_UNDERFLOW_CLEAR)
    #else
        #define timer1_PWM_MODE_CENTER                (timer1_CC_MATCH_INVERT       |   \
                                                                 timer1_OVERLOW_SET           |   \
                                                                 timer1_UNDERFLOW_CLEAR)
    #endif /* (timer1_CY_TCPWM_4000) */
#else
    #define timer1_PWM_MODE_CENTER                (timer1_CC_MATCH_INVERT       |   \
                                                             timer1_OVERLOW_NO_CHANGE     |   \
                                                             timer1_UNDERFLOW_CLEAR)
#endif /* (timer1_CY_TCPWM_NEW) */

/* Command operations without condition */
#define timer1_CMD_CAPTURE                    (0u)
#define timer1_CMD_RELOAD                     (8u)
#define timer1_CMD_STOP                       (16u)
#define timer1_CMD_START                      (24u)

/* Status */
#define timer1_STATUS_DOWN                    (1u)
#define timer1_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   timer1_Init(void);
void   timer1_Enable(void);
void   timer1_Start(void);
void   timer1_Stop(void);

void   timer1_SetMode(uint32 mode);
void   timer1_SetCounterMode(uint32 counterMode);
void   timer1_SetPWMMode(uint32 modeMask);
void   timer1_SetQDMode(uint32 qdMode);

void   timer1_SetPrescaler(uint32 prescaler);
void   timer1_TriggerCommand(uint32 mask, uint32 command);
void   timer1_SetOneShot(uint32 oneShotEnable);
uint32 timer1_ReadStatus(void);

void   timer1_SetPWMSyncKill(uint32 syncKillEnable);
void   timer1_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   timer1_SetPWMDeadTime(uint32 deadTime);
void   timer1_SetPWMInvert(uint32 mask);

void   timer1_SetInterruptMode(uint32 interruptMask);
uint32 timer1_GetInterruptSourceMasked(void);
uint32 timer1_GetInterruptSource(void);
void   timer1_ClearInterrupt(uint32 interruptMask);
void   timer1_SetInterrupt(uint32 interruptMask);

void   timer1_WriteCounter(uint32 count);
uint32 timer1_ReadCounter(void);

uint32 timer1_ReadCapture(void);
uint32 timer1_ReadCaptureBuf(void);

void   timer1_WritePeriod(uint32 period);
uint32 timer1_ReadPeriod(void);
void   timer1_WritePeriodBuf(uint32 periodBuf);
uint32 timer1_ReadPeriodBuf(void);

void   timer1_WriteCompare(uint32 compare);
uint32 timer1_ReadCompare(void);
void   timer1_WriteCompareBuf(uint32 compareBuf);
uint32 timer1_ReadCompareBuf(void);

void   timer1_SetPeriodSwap(uint32 swapEnable);
void   timer1_SetCompareSwap(uint32 swapEnable);

void   timer1_SetCaptureMode(uint32 triggerMode);
void   timer1_SetReloadMode(uint32 triggerMode);
void   timer1_SetStartMode(uint32 triggerMode);
void   timer1_SetStopMode(uint32 triggerMode);
void   timer1_SetCountMode(uint32 triggerMode);

void   timer1_SaveConfig(void);
void   timer1_RestoreConfig(void);
void   timer1_Sleep(void);
void   timer1_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define timer1_BLOCK_CONTROL_REG              (*(reg32 *) timer1_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define timer1_BLOCK_CONTROL_PTR              ( (reg32 *) timer1_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define timer1_COMMAND_REG                    (*(reg32 *) timer1_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define timer1_COMMAND_PTR                    ( (reg32 *) timer1_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define timer1_INTRRUPT_CAUSE_REG             (*(reg32 *) timer1_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define timer1_INTRRUPT_CAUSE_PTR             ( (reg32 *) timer1_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define timer1_CONTROL_REG                    (*(reg32 *) timer1_cy_m0s8_tcpwm_1__CTRL )
#define timer1_CONTROL_PTR                    ( (reg32 *) timer1_cy_m0s8_tcpwm_1__CTRL )
#define timer1_STATUS_REG                     (*(reg32 *) timer1_cy_m0s8_tcpwm_1__STATUS )
#define timer1_STATUS_PTR                     ( (reg32 *) timer1_cy_m0s8_tcpwm_1__STATUS )
#define timer1_COUNTER_REG                    (*(reg32 *) timer1_cy_m0s8_tcpwm_1__COUNTER )
#define timer1_COUNTER_PTR                    ( (reg32 *) timer1_cy_m0s8_tcpwm_1__COUNTER )
#define timer1_COMP_CAP_REG                   (*(reg32 *) timer1_cy_m0s8_tcpwm_1__CC )
#define timer1_COMP_CAP_PTR                   ( (reg32 *) timer1_cy_m0s8_tcpwm_1__CC )
#define timer1_COMP_CAP_BUF_REG               (*(reg32 *) timer1_cy_m0s8_tcpwm_1__CC_BUFF )
#define timer1_COMP_CAP_BUF_PTR               ( (reg32 *) timer1_cy_m0s8_tcpwm_1__CC_BUFF )
#define timer1_PERIOD_REG                     (*(reg32 *) timer1_cy_m0s8_tcpwm_1__PERIOD )
#define timer1_PERIOD_PTR                     ( (reg32 *) timer1_cy_m0s8_tcpwm_1__PERIOD )
#define timer1_PERIOD_BUF_REG                 (*(reg32 *) timer1_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define timer1_PERIOD_BUF_PTR                 ( (reg32 *) timer1_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define timer1_TRIG_CONTROL0_REG              (*(reg32 *) timer1_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define timer1_TRIG_CONTROL0_PTR              ( (reg32 *) timer1_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define timer1_TRIG_CONTROL1_REG              (*(reg32 *) timer1_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define timer1_TRIG_CONTROL1_PTR              ( (reg32 *) timer1_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define timer1_TRIG_CONTROL2_REG              (*(reg32 *) timer1_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define timer1_TRIG_CONTROL2_PTR              ( (reg32 *) timer1_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define timer1_INTERRUPT_REQ_REG              (*(reg32 *) timer1_cy_m0s8_tcpwm_1__INTR )
#define timer1_INTERRUPT_REQ_PTR              ( (reg32 *) timer1_cy_m0s8_tcpwm_1__INTR )
#define timer1_INTERRUPT_SET_REG              (*(reg32 *) timer1_cy_m0s8_tcpwm_1__INTR_SET )
#define timer1_INTERRUPT_SET_PTR              ( (reg32 *) timer1_cy_m0s8_tcpwm_1__INTR_SET )
#define timer1_INTERRUPT_MASK_REG             (*(reg32 *) timer1_cy_m0s8_tcpwm_1__INTR_MASK )
#define timer1_INTERRUPT_MASK_PTR             ( (reg32 *) timer1_cy_m0s8_tcpwm_1__INTR_MASK )
#define timer1_INTERRUPT_MASKED_REG           (*(reg32 *) timer1_cy_m0s8_tcpwm_1__INTR_MASKED )
#define timer1_INTERRUPT_MASKED_PTR           ( (reg32 *) timer1_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define timer1_MASK                           ((uint32)timer1_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define timer1_RELOAD_CC_SHIFT                (0u)
#define timer1_RELOAD_PERIOD_SHIFT            (1u)
#define timer1_PWM_SYNC_KILL_SHIFT            (2u)
#define timer1_PWM_STOP_KILL_SHIFT            (3u)
#define timer1_PRESCALER_SHIFT                (8u)
#define timer1_UPDOWN_SHIFT                   (16u)
#define timer1_ONESHOT_SHIFT                  (18u)
#define timer1_QUAD_MODE_SHIFT                (20u)
#define timer1_INV_OUT_SHIFT                  (20u)
#define timer1_INV_COMPL_OUT_SHIFT            (21u)
#define timer1_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define timer1_RELOAD_CC_MASK                 ((uint32)(timer1_1BIT_MASK        <<  \
                                                                            timer1_RELOAD_CC_SHIFT))
#define timer1_RELOAD_PERIOD_MASK             ((uint32)(timer1_1BIT_MASK        <<  \
                                                                            timer1_RELOAD_PERIOD_SHIFT))
#define timer1_PWM_SYNC_KILL_MASK             ((uint32)(timer1_1BIT_MASK        <<  \
                                                                            timer1_PWM_SYNC_KILL_SHIFT))
#define timer1_PWM_STOP_KILL_MASK             ((uint32)(timer1_1BIT_MASK        <<  \
                                                                            timer1_PWM_STOP_KILL_SHIFT))
#define timer1_PRESCALER_MASK                 ((uint32)(timer1_8BIT_MASK        <<  \
                                                                            timer1_PRESCALER_SHIFT))
#define timer1_UPDOWN_MASK                    ((uint32)(timer1_2BIT_MASK        <<  \
                                                                            timer1_UPDOWN_SHIFT))
#define timer1_ONESHOT_MASK                   ((uint32)(timer1_1BIT_MASK        <<  \
                                                                            timer1_ONESHOT_SHIFT))
#define timer1_QUAD_MODE_MASK                 ((uint32)(timer1_3BIT_MASK        <<  \
                                                                            timer1_QUAD_MODE_SHIFT))
#define timer1_INV_OUT_MASK                   ((uint32)(timer1_2BIT_MASK        <<  \
                                                                            timer1_INV_OUT_SHIFT))
#define timer1_MODE_MASK                      ((uint32)(timer1_3BIT_MASK        <<  \
                                                                            timer1_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define timer1_CAPTURE_SHIFT                  (0u)
#define timer1_COUNT_SHIFT                    (2u)
#define timer1_RELOAD_SHIFT                   (4u)
#define timer1_STOP_SHIFT                     (6u)
#define timer1_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define timer1_CAPTURE_MASK                   ((uint32)(timer1_2BIT_MASK        <<  \
                                                                  timer1_CAPTURE_SHIFT))
#define timer1_COUNT_MASK                     ((uint32)(timer1_2BIT_MASK        <<  \
                                                                  timer1_COUNT_SHIFT))
#define timer1_RELOAD_MASK                    ((uint32)(timer1_2BIT_MASK        <<  \
                                                                  timer1_RELOAD_SHIFT))
#define timer1_STOP_MASK                      ((uint32)(timer1_2BIT_MASK        <<  \
                                                                  timer1_STOP_SHIFT))
#define timer1_START_MASK                     ((uint32)(timer1_2BIT_MASK        <<  \
                                                                  timer1_START_SHIFT))

/* MASK */
#define timer1_1BIT_MASK                      ((uint32)0x01u)
#define timer1_2BIT_MASK                      ((uint32)0x03u)
#define timer1_3BIT_MASK                      ((uint32)0x07u)
#define timer1_6BIT_MASK                      ((uint32)0x3Fu)
#define timer1_8BIT_MASK                      ((uint32)0xFFu)
#define timer1_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define timer1_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define timer1_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(timer1_QUAD_ENCODING_MODES     << timer1_QUAD_MODE_SHIFT))       |\
         ((uint32)(timer1_CONFIG                  << timer1_MODE_SHIFT)))

#define timer1_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(timer1_PWM_STOP_EVENT          << timer1_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(timer1_PWM_OUT_INVERT          << timer1_INV_OUT_SHIFT))         |\
         ((uint32)(timer1_PWM_OUT_N_INVERT        << timer1_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(timer1_PWM_MODE                << timer1_MODE_SHIFT)))

#define timer1_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(timer1_PWM_RUN_MODE         << timer1_ONESHOT_SHIFT))
            
#define timer1_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(timer1_PWM_ALIGN            << timer1_UPDOWN_SHIFT))

#define timer1_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(timer1_PWM_KILL_EVENT      << timer1_PWM_SYNC_KILL_SHIFT))

#define timer1_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(timer1_PWM_DEAD_TIME_CYCLE  << timer1_PRESCALER_SHIFT))

#define timer1_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(timer1_PWM_PRESCALER        << timer1_PRESCALER_SHIFT))

#define timer1_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(timer1_TC_PRESCALER            << timer1_PRESCALER_SHIFT))       |\
         ((uint32)(timer1_TC_COUNTER_MODE         << timer1_UPDOWN_SHIFT))          |\
         ((uint32)(timer1_TC_RUN_MODE             << timer1_ONESHOT_SHIFT))         |\
         ((uint32)(timer1_TC_COMP_CAP_MODE        << timer1_MODE_SHIFT)))
        
#define timer1_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(timer1_QUAD_PHIA_SIGNAL_MODE   << timer1_COUNT_SHIFT))           |\
         ((uint32)(timer1_QUAD_INDEX_SIGNAL_MODE  << timer1_RELOAD_SHIFT))          |\
         ((uint32)(timer1_QUAD_STOP_SIGNAL_MODE   << timer1_STOP_SHIFT))            |\
         ((uint32)(timer1_QUAD_PHIB_SIGNAL_MODE   << timer1_START_SHIFT)))

#define timer1_PWM_SIGNALS_MODES                                                              \
        (((uint32)(timer1_PWM_SWITCH_SIGNAL_MODE  << timer1_CAPTURE_SHIFT))         |\
         ((uint32)(timer1_PWM_COUNT_SIGNAL_MODE   << timer1_COUNT_SHIFT))           |\
         ((uint32)(timer1_PWM_RELOAD_SIGNAL_MODE  << timer1_RELOAD_SHIFT))          |\
         ((uint32)(timer1_PWM_STOP_SIGNAL_MODE    << timer1_STOP_SHIFT))            |\
         ((uint32)(timer1_PWM_START_SIGNAL_MODE   << timer1_START_SHIFT)))

#define timer1_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(timer1_TC_CAPTURE_SIGNAL_MODE  << timer1_CAPTURE_SHIFT))         |\
         ((uint32)(timer1_TC_COUNT_SIGNAL_MODE    << timer1_COUNT_SHIFT))           |\
         ((uint32)(timer1_TC_RELOAD_SIGNAL_MODE   << timer1_RELOAD_SHIFT))          |\
         ((uint32)(timer1_TC_STOP_SIGNAL_MODE     << timer1_STOP_SHIFT))            |\
         ((uint32)(timer1_TC_START_SIGNAL_MODE    << timer1_START_SHIFT)))
        
#define timer1_TIMER_UPDOWN_CNT_USED                                                          \
                ((timer1__COUNT_UPDOWN0 == timer1_TC_COUNTER_MODE)                  ||\
                 (timer1__COUNT_UPDOWN1 == timer1_TC_COUNTER_MODE))

#define timer1_PWM_UPDOWN_CNT_USED                                                            \
                ((timer1__CENTER == timer1_PWM_ALIGN)                               ||\
                 (timer1__ASYMMETRIC == timer1_PWM_ALIGN))               
        
#define timer1_PWM_PR_INIT_VALUE              (1u)
#define timer1_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_timer1_H */

/* [] END OF FILE */
