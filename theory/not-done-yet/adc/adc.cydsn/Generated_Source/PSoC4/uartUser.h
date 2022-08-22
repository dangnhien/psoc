/***************************************************************************//**
* \file uartUser.h
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

#if !defined(CY_SCB_uartUser_H)
#define CY_SCB_uartUser_H

#include <cydevice_trm.h>
#include <cyfitter.h>
#include <cytypes.h>
#include <CyLib.h>

/* SCB IP block v0 is available in PSoC 4100/PSoC 4200 */
#define uartUser_CY_SCBIP_V0    (CYIPBLOCK_m0s8scb_VERSION == 0u)
/* SCB IP block v1 is available in PSoC 4000 */
#define uartUser_CY_SCBIP_V1    (CYIPBLOCK_m0s8scb_VERSION == 1u)
/* SCB IP block v2 is available in all other devices */
#define uartUser_CY_SCBIP_V2    (CYIPBLOCK_m0s8scb_VERSION >= 2u)

/** Component version major.minor */
#define uartUser_COMP_VERSION_MAJOR    (4)
#define uartUser_COMP_VERSION_MINOR    (0)
    
#define uartUser_SCB_MODE           (4u)

/* SCB modes enum */
#define uartUser_SCB_MODE_I2C       (0x01u)
#define uartUser_SCB_MODE_SPI       (0x02u)
#define uartUser_SCB_MODE_UART      (0x04u)
#define uartUser_SCB_MODE_EZI2C     (0x08u)
#define uartUser_SCB_MODE_UNCONFIG  (0xFFu)

/* Condition compilation depends on operation mode: Unconfigured implies apply to all modes */
#define uartUser_SCB_MODE_I2C_CONST_CFG       (uartUser_SCB_MODE_I2C       == uartUser_SCB_MODE)
#define uartUser_SCB_MODE_SPI_CONST_CFG       (uartUser_SCB_MODE_SPI       == uartUser_SCB_MODE)
#define uartUser_SCB_MODE_UART_CONST_CFG      (uartUser_SCB_MODE_UART      == uartUser_SCB_MODE)
#define uartUser_SCB_MODE_EZI2C_CONST_CFG     (uartUser_SCB_MODE_EZI2C     == uartUser_SCB_MODE)
#define uartUser_SCB_MODE_UNCONFIG_CONST_CFG  (uartUser_SCB_MODE_UNCONFIG  == uartUser_SCB_MODE)

/* Condition compilation for includes */
#define uartUser_SCB_MODE_I2C_INC      (0u !=(uartUser_SCB_MODE_I2C   & uartUser_SCB_MODE))
#define uartUser_SCB_MODE_EZI2C_INC    (0u !=(uartUser_SCB_MODE_EZI2C & uartUser_SCB_MODE))
#if (!uartUser_CY_SCBIP_V1)
    #define uartUser_SCB_MODE_SPI_INC  (0u !=(uartUser_SCB_MODE_SPI   & uartUser_SCB_MODE))
    #define uartUser_SCB_MODE_UART_INC (0u !=(uartUser_SCB_MODE_UART  & uartUser_SCB_MODE))
#else
    #define uartUser_SCB_MODE_SPI_INC  (0u)
    #define uartUser_SCB_MODE_UART_INC (0u)
#endif /* (!uartUser_CY_SCBIP_V1) */

/* Interrupts remove options */
#define uartUser_REMOVE_SCB_IRQ             (1u)
#define uartUser_SCB_IRQ_INTERNAL           (0u == uartUser_REMOVE_SCB_IRQ)

#define uartUser_REMOVE_UART_RX_WAKEUP_IRQ  (1u)
#define uartUser_UART_RX_WAKEUP_IRQ         (0u == uartUser_REMOVE_UART_RX_WAKEUP_IRQ)

/* SCB interrupt enum */
#define uartUser_SCB_INTR_MODE_NONE     (0u)
#define uartUser_SCB_INTR_MODE_INTERNAL (1u)
#define uartUser_SCB_INTR_MODE_EXTERNAL (2u)

/* Internal clock remove option */
#define uartUser_REMOVE_SCB_CLK     (0u)
#define uartUser_SCB_CLK_INTERNAL   (0u == uartUser_REMOVE_SCB_CLK)


/***************************************
*       Includes
****************************************/

#include "uartUser_PINS.h"

#if (uartUser_SCB_CLK_INTERNAL)
    #include "uartUser_SCBCLK.h"
#endif /* (uartUser_SCB_CLK_INTERNAL) */


/***************************************
*       Type Definitions
***************************************/

typedef struct
{
    uint8 enableState;
} uartUser_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

/**
* \addtogroup group_general
* @{
*/

/* Start and Stop APIs */
void uartUser_Init(void);
void uartUser_Enable(void);
void uartUser_Start(void);
void uartUser_Stop(void);

/** @} general */

/**
* \addtogroup group_power
* @{
*/
/* Sleep and Wakeup APis */
void uartUser_Sleep(void);
void uartUser_Wakeup(void);
/** @} power */ 

/**
* \addtogroup group_interrupt
* @{
*/
#if (uartUser_SCB_IRQ_INTERNAL)
    /* Custom interrupt handler */
    void uartUser_SetCustomInterruptHandler(void (*func)(void));
#endif /* (uartUser_SCB_IRQ_INTERNAL) */
/** @} interrupt */

/* Interface to internal interrupt component */
#if (uartUser_SCB_IRQ_INTERNAL)
    /**
    * \addtogroup group_interrupt
    * @{
    */    
    /*******************************************************************************
    * Function Name: uartUser_EnableInt
    ****************************************************************************//**
    *
    *  When using an Internal interrupt, this enables the interrupt in the NVIC. 
    *  When using an external interrupt the API for the interrupt component must 
    *  be used to enable the interrupt.
    *
    *******************************************************************************/
    #define uartUser_EnableInt()    CyIntEnable(uartUser_ISR_NUMBER)
    
    
    /*******************************************************************************
    * Function Name: uartUser_DisableInt
    ****************************************************************************//**
    *
    *  When using an Internal interrupt, this disables the interrupt in the NVIC. 
    *  When using an external interrupt the API for the interrupt component must 
    *  be used to disable the interrupt.
    *
    *******************************************************************************/    
    #define uartUser_DisableInt()   CyIntDisable(uartUser_ISR_NUMBER)
    /** @} interrupt */

    /*******************************************************************************
    * Function Name: uartUser_ClearPendingInt
    ****************************************************************************//**
    *
    *  This function clears the interrupt pending status in the NVIC. 
    *
    *******************************************************************************/
    #define uartUser_ClearPendingInt()  CyIntClearPending(uartUser_ISR_NUMBER)
#endif /* (uartUser_SCB_IRQ_INTERNAL) */

#if (uartUser_UART_RX_WAKEUP_IRQ)
    /*******************************************************************************
    * Function Name: uartUser_RxWakeEnableInt
    ****************************************************************************//**
    *
    *  This function enables the interrupt (RX_WAKE) pending status in the NVIC. 
    *
    *******************************************************************************/    
    #define uartUser_RxWakeEnableInt()  CyIntEnable(uartUser_RX_WAKE_ISR_NUMBER)
    

    /*******************************************************************************
    * Function Name: uartUser_RxWakeDisableInt
    ****************************************************************************//**
    *
    *  This function disables the interrupt (RX_WAKE) pending status in the NVIC.  
    *
    *******************************************************************************/
    #define uartUser_RxWakeDisableInt() CyIntDisable(uartUser_RX_WAKE_ISR_NUMBER)
    
    
    /*******************************************************************************
    * Function Name: uartUser_RxWakeClearPendingInt
    ****************************************************************************//**
    *
    *  This function clears the interrupt (RX_WAKE) pending status in the NVIC. 
    *
    *******************************************************************************/    
    #define uartUser_RxWakeClearPendingInt()  CyIntClearPending(uartUser_RX_WAKE_ISR_NUMBER)
#endif /* (uartUser_UART_RX_WAKEUP_IRQ) */

/**
* \addtogroup group_interrupt
* @{
*/
/* Get interrupt cause */
/*******************************************************************************
* Function Name: uartUser_GetInterruptCause
****************************************************************************//**
*
*  Returns a mask of bits showing the source of the current triggered interrupt. 
*  This is useful for modes of operation where an interrupt can be generated by 
*  conditions in multiple interrupt source registers.
*
*  \return
*   Mask with the OR of the following conditions that have been triggered.
*    - uartUser_INTR_CAUSE_MASTER - Interrupt from Master
*    - uartUser_INTR_CAUSE_SLAVE - Interrupt from Slave
*    - uartUser_INTR_CAUSE_TX - Interrupt from TX
*    - uartUser_INTR_CAUSE_RX - Interrupt from RX
*
*******************************************************************************/
#define uartUser_GetInterruptCause()    (uartUser_INTR_CAUSE_REG)


/* APIs to service INTR_RX register */
/*******************************************************************************
* Function Name: uartUser_GetRxInterruptSource
****************************************************************************//**
*
*  Returns RX interrupt request register. This register contains current status 
*  of RX interrupt sources.
*
*  \return
*   Current status of RX interrupt sources.
*   Each constant is a bit field value. The value returned may have multiple 
*   bits set to indicate the current status.
*   - uartUser_INTR_RX_FIFO_LEVEL - The number of data elements in the 
      RX FIFO is greater than the value of RX FIFO level.
*   - uartUser_INTR_RX_NOT_EMPTY - Receiver FIFO is not empty.
*   - uartUser_INTR_RX_FULL - Receiver FIFO is full.
*   - uartUser_INTR_RX_OVERFLOW - Attempt to write to a full 
*     receiver FIFO.
*   - uartUser_INTR_RX_UNDERFLOW - Attempt to read from an empty 
*     receiver FIFO.
*   - uartUser_INTR_RX_FRAME_ERROR - UART framing error detected.
*   - uartUser_INTR_RX_PARITY_ERROR - UART parity error detected.
*
*******************************************************************************/
#define uartUser_GetRxInterruptSource() (uartUser_INTR_RX_REG)


/*******************************************************************************
* Function Name: uartUser_SetRxInterruptMode
****************************************************************************//**
*
*  Writes RX interrupt mask register. This register configures which bits from 
*  RX interrupt request register will trigger an interrupt event.
*
*  \param interruptMask: RX interrupt sources to be enabled (refer to 
*   uartUser_GetRxInterruptSource() function for bit fields values).
*
*******************************************************************************/
#define uartUser_SetRxInterruptMode(interruptMask)     uartUser_WRITE_INTR_RX_MASK(interruptMask)


/*******************************************************************************
* Function Name: uartUser_GetRxInterruptMode
****************************************************************************//**
*
*  Returns RX interrupt mask register This register specifies which bits from 
*  RX interrupt request register will trigger an interrupt event.
*
*  \return 
*   RX interrupt sources to be enabled (refer to 
*   uartUser_GetRxInterruptSource() function for bit fields values).
*
*******************************************************************************/
#define uartUser_GetRxInterruptMode()   (uartUser_INTR_RX_MASK_REG)


/*******************************************************************************
* Function Name: uartUser_GetRxInterruptSourceMasked
****************************************************************************//**
*
*  Returns RX interrupt masked request register. This register contains logical
*  AND of corresponding bits from RX interrupt request and mask registers.
*  This function is intended to be used in the interrupt service routine to 
*  identify which of enabled RX interrupt sources cause interrupt event.
*
*  \return 
*   Current status of enabled RX interrupt sources (refer to 
*   uartUser_GetRxInterruptSource() function for bit fields values).
*
*******************************************************************************/
#define uartUser_GetRxInterruptSourceMasked()   (uartUser_INTR_RX_MASKED_REG)


/*******************************************************************************
* Function Name: uartUser_ClearRxInterruptSource
****************************************************************************//**
*
*  Clears RX interrupt sources in the interrupt request register.
*
*  \param interruptMask: RX interrupt sources to be cleared (refer to 
*   uartUser_GetRxInterruptSource() function for bit fields values).
*
*  \sideeffects 
*   The side effects are listed in the table below for each 
*   affected interrupt source. Refer to section RX FIFO interrupt sources for 
*   detailed description.
*   - uartUser_INTR_RX_FIFO_LEVEL Interrupt source is not cleared when 
*     the receiver FIFO has more entries than level.
*   - uartUser_INTR_RX_NOT_EMPTY Interrupt source is not cleared when
*     receiver FIFO is not empty.
*   - uartUser_INTR_RX_FULL Interrupt source is not cleared when 
*      receiver FIFO is full.
*
*******************************************************************************/
#define uartUser_ClearRxInterruptSource(interruptMask)  uartUser_CLEAR_INTR_RX(interruptMask)


/*******************************************************************************
* Function Name: uartUser_SetRxInterrupt
****************************************************************************//**
*
*  Sets RX interrupt sources in the interrupt request register.
*
*  \param interruptMask: RX interrupt sources to set in the RX interrupt request 
*   register (refer to uartUser_GetRxInterruptSource() function for bit 
*   fields values).
*
*******************************************************************************/
#define uartUser_SetRxInterrupt(interruptMask)  uartUser_SET_INTR_RX(interruptMask)

void uartUser_SetRxFifoLevel(uint32 level);


/* APIs to service INTR_TX register */
/*******************************************************************************
* Function Name: uartUser_GetTxInterruptSource
****************************************************************************//**
*
*  Returns TX interrupt request register. This register contains current status 
*  of TX interrupt sources.
* 
*  \return 
*   Current status of TX interrupt sources.
*   Each constant is a bit field value. The value returned may have multiple 
*   bits set to indicate the current status.
*   - uartUser_INTR_TX_FIFO_LEVEL - The number of data elements in the 
*     TX FIFO is less than the value of TX FIFO level.
*   - uartUser_INTR_TX_NOT_FULL - Transmitter FIFO is not full.
*   - uartUser_INTR_TX_EMPTY - Transmitter FIFO is empty.
*   - uartUser_INTR_TX_OVERFLOW - Attempt to write to a full 
*     transmitter FIFO.
*   - uartUser_INTR_TX_UNDERFLOW - Attempt to read from an empty 
*     transmitter FIFO.
*   - uartUser_INTR_TX_UART_NACK - UART received a NACK in SmartCard 
*   mode.
*   - uartUser_INTR_TX_UART_DONE - UART transfer is complete. 
*     All data elements from the TX FIFO are sent.
*   - uartUser_INTR_TX_UART_ARB_LOST - Value on the TX line of the UART
*     does not match the value on the RX line.
*
*******************************************************************************/
#define uartUser_GetTxInterruptSource() (uartUser_INTR_TX_REG)


/*******************************************************************************
* Function Name: uartUser_SetTxInterruptMode
****************************************************************************//**
*
*  Writes TX interrupt mask register. This register configures which bits from 
*  TX interrupt request register will trigger an interrupt event.
*
*  \param interruptMask: TX interrupt sources to be enabled (refer to 
*   uartUser_GetTxInterruptSource() function for bit field values).
*
*******************************************************************************/
#define uartUser_SetTxInterruptMode(interruptMask)  uartUser_WRITE_INTR_TX_MASK(interruptMask)


/*******************************************************************************
* Function Name: uartUser_GetTxInterruptMode
****************************************************************************//**
*
*  Returns TX interrupt mask register This register specifies which bits from 
*  TX interrupt request register will trigger an interrupt event.
*
*  \return 
*   Enabled TX interrupt sources (refer to 
*   uartUser_GetTxInterruptSource() function for bit field values).
*   
*******************************************************************************/
#define uartUser_GetTxInterruptMode()   (uartUser_INTR_TX_MASK_REG)


/*******************************************************************************
* Function Name: uartUser_GetTxInterruptSourceMasked
****************************************************************************//**
*
*  Returns TX interrupt masked request register. This register contains logical
*  AND of corresponding bits from TX interrupt request and mask registers.
*  This function is intended to be used in the interrupt service routine to identify 
*  which of enabled TX interrupt sources cause interrupt event.
*
*  \return 
*   Current status of enabled TX interrupt sources (refer to 
*   uartUser_GetTxInterruptSource() function for bit field values).
*
*******************************************************************************/
#define uartUser_GetTxInterruptSourceMasked()   (uartUser_INTR_TX_MASKED_REG)


/*******************************************************************************
* Function Name: uartUser_ClearTxInterruptSource
****************************************************************************//**
*
*  Clears TX interrupt sources in the interrupt request register.
*
*  \param interruptMask: TX interrupt sources to be cleared (refer to 
*   uartUser_GetTxInterruptSource() function for bit field values).
*
*  \sideeffects 
*   The side effects are listed in the table below for each affected interrupt 
*   source. Refer to section TX FIFO interrupt sources for detailed description.
*   - uartUser_INTR_TX_FIFO_LEVEL - Interrupt source is not cleared when 
*     transmitter FIFO has less entries than level.
*   - uartUser_INTR_TX_NOT_FULL - Interrupt source is not cleared when
*     transmitter FIFO has empty entries.
*   - uartUser_INTR_TX_EMPTY - Interrupt source is not cleared when 
*     transmitter FIFO is empty.
*   - uartUser_INTR_TX_UNDERFLOW - Interrupt source is not cleared when 
*     transmitter FIFO is empty and I2C mode with clock stretching is selected. 
*     Put data into the transmitter FIFO before clearing it. This behavior only 
*     applicable for PSoC 4100/PSoC 4200 devices.
*
*******************************************************************************/
#define uartUser_ClearTxInterruptSource(interruptMask)  uartUser_CLEAR_INTR_TX(interruptMask)


/*******************************************************************************
* Function Name: uartUser_SetTxInterrupt
****************************************************************************//**
*
*  Sets RX interrupt sources in the interrupt request register.
*
*  \param interruptMask: RX interrupt sources to set in the RX interrupt request 
*   register (refer to uartUser_GetRxInterruptSource() function for bit 
*   fields values).
*
*******************************************************************************/
#define uartUser_SetTxInterrupt(interruptMask)  uartUser_SET_INTR_TX(interruptMask)

void uartUser_SetTxFifoLevel(uint32 level);


/* APIs to service INTR_MASTER register */
/*******************************************************************************
* Function Name: uartUser_GetMasterInterruptSource
****************************************************************************//**
*
*  Returns Master interrupt request register. This register contains current 
*  status of Master interrupt sources.
*
*  \return 
*   Current status of Master interrupt sources. 
*   Each constant is a bit field value. The value returned may have multiple 
*   bits set to indicate the current status.
*   - uartUser_INTR_MASTER_SPI_DONE - SPI master transfer is complete.
*     Refer to Interrupt sources section for detailed description.
*   - uartUser_INTR_MASTER_I2C_ARB_LOST - I2C master lost arbitration.
*   - uartUser_INTR_MASTER_I2C_NACK - I2C master received negative 
*    acknowledgement (NAK).
*   - uartUser_INTR_MASTER_I2C_ACK - I2C master received acknowledgement.
*   - uartUser_INTR_MASTER_I2C_STOP - I2C master generated STOP.
*   - uartUser_INTR_MASTER_I2C_BUS_ERROR - I2C master bus error 
*     (detection of unexpected START or STOP condition).
*
*******************************************************************************/
#define uartUser_GetMasterInterruptSource() (uartUser_INTR_MASTER_REG)

/*******************************************************************************
* Function Name: uartUser_SetMasterInterruptMode
****************************************************************************//**
*
*  Writes Master interrupt mask register. This register configures which bits 
*  from Master interrupt request register will trigger an interrupt event.
*
*  \param interruptMask: Master interrupt sources to be enabled (refer to 
*   uartUser_GetMasterInterruptSource() function for bit field values).
*
*******************************************************************************/
#define uartUser_SetMasterInterruptMode(interruptMask)  uartUser_WRITE_INTR_MASTER_MASK(interruptMask)

/*******************************************************************************
* Function Name: uartUser_GetMasterInterruptMode
****************************************************************************//**
*
*  Returns Master interrupt mask register This register specifies which bits 
*  from Master interrupt request register will trigger an interrupt event.
*
*  \return 
*   Enabled Master interrupt sources (refer to 
*   uartUser_GetMasterInterruptSource() function for return values).
*
*******************************************************************************/
#define uartUser_GetMasterInterruptMode()   (uartUser_INTR_MASTER_MASK_REG)

/*******************************************************************************
* Function Name: uartUser_GetMasterInterruptSourceMasked
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
*   uartUser_GetMasterInterruptSource() function for return values).
*
*******************************************************************************/
#define uartUser_GetMasterInterruptSourceMasked()   (uartUser_INTR_MASTER_MASKED_REG)

/*******************************************************************************
* Function Name: uartUser_ClearMasterInterruptSource
****************************************************************************//**
*
*  Clears Master interrupt sources in the interrupt request register.
*
*  \param interruptMask: Master interrupt sources to be cleared (refer to 
*   uartUser_GetMasterInterruptSource() function for bit field values).
*
*******************************************************************************/
#define uartUser_ClearMasterInterruptSource(interruptMask)  uartUser_CLEAR_INTR_MASTER(interruptMask)

/*******************************************************************************
* Function Name: uartUser_SetMasterInterrupt
****************************************************************************//**
*
*  Sets Master interrupt sources in the interrupt request register.
*
*  \param interruptMask: Master interrupt sources to set in the Master interrupt
*   request register (refer to uartUser_GetMasterInterruptSource() 
*   function for bit field values).
*
*******************************************************************************/
#define uartUser_SetMasterInterrupt(interruptMask)  uartUser_SET_INTR_MASTER(interruptMask)


/* APIs to service INTR_SLAVE register */
/*******************************************************************************
* Function Name: uartUser_GetSlaveInterruptSource
****************************************************************************//**
*
*  Returns Slave interrupt request register. This register contains current 
*  status of Slave interrupt sources.
*
*  \return 
*   Current status of Slave interrupt sources.
*   Each constant is a bit field value. The value returned may have multiple 
*   bits set to indicate the current status.
*   - uartUser_INTR_SLAVE_I2C_ARB_LOST - I2C slave lost arbitration: 
*     the value driven on the SDA line is not the same as the value observed 
*     on the SDA line.
*   - uartUser_INTR_SLAVE_I2C_NACK - I2C slave received negative 
*     acknowledgement (NAK).
*   - uartUser_INTR_SLAVE_I2C_ACK - I2C slave received 
*     acknowledgement (ACK).
*   - uartUser_INTR_SLAVE_I2C_WRITE_STOP - Stop or Repeated Start 
*     event for write transfer intended for this slave (address matching 
*     is performed).
*   - uartUser_INTR_SLAVE_I2C_STOP - Stop or Repeated Start event 
*     for (read or write) transfer intended for this slave (address matching 
*     is performed).
*   - uartUser_INTR_SLAVE_I2C_START - I2C slave received Start 
*     condition.
*   - uartUser_INTR_SLAVE_I2C_ADDR_MATCH - I2C slave received matching 
*     address.
*   - uartUser_INTR_SLAVE_I2C_GENERAL - I2C Slave received general 
*     call address.
*   - uartUser_INTR_SLAVE_I2C_BUS_ERROR - I2C slave bus error (detection 
*      of unexpected Start or Stop condition).
*   - uartUser_INTR_SLAVE_SPI_BUS_ERROR - SPI slave select line is 
*      deselected at an expected time while the SPI transfer.
*
*******************************************************************************/
#define uartUser_GetSlaveInterruptSource()  (uartUser_INTR_SLAVE_REG)

/*******************************************************************************
* Function Name: uartUser_SetSlaveInterruptMode
****************************************************************************//**
*
*  Writes Slave interrupt mask register. 
*  This register configures which bits from Slave interrupt request register 
*  will trigger an interrupt event.
*
*  \param interruptMask: Slave interrupt sources to be enabled (refer to 
*   uartUser_GetSlaveInterruptSource() function for bit field values).
*
*******************************************************************************/
#define uartUser_SetSlaveInterruptMode(interruptMask)   uartUser_WRITE_INTR_SLAVE_MASK(interruptMask)

/*******************************************************************************
* Function Name: uartUser_GetSlaveInterruptMode
****************************************************************************//**
*
*  Returns Slave interrupt mask register.
*  This register specifies which bits from Slave interrupt request register 
*  will trigger an interrupt event.
*
*  \return 
*   Enabled Slave interrupt sources(refer to 
*   uartUser_GetSlaveInterruptSource() function for bit field values).
*
*******************************************************************************/
#define uartUser_GetSlaveInterruptMode()    (uartUser_INTR_SLAVE_MASK_REG)

/*******************************************************************************
* Function Name: uartUser_GetSlaveInterruptSourceMasked
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
*   uartUser_GetSlaveInterruptSource() function for return values).
*
*******************************************************************************/
#define uartUser_GetSlaveInterruptSourceMasked()    (uartUser_INTR_SLAVE_MASKED_REG)

/*******************************************************************************
* Function Name: uartUser_ClearSlaveInterruptSource
****************************************************************************//**
*
*  Clears Slave interrupt sources in the interrupt request register.
*
*  \param interruptMask: Slave interrupt sources to be cleared (refer to 
*   uartUser_GetSlaveInterruptSource() function for return values).
*
*******************************************************************************/
#define uartUser_ClearSlaveInterruptSource(interruptMask)   uartUser_CLEAR_INTR_SLAVE(interruptMask)

/*******************************************************************************
* Function Name: uartUser_SetSlaveInterrupt
****************************************************************************//**
*
*  Sets Slave interrupt sources in the interrupt request register.
*
*  \param interruptMask: Slave interrupt sources to set in the Slave interrupt 
*   request register (refer to uartUser_GetSlaveInterruptSource() 
*   function for return values).
*
*******************************************************************************/
#define uartUser_SetSlaveInterrupt(interruptMask)   uartUser_SET_INTR_SLAVE(interruptMask)

/** @} interrupt */ 


/***************************************
*     Vars with External Linkage
***************************************/

/**
* \addtogroup group_globals
* @{
*/

/** uartUser_initVar indicates whether the uartUser 
*  component has been initialized. The variable is initialized to 0 
*  and set to 1 the first time SCB_Start() is called. This allows 
*  the component to restart without reinitialization after the first 
*  call to the uartUser_Start() routine.
*
*  If re-initialization of the component is required, then the 
*  uartUser_Init() function can be called before the 
*  uartUser_Start() or uartUser_Enable() function.
*/
extern uint8 uartUser_initVar;
/** @} globals */

/***************************************
*              Registers
***************************************/

#define uartUser_CTRL_REG               (*(reg32 *) uartUser_SCB__CTRL)
#define uartUser_CTRL_PTR               ( (reg32 *) uartUser_SCB__CTRL)

#define uartUser_STATUS_REG             (*(reg32 *) uartUser_SCB__STATUS)
#define uartUser_STATUS_PTR             ( (reg32 *) uartUser_SCB__STATUS)

#if (!uartUser_CY_SCBIP_V1)
    #define uartUser_SPI_CTRL_REG           (*(reg32 *) uartUser_SCB__SPI_CTRL)
    #define uartUser_SPI_CTRL_PTR           ( (reg32 *) uartUser_SCB__SPI_CTRL)

    #define uartUser_SPI_STATUS_REG         (*(reg32 *) uartUser_SCB__SPI_STATUS)
    #define uartUser_SPI_STATUS_PTR         ( (reg32 *) uartUser_SCB__SPI_STATUS)

    #define uartUser_UART_CTRL_REG          (*(reg32 *) uartUser_SCB__UART_CTRL)
    #define uartUser_UART_CTRL_PTR          ( (reg32 *) uartUser_SCB__UART_CTRL)

    #define uartUser_UART_TX_CTRL_REG       (*(reg32 *) uartUser_SCB__UART_TX_CTRL)
    #define uartUser_UART_TX_CTRL_PTR       ( (reg32 *) uartUser_SCB__UART_TX_CTRL)

    #define uartUser_UART_RX_CTRL_REG       (*(reg32 *) uartUser_SCB__UART_RX_CTRL)
    #define uartUser_UART_RX_CTRL_PTR       ( (reg32 *) uartUser_SCB__UART_RX_CTRL)

    #define uartUser_UART_RX_STATUS_REG     (*(reg32 *) uartUser_SCB__UART_RX_STATUS)
    #define uartUser_UART_RX_STATUS_PTR     ( (reg32 *) uartUser_SCB__UART_RX_STATUS)
#endif /* (!uartUser_CY_SCBIP_V1) */

#if !(uartUser_CY_SCBIP_V0 || uartUser_CY_SCBIP_V1)
    #define uartUser_UART_FLOW_CTRL_REG     (*(reg32 *) uartUser_SCB__UART_FLOW_CTRL)
    #define uartUser_UART_FLOW_CTRL_PTR     ( (reg32 *) uartUser_SCB__UART_FLOW_CTRL)
#endif /* !(uartUser_CY_SCBIP_V0 || uartUser_CY_SCBIP_V1) */

#define uartUser_I2C_CTRL_REG           (*(reg32 *) uartUser_SCB__I2C_CTRL)
#define uartUser_I2C_CTRL_PTR           ( (reg32 *) uartUser_SCB__I2C_CTRL)

#define uartUser_I2C_STATUS_REG         (*(reg32 *) uartUser_SCB__I2C_STATUS)
#define uartUser_I2C_STATUS_PTR         ( (reg32 *) uartUser_SCB__I2C_STATUS)

#define uartUser_I2C_MASTER_CMD_REG     (*(reg32 *) uartUser_SCB__I2C_M_CMD)
#define uartUser_I2C_MASTER_CMD_PTR     ( (reg32 *) uartUser_SCB__I2C_M_CMD)

#define uartUser_I2C_SLAVE_CMD_REG      (*(reg32 *) uartUser_SCB__I2C_S_CMD)
#define uartUser_I2C_SLAVE_CMD_PTR      ( (reg32 *) uartUser_SCB__I2C_S_CMD)

#define uartUser_I2C_CFG_REG            (*(reg32 *) uartUser_SCB__I2C_CFG)
#define uartUser_I2C_CFG_PTR            ( (reg32 *) uartUser_SCB__I2C_CFG)

#define uartUser_TX_CTRL_REG            (*(reg32 *) uartUser_SCB__TX_CTRL)
#define uartUser_TX_CTRL_PTR            ( (reg32 *) uartUser_SCB__TX_CTRL)

#define uartUser_TX_FIFO_CTRL_REG       (*(reg32 *) uartUser_SCB__TX_FIFO_CTRL)
#define uartUser_TX_FIFO_CTRL_PTR       ( (reg32 *) uartUser_SCB__TX_FIFO_CTRL)

#define uartUser_TX_FIFO_STATUS_REG     (*(reg32 *) uartUser_SCB__TX_FIFO_STATUS)
#define uartUser_TX_FIFO_STATUS_PTR     ( (reg32 *) uartUser_SCB__TX_FIFO_STATUS)

#define uartUser_TX_FIFO_WR_REG         (*(reg32 *) uartUser_SCB__TX_FIFO_WR)
#define uartUser_TX_FIFO_WR_PTR         ( (reg32 *) uartUser_SCB__TX_FIFO_WR)

#define uartUser_RX_CTRL_REG            (*(reg32 *) uartUser_SCB__RX_CTRL)
#define uartUser_RX_CTRL_PTR            ( (reg32 *) uartUser_SCB__RX_CTRL)

#define uartUser_RX_FIFO_CTRL_REG       (*(reg32 *) uartUser_SCB__RX_FIFO_CTRL)
#define uartUser_RX_FIFO_CTRL_PTR       ( (reg32 *) uartUser_SCB__RX_FIFO_CTRL)

#define uartUser_RX_FIFO_STATUS_REG     (*(reg32 *) uartUser_SCB__RX_FIFO_STATUS)
#define uartUser_RX_FIFO_STATUS_PTR     ( (reg32 *) uartUser_SCB__RX_FIFO_STATUS)

#define uartUser_RX_MATCH_REG           (*(reg32 *) uartUser_SCB__RX_MATCH)
#define uartUser_RX_MATCH_PTR           ( (reg32 *) uartUser_SCB__RX_MATCH)

#define uartUser_RX_FIFO_RD_REG         (*(reg32 *) uartUser_SCB__RX_FIFO_RD)
#define uartUser_RX_FIFO_RD_PTR         ( (reg32 *) uartUser_SCB__RX_FIFO_RD)

#define uartUser_RX_FIFO_RD_SILENT_REG  (*(reg32 *) uartUser_SCB__RX_FIFO_RD_SILENT)
#define uartUser_RX_FIFO_RD_SILENT_PTR  ( (reg32 *) uartUser_SCB__RX_FIFO_RD_SILENT)

#ifdef uartUser_SCB__EZ_DATA0
    #define uartUser_EZBUF_DATA0_REG    (*(reg32 *) uartUser_SCB__EZ_DATA0)
    #define uartUser_EZBUF_DATA0_PTR    ( (reg32 *) uartUser_SCB__EZ_DATA0)
#else
    #define uartUser_EZBUF_DATA0_REG    (*(reg32 *) uartUser_SCB__EZ_DATA00)
    #define uartUser_EZBUF_DATA0_PTR    ( (reg32 *) uartUser_SCB__EZ_DATA00)
#endif /* uartUser_SCB__EZ_DATA00 */

#define uartUser_INTR_CAUSE_REG         (*(reg32 *) uartUser_SCB__INTR_CAUSE)
#define uartUser_INTR_CAUSE_PTR         ( (reg32 *) uartUser_SCB__INTR_CAUSE)

#define uartUser_INTR_I2C_EC_REG        (*(reg32 *) uartUser_SCB__INTR_I2C_EC)
#define uartUser_INTR_I2C_EC_PTR        ( (reg32 *) uartUser_SCB__INTR_I2C_EC)

#define uartUser_INTR_I2C_EC_MASK_REG   (*(reg32 *) uartUser_SCB__INTR_I2C_EC_MASK)
#define uartUser_INTR_I2C_EC_MASK_PTR   ( (reg32 *) uartUser_SCB__INTR_I2C_EC_MASK)

#define uartUser_INTR_I2C_EC_MASKED_REG (*(reg32 *) uartUser_SCB__INTR_I2C_EC_MASKED)
#define uartUser_INTR_I2C_EC_MASKED_PTR ( (reg32 *) uartUser_SCB__INTR_I2C_EC_MASKED)

#if (!uartUser_CY_SCBIP_V1)
    #define uartUser_INTR_SPI_EC_REG        (*(reg32 *) uartUser_SCB__INTR_SPI_EC)
    #define uartUser_INTR_SPI_EC_PTR        ( (reg32 *) uartUser_SCB__INTR_SPI_EC)

    #define uartUser_INTR_SPI_EC_MASK_REG   (*(reg32 *) uartUser_SCB__INTR_SPI_EC_MASK)
    #define uartUser_INTR_SPI_EC_MASK_PTR   ( (reg32 *) uartUser_SCB__INTR_SPI_EC_MASK)

    #define uartUser_INTR_SPI_EC_MASKED_REG (*(reg32 *) uartUser_SCB__INTR_SPI_EC_MASKED)
    #define uartUser_INTR_SPI_EC_MASKED_PTR ( (reg32 *) uartUser_SCB__INTR_SPI_EC_MASKED)
#endif /* (!uartUser_CY_SCBIP_V1) */

#define uartUser_INTR_MASTER_REG        (*(reg32 *) uartUser_SCB__INTR_M)
#define uartUser_INTR_MASTER_PTR        ( (reg32 *) uartUser_SCB__INTR_M)

#define uartUser_INTR_MASTER_SET_REG    (*(reg32 *) uartUser_SCB__INTR_M_SET)
#define uartUser_INTR_MASTER_SET_PTR    ( (reg32 *) uartUser_SCB__INTR_M_SET)

#define uartUser_INTR_MASTER_MASK_REG   (*(reg32 *) uartUser_SCB__INTR_M_MASK)
#define uartUser_INTR_MASTER_MASK_PTR   ( (reg32 *) uartUser_SCB__INTR_M_MASK)

#define uartUser_INTR_MASTER_MASKED_REG (*(reg32 *) uartUser_SCB__INTR_M_MASKED)
#define uartUser_INTR_MASTER_MASKED_PTR ( (reg32 *) uartUser_SCB__INTR_M_MASKED)

#define uartUser_INTR_SLAVE_REG         (*(reg32 *) uartUser_SCB__INTR_S)
#define uartUser_INTR_SLAVE_PTR         ( (reg32 *) uartUser_SCB__INTR_S)

#define uartUser_INTR_SLAVE_SET_REG     (*(reg32 *) uartUser_SCB__INTR_S_SET)
#define uartUser_INTR_SLAVE_SET_PTR     ( (reg32 *) uartUser_SCB__INTR_S_SET)

#define uartUser_INTR_SLAVE_MASK_REG    (*(reg32 *) uartUser_SCB__INTR_S_MASK)
#define uartUser_INTR_SLAVE_MASK_PTR    ( (reg32 *) uartUser_SCB__INTR_S_MASK)

#define uartUser_INTR_SLAVE_MASKED_REG  (*(reg32 *) uartUser_SCB__INTR_S_MASKED)
#define uartUser_INTR_SLAVE_MASKED_PTR  ( (reg32 *) uartUser_SCB__INTR_S_MASKED)

#define uartUser_INTR_TX_REG            (*(reg32 *) uartUser_SCB__INTR_TX)
#define uartUser_INTR_TX_PTR            ( (reg32 *) uartUser_SCB__INTR_TX)

#define uartUser_INTR_TX_SET_REG        (*(reg32 *) uartUser_SCB__INTR_TX_SET)
#define uartUser_INTR_TX_SET_PTR        ( (reg32 *) uartUser_SCB__INTR_TX_SET)

#define uartUser_INTR_TX_MASK_REG       (*(reg32 *) uartUser_SCB__INTR_TX_MASK)
#define uartUser_INTR_TX_MASK_PTR       ( (reg32 *) uartUser_SCB__INTR_TX_MASK)

#define uartUser_INTR_TX_MASKED_REG     (*(reg32 *) uartUser_SCB__INTR_TX_MASKED)
#define uartUser_INTR_TX_MASKED_PTR     ( (reg32 *) uartUser_SCB__INTR_TX_MASKED)

#define uartUser_INTR_RX_REG            (*(reg32 *) uartUser_SCB__INTR_RX)
#define uartUser_INTR_RX_PTR            ( (reg32 *) uartUser_SCB__INTR_RX)

#define uartUser_INTR_RX_SET_REG        (*(reg32 *) uartUser_SCB__INTR_RX_SET)
#define uartUser_INTR_RX_SET_PTR        ( (reg32 *) uartUser_SCB__INTR_RX_SET)

#define uartUser_INTR_RX_MASK_REG       (*(reg32 *) uartUser_SCB__INTR_RX_MASK)
#define uartUser_INTR_RX_MASK_PTR       ( (reg32 *) uartUser_SCB__INTR_RX_MASK)

#define uartUser_INTR_RX_MASKED_REG     (*(reg32 *) uartUser_SCB__INTR_RX_MASKED)
#define uartUser_INTR_RX_MASKED_PTR     ( (reg32 *) uartUser_SCB__INTR_RX_MASKED)

/* Defines get from SCB IP parameters. */
#define uartUser_FIFO_SIZE      (8u)  /* TX or RX FIFO size. */
#define uartUser_EZ_DATA_NR     (32u)  /* Number of words in EZ memory. */ 
#define uartUser_ONE_BYTE_WIDTH (8u)            /* Number of bits in one byte. */
#define uartUser_FF_DATA_NR_LOG2_MASK       (0x07u)      /* Number of bits to represent a FIFO address. */
#define uartUser_FF_DATA_NR_LOG2_PLUS1_MASK (0x0Fu) /* Number of bits to represent #bytes in FIFO. */


/***************************************
*        Registers Constants
***************************************/

#if (uartUser_SCB_IRQ_INTERNAL)
    #define uartUser_ISR_NUMBER     ((uint8) uartUser_SCB_IRQ__INTC_NUMBER)
    #define uartUser_ISR_PRIORITY   ((uint8) uartUser_SCB_IRQ__INTC_PRIOR_NUM)
#endif /* (uartUser_SCB_IRQ_INTERNAL) */

#if (uartUser_UART_RX_WAKEUP_IRQ)
    #define uartUser_RX_WAKE_ISR_NUMBER     ((uint8) uartUser_RX_WAKEUP_IRQ__INTC_NUMBER)
    #define uartUser_RX_WAKE_ISR_PRIORITY   ((uint8) uartUser_RX_WAKEUP_IRQ__INTC_PRIOR_NUM)
#endif /* (uartUser_UART_RX_WAKEUP_IRQ) */

/* uartUser_CTRL_REG */
#define uartUser_CTRL_OVS_POS           (0u)  /* [3:0]   Oversampling factor                 */
#define uartUser_CTRL_EC_AM_MODE_POS    (8u)  /* [8]     Externally clocked address match    */
#define uartUser_CTRL_EC_OP_MODE_POS    (9u)  /* [9]     Externally clocked operation mode   */
#define uartUser_CTRL_EZBUF_MODE_POS    (10u) /* [10]    EZ buffer is enabled                */
#if !(uartUser_CY_SCBIP_V0 || uartUser_CY_SCBIP_V1)
    #define uartUser_CTRL_BYTE_MODE_POS (11u) /* [11]    Determines the number of bits per FIFO data element */
#endif /* !(uartUser_CY_SCBIP_V0 || uartUser_CY_SCBIP_V1) */
#define uartUser_CTRL_ADDR_ACCEPT_POS   (16u) /* [16]    Put matched address in RX FIFO       */
#define uartUser_CTRL_BLOCK_POS         (17u) /* [17]    Ext and Int logic to resolve collide */
#define uartUser_CTRL_MODE_POS          (24u) /* [25:24] Operation mode                       */
#define uartUser_CTRL_ENABLED_POS       (31u) /* [31]    Enable SCB block                     */
#define uartUser_CTRL_OVS_MASK          ((uint32) 0x0Fu)
#define uartUser_CTRL_EC_AM_MODE        ((uint32) 0x01u << uartUser_CTRL_EC_AM_MODE_POS)
#define uartUser_CTRL_EC_OP_MODE        ((uint32) 0x01u << uartUser_CTRL_EC_OP_MODE_POS)
#define uartUser_CTRL_EZBUF_MODE        ((uint32) 0x01u << uartUser_CTRL_EZBUF_MODE_POS)
#if !(uartUser_CY_SCBIP_V0 || uartUser_CY_SCBIP_V1)
    #define uartUser_CTRL_BYTE_MODE ((uint32) 0x01u << uartUser_CTRL_BYTE_MODE_POS)
#endif /* !(uartUser_CY_SCBIP_V0 || uartUser_CY_SCBIP_V1) */
#define uartUser_CTRL_ADDR_ACCEPT       ((uint32) 0x01u << uartUser_CTRL_ADDR_ACCEPT_POS)
#define uartUser_CTRL_BLOCK             ((uint32) 0x01u << uartUser_CTRL_BLOCK_POS)
#define uartUser_CTRL_MODE_MASK         ((uint32) 0x03u << uartUser_CTRL_MODE_POS)
#define uartUser_CTRL_MODE_I2C          ((uint32) 0x00u)
#define uartUser_CTRL_MODE_SPI          ((uint32) 0x01u << uartUser_CTRL_MODE_POS)
#define uartUser_CTRL_MODE_UART         ((uint32) 0x02u << uartUser_CTRL_MODE_POS)
#define uartUser_CTRL_ENABLED           ((uint32) 0x01u << uartUser_CTRL_ENABLED_POS)

/* uartUser_STATUS_REG */
#define uartUser_STATUS_EC_BUSY_POS     (0u)  /* [0] Bus busy. Externally clocked logic access to EZ memory */
#define uartUser_STATUS_EC_BUSY         ((uint32) 0x0Fu)

/* uartUser_SPI_CTRL_REG  */
#define uartUser_SPI_CTRL_CONTINUOUS_POS        (0u)  /* [0]     Continuous or Separated SPI data transfers */
#define uartUser_SPI_CTRL_SELECT_PRECEDE_POS    (1u)  /* [1]     Precedes or coincides start of data frame  */
#define uartUser_SPI_CTRL_CPHA_POS              (2u)  /* [2]     SCLK phase                                 */
#define uartUser_SPI_CTRL_CPOL_POS              (3u)  /* [3]     SCLK polarity                              */
#define uartUser_SPI_CTRL_LATE_MISO_SAMPLE_POS  (4u)  /* [4]     Late MISO sample enabled                   */
#if !(uartUser_CY_SCBIP_V0 || uartUser_CY_SCBIP_V1)
    #define uartUser_SPI_CTRL_SCLK_CONTINUOUS_POS   (5u)  /* [5]     Enable continuous SCLK generation */
    #define uartUser_SPI_CTRL_SSEL0_POLARITY_POS    (8u)  /* [8]     SS0 polarity                      */
    #define uartUser_SPI_CTRL_SSEL1_POLARITY_POS    (9u)  /* [9]     SS1 polarity                      */
    #define uartUser_SPI_CTRL_SSEL2_POLARITY_POS    (10u) /* [10]    SS2 polarity                      */
    #define uartUser_SPI_CTRL_SSEL3_POLARITY_POS    (11u) /* [11]    SS3 polarity                      */
#endif /* !(uartUser_CY_SCBIP_V0 || uartUser_CY_SCBIP_V1) */
#define uartUser_SPI_CTRL_LOOPBACK_POS          (16u) /* [16]    Local loop-back control enabled            */
#define uartUser_SPI_CTRL_MODE_POS              (24u) /* [25:24] Submode of SPI operation                   */
#define uartUser_SPI_CTRL_SLAVE_SELECT_POS      (26u) /* [27:26] Selects SPI SS signal                      */
#define uartUser_SPI_CTRL_MASTER_MODE_POS       (31u) /* [31]    Master mode enabled                        */
#define uartUser_SPI_CTRL_CONTINUOUS            ((uint32) 0x01u)
#define uartUser_SPI_CTRL_SELECT_PRECEDE        ((uint32) 0x01u << uartUser_SPI_CTRL_SELECT_PRECEDE_POS)
#define uartUser_SPI_CTRL_SCLK_MODE_MASK        ((uint32) 0x03u << uartUser_SPI_CTRL_CPHA_POS)
#define uartUser_SPI_CTRL_CPHA                  ((uint32) 0x01u << uartUser_SPI_CTRL_CPHA_POS)
#define uartUser_SPI_CTRL_CPOL                  ((uint32) 0x01u << uartUser_SPI_CTRL_CPOL_POS)
#define uartUser_SPI_CTRL_LATE_MISO_SAMPLE      ((uint32) 0x01u << \
                                                                    uartUser_SPI_CTRL_LATE_MISO_SAMPLE_POS)
#if !(uartUser_CY_SCBIP_V0 || uartUser_CY_SCBIP_V1)
    #define uartUser_SPI_CTRL_SCLK_CONTINUOUS  ((uint32) 0x01u << uartUser_SPI_CTRL_SCLK_CONTINUOUS_POS)
    #define uartUser_SPI_CTRL_SSEL0_POLARITY   ((uint32) 0x01u << uartUser_SPI_CTRL_SSEL0_POLARITY_POS)
    #define uartUser_SPI_CTRL_SSEL1_POLARITY   ((uint32) 0x01u << uartUser_SPI_CTRL_SSEL1_POLARITY_POS)
    #define uartUser_SPI_CTRL_SSEL2_POLARITY   ((uint32) 0x01u << uartUser_SPI_CTRL_SSEL2_POLARITY_POS)
    #define uartUser_SPI_CTRL_SSEL3_POLARITY   ((uint32) 0x01u << uartUser_SPI_CTRL_SSEL3_POLARITY_POS)
    #define uartUser_SPI_CTRL_SSEL_POLARITY_MASK ((uint32)0x0Fu << uartUser_SPI_CTRL_SSEL0_POLARITY_POS)
#endif /* !(uartUser_CY_SCBIP_V0 || uartUser_CY_SCBIP_V1) */

#define uartUser_SPI_CTRL_LOOPBACK              ((uint32) 0x01u << uartUser_SPI_CTRL_LOOPBACK_POS)
#define uartUser_SPI_CTRL_MODE_MASK             ((uint32) 0x03u << uartUser_SPI_CTRL_MODE_POS)
#define uartUser_SPI_CTRL_MODE_MOTOROLA         ((uint32) 0x00u)
#define uartUser_SPI_CTRL_MODE_TI               ((uint32) 0x01u << uartUser_CTRL_MODE_POS)
#define uartUser_SPI_CTRL_MODE_NS               ((uint32) 0x02u << uartUser_CTRL_MODE_POS)
#define uartUser_SPI_CTRL_SLAVE_SELECT_MASK     ((uint32) 0x03u << uartUser_SPI_CTRL_SLAVE_SELECT_POS)
#define uartUser_SPI_CTRL_SLAVE_SELECT0         ((uint32) 0x00u)
#define uartUser_SPI_CTRL_SLAVE_SELECT1         ((uint32) 0x01u << uartUser_SPI_CTRL_SLAVE_SELECT_POS)
#define uartUser_SPI_CTRL_SLAVE_SELECT2         ((uint32) 0x02u << uartUser_SPI_CTRL_SLAVE_SELECT_POS)
#define uartUser_SPI_CTRL_SLAVE_SELECT3         ((uint32) 0x03u << uartUser_SPI_CTRL_SLAVE_SELECT_POS)
#define uartUser_SPI_CTRL_MASTER                ((uint32) 0x01u << uartUser_SPI_CTRL_MASTER_MODE_POS)
#define uartUser_SPI_CTRL_SLAVE                 ((uint32) 0x00u)

/* uartUser_SPI_STATUS_REG  */
#define uartUser_SPI_STATUS_BUS_BUSY_POS    (0u)  /* [0]    Bus busy - slave selected */
#define uartUser_SPI_STATUS_EZBUF_ADDR_POS  (8u)  /* [15:8] EzAddress                 */
#define uartUser_SPI_STATUS_BUS_BUSY        ((uint32) 0x01u)
#define uartUser_SPI_STATUS_EZBUF_ADDR_MASK ((uint32) 0xFFu << uartUser_I2C_STATUS_EZBUF_ADDR_POS)

/* uartUser_UART_CTRL */
#define uartUser_UART_CTRL_LOOPBACK_POS         (16u) /* [16] Loop-back    */
#define uartUser_UART_CTRL_MODE_POS             (24u) /* [24] UART subMode */
#define uartUser_UART_CTRL_LOOPBACK             ((uint32) 0x01u << uartUser_UART_CTRL_LOOPBACK_POS)
#define uartUser_UART_CTRL_MODE_UART_STD        ((uint32) 0x00u)
#define uartUser_UART_CTRL_MODE_UART_SMARTCARD  ((uint32) 0x01u << uartUser_UART_CTRL_MODE_POS)
#define uartUser_UART_CTRL_MODE_UART_IRDA       ((uint32) 0x02u << uartUser_UART_CTRL_MODE_POS)
#define uartUser_UART_CTRL_MODE_MASK            ((uint32) 0x03u << uartUser_UART_CTRL_MODE_POS)

/* uartUser_UART_TX_CTRL */
#define uartUser_UART_TX_CTRL_STOP_BITS_POS         (0u)  /* [2:0] Stop bits: (Stop bits + 1) * 0.5 period */
#define uartUser_UART_TX_CTRL_PARITY_POS            (4u)  /* [4]   Parity bit                              */
#define uartUser_UART_TX_CTRL_PARITY_ENABLED_POS    (5u)  /* [5]   Parity enable                           */
#define uartUser_UART_TX_CTRL_RETRY_ON_NACK_POS     (8u)  /* [8]   Smart Card: re-send frame on NACK       */
#define uartUser_UART_TX_CTRL_ONE_STOP_BIT          ((uint32) 0x01u)
#define uartUser_UART_TX_CTRL_ONE_HALF_STOP_BITS    ((uint32) 0x02u)
#define uartUser_UART_TX_CTRL_TWO_STOP_BITS         ((uint32) 0x03u)
#define uartUser_UART_TX_CTRL_STOP_BITS_MASK        ((uint32) 0x07u)
#define uartUser_UART_TX_CTRL_PARITY                ((uint32) 0x01u << \
                                                                    uartUser_UART_TX_CTRL_PARITY_POS)
#define uartUser_UART_TX_CTRL_PARITY_ENABLED        ((uint32) 0x01u << \
                                                                    uartUser_UART_TX_CTRL_PARITY_ENABLED_POS)
#define uartUser_UART_TX_CTRL_RETRY_ON_NACK         ((uint32) 0x01u << \
                                                                    uartUser_UART_TX_CTRL_RETRY_ON_NACK_POS)

/* uartUser_UART_RX_CTRL */
#define uartUser_UART_RX_CTRL_STOP_BITS_POS             (0u)  /* [2:0] Stop bits: (Stop bits + 1) * 0.5 period*/
#define uartUser_UART_RX_CTRL_PARITY_POS                (4u)  /* [4]   Parity bit                             */
#define uartUser_UART_RX_CTRL_PARITY_ENABLED_POS        (5u)  /* [5]   Parity enable                          */
#define uartUser_UART_RX_CTRL_POLARITY_POS              (6u)  /* [6]   IrDA: inverts polarity of RX signal    */
#define uartUser_UART_RX_CTRL_DROP_ON_PARITY_ERR_POS    (8u)  /* [8]   Drop and lost RX FIFO on parity error  */
#define uartUser_UART_RX_CTRL_DROP_ON_FRAME_ERR_POS     (9u)  /* [9]   Drop and lost RX FIFO on frame error   */
#define uartUser_UART_RX_CTRL_MP_MODE_POS               (10u) /* [10]  Multi-processor mode                   */
#define uartUser_UART_RX_CTRL_LIN_MODE_POS              (12u) /* [12]  Lin mode: applicable for UART Standard */
#define uartUser_UART_RX_CTRL_SKIP_START_POS            (13u) /* [13]  Skip start not: only for UART Standard */
#define uartUser_UART_RX_CTRL_BREAK_WIDTH_POS           (16u) /* [19:16]  Break width: (Break width + 1)      */
#define uartUser_UART_TX_CTRL_ONE_STOP_BIT              ((uint32) 0x01u)
#define uartUser_UART_TX_CTRL_ONE_HALF_STOP_BITS        ((uint32) 0x02u)
#define uartUser_UART_TX_CTRL_TWO_STOP_BITS             ((uint32) 0x03u)
#define uartUser_UART_RX_CTRL_STOP_BITS_MASK            ((uint32) 0x07u)
#define uartUser_UART_RX_CTRL_PARITY                    ((uint32) 0x01u << \
                                                                    uartUser_UART_RX_CTRL_PARITY_POS)
#define uartUser_UART_RX_CTRL_PARITY_ENABLED            ((uint32) 0x01u << \
                                                                    uartUser_UART_RX_CTRL_PARITY_ENABLED_POS)
#define uartUser_UART_RX_CTRL_POLARITY                  ((uint32) 0x01u << \
                                                                    uartUser_UART_RX_CTRL_POLARITY_POS)
#define uartUser_UART_RX_CTRL_DROP_ON_PARITY_ERR        ((uint32) 0x01u << \
                                                                   uartUser_UART_RX_CTRL_DROP_ON_PARITY_ERR_POS)
#define uartUser_UART_RX_CTRL_DROP_ON_FRAME_ERR         ((uint32) 0x01u << \
                                                                    uartUser_UART_RX_CTRL_DROP_ON_FRAME_ERR_POS)
#define uartUser_UART_RX_CTRL_MP_MODE                   ((uint32) 0x01u << \
                                                                    uartUser_UART_RX_CTRL_MP_MODE_POS)
#define uartUser_UART_RX_CTRL_LIN_MODE                  ((uint32) 0x01u << \
                                                                    uartUser_UART_RX_CTRL_LIN_MODE_POS)
#define uartUser_UART_RX_CTRL_SKIP_START                ((uint32) 0x01u << \
                                                                    uartUser_UART_RX_CTRL_SKIP_START_POS)
#define uartUser_UART_RX_CTRL_BREAK_WIDTH_MASK          ((uint32) 0x0Fu << \
                                                                    uartUser_UART_RX_CTRL_BREAK_WIDTH_POS)
/* uartUser_UART_RX_STATUS_REG */
#define uartUser_UART_RX_STATUS_BR_COUNTER_POS     (0u)  /* [11:0] Baud Rate counter */
#define uartUser_UART_RX_STATUS_BR_COUNTER_MASK    ((uint32) 0xFFFu)

#if !(uartUser_CY_SCBIP_V0 || uartUser_CY_SCBIP_V1)
    /* uartUser_UART_FLOW_CTRL_REG */
    #define uartUser_UART_FLOW_CTRL_TRIGGER_LEVEL_POS    (0u)  /* [7:0] RTS RX FIFO trigger level         */
    #define uartUser_UART_FLOW_CTRL_RTS_POLARITY_POS     (16u) /* [16]  Polarity of the RTS output signal */
    #define uartUser_UART_FLOW_CTRL_CTS_POLARITY_POS     (24u) /* [24]  Polarity of the CTS input signal  */
    #define uartUser_UART_FLOW_CTRL_CTS_ENABLED_POS      (25u) /* [25]  Enable CTS signal                 */
    #define uartUser_UART_FLOW_CTRL_TRIGGER_LEVEL_MASK   ((uint32) uartUser_FF_DATA_NR_LOG2_MASK)
    #define uartUser_UART_FLOW_CTRL_RTS_POLARITY         ((uint32) 0x01u << \
                                                                       uartUser_UART_FLOW_CTRL_RTS_POLARITY_POS)
    #define uartUser_UART_FLOW_CTRL_CTS_POLARITY         ((uint32) 0x01u << \
                                                                       uartUser_UART_FLOW_CTRL_CTS_POLARITY_POS)
    #define uartUser_UART_FLOW_CTRL_CTS_ENABLE           ((uint32) 0x01u << \
                                                                       uartUser_UART_FLOW_CTRL_CTS_ENABLED_POS)
#endif /* !(uartUser_CY_SCBIP_V0 || uartUser_CY_SCBIP_V1) */

/* uartUser_I2C_CTRL */
#define uartUser_I2C_CTRL_HIGH_PHASE_OVS_POS           (0u)   /* [3:0] Oversampling factor high: master only */
#define uartUser_I2C_CTRL_LOW_PHASE_OVS_POS            (4u)   /* [7:4] Oversampling factor low:  master only */
#define uartUser_I2C_CTRL_M_READY_DATA_ACK_POS         (8u)   /* [8]   Master ACKs data while RX FIFO != FULL*/
#define uartUser_I2C_CTRL_M_NOT_READY_DATA_NACK_POS    (9u)   /* [9]   Master NACKs data if RX FIFO ==  FULL */
#define uartUser_I2C_CTRL_S_GENERAL_IGNORE_POS         (11u)  /* [11]  Slave ignores General call            */
#define uartUser_I2C_CTRL_S_READY_ADDR_ACK_POS         (12u)  /* [12]  Slave ACKs Address if RX FIFO != FULL */
#define uartUser_I2C_CTRL_S_READY_DATA_ACK_POS         (13u)  /* [13]  Slave ACKs data while RX FIFO == FULL */
#define uartUser_I2C_CTRL_S_NOT_READY_ADDR_NACK_POS    (14u)  /* [14]  Slave NACKs address if RX FIFO == FULL*/
#define uartUser_I2C_CTRL_S_NOT_READY_DATA_NACK_POS    (15u)  /* [15]  Slave NACKs data if RX FIFO is  FULL  */
#define uartUser_I2C_CTRL_LOOPBACK_POS                 (16u)  /* [16]  Loop-back                             */
#define uartUser_I2C_CTRL_SLAVE_MODE_POS               (30u)  /* [30]  Slave mode enabled                    */
#define uartUser_I2C_CTRL_MASTER_MODE_POS              (31u)  /* [31]  Master mode enabled                   */
#define uartUser_I2C_CTRL_HIGH_PHASE_OVS_MASK  ((uint32) 0x0Fu)
#define uartUser_I2C_CTRL_LOW_PHASE_OVS_MASK   ((uint32) 0x0Fu << \
                                                                uartUser_I2C_CTRL_LOW_PHASE_OVS_POS)
#define uartUser_I2C_CTRL_M_READY_DATA_ACK      ((uint32) 0x01u << \
                                                                uartUser_I2C_CTRL_M_READY_DATA_ACK_POS)
#define uartUser_I2C_CTRL_M_NOT_READY_DATA_NACK ((uint32) 0x01u << \
                                                                uartUser_I2C_CTRL_M_NOT_READY_DATA_NACK_POS)
#define uartUser_I2C_CTRL_S_GENERAL_IGNORE      ((uint32) 0x01u << \
                                                                uartUser_I2C_CTRL_S_GENERAL_IGNORE_POS)
#define uartUser_I2C_CTRL_S_READY_ADDR_ACK      ((uint32) 0x01u << \
                                                                uartUser_I2C_CTRL_S_READY_ADDR_ACK_POS)
#define uartUser_I2C_CTRL_S_READY_DATA_ACK      ((uint32) 0x01u << \
                                                                uartUser_I2C_CTRL_S_READY_DATA_ACK_POS)
#define uartUser_I2C_CTRL_S_NOT_READY_ADDR_NACK ((uint32) 0x01u << \
                                                                uartUser_I2C_CTRL_S_NOT_READY_ADDR_NACK_POS)
#define uartUser_I2C_CTRL_S_NOT_READY_DATA_NACK ((uint32) 0x01u << \
                                                                uartUser_I2C_CTRL_S_NOT_READY_DATA_NACK_POS)
#define uartUser_I2C_CTRL_LOOPBACK              ((uint32) 0x01u << \
                                                                uartUser_I2C_CTRL_LOOPBACK_POS)
#define uartUser_I2C_CTRL_SLAVE_MODE            ((uint32) 0x01u << \
                                                                uartUser_I2C_CTRL_SLAVE_MODE_POS)
#define uartUser_I2C_CTRL_MASTER_MODE           ((uint32) 0x01u << \
                                                                uartUser_I2C_CTRL_MASTER_MODE_POS)
#define uartUser_I2C_CTRL_SLAVE_MASTER_MODE_MASK    ((uint32) 0x03u << \
                                                                uartUser_I2C_CTRL_SLAVE_MODE_POS)

/* uartUser_I2C_STATUS_REG  */
#define uartUser_I2C_STATUS_BUS_BUSY_POS    (0u)  /* [0]    Bus busy: internally clocked */
#define uartUser_I2C_STATUS_S_READ_POS      (4u)  /* [4]    Slave is read by master      */
#define uartUser_I2C_STATUS_M_READ_POS      (5u)  /* [5]    Master reads Slave           */
#define uartUser_I2C_STATUS_EZBUF_ADDR_POS  (8u)  /* [15:8] EZAddress                    */
#define uartUser_I2C_STATUS_BUS_BUSY        ((uint32) 0x01u)
#define uartUser_I2C_STATUS_S_READ          ((uint32) 0x01u << uartUser_I2C_STATUS_S_READ_POS)
#define uartUser_I2C_STATUS_M_READ          ((uint32) 0x01u << uartUser_I2C_STATUS_M_READ_POS)
#define uartUser_I2C_STATUS_EZBUF_ADDR_MASK ((uint32) 0xFFu << uartUser_I2C_STATUS_EZBUF_ADDR_POS)

/* uartUser_I2C_MASTER_CMD_REG */
#define uartUser_I2C_MASTER_CMD_M_START_POS             (0u)  /* [0] Master generate Start                */
#define uartUser_I2C_MASTER_CMD_M_START_ON_IDLE_POS     (1u)  /* [1] Master generate Start if bus is free */
#define uartUser_I2C_MASTER_CMD_M_ACK_POS               (2u)  /* [2] Master generate ACK                  */
#define uartUser_I2C_MASTER_CMD_M_NACK_POS              (3u)  /* [3] Master generate NACK                 */
#define uartUser_I2C_MASTER_CMD_M_STOP_POS              (4u)  /* [4] Master generate Stop                 */
#define uartUser_I2C_MASTER_CMD_M_START         ((uint32) 0x01u)
#define uartUser_I2C_MASTER_CMD_M_START_ON_IDLE ((uint32) 0x01u << \
                                                                   uartUser_I2C_MASTER_CMD_M_START_ON_IDLE_POS)
#define uartUser_I2C_MASTER_CMD_M_ACK           ((uint32) 0x01u << \
                                                                   uartUser_I2C_MASTER_CMD_M_ACK_POS)
#define uartUser_I2C_MASTER_CMD_M_NACK          ((uint32) 0x01u << \
                                                                    uartUser_I2C_MASTER_CMD_M_NACK_POS)
#define uartUser_I2C_MASTER_CMD_M_STOP          ((uint32) 0x01u << \
                                                                    uartUser_I2C_MASTER_CMD_M_STOP_POS)

/* uartUser_I2C_SLAVE_CMD_REG  */
#define uartUser_I2C_SLAVE_CMD_S_ACK_POS    (0u)  /* [0] Slave generate ACK  */
#define uartUser_I2C_SLAVE_CMD_S_NACK_POS   (1u)  /* [1] Slave generate NACK */
#define uartUser_I2C_SLAVE_CMD_S_ACK        ((uint32) 0x01u)
#define uartUser_I2C_SLAVE_CMD_S_NACK       ((uint32) 0x01u << uartUser_I2C_SLAVE_CMD_S_NACK_POS)

#define uartUser_I2C_SLAVE_CMD_S_ACK_POS    (0u)  /* [0] Slave generate ACK  */
#define uartUser_I2C_SLAVE_CMD_S_NACK_POS   (1u)  /* [1] Slave generate NACK */
#define uartUser_I2C_SLAVE_CMD_S_ACK        ((uint32) 0x01u)
#define uartUser_I2C_SLAVE_CMD_S_NACK       ((uint32) 0x01u << uartUser_I2C_SLAVE_CMD_S_NACK_POS)

/* uartUser_I2C_CFG_REG */
#if (uartUser_CY_SCBIP_V0)
#define uartUser_I2C_CFG_SDA_FILT_HYS_POS           (0u)  /* [1:0]   Trim bits for the I2C SDA filter         */
#define uartUser_I2C_CFG_SDA_FILT_TRIM_POS          (2u)  /* [3:2]   Trim bits for the I2C SDA filter         */
#define uartUser_I2C_CFG_SCL_FILT_HYS_POS           (4u)  /* [5:4]   Trim bits for the I2C SCL filter         */
#define uartUser_I2C_CFG_SCL_FILT_TRIM_POS          (6u)  /* [7:6]   Trim bits for the I2C SCL filter         */
#define uartUser_I2C_CFG_SDA_FILT_OUT_HYS_POS       (8u)  /* [9:8]   Trim bits for I2C SDA filter output path */
#define uartUser_I2C_CFG_SDA_FILT_OUT_TRIM_POS      (10u) /* [11:10] Trim bits for I2C SDA filter output path */
#define uartUser_I2C_CFG_SDA_FILT_HS_POS            (16u) /* [16]    '0': 50 ns filter, '1': 10 ns filter     */
#define uartUser_I2C_CFG_SDA_FILT_ENABLED_POS       (17u) /* [17]    I2C SDA filter enabled                   */
#define uartUser_I2C_CFG_SCL_FILT_HS_POS            (24u) /* [24]    '0': 50 ns filter, '1': 10 ns filter     */
#define uartUser_I2C_CFG_SCL_FILT_ENABLED_POS       (25u) /* [25]    I2C SCL filter enabled                   */
#define uartUser_I2C_CFG_SDA_FILT_OUT_HS_POS        (26u) /* [26]    '0': 50 ns filter, '1': 10 ns filter     */
#define uartUser_I2C_CFG_SDA_FILT_OUT_ENABLED_POS   (27u) /* [27]    I2C SDA output delay filter enabled      */
#define uartUser_I2C_CFG_SDA_FILT_HYS_MASK          ((uint32) 0x03u)
#define uartUser_I2C_CFG_SDA_FILT_TRIM_MASK         ((uint32) 0x03u << \
                                                                uartUser_I2C_CFG_SDA_FILT_TRIM_POS)
#define uartUser_I2C_CFG_SCL_FILT_HYS_MASK          ((uint32) 0x03u << \
                                                                uartUser_I2C_CFG_SCL_FILT_HYS_POS)
#define uartUser_I2C_CFG_SCL_FILT_TRIM_MASK         ((uint32) 0x03u << \
                                                                uartUser_I2C_CFG_SCL_FILT_TRIM_POS)
#define uartUser_I2C_CFG_SDA_FILT_OUT_HYS_MASK      ((uint32) 0x03u << \
                                                                uartUser_I2C_CFG_SDA_FILT_OUT_HYS_POS)
#define uartUser_I2C_CFG_SDA_FILT_OUT_TRIM_MASK     ((uint32) 0x03u << \
                                                                uartUser_I2C_CFG_SDA_FILT_OUT_TRIM_POS)
#define uartUser_I2C_CFG_SDA_FILT_HS                ((uint32) 0x01u << \
                                                                uartUser_I2C_CFG_SDA_FILT_HS_POS)
#define uartUser_I2C_CFG_SDA_FILT_ENABLED           ((uint32) 0x01u << \
                                                                uartUser_I2C_CFG_SDA_FILT_ENABLED_POS)
#define uartUser_I2C_CFG_SCL_FILT_HS                ((uint32) 0x01u << \
                                                                uartUser_I2C_CFG_SCL_FILT_HS_POS)
#define uartUser_I2C_CFG_SCL_FILT_ENABLED           ((uint32) 0x01u << \
                                                                uartUser_I2C_CFG_SCL_FILT_ENABLED_POS)
#define uartUser_I2C_CFG_SDA_FILT_OUT_HS            ((uint32) 0x01u << \
                                                                uartUser_I2C_CFG_SDA_FILT_OUT_HS_POS)
#define uartUser_I2C_CFG_SDA_FILT_OUT_ENABLED       ((uint32) 0x01u << \
                                                                uartUser_I2C_CFG_SDA_FILT_OUT_ENABLED_POS)
#else
#define uartUser_I2C_CFG_SDA_IN_FILT_TRIM_POS   (0u)  /* [1:0] Trim bits for "i2c_sda_in" 50 ns filter */
#define uartUser_I2C_CFG_SDA_IN_FILT_SEL_POS    (4u)  /* [4]   "i2c_sda_in" filter delay: 0 ns and 50 ns */
#define uartUser_I2C_CFG_SCL_IN_FILT_TRIM_POS   (8u)  /* [9:8] Trim bits for "i2c_scl_in" 50 ns filter */
#define uartUser_I2C_CFG_SCL_IN_FILT_SEL_POS    (12u) /* [12]  "i2c_scl_in" filter delay: 0 ns and 50 ns */
#define uartUser_I2C_CFG_SDA_OUT_FILT0_TRIM_POS (16u) /* [17:16] Trim bits for "i2c_sda_out" 50 ns filter 0 */
#define uartUser_I2C_CFG_SDA_OUT_FILT1_TRIM_POS (18u) /* [19:18] Trim bits for "i2c_sda_out" 50 ns filter 1 */
#define uartUser_I2C_CFG_SDA_OUT_FILT2_TRIM_POS (20u) /* [21:20] Trim bits for "i2c_sda_out" 50 ns filter 2 */
#define uartUser_I2C_CFG_SDA_OUT_FILT_SEL_POS   (28u) /* [29:28] Cumulative "i2c_sda_out" filter delay: */

#define uartUser_I2C_CFG_SDA_IN_FILT_TRIM_MASK  ((uint32) 0x03u)
#define uartUser_I2C_CFG_SDA_IN_FILT_SEL        ((uint32) 0x01u << uartUser_I2C_CFG_SDA_IN_FILT_SEL_POS)
#define uartUser_I2C_CFG_SCL_IN_FILT_TRIM_MASK  ((uint32) 0x03u << \
                                                            uartUser_I2C_CFG_SCL_IN_FILT_TRIM_POS)
#define uartUser_I2C_CFG_SCL_IN_FILT_SEL        ((uint32) 0x01u << uartUser_I2C_CFG_SCL_IN_FILT_SEL_POS)
#define uartUser_I2C_CFG_SDA_OUT_FILT0_TRIM_MASK ((uint32) 0x03u << \
                                                            uartUser_I2C_CFG_SDA_OUT_FILT0_TRIM_POS)
#define uartUser_I2C_CFG_SDA_OUT_FILT1_TRIM_MASK ((uint32) 0x03u << \
                                                            uartUser_I2C_CFG_SDA_OUT_FILT1_TRIM_POS)
#define uartUser_I2C_CFG_SDA_OUT_FILT2_TRIM_MASK ((uint32) 0x03u << \
                                                            uartUser_I2C_CFG_SDA_OUT_FILT2_TRIM_POS)
#define uartUser_I2C_CFG_SDA_OUT_FILT_SEL_MASK   ((uint32) 0x03u << \
                                                            uartUser_I2C_CFG_SDA_OUT_FILT_SEL_POS)
#endif /* (uartUser_CY_SCBIP_V0) */


/* uartUser_TX_CTRL_REG */
#define uartUser_TX_CTRL_DATA_WIDTH_POS     (0u)  /* [3:0] Data frame width: (Data width - 1) */
#define uartUser_TX_CTRL_MSB_FIRST_POS      (8u)  /* [8]   MSB first shifter-out             */
#define uartUser_TX_CTRL_ENABLED_POS        (31u) /* [31]  Transmitter enabled               */
#define uartUser_TX_CTRL_DATA_WIDTH_MASK    ((uint32) 0x0Fu)
#define uartUser_TX_CTRL_MSB_FIRST          ((uint32) 0x01u << uartUser_TX_CTRL_MSB_FIRST_POS)
#define uartUser_TX_CTRL_LSB_FIRST          ((uint32) 0x00u)
#define uartUser_TX_CTRL_ENABLED            ((uint32) 0x01u << uartUser_TX_CTRL_ENABLED_POS)

/* uartUser_TX_CTRL_FIFO_REG */
#define uartUser_TX_FIFO_CTRL_TRIGGER_LEVEL_POS     (0u)  /* [2:0] Trigger level                              */
#define uartUser_TX_FIFO_CTRL_CLEAR_POS             (16u) /* [16]  Clear TX FIFO: cleared after set           */
#define uartUser_TX_FIFO_CTRL_FREEZE_POS            (17u) /* [17]  Freeze TX FIFO: HW do not inc read pointer */
#define uartUser_TX_FIFO_CTRL_TRIGGER_LEVEL_MASK    ((uint32) uartUser_FF_DATA_NR_LOG2_MASK)
#define uartUser_TX_FIFO_CTRL_CLEAR                 ((uint32) 0x01u << uartUser_TX_FIFO_CTRL_CLEAR_POS)
#define uartUser_TX_FIFO_CTRL_FREEZE                ((uint32) 0x01u << uartUser_TX_FIFO_CTRL_FREEZE_POS)

/* uartUser_TX_FIFO_STATUS_REG */
#define uartUser_TX_FIFO_STATUS_USED_POS    (0u)  /* [3:0]   Amount of entries in TX FIFO */
#define uartUser_TX_FIFO_SR_VALID_POS       (15u) /* [15]    Shifter status of TX FIFO    */
#define uartUser_TX_FIFO_STATUS_RD_PTR_POS  (16u) /* [18:16] TX FIFO read pointer         */
#define uartUser_TX_FIFO_STATUS_WR_PTR_POS  (24u) /* [26:24] TX FIFO write pointer        */
#define uartUser_TX_FIFO_STATUS_USED_MASK   ((uint32) uartUser_FF_DATA_NR_LOG2_PLUS1_MASK)
#define uartUser_TX_FIFO_SR_VALID           ((uint32) 0x01u << uartUser_TX_FIFO_SR_VALID_POS)
#define uartUser_TX_FIFO_STATUS_RD_PTR_MASK ((uint32) uartUser_FF_DATA_NR_LOG2_MASK << \
                                                                    uartUser_TX_FIFO_STATUS_RD_PTR_POS)
#define uartUser_TX_FIFO_STATUS_WR_PTR_MASK ((uint32) uartUser_FF_DATA_NR_LOG2_MASK << \
                                                                    uartUser_TX_FIFO_STATUS_WR_PTR_POS)

/* uartUser_TX_FIFO_WR_REG */
#define uartUser_TX_FIFO_WR_POS    (0u)  /* [15:0] Data written into TX FIFO */
#define uartUser_TX_FIFO_WR_MASK   ((uint32) 0xFFu)

/* uartUser_RX_CTRL_REG */
#define uartUser_RX_CTRL_DATA_WIDTH_POS     (0u)  /* [3:0] Data frame width: (Data width - 1) */
#define uartUser_RX_CTRL_MSB_FIRST_POS      (8u)  /* [8]   MSB first shifter-out             */
#define uartUser_RX_CTRL_MEDIAN_POS         (9u)  /* [9]   Median filter                     */
#define uartUser_RX_CTRL_ENABLED_POS        (31u) /* [31]  Receiver enabled                  */
#define uartUser_RX_CTRL_DATA_WIDTH_MASK    ((uint32) 0x0Fu)
#define uartUser_RX_CTRL_MSB_FIRST          ((uint32) 0x01u << uartUser_RX_CTRL_MSB_FIRST_POS)
#define uartUser_RX_CTRL_LSB_FIRST          ((uint32) 0x00u)
#define uartUser_RX_CTRL_MEDIAN             ((uint32) 0x01u << uartUser_RX_CTRL_MEDIAN_POS)
#define uartUser_RX_CTRL_ENABLED            ((uint32) 0x01u << uartUser_RX_CTRL_ENABLED_POS)


/* uartUser_RX_FIFO_CTRL_REG */
#define uartUser_RX_FIFO_CTRL_TRIGGER_LEVEL_POS     (0u)   /* [2:0] Trigger level                            */
#define uartUser_RX_FIFO_CTRL_CLEAR_POS             (16u)  /* [16]  Clear RX FIFO: clear after set           */
#define uartUser_RX_FIFO_CTRL_FREEZE_POS            (17u)  /* [17]  Freeze RX FIFO: HW writes has not effect */
#define uartUser_RX_FIFO_CTRL_TRIGGER_LEVEL_MASK    ((uint32) uartUser_FF_DATA_NR_LOG2_MASK)
#define uartUser_RX_FIFO_CTRL_CLEAR                 ((uint32) 0x01u << uartUser_RX_FIFO_CTRL_CLEAR_POS)
#define uartUser_RX_FIFO_CTRL_FREEZE                ((uint32) 0x01u << uartUser_RX_FIFO_CTRL_FREEZE_POS)

/* uartUser_RX_FIFO_STATUS_REG */
#define uartUser_RX_FIFO_STATUS_USED_POS    (0u)   /* [3:0]   Amount of entries in RX FIFO */
#define uartUser_RX_FIFO_SR_VALID_POS       (15u)  /* [15]    Shifter status of RX FIFO    */
#define uartUser_RX_FIFO_STATUS_RD_PTR_POS  (16u)  /* [18:16] RX FIFO read pointer         */
#define uartUser_RX_FIFO_STATUS_WR_PTR_POS  (24u)  /* [26:24] RX FIFO write pointer        */
#define uartUser_RX_FIFO_STATUS_USED_MASK   ((uint32) uartUser_FF_DATA_NR_LOG2_PLUS1_MASK)
#define uartUser_RX_FIFO_SR_VALID           ((uint32) 0x01u << uartUser_RX_FIFO_SR_VALID_POS)
#define uartUser_RX_FIFO_STATUS_RD_PTR_MASK ((uint32) uartUser_FF_DATA_NR_LOG2_MASK << \
                                                                    uartUser_RX_FIFO_STATUS_RD_PTR_POS)
#define uartUser_RX_FIFO_STATUS_WR_PTR_MASK ((uint32) uartUser_FF_DATA_NR_LOG2_MASK << \
                                                                    uartUser_RX_FIFO_STATUS_WR_PTR_POS)

/* uartUser_RX_MATCH_REG */
#define uartUser_RX_MATCH_ADDR_POS     (0u)  /* [7:0]   Slave address                        */
#define uartUser_RX_MATCH_MASK_POS     (16u) /* [23:16] Slave address mask: 0 - doesn't care */
#define uartUser_RX_MATCH_ADDR_MASK    ((uint32) 0xFFu)
#define uartUser_RX_MATCH_MASK_MASK    ((uint32) 0xFFu << uartUser_RX_MATCH_MASK_POS)

/* uartUser_RX_FIFO_WR_REG */
#define uartUser_RX_FIFO_RD_POS    (0u)  /* [15:0] Data read from RX FIFO */
#define uartUser_RX_FIFO_RD_MASK   ((uint32) 0xFFu)

/* uartUser_RX_FIFO_RD_SILENT_REG */
#define uartUser_RX_FIFO_RD_SILENT_POS     (0u)  /* [15:0] Data read from RX FIFO: not remove data from FIFO */
#define uartUser_RX_FIFO_RD_SILENT_MASK    ((uint32) 0xFFu)

/* uartUser_RX_FIFO_RD_SILENT_REG */
#define uartUser_RX_FIFO_RD_SILENT_POS     (0u)  /* [15:0] Data read from RX FIFO: not remove data from FIFO */
#define uartUser_RX_FIFO_RD_SILENT_MASK    ((uint32) 0xFFu)

/* uartUser_EZBUF_DATA_REG */
#define uartUser_EZBUF_DATA_POS   (0u)  /* [7:0] Data from EZ Memory */
#define uartUser_EZBUF_DATA_MASK  ((uint32) 0xFFu)

/*  uartUser_INTR_CAUSE_REG */
#define uartUser_INTR_CAUSE_MASTER_POS  (0u)  /* [0] Master interrupt active                 */
#define uartUser_INTR_CAUSE_SLAVE_POS   (1u)  /* [1] Slave interrupt active                  */
#define uartUser_INTR_CAUSE_TX_POS      (2u)  /* [2] Transmitter interrupt active            */
#define uartUser_INTR_CAUSE_RX_POS      (3u)  /* [3] Receiver interrupt active               */
#define uartUser_INTR_CAUSE_I2C_EC_POS  (4u)  /* [4] Externally clock I2C interrupt active   */
#define uartUser_INTR_CAUSE_SPI_EC_POS  (5u)  /* [5] Externally clocked SPI interrupt active */
#define uartUser_INTR_CAUSE_MASTER      ((uint32) 0x01u)
#define uartUser_INTR_CAUSE_SLAVE       ((uint32) 0x01u << uartUser_INTR_CAUSE_SLAVE_POS)
#define uartUser_INTR_CAUSE_TX          ((uint32) 0x01u << uartUser_INTR_CAUSE_TX_POS)
#define uartUser_INTR_CAUSE_RX          ((uint32) 0x01u << uartUser_INTR_CAUSE_RX_POS)
#define uartUser_INTR_CAUSE_I2C_EC      ((uint32) 0x01u << uartUser_INTR_CAUSE_I2C_EC_POS)
#define uartUser_INTR_CAUSE_SPI_EC      ((uint32) 0x01u << uartUser_INTR_CAUSE_SPI_EC_POS)

/* uartUser_INTR_SPI_EC_REG, uartUser_INTR_SPI_EC_MASK_REG, uartUser_INTR_SPI_EC_MASKED_REG */
#define uartUser_INTR_SPI_EC_WAKE_UP_POS          (0u)  /* [0] Address match: triggers wakeup of chip */
#define uartUser_INTR_SPI_EC_EZBUF_STOP_POS       (1u)  /* [1] Externally clocked Stop detected       */
#define uartUser_INTR_SPI_EC_EZBUF_WRITE_STOP_POS (2u)  /* [2] Externally clocked Write Stop detected */
#define uartUser_INTR_SPI_EC_WAKE_UP              ((uint32) 0x01u)
#define uartUser_INTR_SPI_EC_EZBUF_STOP           ((uint32) 0x01u << \
                                                                    uartUser_INTR_SPI_EC_EZBUF_STOP_POS)
#define uartUser_INTR_SPI_EC_EZBUF_WRITE_STOP     ((uint32) 0x01u << \
                                                                    uartUser_INTR_SPI_EC_EZBUF_WRITE_STOP_POS)

/* uartUser_INTR_I2C_EC, uartUser_INTR_I2C_EC_MASK, uartUser_INTR_I2C_EC_MASKED */
#define uartUser_INTR_I2C_EC_WAKE_UP_POS          (0u)  /* [0] Address match: triggers wakeup of chip */
#define uartUser_INTR_I2C_EC_EZBUF_STOP_POS       (1u)  /* [1] Externally clocked Stop detected       */
#define uartUser_INTR_I2C_EC_EZBUF_WRITE_STOP_POS (2u)  /* [2] Externally clocked Write Stop detected */
#define uartUser_INTR_I2C_EC_WAKE_UP              ((uint32) 0x01u)
#define uartUser_INTR_I2C_EC_EZBUF_STOP           ((uint32) 0x01u << \
                                                                    uartUser_INTR_I2C_EC_EZBUF_STOP_POS)
#define uartUser_INTR_I2C_EC_EZBUF_WRITE_STOP     ((uint32) 0x01u << \
                                                                    uartUser_INTR_I2C_EC_EZBUF_WRITE_STOP_POS)

/* uartUser_INTR_MASTER, uartUser_INTR_MASTER_SET,
   uartUser_INTR_MASTER_MASK, uartUser_INTR_MASTER_MASKED */
#define uartUser_INTR_MASTER_I2C_ARB_LOST_POS   (0u)  /* [0] Master lost arbitration                          */
#define uartUser_INTR_MASTER_I2C_NACK_POS       (1u)  /* [1] Master receives NACK: address or write to slave  */
#define uartUser_INTR_MASTER_I2C_ACK_POS        (2u)  /* [2] Master receives NACK: address or write to slave  */
#define uartUser_INTR_MASTER_I2C_STOP_POS       (4u)  /* [4] Master detects the Stop: only self generated Stop*/
#define uartUser_INTR_MASTER_I2C_BUS_ERROR_POS  (8u)  /* [8] Master detects bus error: misplaced Start or Stop*/
#define uartUser_INTR_MASTER_SPI_DONE_POS       (9u)  /* [9] Master complete transfer: Only for SPI           */
#define uartUser_INTR_MASTER_I2C_ARB_LOST       ((uint32) 0x01u)
#define uartUser_INTR_MASTER_I2C_NACK           ((uint32) 0x01u << uartUser_INTR_MASTER_I2C_NACK_POS)
#define uartUser_INTR_MASTER_I2C_ACK            ((uint32) 0x01u << uartUser_INTR_MASTER_I2C_ACK_POS)
#define uartUser_INTR_MASTER_I2C_STOP           ((uint32) 0x01u << uartUser_INTR_MASTER_I2C_STOP_POS)
#define uartUser_INTR_MASTER_I2C_BUS_ERROR      ((uint32) 0x01u << \
                                                                    uartUser_INTR_MASTER_I2C_BUS_ERROR_POS)
#define uartUser_INTR_MASTER_SPI_DONE           ((uint32) 0x01u << uartUser_INTR_MASTER_SPI_DONE_POS)

/*
* uartUser_INTR_SLAVE, uartUser_INTR_SLAVE_SET,
* uartUser_INTR_SLAVE_MASK, uartUser_INTR_SLAVE_MASKED
*/
#define uartUser_INTR_SLAVE_I2C_ARB_LOST_POS         (0u)  /* [0]  Slave lost arbitration                   */
#define uartUser_INTR_SLAVE_I2C_NACK_POS             (1u)  /* [1]  Slave receives NACK: master reads data   */
#define uartUser_INTR_SLAVE_I2C_ACK_POS              (2u)  /* [2]  Slave receives ACK: master reads data    */
#define uartUser_INTR_SLAVE_I2C_WRITE_STOP_POS       (3u)  /* [3]  Slave detects end of write transaction   */
#define uartUser_INTR_SLAVE_I2C_STOP_POS             (4u)  /* [4]  Slave detects end of transaction intended */
#define uartUser_INTR_SLAVE_I2C_START_POS            (5u)  /* [5]  Slave detects Start                      */
#define uartUser_INTR_SLAVE_I2C_ADDR_MATCH_POS       (6u)  /* [6]  Slave address matches                    */
#define uartUser_INTR_SLAVE_I2C_GENERAL_POS          (7u)  /* [7]  General call received                    */
#define uartUser_INTR_SLAVE_I2C_BUS_ERROR_POS        (8u)  /* [8]  Slave detects bus error                  */
#define uartUser_INTR_SLAVE_SPI_EZBUF_WRITE_STOP_POS (9u)  /* [9]  Slave write complete: Only for SPI       */
#define uartUser_INTR_SLAVE_SPI_EZBUF_STOP_POS       (10u) /* [10] Slave end of transaction: Only for SPI   */
#define uartUser_INTR_SLAVE_SPI_BUS_ERROR_POS        (11u) /* [11] Slave detects bus error: Only for SPI    */
#define uartUser_INTR_SLAVE_I2C_ARB_LOST             ((uint32) 0x01u)
#define uartUser_INTR_SLAVE_I2C_NACK                 ((uint32) 0x01u << \
                                                                    uartUser_INTR_SLAVE_I2C_NACK_POS)
#define uartUser_INTR_SLAVE_I2C_ACK                  ((uint32) 0x01u << \
                                                                    uartUser_INTR_SLAVE_I2C_ACK_POS)
#define uartUser_INTR_SLAVE_I2C_WRITE_STOP           ((uint32) 0x01u << \
                                                                    uartUser_INTR_SLAVE_I2C_WRITE_STOP_POS)
#define uartUser_INTR_SLAVE_I2C_STOP                 ((uint32) 0x01u << \
                                                                    uartUser_INTR_SLAVE_I2C_STOP_POS)
#define uartUser_INTR_SLAVE_I2C_START                ((uint32) 0x01u << \
                                                                    uartUser_INTR_SLAVE_I2C_START_POS)
#define uartUser_INTR_SLAVE_I2C_ADDR_MATCH           ((uint32) 0x01u << \
                                                                    uartUser_INTR_SLAVE_I2C_ADDR_MATCH_POS)
#define uartUser_INTR_SLAVE_I2C_GENERAL              ((uint32) 0x01u << \
                                                                    uartUser_INTR_SLAVE_I2C_GENERAL_POS)
#define uartUser_INTR_SLAVE_I2C_BUS_ERROR            ((uint32) 0x01u << \
                                                                    uartUser_INTR_SLAVE_I2C_BUS_ERROR_POS)
#define uartUser_INTR_SLAVE_SPI_EZBUF_WRITE_STOP     ((uint32) 0x01u << \
                                                                   uartUser_INTR_SLAVE_SPI_EZBUF_WRITE_STOP_POS)
#define uartUser_INTR_SLAVE_SPI_EZBUF_STOP           ((uint32) 0x01u << \
                                                                    uartUser_INTR_SLAVE_SPI_EZBUF_STOP_POS)
#define uartUser_INTR_SLAVE_SPI_BUS_ERROR           ((uint32) 0x01u << \
                                                                    uartUser_INTR_SLAVE_SPI_BUS_ERROR_POS)

/*
* uartUser_INTR_TX, uartUser_INTR_TX_SET,
* uartUser_INTR_TX_MASK, uartUser_INTR_TX_MASKED
*/
#define uartUser_INTR_TX_TRIGGER_POS        (0u)  /* [0]  Trigger on TX FIFO entires                       */
#define uartUser_INTR_TX_NOT_FULL_POS       (1u)  /* [1]  TX FIFO is not full                              */
#define uartUser_INTR_TX_EMPTY_POS          (4u)  /* [4]  TX FIFO is empty                                 */
#define uartUser_INTR_TX_OVERFLOW_POS       (5u)  /* [5]  Attempt to write to a full TX FIFO               */
#define uartUser_INTR_TX_UNDERFLOW_POS      (6u)  /* [6]  Attempt to read from an empty TX FIFO            */
#define uartUser_INTR_TX_BLOCKED_POS        (7u)  /* [7]  No access to the EZ memory                       */
#define uartUser_INTR_TX_UART_NACK_POS      (8u)  /* [8]  UART transmitter received a NACK: SmartCard mode */
#define uartUser_INTR_TX_UART_DONE_POS      (9u)  /* [9]  UART transmitter done even                       */
#define uartUser_INTR_TX_UART_ARB_LOST_POS  (10u) /* [10] UART lost arbitration: LIN or SmartCard          */
#define uartUser_INTR_TX_TRIGGER            ((uint32) 0x01u)
#define uartUser_INTR_TX_FIFO_LEVEL         (uartUser_INTR_TX_TRIGGER)
#define uartUser_INTR_TX_NOT_FULL           ((uint32) 0x01u << uartUser_INTR_TX_NOT_FULL_POS)
#define uartUser_INTR_TX_EMPTY              ((uint32) 0x01u << uartUser_INTR_TX_EMPTY_POS)
#define uartUser_INTR_TX_OVERFLOW           ((uint32) 0x01u << uartUser_INTR_TX_OVERFLOW_POS)
#define uartUser_INTR_TX_UNDERFLOW          ((uint32) 0x01u << uartUser_INTR_TX_UNDERFLOW_POS)
#define uartUser_INTR_TX_BLOCKED            ((uint32) 0x01u << uartUser_INTR_TX_BLOCKED_POS)
#define uartUser_INTR_TX_UART_NACK          ((uint32) 0x01u << uartUser_INTR_TX_UART_NACK_POS)
#define uartUser_INTR_TX_UART_DONE          ((uint32) 0x01u << uartUser_INTR_TX_UART_DONE_POS)
#define uartUser_INTR_TX_UART_ARB_LOST      ((uint32) 0x01u << uartUser_INTR_TX_UART_ARB_LOST_POS)

/*
* uartUser_INTR_RX, uartUser_INTR_RX_SET,
* uartUser_INTR_RX_MASK, uartUser_INTR_RX_MASKED
*/
#define uartUser_INTR_RX_TRIGGER_POS        (0u)   /* [0]  Trigger on RX FIFO entires            */
#define uartUser_INTR_RX_NOT_EMPTY_POS      (2u)   /* [2]  RX FIFO is not empty                  */
#define uartUser_INTR_RX_FULL_POS           (3u)   /* [3]  RX FIFO is full                       */
#define uartUser_INTR_RX_OVERFLOW_POS       (5u)   /* [5]  Attempt to write to a full RX FIFO    */
#define uartUser_INTR_RX_UNDERFLOW_POS      (6u)   /* [6]  Attempt to read from an empty RX FIFO */
#define uartUser_INTR_RX_BLOCKED_POS        (7u)   /* [7]  No access to the EZ memory            */
#define uartUser_INTR_RX_FRAME_ERROR_POS    (8u)   /* [8]  Frame error in received data frame    */
#define uartUser_INTR_RX_PARITY_ERROR_POS   (9u)   /* [9]  Parity error in received data frame   */
#define uartUser_INTR_RX_BAUD_DETECT_POS    (10u)  /* [10] LIN baud rate detection is completed   */
#define uartUser_INTR_RX_BREAK_DETECT_POS   (11u)  /* [11] Break detection is successful         */
#define uartUser_INTR_RX_TRIGGER            ((uint32) 0x01u)
#define uartUser_INTR_RX_FIFO_LEVEL         (uartUser_INTR_RX_TRIGGER)
#define uartUser_INTR_RX_NOT_EMPTY          ((uint32) 0x01u << uartUser_INTR_RX_NOT_EMPTY_POS)
#define uartUser_INTR_RX_FULL               ((uint32) 0x01u << uartUser_INTR_RX_FULL_POS)
#define uartUser_INTR_RX_OVERFLOW           ((uint32) 0x01u << uartUser_INTR_RX_OVERFLOW_POS)
#define uartUser_INTR_RX_UNDERFLOW          ((uint32) 0x01u << uartUser_INTR_RX_UNDERFLOW_POS)
#define uartUser_INTR_RX_BLOCKED            ((uint32) 0x01u << uartUser_INTR_RX_BLOCKED_POS)
#define uartUser_INTR_RX_FRAME_ERROR        ((uint32) 0x01u << uartUser_INTR_RX_FRAME_ERROR_POS)
#define uartUser_INTR_RX_PARITY_ERROR       ((uint32) 0x01u << uartUser_INTR_RX_PARITY_ERROR_POS)
#define uartUser_INTR_RX_BAUD_DETECT        ((uint32) 0x01u << uartUser_INTR_RX_BAUD_DETECT_POS)
#define uartUser_INTR_RX_BREAK_DETECT       ((uint32) 0x01u << uartUser_INTR_RX_BREAK_DETECT_POS)

/* Define all interrupt sources */
#define uartUser_INTR_I2C_EC_ALL    (uartUser_INTR_I2C_EC_WAKE_UP    | \
                                             uartUser_INTR_I2C_EC_EZBUF_STOP | \
                                             uartUser_INTR_I2C_EC_EZBUF_WRITE_STOP)

#define uartUser_INTR_SPI_EC_ALL    (uartUser_INTR_SPI_EC_WAKE_UP    | \
                                             uartUser_INTR_SPI_EC_EZBUF_STOP | \
                                             uartUser_INTR_SPI_EC_EZBUF_WRITE_STOP)

#define uartUser_INTR_MASTER_ALL    (uartUser_INTR_MASTER_I2C_ARB_LOST  | \
                                             uartUser_INTR_MASTER_I2C_NACK      | \
                                             uartUser_INTR_MASTER_I2C_ACK       | \
                                             uartUser_INTR_MASTER_I2C_STOP      | \
                                             uartUser_INTR_MASTER_I2C_BUS_ERROR | \
                                             uartUser_INTR_MASTER_SPI_DONE)

#define uartUser_INTR_SLAVE_ALL     (uartUser_INTR_SLAVE_I2C_ARB_LOST      | \
                                             uartUser_INTR_SLAVE_I2C_NACK          | \
                                             uartUser_INTR_SLAVE_I2C_ACK           | \
                                             uartUser_INTR_SLAVE_I2C_WRITE_STOP    | \
                                             uartUser_INTR_SLAVE_I2C_STOP          | \
                                             uartUser_INTR_SLAVE_I2C_START         | \
                                             uartUser_INTR_SLAVE_I2C_ADDR_MATCH    | \
                                             uartUser_INTR_SLAVE_I2C_GENERAL       | \
                                             uartUser_INTR_SLAVE_I2C_BUS_ERROR     | \
                                             uartUser_INTR_SLAVE_SPI_EZBUF_WRITE_STOP | \
                                             uartUser_INTR_SLAVE_SPI_EZBUF_STOP       | \
                                             uartUser_INTR_SLAVE_SPI_BUS_ERROR)

#define uartUser_INTR_TX_ALL        (uartUser_INTR_TX_TRIGGER   | \
                                             uartUser_INTR_TX_NOT_FULL  | \
                                             uartUser_INTR_TX_EMPTY     | \
                                             uartUser_INTR_TX_OVERFLOW  | \
                                             uartUser_INTR_TX_UNDERFLOW | \
                                             uartUser_INTR_TX_BLOCKED   | \
                                             uartUser_INTR_TX_UART_NACK | \
                                             uartUser_INTR_TX_UART_DONE | \
                                             uartUser_INTR_TX_UART_ARB_LOST)

#define uartUser_INTR_RX_ALL        (uartUser_INTR_RX_TRIGGER      | \
                                             uartUser_INTR_RX_NOT_EMPTY    | \
                                             uartUser_INTR_RX_FULL         | \
                                             uartUser_INTR_RX_OVERFLOW     | \
                                             uartUser_INTR_RX_UNDERFLOW    | \
                                             uartUser_INTR_RX_BLOCKED      | \
                                             uartUser_INTR_RX_FRAME_ERROR  | \
                                             uartUser_INTR_RX_PARITY_ERROR | \
                                             uartUser_INTR_RX_BAUD_DETECT  | \
                                             uartUser_INTR_RX_BREAK_DETECT)

/* I2C and EZI2C slave address defines */
#define uartUser_I2C_SLAVE_ADDR_POS    (0x01u)    /* 7-bit address shift */
#define uartUser_I2C_SLAVE_ADDR_MASK   (0xFEu)    /* 8-bit address mask */

/* OVS constants for IrDA Low Power operation */
#define uartUser_CTRL_OVS_IRDA_LP_OVS16     (0x00u)
#define uartUser_CTRL_OVS_IRDA_LP_OVS32     (0x01u)
#define uartUser_CTRL_OVS_IRDA_LP_OVS48     (0x02u)
#define uartUser_CTRL_OVS_IRDA_LP_OVS96     (0x03u)
#define uartUser_CTRL_OVS_IRDA_LP_OVS192    (0x04u)
#define uartUser_CTRL_OVS_IRDA_LP_OVS768    (0x05u)
#define uartUser_CTRL_OVS_IRDA_LP_OVS1536   (0x06u)

/* OVS constant for IrDA */
#define uartUser_CTRL_OVS_IRDA_OVS16        (uartUser_UART_IRDA_LP_OVS16)


/***************************************
*    Common Macro Definitions
***************************************/

/* Re-enables the SCB IP. A clear enable bit has a different effect
* on the scb IP depending on the version:
*  CY_SCBIP_V0: resets state, status, TX and RX FIFOs.
*  CY_SCBIP_V1 or later: resets state, status, TX and RX FIFOs and interrupt sources.
* Clear I2C command registers are because they are not impacted by re-enable.
*/
#define uartUser_SCB_SW_RESET   uartUser_I2CFwBlockReset()

/* TX FIFO macro */
#define uartUser_CLEAR_TX_FIFO \
                            do{        \
                                uartUser_TX_FIFO_CTRL_REG |= ((uint32)  uartUser_TX_FIFO_CTRL_CLEAR); \
                                uartUser_TX_FIFO_CTRL_REG &= ((uint32) ~uartUser_TX_FIFO_CTRL_CLEAR); \
                            }while(0)

#define uartUser_GET_TX_FIFO_ENTRIES    (uartUser_TX_FIFO_STATUS_REG & \
                                                 uartUser_TX_FIFO_STATUS_USED_MASK)

#define uartUser_GET_TX_FIFO_SR_VALID   ((0u != (uartUser_TX_FIFO_STATUS_REG & \
                                                         uartUser_TX_FIFO_SR_VALID)) ? (1u) : (0u))

/* RX FIFO macro */
#define uartUser_CLEAR_RX_FIFO \
                            do{        \
                                uartUser_RX_FIFO_CTRL_REG |= ((uint32)  uartUser_RX_FIFO_CTRL_CLEAR); \
                                uartUser_RX_FIFO_CTRL_REG &= ((uint32) ~uartUser_RX_FIFO_CTRL_CLEAR); \
                            }while(0)

#define uartUser_GET_RX_FIFO_ENTRIES    (uartUser_RX_FIFO_STATUS_REG & \
                                                    uartUser_RX_FIFO_STATUS_USED_MASK)

#define uartUser_GET_RX_FIFO_SR_VALID   ((0u != (uartUser_RX_FIFO_STATUS_REG & \
                                                         uartUser_RX_FIFO_SR_VALID)) ? (1u) : (0u))

/* Write interrupt source: set sourceMask bits in uartUser_INTR_X_MASK_REG */
#define uartUser_WRITE_INTR_I2C_EC_MASK(sourceMask) \
                                                do{         \
                                                    uartUser_INTR_I2C_EC_MASK_REG = (uint32) (sourceMask); \
                                                }while(0)

#if (!uartUser_CY_SCBIP_V1)
    #define uartUser_WRITE_INTR_SPI_EC_MASK(sourceMask) \
                                                do{         \
                                                    uartUser_INTR_SPI_EC_MASK_REG = (uint32) (sourceMask); \
                                                }while(0)
#endif /* (!uartUser_CY_SCBIP_V1) */

#define uartUser_WRITE_INTR_MASTER_MASK(sourceMask) \
                                                do{         \
                                                    uartUser_INTR_MASTER_MASK_REG = (uint32) (sourceMask); \
                                                }while(0)

#define uartUser_WRITE_INTR_SLAVE_MASK(sourceMask)  \
                                                do{         \
                                                    uartUser_INTR_SLAVE_MASK_REG = (uint32) (sourceMask); \
                                                }while(0)

#define uartUser_WRITE_INTR_TX_MASK(sourceMask)     \
                                                do{         \
                                                    uartUser_INTR_TX_MASK_REG = (uint32) (sourceMask); \
                                                }while(0)

#define uartUser_WRITE_INTR_RX_MASK(sourceMask)     \
                                                do{         \
                                                    uartUser_INTR_RX_MASK_REG = (uint32) (sourceMask); \
                                                }while(0)

/* Enable interrupt source: set sourceMask bits in uartUser_INTR_X_MASK_REG */
#define uartUser_ENABLE_INTR_I2C_EC(sourceMask) \
                                                do{     \
                                                    uartUser_INTR_I2C_EC_MASK_REG |= (uint32) (sourceMask); \
                                                }while(0)
#if (!uartUser_CY_SCBIP_V1)
    #define uartUser_ENABLE_INTR_SPI_EC(sourceMask) \
                                                do{     \
                                                    uartUser_INTR_SPI_EC_MASK_REG |= (uint32) (sourceMask); \
                                                }while(0)
#endif /* (!uartUser_CY_SCBIP_V1) */

#define uartUser_ENABLE_INTR_MASTER(sourceMask) \
                                                do{     \
                                                    uartUser_INTR_MASTER_MASK_REG |= (uint32) (sourceMask); \
                                                }while(0)

#define uartUser_ENABLE_INTR_SLAVE(sourceMask)  \
                                                do{     \
                                                    uartUser_INTR_SLAVE_MASK_REG |= (uint32) (sourceMask); \
                                                }while(0)

#define uartUser_ENABLE_INTR_TX(sourceMask)     \
                                                do{     \
                                                    uartUser_INTR_TX_MASK_REG |= (uint32) (sourceMask); \
                                                }while(0)

#define uartUser_ENABLE_INTR_RX(sourceMask)     \
                                                do{     \
                                                    uartUser_INTR_RX_MASK_REG |= (uint32) (sourceMask); \
                                                }while(0)

/* Disable interrupt source: clear sourceMask bits in uartUser_INTR_X_MASK_REG */
#define uartUser_DISABLE_INTR_I2C_EC(sourceMask) \
                                do{                      \
                                    uartUser_INTR_I2C_EC_MASK_REG &= ((uint32) ~((uint32) (sourceMask))); \
                                }while(0)

#if (!uartUser_CY_SCBIP_V1)
    #define uartUser_DISABLE_INTR_SPI_EC(sourceMask) \
                                do{                      \
                                    uartUser_INTR_SPI_EC_MASK_REG &= ((uint32) ~((uint32) (sourceMask))); \
                                 }while(0)
#endif /* (!uartUser_CY_SCBIP_V1) */

#define uartUser_DISABLE_INTR_MASTER(sourceMask) \
                                do{                      \
                                uartUser_INTR_MASTER_MASK_REG &= ((uint32) ~((uint32) (sourceMask))); \
                                }while(0)

#define uartUser_DISABLE_INTR_SLAVE(sourceMask) \
                                do{                     \
                                    uartUser_INTR_SLAVE_MASK_REG &= ((uint32) ~((uint32) (sourceMask))); \
                                }while(0)

#define uartUser_DISABLE_INTR_TX(sourceMask)    \
                                do{                     \
                                    uartUser_INTR_TX_MASK_REG &= ((uint32) ~((uint32) (sourceMask))); \
                                 }while(0)

#define uartUser_DISABLE_INTR_RX(sourceMask)    \
                                do{                     \
                                    uartUser_INTR_RX_MASK_REG &= ((uint32) ~((uint32) (sourceMask))); \
                                }while(0)

/* Set interrupt sources: write sourceMask bits in uartUser_INTR_X_SET_REG */
#define uartUser_SET_INTR_MASTER(sourceMask)    \
                                                do{     \
                                                    uartUser_INTR_MASTER_SET_REG = (uint32) (sourceMask); \
                                                }while(0)

#define uartUser_SET_INTR_SLAVE(sourceMask) \
                                                do{ \
                                                    uartUser_INTR_SLAVE_SET_REG = (uint32) (sourceMask); \
                                                }while(0)

#define uartUser_SET_INTR_TX(sourceMask)    \
                                                do{ \
                                                    uartUser_INTR_TX_SET_REG = (uint32) (sourceMask); \
                                                }while(0)

#define uartUser_SET_INTR_RX(sourceMask)    \
                                                do{ \
                                                    uartUser_INTR_RX_SET_REG = (uint32) (sourceMask); \
                                                }while(0)

/* Clear interrupt sources: write sourceMask bits in uartUser_INTR_X_REG */
#define uartUser_CLEAR_INTR_I2C_EC(sourceMask)  \
                                                do{     \
                                                    uartUser_INTR_I2C_EC_REG = (uint32) (sourceMask); \
                                                }while(0)

#if (!uartUser_CY_SCBIP_V1)
    #define uartUser_CLEAR_INTR_SPI_EC(sourceMask)  \
                                                do{     \
                                                    uartUser_INTR_SPI_EC_REG = (uint32) (sourceMask); \
                                                }while(0)
#endif /* (!uartUser_CY_SCBIP_V1) */

#define uartUser_CLEAR_INTR_MASTER(sourceMask)  \
                                                do{     \
                                                    uartUser_INTR_MASTER_REG = (uint32) (sourceMask); \
                                                }while(0)

#define uartUser_CLEAR_INTR_SLAVE(sourceMask)   \
                                                do{     \
                                                    uartUser_INTR_SLAVE_REG  = (uint32) (sourceMask); \
                                                }while(0)

#define uartUser_CLEAR_INTR_TX(sourceMask)      \
                                                do{     \
                                                    uartUser_INTR_TX_REG     = (uint32) (sourceMask); \
                                                }while(0)

#define uartUser_CLEAR_INTR_RX(sourceMask)      \
                                                do{     \
                                                    uartUser_INTR_RX_REG     = (uint32) (sourceMask); \
                                                }while(0)

/* Return true if sourceMask is set in uartUser_INTR_CAUSE_REG */
#define uartUser_CHECK_CAUSE_INTR(sourceMask)    (0u != (uartUser_INTR_CAUSE_REG & (sourceMask)))

/* Return true if sourceMask is set in INTR_X_MASKED_REG */
#define uartUser_CHECK_INTR_I2C_EC(sourceMask)  (0u != (uartUser_INTR_I2C_EC_REG & (sourceMask)))
#if (!uartUser_CY_SCBIP_V1)
    #define uartUser_CHECK_INTR_SPI_EC(sourceMask)  (0u != (uartUser_INTR_SPI_EC_REG & (sourceMask)))
#endif /* (!uartUser_CY_SCBIP_V1) */
#define uartUser_CHECK_INTR_MASTER(sourceMask)  (0u != (uartUser_INTR_MASTER_REG & (sourceMask)))
#define uartUser_CHECK_INTR_SLAVE(sourceMask)   (0u != (uartUser_INTR_SLAVE_REG  & (sourceMask)))
#define uartUser_CHECK_INTR_TX(sourceMask)      (0u != (uartUser_INTR_TX_REG     & (sourceMask)))
#define uartUser_CHECK_INTR_RX(sourceMask)      (0u != (uartUser_INTR_RX_REG     & (sourceMask)))

/* Return true if sourceMask is set in uartUser_INTR_X_MASKED_REG */
#define uartUser_CHECK_INTR_I2C_EC_MASKED(sourceMask)   (0u != (uartUser_INTR_I2C_EC_MASKED_REG & \
                                                                       (sourceMask)))
#if (!uartUser_CY_SCBIP_V1)
    #define uartUser_CHECK_INTR_SPI_EC_MASKED(sourceMask)   (0u != (uartUser_INTR_SPI_EC_MASKED_REG & \
                                                                       (sourceMask)))
#endif /* (!uartUser_CY_SCBIP_V1) */
#define uartUser_CHECK_INTR_MASTER_MASKED(sourceMask)   (0u != (uartUser_INTR_MASTER_MASKED_REG & \
                                                                       (sourceMask)))
#define uartUser_CHECK_INTR_SLAVE_MASKED(sourceMask)    (0u != (uartUser_INTR_SLAVE_MASKED_REG  & \
                                                                       (sourceMask)))
#define uartUser_CHECK_INTR_TX_MASKED(sourceMask)       (0u != (uartUser_INTR_TX_MASKED_REG     & \
                                                                       (sourceMask)))
#define uartUser_CHECK_INTR_RX_MASKED(sourceMask)       (0u != (uartUser_INTR_RX_MASKED_REG     & \
                                                                       (sourceMask)))

/* Return true if sourceMask is set in uartUser_CTRL_REG: generally is used to check enable bit */
#define uartUser_GET_CTRL_ENABLED    (0u != (uartUser_CTRL_REG & uartUser_CTRL_ENABLED))

#define uartUser_CHECK_SLAVE_AUTO_ADDR_NACK     (0u != (uartUser_I2C_CTRL_REG & \
                                                                uartUser_I2C_CTRL_S_NOT_READY_DATA_NACK))


/***************************************
*      I2C Macro Definitions
***************************************/

/* Enable auto ACK/NACK */
#define uartUser_ENABLE_SLAVE_AUTO_ADDR_NACK \
                            do{                      \
                                uartUser_I2C_CTRL_REG |= uartUser_I2C_CTRL_S_NOT_READY_DATA_NACK; \
                            }while(0)

#define uartUser_ENABLE_SLAVE_AUTO_DATA_ACK \
                            do{                     \
                                uartUser_I2C_CTRL_REG |= uartUser_I2C_CTRL_S_READY_DATA_ACK; \
                            }while(0)

#define uartUser_ENABLE_SLAVE_AUTO_DATA_NACK \
                            do{                      \
                                uartUser_I2C_CTRL_REG |= uartUser_I2C_CTRL_S_NOT_READY_DATA_NACK; \
                            }while(0)

#define uartUser_ENABLE_MASTER_AUTO_DATA_ACK \
                            do{                      \
                                uartUser_I2C_CTRL_REG |= uartUser_I2C_CTRL_M_READY_DATA_ACK; \
                            }while(0)

#define uartUser_ENABLE_MASTER_AUTO_DATA_NACK \
                            do{                       \
                                uartUser_I2C_CTRL_REG |= uartUser_I2C_CTRL_M_NOT_READY_DATA_NACK; \
                            }while(0)

/* Disable auto ACK/NACK */
#define uartUser_DISABLE_SLAVE_AUTO_ADDR_NACK \
                            do{                       \
                                uartUser_I2C_CTRL_REG &= ~uartUser_I2C_CTRL_S_NOT_READY_DATA_NACK; \
                            }while(0)

#define uartUser_DISABLE_SLAVE_AUTO_DATA_ACK \
                            do{                      \
                                uartUser_I2C_CTRL_REG &= ~uartUser_I2C_CTRL_S_READY_DATA_ACK; \
                            }while(0)

#define uartUser_DISABLE_SLAVE_AUTO_DATA_NACK \
                            do{                       \
                                uartUser_I2C_CTRL_REG &= ~uartUser_I2C_CTRL_S_NOT_READY_DATA_NACK; \
                            }while(0)

#define uartUser_DISABLE_MASTER_AUTO_DATA_ACK \
                            do{                       \
                                uartUser_I2C_CTRL_REG &= ~uartUser_I2C_CTRL_M_READY_DATA_ACK; \
                            }while(0)

#define uartUser_DISABLE_MASTER_AUTO_DATA_NACK \
                            do{                        \
                                uartUser_I2C_CTRL_REG &= ~uartUser_I2C_CTRL_M_NOT_READY_DATA_NACK; \
                            }while(0)

/* Enable Slave autoACK/NACK Data */
#define uartUser_ENABLE_SLAVE_AUTO_DATA \
                            do{                 \
                                uartUser_I2C_CTRL_REG |= (uartUser_I2C_CTRL_S_READY_DATA_ACK |      \
                                                                  uartUser_I2C_CTRL_S_NOT_READY_DATA_NACK); \
                            }while(0)

/* Disable Slave autoACK/NACK Data */
#define uartUser_DISABLE_SLAVE_AUTO_DATA \
                            do{                  \
                                uartUser_I2C_CTRL_REG &= ((uint32) \
                                                                  ~(uartUser_I2C_CTRL_S_READY_DATA_ACK |       \
                                                                    uartUser_I2C_CTRL_S_NOT_READY_DATA_NACK)); \
                            }while(0)

/* Disable Master autoACK/NACK Data */
#define uartUser_DISABLE_MASTER_AUTO_DATA \
                            do{                   \
                                uartUser_I2C_CTRL_REG &= ((uint32) \
                                                                  ~(uartUser_I2C_CTRL_M_READY_DATA_ACK |       \
                                                                    uartUser_I2C_CTRL_M_NOT_READY_DATA_NACK)); \
                            }while(0)
/* Disables auto data ACK/NACK bits */
#define uartUser_DISABLE_AUTO_DATA \
                do{                        \
                    uartUser_I2C_CTRL_REG &= ((uint32) ~(uartUser_I2C_CTRL_M_READY_DATA_ACK      |  \
                                                                 uartUser_I2C_CTRL_M_NOT_READY_DATA_NACK |  \
                                                                 uartUser_I2C_CTRL_S_READY_DATA_ACK      |  \
                                                                 uartUser_I2C_CTRL_S_NOT_READY_DATA_NACK)); \
                }while(0)

/* Master commands */
#define uartUser_I2C_MASTER_GENERATE_START \
                            do{                    \
                                uartUser_I2C_MASTER_CMD_REG = uartUser_I2C_MASTER_CMD_M_START_ON_IDLE; \
                            }while(0)

#define uartUser_I2C_MASTER_CLEAR_START \
                            do{                 \
                                uartUser_I2C_MASTER_CMD_REG =  ((uint32) 0u); \
                            }while(0)

#define uartUser_I2C_MASTER_GENERATE_RESTART uartUser_I2CReStartGeneration()

#define uartUser_I2C_MASTER_GENERATE_STOP \
                            do{                   \
                                uartUser_I2C_MASTER_CMD_REG =                                            \
                                    (uartUser_I2C_MASTER_CMD_M_STOP |                                    \
                                        (uartUser_CHECK_I2C_STATUS(uartUser_I2C_STATUS_M_READ) ? \
                                            (uartUser_I2C_MASTER_CMD_M_NACK) : (0u)));                   \
                            }while(0)

#define uartUser_I2C_MASTER_GENERATE_ACK \
                            do{                  \
                                uartUser_I2C_MASTER_CMD_REG = uartUser_I2C_MASTER_CMD_M_ACK; \
                            }while(0)

#define uartUser_I2C_MASTER_GENERATE_NACK \
                            do{                   \
                                uartUser_I2C_MASTER_CMD_REG = uartUser_I2C_MASTER_CMD_M_NACK; \
                            }while(0)

/* Slave commands */
#define uartUser_I2C_SLAVE_GENERATE_ACK \
                            do{                 \
                                uartUser_I2C_SLAVE_CMD_REG = uartUser_I2C_SLAVE_CMD_S_ACK; \
                            }while(0)

#if (uartUser_CY_SCBIP_V0 || uartUser_CY_SCBIP_V1)
    /* Slave NACK generation for EC_AM logic on address phase. Ticket ID #183902 */
    void uartUser_I2CSlaveNackGeneration(void);
    #define uartUser_I2C_SLAVE_GENERATE_NACK uartUser_I2CSlaveNackGeneration()

#else
    #define uartUser_I2C_SLAVE_GENERATE_NACK \
                            do{                      \
                                uartUser_I2C_SLAVE_CMD_REG = uartUser_I2C_SLAVE_CMD_S_NACK; \
                            }while(0)
#endif /* (uartUser_CY_SCBIP_V0 || uartUser_CY_SCBIP_V1) */

#define uartUser_I2C_SLAVE_CLEAR_NACK \
                            do{               \
                                uartUser_I2C_SLAVE_CMD_REG = 0u; \
                            }while(0)

/* Return 8-bit address. The input address should be 7-bits */
#define uartUser_GET_I2C_8BIT_ADDRESS(addr) (((uint32) ((uint32) (addr) << \
                                                                    uartUser_I2C_SLAVE_ADDR_POS)) & \
                                                                        uartUser_I2C_SLAVE_ADDR_MASK)

#define uartUser_GET_I2C_7BIT_ADDRESS(addr) ((uint32) (addr) >> uartUser_I2C_SLAVE_ADDR_POS)

/* Adjust SDA filter Trim settings */
#define uartUser_DEFAULT_I2C_CFG_SDA_FILT_TRIM  (0x02u)
#define uartUser_EC_AM_I2C_CFG_SDA_FILT_TRIM    (0x03u)

#if (uartUser_CY_SCBIP_V0)
    #define uartUser_SET_I2C_CFG_SDA_FILT_TRIM(sdaTrim) \
        do{                                                 \
            uartUser_I2C_CFG_REG =                  \
                            ((uartUser_I2C_CFG_REG & (uint32) ~uartUser_I2C_CFG_SDA_FILT_TRIM_MASK) | \
                             ((uint32) ((uint32) (sdaTrim) <<uartUser_I2C_CFG_SDA_FILT_TRIM_POS)));           \
        }while(0)
#endif /* (uartUser_CY_SCBIP_V0) */

/* Enable/Disable analog and digital filter */
#define uartUser_DIGITAL_FILTER_DISABLE    (0u)
#define uartUser_DIGITAL_FILTER_ENABLE     (1u)
#define uartUser_I2C_DATA_RATE_FS_MODE_MAX (400u)
#if (uartUser_CY_SCBIP_V0)
    /* uartUser_I2C_CFG_SDA_FILT_OUT_ENABLED is disabled by default */
    #define uartUser_I2C_CFG_FILT_MASK  (uartUser_I2C_CFG_SDA_FILT_ENABLED | \
                                                 uartUser_I2C_CFG_SCL_FILT_ENABLED)
#else
    /* uartUser_I2C_CFG_SDA_OUT_FILT_SEL_MASK is disabled by default */
    #define uartUser_I2C_CFG_FILT_MASK  (uartUser_I2C_CFG_SDA_IN_FILT_SEL | \
                                                 uartUser_I2C_CFG_SCL_IN_FILT_SEL)
#endif /* (uartUser_CY_SCBIP_V0) */

#define uartUser_I2C_CFG_ANALOG_FITER_DISABLE \
        do{                                           \
            uartUser_I2C_CFG_REG &= (uint32) ~uartUser_I2C_CFG_FILT_MASK; \
        }while(0)

#define uartUser_I2C_CFG_ANALOG_FITER_ENABLE \
        do{                                          \
            uartUser_I2C_CFG_REG |= (uint32)  uartUser_I2C_CFG_FILT_MASK; \
        }while(0)

/* Return slave select number from SPI_CTRL register */
#define uartUser_GET_SPI_CTRL_SS(activeSelect) (((uint32) ((uint32) (activeSelect) << \
                                                                    uartUser_SPI_CTRL_SLAVE_SELECT_POS)) & \
                                                                        uartUser_SPI_CTRL_SLAVE_SELECT_MASK)

/* Return true if bit is set in uartUser_I2C_STATUS_REG */
#define uartUser_CHECK_I2C_STATUS(sourceMask)   (0u != (uartUser_I2C_STATUS_REG & (sourceMask)))

/* Return true if bit is set in uartUser_SPI_STATUS_REG */
#define uartUser_CHECK_SPI_STATUS(sourceMask)   (0u != (uartUser_SPI_STATUS_REG & (sourceMask)))

/* Return FIFO size depends on uartUser_CTRL_BYTE_MODE bit */
#define uartUser_GET_FIFO_SIZE(condition) ((0u != (condition)) ? \
                                                    (2u * uartUser_FIFO_SIZE) : (uartUser_FIFO_SIZE))


/***************************************
*       Get Macros Definitions
***************************************/

/* uartUser_CTRL */
#define uartUser_GET_CTRL_OVS(oversample)       (((uint32) (oversample) - 1u) & uartUser_CTRL_OVS_MASK)

#define uartUser_GET_CTRL_EC_OP_MODE(opMode)        ((0u != (opMode)) ? \
                                                                (uartUser_CTRL_EC_OP_MODE)  : (0u))

#define uartUser_GET_CTRL_EC_AM_MODE(amMode)        ((0u != (amMode)) ? \
                                                                (uartUser_CTRL_EC_AM_MODE)  : (0u))

#define uartUser_GET_CTRL_BLOCK(block)              ((0u != (block))  ? \
                                                                (uartUser_CTRL_BLOCK)       : (0u))

#define uartUser_GET_CTRL_ADDR_ACCEPT(acceptAddr)   ((0u != (acceptAddr)) ? \
                                                                (uartUser_CTRL_ADDR_ACCEPT) : (0u))

#if (uartUser_CY_SCBIP_V0 || uartUser_CY_SCBIP_V1)
    #define uartUser_GET_CTRL_BYTE_MODE(mode)   (0u)
#else
    #define uartUser_GET_CTRL_BYTE_MODE(mode)   ((0u != (mode)) ? \
                                                            (uartUser_CTRL_BYTE_MODE) : (0u))
#endif /* (uartUser_CY_SCBIP_V0 || uartUser_CY_SCBIP_V1) */

/* uartUser_I2C_CTRL */
#define uartUser_GET_I2C_CTRL_HIGH_PHASE_OVS(oversampleHigh) (((uint32) (oversampleHigh) - 1u) & \
                                                                        uartUser_I2C_CTRL_HIGH_PHASE_OVS_MASK)

#define uartUser_GET_I2C_CTRL_LOW_PHASE_OVS(oversampleLow)  ((((uint32) (oversampleLow) - 1u) << \
                                                                    uartUser_I2C_CTRL_LOW_PHASE_OVS_POS) &  \
                                                                    uartUser_I2C_CTRL_LOW_PHASE_OVS_MASK)

#define uartUser_GET_I2C_CTRL_S_NOT_READY_ADDR_NACK(wakeNack) ((0u != (wakeNack)) ? \
                                                            (uartUser_I2C_CTRL_S_NOT_READY_ADDR_NACK) : (0u))

#define uartUser_GET_I2C_CTRL_S_GENERAL_IGNORE(genCall) ((0u != (genCall)) ? \
                                                                    (uartUser_I2C_CTRL_S_GENERAL_IGNORE) : (0u))

#define uartUser_GET_I2C_CTRL_SL_MSTR_MODE(mode)    ((uint32)(mode) << uartUser_I2C_CTRL_SLAVE_MODE_POS)

/* uartUser_SPI_CTRL */
#define uartUser_GET_SPI_CTRL_CONTINUOUS(separate)  ((0u != (separate)) ? \
                                                                (uartUser_SPI_CTRL_CONTINUOUS) : (0u))

#define uartUser_GET_SPI_CTRL_SELECT_PRECEDE(mode)  ((0u != (mode)) ? \
                                                                      (uartUser_SPI_CTRL_SELECT_PRECEDE) : (0u))

#define uartUser_GET_SPI_CTRL_SCLK_MODE(mode)       (((uint32) (mode) << \
                                                                        uartUser_SPI_CTRL_CPHA_POS) & \
                                                                        uartUser_SPI_CTRL_SCLK_MODE_MASK)

#define uartUser_GET_SPI_CTRL_LATE_MISO_SAMPLE(lateMiso) ((0u != (lateMiso)) ? \
                                                                    (uartUser_SPI_CTRL_LATE_MISO_SAMPLE) : (0u))

#if (uartUser_CY_SCBIP_V0 || uartUser_CY_SCBIP_V1)
    #define uartUser_GET_SPI_CTRL_SCLK_CONTINUOUS(sclkType) (0u)
    #define uartUser_GET_SPI_CTRL_SSEL_POLARITY(polarity)   (0u)
#else
    #define uartUser_GET_SPI_CTRL_SCLK_CONTINUOUS(sclkType) ((0u != (sclkType)) ? \
                                                                    (uartUser_SPI_CTRL_SCLK_CONTINUOUS) : (0u))

    #define uartUser_GET_SPI_CTRL_SSEL_POLARITY(polarity)   (((uint32) (polarity) << \
                                                                     uartUser_SPI_CTRL_SSEL0_POLARITY_POS) & \
                                                                     uartUser_SPI_CTRL_SSEL_POLARITY_MASK)
#endif /* ((uartUser_CY_SCBIP_V0 || uartUser_CY_SCBIP_V1) */

#define uartUser_GET_SPI_CTRL_SUB_MODE(mode)        (((uint32) (mode) << uartUser_SPI_CTRL_MODE_POS) & \
                                                                                 uartUser_SPI_CTRL_MODE_MASK)

#define uartUser_GET_SPI_CTRL_SLAVE_SELECT(select)  (((uint32) (select) << \
                                                                      uartUser_SPI_CTRL_SLAVE_SELECT_POS) & \
                                                                      uartUser_SPI_CTRL_SLAVE_SELECT_MASK)

#define uartUser_GET_SPI_CTRL_MASTER_MODE(mode)     ((0u != (mode)) ? \
                                                                (uartUser_SPI_CTRL_MASTER) : (0u))

/* uartUser_UART_CTRL */
#define uartUser_GET_UART_CTRL_MODE(mode)           (((uint32) (mode) << \
                                                                            uartUser_UART_CTRL_MODE_POS) & \
                                                                            uartUser_UART_CTRL_MODE_MASK)

/* uartUser_UART_RX_CTRL */
#define uartUser_GET_UART_RX_CTRL_MODE(stopBits)    (((uint32) (stopBits) - 1u) & \
                                                                        uartUser_UART_RX_CTRL_STOP_BITS_MASK)

#define uartUser_GET_UART_RX_CTRL_PARITY(parity)    ((0u != (parity)) ? \
                                                                    (uartUser_UART_RX_CTRL_PARITY) : (0u))

#define uartUser_GET_UART_RX_CTRL_POLARITY(polarity)    ((0u != (polarity)) ? \
                                                                    (uartUser_UART_RX_CTRL_POLARITY) : (0u))

#define uartUser_GET_UART_RX_CTRL_DROP_ON_PARITY_ERR(dropErr) ((0u != (dropErr)) ? \
                                                        (uartUser_UART_RX_CTRL_DROP_ON_PARITY_ERR) : (0u))

#define uartUser_GET_UART_RX_CTRL_DROP_ON_FRAME_ERR(dropErr) ((0u != (dropErr)) ? \
                                                        (uartUser_UART_RX_CTRL_DROP_ON_FRAME_ERR) : (0u))

#define uartUser_GET_UART_RX_CTRL_MP_MODE(mpMode)   ((0u != (mpMode)) ? \
                                                        (uartUser_UART_RX_CTRL_MP_MODE) : (0u))

#define uartUser_GET_UART_RX_CTRL_BREAK_WIDTH(width)    (((uint32) ((uint32) (width) - 1u) << \
                                                                    uartUser_UART_RX_CTRL_BREAK_WIDTH_POS) & \
                                                                    uartUser_UART_RX_CTRL_BREAK_WIDTH_MASK)

/* uartUser_UART_TX_CTRL */
#define uartUser_GET_UART_TX_CTRL_MODE(stopBits)    (((uint32) (stopBits) - 1u) & \
                                                                uartUser_UART_RX_CTRL_STOP_BITS_MASK)

#define uartUser_GET_UART_TX_CTRL_PARITY(parity)    ((0u != (parity)) ? \
                                                               (uartUser_UART_TX_CTRL_PARITY) : (0u))

#define uartUser_GET_UART_TX_CTRL_RETRY_NACK(nack)  ((0u != (nack)) ? \
                                                               (uartUser_UART_TX_CTRL_RETRY_ON_NACK) : (0u))

/* uartUser_UART_FLOW_CTRL */
#if !(uartUser_CY_SCBIP_V0 || uartUser_CY_SCBIP_V1)
    #define uartUser_GET_UART_FLOW_CTRL_TRIGGER_LEVEL(level)   ( (uint32) (level) & \
                                                                 uartUser_UART_FLOW_CTRL_TRIGGER_LEVEL_MASK)

    #define uartUser_GET_UART_FLOW_CTRL_RTS_POLARITY(polarity) ((0u != (polarity)) ? \
                                                                (uartUser_UART_FLOW_CTRL_RTS_POLARITY) : (0u))

    #define uartUser_GET_UART_FLOW_CTRL_CTS_POLARITY(polarity) ((0u != (polarity)) ? \
                                                                (uartUser_UART_FLOW_CTRL_CTS_POLARITY) : (0u))

    #define uartUser_GET_UART_FLOW_CTRL_CTS_ENABLE(ctsEn)      ((0u != (ctsEn)) ? \
                                                                (uartUser_UART_FLOW_CTRL_CTS_ENABLE) : (0u))
#endif /* !(uartUser_CY_SCBIP_V0 || uartUser_CY_SCBIP_V1) */

/* uartUser_RX_CTRL */
#define uartUser_GET_RX_CTRL_DATA_WIDTH(dataWidth)  (((uint32) (dataWidth) - 1u) & \
                                                                uartUser_RX_CTRL_DATA_WIDTH_MASK)

#define uartUser_GET_RX_CTRL_BIT_ORDER(bitOrder)    ((0u != (bitOrder)) ? \
                                                                (uartUser_RX_CTRL_MSB_FIRST) : (0u))

#define uartUser_GET_RX_CTRL_MEDIAN(filterEn)       ((0u != (filterEn)) ? \
                                                                (uartUser_RX_CTRL_MEDIAN) : (0u))

/* uartUser_RX_MATCH */
#define uartUser_GET_RX_MATCH_ADDR(addr)    ((uint32) (addr) & uartUser_RX_MATCH_ADDR_MASK)
#define uartUser_GET_RX_MATCH_MASK(mask)    (((uint32) (mask) << \
                                                            uartUser_RX_MATCH_MASK_POS) & \
                                                            uartUser_RX_MATCH_MASK_MASK)

/* uartUser_RX_FIFO_CTRL */
#define uartUser_GET_RX_FIFO_CTRL_TRIGGER_LEVEL(level)  ((uint32) (level) & \
                                                                    uartUser_RX_FIFO_CTRL_TRIGGER_LEVEL_MASK)

/* uartUser_TX_CTRL */
#define uartUser_GET_TX_CTRL_DATA_WIDTH(dataWidth)  (((uint32) (dataWidth) - 1u) & \
                                                                uartUser_TX_CTRL_DATA_WIDTH_MASK)

#define uartUser_GET_TX_CTRL_BIT_ORDER(bitOrder)    ((0u != (bitOrder)) ? \
                                                                (uartUser_TX_CTRL_MSB_FIRST) : (0u))

/* uartUser_TX_FIFO_CTRL */
#define uartUser_GET_TX_FIFO_CTRL_TRIGGER_LEVEL(level)  ((uint32) (level) & \
                                                                    uartUser_TX_FIFO_CTRL_TRIGGER_LEVEL_MASK)

/* uartUser_INTR_SLAVE_I2C_GENERAL */
#define uartUser_GET_INTR_SLAVE_I2C_GENERAL(genCall)  ((0u != (genCall)) ? \
                                                                (uartUser_INTR_SLAVE_I2C_GENERAL) : (0u))

/* Return true if master mode is enabled uartUser_SPI_CTRL_REG */
#define uartUser_CHECK_SPI_MASTER   (0u != (uartUser_SPI_CTRL_REG & uartUser_SPI_CTRL_MASTER))

/* Return inactive state of SPI SCLK line depends on CPOL */
#define uartUser_GET_SPI_SCLK_INACTIVE \
            ((0u == (uartUser_SPI_CTRL_REG & uartUser_SPI_CTRL_CPOL)) ? (0u) : (1u))

/* Get output pin inactive state */
#if (uartUser_CY_SCBIP_V0 || uartUser_CY_SCBIP_V1)
#define uartUser_GET_SPI_SS0_INACTIVE       (1u)
#define uartUser_GET_SPI_SS1_INACTIVE       (1u)
#define uartUser_GET_SPI_SS2_INACTIVE       (1u)
#define uartUser_GET_SPI_SS3_INACTIVE       (1u)
#define uartUser_GET_UART_RTS_INACTIVE      (1u)

#else
#define uartUser_GET_SPI_SS0_INACTIVE  \
        ((0u != (uartUser_SPI_CTRL_REG & uartUser_SPI_CTRL_SSEL0_POLARITY)) ? (0u) : (1u))

#define uartUser_GET_SPI_SS1_INACTIVE  \
        ((0u != (uartUser_SPI_CTRL_REG & uartUser_SPI_CTRL_SSEL1_POLARITY)) ? (0u) : (1u))

#define uartUser_GET_SPI_SS2_INACTIVE  \
        ((0u != (uartUser_SPI_CTRL_REG & uartUser_SPI_CTRL_SSEL2_POLARITY)) ? (0u) : (1u))

#define uartUser_GET_SPI_SS3_INACTIVE  \
        ((0u != (uartUser_SPI_CTRL_REG & uartUser_SPI_CTRL_SSEL3_POLARITY)) ? (0u) : (1u))

#define uartUser_GET_UART_RTS_INACTIVE \
        ((0u == (uartUser_UART_FLOW_CTRL_REG & uartUser_UART_FLOW_CTRL_RTS_POLARITY)) ? (0u) : (1u))

#endif /*(uartUser_CY_SCBIP_V0 || uartUser_CY_SCBIP_V1) */

/* Clear register constants for configuration and interrupt mask */
#define uartUser_CLEAR_REG          ((uint32) (0u))
#define uartUser_NO_INTR_SOURCES    ((uint32) (0u))
#define uartUser_DUMMY_PARAM        ((uint32) (0u))
#define uartUser_SUBMODE_SPI_SLAVE  ((uint32) (0u))

/* Return in case of I2C read error */
#define uartUser_I2C_INVALID_BYTE   ((uint32) 0xFFFFFFFFu)
#define uartUser_CHECK_VALID_BYTE   ((uint32) 0x80000000u)


/***************************************
* The following code is DEPRECATED and
* must not be used.
***************************************/

#define uartUser_CHECK_INTR_EC_I2C(sourceMask)  uartUser_CHECK_INTR_I2C_EC(sourceMask)
#if (!uartUser_CY_SCBIP_V1)
    #define uartUser_CHECK_INTR_EC_SPI(sourceMask)  uartUser_CHECK_INTR_SPI_EC(sourceMask)
#endif /* (!uartUser_CY_SCBIP_V1) */

#define uartUser_CY_SCBIP_V1_I2C_ONLY   (uartUser_CY_SCBIP_V1)
#define uartUser_EZBUFFER_SIZE          (uartUser_EZ_DATA_NR)

#define uartUser_EZBUF_DATA00_REG   uartUser_EZBUF_DATA0_REG
#define uartUser_EZBUF_DATA00_PTR   uartUser_EZBUF_DATA0_PTR

#endif /* (CY_SCB_uartUser_H) */


/* [] END OF FILE */
