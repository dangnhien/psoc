/*******************************************************************************
* File Name: adc_measure_resister.h
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

#if !defined(CY_ADC_SAR_SEQ_adc_measure_resister_H)
#define CY_ADC_SAR_SEQ_adc_measure_resister_H

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
} adc_measure_resister_BACKUP_STRUCT;


/**************************************
*    Enumerated Types and Parameters
**************************************/

/*  Clock Source setting constants */
#define adc_measure_resister__EXTERNAL 0
#define adc_measure_resister__INTERNAL 1

/*  Sample Mode setting constants */
#define adc_measure_resister__FREERUNNING 0
#define adc_measure_resister__HARDWARESOC 1

/*  Reference type setting constants */
#define adc_measure_resister__VDDA_2 0
#define adc_measure_resister__VDDA 1
#define adc_measure_resister__INTERNAL1024 2
#define adc_measure_resister__INTERNAL1024BYPASSED 3
#define adc_measure_resister__INTERNALVREF 4
#define adc_measure_resister__INTERNALVREFBYPASSED 5
#define adc_measure_resister__VDDA_2BYPASSED 6
#define adc_measure_resister__EXTERNALVREF 7

/* Input buffer gain setting constants */
#define adc_measure_resister__DISABLED 0
#define adc_measure_resister__ONE 1
#define adc_measure_resister__TWO 2
#define adc_measure_resister__FOUR 3
#define adc_measure_resister__EIGHT 4
#define adc_measure_resister__SIXTEEN 5

/* Negative input setting sonstants in single ended mode */
#define adc_measure_resister__VSS 0
#define adc_measure_resister__VREF 1
#define adc_measure_resister__OTHER 2

/* Compare mode setting constants:
*    Mode0 - Disable
*    Mode1 - Result < Low_Limit
*    Mode2 - Low_Limit <= Result < High_Limit
*    Mode3 - High_Limit <= Result
*    Mode4 - (Result < Low_Limit) or (High_Limit <= Result)
*/
#define adc_measure_resister__MODE0 0
#define adc_measure_resister__MODE1 1
#define adc_measure_resister__MODE2 2
#define adc_measure_resister__MODE3 3

#define adc_measure_resister__RES8 0
#define adc_measure_resister__RES10 1

#define adc_measure_resister__RIGHT 0
#define adc_measure_resister__LEFT 1

#define adc_measure_resister__FSIGNED 1
#define adc_measure_resister__FUNSIGNED 0

#define adc_measure_resister__ACCUMULATE 0
#define adc_measure_resister__FIXEDRESOLUTION 1



/***************************************
*   Conditional Compilation Parameters
****************************************/ 

#define adc_measure_resister_CY_SAR_IP_VER0               	(0u)
#define adc_measure_resister_CY_SAR_IP_VER1               	(1u)

#if (CY_PSOC4_4100 || CY_PSOC4_4200)
    #define adc_measure_resister_CY_SAR_IP_VER              (adc_measure_resister_CY_SAR_IP_VER0)
#else /* Other devices */
    #define adc_measure_resister_CY_SAR_IP_VER              (adc_measure_resister_CY_SAR_IP_VER1)
#endif  /* (CY_PSOC4_4100 || CY_PSOC4_4200) */


/***************************************
*    Initial Parameter Constants
***************************************/
#define adc_measure_resister_DEFAULT_SAMPLE_MODE_SEL        (0u)
#define adc_measure_resister_DEFAULT_VREF_SEL               (1u)
#define adc_measure_resister_DEFAULT_NEG_INPUT_SEL          (0u)
#define adc_measure_resister_DEFAULT_ALT_RESOLUTION_SEL     (0u)
#define adc_measure_resister_DEFAULT_JUSTIFICATION_SEL      (0u)
#define adc_measure_resister_DEFAULT_DIFF_RESULT_FORMAT_SEL (1u)
#define adc_measure_resister_DEFAULT_SE_RESULT_FORMAT_SEL   (1u)
#define adc_measure_resister_DEFAULT_CLOCK_SOURCE           (1u)
#define adc_measure_resister_DEFAULT_VREF_MV_VALUE          (5000)
#define adc_measure_resister_DEFAULT_BUFFER_GAIN            (0u)
#define adc_measure_resister_DEFAULT_AVG_SAMPLES_NUM        (0u)
#define adc_measure_resister_DEFAULT_AVG_SAMPLES_DIV        (0u < 4u) ? (int16)(0x100u >> (7u - 0u)) : (int16)(0x100u >> 4u)
#define adc_measure_resister_DEFAULT_AVG_MODE               (1u)
#define adc_measure_resister_MAX_RESOLUTION                 (12u)
#define adc_measure_resister_DEFAULT_LOW_LIMIT              (0u)
#define adc_measure_resister_DEFAULT_HIGH_LIMIT             (2047u)
#define adc_measure_resister_DEFAULT_COMPARE_MODE           (0u)
#define adc_measure_resister_DEFAULT_ACLKS_NUM              (2u)
#define adc_measure_resister_DEFAULT_BCLKS_NUM              (2u)
#define adc_measure_resister_DEFAULT_CCLKS_NUM              (2u)
#define adc_measure_resister_DEFAULT_DCLKS_NUM              (2u)
#define adc_measure_resister_TOTAL_CHANNELS_NUM             (4u)
#define adc_measure_resister_SEQUENCED_CHANNELS_NUM         (4u)
#define adc_measure_resister_DEFAULT_EN_CHANNELS            (15u)
#define adc_measure_resister_NOMINAL_CLOCK_FREQ             (8000000)
#define adc_measure_resister_INJ_CHANNEL_ENABLED            (0u)
#define adc_measure_resister_IRQ_REMOVE                     (0u)

/* Determines whether the configuration contains external negative input. */
#define adc_measure_resister_SINGLE_PRESENT                 (0u)
#define adc_measure_resister_CHANNELS_MODE                  (0u)
#define adc_measure_resister_MAX_CHANNELS_EN_MASK           (0xffffu >> (16u - adc_measure_resister_SEQUENCED_CHANNELS_NUM))


/***************************************
*        Function Prototypes
***************************************/

void adc_measure_resister_Start(void);
void adc_measure_resister_Stop(void);
void adc_measure_resister_Init(void);
void adc_measure_resister_Enable(void);
void adc_measure_resister_StartConvert(void);
void adc_measure_resister_StopConvert(void);
uint32 adc_measure_resister_IsEndConversion(uint32 retMode);
int16 adc_measure_resister_GetResult16(uint32 chan);
void adc_measure_resister_SetChanMask(uint32 mask);
void adc_measure_resister_SetLowLimit(uint32 lowLimit);
void adc_measure_resister_SetHighLimit(uint32 highLimit);
void adc_measure_resister_SetLimitMask(uint32 mask);
void adc_measure_resister_SetSatMask(uint32 mask);
void adc_measure_resister_SetOffset(uint32 chan, int16 offset);
void adc_measure_resister_SetGain(uint32 chan, int32 adcGain);
#if(adc_measure_resister_INJ_CHANNEL_ENABLED)
    void adc_measure_resister_EnableInjection(void);
#endif /* adc_measure_resister_INJ_CHANNEL_ENABLED */
#if(adc_measure_resister_DEFAULT_JUSTIFICATION_SEL == adc_measure_resister__RIGHT)
    int16 adc_measure_resister_CountsTo_mVolts(uint32 chan, int16 adcCounts);
    int32 adc_measure_resister_CountsTo_uVolts(uint32 chan, int16 adcCounts);
    float32 adc_measure_resister_CountsTo_Volts(uint32 chan, int16 adcCounts);
#endif /* End adc_measure_resister_DEFAULT_JUSTIFICATION_SEL == adc_measure_resister__RIGHT */
void adc_measure_resister_Sleep(void);
void adc_measure_resister_Wakeup(void);
void adc_measure_resister_SaveConfig(void);
void adc_measure_resister_RestoreConfig(void);

CY_ISR_PROTO( adc_measure_resister_ISR );


/**************************************
*           API Constants
**************************************/
/* Constants for Sleep mode states */
#define adc_measure_resister_DISABLED                   (0x00u)
#define adc_measure_resister_ENABLED                    (0x01u)
#define adc_measure_resister_STARTED                    (0x02u)
#define adc_measure_resister_BOOSTPUMP_ENABLED          (0x04u)

/*   Constants for IsEndConversion() "retMode" parameter  */
#define adc_measure_resister_RETURN_STATUS              (0x01u)
#define adc_measure_resister_WAIT_FOR_RESULT            (0x02u)
#define adc_measure_resister_RETURN_STATUS_INJ          (0x04u)
#define adc_measure_resister_WAIT_FOR_RESULT_INJ        (0x08u)

#define adc_measure_resister_MAX_FREQUENCY              (18000000)       /*18Mhz*/

#define adc_measure_resister_RESOLUTION_12              (12u)
#define adc_measure_resister_RESOLUTION_10              (10u)
#define adc_measure_resister_RESOLUTION_8               (8u)

#define adc_measure_resister_10US_DELAY                 (10u)

#define adc_measure_resister_10V_COUNTS                 (10.0F)
#define adc_measure_resister_10MV_COUNTS                (10000)
#define adc_measure_resister_10UV_COUNTS                (10000000L)


/***************************************
* Global variables external identifier
***************************************/

extern uint8 adc_measure_resister_initVar;
extern volatile int16 adc_measure_resister_offset[adc_measure_resister_TOTAL_CHANNELS_NUM];
extern volatile int32 adc_measure_resister_countsPer10Volt[adc_measure_resister_TOTAL_CHANNELS_NUM];


/***************************************
*              Registers
***************************************/

#define adc_measure_resister_SAR_CTRL_REG                (*(reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_CTRL )
#define adc_measure_resister_SAR_CTRL_PTR                ( (reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_CTRL )

#define adc_measure_resister_SAR_SAMPLE_CTRL_REG         (*(reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_SAMPLE_CTRL )
#define adc_measure_resister_SAR_SAMPLE_CTRL_PTR         ( (reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_SAMPLE_CTRL )

#define adc_measure_resister_SAR_SAMPLE_TIME01_REG       (*(reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_SAMPLE_TIME01 )
#define adc_measure_resister_SAR_SAMPLE_TIME01_PTR       ( (reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_SAMPLE_TIME01 )

#define adc_measure_resister_SAR_SAMPLE_TIME23_REG       (*(reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_SAMPLE_TIME23 )
#define adc_measure_resister_SAR_SAMPLE_TIME23_PTR       ( (reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_SAMPLE_TIME23 )

#define adc_measure_resister_SAR_RANGE_THRES_REG         (*(reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_RANGE_THRES )
#define adc_measure_resister_SAR_RANGE_THRES_PTR         ( (reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_RANGE_THRES )

#define adc_measure_resister_SAR_RANGE_COND_REG          (*(reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_RANGE_COND )
#define adc_measure_resister_SAR_RANGE_COND_PTR          ( (reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_RANGE_COND )

#define adc_measure_resister_SAR_CHAN_EN_REG             (*(reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_CHAN_EN )
#define adc_measure_resister_SAR_CHAN_EN_PTR             ( (reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_CHAN_EN )

#define adc_measure_resister_SAR_START_CTRL_REG          (*(reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_START_CTRL )
#define adc_measure_resister_SAR_START_CTRL_PTR          ( (reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_START_CTRL )

#define adc_measure_resister_SAR_DFT_CTRL_REG            (*(reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_DFT_CTRL )
#define adc_measure_resister_SAR_DFT_CTRL_PTR            ( (reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_DFT_CTRL )

#define adc_measure_resister_SAR_CHAN_CONFIG_REG         (*(reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_CHAN_CONFIG00 )
#define adc_measure_resister_SAR_CHAN_CONFIG_PTR         ( (reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_CHAN_CONFIG00 )
#define adc_measure_resister_SAR_CHAN_CONFIG_IND         adc_measure_resister_cy_psoc4_sar__SAR_CHAN_CONFIG00

#define adc_measure_resister_SAR_CHAN_WORK_REG           (*(reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_CHAN_WORK00 )
#define adc_measure_resister_SAR_CHAN_WORK_PTR           ( (reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_CHAN_WORK00 )

#define adc_measure_resister_SAR_CHAN_RESULT_REG         (*(reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_CHAN_RESULT00 )
#define adc_measure_resister_SAR_CHAN_RESULT_PTR         ( (reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_CHAN_RESULT00 )
#define adc_measure_resister_SAR_CHAN_RESULT_IND         adc_measure_resister_cy_psoc4_sar__SAR_CHAN_RESULT00

#define adc_measure_resister_SAR_CHAN0_RESULT_REG         (*(reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_CHAN_RESULT00 )
#define adc_measure_resister_SAR_CHAN0_RESULT_PTR         ( (reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_CHAN_RESULT00 )

#define adc_measure_resister_SAR_CHAN1_RESULT_REG         (*(reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_CHAN_RESULT01 )
#define adc_measure_resister_SAR_CHAN1_RESULT_PTR         ( (reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_CHAN_RESULT01 )

#define adc_measure_resister_SAR_CHAN2_RESULT_REG         (*(reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_CHAN_RESULT02 )
#define adc_measure_resister_SAR_CHAN2_RESULT_PTR         ( (reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_CHAN_RESULT02 )

#define adc_measure_resister_SAR_CHAN3_RESULT_REG         (*(reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_CHAN_RESULT03 )
#define adc_measure_resister_SAR_CHAN3_RESULT_PTR         ( (reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_CHAN_RESULT03 )

#define adc_measure_resister_SAR_CHAN4_RESULT_REG         (*(reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_CHAN_RESULT04 )
#define adc_measure_resister_SAR_CHAN4_RESULT_PTR         ( (reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_CHAN_RESULT04 )

#define adc_measure_resister_SAR_CHAN5_RESULT_REG         (*(reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_CHAN_RESULT05 )
#define adc_measure_resister_SAR_CHAN5_RESULT_PTR         ( (reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_CHAN_RESULT05 )

#define adc_measure_resister_SAR_CHAN6_RESULT_REG         (*(reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_CHAN_RESULT06 )
#define adc_measure_resister_SAR_CHAN6_RESULT_PTR         ( (reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_CHAN_RESULT06 )

#define adc_measure_resister_SAR_CHAN7_RESULT_REG         (*(reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_CHAN_RESULT07 )
#define adc_measure_resister_SAR_CHAN7_RESULT_PTR         ( (reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_CHAN_RESULT07 )

#if(adc_measure_resister_CY_SAR_IP_VER != adc_measure_resister_CY_SAR_IP_VER0)
    #define adc_measure_resister_SAR_CHAN8_RESULT_REG     (*(reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_CHAN_RESULT08 )
    #define adc_measure_resister_SAR_CHAN8_RESULT_PTR     ( (reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_CHAN_RESULT08 )

    #define adc_measure_resister_SAR_CHAN9_RESULT_REG     (*(reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_CHAN_RESULT09 )
    #define adc_measure_resister_SAR_CHAN9_RESULT_PTR     ( (reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_CHAN_RESULT09 )

    #define adc_measure_resister_SAR_CHAN10_RESULT_REG    (*(reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_CHAN_RESULT10 )
    #define adc_measure_resister_SAR_CHAN10_RESULT_PTR    ( (reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_CHAN_RESULT10 )

    #define adc_measure_resister_SAR_CHAN11_RESULT_REG    (*(reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_CHAN_RESULT11 )
    #define adc_measure_resister_SAR_CHAN11_RESULT_PTR    ( (reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_CHAN_RESULT11 )

    #define adc_measure_resister_SAR_CHAN12_RESULT_REG    (*(reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_CHAN_RESULT12 )
    #define adc_measure_resister_SAR_CHAN12_RESULT_PTR    ( (reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_CHAN_RESULT12 )

    #define adc_measure_resister_SAR_CHAN13_RESULT_REG    (*(reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_CHAN_RESULT13 )
    #define adc_measure_resister_SAR_CHAN13_RESULT_PTR    ( (reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_CHAN_RESULT13 )

    #define adc_measure_resister_SAR_CHAN14_RESULT_REG    (*(reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_CHAN_RESULT14 )
    #define adc_measure_resister_SAR_CHAN14_RESULT_PTR    ( (reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_CHAN_RESULT14 )

    #define adc_measure_resister_SAR_CHAN15_RESULT_REG    (*(reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_CHAN_RESULT15 )
    #define adc_measure_resister_SAR_CHAN15_RESULT_PTR    ( (reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_CHAN_RESULT15 )
#endif /* (adc_measure_resister_CY_SAR_IP_VER != adc_measure_resister_CY_SAR_IP_VER0) */

#define adc_measure_resister_SAR_CHAN_WORK_VALID_REG     (*(reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_CHAN_WORK_VALID)
#define adc_measure_resister_SAR_CHAN_WORK_VALID_PTR     ( (reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_CHAN_WORK_VALID)

#define adc_measure_resister_SAR_CHAN_RESULT_VALID_REG  ( *(reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_CHAN_RESULT_VALID )
#define adc_measure_resister_SAR_CHAN_RESULT_VALID_PTR  ( (reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_CHAN_RESULT_VALID )

#define adc_measure_resister_SAR_STATUS_REG              (*(reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_STATUS )
#define adc_measure_resister_SAR_STATUS_PTR              ( (reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_STATUS )

#define adc_measure_resister_SAR_AVG_START_REG           (*(reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_AVG_STAT )
#define adc_measure_resister_SAR_AVG_START_PTR           ( (reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_AVG_STAT )

#define adc_measure_resister_SAR_INTR_REG                (*(reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_INTR )
#define adc_measure_resister_SAR_INTR_PTR                ( (reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_INTR )

#define adc_measure_resister_SAR_INTR_SET_REG            (*(reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_INTR_SET )
#define adc_measure_resister_SAR_INTR_SET_PTR            ( (reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_INTR_SET )

#define adc_measure_resister_SAR_INTR_MASK_REG           (*(reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_INTR_MASK )
#define adc_measure_resister_SAR_INTR_MASK_PTR           ( (reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_INTR_MASK )

#define adc_measure_resister_SAR_INTR_MASKED_REG         (*(reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_INTR_MASKED )
#define adc_measure_resister_SAR_INTR_MASKED_PTR         ( (reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_INTR_MASKED )

#define adc_measure_resister_SAR_SATURATE_INTR_REG       (*(reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_SATURATE_INTR )
#define adc_measure_resister_SAR_SATURATE_INTR_PTR       ( (reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_SATURATE_INTR )

#define adc_measure_resister_SAR_SATURATE_INTR_SET_REG   (*(reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_SATURATE_INTR_SET )
#define adc_measure_resister_SAR_SATURATE_INTR_SET_PTR   ( (reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_SATURATE_INTR_SET )

#define adc_measure_resister_SAR_SATURATE_INTR_MASK_REG (*(reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_SATURATE_INTR_MASK )
#define adc_measure_resister_SAR_SATURATE_INTR_MASK_PTR ( (reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_SATURATE_INTR_MASK )

#define adc_measure_resister_SAR_SATURATE_INTR_MASKED_REG \
                                                 (*(reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_SATURATE_INTR_MASKED )
#define adc_measure_resister_SAR_SATURATE_INTR_MASKED_PTR \
                                                 ( (reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_SATURATE_INTR_MASKED )

#define adc_measure_resister_SAR_RANGE_INTR_REG          (*(reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_RANGE_INTR )
#define adc_measure_resister_SAR_RANGE_INTR_PTR          ( (reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_RANGE_INTR )

#define adc_measure_resister_SAR_RANGE_INTR_SET_REG      (*(reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_RANGE_INTR_SET )
#define adc_measure_resister_SAR_RANGE_INTR_SET_PTR      ( (reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_RANGE_INTR_SET )

#define adc_measure_resister_SAR_RANGE_INTR_MASK_REG     (*(reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_RANGE_INTR_MASK )
#define adc_measure_resister_SAR_RANGE_INTR_MASK_PTR     ( (reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_RANGE_INTR_MASK )

#define adc_measure_resister_SAR_RANGE_INTR_MASKED_REG   (*(reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_RANGE_INTR_MASKED )
#define adc_measure_resister_SAR_RANGE_INTR_MASKED_PTR   ( (reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_RANGE_INTR_MASKED )

#define adc_measure_resister_SAR_INTR_CAUSE_REG          (*(reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_INTR_CAUSE )
#define adc_measure_resister_SAR_INTR_CAUSE_PTR          ( (reg32 *) adc_measure_resister_cy_psoc4_sar__SAR_INTR_CAUSE )

#if(adc_measure_resister_INJ_CHANNEL_ENABLED)
    #define adc_measure_resister_SAR_INJ_CHAN_CONFIG_REG \
                                                 (*(reg32 *) adc_measure_resister_cy_psoc4_sarmux_8__SAR_INJ_CHAN_CONFIG )
    #define adc_measure_resister_SAR_INJ_CHAN_CONFIG_PTR    \
                                                 ( (reg32 *) adc_measure_resister_cy_psoc4_sarmux_8__SAR_INJ_CHAN_CONFIG )

    #define adc_measure_resister_SAR_INJ_RESULT_REG    (*(reg32 *) adc_measure_resister_cy_psoc4_sarmux_8__SAR_INJ_RESULT )
    #define adc_measure_resister_SAR_INJ_RESULT_PTR    ( (reg32 *) adc_measure_resister_cy_psoc4_sarmux_8__SAR_INJ_RESULT )
#endif /* adc_measure_resister_INJ_CHANNEL_ENABLED */
    
#define adc_measure_resister_MUX_SWITCH0_REG           (*(reg32 *)  adc_measure_resister_cy_psoc4_sar__SAR_MUX_SWITCH0 )
#define adc_measure_resister_MUX_SWITCH0_PTR           ( (reg32 *)  adc_measure_resister_cy_psoc4_sar__SAR_MUX_SWITCH0 )

#define adc_measure_resister_MUX_SWITCH_HW_CTRL_REG    (*(reg32 *)  adc_measure_resister_cy_psoc4_sar__SAR_MUX_SWITCH_HW_CTRL )
#define adc_measure_resister_MUX_SWITCH_HW_CTRL_PTR    ( (reg32 *)  adc_measure_resister_cy_psoc4_sar__SAR_MUX_SWITCH_HW_CTRL )

#define adc_measure_resister_PUMP_CTRL_REG             (*(reg32 *)  adc_measure_resister_cy_psoc4_sar__SAR_PUMP_CTRL )
#define adc_measure_resister_PUMP_CTRL_PTR             ( (reg32 *)  adc_measure_resister_cy_psoc4_sar__SAR_PUMP_CTRL )

#define adc_measure_resister_ANA_TRIM_REG              (*(reg32 *)  adc_measure_resister_cy_psoc4_sar__SAR_ANA_TRIM )
#define adc_measure_resister_ANA_TRIM_PTR              ( (reg32 *)  adc_measure_resister_cy_psoc4_sar__SAR_ANA_TRIM )

#define adc_measure_resister_WOUNDING_REG              (*(reg32 *)  adc_measure_resister_cy_psoc4_sar__SAR_WOUNDING )
#define adc_measure_resister_WOUNDING_PTR              ( (reg32 *)  adc_measure_resister_cy_psoc4_sar__SAR_WOUNDING )


/**************************************
*       Register Constants
**************************************/
#define adc_measure_resister_INTC_NUMBER                (adc_measure_resister_IRQ__INTC_NUMBER)
#define adc_measure_resister_INTC_PRIOR_NUMBER          (adc_measure_resister_IRQ__INTC_PRIOR_NUM)

/* defines for CTRL register */
#define adc_measure_resister_VREF_INTERNAL1024          (0x00000040Lu)
#define adc_measure_resister_VREF_EXTERNAL              (0x00000050Lu)
#define adc_measure_resister_VREF_VDDA_2                (0x00000060Lu)
#define adc_measure_resister_VREF_VDDA                  (0x00000070Lu)
#define adc_measure_resister_VREF_INTERNAL1024BYPASSED  (0x000000C0Lu)
#define adc_measure_resister_VREF_VDDA_2BYPASSED        (0x000000E0Lu)
#define adc_measure_resister_VREF_INTERNALVREF          (0x00000040Lu)
#define adc_measure_resister_VREF_INTERNALVREFBYPASSED  (0x000000C0Lu)

#define adc_measure_resister_NEG_VSSA_KELVIN            (0x00000000Lu)
#define adc_measure_resister_NEG_VSSA                   (0x00000200Lu)
#define adc_measure_resister_NEG_VREF                   (0x00000E00Lu)
#if(adc_measure_resister_TOTAL_CHANNELS_NUM > 1u)
    #define adc_measure_resister_NEG_OTHER              (uint16)((uint16)adc_measure_resister_cy_psoc4_sarmux_8__VNEG0 << 9u)
#else
    #define adc_measure_resister_NEG_OTHER              (0)
#endif /* adc_measure_resister_TOTAL_CHANNELS_NUM > 1u */

#define adc_measure_resister_SAR_HW_CTRL_NEGVREF        (0x00002000Lu)

#define adc_measure_resister_BOOSTPUMP_EN               (0x00100000Lu)

#define adc_measure_resister_NORMAL_PWR                 (0x00000000Lu)
#define adc_measure_resister_HALF_PWR                   (0x01000000Lu)
#define adc_measure_resister_MORE_PWR                   (0x02000000Lu)
#define adc_measure_resister_QUARTER_PWR                (0x03000000Lu)
#define adc_measure_resister_DEEPSLEEP_ON               (0x08000000Lu)

#define adc_measure_resister_DSI_SYNC_CONFIG            (0x10000000Lu)
#define adc_measure_resister_DSI_MODE                   (0x20000000Lu)
#define adc_measure_resister_SWITCH_DISABLE             (0x40000000Lu)
#define adc_measure_resister_ENABLE                     (0x80000000Lu)

/* defines for STATUS register */
#define adc_measure_resister_STATUS_BUSY                (0x80000000Lu)

/* defines for SAMPLE_CTRL register */
#define adc_measure_resister_ALT_RESOLUTION_10BIT       (0x00000001Lu)
#define adc_measure_resister_ALT_RESOLUTION_8BIT        (0x00000000Lu)

#define adc_measure_resister_DATA_ALIGN_LEFT            (0x00000002Lu)
#define adc_measure_resister_DATA_ALIGN_RIGHT           (0x00000000Lu)

#define adc_measure_resister_SE_SIGNED_RESULT           (0x00000004Lu)
#define adc_measure_resister_SE_UNSIGNED_RESULT         (0x00000000Lu)

#define adc_measure_resister_DIFF_SIGNED_RESULT         (0x00000008Lu)
#define adc_measure_resister_DIFF_UNSIGNED_RESULT       (0x00000000Lu)

#define adc_measure_resister_AVG_CNT_OFFSET             (4u)
#define adc_measure_resister_AVG_CNT_MASK               (0x00000070Lu)
#define adc_measure_resister_AVG_SHIFT                  (0x00000080Lu)

#define adc_measure_resister_CONTINUOUS_EN              (0x00010000Lu)
#define adc_measure_resister_DSI_TRIGGER_EN             (0x00020000Lu)
#define adc_measure_resister_DSI_TRIGGER_LEVEL          (0x00040000Lu)
#define adc_measure_resister_DSI_SYNC_TRIGGER           (0x00080000Lu)
#define adc_measure_resister_EOS_DSI_OUT_EN             (0x80000000Lu)

/* defines for SAMPLE_TIME01 / SAMPLE_TIME23 registers */
#define adc_measure_resister_SAMPLE_TIME13_OFFSET       (16u)
#define adc_measure_resister_SAMPLE_TIME02_MASK         (0x000003FFLu)
#define adc_measure_resister_SAMPLE_TIME13_MASK         (0x03FF0000Lu)

/* defines for RANGE_THRES registers */
#define adc_measure_resister_RANGE_HIGH_OFFSET          (16u)
#define adc_measure_resister_RANGE_HIGH_MASK            (0xFFFF0000Lu)
#define adc_measure_resister_RANGE_LOW_MASK             (0x0000FFFFLu)

/* defines for RANGE_COND register */
/* Compare mode setting constants:
*    BELOW   - Result < Low_Limit
*    INSIDE  - Low_Limit <= Result < High_Limit
*    ABOVE   - High_Limit <= Result
*    OUTSIDE - (Result < Low_Limit) or (High_Limit <= Result)
*/
#define adc_measure_resister_CMP_MODE_BELOW             (0x00000000Lu)
#define adc_measure_resister_CMP_MODE_INSIDE            (0x40000000Lu)
#define adc_measure_resister_CMP_MODE_ABOVE             (0x80000000Lu)
#define adc_measure_resister_CMP_MODE_OUTSIDE           (0xC0000000Lu)
#define adc_measure_resister_CMP_OFFSET                 (30u)

/* defines for _START_CTRL register */
#define adc_measure_resister_FW_TRIGGER                 (0x00000001Lu)

/* defines for DFT_CTRL register */
#define adc_measure_resister_DLY_INC                    (0x00000001Lu)
#define adc_measure_resister_HIZ                        (0x00000002Lu)
#define adc_measure_resister_DFT_INC_MASK               (0x000F0000Lu)
#define adc_measure_resister_DFT_OUTC_MASK              (0x00700000Lu)
#define adc_measure_resister_SEL_CSEL_DFT_MASK          (0x0F000000Lu)

/* configuration for clock speed > 9 Mhz based on
* characterization results
*/
#define adc_measure_resister_SEL_CSEL_DFT_CHAR          (0x03000000Lu)
#define adc_measure_resister_EN_CSEL_DFT                (0x10000000Lu)
#define adc_measure_resister_DCEN                       (0x20000000Lu)
#define adc_measure_resister_ADFT_OVERRIDE              (0x80000000Lu)

/* defines for CHAN_CONFIG / DIE_CHAN_CONFIG register
*  and channelsConfig parameter
*/
#define adc_measure_resister_SARMUX_VIRT_SELECT         (0x00000070Lu)
#define adc_measure_resister_DIFFERENTIAL_EN            (0x00000100Lu)
#define adc_measure_resister_ALT_RESOLUTION_ON          (0x00000200Lu)
#define adc_measure_resister_AVERAGING_EN               (0x00000400Lu)

#define adc_measure_resister_SAMPLE_TIME_SEL_SHIFT      (12u)
#define adc_measure_resister_SAMPLE_TIME_SEL_MASK       (0x00003000Lu)

#define adc_measure_resister_CHANNEL_CONFIG_MASK        (0x00003700Lu)

/* for CHAN_CONFIG only */
#define adc_measure_resister_DSI_OUT_EN                 (0x80000000Lu)

/* for INJ_CHAN_CONFIG only */
#define adc_measure_resister_INJ_TAILGATING             (0x40000000Lu)
#define adc_measure_resister_INJ_CHAN_EN                (0x80000000Lu)

/* defines for CHAN_WORK register */
#define adc_measure_resister_SAR_WRK_MAX_12BIT          (0x00001000Lu)
#define adc_measure_resister_SAR_WRK_MAX_10BIT          (0x00000400Lu)
#define adc_measure_resister_SAR_WRK_MAX_8BIT           (0x00000100Lu)

/* defines for CHAN_RESULT register */
#define adc_measure_resister_RESULT_MASK                (0x0000FFFFLu)
#define adc_measure_resister_SATURATE_INTR_MIR          (0x20000000Lu)
#define adc_measure_resister_RANGE_INTR_MIR             (0x40000000Lu)
#define adc_measure_resister_CHAN_RESULT_VALID_MIR      (0x80000000Lu)

/* defines for INTR_MASK register */
#define adc_measure_resister_EOS_MASK                   (0x00000001Lu)
#define adc_measure_resister_OVERFLOW_MASK              (0x00000002Lu)
#define adc_measure_resister_FW_COLLISION_MASK          (0x00000004Lu)
#define adc_measure_resister_DSI_COLLISION_MASK         (0x00000008Lu)
#define adc_measure_resister_INJ_EOC_MASK               (0x00000010Lu)
#define adc_measure_resister_INJ_SATURATE_MASK          (0x00000020Lu)
#define adc_measure_resister_INJ_RANGE_MASK             (0x00000040Lu)
#define adc_measure_resister_INJ_COLLISION_MASK         (0x00000080Lu)

/* defines for INJ_RESULT register */
#define adc_measure_resister_INJ_COLLISION_INTR_MIR     (0x10000000Lu)
#define adc_measure_resister_INJ_SATURATE_INTR_MIR      (0x20000000Lu)
#define adc_measure_resister_INJ_RANGE_INTR_MIR         (0x40000000Lu)
#define adc_measure_resister_INJ_EOC_INTR_MIR           (0x80000000Lu)

/* defines for MUX_SWITCH0 register */
#define adc_measure_resister_MUX_FW_VSSA_VMINUS         (0x00010000Lu)

/* defines for PUMP_CTRL register */
#define adc_measure_resister_PUMP_CTRL_ENABLED          (0x80000000Lu)

/* additional defines for channelsConfig parameter */
#define adc_measure_resister_IS_SATURATE_EN_MASK        (0x00000001Lu)
#define adc_measure_resister_IS_RANGE_CTRL_EN_MASK      (0x00000002Lu)

/* defines for WOUNDING register */
#define adc_measure_resister_WOUNDING_12BIT             (0x00000000Lu)
#define adc_measure_resister_WOUNDING_10BIT             (0x00000001Lu)
#define adc_measure_resister_WOUNDING_8BIT              (0x00000002Lu)

/* Trim value based on characterization */
#define adc_measure_resister_TRIM_COEF                  (2u)

#if(adc_measure_resister_MAX_RESOLUTION == adc_measure_resister_RESOLUTION_10)
    #define adc_measure_resister_ALT_WOUNDING           adc_measure_resister_WOUNDING_10BIT
#else
    #define adc_measure_resister_ALT_WOUNDING           adc_measure_resister_WOUNDING_8BIT
#endif /* adc_measure_resister_MAX_RESOLUTION == adc_measure_resister_RESOLUTION_10 */

#if(adc_measure_resister_DEFAULT_VREF_SEL == adc_measure_resister__VDDA_2)
    #define adc_measure_resister_DEFAULT_VREF_SOURCE    adc_measure_resister_VREF_VDDA_2
#elif(adc_measure_resister_DEFAULT_VREF_SEL == adc_measure_resister__VDDA)
    #define adc_measure_resister_DEFAULT_VREF_SOURCE    adc_measure_resister_VREF_VDDA
#elif(adc_measure_resister_DEFAULT_VREF_SEL == adc_measure_resister__INTERNAL1024)
    #define adc_measure_resister_DEFAULT_VREF_SOURCE    adc_measure_resister_VREF_INTERNAL1024
#elif(adc_measure_resister_DEFAULT_VREF_SEL == adc_measure_resister__INTERNAL1024BYPASSED)
    #define adc_measure_resister_DEFAULT_VREF_SOURCE    adc_measure_resister_VREF_INTERNAL1024BYPASSED
#elif(adc_measure_resister_DEFAULT_VREF_SEL == adc_measure_resister__INTERNALVREF)
    #define adc_measure_resister_DEFAULT_VREF_SOURCE    adc_measure_resister_VREF_INTERNALVREF
#elif(adc_measure_resister_DEFAULT_VREF_SEL == adc_measure_resister__INTERNALVREFBYPASSED)
    #define adc_measure_resister_DEFAULT_VREF_SOURCE    adc_measure_resister_VREF_INTERNALVREFBYPASSED
#elif(adc_measure_resister_DEFAULT_VREF_SEL == adc_measure_resister__VDDA_2BYPASSED)
    #define adc_measure_resister_DEFAULT_VREF_SOURCE    adc_measure_resister_VREF_VDDA_2BYPASSED
#else
    #define adc_measure_resister_DEFAULT_VREF_SOURCE    adc_measure_resister_VREF_EXTERNAL
#endif /* adc_measure_resister_DEFAULT_VREF_SEL == adc_measure_resister__VDDA_2 */

#if(adc_measure_resister_DEFAULT_NEG_INPUT_SEL == adc_measure_resister__VSS)
    /* Connect NEG input of SARADC to VSSA close to the SARADC for single channel mode */
    #if(adc_measure_resister_TOTAL_CHANNELS_NUM == 1u)
        #define adc_measure_resister_DEFAULT_SE_NEG_INPUT    adc_measure_resister_NEG_VSSA
    #else
        #define adc_measure_resister_DEFAULT_SE_NEG_INPUT    adc_measure_resister_NEG_VSSA_KELVIN
    #endif /* (adc_measure_resister_TOTAL_CHANNELS_NUM == 1u) */
    /* Do not connect VSSA to VMINUS when one channel in differential mode used */
    #if((adc_measure_resister_TOTAL_CHANNELS_NUM == 1u) && (adc_measure_resister_CHANNELS_MODE != 0u))
        #define adc_measure_resister_DEFAULT_MUX_SWITCH0     0u
    #else    /* miltiple channels or one single channel */
        #define adc_measure_resister_DEFAULT_MUX_SWITCH0     adc_measure_resister_MUX_FW_VSSA_VMINUS
    #endif /* (adc_measure_resister_TOTAL_CHANNELS_NUM == 1u) */
#elif(adc_measure_resister_DEFAULT_NEG_INPUT_SEL == adc_measure_resister__VREF)
    /* Do not connect VNEG to VREF when one channel in differential mode used */
    #if((adc_measure_resister_TOTAL_CHANNELS_NUM == 1u) && (adc_measure_resister_CHANNELS_MODE != 0u))
        #define adc_measure_resister_DEFAULT_SE_NEG_INPUT    0u
    #else    /* miltiple channels or one single channel */
        #define adc_measure_resister_DEFAULT_SE_NEG_INPUT    adc_measure_resister_NEG_VREF
    #endif /* (adc_measure_resister_TOTAL_CHANNELS_NUM == 1u) */
    #define adc_measure_resister_DEFAULT_MUX_SWITCH0     0u
#elif (adc_measure_resister_SINGLE_PRESENT != 0u)
    #define adc_measure_resister_DEFAULT_SE_NEG_INPUT    adc_measure_resister_NEG_OTHER
    #define adc_measure_resister_DEFAULT_MUX_SWITCH0     0u
#else
    #define adc_measure_resister_DEFAULT_SE_NEG_INPUT    0u
    #define adc_measure_resister_DEFAULT_MUX_SWITCH0     0u
#endif /* adc_measure_resister_DEFAULT_NEG_INPUT_SEL == adc_measure_resister__VREF */

/* If the SAR is configured for multiple channels, always set SAR_HW_CTRL_NEGVREF to 1 */
#if(adc_measure_resister_TOTAL_CHANNELS_NUM == 1u)
    #define adc_measure_resister_DEFAULT_HW_CTRL_NEGVREF 0u
#else
    #define adc_measure_resister_DEFAULT_HW_CTRL_NEGVREF adc_measure_resister_SAR_HW_CTRL_NEGVREF
#endif /* (adc_measure_resister_TOTAL_CHANNELS_NUM == 1u) */


#if(adc_measure_resister_DEFAULT_ALT_RESOLUTION_SEL == adc_measure_resister__RES8)
    #define adc_measure_resister_DEFAULT_ALT_RESOLUTION     (adc_measure_resister_ALT_RESOLUTION_8BIT)
    #define adc_measure_resister_DEFAULT_MAX_WRK_ALT        (adc_measure_resister_SAR_WRK_MAX_8BIT)
#else
    #define adc_measure_resister_DEFAULT_ALT_RESOLUTION     (adc_measure_resister_ALT_RESOLUTION_10BIT)
    #define adc_measure_resister_DEFAULT_MAX_WRK_ALT        (adc_measure_resister_SAR_WRK_MAX_10BIT)
#endif /* End adc_measure_resister_DEFAULT_ALT_RESOLUTION_SEL == adc_measure_resister__RES8 */

#if(adc_measure_resister_DEFAULT_JUSTIFICATION_SEL == adc_measure_resister__RIGHT)
    #define adc_measure_resister_DEFAULT_JUSTIFICATION  adc_measure_resister_DATA_ALIGN_RIGHT
#else
    #define adc_measure_resister_DEFAULT_JUSTIFICATION  adc_measure_resister_DATA_ALIGN_LEFT
#endif /* adc_measure_resister_DEFAULT_JUSTIFICATION_SEL == adc_measure_resister__RIGHT */

#if(adc_measure_resister_DEFAULT_DIFF_RESULT_FORMAT_SEL == adc_measure_resister__FSIGNED)
    #define adc_measure_resister_DEFAULT_DIFF_RESULT_FORMAT adc_measure_resister_DIFF_SIGNED_RESULT
#else
    #define adc_measure_resister_DEFAULT_DIFF_RESULT_FORMAT adc_measure_resister_DIFF_UNSIGNED_RESULT
#endif /* adc_measure_resister_DEFAULT_DIFF_RESULT_FORMAT_SEL == adc_measure_resister__FSIGNED */

#if(adc_measure_resister_DEFAULT_SE_RESULT_FORMAT_SEL == adc_measure_resister__FSIGNED)
    #define adc_measure_resister_DEFAULT_SE_RESULT_FORMAT adc_measure_resister_SE_SIGNED_RESULT
#else
    #define adc_measure_resister_DEFAULT_SE_RESULT_FORMAT adc_measure_resister_SE_UNSIGNED_RESULT
#endif /* adc_measure_resister_DEFAULT_SE_RESULT_FORMAT_SEL == adc_measure_resister__FSIGNED */

#if(adc_measure_resister_DEFAULT_SAMPLE_MODE_SEL == adc_measure_resister__FREERUNNING)
    #define adc_measure_resister_DSI_TRIGGER        0u
#else /* Firmware trigger */
    #define adc_measure_resister_DSI_TRIGGER        (adc_measure_resister_DSI_TRIGGER_EN | adc_measure_resister_DSI_SYNC_TRIGGER)
#endif /* End adc_measure_resister_DEFAULT_SAMPLE_MODE == adc_measure_resister__FREERUNNING */

#if(adc_measure_resister_INJ_CHANNEL_ENABLED)
    #define adc_measure_resister_SAR_INTR_MASK      (adc_measure_resister_EOS_MASK | adc_measure_resister_INJ_EOC_MASK)
#else
    #define adc_measure_resister_SAR_INTR_MASK      (adc_measure_resister_EOS_MASK)
#endif /* adc_measure_resister_INJ_CHANNEL_ENABLED*/

#if(adc_measure_resister_DEFAULT_AVG_MODE == adc_measure_resister__FIXEDRESOLUTION)
    #define adc_measure_resister_AVG_SHIFT_MODE     adc_measure_resister_AVG_SHIFT
#else
    #define adc_measure_resister_AVG_SHIFT_MODE     0u
#endif /* End adc_measure_resister_DEFAULT_AVG_MODE */

#define adc_measure_resister_COMPARE_MODE           (uint32)((uint32)(adc_measure_resister_DEFAULT_COMPARE_MODE) \
                                                << adc_measure_resister_CMP_OFFSET)

#if(adc_measure_resister_TOTAL_CHANNELS_NUM > 1u)
    #define adc_measure_resister_DEFAULT_SWITCH_CONF    0u
#else /* Disable SAR sequencer from enabling routing switches in single channel mode */
    #define adc_measure_resister_DEFAULT_SWITCH_CONF    adc_measure_resister_SWITCH_DISABLE
#endif /* End adc_measure_resister_TOTAL_CHANNELS_NUM > 1 */

#define adc_measure_resister_DEFAULT_POWER \
       ((adc_measure_resister_NOMINAL_CLOCK_FREQ > (adc_measure_resister_MAX_FREQUENCY / 4)) ? adc_measure_resister_NORMAL_PWR : \
       ((adc_measure_resister_NOMINAL_CLOCK_FREQ > (adc_measure_resister_MAX_FREQUENCY / 8)) ? adc_measure_resister_HALF_PWR : \
                                                                                       adc_measure_resister_QUARTER_PWR))

#define adc_measure_resister_DEFAULT_CTRL_REG_CFG       (adc_measure_resister_DEFAULT_VREF_SOURCE \
                                                   | adc_measure_resister_DEFAULT_SE_NEG_INPUT \
                                                   | adc_measure_resister_DEFAULT_HW_CTRL_NEGVREF \
                                                   | adc_measure_resister_DEFAULT_POWER \
                                                   | adc_measure_resister_DSI_SYNC_CONFIG \
                                                   | adc_measure_resister_DEFAULT_SWITCH_CONF)

#define adc_measure_resister_DEFAULT_SAMPLE_CTRL_REG_CFG (adc_measure_resister_DEFAULT_DIFF_RESULT_FORMAT \
                                                    | adc_measure_resister_DEFAULT_SE_RESULT_FORMAT \
                                                    | adc_measure_resister_DEFAULT_JUSTIFICATION \
                                                    | adc_measure_resister_DEFAULT_ALT_RESOLUTION \
                                           | (uint8)(adc_measure_resister_DEFAULT_AVG_SAMPLES_NUM \
                                                   << adc_measure_resister_AVG_CNT_OFFSET) \
                                                    | adc_measure_resister_AVG_SHIFT_MODE \
                                                    | adc_measure_resister_DSI_TRIGGER \
                                                    | adc_measure_resister_EOS_DSI_OUT_EN)

#define adc_measure_resister_DEFAULT_RANGE_THRES_REG_CFG (adc_measure_resister_DEFAULT_LOW_LIMIT \
            | (uint32)((uint32)adc_measure_resister_DEFAULT_HIGH_LIMIT << adc_measure_resister_RANGE_HIGH_OFFSET))

#define adc_measure_resister_DEFAULT_SAMPLE_TIME01_REG_CFG (adc_measure_resister_DEFAULT_ACLKS_NUM \
            | (uint32)((uint32)adc_measure_resister_DEFAULT_BCLKS_NUM << adc_measure_resister_SAMPLE_TIME13_OFFSET))

#define adc_measure_resister_DEFAULT_SAMPLE_TIME23_REG_CFG (adc_measure_resister_DEFAULT_CCLKS_NUM \
            | (uint32)((uint32)adc_measure_resister_DEFAULT_DCLKS_NUM << adc_measure_resister_SAMPLE_TIME13_OFFSET))


#endif /* End CY_ADC_SAR_SEQ_adc_measure_resister_H */


/* [] END OF FILE */
