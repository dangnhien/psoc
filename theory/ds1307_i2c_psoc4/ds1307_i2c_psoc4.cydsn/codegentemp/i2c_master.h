/***************************************************************************//**
* \file i2c_master.h
* \version 4.0
*
* \brief
*  This file provides constants and parameter values for the SCB Component.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2013-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_i2c_master_H)
#define CY_SCB_i2c_master_H

#include <cydevice_trm.h>
#include <cyfitter.h>
#include <cytypes.h>
#include <CyLib.h>

/* SCB IP block v0 is available in PSoC 4100/PSoC 4200 */
#define i2c_master_CY_SCBIP_V0    (CYIPBLOCK_m0s8scb_VERSION == 0u)
/* SCB IP block v1 is available in PSoC 4000 */
#define i2c_master_CY_SCBIP_V1    (CYIPBLOCK_m0s8scb_VERSION == 1u)
/* SCB IP block v2 is available in all other devices */
#define i2c_master_CY_SCBIP_V2    (CYIPBLOCK_m0s8scb_VERSION >= 2u)

/** Component version major.minor */
#define i2c_master_COMP_VERSION_MAJOR    (4)
#define i2c_master_COMP_VERSION_MINOR    (0)
    
#define i2c_master_SCB_MODE           (1u)

/* SCB modes enum */
#define i2c_master_SCB_MODE_I2C       (0x01u)
#define i2c_master_SCB_MODE_SPI       (0x02u)
#define i2c_master_SCB_MODE_UART      (0x04u)
#define i2c_master_SCB_MODE_EZI2C     (0x08u)
#define i2c_master_SCB_MODE_UNCONFIG  (0xFFu)

/* Condition compilation depends on operation mode: Unconfigured implies apply to all modes */
#define i2c_master_SCB_MODE_I2C_CONST_CFG       (i2c_master_SCB_MODE_I2C       == i2c_master_SCB_MODE)
#define i2c_master_SCB_MODE_SPI_CONST_CFG       (i2c_master_SCB_MODE_SPI       == i2c_master_SCB_MODE)
#define i2c_master_SCB_MODE_UART_CONST_CFG      (i2c_master_SCB_MODE_UART      == i2c_master_SCB_MODE)
#define i2c_master_SCB_MODE_EZI2C_CONST_CFG     (i2c_master_SCB_MODE_EZI2C     == i2c_master_SCB_MODE)
#define i2c_master_SCB_MODE_UNCONFIG_CONST_CFG  (i2c_master_SCB_MODE_UNCONFIG  == i2c_master_SCB_MODE)

/* Condition compilation for includes */
#define i2c_master_SCB_MODE_I2C_INC      (0u !=(i2c_master_SCB_MODE_I2C   & i2c_master_SCB_MODE))
#define i2c_master_SCB_MODE_EZI2C_INC    (0u !=(i2c_master_SCB_MODE_EZI2C & i2c_master_SCB_MODE))
#if (!i2c_master_CY_SCBIP_V1)
    #define i2c_master_SCB_MODE_SPI_INC  (0u !=(i2c_master_SCB_MODE_SPI   & i2c_master_SCB_MODE))
    #define i2c_master_SCB_MODE_UART_INC (0u !=(i2c_master_SCB_MODE_UART  & i2c_master_SCB_MODE))
#else
    #define i2c_master_SCB_MODE_SPI_INC  (0u)
    #define i2c_master_SCB_MODE_UART_INC (0u)
#endif /* (!i2c_master_CY_SCBIP_V1) */

/* Interrupts remove options */
#define i2c_master_REMOVE_SCB_IRQ             (0u)
#define i2c_master_SCB_IRQ_INTERNAL           (0u == i2c_master_REMOVE_SCB_IRQ)

#define i2c_master_REMOVE_UART_RX_WAKEUP_IRQ  (1u)
#define i2c_master_UART_RX_WAKEUP_IRQ         (0u == i2c_master_REMOVE_UART_RX_WAKEUP_IRQ)

/* SCB interrupt enum */
#define i2c_master_SCB_INTR_MODE_NONE     (0u)
#define i2c_master_SCB_INTR_MODE_INTERNAL (1u)
#define i2c_master_SCB_INTR_MODE_EXTERNAL (2u)

/* Internal clock remove option */
#define i2c_master_REMOVE_SCB_CLK     (0u)
#define i2c_master_SCB_CLK_INTERNAL   (0u == i2c_master_REMOVE_SCB_CLK)


/***************************************
*       Includes
****************************************/

#include "i2c_master_PINS.h"

#if (i2c_master_SCB_CLK_INTERNAL)
    #include "i2c_master_SCBCLK.h"
#endif /* (i2c_master_SCB_CLK_INTERNAL) */


/***************************************
*       Type Definitions
***************************************/

typedef struct
{
    uint8 enableState;
} i2c_master_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

/**
* \addtogroup group_general
* @{
*/

/* Start and Stop APIs */
void i2c_master_Init(void);
void i2c_master_Enable(void);
void i2c_master_Start(void);
void i2c_master_Stop(void);

/** @} general */

/**
* \addtogroup group_power
* @{
*/
/* Sleep and Wakeup APis */
void i2c_master_Sleep(void);
void i2c_master_Wakeup(void);
/** @} power */ 

/**
* \addtogroup group_interrupt
* @{
*/
#if (i2c_master_SCB_IRQ_INTERNAL)
    /* Custom interrupt handler */
    void i2c_master_SetCustomInterruptHandler(void (*func)(void));
#endif /* (i2c_master_SCB_IRQ_INTERNAL) */
/** @} interrupt */

/* Interface to internal interrupt component */
#if (i2c_master_SCB_IRQ_INTERNAL)
    /**
    * \addtogroup group_interrupt
    * @{
    */    
    /*******************************************************************************
    * Function Name: i2c_master_EnableInt
    ****************************************************************************//**
    *
    *  When using an Internal interrupt, this enables the interrupt in the NVIC. 
    *  When using an external interrupt the API for the interrupt component must 
    *  be used to enable the interrupt.
    *
    *******************************************************************************/
    #define i2c_master_EnableInt()    CyIntEnable(i2c_master_ISR_NUMBER)
    
    
    /*******************************************************************************
    * Function Name: i2c_master_DisableInt
    ****************************************************************************//**
    *
    *  When using an Internal interrupt, this disables the interrupt in the NVIC. 
    *  When using an external interrupt the API for the interrupt component must 
    *  be used to disable the interrupt.
    *
    *******************************************************************************/    
    #define i2c_master_DisableInt()   CyIntDisable(i2c_master_ISR_NUMBER)
    /** @} interrupt */

    /*******************************************************************************
    * Function Name: i2c_master_ClearPendingInt
    ****************************************************************************//**
    *
    *  This function clears the interrupt pending status in the NVIC. 
    *
    *******************************************************************************/
    #define i2c_master_ClearPendingInt()  CyIntClearPending(i2c_master_ISR_NUMBER)
#endif /* (i2c_master_SCB_IRQ_INTERNAL) */

#if (i2c_master_UART_RX_WAKEUP_IRQ)
    /*******************************************************************************
    * Function Name: i2c_master_RxWakeEnableInt
    ****************************************************************************//**
    *
    *  This function enables the interrupt (RX_WAKE) pending status in the NVIC. 
    *
    *******************************************************************************/    
    #define i2c_master_RxWakeEnableInt()  CyIntEnable(i2c_master_RX_WAKE_ISR_NUMBER)
    

    /*******************************************************************************
    * Function Name: i2c_master_RxWakeDisableInt
    ****************************************************************************//**
    *
    *  This function disables the interrupt (RX_WAKE) pending status in the NVIC.  
    *
    *******************************************************************************/
    #define i2c_master_RxWakeDisableInt() CyIntDisable(i2c_master_RX_WAKE_ISR_NUMBER)
    
    
    /*******************************************************************************
    * Function Name: i2c_master_RxWakeClearPendingInt
    ****************************************************************************//**
    *
    *  This function clears the interrupt (RX_WAKE) pending status in the NVIC. 
    *
    *******************************************************************************/    
    #define i2c_master_RxWakeClearPendingInt()  CyIntClearPending(i2c_master_RX_WAKE_ISR_NUMBER)
#endif /* (i2c_master_UART_RX_WAKEUP_IRQ) */

/**
* \addtogroup group_interrupt
* @{
*/
/* Get interrupt cause */
/*******************************************************************************
* Function Name: i2c_master_GetInterruptCause
****************************************************************************//**
*
*  Returns a mask of bits showing the source of the current triggered interrupt. 
*  This is useful for modes of operation where an interrupt can be generated by 
*  conditions in multiple interrupt source registers.
*
*  \return
*   Mask with the OR of the following conditions that have been triggered.
*    - i2c_master_INTR_CAUSE_MASTER - Interrupt from Master
*    - i2c_master_INTR_CAUSE_SLAVE - Interrupt from Slave
*    - i2c_master_INTR_CAUSE_TX - Interrupt from TX
*    - i2c_master_INTR_CAUSE_RX - Interrupt from RX
*
*******************************************************************************/
#define i2c_master_GetInterruptCause()    (i2c_master_INTR_CAUSE_REG)


/* APIs to service INTR_RX register */
/*******************************************************************************
* Function Name: i2c_master_GetRxInterruptSource
****************************************************************************//**
*
*  Returns RX interrupt request register. This register contains current status 
*  of RX interrupt sources.
*
*  \return
*   Current status of RX interrupt sources.
*   Each constant is a bit field value. The value returned may have multiple 
*   bits set to indicate the current status.
*   - i2c_master_INTR_RX_FIFO_LEVEL - The number of data elements in the 
      RX FIFO is greater than the value of RX FIFO level.
*   - i2c_master_INTR_RX_NOT_EMPTY - Receiver FIFO is not empty.
*   - i2c_master_INTR_RX_FULL - Receiver FIFO is full.
*   - i2c_master_INTR_RX_OVERFLOW - Attempt to write to a full 
*     receiver FIFO.
*   - i2c_master_INTR_RX_UNDERFLOW - Attempt to read from an empty 
*     receiver FIFO.
*   - i2c_master_INTR_RX_FRAME_ERROR - UART framing error detected.
*   - i2c_master_INTR_RX_PARITY_ERROR - UART parity error detected.
*
*******************************************************************************/
#define i2c_master_GetRxInterruptSource() (i2c_master_INTR_RX_REG)


/*******************************************************************************
* Function Name: i2c_master_SetRxInterruptMode
****************************************************************************//**
*
*  Writes RX interrupt mask register. This register configures which bits from 
*  RX interrupt request register will trigger an interrupt event.
*
*  \param interruptMask: RX interrupt sources to be enabled (refer to 
*   i2c_master_GetRxInterruptSource() function for bit fields values).
*
*******************************************************************************/
#define i2c_master_SetRxInterruptMode(interruptMask)     i2c_master_WRITE_INTR_RX_MASK(interruptMask)


/*******************************************************************************
* Function Name: i2c_master_GetRxInterruptMode
****************************************************************************//**
*
*  Returns RX interrupt mask register This register specifies which bits from 
*  RX interrupt request register will trigger an interrupt event.
*
*  \return 
*   RX interrupt sources to be enabled (refer to 
*   i2c_master_GetRxInterruptSource() function for bit fields values).
*
*******************************************************************************/
#define i2c_master_GetRxInterruptMode()   (i2c_master_INTR_RX_MASK_REG)


/*******************************************************************************
* Function Name: i2c_master_GetRxInterruptSourceMasked
****************************************************************************//**
*
*  Returns RX interrupt masked request register. This register contains logical
*  AND of corresponding bits from RX interrupt request and mask registers.
*  This function is intended to be used in the interrupt service routine to 
*  identify which of enabled RX interrupt sources cause interrupt event.
*
*  \return 
*   Current status of enabled RX interrupt sources (refer to 
*   i2c_master_GetRxInterruptSource() function for bit fields values).
*
*******************************************************************************/
#define i2c_master_GetRxInterruptSourceMasked()   (i2c_master_INTR_RX_MASKED_REG)


/*******************************************************************************
* Function Name: i2c_master_ClearRxInterruptSource
****************************************************************************//**
*
*  Clears RX interrupt sources in the interrupt request register.
*
*  \param interruptMask: RX interrupt sources to be cleared (refer to 
*   i2c_master_GetRxInterruptSource() function for bit fields values).
*
*  \sideeffects 
*   The side effects are listed in the table below for each 
*   affected interrupt source. Refer to section RX FIFO interrupt sources for 
*   detailed description.
*   - i2c_master_INTR_RX_FIFO_LEVEL Interrupt source is not cleared when 
*     the receiver FIFO has more entries than level.
*   - i2c_master_INTR_RX_NOT_EMPTY Interrupt source is not cleared when
*     receiver FIFO is not empty.
*   - i2c_master_INTR_RX_FULL Interrupt source is not cleared when 
*      receiver FIFO is full.
*
*******************************************************************************/
#define i2c_master_ClearRxInterruptSource(interruptMask)  i2c_master_CLEAR_INTR_RX(interruptMask)


/*******************************************************************************
* Function Name: i2c_master_SetRxInterrupt
****************************************************************************//**
*
*  Sets RX interrupt sources in the interrupt request register.
*
*  \param interruptMask: RX interrupt sources to set in the RX interrupt request 
*   register (refer to i2c_master_GetRxInterruptSource() function for bit 
*   fields values).
*
*******************************************************************************/
#define i2c_master_SetRxInterrupt(interruptMask)  i2c_master_SET_INTR_RX(interruptMask)

void i2c_master_SetRxFifoLevel(uint32 level);


/* APIs to service INTR_TX register */
/*******************************************************************************
* Function Name: i2c_master_GetTxInterruptSource
****************************************************************************//**
*
*  Returns TX interrupt request register. This register contains current status 
*  of TX interrupt sources.
* 
*  \return 
*   Current status of TX interrupt sources.
*   Each constant is a bit field value. The value returned may have multiple 
*   bits set to indicate the current status.
*   - i2c_master_INTR_TX_FIFO_LEVEL - The number of data elements in the 
*     TX FIFO is less than the value of TX FIFO level.
*   - i2c_master_INTR_TX_NOT_FULL - Transmitter FIFO is not full.
*   - i2c_master_INTR_TX_EMPTY - Transmitter FIFO is empty.
*   - i2c_master_INTR_TX_OVERFLOW - Attempt to write to a full 
*     transmitter FIFO.
*   - i2c_master_INTR_TX_UNDERFLOW - Attempt to read from an empty 
*     transmitter FIFO.
*   - i2c_master_INTR_TX_UART_NACK - UART received a NACK in SmartCard 
*   mode.
*   - i2c_master_INTR_TX_UART_DONE - UART transfer is complete. 
*     All data elements from the TX FIFO are sent.
*   - i2c_master_INTR_TX_UART_ARB_LOST - Value on the TX line of the UART
*     does not match the value on the RX line.
*
*******************************************************************************/
#define i2c_master_GetTxInterruptSource() (i2c_master_INTR_TX_REG)


/*******************************************************************************
* Function Name: i2c_master_SetTxInterruptMode
****************************************************************************//**
*
*  Writes TX interrupt mask register. This register configures which bits from 
*  TX interrupt request register will trigger an interrupt event.
*
*  \param interruptMask: TX interrupt sources to be enabled (refer to 
*   i2c_master_GetTxInterruptSource() function for bit field values).
*
*******************************************************************************/
#define i2c_master_SetTxInterruptMode(interruptMask)  i2c_master_WRITE_INTR_TX_MASK(interruptMask)


/*******************************************************************************
* Function Name: i2c_master_GetTxInterruptMode
****************************************************************************//**
*
*  Returns TX interrupt mask register This register specifies which bits from 
*  TX interrupt request register will trigger an interrupt event.
*
*  \return 
*   Enabled TX interrupt sources (refer to 
*   i2c_master_GetTxInterruptSource() function for bit field values).
*   
*******************************************************************************/
#define i2c_master_GetTxInterruptMode()   (i2c_master_INTR_TX_MASK_REG)


/*******************************************************************************
* Function Name: i2c_master_GetTxInterruptSourceMasked
****************************************************************************//**
*
*  Returns TX interrupt masked request register. This register contains logical
*  AND of corresponding bits from TX interrupt request and mask registers.
*  This function is intended to be used in the interrupt service routine to identify 
*  which of enabled TX interrupt sources cause interrupt event.
*
*  \return 
*   Current status of enabled TX interrupt sources (refer to 
*   i2c_master_GetTxInterruptSource() function for bit field values).
*
*******************************************************************************/
#define i2c_master_GetTxInterruptSourceMasked()   (i2c_master_INTR_TX_MASKED_REG)


/*******************************************************************************
* Function Name: i2c_master_ClearTxInterruptSource
****************************************************************************//**
*
*  Clears TX interrupt sources in the interrupt request register.
*
*  \param interruptMask: TX interrupt sources to be cleared (refer to 
*   i2c_master_GetTxInterruptSource() function for bit field values).
*
*  \sideeffects 
*   The side effects are listed in the table below for each affected interrupt 
*   source. Refer to section TX FIFO interrupt sources for detailed description.
*   - i2c_master_INTR_TX_FIFO_LEVEL - Interrupt source is not cleared when 
*     transmitter FIFO has less entries than level.
*   - i2c_master_INTR_TX_NOT_FULL - Interrupt source is not cleared when
*     transmitter FIFO has empty entries.
*   - i2c_master_INTR_TX_EMPTY - Interrupt source is not cleared when 
*     transmitter FIFO is empty.
*   - i2c_master_INTR_TX_UNDERFLOW - Interrupt source is not cleared when 
*     transmitter FIFO is empty and I2C mode with clock stretching is selected. 
*     Put data into the transmitter FIFO before clearing it. This behavior only 
*     applicable for PSoC 4100/PSoC 4200 devices.
*
*******************************************************************************/
#define i2c_master_ClearTxInterruptSource(interruptMask)  i2c_master_CLEAR_INTR_TX(interruptMask)


/*******************************************************************************
* Function Name: i2c_master_SetTxInterrupt
****************************************************************************//**
*
*  Sets RX interrupt sources in the interrupt request register.
*
*  \param interruptMask: RX interrupt sources to set in the RX interrupt request 
*   register (refer to i2c_master_GetRxInterruptSource() function for bit 
*   fields values).
*
*******************************************************************************/
#define i2c_master_SetTxInterrupt(interruptMask)  i2c_master_SET_INTR_TX(interruptMask)

void i2c_master_SetTxFifoLevel(uint32 level);


/* APIs to service INTR_MASTER register */
/*******************************************************************************
* Function Name: i2c_master_GetMasterInterruptSource
****************************************************************************//**
*
*  Returns Master interrupt request register. This register contains current 
*  status of Master interrupt sources.
*
*  \return 
*   Current status of Master interrupt sources. 
*   Each constant is a bit field value. The value returned may have multiple 
*   bits set to indicate the current status.
*   - i2c_master_INTR_MASTER_SPI_DONE - SPI master transfer is complete.
*     Refer to Interrupt sources section for detailed description.
*   - i2c_master_INTR_MASTER_I2C_ARB_LOST - I2C master lost arbitration.
*   - i2c_master_INTR_MASTER_I2C_NACK - I2C master received negative 
*    acknowledgement (NAK).
*   - i2c_master_INTR_MASTER_I2C_ACK - I2C master received acknowledgement.
*   - i2c_master_INTR_MASTER_I2C_STOP - I2C master generated STOP.
*   - i2c_master_INTR_MASTER_I2C_BUS_ERROR - I2C master bus error 
*     (detection of unexpected START or STOP condition).
*
*******************************************************************************/
#define i2c_master_GetMasterInterruptSource() (i2c_master_INTR_MASTER_REG)

/*******************************************************************************
* Function Name: i2c_master_SetMasterInterruptMode
****************************************************************************//**
*
*  Writes Master interrupt mask register. This register configures which bits 
*  from Master interrupt request register will trigger an interrupt event.
*
*  \param interruptMask: Master interrupt sources to be enabled (refer to 
*   i2c_master_GetMasterInterruptSource() function for bit field values).
*
*******************************************************************************/
#define i2c_master_SetMasterInterruptMode(interruptMask)  i2c_master_WRITE_INTR_MASTER_MASK(interruptMask)

/*******************************************************************************
* Function Name: i2c_master_GetMasterInterruptMode
****************************************************************************//**
*
*  Returns Master interrupt mask register This register specifies which bits 
*  from Master interrupt request register will trigger an interrupt event.
*
*  \return 
*   Enabled Master interrupt sources (refer to 
*   i2c_master_GetMasterInterruptSource() function for return values).
*
*******************************************************************************/
#define i2c_master_GetMasterInterruptMode()   (i2c_master_INTR_MASTER_MASK_REG)

/*******************************************************************************
* Function Name: i2c_master_GetMasterInterruptSourceMasked
****************************************************************************//**
*
*  Returns Master interrupt masked request register. This register contains 
*  logical AND of corresponding bits from Master interrupt request and mask 
*  registers.
*  This function is intended to be used in the interrupt service routine to 
*  identify which of enabled Master interrupt sources cause interrupt event.
*
*  \return 
*   Current status of enabled Master interrupt sources (refer to 
*   i2c_master_GetMasterInterruptSource() function for return values).
*
*******************************************************************************/
#define i2c_master_GetMasterInterruptSourceMasked()   (i2c_master_INTR_MASTER_MASKED_REG)

/*******************************************************************************
* Function Name: i2c_master_ClearMasterInterruptSource
****************************************************************************//**
*
*  Clears Master interrupt sources in the interrupt request register.
*
*  \param interruptMask: Master interrupt sources to be cleared (refer to 
*   i2c_master_GetMasterInterruptSource() function for bit field values).
*
*******************************************************************************/
#define i2c_master_ClearMasterInterruptSource(interruptMask)  i2c_master_CLEAR_INTR_MASTER(interruptMask)

/*******************************************************************************
* Function Name: i2c_master_SetMasterInterrupt
****************************************************************************//**
*
*  Sets Master interrupt sources in the interrupt request register.
*
*  \param interruptMask: Master interrupt sources to set in the Master interrupt
*   request register (refer to i2c_master_GetMasterInterruptSource() 
*   function for bit field values).
*
*******************************************************************************/
#define i2c_master_SetMasterInterrupt(interruptMask)  i2c_master_SET_INTR_MASTER(interruptMask)


/* APIs to service INTR_SLAVE register */
/*******************************************************************************
* Function Name: i2c_master_GetSlaveInterruptSource
****************************************************************************//**
*
*  Returns Slave interrupt request register. This register contains current 
*  status of Slave interrupt sources.
*
*  \return 
*   Current status of Slave interrupt sources.
*   Each constant is a bit field value. The value returned may have multiple 
*   bits set to indicate the current status.
*   - i2c_master_INTR_SLAVE_I2C_ARB_LOST - I2C slave lost arbitration: 
*     the value driven on the SDA line is not the same as the value observed 
*     on the SDA line.
*   - i2c_master_INTR_SLAVE_I2C_NACK - I2C slave received negative 
*     acknowledgement (NAK).
*   - i2c_master_INTR_SLAVE_I2C_ACK - I2C slave received 
*     acknowledgement (ACK).
*   - i2c_master_INTR_SLAVE_I2C_WRITE_STOP - Stop or Repeated Start 
*     event for write transfer intended for this slave (address matching 
*     is performed).
*   - i2c_master_INTR_SLAVE_I2C_STOP - Stop or Repeated Start event 
*     for (read or write) transfer intended for this slave (address matching 
*     is performed).
*   - i2c_master_INTR_SLAVE_I2C_START - I2C slave received Start 
*     condition.
*   - i2c_master_INTR_SLAVE_I2C_ADDR_MATCH - I2C slave received matching 
*     address.
*   - i2c_master_INTR_SLAVE_I2C_GENERAL - I2C Slave received general 
*     call address.
*   - i2c_master_INTR_SLAVE_I2C_BUS_ERROR - I2C slave bus error (detection 
*      of unexpected Start or Stop condition).
*   - i2c_master_INTR_SLAVE_SPI_BUS_ERROR - SPI slave select line is 
*      deselected at an expected time while the SPI transfer.
*
*******************************************************************************/
#define i2c_master_GetSlaveInterruptSource()  (i2c_master_INTR_SLAVE_REG)

/*******************************************************************************
* Function Name: i2c_master_SetSlaveInterruptMode
****************************************************************************//**
*
*  Writes Slave interrupt mask register. 
*  This register configures which bits from Slave interrupt request register 
*  will trigger an interrupt event.
*
*  \param interruptMask: Slave interrupt sources to be enabled (refer to 
*   i2c_master_GetSlaveInterruptSource() function for bit field values).
*
*******************************************************************************/
#define i2c_master_SetSlaveInterruptMode(interruptMask)   i2c_master_WRITE_INTR_SLAVE_MASK(interruptMask)

/*******************************************************************************
* Function Name: i2c_master_GetSlaveInterruptMode
****************************************************************************//**
*
*  Returns Slave interrupt mask register.
*  This register specifies which bits from Slave interrupt request register 
*  will trigger an interrupt event.
*
*  \return 
*   Enabled Slave interrupt sources(refer to 
*   i2c_master_GetSlaveInterruptSource() function for bit field values).
*
*******************************************************************************/
#define i2c_master_GetSlaveInterruptMode()    (i2c_master_INTR_SLAVE_MASK_REG)

/*******************************************************************************
* Function Name: i2c_master_GetSlaveInterruptSourceMasked
****************************************************************************//**
*
*  Returns Slave interrupt masked request register. This register contains 
*  logical AND of corresponding bits from Slave interrupt request and mask 
*  registers.
*  This function is intended to be used in the interrupt service routine to 
*  identify which of enabled Slave interrupt sources cause interrupt event.
*
*  \return 
*   Current status of enabled Slave interrupt sources (refer to 
*   i2c_master_GetSlaveInterruptSource() function for return values).
*
*******************************************************************************/
#define i2c_master_GetSlaveInterruptSourceMasked()    (i2c_master_INTR_SLAVE_MASKED_REG)

/*******************************************************************************
* Function Name: i2c_master_ClearSlaveInterruptSource
****************************************************************************//**
*
*  Clears Slave interrupt sources in the interrupt request register.
*
*  \param interruptMask: Slave interrupt sources to be cleared (refer to 
*   i2c_master_GetSlaveInterruptSource() function for return values).
*
*******************************************************************************/
#define i2c_master_ClearSlaveInterruptSource(interruptMask)   i2c_master_CLEAR_INTR_SLAVE(interruptMask)

/*******************************************************************************
* Function Name: i2c_master_SetSlaveInterrupt
****************************************************************************//**
*
*  Sets Slave interrupt sources in the interrupt request register.
*
*  \param interruptMask: Slave interrupt sources to set in the Slave interrupt 
*   request register (refer to i2c_master_GetSlaveInterruptSource() 
*   function for return values).
*
*******************************************************************************/
#define i2c_master_SetSlaveInterrupt(interruptMask)   i2c_master_SET_INTR_SLAVE(interruptMask)

/** @} interrupt */ 


/***************************************
*     Vars with External Linkage
***************************************/

/**
* \addtogroup group_globals
* @{
*/

/** i2c_master_initVar indicates whether the i2c_master 
*  component has been initialized. The variable is initialized to 0 
*  and set to 1 the first time SCB_Start() is called. This allows 
*  the component to restart without reinitialization after the first 
*  call to the i2c_master_Start() routine.
*
*  If re-initialization of the component is required, then the 
*  i2c_master_Init() function can be called before the 
*  i2c_master_Start() or i2c_master_Enable() function.
*/
extern uint8 i2c_master_initVar;
/** @} globals */

/***************************************
*              Registers
***************************************/

#define i2c_master_CTRL_REG               (*(reg32 *) i2c_master_SCB__CTRL)
#define i2c_master_CTRL_PTR               ( (reg32 *) i2c_master_SCB__CTRL)

#define i2c_master_STATUS_REG             (*(reg32 *) i2c_master_SCB__STATUS)
#define i2c_master_STATUS_PTR             ( (reg32 *) i2c_master_SCB__STATUS)

#if (!i2c_master_CY_SCBIP_V1)
    #define i2c_master_SPI_CTRL_REG           (*(reg32 *) i2c_master_SCB__SPI_CTRL)
    #define i2c_master_SPI_CTRL_PTR           ( (reg32 *) i2c_master_SCB__SPI_CTRL)

    #define i2c_master_SPI_STATUS_REG         (*(reg32 *) i2c_master_SCB__SPI_STATUS)
    #define i2c_master_SPI_STATUS_PTR         ( (reg32 *) i2c_master_SCB__SPI_STATUS)

    #define i2c_master_UART_CTRL_REG          (*(reg32 *) i2c_master_SCB__UART_CTRL)
    #define i2c_master_UART_CTRL_PTR          ( (reg32 *) i2c_master_SCB__UART_CTRL)

    #define i2c_master_UART_TX_CTRL_REG       (*(reg32 *) i2c_master_SCB__UART_TX_CTRL)
    #define i2c_master_UART_TX_CTRL_PTR       ( (reg32 *) i2c_master_SCB__UART_TX_CTRL)

    #define i2c_master_UART_RX_CTRL_REG       (*(reg32 *) i2c_master_SCB__UART_RX_CTRL)
    #define i2c_master_UART_RX_CTRL_PTR       ( (reg32 *) i2c_master_SCB__UART_RX_CTRL)

    #define i2c_master_UART_RX_STATUS_REG     (*(reg32 *) i2c_master_SCB__UART_RX_STATUS)
    #define i2c_master_UART_RX_STATUS_PTR     ( (reg32 *) i2c_master_SCB__UART_RX_STATUS)
#endif /* (!i2c_master_CY_SCBIP_V1) */

#if !(i2c_master_CY_SCBIP_V0 || i2c_master_CY_SCBIP_V1)
    #define i2c_master_UART_FLOW_CTRL_REG     (*(reg32 *) i2c_master_SCB__UART_FLOW_CTRL)
    #define i2c_master_UART_FLOW_CTRL_PTR     ( (reg32 *) i2c_master_SCB__UART_FLOW_CTRL)
#endif /* !(i2c_master_CY_SCBIP_V0 || i2c_master_CY_SCBIP_V1) */

#define i2c_master_I2C_CTRL_REG           (*(reg32 *) i2c_master_SCB__I2C_CTRL)
#define i2c_master_I2C_CTRL_PTR           ( (reg32 *) i2c_master_SCB__I2C_CTRL)

#define i2c_master_I2C_STATUS_REG         (*(reg32 *) i2c_master_SCB__I2C_STATUS)
#define i2c_master_I2C_STATUS_PTR         ( (reg32 *) i2c_master_SCB__I2C_STATUS)

#define i2c_master_I2C_MASTER_CMD_REG     (*(reg32 *) i2c_master_SCB__I2C_M_CMD)
#define i2c_master_I2C_MASTER_CMD_PTR     ( (reg32 *) i2c_master_SCB__I2C_M_CMD)

#define i2c_master_I2C_SLAVE_CMD_REG      (*(reg32 *) i2c_master_SCB__I2C_S_CMD)
#define i2c_master_I2C_SLAVE_CMD_PTR      ( (reg32 *) i2c_master_SCB__I2C_S_CMD)

#define i2c_master_I2C_CFG_REG            (*(reg32 *) i2c_master_SCB__I2C_CFG)
#define i2c_master_I2C_CFG_PTR            ( (reg32 *) i2c_master_SCB__I2C_CFG)

#define i2c_master_TX_CTRL_REG            (*(reg32 *) i2c_master_SCB__TX_CTRL)
#define i2c_master_TX_CTRL_PTR            ( (reg32 *) i2c_master_SCB__TX_CTRL)

#define i2c_master_TX_FIFO_CTRL_REG       (*(reg32 *) i2c_master_SCB__TX_FIFO_CTRL)
#define i2c_master_TX_FIFO_CTRL_PTR       ( (reg32 *) i2c_master_SCB__TX_FIFO_CTRL)

#define i2c_master_TX_FIFO_STATUS_REG     (*(reg32 *) i2c_master_SCB__TX_FIFO_STATUS)
#define i2c_master_TX_FIFO_STATUS_PTR     ( (reg32 *) i2c_master_SCB__TX_FIFO_STATUS)

#define i2c_master_TX_FIFO_WR_REG         (*(reg32 *) i2c_master_SCB__TX_FIFO_WR)
#define i2c_master_TX_FIFO_WR_PTR         ( (reg32 *) i2c_master_SCB__TX_FIFO_WR)

#define i2c_master_RX_CTRL_REG            (*(reg32 *) i2c_master_SCB__RX_CTRL)
#define i2c_master_RX_CTRL_PTR            ( (reg32 *) i2c_master_SCB__RX_CTRL)

#define i2c_master_RX_FIFO_CTRL_REG       (*(reg32 *) i2c_master_SCB__RX_FIFO_CTRL)
#define i2c_master_RX_FIFO_CTRL_PTR       ( (reg32 *) i2c_master_SCB__RX_FIFO_CTRL)

#define i2c_master_RX_FIFO_STATUS_REG     (*(reg32 *) i2c_master_SCB__RX_FIFO_STATUS)
#define i2c_master_RX_FIFO_STATUS_PTR     ( (reg32 *) i2c_master_SCB__RX_FIFO_STATUS)

#define i2c_master_RX_MATCH_REG           (*(reg32 *) i2c_master_SCB__RX_MATCH)
#define i2c_master_RX_MATCH_PTR           ( (reg32 *) i2c_master_SCB__RX_MATCH)

#define i2c_master_RX_FIFO_RD_REG         (*(reg32 *) i2c_master_SCB__RX_FIFO_RD)
#define i2c_master_RX_FIFO_RD_PTR         ( (reg32 *) i2c_master_SCB__RX_FIFO_RD)

#define i2c_master_RX_FIFO_RD_SILENT_REG  (*(reg32 *) i2c_master_SCB__RX_FIFO_RD_SILENT)
#define i2c_master_RX_FIFO_RD_SILENT_PTR  ( (reg32 *) i2c_master_SCB__RX_FIFO_RD_SILENT)

#ifdef i2c_master_SCB__EZ_DATA0
    #define i2c_master_EZBUF_DATA0_REG    (*(reg32 *) i2c_master_SCB__EZ_DATA0)
    #define i2c_master_EZBUF_DATA0_PTR    ( (reg32 *) i2c_master_SCB__EZ_DATA0)
#else
    #define i2c_master_EZBUF_DATA0_REG    (*(reg32 *) i2c_master_SCB__EZ_DATA00)
    #define i2c_master_EZBUF_DATA0_PTR    ( (reg32 *) i2c_master_SCB__EZ_DATA00)
#endif /* i2c_master_SCB__EZ_DATA00 */

#define i2c_master_INTR_CAUSE_REG         (*(reg32 *) i2c_master_SCB__INTR_CAUSE)
#define i2c_master_INTR_CAUSE_PTR         ( (reg32 *) i2c_master_SCB__INTR_CAUSE)

#define i2c_master_INTR_I2C_EC_REG        (*(reg32 *) i2c_master_SCB__INTR_I2C_EC)
#define i2c_master_INTR_I2C_EC_PTR        ( (reg32 *) i2c_master_SCB__INTR_I2C_EC)

#define i2c_master_INTR_I2C_EC_MASK_REG   (*(reg32 *) i2c_master_SCB__INTR_I2C_EC_MASK)
#define i2c_master_INTR_I2C_EC_MASK_PTR   ( (reg32 *) i2c_master_SCB__INTR_I2C_EC_MASK)

#define i2c_master_INTR_I2C_EC_MASKED_REG (*(reg32 *) i2c_master_SCB__INTR_I2C_EC_MASKED)
#define i2c_master_INTR_I2C_EC_MASKED_PTR ( (reg32 *) i2c_master_SCB__INTR_I2C_EC_MASKED)

#if (!i2c_master_CY_SCBIP_V1)
    #define i2c_master_INTR_SPI_EC_REG        (*(reg32 *) i2c_master_SCB__INTR_SPI_EC)
    #define i2c_master_INTR_SPI_EC_PTR        ( (reg32 *) i2c_master_SCB__INTR_SPI_EC)

    #define i2c_master_INTR_SPI_EC_MASK_REG   (*(reg32 *) i2c_master_SCB__INTR_SPI_EC_MASK)
    #define i2c_master_INTR_SPI_EC_MASK_PTR   ( (reg32 *) i2c_master_SCB__INTR_SPI_EC_MASK)

    #define i2c_master_INTR_SPI_EC_MASKED_REG (*(reg32 *) i2c_master_SCB__INTR_SPI_EC_MASKED)
    #define i2c_master_INTR_SPI_EC_MASKED_PTR ( (reg32 *) i2c_master_SCB__INTR_SPI_EC_MASKED)
#endif /* (!i2c_master_CY_SCBIP_V1) */

#define i2c_master_INTR_MASTER_REG        (*(reg32 *) i2c_master_SCB__INTR_M)
#define i2c_master_INTR_MASTER_PTR        ( (reg32 *) i2c_master_SCB__INTR_M)

#define i2c_master_INTR_MASTER_SET_REG    (*(reg32 *) i2c_master_SCB__INTR_M_SET)
#define i2c_master_INTR_MASTER_SET_PTR    ( (reg32 *) i2c_master_SCB__INTR_M_SET)

#define i2c_master_INTR_MASTER_MASK_REG   (*(reg32 *) i2c_master_SCB__INTR_M_MASK)
#define i2c_master_INTR_MASTER_MASK_PTR   ( (reg32 *) i2c_master_SCB__INTR_M_MASK)

#define i2c_master_INTR_MASTER_MASKED_REG (*(reg32 *) i2c_master_SCB__INTR_M_MASKED)
#define i2c_master_INTR_MASTER_MASKED_PTR ( (reg32 *) i2c_master_SCB__INTR_M_MASKED)

#define i2c_master_INTR_SLAVE_REG         (*(reg32 *) i2c_master_SCB__INTR_S)
#define i2c_master_INTR_SLAVE_PTR         ( (reg32 *) i2c_master_SCB__INTR_S)

#define i2c_master_INTR_SLAVE_SET_REG     (*(reg32 *) i2c_master_SCB__INTR_S_SET)
#define i2c_master_INTR_SLAVE_SET_PTR     ( (reg32 *) i2c_master_SCB__INTR_S_SET)

#define i2c_master_INTR_SLAVE_MASK_REG    (*(reg32 *) i2c_master_SCB__INTR_S_MASK)
#define i2c_master_INTR_SLAVE_MASK_PTR    ( (reg32 *) i2c_master_SCB__INTR_S_MASK)

#define i2c_master_INTR_SLAVE_MASKED_REG  (*(reg32 *) i2c_master_SCB__INTR_S_MASKED)
#define i2c_master_INTR_SLAVE_MASKED_PTR  ( (reg32 *) i2c_master_SCB__INTR_S_MASKED)

#define i2c_master_INTR_TX_REG            (*(reg32 *) i2c_master_SCB__INTR_TX)
#define i2c_master_INTR_TX_PTR            ( (reg32 *) i2c_master_SCB__INTR_TX)

#define i2c_master_INTR_TX_SET_REG        (*(reg32 *) i2c_master_SCB__INTR_TX_SET)
#define i2c_master_INTR_TX_SET_PTR        ( (reg32 *) i2c_master_SCB__INTR_TX_SET)

#define i2c_master_INTR_TX_MASK_REG       (*(reg32 *) i2c_master_SCB__INTR_TX_MASK)
#define i2c_master_INTR_TX_MASK_PTR       ( (reg32 *) i2c_master_SCB__INTR_TX_MASK)

#define i2c_master_INTR_TX_MASKED_REG     (*(reg32 *) i2c_master_SCB__INTR_TX_MASKED)
#define i2c_master_INTR_TX_MASKED_PTR     ( (reg32 *) i2c_master_SCB__INTR_TX_MASKED)

#define i2c_master_INTR_RX_REG            (*(reg32 *) i2c_master_SCB__INTR_RX)
#define i2c_master_INTR_RX_PTR            ( (reg32 *) i2c_master_SCB__INTR_RX)

#define i2c_master_INTR_RX_SET_REG        (*(reg32 *) i2c_master_SCB__INTR_RX_SET)
#define i2c_master_INTR_RX_SET_PTR        ( (reg32 *) i2c_master_SCB__INTR_RX_SET)

#define i2c_master_INTR_RX_MASK_REG       (*(reg32 *) i2c_master_SCB__INTR_RX_MASK)
#define i2c_master_INTR_RX_MASK_PTR       ( (reg32 *) i2c_master_SCB__INTR_RX_MASK)

#define i2c_master_INTR_RX_MASKED_REG     (*(reg32 *) i2c_master_SCB__INTR_RX_MASKED)
#define i2c_master_INTR_RX_MASKED_PTR     ( (reg32 *) i2c_master_SCB__INTR_RX_MASKED)

/* Defines get from SCB IP parameters. */
#define i2c_master_FIFO_SIZE      (8u)  /* TX or RX FIFO size. */
#define i2c_master_EZ_DATA_NR     (32u)  /* Number of words in EZ memory. */ 
#define i2c_master_ONE_BYTE_WIDTH (8u)            /* Number of bits in one byte. */
#define i2c_master_FF_DATA_NR_LOG2_MASK       (0x07u)      /* Number of bits to represent a FIFO address. */
#define i2c_master_FF_DATA_NR_LOG2_PLUS1_MASK (0x0Fu) /* Number of bits to represent #bytes in FIFO. */


/***************************************
*        Registers Constants
***************************************/

#if (i2c_master_SCB_IRQ_INTERNAL)
    #define i2c_master_ISR_NUMBER     ((uint8) i2c_master_SCB_IRQ__INTC_NUMBER)
    #define i2c_master_ISR_PRIORITY   ((uint8) i2c_master_SCB_IRQ__INTC_PRIOR_NUM)
#endif /* (i2c_master_SCB_IRQ_INTERNAL) */

#if (i2c_master_UART_RX_WAKEUP_IRQ)
    #define i2c_master_RX_WAKE_ISR_NUMBER     ((uint8) i2c_master_RX_WAKEUP_IRQ__INTC_NUMBER)
    #define i2c_master_RX_WAKE_ISR_PRIORITY   ((uint8) i2c_master_RX_WAKEUP_IRQ__INTC_PRIOR_NUM)
#endif /* (i2c_master_UART_RX_WAKEUP_IRQ) */

/* i2c_master_CTRL_REG */
#define i2c_master_CTRL_OVS_POS           (0u)  /* [3:0]   Oversampling factor                 */
#define i2c_master_CTRL_EC_AM_MODE_POS    (8u)  /* [8]     Externally clocked address match    */
#define i2c_master_CTRL_EC_OP_MODE_POS    (9u)  /* [9]     Externally clocked operation mode   */
#define i2c_master_CTRL_EZBUF_MODE_POS    (10u) /* [10]    EZ buffer is enabled                */
#if !(i2c_master_CY_SCBIP_V0 || i2c_master_CY_SCBIP_V1)
    #define i2c_master_CTRL_BYTE_MODE_POS (11u) /* [11]    Determines the number of bits per FIFO data element */
#endif /* !(i2c_master_CY_SCBIP_V0 || i2c_master_CY_SCBIP_V1) */
#define i2c_master_CTRL_ADDR_ACCEPT_POS   (16u) /* [16]    Put matched address in RX FIFO       */
#define i2c_master_CTRL_BLOCK_POS         (17u) /* [17]    Ext and Int logic to resolve collide */
#define i2c_master_CTRL_MODE_POS          (24u) /* [25:24] Operation mode                       */
#define i2c_master_CTRL_ENABLED_POS       (31u) /* [31]    Enable SCB block                     */
#define i2c_master_CTRL_OVS_MASK          ((uint32) 0x0Fu)
#define i2c_master_CTRL_EC_AM_MODE        ((uint32) 0x01u << i2c_master_CTRL_EC_AM_MODE_POS)
#define i2c_master_CTRL_EC_OP_MODE        ((uint32) 0x01u << i2c_master_CTRL_EC_OP_MODE_POS)
#define i2c_master_CTRL_EZBUF_MODE        ((uint32) 0x01u << i2c_master_CTRL_EZBUF_MODE_POS)
#if !(i2c_master_CY_SCBIP_V0 || i2c_master_CY_SCBIP_V1)
    #define i2c_master_CTRL_BYTE_MODE ((uint32) 0x01u << i2c_master_CTRL_BYTE_MODE_POS)
#endif /* !(i2c_master_CY_SCBIP_V0 || i2c_master_CY_SCBIP_V1) */
#define i2c_master_CTRL_ADDR_ACCEPT       ((uint32) 0x01u << i2c_master_CTRL_ADDR_ACCEPT_POS)
#define i2c_master_CTRL_BLOCK             ((uint32) 0x01u << i2c_master_CTRL_BLOCK_POS)
#define i2c_master_CTRL_MODE_MASK         ((uint32) 0x03u << i2c_master_CTRL_MODE_POS)
#define i2c_master_CTRL_MODE_I2C          ((uint32) 0x00u)
#define i2c_master_CTRL_MODE_SPI          ((uint32) 0x01u << i2c_master_CTRL_MODE_POS)
#define i2c_master_CTRL_MODE_UART         ((uint32) 0x02u << i2c_master_CTRL_MODE_POS)
#define i2c_master_CTRL_ENABLED           ((uint32) 0x01u << i2c_master_CTRL_ENABLED_POS)

/* i2c_master_STATUS_REG */
#define i2c_master_STATUS_EC_BUSY_POS     (0u)  /* [0] Bus busy. Externally clocked logic access to EZ memory */
#define i2c_master_STATUS_EC_BUSY         ((uint32) 0x0Fu)

/* i2c_master_SPI_CTRL_REG  */
#define i2c_master_SPI_CTRL_CONTINUOUS_POS        (0u)  /* [0]     Continuous or Separated SPI data transfers */
#define i2c_master_SPI_CTRL_SELECT_PRECEDE_POS    (1u)  /* [1]     Precedes or coincides start of data frame  */
#define i2c_master_SPI_CTRL_CPHA_POS              (2u)  /* [2]     SCLK phase                                 */
#define i2c_master_SPI_CTRL_CPOL_POS              (3u)  /* [3]     SCLK polarity                              */
#define i2c_master_SPI_CTRL_LATE_MISO_SAMPLE_POS  (4u)  /* [4]     Late MISO sample enabled                   */
#if !(i2c_master_CY_SCBIP_V0 || i2c_master_CY_SCBIP_V1)
    #define i2c_master_SPI_CTRL_SCLK_CONTINUOUS_POS   (5u)  /* [5]     Enable continuous SCLK generation */
    #define i2c_master_SPI_CTRL_SSEL0_POLARITY_POS    (8u)  /* [8]     SS0 polarity                      */
    #define i2c_master_SPI_CTRL_SSEL1_POLARITY_POS    (9u)  /* [9]     SS1 polarity                      */
    #define i2c_master_SPI_CTRL_SSEL2_POLARITY_POS    (10u) /* [10]    SS2 polarity                      */
    #define i2c_master_SPI_CTRL_SSEL3_POLARITY_POS    (11u) /* [11]    SS3 polarity                      */
#endif /* !(i2c_master_CY_SCBIP_V0 || i2c_master_CY_SCBIP_V1) */
#define i2c_master_SPI_CTRL_LOOPBACK_POS          (16u) /* [16]    Local loop-back control enabled            */
#define i2c_master_SPI_CTRL_MODE_POS              (24u) /* [25:24] Submode of SPI operation                   */
#define i2c_master_SPI_CTRL_SLAVE_SELECT_POS      (26u) /* [27:26] Selects SPI SS signal                      */
#define i2c_master_SPI_CTRL_MASTER_MODE_POS       (31u) /* [31]    Master mode enabled                        */
#define i2c_master_SPI_CTRL_CONTINUOUS            ((uint32) 0x01u)
#define i2c_master_SPI_CTRL_SELECT_PRECEDE        ((uint32) 0x01u << i2c_master_SPI_CTRL_SELECT_PRECEDE_POS)
#define i2c_master_SPI_CTRL_SCLK_MODE_MASK        ((uint32) 0x03u << i2c_master_SPI_CTRL_CPHA_POS)
#define i2c_master_SPI_CTRL_CPHA                  ((uint32) 0x01u << i2c_master_SPI_CTRL_CPHA_POS)
#define i2c_master_SPI_CTRL_CPOL                  ((uint32) 0x01u << i2c_master_SPI_CTRL_CPOL_POS)
#define i2c_master_SPI_CTRL_LATE_MISO_SAMPLE      ((uint32) 0x01u << \
                                                                    i2c_master_SPI_CTRL_LATE_MISO_SAMPLE_POS)
#if !(i2c_master_CY_SCBIP_V0 || i2c_master_CY_SCBIP_V1)
    #define i2c_master_SPI_CTRL_SCLK_CONTINUOUS  ((uint32) 0x01u << i2c_master_SPI_CTRL_SCLK_CONTINUOUS_POS)
    #define i2c_master_SPI_CTRL_SSEL0_POLARITY   ((uint32) 0x01u << i2c_master_SPI_CTRL_SSEL0_POLARITY_POS)
    #define i2c_master_SPI_CTRL_SSEL1_POLARITY   ((uint32) 0x01u << i2c_master_SPI_CTRL_SSEL1_POLARITY_POS)
    #define i2c_master_SPI_CTRL_SSEL2_POLARITY   ((uint32) 0x01u << i2c_master_SPI_CTRL_SSEL2_POLARITY_POS)
    #define i2c_master_SPI_CTRL_SSEL3_POLARITY   ((uint32) 0x01u << i2c_master_SPI_CTRL_SSEL3_POLARITY_POS)
    #define i2c_master_SPI_CTRL_SSEL_POLARITY_MASK ((uint32)0x0Fu << i2c_master_SPI_CTRL_SSEL0_POLARITY_POS)
#endif /* !(i2c_master_CY_SCBIP_V0 || i2c_master_CY_SCBIP_V1) */

#define i2c_master_SPI_CTRL_LOOPBACK              ((uint32) 0x01u << i2c_master_SPI_CTRL_LOOPBACK_POS)
#define i2c_master_SPI_CTRL_MODE_MASK             ((uint32) 0x03u << i2c_master_SPI_CTRL_MODE_POS)
#define i2c_master_SPI_CTRL_MODE_MOTOROLA         ((uint32) 0x00u)
#define i2c_master_SPI_CTRL_MODE_TI               ((uint32) 0x01u << i2c_master_CTRL_MODE_POS)
#define i2c_master_SPI_CTRL_MODE_NS               ((uint32) 0x02u << i2c_master_CTRL_MODE_POS)
#define i2c_master_SPI_CTRL_SLAVE_SELECT_MASK     ((uint32) 0x03u << i2c_master_SPI_CTRL_SLAVE_SELECT_POS)
#define i2c_master_SPI_CTRL_SLAVE_SELECT0         ((uint32) 0x00u)
#define i2c_master_SPI_CTRL_SLAVE_SELECT1         ((uint32) 0x01u << i2c_master_SPI_CTRL_SLAVE_SELECT_POS)
#define i2c_master_SPI_CTRL_SLAVE_SELECT2         ((uint32) 0x02u << i2c_master_SPI_CTRL_SLAVE_SELECT_POS)
#define i2c_master_SPI_CTRL_SLAVE_SELECT3         ((uint32) 0x03u << i2c_master_SPI_CTRL_SLAVE_SELECT_POS)
#define i2c_master_SPI_CTRL_MASTER                ((uint32) 0x01u << i2c_master_SPI_CTRL_MASTER_MODE_POS)
#define i2c_master_SPI_CTRL_SLAVE                 ((uint32) 0x00u)

/* i2c_master_SPI_STATUS_REG  */
#define i2c_master_SPI_STATUS_BUS_BUSY_POS    (0u)  /* [0]    Bus busy - slave selected */
#define i2c_master_SPI_STATUS_EZBUF_ADDR_POS  (8u)  /* [15:8] EzAddress                 */
#define i2c_master_SPI_STATUS_BUS_BUSY        ((uint32) 0x01u)
#define i2c_master_SPI_STATUS_EZBUF_ADDR_MASK ((uint32) 0xFFu << i2c_master_I2C_STATUS_EZBUF_ADDR_POS)

/* i2c_master_UART_CTRL */
#define i2c_master_UART_CTRL_LOOPBACK_POS         (16u) /* [16] Loop-back    */
#define i2c_master_UART_CTRL_MODE_POS             (24u) /* [24] UART subMode */
#define i2c_master_UART_CTRL_LOOPBACK             ((uint32) 0x01u << i2c_master_UART_CTRL_LOOPBACK_POS)
#define i2c_master_UART_CTRL_MODE_UART_STD        ((uint32) 0x00u)
#define i2c_master_UART_CTRL_MODE_UART_SMARTCARD  ((uint32) 0x01u << i2c_master_UART_CTRL_MODE_POS)
#define i2c_master_UART_CTRL_MODE_UART_IRDA       ((uint32) 0x02u << i2c_master_UART_CTRL_MODE_POS)
#define i2c_master_UART_CTRL_MODE_MASK            ((uint32) 0x03u << i2c_master_UART_CTRL_MODE_POS)

/* i2c_master_UART_TX_CTRL */
#define i2c_master_UART_TX_CTRL_STOP_BITS_POS         (0u)  /* [2:0] Stop bits: (Stop bits + 1) * 0.5 period */
#define i2c_master_UART_TX_CTRL_PARITY_POS            (4u)  /* [4]   Parity bit                              */
#define i2c_master_UART_TX_CTRL_PARITY_ENABLED_POS    (5u)  /* [5]   Parity enable                           */
#define i2c_master_UART_TX_CTRL_RETRY_ON_NACK_POS     (8u)  /* [8]   Smart Card: re-send frame on NACK       */
#define i2c_master_UART_TX_CTRL_ONE_STOP_BIT          ((uint32) 0x01u)
#define i2c_master_UART_TX_CTRL_ONE_HALF_STOP_BITS    ((uint32) 0x02u)
#define i2c_master_UART_TX_CTRL_TWO_STOP_BITS         ((uint32) 0x03u)
#define i2c_master_UART_TX_CTRL_STOP_BITS_MASK        ((uint32) 0x07u)
#define i2c_master_UART_TX_CTRL_PARITY                ((uint32) 0x01u << \
                                                                    i2c_master_UART_TX_CTRL_PARITY_POS)
#define i2c_master_UART_TX_CTRL_PARITY_ENABLED        ((uint32) 0x01u << \
                                                                    i2c_master_UART_TX_CTRL_PARITY_ENABLED_POS)
#define i2c_master_UART_TX_CTRL_RETRY_ON_NACK         ((uint32) 0x01u << \
                                                                    i2c_master_UART_TX_CTRL_RETRY_ON_NACK_POS)

/* i2c_master_UART_RX_CTRL */
#define i2c_master_UART_RX_CTRL_STOP_BITS_POS             (0u)  /* [2:0] Stop bits: (Stop bits + 1) * 0.5 period*/
#define i2c_master_UART_RX_CTRL_PARITY_POS                (4u)  /* [4]   Parity bit                             */
#define i2c_master_UART_RX_CTRL_PARITY_ENABLED_POS        (5u)  /* [5]   Parity enable                          */
#define i2c_master_UART_RX_CTRL_POLARITY_POS              (6u)  /* [6]   IrDA: inverts polarity of RX signal    */
#define i2c_master_UART_RX_CTRL_DROP_ON_PARITY_ERR_POS    (8u)  /* [8]   Drop and lost RX FIFO on parity error  */
#define i2c_master_UART_RX_CTRL_DROP_ON_FRAME_ERR_POS     (9u)  /* [9]   Drop and lost RX FIFO on frame error   */
#define i2c_master_UART_RX_CTRL_MP_MODE_POS               (10u) /* [10]  Multi-processor mode                   */
#define i2c_master_UART_RX_CTRL_LIN_MODE_POS              (12u) /* [12]  Lin mode: applicable for UART Standard */
#define i2c_master_UART_RX_CTRL_SKIP_START_POS            (13u) /* [13]  Skip start not: only for UART Standard */
#define i2c_master_UART_RX_CTRL_BREAK_WIDTH_POS           (16u) /* [19:16]  Break width: (Break width + 1)      */
#define i2c_master_UART_TX_CTRL_ONE_STOP_BIT              ((uint32) 0x01u)
#define i2c_master_UART_TX_CTRL_ONE_HALF_STOP_BITS        ((uint32) 0x02u)
#define i2c_master_UART_TX_CTRL_TWO_STOP_BITS             ((uint32) 0x03u)
#define i2c_master_UART_RX_CTRL_STOP_BITS_MASK            ((uint32) 0x07u)
#define i2c_master_UART_RX_CTRL_PARITY                    ((uint32) 0x01u << \
                                                                    i2c_master_UART_RX_CTRL_PARITY_POS)
#define i2c_master_UART_RX_CTRL_PARITY_ENABLED            ((uint32) 0x01u << \
                                                                    i2c_master_UART_RX_CTRL_PARITY_ENABLED_POS)
#define i2c_master_UART_RX_CTRL_POLARITY                  ((uint32) 0x01u << \
                                                                    i2c_master_UART_RX_CTRL_POLARITY_POS)
#define i2c_master_UART_RX_CTRL_DROP_ON_PARITY_ERR        ((uint32) 0x01u << \
                                                                   i2c_master_UART_RX_CTRL_DROP_ON_PARITY_ERR_POS)
#define i2c_master_UART_RX_CTRL_DROP_ON_FRAME_ERR         ((uint32) 0x01u << \
                                                                    i2c_master_UART_RX_CTRL_DROP_ON_FRAME_ERR_POS)
#define i2c_master_UART_RX_CTRL_MP_MODE                   ((uint32) 0x01u << \
                                                                    i2c_master_UART_RX_CTRL_MP_MODE_POS)
#define i2c_master_UART_RX_CTRL_LIN_MODE                  ((uint32) 0x01u << \
                                                                    i2c_master_UART_RX_CTRL_LIN_MODE_POS)
#define i2c_master_UART_RX_CTRL_SKIP_START                ((uint32) 0x01u << \
                                                                    i2c_master_UART_RX_CTRL_SKIP_START_POS)
#define i2c_master_UART_RX_CTRL_BREAK_WIDTH_MASK          ((uint32) 0x0Fu << \
                                                                    i2c_master_UART_RX_CTRL_BREAK_WIDTH_POS)
/* i2c_master_UART_RX_STATUS_REG */
#define i2c_master_UART_RX_STATUS_BR_COUNTER_POS     (0u)  /* [11:0] Baud Rate counter */
#define i2c_master_UART_RX_STATUS_BR_COUNTER_MASK    ((uint32) 0xFFFu)

#if !(i2c_master_CY_SCBIP_V0 || i2c_master_CY_SCBIP_V1)
    /* i2c_master_UART_FLOW_CTRL_REG */
    #define i2c_master_UART_FLOW_CTRL_TRIGGER_LEVEL_POS    (0u)  /* [7:0] RTS RX FIFO trigger level         */
    #define i2c_master_UART_FLOW_CTRL_RTS_POLARITY_POS     (16u) /* [16]  Polarity of the RTS output signal */
    #define i2c_master_UART_FLOW_CTRL_CTS_POLARITY_POS     (24u) /* [24]  Polarity of the CTS input signal  */
    #define i2c_master_UART_FLOW_CTRL_CTS_ENABLED_POS      (25u) /* [25]  Enable CTS signal                 */
    #define i2c_master_UART_FLOW_CTRL_TRIGGER_LEVEL_MASK   ((uint32) i2c_master_FF_DATA_NR_LOG2_MASK)
    #define i2c_master_UART_FLOW_CTRL_RTS_POLARITY         ((uint32) 0x01u << \
                                                                       i2c_master_UART_FLOW_CTRL_RTS_POLARITY_POS)
    #define i2c_master_UART_FLOW_CTRL_CTS_POLARITY         ((uint32) 0x01u << \
                                                                       i2c_master_UART_FLOW_CTRL_CTS_POLARITY_POS)
    #define i2c_master_UART_FLOW_CTRL_CTS_ENABLE           ((uint32) 0x01u << \
                                                                       i2c_master_UART_FLOW_CTRL_CTS_ENABLED_POS)
#endif /* !(i2c_master_CY_SCBIP_V0 || i2c_master_CY_SCBIP_V1) */

/* i2c_master_I2C_CTRL */
#define i2c_master_I2C_CTRL_HIGH_PHASE_OVS_POS           (0u)   /* [3:0] Oversampling factor high: master only */
#define i2c_master_I2C_CTRL_LOW_PHASE_OVS_POS            (4u)   /* [7:4] Oversampling factor low:  master only */
#define i2c_master_I2C_CTRL_M_READY_DATA_ACK_POS         (8u)   /* [8]   Master ACKs data while RX FIFO != FULL*/
#define i2c_master_I2C_CTRL_M_NOT_READY_DATA_NACK_POS    (9u)   /* [9]   Master NACKs data if RX FIFO ==  FULL */
#define i2c_master_I2C_CTRL_S_GENERAL_IGNORE_POS         (11u)  /* [11]  Slave ignores General call            */
#define i2c_master_I2C_CTRL_S_READY_ADDR_ACK_POS         (12u)  /* [12]  Slave ACKs Address if RX FIFO != FULL */
#define i2c_master_I2C_CTRL_S_READY_DATA_ACK_POS         (13u)  /* [13]  Slave ACKs data while RX FIFO == FULL */
#define i2c_master_I2C_CTRL_S_NOT_READY_ADDR_NACK_POS    (14u)  /* [14]  Slave NACKs address if RX FIFO == FULL*/
#define i2c_master_I2C_CTRL_S_NOT_READY_DATA_NACK_POS    (15u)  /* [15]  Slave NACKs data if RX FIFO is  FULL  */
#define i2c_master_I2C_CTRL_LOOPBACK_POS                 (16u)  /* [16]  Loop-back                             */
#define i2c_master_I2C_CTRL_SLAVE_MODE_POS               (30u)  /* [30]  Slave mode enabled                    */
#define i2c_master_I2C_CTRL_MASTER_MODE_POS              (31u)  /* [31]  Master mode enabled                   */
#define i2c_master_I2C_CTRL_HIGH_PHASE_OVS_MASK  ((uint32) 0x0Fu)
#define i2c_master_I2C_CTRL_LOW_PHASE_OVS_MASK   ((uint32) 0x0Fu << \
                                                                i2c_master_I2C_CTRL_LOW_PHASE_OVS_POS)
#define i2c_master_I2C_CTRL_M_READY_DATA_ACK      ((uint32) 0x01u << \
                                                                i2c_master_I2C_CTRL_M_READY_DATA_ACK_POS)
#define i2c_master_I2C_CTRL_M_NOT_READY_DATA_NACK ((uint32) 0x01u << \
                                                                i2c_master_I2C_CTRL_M_NOT_READY_DATA_NACK_POS)
#define i2c_master_I2C_CTRL_S_GENERAL_IGNORE      ((uint32) 0x01u << \
                                                                i2c_master_I2C_CTRL_S_GENERAL_IGNORE_POS)
#define i2c_master_I2C_CTRL_S_READY_ADDR_ACK      ((uint32) 0x01u << \
                                                                i2c_master_I2C_CTRL_S_READY_ADDR_ACK_POS)
#define i2c_master_I2C_CTRL_S_READY_DATA_ACK      ((uint32) 0x01u << \
                                                                i2c_master_I2C_CTRL_S_READY_DATA_ACK_POS)
#define i2c_master_I2C_CTRL_S_NOT_READY_ADDR_NACK ((uint32) 0x01u << \
                                                                i2c_master_I2C_CTRL_S_NOT_READY_ADDR_NACK_POS)
#define i2c_master_I2C_CTRL_S_NOT_READY_DATA_NACK ((uint32) 0x01u << \
                                                                i2c_master_I2C_CTRL_S_NOT_READY_DATA_NACK_POS)
#define i2c_master_I2C_CTRL_LOOPBACK              ((uint32) 0x01u << \
                                                                i2c_master_I2C_CTRL_LOOPBACK_POS)
#define i2c_master_I2C_CTRL_SLAVE_MODE            ((uint32) 0x01u << \
                                                                i2c_master_I2C_CTRL_SLAVE_MODE_POS)
#define i2c_master_I2C_CTRL_MASTER_MODE           ((uint32) 0x01u << \
                                                                i2c_master_I2C_CTRL_MASTER_MODE_POS)
#define i2c_master_I2C_CTRL_SLAVE_MASTER_MODE_MASK    ((uint32) 0x03u << \
                                                                i2c_master_I2C_CTRL_SLAVE_MODE_POS)

/* i2c_master_I2C_STATUS_REG  */
#define i2c_master_I2C_STATUS_BUS_BUSY_POS    (0u)  /* [0]    Bus busy: internally clocked */
#define i2c_master_I2C_STATUS_S_READ_POS      (4u)  /* [4]    Slave is read by master      */
#define i2c_master_I2C_STATUS_M_READ_POS      (5u)  /* [5]    Master reads Slave           */
#define i2c_master_I2C_STATUS_EZBUF_ADDR_POS  (8u)  /* [15:8] EZAddress                    */
#define i2c_master_I2C_STATUS_BUS_BUSY        ((uint32) 0x01u)
#define i2c_master_I2C_STATUS_S_READ          ((uint32) 0x01u << i2c_master_I2C_STATUS_S_READ_POS)
#define i2c_master_I2C_STATUS_M_READ          ((uint32) 0x01u << i2c_master_I2C_STATUS_M_READ_POS)
#define i2c_master_I2C_STATUS_EZBUF_ADDR_MASK ((uint32) 0xFFu << i2c_master_I2C_STATUS_EZBUF_ADDR_POS)

/* i2c_master_I2C_MASTER_CMD_REG */
#define i2c_master_I2C_MASTER_CMD_M_START_POS             (0u)  /* [0] Master generate Start                */
#define i2c_master_I2C_MASTER_CMD_M_START_ON_IDLE_POS     (1u)  /* [1] Master generate Start if bus is free */
#define i2c_master_I2C_MASTER_CMD_M_ACK_POS               (2u)  /* [2] Master generate ACK                  */
#define i2c_master_I2C_MASTER_CMD_M_NACK_POS              (3u)  /* [3] Master generate NACK                 */
#define i2c_master_I2C_MASTER_CMD_M_STOP_POS              (4u)  /* [4] Master generate Stop                 */
#define i2c_master_I2C_MASTER_CMD_M_START         ((uint32) 0x01u)
#define i2c_master_I2C_MASTER_CMD_M_START_ON_IDLE ((uint32) 0x01u << \
                                                                   i2c_master_I2C_MASTER_CMD_M_START_ON_IDLE_POS)
#define i2c_master_I2C_MASTER_CMD_M_ACK           ((uint32) 0x01u << \
                                                                   i2c_master_I2C_MASTER_CMD_M_ACK_POS)
#define i2c_master_I2C_MASTER_CMD_M_NACK          ((uint32) 0x01u << \
                                                                    i2c_master_I2C_MASTER_CMD_M_NACK_POS)
#define i2c_master_I2C_MASTER_CMD_M_STOP          ((uint32) 0x01u << \
                                                                    i2c_master_I2C_MASTER_CMD_M_STOP_POS)

/* i2c_master_I2C_SLAVE_CMD_REG  */
#define i2c_master_I2C_SLAVE_CMD_S_ACK_POS    (0u)  /* [0] Slave generate ACK  */
#define i2c_master_I2C_SLAVE_CMD_S_NACK_POS   (1u)  /* [1] Slave generate NACK */
#define i2c_master_I2C_SLAVE_CMD_S_ACK        ((uint32) 0x01u)
#define i2c_master_I2C_SLAVE_CMD_S_NACK       ((uint32) 0x01u << i2c_master_I2C_SLAVE_CMD_S_NACK_POS)

#define i2c_master_I2C_SLAVE_CMD_S_ACK_POS    (0u)  /* [0] Slave generate ACK  */
#define i2c_master_I2C_SLAVE_CMD_S_NACK_POS   (1u)  /* [1] Slave generate NACK */
#define i2c_master_I2C_SLAVE_CMD_S_ACK        ((uint32) 0x01u)
#define i2c_master_I2C_SLAVE_CMD_S_NACK       ((uint32) 0x01u << i2c_master_I2C_SLAVE_CMD_S_NACK_POS)

/* i2c_master_I2C_CFG_REG */
#if (i2c_master_CY_SCBIP_V0)
#define i2c_master_I2C_CFG_SDA_FILT_HYS_POS           (0u)  /* [1:0]   Trim bits for the I2C SDA filter         */
#define i2c_master_I2C_CFG_SDA_FILT_TRIM_POS          (2u)  /* [3:2]   Trim bits for the I2C SDA filter         */
#define i2c_master_I2C_CFG_SCL_FILT_HYS_POS           (4u)  /* [5:4]   Trim bits for the I2C SCL filter         */
#define i2c_master_I2C_CFG_SCL_FILT_TRIM_POS          (6u)  /* [7:6]   Trim bits for the I2C SCL filter         */
#define i2c_master_I2C_CFG_SDA_FILT_OUT_HYS_POS       (8u)  /* [9:8]   Trim bits for I2C SDA filter output path */
#define i2c_master_I2C_CFG_SDA_FILT_OUT_TRIM_POS      (10u) /* [11:10] Trim bits for I2C SDA filter output path */
#define i2c_master_I2C_CFG_SDA_FILT_HS_POS            (16u) /* [16]    '0': 50 ns filter, '1': 10 ns filter     */
#define i2c_master_I2C_CFG_SDA_FILT_ENABLED_POS       (17u) /* [17]    I2C SDA filter enabled                   */
#define i2c_master_I2C_CFG_SCL_FILT_HS_POS            (24u) /* [24]    '0': 50 ns filter, '1': 10 ns filter     */
#define i2c_master_I2C_CFG_SCL_FILT_ENABLED_POS       (25u) /* [25]    I2C SCL filter enabled                   */
#define i2c_master_I2C_CFG_SDA_FILT_OUT_HS_POS        (26u) /* [26]    '0': 50 ns filter, '1': 10 ns filter     */
#define i2c_master_I2C_CFG_SDA_FILT_OUT_ENABLED_POS   (27u) /* [27]    I2C SDA output delay filter enabled      */
#define i2c_master_I2C_CFG_SDA_FILT_HYS_MASK          ((uint32) 0x03u)
#define i2c_master_I2C_CFG_SDA_FILT_TRIM_MASK         ((uint32) 0x03u << \
                                                                i2c_master_I2C_CFG_SDA_FILT_TRIM_POS)
#define i2c_master_I2C_CFG_SCL_FILT_HYS_MASK          ((uint32) 0x03u << \
                                                                i2c_master_I2C_CFG_SCL_FILT_HYS_POS)
#define i2c_master_I2C_CFG_SCL_FILT_TRIM_MASK         ((uint32) 0x03u << \
                                                                i2c_master_I2C_CFG_SCL_FILT_TRIM_POS)
#define i2c_master_I2C_CFG_SDA_FILT_OUT_HYS_MASK      ((uint32) 0x03u << \
                                                                i2c_master_I2C_CFG_SDA_FILT_OUT_HYS_POS)
#define i2c_master_I2C_CFG_SDA_FILT_OUT_TRIM_MASK     ((uint32) 0x03u << \
                                                                i2c_master_I2C_CFG_SDA_FILT_OUT_TRIM_POS)
#define i2c_master_I2C_CFG_SDA_FILT_HS                ((uint32) 0x01u << \
                                                                i2c_master_I2C_CFG_SDA_FILT_HS_POS)
#define i2c_master_I2C_CFG_SDA_FILT_ENABLED           ((uint32) 0x01u << \
                                                                i2c_master_I2C_CFG_SDA_FILT_ENABLED_POS)
#define i2c_master_I2C_CFG_SCL_FILT_HS                ((uint32) 0x01u << \
                                                                i2c_master_I2C_CFG_SCL_FILT_HS_POS)
#define i2c_master_I2C_CFG_SCL_FILT_ENABLED           ((uint32) 0x01u << \
                                                                i2c_master_I2C_CFG_SCL_FILT_ENABLED_POS)
#define i2c_master_I2C_CFG_SDA_FILT_OUT_HS            ((uint32) 0x01u << \
                                                                i2c_master_I2C_CFG_SDA_FILT_OUT_HS_POS)
#define i2c_master_I2C_CFG_SDA_FILT_OUT_ENABLED       ((uint32) 0x01u << \
                                                                i2c_master_I2C_CFG_SDA_FILT_OUT_ENABLED_POS)
#else
#define i2c_master_I2C_CFG_SDA_IN_FILT_TRIM_POS   (0u)  /* [1:0] Trim bits for "i2c_sda_in" 50 ns filter */
#define i2c_master_I2C_CFG_SDA_IN_FILT_SEL_POS    (4u)  /* [4]   "i2c_sda_in" filter delay: 0 ns and 50 ns */
#define i2c_master_I2C_CFG_SCL_IN_FILT_TRIM_POS   (8u)  /* [9:8] Trim bits for "i2c_scl_in" 50 ns filter */
#define i2c_master_I2C_CFG_SCL_IN_FILT_SEL_POS    (12u) /* [12]  "i2c_scl_in" filter delay: 0 ns and 50 ns */
#define i2c_master_I2C_CFG_SDA_OUT_FILT0_TRIM_POS (16u) /* [17:16] Trim bits for "i2c_sda_out" 50 ns filter 0 */
#define i2c_master_I2C_CFG_SDA_OUT_FILT1_TRIM_POS (18u) /* [19:18] Trim bits for "i2c_sda_out" 50 ns filter 1 */
#define i2c_master_I2C_CFG_SDA_OUT_FILT2_TRIM_POS (20u) /* [21:20] Trim bits for "i2c_sda_out" 50 ns filter 2 */
#define i2c_master_I2C_CFG_SDA_OUT_FILT_SEL_POS   (28u) /* [29:28] Cumulative "i2c_sda_out" filter delay: */

#define i2c_master_I2C_CFG_SDA_IN_FILT_TRIM_MASK  ((uint32) 0x03u)
#define i2c_master_I2C_CFG_SDA_IN_FILT_SEL        ((uint32) 0x01u << i2c_master_I2C_CFG_SDA_IN_FILT_SEL_POS)
#define i2c_master_I2C_CFG_SCL_IN_FILT_TRIM_MASK  ((uint32) 0x03u << \
                                                            i2c_master_I2C_CFG_SCL_IN_FILT_TRIM_POS)
#define i2c_master_I2C_CFG_SCL_IN_FILT_SEL        ((uint32) 0x01u << i2c_master_I2C_CFG_SCL_IN_FILT_SEL_POS)
#define i2c_master_I2C_CFG_SDA_OUT_FILT0_TRIM_MASK ((uint32) 0x03u << \
                                                            i2c_master_I2C_CFG_SDA_OUT_FILT0_TRIM_POS)
#define i2c_master_I2C_CFG_SDA_OUT_FILT1_TRIM_MASK ((uint32) 0x03u << \
                                                            i2c_master_I2C_CFG_SDA_OUT_FILT1_TRIM_POS)
#define i2c_master_I2C_CFG_SDA_OUT_FILT2_TRIM_MASK ((uint32) 0x03u << \
                                                            i2c_master_I2C_CFG_SDA_OUT_FILT2_TRIM_POS)
#define i2c_master_I2C_CFG_SDA_OUT_FILT_SEL_MASK   ((uint32) 0x03u << \
                                                            i2c_master_I2C_CFG_SDA_OUT_FILT_SEL_POS)
#endif /* (i2c_master_CY_SCBIP_V0) */


/* i2c_master_TX_CTRL_REG */
#define i2c_master_TX_CTRL_DATA_WIDTH_POS     (0u)  /* [3:0] Data frame width: (Data width - 1) */
#define i2c_master_TX_CTRL_MSB_FIRST_POS      (8u)  /* [8]   MSB first shifter-out             */
#define i2c_master_TX_CTRL_ENABLED_POS        (31u) /* [31]  Transmitter enabled               */
#define i2c_master_TX_CTRL_DATA_WIDTH_MASK    ((uint32) 0x0Fu)
#define i2c_master_TX_CTRL_MSB_FIRST          ((uint32) 0x01u << i2c_master_TX_CTRL_MSB_FIRST_POS)
#define i2c_master_TX_CTRL_LSB_FIRST          ((uint32) 0x00u)
#define i2c_master_TX_CTRL_ENABLED            ((uint32) 0x01u << i2c_master_TX_CTRL_ENABLED_POS)

/* i2c_master_TX_CTRL_FIFO_REG */
#define i2c_master_TX_FIFO_CTRL_TRIGGER_LEVEL_POS     (0u)  /* [2:0] Trigger level                              */
#define i2c_master_TX_FIFO_CTRL_CLEAR_POS             (16u) /* [16]  Clear TX FIFO: cleared after set           */
#define i2c_master_TX_FIFO_CTRL_FREEZE_POS            (17u) /* [17]  Freeze TX FIFO: HW do not inc read pointer */
#define i2c_master_TX_FIFO_CTRL_TRIGGER_LEVEL_MASK    ((uint32) i2c_master_FF_DATA_NR_LOG2_MASK)
#define i2c_master_TX_FIFO_CTRL_CLEAR                 ((uint32) 0x01u << i2c_master_TX_FIFO_CTRL_CLEAR_POS)
#define i2c_master_TX_FIFO_CTRL_FREEZE                ((uint32) 0x01u << i2c_master_TX_FIFO_CTRL_FREEZE_POS)

/* i2c_master_TX_FIFO_STATUS_REG */
#define i2c_master_TX_FIFO_STATUS_USED_POS    (0u)  /* [3:0]   Amount of entries in TX FIFO */
#define i2c_master_TX_FIFO_SR_VALID_POS       (15u) /* [15]    Shifter status of TX FIFO    */
#define i2c_master_TX_FIFO_STATUS_RD_PTR_POS  (16u) /* [18:16] TX FIFO read pointer         */
#define i2c_master_TX_FIFO_STATUS_WR_PTR_POS  (24u) /* [26:24] TX FIFO write pointer        */
#define i2c_master_TX_FIFO_STATUS_USED_MASK   ((uint32) i2c_master_FF_DATA_NR_LOG2_PLUS1_MASK)
#define i2c_master_TX_FIFO_SR_VALID           ((uint32) 0x01u << i2c_master_TX_FIFO_SR_VALID_POS)
#define i2c_master_TX_FIFO_STATUS_RD_PTR_MASK ((uint32) i2c_master_FF_DATA_NR_LOG2_MASK << \
                                                                    i2c_master_TX_FIFO_STATUS_RD_PTR_POS)
#define i2c_master_TX_FIFO_STATUS_WR_PTR_MASK ((uint32) i2c_master_FF_DATA_NR_LOG2_MASK << \
                                                                    i2c_master_TX_FIFO_STATUS_WR_PTR_POS)

/* i2c_master_TX_FIFO_WR_REG */
#define i2c_master_TX_FIFO_WR_POS    (0u)  /* [15:0] Data written into TX FIFO */
#define i2c_master_TX_FIFO_WR_MASK   ((uint32) 0xFFu)

/* i2c_master_RX_CTRL_REG */
#define i2c_master_RX_CTRL_DATA_WIDTH_POS     (0u)  /* [3:0] Data frame width: (Data width - 1) */
#define i2c_master_RX_CTRL_MSB_FIRST_POS      (8u)  /* [8]   MSB first shifter-out             */
#define i2c_master_RX_CTRL_MEDIAN_POS         (9u)  /* [9]   Median filter                     */
#define i2c_master_RX_CTRL_ENABLED_POS        (31u) /* [31]  Receiver enabled                  */
#define i2c_master_RX_CTRL_DATA_WIDTH_MASK    ((uint32) 0x0Fu)
#define i2c_master_RX_CTRL_MSB_FIRST          ((uint32) 0x01u << i2c_master_RX_CTRL_MSB_FIRST_POS)
#define i2c_master_RX_CTRL_LSB_FIRST          ((uint32) 0x00u)
#define i2c_master_RX_CTRL_MEDIAN             ((uint32) 0x01u << i2c_master_RX_CTRL_MEDIAN_POS)
#define i2c_master_RX_CTRL_ENABLED            ((uint32) 0x01u << i2c_master_RX_CTRL_ENABLED_POS)


/* i2c_master_RX_FIFO_CTRL_REG */
#define i2c_master_RX_FIFO_CTRL_TRIGGER_LEVEL_POS     (0u)   /* [2:0] Trigger level                            */
#define i2c_master_RX_FIFO_CTRL_CLEAR_POS             (16u)  /* [16]  Clear RX FIFO: clear after set           */
#define i2c_master_RX_FIFO_CTRL_FREEZE_POS            (17u)  /* [17]  Freeze RX FIFO: HW writes has not effect */
#define i2c_master_RX_FIFO_CTRL_TRIGGER_LEVEL_MASK    ((uint32) i2c_master_FF_DATA_NR_LOG2_MASK)
#define i2c_master_RX_FIFO_CTRL_CLEAR                 ((uint32) 0x01u << i2c_master_RX_FIFO_CTRL_CLEAR_POS)
#define i2c_master_RX_FIFO_CTRL_FREEZE                ((uint32) 0x01u << i2c_master_RX_FIFO_CTRL_FREEZE_POS)

/* i2c_master_RX_FIFO_STATUS_REG */
#define i2c_master_RX_FIFO_STATUS_USED_POS    (0u)   /* [3:0]   Amount of entries in RX FIFO */
#define i2c_master_RX_FIFO_SR_VALID_POS       (15u)  /* [15]    Shifter status of RX FIFO    */
#define i2c_master_RX_FIFO_STATUS_RD_PTR_POS  (16u)  /* [18:16] RX FIFO read pointer         */
#define i2c_master_RX_FIFO_STATUS_WR_PTR_POS  (24u)  /* [26:24] RX FIFO write pointer        */
#define i2c_master_RX_FIFO_STATUS_USED_MASK   ((uint32) i2c_master_FF_DATA_NR_LOG2_PLUS1_MASK)
#define i2c_master_RX_FIFO_SR_VALID           ((uint32) 0x01u << i2c_master_RX_FIFO_SR_VALID_POS)
#define i2c_master_RX_FIFO_STATUS_RD_PTR_MASK ((uint32) i2c_master_FF_DATA_NR_LOG2_MASK << \
                                                                    i2c_master_RX_FIFO_STATUS_RD_PTR_POS)
#define i2c_master_RX_FIFO_STATUS_WR_PTR_MASK ((uint32) i2c_master_FF_DATA_NR_LOG2_MASK << \
                                                                    i2c_master_RX_FIFO_STATUS_WR_PTR_POS)

/* i2c_master_RX_MATCH_REG */
#define i2c_master_RX_MATCH_ADDR_POS     (0u)  /* [7:0]   Slave address                        */
#define i2c_master_RX_MATCH_MASK_POS     (16u) /* [23:16] Slave address mask: 0 - doesn't care */
#define i2c_master_RX_MATCH_ADDR_MASK    ((uint32) 0xFFu)
#define i2c_master_RX_MATCH_MASK_MASK    ((uint32) 0xFFu << i2c_master_RX_MATCH_MASK_POS)

/* i2c_master_RX_FIFO_WR_REG */
#define i2c_master_RX_FIFO_RD_POS    (0u)  /* [15:0] Data read from RX FIFO */
#define i2c_master_RX_FIFO_RD_MASK   ((uint32) 0xFFu)

/* i2c_master_RX_FIFO_RD_SILENT_REG */
#define i2c_master_RX_FIFO_RD_SILENT_POS     (0u)  /* [15:0] Data read from RX FIFO: not remove data from FIFO */
#define i2c_master_RX_FIFO_RD_SILENT_MASK    ((uint32) 0xFFu)

/* i2c_master_RX_FIFO_RD_SILENT_REG */
#define i2c_master_RX_FIFO_RD_SILENT_POS     (0u)  /* [15:0] Data read from RX FIFO: not remove data from FIFO */
#define i2c_master_RX_FIFO_RD_SILENT_MASK    ((uint32) 0xFFu)

/* i2c_master_EZBUF_DATA_REG */
#define i2c_master_EZBUF_DATA_POS   (0u)  /* [7:0] Data from EZ Memory */
#define i2c_master_EZBUF_DATA_MASK  ((uint32) 0xFFu)

/*  i2c_master_INTR_CAUSE_REG */
#define i2c_master_INTR_CAUSE_MASTER_POS  (0u)  /* [0] Master interrupt active                 */
#define i2c_master_INTR_CAUSE_SLAVE_POS   (1u)  /* [1] Slave interrupt active                  */
#define i2c_master_INTR_CAUSE_TX_POS      (2u)  /* [2] Transmitter interrupt active            */
#define i2c_master_INTR_CAUSE_RX_POS      (3u)  /* [3] Receiver interrupt active               */
#define i2c_master_INTR_CAUSE_I2C_EC_POS  (4u)  /* [4] Externally clock I2C interrupt active   */
#define i2c_master_INTR_CAUSE_SPI_EC_POS  (5u)  /* [5] Externally clocked SPI interrupt active */
#define i2c_master_INTR_CAUSE_MASTER      ((uint32) 0x01u)
#define i2c_master_INTR_CAUSE_SLAVE       ((uint32) 0x01u << i2c_master_INTR_CAUSE_SLAVE_POS)
#define i2c_master_INTR_CAUSE_TX          ((uint32) 0x01u << i2c_master_INTR_CAUSE_TX_POS)
#define i2c_master_INTR_CAUSE_RX          ((uint32) 0x01u << i2c_master_INTR_CAUSE_RX_POS)
#define i2c_master_INTR_CAUSE_I2C_EC      ((uint32) 0x01u << i2c_master_INTR_CAUSE_I2C_EC_POS)
#define i2c_master_INTR_CAUSE_SPI_EC      ((uint32) 0x01u << i2c_master_INTR_CAUSE_SPI_EC_POS)

/* i2c_master_INTR_SPI_EC_REG, i2c_master_INTR_SPI_EC_MASK_REG, i2c_master_INTR_SPI_EC_MASKED_REG */
#define i2c_master_INTR_SPI_EC_WAKE_UP_POS          (0u)  /* [0] Address match: triggers wakeup of chip */
#define i2c_master_INTR_SPI_EC_EZBUF_STOP_POS       (1u)  /* [1] Externally clocked Stop detected       */
#define i2c_master_INTR_SPI_EC_EZBUF_WRITE_STOP_POS (2u)  /* [2] Externally clocked Write Stop detected */
#define i2c_master_INTR_SPI_EC_WAKE_UP              ((uint32) 0x01u)
#define i2c_master_INTR_SPI_EC_EZBUF_STOP           ((uint32) 0x01u << \
                                                                    i2c_master_INTR_SPI_EC_EZBUF_STOP_POS)
#define i2c_master_INTR_SPI_EC_EZBUF_WRITE_STOP     ((uint32) 0x01u << \
                                                                    i2c_master_INTR_SPI_EC_EZBUF_WRITE_STOP_POS)

/* i2c_master_INTR_I2C_EC, i2c_master_INTR_I2C_EC_MASK, i2c_master_INTR_I2C_EC_MASKED */
#define i2c_master_INTR_I2C_EC_WAKE_UP_POS          (0u)  /* [0] Address match: triggers wakeup of chip */
#define i2c_master_INTR_I2C_EC_EZBUF_STOP_POS       (1u)  /* [1] Externally clocked Stop detected       */
#define i2c_master_INTR_I2C_EC_EZBUF_WRITE_STOP_POS (2u)  /* [2] Externally clocked Write Stop detected */
#define i2c_master_INTR_I2C_EC_WAKE_UP              ((uint32) 0x01u)
#define i2c_master_INTR_I2C_EC_EZBUF_STOP           ((uint32) 0x01u << \
                                                                    i2c_master_INTR_I2C_EC_EZBUF_STOP_POS)
#define i2c_master_INTR_I2C_EC_EZBUF_WRITE_STOP     ((uint32) 0x01u << \
                                                                    i2c_master_INTR_I2C_EC_EZBUF_WRITE_STOP_POS)

/* i2c_master_INTR_MASTER, i2c_master_INTR_MASTER_SET,
   i2c_master_INTR_MASTER_MASK, i2c_master_INTR_MASTER_MASKED */
#define i2c_master_INTR_MASTER_I2C_ARB_LOST_POS   (0u)  /* [0] Master lost arbitration                          */
#define i2c_master_INTR_MASTER_I2C_NACK_POS       (1u)  /* [1] Master receives NACK: address or write to slave  */
#define i2c_master_INTR_MASTER_I2C_ACK_POS        (2u)  /* [2] Master receives NACK: address or write to slave  */
#define i2c_master_INTR_MASTER_I2C_STOP_POS       (4u)  /* [4] Master detects the Stop: only self generated Stop*/
#define i2c_master_INTR_MASTER_I2C_BUS_ERROR_POS  (8u)  /* [8] Master detects bus error: misplaced Start or Stop*/
#define i2c_master_INTR_MASTER_SPI_DONE_POS       (9u)  /* [9] Master complete transfer: Only for SPI           */
#define i2c_master_INTR_MASTER_I2C_ARB_LOST       ((uint32) 0x01u)
#define i2c_master_INTR_MASTER_I2C_NACK           ((uint32) 0x01u << i2c_master_INTR_MASTER_I2C_NACK_POS)
#define i2c_master_INTR_MASTER_I2C_ACK            ((uint32) 0x01u << i2c_master_INTR_MASTER_I2C_ACK_POS)
#define i2c_master_INTR_MASTER_I2C_STOP           ((uint32) 0x01u << i2c_master_INTR_MASTER_I2C_STOP_POS)
#define i2c_master_INTR_MASTER_I2C_BUS_ERROR      ((uint32) 0x01u << \
                                                                    i2c_master_INTR_MASTER_I2C_BUS_ERROR_POS)
#define i2c_master_INTR_MASTER_SPI_DONE           ((uint32) 0x01u << i2c_master_INTR_MASTER_SPI_DONE_POS)

/*
* i2c_master_INTR_SLAVE, i2c_master_INTR_SLAVE_SET,
* i2c_master_INTR_SLAVE_MASK, i2c_master_INTR_SLAVE_MASKED
*/
#define i2c_master_INTR_SLAVE_I2C_ARB_LOST_POS         (0u)  /* [0]  Slave lost arbitration                   */
#define i2c_master_INTR_SLAVE_I2C_NACK_POS             (1u)  /* [1]  Slave receives NACK: master reads data   */
#define i2c_master_INTR_SLAVE_I2C_ACK_POS              (2u)  /* [2]  Slave receives ACK: master reads data    */
#define i2c_master_INTR_SLAVE_I2C_WRITE_STOP_POS       (3u)  /* [3]  Slave detects end of write transaction   */
#define i2c_master_INTR_SLAVE_I2C_STOP_POS             (4u)  /* [4]  Slave detects end of transaction intended */
#define i2c_master_INTR_SLAVE_I2C_START_POS            (5u)  /* [5]  Slave detects Start                      */
#define i2c_master_INTR_SLAVE_I2C_ADDR_MATCH_POS       (6u)  /* [6]  Slave address matches                    */
#define i2c_master_INTR_SLAVE_I2C_GENERAL_POS          (7u)  /* [7]  General call received                    */
#define i2c_master_INTR_SLAVE_I2C_BUS_ERROR_POS        (8u)  /* [8]  Slave detects bus error                  */
#define i2c_master_INTR_SLAVE_SPI_EZBUF_WRITE_STOP_POS (9u)  /* [9]  Slave write complete: Only for SPI       */
#define i2c_master_INTR_SLAVE_SPI_EZBUF_STOP_POS       (10u) /* [10] Slave end of transaction: Only for SPI   */
#define i2c_master_INTR_SLAVE_SPI_BUS_ERROR_POS        (11u) /* [11] Slave detects bus error: Only for SPI    */
#define i2c_master_INTR_SLAVE_I2C_ARB_LOST             ((uint32) 0x01u)
#define i2c_master_INTR_SLAVE_I2C_NACK                 ((uint32) 0x01u << \
                                                                    i2c_master_INTR_SLAVE_I2C_NACK_POS)
#define i2c_master_INTR_SLAVE_I2C_ACK                  ((uint32) 0x01u << \
                                                                    i2c_master_INTR_SLAVE_I2C_ACK_POS)
#define i2c_master_INTR_SLAVE_I2C_WRITE_STOP           ((uint32) 0x01u << \
                                                                    i2c_master_INTR_SLAVE_I2C_WRITE_STOP_POS)
#define i2c_master_INTR_SLAVE_I2C_STOP                 ((uint32) 0x01u << \
                                                                    i2c_master_INTR_SLAVE_I2C_STOP_POS)
#define i2c_master_INTR_SLAVE_I2C_START                ((uint32) 0x01u << \
                                                                    i2c_master_INTR_SLAVE_I2C_START_POS)
#define i2c_master_INTR_SLAVE_I2C_ADDR_MATCH           ((uint32) 0x01u << \
                                                                    i2c_master_INTR_SLAVE_I2C_ADDR_MATCH_POS)
#define i2c_master_INTR_SLAVE_I2C_GENERAL              ((uint32) 0x01u << \
                                                                    i2c_master_INTR_SLAVE_I2C_GENERAL_POS)
#define i2c_master_INTR_SLAVE_I2C_BUS_ERROR            ((uint32) 0x01u << \
                                                                    i2c_master_INTR_SLAVE_I2C_BUS_ERROR_POS)
#define i2c_master_INTR_SLAVE_SPI_EZBUF_WRITE_STOP     ((uint32) 0x01u << \
                                                                   i2c_master_INTR_SLAVE_SPI_EZBUF_WRITE_STOP_POS)
#define i2c_master_INTR_SLAVE_SPI_EZBUF_STOP           ((uint32) 0x01u << \
                                                                    i2c_master_INTR_SLAVE_SPI_EZBUF_STOP_POS)
#define i2c_master_INTR_SLAVE_SPI_BUS_ERROR           ((uint32) 0x01u << \
                                                                    i2c_master_INTR_SLAVE_SPI_BUS_ERROR_POS)

/*
* i2c_master_INTR_TX, i2c_master_INTR_TX_SET,
* i2c_master_INTR_TX_MASK, i2c_master_INTR_TX_MASKED
*/
#define i2c_master_INTR_TX_TRIGGER_POS        (0u)  /* [0]  Trigger on TX FIFO entires                       */
#define i2c_master_INTR_TX_NOT_FULL_POS       (1u)  /* [1]  TX FIFO is not full                              */
#define i2c_master_INTR_TX_EMPTY_POS          (4u)  /* [4]  TX FIFO is empty                                 */
#define i2c_master_INTR_TX_OVERFLOW_POS       (5u)  /* [5]  Attempt to write to a full TX FIFO               */
#define i2c_master_INTR_TX_UNDERFLOW_POS      (6u)  /* [6]  Attempt to read from an empty TX FIFO            */
#define i2c_master_INTR_TX_BLOCKED_POS        (7u)  /* [7]  No access to the EZ memory                       */
#define i2c_master_INTR_TX_UART_NACK_POS      (8u)  /* [8]  UART transmitter received a NACK: SmartCard mode */
#define i2c_master_INTR_TX_UART_DONE_POS      (9u)  /* [9]  UART transmitter done even                       */
#define i2c_master_INTR_TX_UART_ARB_LOST_POS  (10u) /* [10] UART lost arbitration: LIN or SmartCard          */
#define i2c_master_INTR_TX_TRIGGER            ((uint32) 0x01u)
#define i2c_master_INTR_TX_FIFO_LEVEL         (i2c_master_INTR_TX_TRIGGER)
#define i2c_master_INTR_TX_NOT_FULL           ((uint32) 0x01u << i2c_master_INTR_TX_NOT_FULL_POS)
#define i2c_master_INTR_TX_EMPTY              ((uint32) 0x01u << i2c_master_INTR_TX_EMPTY_POS)
#define i2c_master_INTR_TX_OVERFLOW           ((uint32) 0x01u << i2c_master_INTR_TX_OVERFLOW_POS)
#define i2c_master_INTR_TX_UNDERFLOW          ((uint32) 0x01u << i2c_master_INTR_TX_UNDERFLOW_POS)
#define i2c_master_INTR_TX_BLOCKED            ((uint32) 0x01u << i2c_master_INTR_TX_BLOCKED_POS)
#define i2c_master_INTR_TX_UART_NACK          ((uint32) 0x01u << i2c_master_INTR_TX_UART_NACK_POS)
#define i2c_master_INTR_TX_UART_DONE          ((uint32) 0x01u << i2c_master_INTR_TX_UART_DONE_POS)
#define i2c_master_INTR_TX_UART_ARB_LOST      ((uint32) 0x01u << i2c_master_INTR_TX_UART_ARB_LOST_POS)

/*
* i2c_master_INTR_RX, i2c_master_INTR_RX_SET,
* i2c_master_INTR_RX_MASK, i2c_master_INTR_RX_MASKED
*/
#define i2c_master_INTR_RX_TRIGGER_POS        (0u)   /* [0]  Trigger on RX FIFO entires            */
#define i2c_master_INTR_RX_NOT_EMPTY_POS      (2u)   /* [2]  RX FIFO is not empty                  */
#define i2c_master_INTR_RX_FULL_POS           (3u)   /* [3]  RX FIFO is full                       */
#define i2c_master_INTR_RX_OVERFLOW_POS       (5u)   /* [5]  Attempt to write to a full RX FIFO    */
#define i2c_master_INTR_RX_UNDERFLOW_POS      (6u)   /* [6]  Attempt to read from an empty RX FIFO */
#define i2c_master_INTR_RX_BLOCKED_POS        (7u)   /* [7]  No access to the EZ memory            */
#define i2c_master_INTR_RX_FRAME_ERROR_POS    (8u)   /* [8]  Frame error in received data frame    */
#define i2c_master_INTR_RX_PARITY_ERROR_POS   (9u)   /* [9]  Parity error in received data frame   */
#define i2c_master_INTR_RX_BAUD_DETECT_POS    (10u)  /* [10] LIN baud rate detection is completed   */
#define i2c_master_INTR_RX_BREAK_DETECT_POS   (11u)  /* [11] Break detection is successful         */
#define i2c_master_INTR_RX_TRIGGER            ((uint32) 0x01u)
#define i2c_master_INTR_RX_FIFO_LEVEL         (i2c_master_INTR_RX_TRIGGER)
#define i2c_master_INTR_RX_NOT_EMPTY          ((uint32) 0x01u << i2c_master_INTR_RX_NOT_EMPTY_POS)
#define i2c_master_INTR_RX_FULL               ((uint32) 0x01u << i2c_master_INTR_RX_FULL_POS)
#define i2c_master_INTR_RX_OVERFLOW           ((uint32) 0x01u << i2c_master_INTR_RX_OVERFLOW_POS)
#define i2c_master_INTR_RX_UNDERFLOW          ((uint32) 0x01u << i2c_master_INTR_RX_UNDERFLOW_POS)
#define i2c_master_INTR_RX_BLOCKED            ((uint32) 0x01u << i2c_master_INTR_RX_BLOCKED_POS)
#define i2c_master_INTR_RX_FRAME_ERROR        ((uint32) 0x01u << i2c_master_INTR_RX_FRAME_ERROR_POS)
#define i2c_master_INTR_RX_PARITY_ERROR       ((uint32) 0x01u << i2c_master_INTR_RX_PARITY_ERROR_POS)
#define i2c_master_INTR_RX_BAUD_DETECT        ((uint32) 0x01u << i2c_master_INTR_RX_BAUD_DETECT_POS)
#define i2c_master_INTR_RX_BREAK_DETECT       ((uint32) 0x01u << i2c_master_INTR_RX_BREAK_DETECT_POS)

/* Define all interrupt sources */
#define i2c_master_INTR_I2C_EC_ALL    (i2c_master_INTR_I2C_EC_WAKE_UP    | \
                                             i2c_master_INTR_I2C_EC_EZBUF_STOP | \
                                             i2c_master_INTR_I2C_EC_EZBUF_WRITE_STOP)

#define i2c_master_INTR_SPI_EC_ALL    (i2c_master_INTR_SPI_EC_WAKE_UP    | \
                                             i2c_master_INTR_SPI_EC_EZBUF_STOP | \
                                             i2c_master_INTR_SPI_EC_EZBUF_WRITE_STOP)

#define i2c_master_INTR_MASTER_ALL    (i2c_master_INTR_MASTER_I2C_ARB_LOST  | \
                                             i2c_master_INTR_MASTER_I2C_NACK      | \
                                             i2c_master_INTR_MASTER_I2C_ACK       | \
                                             i2c_master_INTR_MASTER_I2C_STOP      | \
                                             i2c_master_INTR_MASTER_I2C_BUS_ERROR | \
                                             i2c_master_INTR_MASTER_SPI_DONE)

#define i2c_master_INTR_SLAVE_ALL     (i2c_master_INTR_SLAVE_I2C_ARB_LOST      | \
                                             i2c_master_INTR_SLAVE_I2C_NACK          | \
                                             i2c_master_INTR_SLAVE_I2C_ACK           | \
                                             i2c_master_INTR_SLAVE_I2C_WRITE_STOP    | \
                                             i2c_master_INTR_SLAVE_I2C_STOP          | \
                                             i2c_master_INTR_SLAVE_I2C_START         | \
                                             i2c_master_INTR_SLAVE_I2C_ADDR_MATCH    | \
                                             i2c_master_INTR_SLAVE_I2C_GENERAL       | \
                                             i2c_master_INTR_SLAVE_I2C_BUS_ERROR     | \
                                             i2c_master_INTR_SLAVE_SPI_EZBUF_WRITE_STOP | \
                                             i2c_master_INTR_SLAVE_SPI_EZBUF_STOP       | \
                                             i2c_master_INTR_SLAVE_SPI_BUS_ERROR)

#define i2c_master_INTR_TX_ALL        (i2c_master_INTR_TX_TRIGGER   | \
                                             i2c_master_INTR_TX_NOT_FULL  | \
                                             i2c_master_INTR_TX_EMPTY     | \
                                             i2c_master_INTR_TX_OVERFLOW  | \
                                             i2c_master_INTR_TX_UNDERFLOW | \
                                             i2c_master_INTR_TX_BLOCKED   | \
                                             i2c_master_INTR_TX_UART_NACK | \
                                             i2c_master_INTR_TX_UART_DONE | \
                                             i2c_master_INTR_TX_UART_ARB_LOST)

#define i2c_master_INTR_RX_ALL        (i2c_master_INTR_RX_TRIGGER      | \
                                             i2c_master_INTR_RX_NOT_EMPTY    | \
                                             i2c_master_INTR_RX_FULL         | \
                                             i2c_master_INTR_RX_OVERFLOW     | \
                                             i2c_master_INTR_RX_UNDERFLOW    | \
                                             i2c_master_INTR_RX_BLOCKED      | \
                                             i2c_master_INTR_RX_FRAME_ERROR  | \
                                             i2c_master_INTR_RX_PARITY_ERROR | \
                                             i2c_master_INTR_RX_BAUD_DETECT  | \
                                             i2c_master_INTR_RX_BREAK_DETECT)

/* I2C and EZI2C slave address defines */
#define i2c_master_I2C_SLAVE_ADDR_POS    (0x01u)    /* 7-bit address shift */
#define i2c_master_I2C_SLAVE_ADDR_MASK   (0xFEu)    /* 8-bit address mask */

/* OVS constants for IrDA Low Power operation */
#define i2c_master_CTRL_OVS_IRDA_LP_OVS16     (0x00u)
#define i2c_master_CTRL_OVS_IRDA_LP_OVS32     (0x01u)
#define i2c_master_CTRL_OVS_IRDA_LP_OVS48     (0x02u)
#define i2c_master_CTRL_OVS_IRDA_LP_OVS96     (0x03u)
#define i2c_master_CTRL_OVS_IRDA_LP_OVS192    (0x04u)
#define i2c_master_CTRL_OVS_IRDA_LP_OVS768    (0x05u)
#define i2c_master_CTRL_OVS_IRDA_LP_OVS1536   (0x06u)

/* OVS constant for IrDA */
#define i2c_master_CTRL_OVS_IRDA_OVS16        (i2c_master_UART_IRDA_LP_OVS16)


/***************************************
*    Common Macro Definitions
***************************************/

/* Re-enables the SCB IP. A clear enable bit has a different effect
* on the scb IP depending on the version:
*  CY_SCBIP_V0: resets state, status, TX and RX FIFOs.
*  CY_SCBIP_V1 or later: resets state, status, TX and RX FIFOs and interrupt sources.
* Clear I2C command registers are because they are not impacted by re-enable.
*/
#define i2c_master_SCB_SW_RESET   i2c_master_I2CFwBlockReset()

/* TX FIFO macro */
#define i2c_master_CLEAR_TX_FIFO \
                            do{        \
                                i2c_master_TX_FIFO_CTRL_REG |= ((uint32)  i2c_master_TX_FIFO_CTRL_CLEAR); \
                                i2c_master_TX_FIFO_CTRL_REG &= ((uint32) ~i2c_master_TX_FIFO_CTRL_CLEAR); \
                            }while(0)

#define i2c_master_GET_TX_FIFO_ENTRIES    (i2c_master_TX_FIFO_STATUS_REG & \
                                                 i2c_master_TX_FIFO_STATUS_USED_MASK)

#define i2c_master_GET_TX_FIFO_SR_VALID   ((0u != (i2c_master_TX_FIFO_STATUS_REG & \
                                                         i2c_master_TX_FIFO_SR_VALID)) ? (1u) : (0u))

/* RX FIFO macro */
#define i2c_master_CLEAR_RX_FIFO \
                            do{        \
                                i2c_master_RX_FIFO_CTRL_REG |= ((uint32)  i2c_master_RX_FIFO_CTRL_CLEAR); \
                                i2c_master_RX_FIFO_CTRL_REG &= ((uint32) ~i2c_master_RX_FIFO_CTRL_CLEAR); \
                            }while(0)

#define i2c_master_GET_RX_FIFO_ENTRIES    (i2c_master_RX_FIFO_STATUS_REG & \
                                                    i2c_master_RX_FIFO_STATUS_USED_MASK)

#define i2c_master_GET_RX_FIFO_SR_VALID   ((0u != (i2c_master_RX_FIFO_STATUS_REG & \
                                                         i2c_master_RX_FIFO_SR_VALID)) ? (1u) : (0u))

/* Write interrupt source: set sourceMask bits in i2c_master_INTR_X_MASK_REG */
#define i2c_master_WRITE_INTR_I2C_EC_MASK(sourceMask) \
                                                do{         \
                                                    i2c_master_INTR_I2C_EC_MASK_REG = (uint32) (sourceMask); \
                                                }while(0)

#if (!i2c_master_CY_SCBIP_V1)
    #define i2c_master_WRITE_INTR_SPI_EC_MASK(sourceMask) \
                                                do{         \
                                                    i2c_master_INTR_SPI_EC_MASK_REG = (uint32) (sourceMask); \
                                                }while(0)
#endif /* (!i2c_master_CY_SCBIP_V1) */

#define i2c_master_WRITE_INTR_MASTER_MASK(sourceMask) \
                                                do{         \
                                                    i2c_master_INTR_MASTER_MASK_REG = (uint32) (sourceMask); \
                                                }while(0)

#define i2c_master_WRITE_INTR_SLAVE_MASK(sourceMask)  \
                                                do{         \
                                                    i2c_master_INTR_SLAVE_MASK_REG = (uint32) (sourceMask); \
                                                }while(0)

#define i2c_master_WRITE_INTR_TX_MASK(sourceMask)     \
                                                do{         \
                                                    i2c_master_INTR_TX_MASK_REG = (uint32) (sourceMask); \
                                                }while(0)

#define i2c_master_WRITE_INTR_RX_MASK(sourceMask)     \
                                                do{         \
                                                    i2c_master_INTR_RX_MASK_REG = (uint32) (sourceMask); \
                                                }while(0)

/* Enable interrupt source: set sourceMask bits in i2c_master_INTR_X_MASK_REG */
#define i2c_master_ENABLE_INTR_I2C_EC(sourceMask) \
                                                do{     \
                                                    i2c_master_INTR_I2C_EC_MASK_REG |= (uint32) (sourceMask); \
                                                }while(0)
#if (!i2c_master_CY_SCBIP_V1)
    #define i2c_master_ENABLE_INTR_SPI_EC(sourceMask) \
                                                do{     \
                                                    i2c_master_INTR_SPI_EC_MASK_REG |= (uint32) (sourceMask); \
                                                }while(0)
#endif /* (!i2c_master_CY_SCBIP_V1) */

#define i2c_master_ENABLE_INTR_MASTER(sourceMask) \
                                                do{     \
                                                    i2c_master_INTR_MASTER_MASK_REG |= (uint32) (sourceMask); \
                                                }while(0)

#define i2c_master_ENABLE_INTR_SLAVE(sourceMask)  \
                                                do{     \
                                                    i2c_master_INTR_SLAVE_MASK_REG |= (uint32) (sourceMask); \
                                                }while(0)

#define i2c_master_ENABLE_INTR_TX(sourceMask)     \
                                                do{     \
                                                    i2c_master_INTR_TX_MASK_REG |= (uint32) (sourceMask); \
                                                }while(0)

#define i2c_master_ENABLE_INTR_RX(sourceMask)     \
                                                do{     \
                                                    i2c_master_INTR_RX_MASK_REG |= (uint32) (sourceMask); \
                                                }while(0)

/* Disable interrupt source: clear sourceMask bits in i2c_master_INTR_X_MASK_REG */
#define i2c_master_DISABLE_INTR_I2C_EC(sourceMask) \
                                do{                      \
                                    i2c_master_INTR_I2C_EC_MASK_REG &= ((uint32) ~((uint32) (sourceMask))); \
                                }while(0)

#if (!i2c_master_CY_SCBIP_V1)
    #define i2c_master_DISABLE_INTR_SPI_EC(sourceMask) \
                                do{                      \
                                    i2c_master_INTR_SPI_EC_MASK_REG &= ((uint32) ~((uint32) (sourceMask))); \
                                 }while(0)
#endif /* (!i2c_master_CY_SCBIP_V1) */

#define i2c_master_DISABLE_INTR_MASTER(sourceMask) \
                                do{                      \
                                i2c_master_INTR_MASTER_MASK_REG &= ((uint32) ~((uint32) (sourceMask))); \
                                }while(0)

#define i2c_master_DISABLE_INTR_SLAVE(sourceMask) \
                                do{                     \
                                    i2c_master_INTR_SLAVE_MASK_REG &= ((uint32) ~((uint32) (sourceMask))); \
                                }while(0)

#define i2c_master_DISABLE_INTR_TX(sourceMask)    \
                                do{                     \
                                    i2c_master_INTR_TX_MASK_REG &= ((uint32) ~((uint32) (sourceMask))); \
                                 }while(0)

#define i2c_master_DISABLE_INTR_RX(sourceMask)    \
                                do{                     \
                                    i2c_master_INTR_RX_MASK_REG &= ((uint32) ~((uint32) (sourceMask))); \
                                }while(0)

/* Set interrupt sources: write sourceMask bits in i2c_master_INTR_X_SET_REG */
#define i2c_master_SET_INTR_MASTER(sourceMask)    \
                                                do{     \
                                                    i2c_master_INTR_MASTER_SET_REG = (uint32) (sourceMask); \
                                                }while(0)

#define i2c_master_SET_INTR_SLAVE(sourceMask) \
                                                do{ \
                                                    i2c_master_INTR_SLAVE_SET_REG = (uint32) (sourceMask); \
                                                }while(0)

#define i2c_master_SET_INTR_TX(sourceMask)    \
                                                do{ \
                                                    i2c_master_INTR_TX_SET_REG = (uint32) (sourceMask); \
                                                }while(0)

#define i2c_master_SET_INTR_RX(sourceMask)    \
                                                do{ \
                                                    i2c_master_INTR_RX_SET_REG = (uint32) (sourceMask); \
                                                }while(0)

/* Clear interrupt sources: write sourceMask bits in i2c_master_INTR_X_REG */
#define i2c_master_CLEAR_INTR_I2C_EC(sourceMask)  \
                                                do{     \
                                                    i2c_master_INTR_I2C_EC_REG = (uint32) (sourceMask); \
                                                }while(0)

#if (!i2c_master_CY_SCBIP_V1)
    #define i2c_master_CLEAR_INTR_SPI_EC(sourceMask)  \
                                                do{     \
                                                    i2c_master_INTR_SPI_EC_REG = (uint32) (sourceMask); \
                                                }while(0)
#endif /* (!i2c_master_CY_SCBIP_V1) */

#define i2c_master_CLEAR_INTR_MASTER(sourceMask)  \
                                                do{     \
                                                    i2c_master_INTR_MASTER_REG = (uint32) (sourceMask); \
                                                }while(0)

#define i2c_master_CLEAR_INTR_SLAVE(sourceMask)   \
                                                do{     \
                                                    i2c_master_INTR_SLAVE_REG  = (uint32) (sourceMask); \
                                                }while(0)

#define i2c_master_CLEAR_INTR_TX(sourceMask)      \
                                                do{     \
                                                    i2c_master_INTR_TX_REG     = (uint32) (sourceMask); \
                                                }while(0)

#define i2c_master_CLEAR_INTR_RX(sourceMask)      \
                                                do{     \
                                                    i2c_master_INTR_RX_REG     = (uint32) (sourceMask); \
                                                }while(0)

/* Return true if sourceMask is set in i2c_master_INTR_CAUSE_REG */
#define i2c_master_CHECK_CAUSE_INTR(sourceMask)    (0u != (i2c_master_INTR_CAUSE_REG & (sourceMask)))

/* Return true if sourceMask is set in INTR_X_MASKED_REG */
#define i2c_master_CHECK_INTR_I2C_EC(sourceMask)  (0u != (i2c_master_INTR_I2C_EC_REG & (sourceMask)))
#if (!i2c_master_CY_SCBIP_V1)
    #define i2c_master_CHECK_INTR_SPI_EC(sourceMask)  (0u != (i2c_master_INTR_SPI_EC_REG & (sourceMask)))
#endif /* (!i2c_master_CY_SCBIP_V1) */
#define i2c_master_CHECK_INTR_MASTER(sourceMask)  (0u != (i2c_master_INTR_MASTER_REG & (sourceMask)))
#define i2c_master_CHECK_INTR_SLAVE(sourceMask)   (0u != (i2c_master_INTR_SLAVE_REG  & (sourceMask)))
#define i2c_master_CHECK_INTR_TX(sourceMask)      (0u != (i2c_master_INTR_TX_REG     & (sourceMask)))
#define i2c_master_CHECK_INTR_RX(sourceMask)      (0u != (i2c_master_INTR_RX_REG     & (sourceMask)))

/* Return true if sourceMask is set in i2c_master_INTR_X_MASKED_REG */
#define i2c_master_CHECK_INTR_I2C_EC_MASKED(sourceMask)   (0u != (i2c_master_INTR_I2C_EC_MASKED_REG & \
                                                                       (sourceMask)))
#if (!i2c_master_CY_SCBIP_V1)
    #define i2c_master_CHECK_INTR_SPI_EC_MASKED(sourceMask)   (0u != (i2c_master_INTR_SPI_EC_MASKED_REG & \
                                                                       (sourceMask)))
#endif /* (!i2c_master_CY_SCBIP_V1) */
#define i2c_master_CHECK_INTR_MASTER_MASKED(sourceMask)   (0u != (i2c_master_INTR_MASTER_MASKED_REG & \
                                                                       (sourceMask)))
#define i2c_master_CHECK_INTR_SLAVE_MASKED(sourceMask)    (0u != (i2c_master_INTR_SLAVE_MASKED_REG  & \
                                                                       (sourceMask)))
#define i2c_master_CHECK_INTR_TX_MASKED(sourceMask)       (0u != (i2c_master_INTR_TX_MASKED_REG     & \
                                                                       (sourceMask)))
#define i2c_master_CHECK_INTR_RX_MASKED(sourceMask)       (0u != (i2c_master_INTR_RX_MASKED_REG     & \
                                                                       (sourceMask)))

/* Return true if sourceMask is set in i2c_master_CTRL_REG: generally is used to check enable bit */
#define i2c_master_GET_CTRL_ENABLED    (0u != (i2c_master_CTRL_REG & i2c_master_CTRL_ENABLED))

#define i2c_master_CHECK_SLAVE_AUTO_ADDR_NACK     (0u != (i2c_master_I2C_CTRL_REG & \
                                                                i2c_master_I2C_CTRL_S_NOT_READY_DATA_NACK))


/***************************************
*      I2C Macro Definitions
***************************************/

/* Enable auto ACK/NACK */
#define i2c_master_ENABLE_SLAVE_AUTO_ADDR_NACK \
                            do{                      \
                                i2c_master_I2C_CTRL_REG |= i2c_master_I2C_CTRL_S_NOT_READY_DATA_NACK; \
                            }while(0)

#define i2c_master_ENABLE_SLAVE_AUTO_DATA_ACK \
                            do{                     \
                                i2c_master_I2C_CTRL_REG |= i2c_master_I2C_CTRL_S_READY_DATA_ACK; \
                            }while(0)

#define i2c_master_ENABLE_SLAVE_AUTO_DATA_NACK \
                            do{                      \
                                i2c_master_I2C_CTRL_REG |= i2c_master_I2C_CTRL_S_NOT_READY_DATA_NACK; \
                            }while(0)

#define i2c_master_ENABLE_MASTER_AUTO_DATA_ACK \
                            do{                      \
                                i2c_master_I2C_CTRL_REG |= i2c_master_I2C_CTRL_M_READY_DATA_ACK; \
                            }while(0)

#define i2c_master_ENABLE_MASTER_AUTO_DATA_NACK \
                            do{                       \
                                i2c_master_I2C_CTRL_REG |= i2c_master_I2C_CTRL_M_NOT_READY_DATA_NACK; \
                            }while(0)

/* Disable auto ACK/NACK */
#define i2c_master_DISABLE_SLAVE_AUTO_ADDR_NACK \
                            do{                       \
                                i2c_master_I2C_CTRL_REG &= ~i2c_master_I2C_CTRL_S_NOT_READY_DATA_NACK; \
                            }while(0)

#define i2c_master_DISABLE_SLAVE_AUTO_DATA_ACK \
                            do{                      \
                                i2c_master_I2C_CTRL_REG &= ~i2c_master_I2C_CTRL_S_READY_DATA_ACK; \
                            }while(0)

#define i2c_master_DISABLE_SLAVE_AUTO_DATA_NACK \
                            do{                       \
                                i2c_master_I2C_CTRL_REG &= ~i2c_master_I2C_CTRL_S_NOT_READY_DATA_NACK; \
                            }while(0)

#define i2c_master_DISABLE_MASTER_AUTO_DATA_ACK \
                            do{                       \
                                i2c_master_I2C_CTRL_REG &= ~i2c_master_I2C_CTRL_M_READY_DATA_ACK; \
                            }while(0)

#define i2c_master_DISABLE_MASTER_AUTO_DATA_NACK \
                            do{                        \
                                i2c_master_I2C_CTRL_REG &= ~i2c_master_I2C_CTRL_M_NOT_READY_DATA_NACK; \
                            }while(0)

/* Enable Slave autoACK/NACK Data */
#define i2c_master_ENABLE_SLAVE_AUTO_DATA \
                            do{                 \
                                i2c_master_I2C_CTRL_REG |= (i2c_master_I2C_CTRL_S_READY_DATA_ACK |      \
                                                                  i2c_master_I2C_CTRL_S_NOT_READY_DATA_NACK); \
                            }while(0)

/* Disable Slave autoACK/NACK Data */
#define i2c_master_DISABLE_SLAVE_AUTO_DATA \
                            do{                  \
                                i2c_master_I2C_CTRL_REG &= ((uint32) \
                                                                  ~(i2c_master_I2C_CTRL_S_READY_DATA_ACK |       \
                                                                    i2c_master_I2C_CTRL_S_NOT_READY_DATA_NACK)); \
                            }while(0)

/* Disable Master autoACK/NACK Data */
#define i2c_master_DISABLE_MASTER_AUTO_DATA \
                            do{                   \
                                i2c_master_I2C_CTRL_REG &= ((uint32) \
                                                                  ~(i2c_master_I2C_CTRL_M_READY_DATA_ACK |       \
                                                                    i2c_master_I2C_CTRL_M_NOT_READY_DATA_NACK)); \
                            }while(0)
/* Disables auto data ACK/NACK bits */
#define i2c_master_DISABLE_AUTO_DATA \
                do{                        \
                    i2c_master_I2C_CTRL_REG &= ((uint32) ~(i2c_master_I2C_CTRL_M_READY_DATA_ACK      |  \
                                                                 i2c_master_I2C_CTRL_M_NOT_READY_DATA_NACK |  \
                                                                 i2c_master_I2C_CTRL_S_READY_DATA_ACK      |  \
                                                                 i2c_master_I2C_CTRL_S_NOT_READY_DATA_NACK)); \
                }while(0)

/* Master commands */
#define i2c_master_I2C_MASTER_GENERATE_START \
                            do{                    \
                                i2c_master_I2C_MASTER_CMD_REG = i2c_master_I2C_MASTER_CMD_M_START_ON_IDLE; \
                            }while(0)

#define i2c_master_I2C_MASTER_CLEAR_START \
                            do{                 \
                                i2c_master_I2C_MASTER_CMD_REG =  ((uint32) 0u); \
                            }while(0)

#define i2c_master_I2C_MASTER_GENERATE_RESTART i2c_master_I2CReStartGeneration()

#define i2c_master_I2C_MASTER_GENERATE_STOP \
                            do{                   \
                                i2c_master_I2C_MASTER_CMD_REG =                                            \
                                    (i2c_master_I2C_MASTER_CMD_M_STOP |                                    \
                                        (i2c_master_CHECK_I2C_STATUS(i2c_master_I2C_STATUS_M_READ) ? \
                                            (i2c_master_I2C_MASTER_CMD_M_NACK) : (0u)));                   \
                            }while(0)

#define i2c_master_I2C_MASTER_GENERATE_ACK \
                            do{                  \
                                i2c_master_I2C_MASTER_CMD_REG = i2c_master_I2C_MASTER_CMD_M_ACK; \
                            }while(0)

#define i2c_master_I2C_MASTER_GENERATE_NACK \
                            do{                   \
                                i2c_master_I2C_MASTER_CMD_REG = i2c_master_I2C_MASTER_CMD_M_NACK; \
                            }while(0)

/* Slave commands */
#define i2c_master_I2C_SLAVE_GENERATE_ACK \
                            do{                 \
                                i2c_master_I2C_SLAVE_CMD_REG = i2c_master_I2C_SLAVE_CMD_S_ACK; \
                            }while(0)

#if (i2c_master_CY_SCBIP_V0 || i2c_master_CY_SCBIP_V1)
    /* Slave NACK generation for EC_AM logic on address phase. Ticket ID #183902 */
    void i2c_master_I2CSlaveNackGeneration(void);
    #define i2c_master_I2C_SLAVE_GENERATE_NACK i2c_master_I2CSlaveNackGeneration()

#else
    #define i2c_master_I2C_SLAVE_GENERATE_NACK \
                            do{                      \
                                i2c_master_I2C_SLAVE_CMD_REG = i2c_master_I2C_SLAVE_CMD_S_NACK; \
                            }while(0)
#endif /* (i2c_master_CY_SCBIP_V0 || i2c_master_CY_SCBIP_V1) */

#define i2c_master_I2C_SLAVE_CLEAR_NACK \
                            do{               \
                                i2c_master_I2C_SLAVE_CMD_REG = 0u; \
                            }while(0)

/* Return 8-bit address. The input address should be 7-bits */
#define i2c_master_GET_I2C_8BIT_ADDRESS(addr) (((uint32) ((uint32) (addr) << \
                                                                    i2c_master_I2C_SLAVE_ADDR_POS)) & \
                                                                        i2c_master_I2C_SLAVE_ADDR_MASK)

#define i2c_master_GET_I2C_7BIT_ADDRESS(addr) ((uint32) (addr) >> i2c_master_I2C_SLAVE_ADDR_POS)

/* Adjust SDA filter Trim settings */
#define i2c_master_DEFAULT_I2C_CFG_SDA_FILT_TRIM  (0x02u)
#define i2c_master_EC_AM_I2C_CFG_SDA_FILT_TRIM    (0x03u)

#if (i2c_master_CY_SCBIP_V0)
    #define i2c_master_SET_I2C_CFG_SDA_FILT_TRIM(sdaTrim) \
        do{                                                 \
            i2c_master_I2C_CFG_REG =                  \
                            ((i2c_master_I2C_CFG_REG & (uint32) ~i2c_master_I2C_CFG_SDA_FILT_TRIM_MASK) | \
                             ((uint32) ((uint32) (sdaTrim) <<i2c_master_I2C_CFG_SDA_FILT_TRIM_POS)));           \
        }while(0)
#endif /* (i2c_master_CY_SCBIP_V0) */

/* Enable/Disable analog and digital filter */
#define i2c_master_DIGITAL_FILTER_DISABLE    (0u)
#define i2c_master_DIGITAL_FILTER_ENABLE     (1u)
#define i2c_master_I2C_DATA_RATE_FS_MODE_MAX (400u)
#if (i2c_master_CY_SCBIP_V0)
    /* i2c_master_I2C_CFG_SDA_FILT_OUT_ENABLED is disabled by default */
    #define i2c_master_I2C_CFG_FILT_MASK  (i2c_master_I2C_CFG_SDA_FILT_ENABLED | \
                                                 i2c_master_I2C_CFG_SCL_FILT_ENABLED)
#else
    /* i2c_master_I2C_CFG_SDA_OUT_FILT_SEL_MASK is disabled by default */
    #define i2c_master_I2C_CFG_FILT_MASK  (i2c_master_I2C_CFG_SDA_IN_FILT_SEL | \
                                                 i2c_master_I2C_CFG_SCL_IN_FILT_SEL)
#endif /* (i2c_master_CY_SCBIP_V0) */

#define i2c_master_I2C_CFG_ANALOG_FITER_DISABLE \
        do{                                           \
            i2c_master_I2C_CFG_REG &= (uint32) ~i2c_master_I2C_CFG_FILT_MASK; \
        }while(0)

#define i2c_master_I2C_CFG_ANALOG_FITER_ENABLE \
        do{                                          \
            i2c_master_I2C_CFG_REG |= (uint32)  i2c_master_I2C_CFG_FILT_MASK; \
        }while(0)

/* Return slave select number from SPI_CTRL register */
#define i2c_master_GET_SPI_CTRL_SS(activeSelect) (((uint32) ((uint32) (activeSelect) << \
                                                                    i2c_master_SPI_CTRL_SLAVE_SELECT_POS)) & \
                                                                        i2c_master_SPI_CTRL_SLAVE_SELECT_MASK)

/* Return true if bit is set in i2c_master_I2C_STATUS_REG */
#define i2c_master_CHECK_I2C_STATUS(sourceMask)   (0u != (i2c_master_I2C_STATUS_REG & (sourceMask)))

/* Return true if bit is set in i2c_master_SPI_STATUS_REG */
#define i2c_master_CHECK_SPI_STATUS(sourceMask)   (0u != (i2c_master_SPI_STATUS_REG & (sourceMask)))

/* Return FIFO size depends on i2c_master_CTRL_BYTE_MODE bit */
#define i2c_master_GET_FIFO_SIZE(condition) ((0u != (condition)) ? \
                                                    (2u * i2c_master_FIFO_SIZE) : (i2c_master_FIFO_SIZE))


/***************************************
*       Get Macros Definitions
***************************************/

/* i2c_master_CTRL */
#define i2c_master_GET_CTRL_OVS(oversample)       (((uint32) (oversample) - 1u) & i2c_master_CTRL_OVS_MASK)

#define i2c_master_GET_CTRL_EC_OP_MODE(opMode)        ((0u != (opMode)) ? \
                                                                (i2c_master_CTRL_EC_OP_MODE)  : (0u))

#define i2c_master_GET_CTRL_EC_AM_MODE(amMode)        ((0u != (amMode)) ? \
                                                                (i2c_master_CTRL_EC_AM_MODE)  : (0u))

#define i2c_master_GET_CTRL_BLOCK(block)              ((0u != (block))  ? \
                                                                (i2c_master_CTRL_BLOCK)       : (0u))

#define i2c_master_GET_CTRL_ADDR_ACCEPT(acceptAddr)   ((0u != (acceptAddr)) ? \
                                                                (i2c_master_CTRL_ADDR_ACCEPT) : (0u))

#if (i2c_master_CY_SCBIP_V0 || i2c_master_CY_SCBIP_V1)
    #define i2c_master_GET_CTRL_BYTE_MODE(mode)   (0u)
#else
    #define i2c_master_GET_CTRL_BYTE_MODE(mode)   ((0u != (mode)) ? \
                                                            (i2c_master_CTRL_BYTE_MODE) : (0u))
#endif /* (i2c_master_CY_SCBIP_V0 || i2c_master_CY_SCBIP_V1) */

/* i2c_master_I2C_CTRL */
#define i2c_master_GET_I2C_CTRL_HIGH_PHASE_OVS(oversampleHigh) (((uint32) (oversampleHigh) - 1u) & \
                                                                        i2c_master_I2C_CTRL_HIGH_PHASE_OVS_MASK)

#define i2c_master_GET_I2C_CTRL_LOW_PHASE_OVS(oversampleLow)  ((((uint32) (oversampleLow) - 1u) << \
                                                                    i2c_master_I2C_CTRL_LOW_PHASE_OVS_POS) &  \
                                                                    i2c_master_I2C_CTRL_LOW_PHASE_OVS_MASK)

#define i2c_master_GET_I2C_CTRL_S_NOT_READY_ADDR_NACK(wakeNack) ((0u != (wakeNack)) ? \
                                                            (i2c_master_I2C_CTRL_S_NOT_READY_ADDR_NACK) : (0u))

#define i2c_master_GET_I2C_CTRL_S_GENERAL_IGNORE(genCall) ((0u != (genCall)) ? \
                                                                    (i2c_master_I2C_CTRL_S_GENERAL_IGNORE) : (0u))

#define i2c_master_GET_I2C_CTRL_SL_MSTR_MODE(mode)    ((uint32)(mode) << i2c_master_I2C_CTRL_SLAVE_MODE_POS)

/* i2c_master_SPI_CTRL */
#define i2c_master_GET_SPI_CTRL_CONTINUOUS(separate)  ((0u != (separate)) ? \
                                                                (i2c_master_SPI_CTRL_CONTINUOUS) : (0u))

#define i2c_master_GET_SPI_CTRL_SELECT_PRECEDE(mode)  ((0u != (mode)) ? \
                                                                      (i2c_master_SPI_CTRL_SELECT_PRECEDE) : (0u))

#define i2c_master_GET_SPI_CTRL_SCLK_MODE(mode)       (((uint32) (mode) << \
                                                                        i2c_master_SPI_CTRL_CPHA_POS) & \
                                                                        i2c_master_SPI_CTRL_SCLK_MODE_MASK)

#define i2c_master_GET_SPI_CTRL_LATE_MISO_SAMPLE(lateMiso) ((0u != (lateMiso)) ? \
                                                                    (i2c_master_SPI_CTRL_LATE_MISO_SAMPLE) : (0u))

#if (i2c_master_CY_SCBIP_V0 || i2c_master_CY_SCBIP_V1)
    #define i2c_master_GET_SPI_CTRL_SCLK_CONTINUOUS(sclkType) (0u)
    #define i2c_master_GET_SPI_CTRL_SSEL_POLARITY(polarity)   (0u)
#else
    #define i2c_master_GET_SPI_CTRL_SCLK_CONTINUOUS(sclkType) ((0u != (sclkType)) ? \
                                                                    (i2c_master_SPI_CTRL_SCLK_CONTINUOUS) : (0u))

    #define i2c_master_GET_SPI_CTRL_SSEL_POLARITY(polarity)   (((uint32) (polarity) << \
                                                                     i2c_master_SPI_CTRL_SSEL0_POLARITY_POS) & \
                                                                     i2c_master_SPI_CTRL_SSEL_POLARITY_MASK)
#endif /* ((i2c_master_CY_SCBIP_V0 || i2c_master_CY_SCBIP_V1) */

#define i2c_master_GET_SPI_CTRL_SUB_MODE(mode)        (((uint32) (mode) << i2c_master_SPI_CTRL_MODE_POS) & \
                                                                                 i2c_master_SPI_CTRL_MODE_MASK)

#define i2c_master_GET_SPI_CTRL_SLAVE_SELECT(select)  (((uint32) (select) << \
                                                                      i2c_master_SPI_CTRL_SLAVE_SELECT_POS) & \
                                                                      i2c_master_SPI_CTRL_SLAVE_SELECT_MASK)

#define i2c_master_GET_SPI_CTRL_MASTER_MODE(mode)     ((0u != (mode)) ? \
                                                                (i2c_master_SPI_CTRL_MASTER) : (0u))

/* i2c_master_UART_CTRL */
#define i2c_master_GET_UART_CTRL_MODE(mode)           (((uint32) (mode) << \
                                                                            i2c_master_UART_CTRL_MODE_POS) & \
                                                                            i2c_master_UART_CTRL_MODE_MASK)

/* i2c_master_UART_RX_CTRL */
#define i2c_master_GET_UART_RX_CTRL_MODE(stopBits)    (((uint32) (stopBits) - 1u) & \
                                                                        i2c_master_UART_RX_CTRL_STOP_BITS_MASK)

#define i2c_master_GET_UART_RX_CTRL_PARITY(parity)    ((0u != (parity)) ? \
                                                                    (i2c_master_UART_RX_CTRL_PARITY) : (0u))

#define i2c_master_GET_UART_RX_CTRL_POLARITY(polarity)    ((0u != (polarity)) ? \
                                                                    (i2c_master_UART_RX_CTRL_POLARITY) : (0u))

#define i2c_master_GET_UART_RX_CTRL_DROP_ON_PARITY_ERR(dropErr) ((0u != (dropErr)) ? \
                                                        (i2c_master_UART_RX_CTRL_DROP_ON_PARITY_ERR) : (0u))

#define i2c_master_GET_UART_RX_CTRL_DROP_ON_FRAME_ERR(dropErr) ((0u != (dropErr)) ? \
                                                        (i2c_master_UART_RX_CTRL_DROP_ON_FRAME_ERR) : (0u))

#define i2c_master_GET_UART_RX_CTRL_MP_MODE(mpMode)   ((0u != (mpMode)) ? \
                                                        (i2c_master_UART_RX_CTRL_MP_MODE) : (0u))

#define i2c_master_GET_UART_RX_CTRL_BREAK_WIDTH(width)    (((uint32) ((uint32) (width) - 1u) << \
                                                                    i2c_master_UART_RX_CTRL_BREAK_WIDTH_POS) & \
                                                                    i2c_master_UART_RX_CTRL_BREAK_WIDTH_MASK)

/* i2c_master_UART_TX_CTRL */
#define i2c_master_GET_UART_TX_CTRL_MODE(stopBits)    (((uint32) (stopBits) - 1u) & \
                                                                i2c_master_UART_RX_CTRL_STOP_BITS_MASK)

#define i2c_master_GET_UART_TX_CTRL_PARITY(parity)    ((0u != (parity)) ? \
                                                               (i2c_master_UART_TX_CTRL_PARITY) : (0u))

#define i2c_master_GET_UART_TX_CTRL_RETRY_NACK(nack)  ((0u != (nack)) ? \
                                                               (i2c_master_UART_TX_CTRL_RETRY_ON_NACK) : (0u))

/* i2c_master_UART_FLOW_CTRL */
#if !(i2c_master_CY_SCBIP_V0 || i2c_master_CY_SCBIP_V1)
    #define i2c_master_GET_UART_FLOW_CTRL_TRIGGER_LEVEL(level)   ( (uint32) (level) & \
                                                                 i2c_master_UART_FLOW_CTRL_TRIGGER_LEVEL_MASK)

    #define i2c_master_GET_UART_FLOW_CTRL_RTS_POLARITY(polarity) ((0u != (polarity)) ? \
                                                                (i2c_master_UART_FLOW_CTRL_RTS_POLARITY) : (0u))

    #define i2c_master_GET_UART_FLOW_CTRL_CTS_POLARITY(polarity) ((0u != (polarity)) ? \
                                                                (i2c_master_UART_FLOW_CTRL_CTS_POLARITY) : (0u))

    #define i2c_master_GET_UART_FLOW_CTRL_CTS_ENABLE(ctsEn)      ((0u != (ctsEn)) ? \
                                                                (i2c_master_UART_FLOW_CTRL_CTS_ENABLE) : (0u))
#endif /* !(i2c_master_CY_SCBIP_V0 || i2c_master_CY_SCBIP_V1) */

/* i2c_master_RX_CTRL */
#define i2c_master_GET_RX_CTRL_DATA_WIDTH(dataWidth)  (((uint32) (dataWidth) - 1u) & \
                                                                i2c_master_RX_CTRL_DATA_WIDTH_MASK)

#define i2c_master_GET_RX_CTRL_BIT_ORDER(bitOrder)    ((0u != (bitOrder)) ? \
                                                                (i2c_master_RX_CTRL_MSB_FIRST) : (0u))

#define i2c_master_GET_RX_CTRL_MEDIAN(filterEn)       ((0u != (filterEn)) ? \
                                                                (i2c_master_RX_CTRL_MEDIAN) : (0u))

/* i2c_master_RX_MATCH */
#define i2c_master_GET_RX_MATCH_ADDR(addr)    ((uint32) (addr) & i2c_master_RX_MATCH_ADDR_MASK)
#define i2c_master_GET_RX_MATCH_MASK(mask)    (((uint32) (mask) << \
                                                            i2c_master_RX_MATCH_MASK_POS) & \
                                                            i2c_master_RX_MATCH_MASK_MASK)

/* i2c_master_RX_FIFO_CTRL */
#define i2c_master_GET_RX_FIFO_CTRL_TRIGGER_LEVEL(level)  ((uint32) (level) & \
                                                                    i2c_master_RX_FIFO_CTRL_TRIGGER_LEVEL_MASK)

/* i2c_master_TX_CTRL */
#define i2c_master_GET_TX_CTRL_DATA_WIDTH(dataWidth)  (((uint32) (dataWidth) - 1u) & \
                                                                i2c_master_TX_CTRL_DATA_WIDTH_MASK)

#define i2c_master_GET_TX_CTRL_BIT_ORDER(bitOrder)    ((0u != (bitOrder)) ? \
                                                                (i2c_master_TX_CTRL_MSB_FIRST) : (0u))

/* i2c_master_TX_FIFO_CTRL */
#define i2c_master_GET_TX_FIFO_CTRL_TRIGGER_LEVEL(level)  ((uint32) (level) & \
                                                                    i2c_master_TX_FIFO_CTRL_TRIGGER_LEVEL_MASK)

/* i2c_master_INTR_SLAVE_I2C_GENERAL */
#define i2c_master_GET_INTR_SLAVE_I2C_GENERAL(genCall)  ((0u != (genCall)) ? \
                                                                (i2c_master_INTR_SLAVE_I2C_GENERAL) : (0u))

/* Return true if master mode is enabled i2c_master_SPI_CTRL_REG */
#define i2c_master_CHECK_SPI_MASTER   (0u != (i2c_master_SPI_CTRL_REG & i2c_master_SPI_CTRL_MASTER))

/* Return inactive state of SPI SCLK line depends on CPOL */
#define i2c_master_GET_SPI_SCLK_INACTIVE \
            ((0u == (i2c_master_SPI_CTRL_REG & i2c_master_SPI_CTRL_CPOL)) ? (0u) : (1u))

/* Get output pin inactive state */
#if (i2c_master_CY_SCBIP_V0 || i2c_master_CY_SCBIP_V1)
#define i2c_master_GET_SPI_SS0_INACTIVE       (1u)
#define i2c_master_GET_SPI_SS1_INACTIVE       (1u)
#define i2c_master_GET_SPI_SS2_INACTIVE       (1u)
#define i2c_master_GET_SPI_SS3_INACTIVE       (1u)
#define i2c_master_GET_UART_RTS_INACTIVE      (1u)

#else
#define i2c_master_GET_SPI_SS0_INACTIVE  \
        ((0u != (i2c_master_SPI_CTRL_REG & i2c_master_SPI_CTRL_SSEL0_POLARITY)) ? (0u) : (1u))

#define i2c_master_GET_SPI_SS1_INACTIVE  \
        ((0u != (i2c_master_SPI_CTRL_REG & i2c_master_SPI_CTRL_SSEL1_POLARITY)) ? (0u) : (1u))

#define i2c_master_GET_SPI_SS2_INACTIVE  \
        ((0u != (i2c_master_SPI_CTRL_REG & i2c_master_SPI_CTRL_SSEL2_POLARITY)) ? (0u) : (1u))

#define i2c_master_GET_SPI_SS3_INACTIVE  \
        ((0u != (i2c_master_SPI_CTRL_REG & i2c_master_SPI_CTRL_SSEL3_POLARITY)) ? (0u) : (1u))

#define i2c_master_GET_UART_RTS_INACTIVE \
        ((0u == (i2c_master_UART_FLOW_CTRL_REG & i2c_master_UART_FLOW_CTRL_RTS_POLARITY)) ? (0u) : (1u))

#endif /*(i2c_master_CY_SCBIP_V0 || i2c_master_CY_SCBIP_V1) */

/* Clear register constants for configuration and interrupt mask */
#define i2c_master_CLEAR_REG          ((uint32) (0u))
#define i2c_master_NO_INTR_SOURCES    ((uint32) (0u))
#define i2c_master_DUMMY_PARAM        ((uint32) (0u))
#define i2c_master_SUBMODE_SPI_SLAVE  ((uint32) (0u))

/* Return in case of I2C read error */
#define i2c_master_I2C_INVALID_BYTE   ((uint32) 0xFFFFFFFFu)
#define i2c_master_CHECK_VALID_BYTE   ((uint32) 0x80000000u)


/***************************************
* The following code is DEPRECATED and
* must not be used.
***************************************/

#define i2c_master_CHECK_INTR_EC_I2C(sourceMask)  i2c_master_CHECK_INTR_I2C_EC(sourceMask)
#if (!i2c_master_CY_SCBIP_V1)
    #define i2c_master_CHECK_INTR_EC_SPI(sourceMask)  i2c_master_CHECK_INTR_SPI_EC(sourceMask)
#endif /* (!i2c_master_CY_SCBIP_V1) */

#define i2c_master_CY_SCBIP_V1_I2C_ONLY   (i2c_master_CY_SCBIP_V1)
#define i2c_master_EZBUFFER_SIZE          (i2c_master_EZ_DATA_NR)

#define i2c_master_EZBUF_DATA00_REG   i2c_master_EZBUF_DATA0_REG
#define i2c_master_EZBUF_DATA00_PTR   i2c_master_EZBUF_DATA0_PTR

#endif /* (CY_SCB_i2c_master_H) */


/* [] END OF FILE */
