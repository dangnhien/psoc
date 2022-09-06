/*******************************************************************************
* File Name: pwm_PM.c
* Version 2.10
*
* Description:
*  This file contains the setup, control, and status commands to support
*  the component operations in the low power mode.
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

#include "pwm.h"

static pwm_BACKUP_STRUCT pwm_backup;


/*******************************************************************************
* Function Name: pwm_SaveConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to save here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void pwm_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: pwm_Sleep
********************************************************************************
*
* Summary:
*  Stops the component operation and saves the user configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void pwm_Sleep(void)
{
    if(0u != (pwm_BLOCK_CONTROL_REG & pwm_MASK))
    {
        pwm_backup.enableState = 1u;
    }
    else
    {
        pwm_backup.enableState = 0u;
    }

    pwm_Stop();
    pwm_SaveConfig();
}


/*******************************************************************************
* Function Name: pwm_RestoreConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to restore here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void pwm_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: pwm_Wakeup
********************************************************************************
*
* Summary:
*  Restores the user configuration and restores the enable state.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void pwm_Wakeup(void)
{
    pwm_RestoreConfig();

    if(0u != pwm_backup.enableState)
    {
        pwm_Enable();
    }
}


/* [] END OF FILE */
