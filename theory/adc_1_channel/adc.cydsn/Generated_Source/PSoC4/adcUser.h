/*******************************************************************************
* File Name: adcUser.h
* Version 2.50
*
* Description:
*  This file contains the function prototypes and constants used in
*  the Sequencing Successive Approximation ADC Component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_ADC_SAR_SEQ_adcUser_H)
#define CY_ADC_SAR_SEQ_adcUser_H

#include "cytypes.h"
#include "CyLib.h"


/***************************************
*      Data Struct Definition
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 enableState;
    uint32 dftRegVal;
} adcUser_BACKUP_STRUCT;


/**************************************
*    Enumerated Types and Parameters
**************************************/

/*  Clock Source setting constants */
#define adcUser__EXTERNAL 0
#define adcUser__INTERNAL 1

/*  Sample Mode setting constants */
#define adcUser__FREERUNNING 0
#define adcUser__HARDWARESOC 1

/*  Reference type setting constants */
#define adcUser__VDDA_2 0
#define adcUser__VDDA 1
#define adcUser__INTERNAL1024 2
#define adcUser__INTERNAL1024BYPASSED 3
#define adcUser__INTERNALVREF 4
#define adcUser__INTERNALVREFBYPASSED 5
#define adcUser__VDDA_2BYPASSED 6
#define adcUser__EXTERNALVREF 7

/* Input buffer gain setting constants */
#define adcUser__DISABLED 0
#define adcUser__ONE 1
#define adcUser__TWO 2
#define adcUser__FOUR 3
#define adcUser__EIGHT 4
#define adcUser__SIXTEEN 5

/* Negative input setting sonstants in single ended mode */
#define adcUser__VSS 0
#define adcUser__VREF 1
#define adcUser__OTHER 2

/* Compare mode setting constants:
*    Mode0 - Disable
*    Mode1 - Result < Low_Limit
*    Mode2 - Low_Limit <= Result < High_Limit
*    Mode3 - High_Limit <= Result
*    Mode4 - (Result < Low_Limit) or (High_Limit <= Result)
*/
#define adcUser__MODE0 0
#define adcUser__MODE1 1
#define adcUser__MODE2 2
#define adcUser__MODE3 3

#define adcUser__RES8 0
#define adcUser__RES10 1

#define adcUser__RIGHT 0
#define adcUser__LEFT 1

#define adcUser__FSIGNED 1
#define adcUser__FUNSIGNED 0

#define adcUser__ACCUMULATE 0
#define adcUser__FIXEDRESOLUTION 1



/***************************************
*   Conditional Compilation Parameters
****************************************/ 

#define adcUser_CY_SAR_IP_VER0               	(0u)
#define adcUser_CY_SAR_IP_VER1               	(1u)

#if (CY_PSOC4_4100 || CY_PSOC4_4200)
    #define adcUser_CY_SAR_IP_VER              (adcUser_CY_SAR_IP_VER0)
#else /* Other devices */
    #define adcUser_CY_SAR_IP_VER              (adcUser_CY_SAR_IP_VER1)
#endif  /* (CY_PSOC4_4100 || CY_PSOC4_4200) */


/***************************************
*    Initial Parameter Constants
***************************************/
#define adcUser_DEFAULT_SAMPLE_MODE_SEL        (0u)
#define adcUser_DEFAULT_VREF_SEL               (1u)
#define adcUser_DEFAULT_NEG_INPUT_SEL          (0u)
#define adcUser_DEFAULT_ALT_RESOLUTION_SEL     (0u)
#define adcUser_DEFAULT_JUSTIFICATION_SEL      (1u)
#define adcUser_DEFAULT_DIFF_RESULT_FORMAT_SEL (1u)
#define adcUser_DEFAULT_SE_RESULT_FORMAT_SEL   (1u)
#define adcUser_DEFAULT_CLOCK_SOURCE           (1u)
#define adcUser_DEFAULT_VREF_MV_VALUE          (5000)
#define adcUser_DEFAULT_BUFFER_GAIN            (0u)
#define adcUser_DEFAULT_AVG_SAMPLES_NUM        (0u)
#define adcUser_DEFAULT_AVG_SAMPLES_DIV        (0u < 4u) ? (int16)(0x100u >> (7u - 0u)) : (int16)(0x100u >> 4u)
#define adcUser_DEFAULT_AVG_MODE               (1u)
#define adcUser_MAX_RESOLUTION                 (8u)
#define adcUser_DEFAULT_LOW_LIMIT              (0u)
#define adcUser_DEFAULT_HIGH_LIMIT             (2047u)
#define adcUser_DEFAULT_COMPARE_MODE           (0u)
#define adcUser_DEFAULT_ACLKS_NUM              (2u)
#define adcUser_DEFAULT_BCLKS_NUM              (2u)
#define adcUser_DEFAULT_CCLKS_NUM              (2u)
#define adcUser_DEFAULT_DCLKS_NUM              (2u)
#define adcUser_TOTAL_CHANNELS_NUM             (1u)
#define adcUser_SEQUENCED_CHANNELS_NUM         (1u)
#define adcUser_DEFAULT_EN_CHANNELS            (1u)
#define adcUser_NOMINAL_CLOCK_FREQ             (2000000)
#define adcUser_INJ_CHANNEL_ENABLED            (0u)
#define adcUser_IRQ_REMOVE                     (0u)

/* Determines whether the configuration contains external negative input. */
#define adcUser_SINGLE_PRESENT                 (0u)
#define adcUser_CHANNELS_MODE                  (0u)
#define adcUser_MAX_CHANNELS_EN_MASK           (0xffffu >> (16u - adcUser_SEQUENCED_CHANNELS_NUM))


/***************************************
*        Function Prototypes
***************************************/

void adcUser_Start(void);
void adcUser_Stop(void);
void adcUser_Init(void);
void adcUser_Enable(void);
void adcUser_StartConvert(void);
void adcUser_StopConvert(void);
uint32 adcUser_IsEndConversion(uint32 retMode);
int16 adcUser_GetResult16(uint32 chan);
void adcUser_SetChanMask(uint32 mask);
void adcUser_SetLowLimit(uint32 lowLimit);
void adcUser_SetHighLimit(uint32 highLimit);
void adcUser_SetLimitMask(uint32 mask);
void adcUser_SetSatMask(uint32 mask);
void adcUser_SetOffset(uint32 chan, int16 offset);
void adcUser_SetGain(uint32 chan, int32 adcGain);
#if(adcUser_INJ_CHANNEL_ENABLED)
    void adcUser_EnableInjection(void);
#endif /* adcUser_INJ_CHANNEL_ENABLED */
#if(adcUser_DEFAULT_JUSTIFICATION_SEL == adcUser__RIGHT)
    int16 adcUser_CountsTo_mVolts(uint32 chan, int16 adcCounts);
    int32 adcUser_CountsTo_uVolts(uint32 chan, int16 adcCounts);
    float32 adcUser_CountsTo_Volts(uint32 chan, int16 adcCounts);
#endif /* End adcUser_DEFAULT_JUSTIFICATION_SEL == adcUser__RIGHT */
void adcUser_Sleep(void);
void adcUser_Wakeup(void);
void adcUser_SaveConfig(void);
void adcUser_RestoreConfig(void);

CY_ISR_PROTO( adcUser_ISR );


/**************************************
*           API Constants
**************************************/
/* Constants for Sleep mode states */
#define adcUser_DISABLED                   (0x00u)
#define adcUser_ENABLED                    (0x01u)
#define adcUser_STARTED                    (0x02u)
#define adcUser_BOOSTPUMP_ENABLED          (0x04u)

/*   Constants for IsEndConversion() "retMode" parameter  */
#define adcUser_RETURN_STATUS              (0x01u)
#define adcUser_WAIT_FOR_RESULT            (0x02u)
#define adcUser_RETURN_STATUS_INJ          (0x04u)
#define adcUser_WAIT_FOR_RESULT_INJ        (0x08u)

#define adcUser_MAX_FREQUENCY              (18000000)       /*18Mhz*/

#define adcUser_RESOLUTION_12              (12u)
#define adcUser_RESOLUTION_10              (10u)
#define adcUser_RESOLUTION_8               (8u)

#define adcUser_10US_DELAY                 (10u)

#define adcUser_10V_COUNTS                 (10.0F)
#define adcUser_10MV_COUNTS                (10000)
#define adcUser_10UV_COUNTS                (10000000L)


/***************************************
* Global variables external identifier
***************************************/

extern uint8 adcUser_initVar;
extern volatile int16 adcUser_offset[adcUser_TOTAL_CHANNELS_NUM];
extern volatile int32 adcUser_countsPer10Volt[adcUser_TOTAL_CHANNELS_NUM];


/***************************************
*              Registers
***************************************/

#define adcUser_SAR_CTRL_REG                (*(reg32 *) adcUser_cy_psoc4_sar__SAR_CTRL )
#define adcUser_SAR_CTRL_PTR                ( (reg32 *) adcUser_cy_psoc4_sar__SAR_CTRL )

#define adcUser_SAR_SAMPLE_CTRL_REG         (*(reg32 *) adcUser_cy_psoc4_sar__SAR_SAMPLE_CTRL )
#define adcUser_SAR_SAMPLE_CTRL_PTR         ( (reg32 *) adcUser_cy_psoc4_sar__SAR_SAMPLE_CTRL )

#define adcUser_SAR_SAMPLE_TIME01_REG       (*(reg32 *) adcUser_cy_psoc4_sar__SAR_SAMPLE_TIME01 )
#define adcUser_SAR_SAMPLE_TIME01_PTR       ( (reg32 *) adcUser_cy_psoc4_sar__SAR_SAMPLE_TIME01 )

#define adcUser_SAR_SAMPLE_TIME23_REG       (*(reg32 *) adcUser_cy_psoc4_sar__SAR_SAMPLE_TIME23 )
#define adcUser_SAR_SAMPLE_TIME23_PTR       ( (reg32 *) adcUser_cy_psoc4_sar__SAR_SAMPLE_TIME23 )

#define adcUser_SAR_RANGE_THRES_REG         (*(reg32 *) adcUser_cy_psoc4_sar__SAR_RANGE_THRES )
#define adcUser_SAR_RANGE_THRES_PTR         ( (reg32 *) adcUser_cy_psoc4_sar__SAR_RANGE_THRES )

#define adcUser_SAR_RANGE_COND_REG          (*(reg32 *) adcUser_cy_psoc4_sar__SAR_RANGE_COND )
#define adcUser_SAR_RANGE_COND_PTR          ( (reg32 *) adcUser_cy_psoc4_sar__SAR_RANGE_COND )

#define adcUser_SAR_CHAN_EN_REG             (*(reg32 *) adcUser_cy_psoc4_sar__SAR_CHAN_EN )
#define adcUser_SAR_CHAN_EN_PTR             ( (reg32 *) adcUser_cy_psoc4_sar__SAR_CHAN_EN )

#define adcUser_SAR_START_CTRL_REG          (*(reg32 *) adcUser_cy_psoc4_sar__SAR_START_CTRL )
#define adcUser_SAR_START_CTRL_PTR          ( (reg32 *) adcUser_cy_psoc4_sar__SAR_START_CTRL )

#define adcUser_SAR_DFT_CTRL_REG            (*(reg32 *) adcUser_cy_psoc4_sar__SAR_DFT_CTRL )
#define adcUser_SAR_DFT_CTRL_PTR            ( (reg32 *) adcUser_cy_psoc4_sar__SAR_DFT_CTRL )

#define adcUser_SAR_CHAN_CONFIG_REG         (*(reg32 *) adcUser_cy_psoc4_sar__SAR_CHAN_CONFIG00 )
#define adcUser_SAR_CHAN_CONFIG_PTR         ( (reg32 *) adcUser_cy_psoc4_sar__SAR_CHAN_CONFIG00 )
#define adcUser_SAR_CHAN_CONFIG_IND         adcUser_cy_psoc4_sar__SAR_CHAN_CONFIG00

#define adcUser_SAR_CHAN_WORK_REG           (*(reg32 *) adcUser_cy_psoc4_sar__SAR_CHAN_WORK00 )
#define adcUser_SAR_CHAN_WORK_PTR           ( (reg32 *) adcUser_cy_psoc4_sar__SAR_CHAN_WORK00 )

#define adcUser_SAR_CHAN_RESULT_REG         (*(reg32 *) adcUser_cy_psoc4_sar__SAR_CHAN_RESULT00 )
#define adcUser_SAR_CHAN_RESULT_PTR         ( (reg32 *) adcUser_cy_psoc4_sar__SAR_CHAN_RESULT00 )
#define adcUser_SAR_CHAN_RESULT_IND         adcUser_cy_psoc4_sar__SAR_CHAN_RESULT00

#define adcUser_SAR_CHAN0_RESULT_REG         (*(reg32 *) adcUser_cy_psoc4_sar__SAR_CHAN_RESULT00 )
#define adcUser_SAR_CHAN0_RESULT_PTR         ( (reg32 *) adcUser_cy_psoc4_sar__SAR_CHAN_RESULT00 )

#define adcUser_SAR_CHAN1_RESULT_REG         (*(reg32 *) adcUser_cy_psoc4_sar__SAR_CHAN_RESULT01 )
#define adcUser_SAR_CHAN1_RESULT_PTR         ( (reg32 *) adcUser_cy_psoc4_sar__SAR_CHAN_RESULT01 )

#define adcUser_SAR_CHAN2_RESULT_REG         (*(reg32 *) adcUser_cy_psoc4_sar__SAR_CHAN_RESULT02 )
#define adcUser_SAR_CHAN2_RESULT_PTR         ( (reg32 *) adcUser_cy_psoc4_sar__SAR_CHAN_RESULT02 )

#define adcUser_SAR_CHAN3_RESULT_REG         (*(reg32 *) adcUser_cy_psoc4_sar__SAR_CHAN_RESULT03 )
#define adcUser_SAR_CHAN3_RESULT_PTR         ( (reg32 *) adcUser_cy_psoc4_sar__SAR_CHAN_RESULT03 )

#define adcUser_SAR_CHAN4_RESULT_REG         (*(reg32 *) adcUser_cy_psoc4_sar__SAR_CHAN_RESULT04 )
#define adcUser_SAR_CHAN4_RESULT_PTR         ( (reg32 *) adcUser_cy_psoc4_sar__SAR_CHAN_RESULT04 )

#define adcUser_SAR_CHAN5_RESULT_REG         (*(reg32 *) adcUser_cy_psoc4_sar__SAR_CHAN_RESULT05 )
#define adcUser_SAR_CHAN5_RESULT_PTR         ( (reg32 *) adcUser_cy_psoc4_sar__SAR_CHAN_RESULT05 )

#define adcUser_SAR_CHAN6_RESULT_REG         (*(reg32 *) adcUser_cy_psoc4_sar__SAR_CHAN_RESULT06 )
#define adcUser_SAR_CHAN6_RESULT_PTR         ( (reg32 *) adcUser_cy_psoc4_sar__SAR_CHAN_RESULT06 )

#define adcUser_SAR_CHAN7_RESULT_REG         (*(reg32 *) adcUser_cy_psoc4_sar__SAR_CHAN_RESULT07 )
#define adcUser_SAR_CHAN7_RESULT_PTR         ( (reg32 *) adcUser_cy_psoc4_sar__SAR_CHAN_RESULT07 )

#if(adcUser_CY_SAR_IP_VER != adcUser_CY_SAR_IP_VER0)
    #define adcUser_SAR_CHAN8_RESULT_REG     (*(reg32 *) adcUser_cy_psoc4_sar__SAR_CHAN_RESULT08 )
    #define adcUser_SAR_CHAN8_RESULT_PTR     ( (reg32 *) adcUser_cy_psoc4_sar__SAR_CHAN_RESULT08 )

    #define adcUser_SAR_CHAN9_RESULT_REG     (*(reg32 *) adcUser_cy_psoc4_sar__SAR_CHAN_RESULT09 )
    #define adcUser_SAR_CHAN9_RESULT_PTR     ( (reg32 *) adcUser_cy_psoc4_sar__SAR_CHAN_RESULT09 )

    #define adcUser_SAR_CHAN10_RESULT_REG    (*(reg32 *) adcUser_cy_psoc4_sar__SAR_CHAN_RESULT10 )
    #define adcUser_SAR_CHAN10_RESULT_PTR    ( (reg32 *) adcUser_cy_psoc4_sar__SAR_CHAN_RESULT10 )

    #define adcUser_SAR_CHAN11_RESULT_REG    (*(reg32 *) adcUser_cy_psoc4_sar__SAR_CHAN_RESULT11 )
    #define adcUser_SAR_CHAN11_RESULT_PTR    ( (reg32 *) adcUser_cy_psoc4_sar__SAR_CHAN_RESULT11 )

    #define adcUser_SAR_CHAN12_RESULT_REG    (*(reg32 *) adcUser_cy_psoc4_sar__SAR_CHAN_RESULT12 )
    #define adcUser_SAR_CHAN12_RESULT_PTR    ( (reg32 *) adcUser_cy_psoc4_sar__SAR_CHAN_RESULT12 )

    #define adcUser_SAR_CHAN13_RESULT_REG    (*(reg32 *) adcUser_cy_psoc4_sar__SAR_CHAN_RESULT13 )
    #define adcUser_SAR_CHAN13_RESULT_PTR    ( (reg32 *) adcUser_cy_psoc4_sar__SAR_CHAN_RESULT13 )

    #define adcUser_SAR_CHAN14_RESULT_REG    (*(reg32 *) adcUser_cy_psoc4_sar__SAR_CHAN_RESULT14 )
    #define adcUser_SAR_CHAN14_RESULT_PTR    ( (reg32 *) adcUser_cy_psoc4_sar__SAR_CHAN_RESULT14 )

    #define adcUser_SAR_CHAN15_RESULT_REG    (*(reg32 *) adcUser_cy_psoc4_sar__SAR_CHAN_RESULT15 )
    #define adcUser_SAR_CHAN15_RESULT_PTR    ( (reg32 *) adcUser_cy_psoc4_sar__SAR_CHAN_RESULT15 )
#endif /* (adcUser_CY_SAR_IP_VER != adcUser_CY_SAR_IP_VER0) */

#define adcUser_SAR_CHAN_WORK_VALID_REG     (*(reg32 *) adcUser_cy_psoc4_sar__SAR_CHAN_WORK_VALID)
#define adcUser_SAR_CHAN_WORK_VALID_PTR     ( (reg32 *) adcUser_cy_psoc4_sar__SAR_CHAN_WORK_VALID)

#define adcUser_SAR_CHAN_RESULT_VALID_REG  ( *(reg32 *) adcUser_cy_psoc4_sar__SAR_CHAN_RESULT_VALID )
#define adcUser_SAR_CHAN_RESULT_VALID_PTR  ( (reg32 *) adcUser_cy_psoc4_sar__SAR_CHAN_RESULT_VALID )

#define adcUser_SAR_STATUS_REG              (*(reg32 *) adcUser_cy_psoc4_sar__SAR_STATUS )
#define adcUser_SAR_STATUS_PTR              ( (reg32 *) adcUser_cy_psoc4_sar__SAR_STATUS )

#define adcUser_SAR_AVG_START_REG           (*(reg32 *) adcUser_cy_psoc4_sar__SAR_AVG_STAT )
#define adcUser_SAR_AVG_START_PTR           ( (reg32 *) adcUser_cy_psoc4_sar__SAR_AVG_STAT )

#define adcUser_SAR_INTR_REG                (*(reg32 *) adcUser_cy_psoc4_sar__SAR_INTR )
#define adcUser_SAR_INTR_PTR                ( (reg32 *) adcUser_cy_psoc4_sar__SAR_INTR )

#define adcUser_SAR_INTR_SET_REG            (*(reg32 *) adcUser_cy_psoc4_sar__SAR_INTR_SET )
#define adcUser_SAR_INTR_SET_PTR            ( (reg32 *) adcUser_cy_psoc4_sar__SAR_INTR_SET )

#define adcUser_SAR_INTR_MASK_REG           (*(reg32 *) adcUser_cy_psoc4_sar__SAR_INTR_MASK )
#define adcUser_SAR_INTR_MASK_PTR           ( (reg32 *) adcUser_cy_psoc4_sar__SAR_INTR_MASK )

#define adcUser_SAR_INTR_MASKED_REG         (*(reg32 *) adcUser_cy_psoc4_sar__SAR_INTR_MASKED )
#define adcUser_SAR_INTR_MASKED_PTR         ( (reg32 *) adcUser_cy_psoc4_sar__SAR_INTR_MASKED )

#define adcUser_SAR_SATURATE_INTR_REG       (*(reg32 *) adcUser_cy_psoc4_sar__SAR_SATURATE_INTR )
#define adcUser_SAR_SATURATE_INTR_PTR       ( (reg32 *) adcUser_cy_psoc4_sar__SAR_SATURATE_INTR )

#define adcUser_SAR_SATURATE_INTR_SET_REG   (*(reg32 *) adcUser_cy_psoc4_sar__SAR_SATURATE_INTR_SET )
#define adcUser_SAR_SATURATE_INTR_SET_PTR   ( (reg32 *) adcUser_cy_psoc4_sar__SAR_SATURATE_INTR_SET )

#define adcUser_SAR_SATURATE_INTR_MASK_REG (*(reg32 *) adcUser_cy_psoc4_sar__SAR_SATURATE_INTR_MASK )
#define adcUser_SAR_SATURATE_INTR_MASK_PTR ( (reg32 *) adcUser_cy_psoc4_sar__SAR_SATURATE_INTR_MASK )

#define adcUser_SAR_SATURATE_INTR_MASKED_REG \
                                                 (*(reg32 *) adcUser_cy_psoc4_sar__SAR_SATURATE_INTR_MASKED )
#define adcUser_SAR_SATURATE_INTR_MASKED_PTR \
                                                 ( (reg32 *) adcUser_cy_psoc4_sar__SAR_SATURATE_INTR_MASKED )

#define adcUser_SAR_RANGE_INTR_REG          (*(reg32 *) adcUser_cy_psoc4_sar__SAR_RANGE_INTR )
#define adcUser_SAR_RANGE_INTR_PTR          ( (reg32 *) adcUser_cy_psoc4_sar__SAR_RANGE_INTR )

#define adcUser_SAR_RANGE_INTR_SET_REG      (*(reg32 *) adcUser_cy_psoc4_sar__SAR_RANGE_INTR_SET )
#define adcUser_SAR_RANGE_INTR_SET_PTR      ( (reg32 *) adcUser_cy_psoc4_sar__SAR_RANGE_INTR_SET )

#define adcUser_SAR_RANGE_INTR_MASK_REG     (*(reg32 *) adcUser_cy_psoc4_sar__SAR_RANGE_INTR_MASK )
#define adcUser_SAR_RANGE_INTR_MASK_PTR     ( (reg32 *) adcUser_cy_psoc4_sar__SAR_RANGE_INTR_MASK )

#define adcUser_SAR_RANGE_INTR_MASKED_REG   (*(reg32 *) adcUser_cy_psoc4_sar__SAR_RANGE_INTR_MASKED )
#define adcUser_SAR_RANGE_INTR_MASKED_PTR   ( (reg32 *) adcUser_cy_psoc4_sar__SAR_RANGE_INTR_MASKED )

#define adcUser_SAR_INTR_CAUSE_REG          (*(reg32 *) adcUser_cy_psoc4_sar__SAR_INTR_CAUSE )
#define adcUser_SAR_INTR_CAUSE_PTR          ( (reg32 *) adcUser_cy_psoc4_sar__SAR_INTR_CAUSE )

#if(adcUser_INJ_CHANNEL_ENABLED)
    #define adcUser_SAR_INJ_CHAN_CONFIG_REG \
                                                 (*(reg32 *) adcUser_cy_psoc4_sarmux_8__SAR_INJ_CHAN_CONFIG )
    #define adcUser_SAR_INJ_CHAN_CONFIG_PTR    \
                                                 ( (reg32 *) adcUser_cy_psoc4_sarmux_8__SAR_INJ_CHAN_CONFIG )

    #define adcUser_SAR_INJ_RESULT_REG    (*(reg32 *) adcUser_cy_psoc4_sarmux_8__SAR_INJ_RESULT )
    #define adcUser_SAR_INJ_RESULT_PTR    ( (reg32 *) adcUser_cy_psoc4_sarmux_8__SAR_INJ_RESULT )
#endif /* adcUser_INJ_CHANNEL_ENABLED */
    
#define adcUser_MUX_SWITCH0_REG           (*(reg32 *)  adcUser_cy_psoc4_sar__SAR_MUX_SWITCH0 )
#define adcUser_MUX_SWITCH0_PTR           ( (reg32 *)  adcUser_cy_psoc4_sar__SAR_MUX_SWITCH0 )

#define adcUser_MUX_SWITCH_HW_CTRL_REG    (*(reg32 *)  adcUser_cy_psoc4_sar__SAR_MUX_SWITCH_HW_CTRL )
#define adcUser_MUX_SWITCH_HW_CTRL_PTR    ( (reg32 *)  adcUser_cy_psoc4_sar__SAR_MUX_SWITCH_HW_CTRL )

#define adcUser_PUMP_CTRL_REG             (*(reg32 *)  adcUser_cy_psoc4_sar__SAR_PUMP_CTRL )
#define adcUser_PUMP_CTRL_PTR             ( (reg32 *)  adcUser_cy_psoc4_sar__SAR_PUMP_CTRL )

#define adcUser_ANA_TRIM_REG              (*(reg32 *)  adcUser_cy_psoc4_sar__SAR_ANA_TRIM )
#define adcUser_ANA_TRIM_PTR              ( (reg32 *)  adcUser_cy_psoc4_sar__SAR_ANA_TRIM )

#define adcUser_WOUNDING_REG              (*(reg32 *)  adcUser_cy_psoc4_sar__SAR_WOUNDING )
#define adcUser_WOUNDING_PTR              ( (reg32 *)  adcUser_cy_psoc4_sar__SAR_WOUNDING )


/**************************************
*       Register Constants
**************************************/
#define adcUser_INTC_NUMBER                (adcUser_IRQ__INTC_NUMBER)
#define adcUser_INTC_PRIOR_NUMBER          (adcUser_IRQ__INTC_PRIOR_NUM)

/* defines for CTRL register */
#define adcUser_VREF_INTERNAL1024          (0x00000040Lu)
#define adcUser_VREF_EXTERNAL              (0x00000050Lu)
#define adcUser_VREF_VDDA_2                (0x00000060Lu)
#define adcUser_VREF_VDDA                  (0x00000070Lu)
#define adcUser_VREF_INTERNAL1024BYPASSED  (0x000000C0Lu)
#define adcUser_VREF_VDDA_2BYPASSED        (0x000000E0Lu)
#define adcUser_VREF_INTERNALVREF          (0x00000040Lu)
#define adcUser_VREF_INTERNALVREFBYPASSED  (0x000000C0Lu)

#define adcUser_NEG_VSSA_KELVIN            (0x00000000Lu)
#define adcUser_NEG_VSSA                   (0x00000200Lu)
#define adcUser_NEG_VREF                   (0x00000E00Lu)
#if(adcUser_TOTAL_CHANNELS_NUM > 1u)
    #define adcUser_NEG_OTHER              (uint16)((uint16)adcUser_cy_psoc4_sarmux_8__VNEG0 << 9u)
#else
    #define adcUser_NEG_OTHER              (0)
#endif /* adcUser_TOTAL_CHANNELS_NUM > 1u */

#define adcUser_SAR_HW_CTRL_NEGVREF        (0x00002000Lu)

#define adcUser_BOOSTPUMP_EN               (0x00100000Lu)

#define adcUser_NORMAL_PWR                 (0x00000000Lu)
#define adcUser_HALF_PWR                   (0x01000000Lu)
#define adcUser_MORE_PWR                   (0x02000000Lu)
#define adcUser_QUARTER_PWR                (0x03000000Lu)
#define adcUser_DEEPSLEEP_ON               (0x08000000Lu)

#define adcUser_DSI_SYNC_CONFIG            (0x10000000Lu)
#define adcUser_DSI_MODE                   (0x20000000Lu)
#define adcUser_SWITCH_DISABLE             (0x40000000Lu)
#define adcUser_ENABLE                     (0x80000000Lu)

/* defines for STATUS register */
#define adcUser_STATUS_BUSY                (0x80000000Lu)

/* defines for SAMPLE_CTRL register */
#define adcUser_ALT_RESOLUTION_10BIT       (0x00000001Lu)
#define adcUser_ALT_RESOLUTION_8BIT        (0x00000000Lu)

#define adcUser_DATA_ALIGN_LEFT            (0x00000002Lu)
#define adcUser_DATA_ALIGN_RIGHT           (0x00000000Lu)

#define adcUser_SE_SIGNED_RESULT           (0x00000004Lu)
#define adcUser_SE_UNSIGNED_RESULT         (0x00000000Lu)

#define adcUser_DIFF_SIGNED_RESULT         (0x00000008Lu)
#define adcUser_DIFF_UNSIGNED_RESULT       (0x00000000Lu)

#define adcUser_AVG_CNT_OFFSET             (4u)
#define adcUser_AVG_CNT_MASK               (0x00000070Lu)
#define adcUser_AVG_SHIFT                  (0x00000080Lu)

#define adcUser_CONTINUOUS_EN              (0x00010000Lu)
#define adcUser_DSI_TRIGGER_EN             (0x00020000Lu)
#define adcUser_DSI_TRIGGER_LEVEL          (0x00040000Lu)
#define adcUser_DSI_SYNC_TRIGGER           (0x00080000Lu)
#define adcUser_EOS_DSI_OUT_EN             (0x80000000Lu)

/* defines for SAMPLE_TIME01 / SAMPLE_TIME23 registers */
#define adcUser_SAMPLE_TIME13_OFFSET       (16u)
#define adcUser_SAMPLE_TIME02_MASK         (0x000003FFLu)
#define adcUser_SAMPLE_TIME13_MASK         (0x03FF0000Lu)

/* defines for RANGE_THRES registers */
#define adcUser_RANGE_HIGH_OFFSET          (16u)
#define adcUser_RANGE_HIGH_MASK            (0xFFFF0000Lu)
#define adcUser_RANGE_LOW_MASK             (0x0000FFFFLu)

/* defines for RANGE_COND register */
/* Compare mode setting constants:
*    BELOW   - Result < Low_Limit
*    INSIDE  - Low_Limit <= Result < High_Limit
*    ABOVE   - High_Limit <= Result
*    OUTSIDE - (Result < Low_Limit) or (High_Limit <= Result)
*/
#define adcUser_CMP_MODE_BELOW             (0x00000000Lu)
#define adcUser_CMP_MODE_INSIDE            (0x40000000Lu)
#define adcUser_CMP_MODE_ABOVE             (0x80000000Lu)
#define adcUser_CMP_MODE_OUTSIDE           (0xC0000000Lu)
#define adcUser_CMP_OFFSET                 (30u)

/* defines for _START_CTRL register */
#define adcUser_FW_TRIGGER                 (0x00000001Lu)

/* defines for DFT_CTRL register */
#define adcUser_DLY_INC                    (0x00000001Lu)
#define adcUser_HIZ                        (0x00000002Lu)
#define adcUser_DFT_INC_MASK               (0x000F0000Lu)
#define adcUser_DFT_OUTC_MASK              (0x00700000Lu)
#define adcUser_SEL_CSEL_DFT_MASK          (0x0F000000Lu)

/* configuration for clock speed > 9 Mhz based on
* characterization results
*/
#define adcUser_SEL_CSEL_DFT_CHAR          (0x03000000Lu)
#define adcUser_EN_CSEL_DFT                (0x10000000Lu)
#define adcUser_DCEN                       (0x20000000Lu)
#define adcUser_ADFT_OVERRIDE              (0x80000000Lu)

/* defines for CHAN_CONFIG / DIE_CHAN_CONFIG register
*  and channelsConfig parameter
*/
#define adcUser_SARMUX_VIRT_SELECT         (0x00000070Lu)
#define adcUser_DIFFERENTIAL_EN            (0x00000100Lu)
#define adcUser_ALT_RESOLUTION_ON          (0x00000200Lu)
#define adcUser_AVERAGING_EN               (0x00000400Lu)

#define adcUser_SAMPLE_TIME_SEL_SHIFT      (12u)
#define adcUser_SAMPLE_TIME_SEL_MASK       (0x00003000Lu)

#define adcUser_CHANNEL_CONFIG_MASK        (0x00003700Lu)

/* for CHAN_CONFIG only */
#define adcUser_DSI_OUT_EN                 (0x80000000Lu)

/* for INJ_CHAN_CONFIG only */
#define adcUser_INJ_TAILGATING             (0x40000000Lu)
#define adcUser_INJ_CHAN_EN                (0x80000000Lu)

/* defines for CHAN_WORK register */
#define adcUser_SAR_WRK_MAX_12BIT          (0x00001000Lu)
#define adcUser_SAR_WRK_MAX_10BIT          (0x00000400Lu)
#define adcUser_SAR_WRK_MAX_8BIT           (0x00000100Lu)

/* defines for CHAN_RESULT register */
#define adcUser_RESULT_MASK                (0x0000FFFFLu)
#define adcUser_SATURATE_INTR_MIR          (0x20000000Lu)
#define adcUser_RANGE_INTR_MIR             (0x40000000Lu)
#define adcUser_CHAN_RESULT_VALID_MIR      (0x80000000Lu)

/* defines for INTR_MASK register */
#define adcUser_EOS_MASK                   (0x00000001Lu)
#define adcUser_OVERFLOW_MASK              (0x00000002Lu)
#define adcUser_FW_COLLISION_MASK          (0x00000004Lu)
#define adcUser_DSI_COLLISION_MASK         (0x00000008Lu)
#define adcUser_INJ_EOC_MASK               (0x00000010Lu)
#define adcUser_INJ_SATURATE_MASK          (0x00000020Lu)
#define adcUser_INJ_RANGE_MASK             (0x00000040Lu)
#define adcUser_INJ_COLLISION_MASK         (0x00000080Lu)

/* defines for INJ_RESULT register */
#define adcUser_INJ_COLLISION_INTR_MIR     (0x10000000Lu)
#define adcUser_INJ_SATURATE_INTR_MIR      (0x20000000Lu)
#define adcUser_INJ_RANGE_INTR_MIR         (0x40000000Lu)
#define adcUser_INJ_EOC_INTR_MIR           (0x80000000Lu)

/* defines for MUX_SWITCH0 register */
#define adcUser_MUX_FW_VSSA_VMINUS         (0x00010000Lu)

/* defines for PUMP_CTRL register */
#define adcUser_PUMP_CTRL_ENABLED          (0x80000000Lu)

/* additional defines for channelsConfig parameter */
#define adcUser_IS_SATURATE_EN_MASK        (0x00000001Lu)
#define adcUser_IS_RANGE_CTRL_EN_MASK      (0x00000002Lu)

/* defines for WOUNDING register */
#define adcUser_WOUNDING_12BIT             (0x00000000Lu)
#define adcUser_WOUNDING_10BIT             (0x00000001Lu)
#define adcUser_WOUNDING_8BIT              (0x00000002Lu)

/* Trim value based on characterization */
#define adcUser_TRIM_COEF                  (2u)

#if(adcUser_MAX_RESOLUTION == adcUser_RESOLUTION_10)
    #define adcUser_ALT_WOUNDING           adcUser_WOUNDING_10BIT
#else
    #define adcUser_ALT_WOUNDING           adcUser_WOUNDING_8BIT
#endif /* adcUser_MAX_RESOLUTION == adcUser_RESOLUTION_10 */

#if(adcUser_DEFAULT_VREF_SEL == adcUser__VDDA_2)
    #define adcUser_DEFAULT_VREF_SOURCE    adcUser_VREF_VDDA_2
#elif(adcUser_DEFAULT_VREF_SEL == adcUser__VDDA)
    #define adcUser_DEFAULT_VREF_SOURCE    adcUser_VREF_VDDA
#elif(adcUser_DEFAULT_VREF_SEL == adcUser__INTERNAL1024)
    #define adcUser_DEFAULT_VREF_SOURCE    adcUser_VREF_INTERNAL1024
#elif(adcUser_DEFAULT_VREF_SEL == adcUser__INTERNAL1024BYPASSED)
    #define adcUser_DEFAULT_VREF_SOURCE    adcUser_VREF_INTERNAL1024BYPASSED
#elif(adcUser_DEFAULT_VREF_SEL == adcUser__INTERNALVREF)
    #define adcUser_DEFAULT_VREF_SOURCE    adcUser_VREF_INTERNALVREF
#elif(adcUser_DEFAULT_VREF_SEL == adcUser__INTERNALVREFBYPASSED)
    #define adcUser_DEFAULT_VREF_SOURCE    adcUser_VREF_INTERNALVREFBYPASSED
#elif(adcUser_DEFAULT_VREF_SEL == adcUser__VDDA_2BYPASSED)
    #define adcUser_DEFAULT_VREF_SOURCE    adcUser_VREF_VDDA_2BYPASSED
#else
    #define adcUser_DEFAULT_VREF_SOURCE    adcUser_VREF_EXTERNAL
#endif /* adcUser_DEFAULT_VREF_SEL == adcUser__VDDA_2 */

#if(adcUser_DEFAULT_NEG_INPUT_SEL == adcUser__VSS)
    /* Connect NEG input of SARADC to VSSA close to the SARADC for single channel mode */
    #if(adcUser_TOTAL_CHANNELS_NUM == 1u)
        #define adcUser_DEFAULT_SE_NEG_INPUT    adcUser_NEG_VSSA
    #else
        #define adcUser_DEFAULT_SE_NEG_INPUT    adcUser_NEG_VSSA_KELVIN
    #endif /* (adcUser_TOTAL_CHANNELS_NUM == 1u) */
    /* Do not connect VSSA to VMINUS when one channel in differential mode used */
    #if((adcUser_TOTAL_CHANNELS_NUM == 1u) && (adcUser_CHANNELS_MODE != 0u))
        #define adcUser_DEFAULT_MUX_SWITCH0     0u
    #else    /* miltiple channels or one single channel */
        #define adcUser_DEFAULT_MUX_SWITCH0     adcUser_MUX_FW_VSSA_VMINUS
    #endif /* (adcUser_TOTAL_CHANNELS_NUM == 1u) */
#elif(adcUser_DEFAULT_NEG_INPUT_SEL == adcUser__VREF)
    /* Do not connect VNEG to VREF when one channel in differential mode used */
    #if((adcUser_TOTAL_CHANNELS_NUM == 1u) && (adcUser_CHANNELS_MODE != 0u))
        #define adcUser_DEFAULT_SE_NEG_INPUT    0u
    #else    /* miltiple channels or one single channel */
        #define adcUser_DEFAULT_SE_NEG_INPUT    adcUser_NEG_VREF
    #endif /* (adcUser_TOTAL_CHANNELS_NUM == 1u) */
    #define adcUser_DEFAULT_MUX_SWITCH0     0u
#elif (adcUser_SINGLE_PRESENT != 0u)
    #define adcUser_DEFAULT_SE_NEG_INPUT    adcUser_NEG_OTHER
    #define adcUser_DEFAULT_MUX_SWITCH0     0u
#else
    #define adcUser_DEFAULT_SE_NEG_INPUT    0u
    #define adcUser_DEFAULT_MUX_SWITCH0     0u
#endif /* adcUser_DEFAULT_NEG_INPUT_SEL == adcUser__VREF */

/* If the SAR is configured for multiple channels, always set SAR_HW_CTRL_NEGVREF to 1 */
#if(adcUser_TOTAL_CHANNELS_NUM == 1u)
    #define adcUser_DEFAULT_HW_CTRL_NEGVREF 0u
#else
    #define adcUser_DEFAULT_HW_CTRL_NEGVREF adcUser_SAR_HW_CTRL_NEGVREF
#endif /* (adcUser_TOTAL_CHANNELS_NUM == 1u) */


#if(adcUser_DEFAULT_ALT_RESOLUTION_SEL == adcUser__RES8)
    #define adcUser_DEFAULT_ALT_RESOLUTION     (adcUser_ALT_RESOLUTION_8BIT)
    #define adcUser_DEFAULT_MAX_WRK_ALT        (adcUser_SAR_WRK_MAX_8BIT)
#else
    #define adcUser_DEFAULT_ALT_RESOLUTION     (adcUser_ALT_RESOLUTION_10BIT)
    #define adcUser_DEFAULT_MAX_WRK_ALT        (adcUser_SAR_WRK_MAX_10BIT)
#endif /* End adcUser_DEFAULT_ALT_RESOLUTION_SEL == adcUser__RES8 */

#if(adcUser_DEFAULT_JUSTIFICATION_SEL == adcUser__RIGHT)
    #define adcUser_DEFAULT_JUSTIFICATION  adcUser_DATA_ALIGN_RIGHT
#else
    #define adcUser_DEFAULT_JUSTIFICATION  adcUser_DATA_ALIGN_LEFT
#endif /* adcUser_DEFAULT_JUSTIFICATION_SEL == adcUser__RIGHT */

#if(adcUser_DEFAULT_DIFF_RESULT_FORMAT_SEL == adcUser__FSIGNED)
    #define adcUser_DEFAULT_DIFF_RESULT_FORMAT adcUser_DIFF_SIGNED_RESULT
#else
    #define adcUser_DEFAULT_DIFF_RESULT_FORMAT adcUser_DIFF_UNSIGNED_RESULT
#endif /* adcUser_DEFAULT_DIFF_RESULT_FORMAT_SEL == adcUser__FSIGNED */

#if(adcUser_DEFAULT_SE_RESULT_FORMAT_SEL == adcUser__FSIGNED)
    #define adcUser_DEFAULT_SE_RESULT_FORMAT adcUser_SE_SIGNED_RESULT
#else
    #define adcUser_DEFAULT_SE_RESULT_FORMAT adcUser_SE_UNSIGNED_RESULT
#endif /* adcUser_DEFAULT_SE_RESULT_FORMAT_SEL == adcUser__FSIGNED */

#if(adcUser_DEFAULT_SAMPLE_MODE_SEL == adcUser__FREERUNNING)
    #define adcUser_DSI_TRIGGER        0u
#else /* Firmware trigger */
    #define adcUser_DSI_TRIGGER        (adcUser_DSI_TRIGGER_EN | adcUser_DSI_SYNC_TRIGGER)
#endif /* End adcUser_DEFAULT_SAMPLE_MODE == adcUser__FREERUNNING */

#if(adcUser_INJ_CHANNEL_ENABLED)
    #define adcUser_SAR_INTR_MASK      (adcUser_EOS_MASK | adcUser_INJ_EOC_MASK)
#else
    #define adcUser_SAR_INTR_MASK      (adcUser_EOS_MASK)
#endif /* adcUser_INJ_CHANNEL_ENABLED*/

#if(adcUser_DEFAULT_AVG_MODE == adcUser__FIXEDRESOLUTION)
    #define adcUser_AVG_SHIFT_MODE     adcUser_AVG_SHIFT
#else
    #define adcUser_AVG_SHIFT_MODE     0u
#endif /* End adcUser_DEFAULT_AVG_MODE */

#define adcUser_COMPARE_MODE           (uint32)((uint32)(adcUser_DEFAULT_COMPARE_MODE) \
                                                << adcUser_CMP_OFFSET)

#if(adcUser_TOTAL_CHANNELS_NUM > 1u)
    #define adcUser_DEFAULT_SWITCH_CONF    0u
#else /* Disable SAR sequencer from enabling routing switches in single channel mode */
    #define adcUser_DEFAULT_SWITCH_CONF    adcUser_SWITCH_DISABLE
#endif /* End adcUser_TOTAL_CHANNELS_NUM > 1 */

#define adcUser_DEFAULT_POWER \
       ((adcUser_NOMINAL_CLOCK_FREQ > (adcUser_MAX_FREQUENCY / 4)) ? adcUser_NORMAL_PWR : \
       ((adcUser_NOMINAL_CLOCK_FREQ > (adcUser_MAX_FREQUENCY / 8)) ? adcUser_HALF_PWR : \
                                                                                       adcUser_QUARTER_PWR))

#define adcUser_DEFAULT_CTRL_REG_CFG       (adcUser_DEFAULT_VREF_SOURCE \
                                                   | adcUser_DEFAULT_SE_NEG_INPUT \
                                                   | adcUser_DEFAULT_HW_CTRL_NEGVREF \
                                                   | adcUser_DEFAULT_POWER \
                                                   | adcUser_DSI_SYNC_CONFIG \
                                                   | adcUser_DEFAULT_SWITCH_CONF)

#define adcUser_DEFAULT_SAMPLE_CTRL_REG_CFG (adcUser_DEFAULT_DIFF_RESULT_FORMAT \
                                                    | adcUser_DEFAULT_SE_RESULT_FORMAT \
                                                    | adcUser_DEFAULT_JUSTIFICATION \
                                                    | adcUser_DEFAULT_ALT_RESOLUTION \
                                           | (uint8)(adcUser_DEFAULT_AVG_SAMPLES_NUM \
                                                   << adcUser_AVG_CNT_OFFSET) \
                                                    | adcUser_AVG_SHIFT_MODE \
                                                    | adcUser_DSI_TRIGGER \
                                                    | adcUser_EOS_DSI_OUT_EN)

#define adcUser_DEFAULT_RANGE_THRES_REG_CFG (adcUser_DEFAULT_LOW_LIMIT \
            | (uint32)((uint32)adcUser_DEFAULT_HIGH_LIMIT << adcUser_RANGE_HIGH_OFFSET))

#define adcUser_DEFAULT_SAMPLE_TIME01_REG_CFG (adcUser_DEFAULT_ACLKS_NUM \
            | (uint32)((uint32)adcUser_DEFAULT_BCLKS_NUM << adcUser_SAMPLE_TIME13_OFFSET))

#define adcUser_DEFAULT_SAMPLE_TIME23_REG_CFG (adcUser_DEFAULT_CCLKS_NUM \
            | (uint32)((uint32)adcUser_DEFAULT_DCLKS_NUM << adcUser_SAMPLE_TIME13_OFFSET))


#endif /* End CY_ADC_SAR_SEQ_adcUser_H */


/* [] END OF FILE */
