/*******************************************************************************
* File Name: adcUser_PM.c
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

#include "adcUser.h"


/***************************************
* Local data allocation
***************************************/

static adcUser_BACKUP_STRUCT  adcUser_backup =
{
    adcUser_DISABLED,
    0u    
};


/*******************************************************************************
* Function Name: adcUser_SaveConfig
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
void adcUser_SaveConfig(void)
{
    /* All configuration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: adcUser_RestoreConfig
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
void adcUser_RestoreConfig(void)
{
    /* All configuration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: adcUser_Sleep
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
*  adcUser_backup - modified.
*
*******************************************************************************/
void adcUser_Sleep(void)
{
    /* During deepsleep/ hibernate mode keep SARMUX active, i.e. do not open
    *   all switches (disconnect), to be used for ADFT
    */
    adcUser_backup.dftRegVal = adcUser_SAR_DFT_CTRL_REG & (uint32)~adcUser_ADFT_OVERRIDE;
    adcUser_SAR_DFT_CTRL_REG |= adcUser_ADFT_OVERRIDE;
    if((adcUser_SAR_CTRL_REG  & adcUser_ENABLE) != 0u)
    {
        if((adcUser_SAR_SAMPLE_CTRL_REG & adcUser_CONTINUOUS_EN) != 0u)
        {
            adcUser_backup.enableState = adcUser_ENABLED | adcUser_STARTED;
        }
        else
        {
            adcUser_backup.enableState = adcUser_ENABLED;
        }
        adcUser_StopConvert();
        adcUser_Stop();
        
        /* Disable the SAR internal pump before entering the chip low power mode */
        if((adcUser_SAR_CTRL_REG & adcUser_BOOSTPUMP_EN) != 0u)
        {
            adcUser_SAR_CTRL_REG &= (uint32)~adcUser_BOOSTPUMP_EN;
            adcUser_backup.enableState |= adcUser_BOOSTPUMP_ENABLED;
        }
    }
    else
    {
        adcUser_backup.enableState = adcUser_DISABLED;
    }
}


/*******************************************************************************
* Function Name: adcUser_Wakeup
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
*  adcUser_backup - used.
*
*******************************************************************************/
void adcUser_Wakeup(void)
{
    adcUser_SAR_DFT_CTRL_REG = adcUser_backup.dftRegVal;
    if(adcUser_backup.enableState != adcUser_DISABLED)
    {
        /* Enable the SAR internal pump  */
        if((adcUser_backup.enableState & adcUser_BOOSTPUMP_ENABLED) != 0u)
        {
            adcUser_SAR_CTRL_REG |= adcUser_BOOSTPUMP_EN;
        }
        adcUser_Enable();
        if((adcUser_backup.enableState & adcUser_STARTED) != 0u)
        {
            adcUser_StartConvert();
        }
    }
}
/* [] END OF FILE */
