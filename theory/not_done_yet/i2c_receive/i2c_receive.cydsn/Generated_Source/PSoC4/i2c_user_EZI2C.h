/***************************************************************************//**
* \file i2c_user_EZI2C.h
* \version 4.0
*
* \brief
*  This file provides constants and parameter values for the SCB Component in
*  the EZI2C mode.
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

#if !defined(CY_SCB_EZI2C_i2c_user_H)
#define CY_SCB_EZI2C_i2c_user_H

#include "i2c_user.h"


/***************************************
*   Initial Parameter Constants
****************************************/

#define i2c_user_EZI2C_CLOCK_STRETCHING         (1u)
#define i2c_user_EZI2C_MEDIAN_FILTER_ENABLE     (1u)
#define i2c_user_EZI2C_NUMBER_OF_ADDRESSES      (0u)
#define i2c_user_EZI2C_PRIMARY_SLAVE_ADDRESS    (0x8u)
#define i2c_user_EZI2C_SECONDARY_SLAVE_ADDRESS  (0x9u)
#define i2c_user_EZI2C_SUB_ADDRESS_SIZE         (0u)
#define i2c_user_EZI2C_WAKE_ENABLE              (0u)
#define i2c_user_EZI2C_DATA_RATE                (100u)
#define i2c_user_EZI2C_SLAVE_ADDRESS_MASK       (0xFEu)
#define i2c_user_EZI2C_BYTE_MODE_ENABLE         (0u)


/***************************************
*  Conditional Compilation Parameters
****************************************/

#if(i2c_user_SCB_MODE_UNCONFIG_CONST_CFG)

    #define i2c_user_SUB_ADDRESS_SIZE16             (0u != i2c_user_subAddrSize)
    #define i2c_user_SECONDARY_ADDRESS_ENABLE       (0u != i2c_user_numberOfAddr)

    #define i2c_user_EZI2C_EC_AM_ENABLE         (0u != (i2c_user_CTRL_REG & \
                                                                i2c_user_CTRL_EC_AM_MODE))
    #define i2c_user_EZI2C_SCL_STRETCH_ENABLE   (0u != (i2c_user_GetSlaveInterruptMode() & \
                                                                i2c_user_INTR_SLAVE_I2C_ADDR_MATCH))
    #define i2c_user_EZI2C_SCL_STRETCH_DISABLE       (!i2c_user_EZI2C_SCL_STRETCH_ENABLE)

    #define i2c_user_SECONDARY_ADDRESS_ENABLE_CONST  (1u)
    #define i2c_user_SUB_ADDRESS_SIZE16_CONST        (1u)
    #define i2c_user_EZI2C_SCL_STRETCH_ENABLE_CONST  (1u)
    #define i2c_user_EZI2C_SCL_STRETCH_DISABLE_CONST (1u)
    #define i2c_user_EZI2C_WAKE_ENABLE_CONST         (1u)

    #if (i2c_user_CY_SCBIP_V0 || i2c_user_CY_SCBIP_V1)
        #define i2c_user_EZI2C_FIFO_SIZE    (i2c_user_FIFO_SIZE)
    #else
        #define i2c_user_EZI2C_FIFO_SIZE    (i2c_user_GET_FIFO_SIZE(i2c_user_CTRL_REG & \
                                                                                    i2c_user_CTRL_BYTE_MODE))
    #endif /* (i2c_user_CY_SCBIP_V0 || i2c_user_CY_SCBIP_V1) */

#else

    #define i2c_user_SUB_ADDRESS_SIZE16         (0u != i2c_user_EZI2C_SUB_ADDRESS_SIZE)
    #define i2c_user_SUB_ADDRESS_SIZE16_CONST   (i2c_user_SUB_ADDRESS_SIZE16)

    #define i2c_user_SECONDARY_ADDRESS_ENABLE        (0u != i2c_user_EZI2C_NUMBER_OF_ADDRESSES)
    #define i2c_user_SECONDARY_ADDRESS_ENABLE_CONST  (i2c_user_SECONDARY_ADDRESS_ENABLE)

    #define i2c_user_EZI2C_SCL_STRETCH_ENABLE        (0u != i2c_user_EZI2C_CLOCK_STRETCHING)
    #define i2c_user_EZI2C_SCL_STRETCH_DISABLE       (!i2c_user_EZI2C_SCL_STRETCH_ENABLE)
    #define i2c_user_EZI2C_SCL_STRETCH_ENABLE_CONST  (i2c_user_EZI2C_SCL_STRETCH_ENABLE)
    #define i2c_user_EZI2C_SCL_STRETCH_DISABLE_CONST (i2c_user_EZI2C_SCL_STRETCH_DISABLE)

    #define i2c_user_EZI2C_WAKE_ENABLE_CONST         (0u != i2c_user_EZI2C_WAKE_ENABLE)
    #define i2c_user_EZI2C_EC_AM_ENABLE              (0u != i2c_user_EZI2C_WAKE_ENABLE)

    #define i2c_user_EZI2C_FIFO_SIZE i2c_user_GET_FIFO_SIZE(i2c_user_EZI2C_BYTE_MODE_ENABLE)

#endif /* (i2c_user_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*       Type Definitions
***************************************/
/**
* \addtogroup group_structures
* @{
*/
typedef struct
{
    /** When enabled the SCL is stretched as required for proper operation: 
     *  0 – disable, 1 – enable.
    */
    uint32 enableClockStretch;
    
    /** This field is left for compatibility and its value is ignored. 
     *  Median filter is disabled for EZI2C mode.
    */
    uint32 enableMedianFilter;
    
    /** Number of supported addresses: 
     *  - i2c_user_EZI2C_ONE_ADDRESS
     *  - i2c_user_EZI2C_TWO_ADDRESSES
    */
    uint32 numberOfAddresses;
    
    /** Primary 7-bit slave address.
    */
    uint32 primarySlaveAddr;
    
    /** Secondary 7-bit slave address.
    */
    uint32 secondarySlaveAddr;
    
    /** Size of sub-address.
     *  - i2c_user_EZI2C_SUB_ADDR8_BITS 
     *  - i2c_user_EZI2C_SUB_ADDR16_BITS
    */
    uint32 subAddrSize;
    
    /** When enabled the TX and RX FIFO depth is doubled and equal to 
     *  16 bytes: 0 – disable, 1 – enable.
    */
    uint32 enableWake;
    
    /** When enabled the TX and RX FIFO depth is 16 bytes: 0 – disable, 
     *  1 – enable.
     * 
     *  Ignored for all devices other than PSoC 4100 BLE / PSoC 4200 BLE / 
     *  PSoC 4100M / PSoC 4200M / PSoC 4200L / PSoC 4000S / PSoC 4100S / 
     *  PSoC Analog Coprocessor.
    */
    uint8  enableByteMode;
} i2c_user_EZI2C_INIT_STRUCT;
/** @} structures */

/***************************************
*        Function Prototypes
***************************************/

/**
* \addtogroup group_ezi2c
* @{
*/

#if(i2c_user_SCB_MODE_UNCONFIG_CONST_CFG)
    void i2c_user_EzI2CInit(const i2c_user_EZI2C_INIT_STRUCT *config);
#endif /* (i2c_user_SCB_MODE_UNCONFIG_CONST_CFG) */

uint32 i2c_user_EzI2CGetActivity(void);

void   i2c_user_EzI2CSetAddress1(uint32 address);
uint32 i2c_user_EzI2CGetAddress1(void);
void   i2c_user_EzI2CSetBuffer1(uint32 bufSize, uint32 rwBoundary, volatile uint8 * buffer);
void   i2c_user_EzI2CSetReadBoundaryBuffer1(uint32 rwBoundary);

#if(i2c_user_SECONDARY_ADDRESS_ENABLE_CONST)
    void   i2c_user_EzI2CSetAddress2(uint32 address);
    uint32 i2c_user_EzI2CGetAddress2(void);
    void   i2c_user_EzI2CSetBuffer2(uint32 bufSize, uint32 rwBoundary, volatile uint8 * buffer);
    void   i2c_user_EzI2CSetReadBoundaryBuffer2(uint32 rwBoundary);
#endif /* (i2c_user_SECONDARY_ADDRESS_ENABLE_CONST) */
/** @} ezi2c */

#if(i2c_user_EZI2C_SCL_STRETCH_ENABLE_CONST)
    CY_ISR_PROTO(i2c_user_EZI2C_STRETCH_ISR);
#endif /* (i2c_user_EZI2C_SCL_STRETCH_ENABLE_CONST) */

#if(i2c_user_EZI2C_SCL_STRETCH_DISABLE_CONST)
    CY_ISR_PROTO(i2c_user_EZI2C_NO_STRETCH_ISR);
#endif /* (i2c_user_EZI2C_SCL_STRETCH_DISABLE) */


/***************************************
*            API Constants
***************************************/

/* Configuration structure constants */
#define i2c_user_EZI2C_ONE_ADDRESS      (0u)
#define i2c_user_EZI2C_TWO_ADDRESSES    (1u)

#define i2c_user_EZI2C_PRIMARY_ADDRESS  (0u)
#define i2c_user_EZI2C_BOTH_ADDRESSES   (1u)

#define i2c_user_EZI2C_SUB_ADDR8_BITS   (0u)
#define i2c_user_EZI2C_SUB_ADDR16_BITS  (1u)

/* i2c_user_EzI2CGetActivity() return constants */
#define i2c_user_EZI2C_STATUS_SECOND_OFFSET (1u)
#define i2c_user_EZI2C_STATUS_READ1     ((uint32) (i2c_user_INTR_SLAVE_I2C_NACK))        /* Bit [1]   */
#define i2c_user_EZI2C_STATUS_WRITE1    ((uint32) (i2c_user_INTR_SLAVE_I2C_WRITE_STOP))  /* Bit [3]   */
#define i2c_user_EZI2C_STATUS_READ2     ((uint32) (i2c_user_INTR_SLAVE_I2C_NACK >> \
                                                           i2c_user_EZI2C_STATUS_SECOND_OFFSET)) /* Bit [0]   */
#define i2c_user_EZI2C_STATUS_WRITE2    ((uint32) (i2c_user_INTR_SLAVE_I2C_WRITE_STOP >> \
                                                           i2c_user_EZI2C_STATUS_SECOND_OFFSET)) /* Bit [2]   */
#define i2c_user_EZI2C_STATUS_ERR       ((uint32) (0x10u))                                       /* Bit [4]   */
#define i2c_user_EZI2C_STATUS_BUSY      ((uint32) (0x20u))                                       /* Bit [5]   */
#define i2c_user_EZI2C_CLEAR_STATUS     ((uint32) (0x1Fu))                                       /* Bits [0-4]*/
#define i2c_user_EZI2C_CMPLT_INTR_MASK  ((uint32) (i2c_user_INTR_SLAVE_I2C_NACK | \
                                                           i2c_user_INTR_SLAVE_I2C_WRITE_STOP))


/***************************************
*     Vars with External Linkage
***************************************/

#if(i2c_user_SCB_MODE_UNCONFIG_CONST_CFG)
    extern const i2c_user_EZI2C_INIT_STRUCT i2c_user_configEzI2C;
#endif /* (i2c_user_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*           FSM states
***************************************/

/* Returns to master when there is no data to transmit */
#define i2c_user_EZI2C_OVFL_RETURN  (0xFFu)

/* States of EZI2C Slave FSM */
#define i2c_user_EZI2C_FSM_OFFSET_HI8 ((uint8) (0x02u)) /* Idle state for 1 addr: waits for high byte offset */
#define i2c_user_EZI2C_FSM_OFFSET_LO8 ((uint8) (0x00u)) /* Idle state for 2 addr: waits for low byte offset  */
#define i2c_user_EZI2C_FSM_BYTE_WRITE ((uint8) (0x01u)) /* Data byte write state: byte by byte mode          */
#define i2c_user_EZI2C_FSM_WAIT_STOP  ((uint8) (0x03u)) /* Discards written bytes as they do not match write
                                                                   criteria */
#define i2c_user_EZI2C_FSM_WRITE_MASK ((uint8) (0x01u)) /* Incorporates write states: EZI2C_FSM_BYTE_WRITE and
                                                                   EZI2C_FSM_WAIT_STOP  */

#define i2c_user_EZI2C_FSM_IDLE     ((i2c_user_SUB_ADDRESS_SIZE16) ?      \
                                                (i2c_user_EZI2C_FSM_OFFSET_HI8) : \
                                                (i2c_user_EZI2C_FSM_OFFSET_LO8))

#define i2c_user_EZI2C_CONTINUE_TRANSFER    (1u)
#define i2c_user_EZI2C_COMPLETE_TRANSFER    (0u)

#define i2c_user_EZI2C_NACK_RECEIVED_ADDRESS  (0u)
#define i2c_user_EZI2C_ACK_RECEIVED_ADDRESS   (1u)

#define i2c_user_EZI2C_ACTIVE_ADDRESS1  (0u)
#define i2c_user_EZI2C_ACTIVE_ADDRESS2  (1u)


/***************************************
*       Macro Definitions
***************************************/

/* Access to global variables */
#if(i2c_user_SECONDARY_ADDRESS_ENABLE_CONST)

    #define i2c_user_EZI2C_UPDATE_LOC_STATUS(activeAddress, locStatus) \
            do{ \
                (locStatus) >>= (activeAddress); \
            }while(0)

    #define i2c_user_EZI2C_GET_INDEX(activeAddress) \
            ((i2c_user_EZI2C_ACTIVE_ADDRESS1 == (activeAddress)) ? \
                ((uint32) i2c_user_indexBuf1) :                    \
                ((uint32) i2c_user_indexBuf2))

    #define i2c_user_EZI2C_GET_OFFSET(activeAddress) \
            ((i2c_user_EZI2C_ACTIVE_ADDRESS1 == (activeAddress)) ? \
                ((uint32) i2c_user_offsetBuf1) :                   \
                ((uint32) i2c_user_offsetBuf2))

    #define i2c_user_EZI2C_SET_INDEX(activeAddress, locIndex) \
            do{ \
                if(i2c_user_EZI2C_ACTIVE_ADDRESS1 == (activeAddress)) \
                {    \
                    i2c_user_indexBuf1 = (uint16) (locIndex); \
                }    \
                else \
                {    \
                    i2c_user_indexBuf2 = (uint16) (locIndex); \
                }    \
            }while(0)

    #define i2c_user_EZI2C_SET_OFFSET(activeAddress, locOffset) \
            do{ \
                if(i2c_user_EZI2C_ACTIVE_ADDRESS1 == (activeAddress)) \
                {    \
                    i2c_user_offsetBuf1 = (uint8) (locOffset); \
                }    \
                else \
                {    \
                    i2c_user_offsetBuf2 = (uint8) (locOffset); \
                }    \
            }while(0)
#else
    #define i2c_user_EZI2C_UPDATE_LOC_STATUS(activeAddress, locStatus)  do{ /* Empty*/ }while(0)

    #define i2c_user_EZI2C_GET_INDEX(activeAddress)  ((uint32) (i2c_user_indexBuf1))

    #define i2c_user_EZI2C_GET_OFFSET(activeAddress) ((uint32) (i2c_user_offsetBuf1))

    #define i2c_user_EZI2C_SET_INDEX(activeAddress, locIndex) \
            do{ \
                i2c_user_indexBuf1 = (uint16) (locIndex); \
            }while(0)

    #define i2c_user_EZI2C_SET_OFFSET(activeAddress, locOffset) \
            do{ \
                i2c_user_offsetBuf1 = (uint8) (locOffset); \
            }while(0)

#endif  /* (i2c_user_SUB_ADDRESS_SIZE16_CONST) */


/* This macro only applicable for EZI2C slave without clock stretching.
* It should not be used for other pusposes. */
#define i2c_user_EZI2C_TX_FIFO_CTRL_SET   (i2c_user_EZI2C_TX_FIFO_CTRL | \
                                                   i2c_user_TX_FIFO_CTRL_CLEAR)
#define i2c_user_EZI2C_TX_FIFO_CTRL_CLEAR (i2c_user_EZI2C_TX_FIFO_CTRL)
#define i2c_user_FAST_CLEAR_TX_FIFO \
                            do{             \
                                i2c_user_TX_FIFO_CTRL_REG = i2c_user_EZI2C_TX_FIFO_CTRL_SET;   \
                                i2c_user_TX_FIFO_CTRL_REG = i2c_user_EZI2C_TX_FIFO_CTRL_CLEAR; \
                            }while(0)


/***************************************
*      Common Register Settings
***************************************/

#define i2c_user_CTRL_EZI2C     (i2c_user_CTRL_MODE_I2C)

#define i2c_user_EZI2C_CTRL     (i2c_user_I2C_CTRL_S_GENERAL_IGNORE | \
                                         i2c_user_I2C_CTRL_SLAVE_MODE)

#define i2c_user_EZI2C_CTRL_AUTO    (i2c_user_I2C_CTRL_S_READY_ADDR_ACK      | \
                                             i2c_user_I2C_CTRL_S_READY_DATA_ACK      | \
                                             i2c_user_I2C_CTRL_S_NOT_READY_ADDR_NACK | \
                                             i2c_user_I2C_CTRL_S_NOT_READY_DATA_NACK)

#define i2c_user_EZI2C_RX_CTRL  ((i2c_user_FIFO_SIZE - 1u)   | \
                                          i2c_user_RX_CTRL_MSB_FIRST | \
                                          i2c_user_RX_CTRL_ENABLED)

#define i2c_user_EZI2C_TX_FIFO_CTRL (2u)
#define i2c_user_TX_LOAD_SIZE       (2u)

#define i2c_user_EZI2C_TX_CTRL  ((i2c_user_ONE_BYTE_WIDTH - 1u) | \
                                          i2c_user_TX_CTRL_MSB_FIRST    | \
                                          i2c_user_TX_CTRL_ENABLED)

#define i2c_user_EZI2C_INTR_SLAVE_MASK  (i2c_user_INTR_SLAVE_I2C_BUS_ERROR | \
                                                 i2c_user_INTR_SLAVE_I2C_ARB_LOST  | \
                                                 i2c_user_INTR_SLAVE_I2C_STOP)

#define i2c_user_INTR_SLAVE_COMPLETE    (i2c_user_INTR_SLAVE_I2C_STOP | \
                                                 i2c_user_INTR_SLAVE_I2C_NACK | \
                                                 i2c_user_INTR_SLAVE_I2C_WRITE_STOP)


/***************************************
*    Initialization Register Settings
***************************************/

#if(i2c_user_SCB_MODE_EZI2C_CONST_CFG)

    #define i2c_user_EZI2C_DEFAULT_CTRL \
                                (i2c_user_GET_CTRL_BYTE_MODE  (i2c_user_EZI2C_BYTE_MODE_ENABLE)    | \
                                 i2c_user_GET_CTRL_ADDR_ACCEPT(i2c_user_EZI2C_NUMBER_OF_ADDRESSES) | \
                                 i2c_user_GET_CTRL_EC_AM_MODE (i2c_user_EZI2C_WAKE_ENABLE))

    #if(i2c_user_EZI2C_SCL_STRETCH_ENABLE_CONST)
        #define i2c_user_EZI2C_DEFAULT_I2C_CTRL (i2c_user_EZI2C_CTRL)
    #else
        #define i2c_user_EZI2C_DEFAULT_I2C_CTRL (i2c_user_EZI2C_CTRL_AUTO | i2c_user_EZI2C_CTRL)
    #endif /* (i2c_user_EZI2C_SCL_STRETCH_ENABLE_CONST) */


    #define i2c_user_EZI2C_DEFAULT_RX_MATCH \
                                (i2c_user_GET_I2C_8BIT_ADDRESS(i2c_user_EZI2C_PRIMARY_SLAVE_ADDRESS) | \
                                 i2c_user_GET_RX_MATCH_MASK   (i2c_user_EZI2C_SLAVE_ADDRESS_MASK))

    #define i2c_user_EZI2C_DEFAULT_RX_CTRL  (i2c_user_EZI2C_RX_CTRL)
    #define i2c_user_EZI2C_DEFAULT_TX_CTRL  (i2c_user_EZI2C_TX_CTRL)

    #define i2c_user_EZI2C_DEFAULT_RX_FIFO_CTRL (0u)
    #if(i2c_user_EZI2C_SCL_STRETCH_ENABLE_CONST)
        #define i2c_user_EZI2C_DEFAULT_TX_FIFO_CTRL (0u)
    #else
        #define i2c_user_EZI2C_DEFAULT_TX_FIFO_CTRL (2u)
    #endif /* (i2c_user_EZI2C_SCL_STRETCH_ENABLE_CONST) */

    /* Interrupt sources */
    #define i2c_user_EZI2C_DEFAULT_INTR_I2C_EC_MASK (i2c_user_NO_INTR_SOURCES)
    #define i2c_user_EZI2C_DEFAULT_INTR_SPI_EC_MASK (i2c_user_NO_INTR_SOURCES)
    #define i2c_user_EZI2C_DEFAULT_INTR_MASTER_MASK (i2c_user_NO_INTR_SOURCES)
    #define i2c_user_EZI2C_DEFAULT_INTR_TX_MASK     (i2c_user_NO_INTR_SOURCES)

    #if(i2c_user_EZI2C_SCL_STRETCH_ENABLE_CONST)
        #define i2c_user_EZI2C_DEFAULT_INTR_RX_MASK     (i2c_user_NO_INTR_SOURCES)
        #define i2c_user_EZI2C_DEFAULT_INTR_SLAVE_MASK  (i2c_user_INTR_SLAVE_I2C_ADDR_MATCH | \
                                                                 i2c_user_EZI2C_INTR_SLAVE_MASK)
    #else
        #define i2c_user_EZI2C_DEFAULT_INTR_RX_MASK     (i2c_user_INTR_RX_NOT_EMPTY)
        #define i2c_user_EZI2C_DEFAULT_INTR_SLAVE_MASK  (i2c_user_INTR_SLAVE_I2C_START | \
                                                                 i2c_user_EZI2C_INTR_SLAVE_MASK)
    #endif /* (i2c_user_EZI2C_SCL_STRETCH_ENABLE_CONST) */

#endif /* (i2c_user_SCB_MODE_EZI2C_CONST_CFG) */

#endif /* (CY_SCB_EZI2C_i2c_user_H) */


/* [] END OF FILE */
