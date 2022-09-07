/*******************************************************************************
* File Name: adc_measure_resister_PM.c
* Version 2.50
*
* Description:
*  This file provides Sleep/WakeUp APIs functionality.
*
* Note:
*
********************************************************************************
* Copyright 2008-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "adc_measure_resister.h"


/***************************************
* Local data allocation
***************************************/

static adc_measure_resister_BACKUP_STRUCT  adc_measure_resister_backup =
{
    adc_measure_resister_DISABLED,
    0u    
};


/*******************************************************************************
* Function Name: adc_measure_resister_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void adc_measure_resister_SaveConfig(void)
{
    /* All configuration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: adc_measure_resister_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void adc_measure_resister_RestoreConfig(void)
{
    /* All configuration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: adc_measure_resister_Sleep
********************************************************************************
*
* Summary:
*  Stops the ADC operation and saves the configuration registers and component
*  enable state. Should be called just prior to entering sleep.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  adc_measure_resister_backup - modified.
*
*******************************************************************************/
void adc_measure_resister_Sleep(void)
{
    /* During deepsleep/ hibernate mode keep SARMUX active, i.e. do not open
    *   all switches (disconnect), to be used for ADFT
    */
    adc_measure_resister_backup.dftRegVal = adc_measure_resister_SAR_DFT_CTRL_REG & (uint32)~adc_measure_resister_ADFT_OVERRIDE;
    adc_measure_resister_SAR_DFT_CTRL_REG |= adc_measure_resister_ADFT_OVERRIDE;
    if((adc_measure_resister_SAR_CTRL_REG  & adc_measure_resister_ENABLE) != 0u)
    {
        if((adc_measure_resister_SAR_SAMPLE_CTRL_REG & adc_measure_resister_CONTINUOUS_EN) != 0u)
        {
            adc_measure_resister_backup.enableState = adc_measure_resister_ENABLED | adc_measure_resister_STARTED;
        }
        else
        {
            adc_measure_resister_backup.enableState = adc_measure_resister_ENABLED;
        }
        adc_measure_resister_StopConvert();
        adc_measure_resister_Stop();
        
        /* Disable the SAR internal pump before entering the chip low power mode */
        if((adc_measure_resister_SAR_CTRL_REG & adc_measure_resister_BOOSTPUMP_EN) != 0u)
        {
            adc_measure_resister_SAR_CTRL_REG &= (uint32)~adc_measure_resister_BOOSTPUMP_EN;
            adc_measure_resister_backup.enableState |= adc_measure_resister_BOOSTPUMP_ENABLED;
        }
    }
    else
    {
        adc_measure_resister_backup.enableState = adc_measure_resister_DISABLED;
    }
}


/*******************************************************************************
* Function Name: adc_measure_resister_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component enable state and configuration registers.
*  This should be called just after awaking from sleep mode.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  adc_measure_resister_backup - used.
*
*******************************************************************************/
void adc_measure_resister_Wakeup(void)
{
    adc_measure_resister_SAR_DFT_CTRL_REG = adc_measure_resister_backup.dftRegVal;
    if(adc_measure_resister_backup.enableState != adc_measure_resister_DISABLED)
    {
        /* Enable the SAR internal pump  */
        if((adc_measure_resister_backup.enableState & adc_measure_resister_BOOSTPUMP_ENABLED) != 0u)
        {
            adc_measure_resister_SAR_CTRL_REG |= adc_measure_resister_BOOSTPUMP_EN;
        }
        adc_measure_resister_Enable();
        if((adc_measure_resister_backup.enableState & adc_measure_resister_STARTED) != 0u)
        {
            adc_measure_resister_StartConvert();
        }
    }
}
/* [] END OF FILE */
