/*******************************************************************************
* File Name: timer1_PM.c
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

#include "timer1.h"

static timer1_BACKUP_STRUCT timer1_backup;


/*******************************************************************************
* Function Name: timer1_SaveConfig
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
void timer1_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: timer1_Sleep
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
void timer1_Sleep(void)
{
    if(0u != (timer1_BLOCK_CONTROL_REG & timer1_MASK))
    {
        timer1_backup.enableState = 1u;
    }
    else
    {
        timer1_backup.enableState = 0u;
    }

    timer1_Stop();
    timer1_SaveConfig();
}


/*******************************************************************************
* Function Name: timer1_RestoreConfig
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
void timer1_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: timer1_Wakeup
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
void timer1_Wakeup(void)
{
    timer1_RestoreConfig();

    if(0u != timer1_backup.enableState)
    {
        timer1_Enable();
    }
}


/* [] END OF FILE */
