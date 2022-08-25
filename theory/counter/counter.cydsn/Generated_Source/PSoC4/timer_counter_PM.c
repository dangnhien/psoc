/*******************************************************************************
* File Name: timer_counter_PM.c
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

#include "timer_counter.h"

static timer_counter_BACKUP_STRUCT timer_counter_backup;


/*******************************************************************************
* Function Name: timer_counter_SaveConfig
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
void timer_counter_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: timer_counter_Sleep
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
void timer_counter_Sleep(void)
{
    if(0u != (timer_counter_BLOCK_CONTROL_REG & timer_counter_MASK))
    {
        timer_counter_backup.enableState = 1u;
    }
    else
    {
        timer_counter_backup.enableState = 0u;
    }

    timer_counter_Stop();
    timer_counter_SaveConfig();
}


/*******************************************************************************
* Function Name: timer_counter_RestoreConfig
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
void timer_counter_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: timer_counter_Wakeup
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
void timer_counter_Wakeup(void)
{
    timer_counter_RestoreConfig();

    if(0u != timer_counter_backup.enableState)
    {
        timer_counter_Enable();
    }
}


/* [] END OF FILE */
