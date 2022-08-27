/***************************************************************************//**
* \file i2c_master_PINS.h
* \version 4.0
*
* \brief
*  This file provides constants and parameter values for the pin components
*  buried into SCB Component.
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

#if !defined(CY_SCB_PINS_i2c_master_H)
#define CY_SCB_PINS_i2c_master_H

#include "cydevice_trm.h"
#include "cyfitter.h"
#include "cytypes.h"


/***************************************
*   Conditional Compilation Parameters
****************************************/

/* Unconfigured pins */
#define i2c_master_REMOVE_RX_WAKE_SCL_MOSI_PIN  (1u)
#define i2c_master_REMOVE_RX_SCL_MOSI_PIN      (1u)
#define i2c_master_REMOVE_TX_SDA_MISO_PIN      (1u)
#define i2c_master_REMOVE_SCLK_PIN      (1u)
#define i2c_master_REMOVE_SS0_PIN      (1u)
#define i2c_master_REMOVE_SS1_PIN                 (1u)
#define i2c_master_REMOVE_SS2_PIN                 (1u)
#define i2c_master_REMOVE_SS3_PIN                 (1u)

/* Mode defined pins */
#define i2c_master_REMOVE_I2C_PINS                (0u)
#define i2c_master_REMOVE_SPI_MASTER_PINS         (1u)
#define i2c_master_REMOVE_SPI_MASTER_SCLK_PIN     (1u)
#define i2c_master_REMOVE_SPI_MASTER_MOSI_PIN     (1u)
#define i2c_master_REMOVE_SPI_MASTER_MISO_PIN     (1u)
#define i2c_master_REMOVE_SPI_MASTER_SS0_PIN      (1u)
#define i2c_master_REMOVE_SPI_MASTER_SS1_PIN      (1u)
#define i2c_master_REMOVE_SPI_MASTER_SS2_PIN      (1u)
#define i2c_master_REMOVE_SPI_MASTER_SS3_PIN      (1u)
#define i2c_master_REMOVE_SPI_SLAVE_PINS          (1u)
#define i2c_master_REMOVE_SPI_SLAVE_MOSI_PIN      (1u)
#define i2c_master_REMOVE_SPI_SLAVE_MISO_PIN      (1u)
#define i2c_master_REMOVE_UART_TX_PIN             (1u)
#define i2c_master_REMOVE_UART_RX_TX_PIN          (1u)
#define i2c_master_REMOVE_UART_RX_PIN             (1u)
#define i2c_master_REMOVE_UART_RX_WAKE_PIN        (1u)
#define i2c_master_REMOVE_UART_RTS_PIN            (1u)
#define i2c_master_REMOVE_UART_CTS_PIN            (1u)

/* Unconfigured pins */
#define i2c_master_RX_WAKE_SCL_MOSI_PIN (0u == i2c_master_REMOVE_RX_WAKE_SCL_MOSI_PIN)
#define i2c_master_RX_SCL_MOSI_PIN     (0u == i2c_master_REMOVE_RX_SCL_MOSI_PIN)
#define i2c_master_TX_SDA_MISO_PIN     (0u == i2c_master_REMOVE_TX_SDA_MISO_PIN)
#define i2c_master_SCLK_PIN     (0u == i2c_master_REMOVE_SCLK_PIN)
#define i2c_master_SS0_PIN     (0u == i2c_master_REMOVE_SS0_PIN)
#define i2c_master_SS1_PIN                (0u == i2c_master_REMOVE_SS1_PIN)
#define i2c_master_SS2_PIN                (0u == i2c_master_REMOVE_SS2_PIN)
#define i2c_master_SS3_PIN                (0u == i2c_master_REMOVE_SS3_PIN)

/* Mode defined pins */
#define i2c_master_I2C_PINS               (0u == i2c_master_REMOVE_I2C_PINS)
#define i2c_master_SPI_MASTER_PINS        (0u == i2c_master_REMOVE_SPI_MASTER_PINS)
#define i2c_master_SPI_MASTER_SCLK_PIN    (0u == i2c_master_REMOVE_SPI_MASTER_SCLK_PIN)
#define i2c_master_SPI_MASTER_MOSI_PIN    (0u == i2c_master_REMOVE_SPI_MASTER_MOSI_PIN)
#define i2c_master_SPI_MASTER_MISO_PIN    (0u == i2c_master_REMOVE_SPI_MASTER_MISO_PIN)
#define i2c_master_SPI_MASTER_SS0_PIN     (0u == i2c_master_REMOVE_SPI_MASTER_SS0_PIN)
#define i2c_master_SPI_MASTER_SS1_PIN     (0u == i2c_master_REMOVE_SPI_MASTER_SS1_PIN)
#define i2c_master_SPI_MASTER_SS2_PIN     (0u == i2c_master_REMOVE_SPI_MASTER_SS2_PIN)
#define i2c_master_SPI_MASTER_SS3_PIN     (0u == i2c_master_REMOVE_SPI_MASTER_SS3_PIN)
#define i2c_master_SPI_SLAVE_PINS         (0u == i2c_master_REMOVE_SPI_SLAVE_PINS)
#define i2c_master_SPI_SLAVE_MOSI_PIN     (0u == i2c_master_REMOVE_SPI_SLAVE_MOSI_PIN)
#define i2c_master_SPI_SLAVE_MISO_PIN     (0u == i2c_master_REMOVE_SPI_SLAVE_MISO_PIN)
#define i2c_master_UART_TX_PIN            (0u == i2c_master_REMOVE_UART_TX_PIN)
#define i2c_master_UART_RX_TX_PIN         (0u == i2c_master_REMOVE_UART_RX_TX_PIN)
#define i2c_master_UART_RX_PIN            (0u == i2c_master_REMOVE_UART_RX_PIN)
#define i2c_master_UART_RX_WAKE_PIN       (0u == i2c_master_REMOVE_UART_RX_WAKE_PIN)
#define i2c_master_UART_RTS_PIN           (0u == i2c_master_REMOVE_UART_RTS_PIN)
#define i2c_master_UART_CTS_PIN           (0u == i2c_master_REMOVE_UART_CTS_PIN)


/***************************************
*             Includes
****************************************/

#if (i2c_master_RX_WAKE_SCL_MOSI_PIN)
    #include "i2c_master_uart_rx_wake_i2c_scl_spi_mosi.h"
#endif /* (i2c_master_RX_SCL_MOSI) */

#if (i2c_master_RX_SCL_MOSI_PIN)
    #include "i2c_master_uart_rx_i2c_scl_spi_mosi.h"
#endif /* (i2c_master_RX_SCL_MOSI) */

#if (i2c_master_TX_SDA_MISO_PIN)
    #include "i2c_master_uart_tx_i2c_sda_spi_miso.h"
#endif /* (i2c_master_TX_SDA_MISO) */

#if (i2c_master_SCLK_PIN)
    #include "i2c_master_spi_sclk.h"
#endif /* (i2c_master_SCLK) */

#if (i2c_master_SS0_PIN)
    #include "i2c_master_spi_ss0.h"
#endif /* (i2c_master_SS0_PIN) */

#if (i2c_master_SS1_PIN)
    #include "i2c_master_spi_ss1.h"
#endif /* (i2c_master_SS1_PIN) */

#if (i2c_master_SS2_PIN)
    #include "i2c_master_spi_ss2.h"
#endif /* (i2c_master_SS2_PIN) */

#if (i2c_master_SS3_PIN)
    #include "i2c_master_spi_ss3.h"
#endif /* (i2c_master_SS3_PIN) */

#if (i2c_master_I2C_PINS)
    #include "i2c_master_scl.h"
    #include "i2c_master_sda.h"
#endif /* (i2c_master_I2C_PINS) */

#if (i2c_master_SPI_MASTER_PINS)
#if (i2c_master_SPI_MASTER_SCLK_PIN)
    #include "i2c_master_sclk_m.h"
#endif /* (i2c_master_SPI_MASTER_SCLK_PIN) */

#if (i2c_master_SPI_MASTER_MOSI_PIN)
    #include "i2c_master_mosi_m.h"
#endif /* (i2c_master_SPI_MASTER_MOSI_PIN) */

#if (i2c_master_SPI_MASTER_MISO_PIN)
    #include "i2c_master_miso_m.h"
#endif /*(i2c_master_SPI_MASTER_MISO_PIN) */
#endif /* (i2c_master_SPI_MASTER_PINS) */

#if (i2c_master_SPI_SLAVE_PINS)
    #include "i2c_master_sclk_s.h"
    #include "i2c_master_ss_s.h"

#if (i2c_master_SPI_SLAVE_MOSI_PIN)
    #include "i2c_master_mosi_s.h"
#endif /* (i2c_master_SPI_SLAVE_MOSI_PIN) */

#if (i2c_master_SPI_SLAVE_MISO_PIN)
    #include "i2c_master_miso_s.h"
#endif /*(i2c_master_SPI_SLAVE_MISO_PIN) */
#endif /* (i2c_master_SPI_SLAVE_PINS) */

#if (i2c_master_SPI_MASTER_SS0_PIN)
    #include "i2c_master_ss0_m.h"
#endif /* (i2c_master_SPI_MASTER_SS0_PIN) */

#if (i2c_master_SPI_MASTER_SS1_PIN)
    #include "i2c_master_ss1_m.h"
#endif /* (i2c_master_SPI_MASTER_SS1_PIN) */

#if (i2c_master_SPI_MASTER_SS2_PIN)
    #include "i2c_master_ss2_m.h"
#endif /* (i2c_master_SPI_MASTER_SS2_PIN) */

#if (i2c_master_SPI_MASTER_SS3_PIN)
    #include "i2c_master_ss3_m.h"
#endif /* (i2c_master_SPI_MASTER_SS3_PIN) */

#if (i2c_master_UART_TX_PIN)
    #include "i2c_master_tx.h"
#endif /* (i2c_master_UART_TX_PIN) */

#if (i2c_master_UART_RX_TX_PIN)
    #include "i2c_master_rx_tx.h"
#endif /* (i2c_master_UART_RX_TX_PIN) */

#if (i2c_master_UART_RX_PIN)
    #include "i2c_master_rx.h"
#endif /* (i2c_master_UART_RX_PIN) */

#if (i2c_master_UART_RX_WAKE_PIN)
    #include "i2c_master_rx_wake.h"
#endif /* (i2c_master_UART_RX_WAKE_PIN) */

#if (i2c_master_UART_RTS_PIN)
    #include "i2c_master_rts.h"
#endif /* (i2c_master_UART_RTS_PIN) */

#if (i2c_master_UART_CTS_PIN)
    #include "i2c_master_cts.h"
#endif /* (i2c_master_UART_CTS_PIN) */


/***************************************
*              Registers
***************************************/

#if (i2c_master_RX_SCL_MOSI_PIN)
    #define i2c_master_RX_SCL_MOSI_HSIOM_REG   (*(reg32 *) i2c_master_uart_rx_i2c_scl_spi_mosi__0__HSIOM)
    #define i2c_master_RX_SCL_MOSI_HSIOM_PTR   ( (reg32 *) i2c_master_uart_rx_i2c_scl_spi_mosi__0__HSIOM)
    
    #define i2c_master_RX_SCL_MOSI_HSIOM_MASK      (i2c_master_uart_rx_i2c_scl_spi_mosi__0__HSIOM_MASK)
    #define i2c_master_RX_SCL_MOSI_HSIOM_POS       (i2c_master_uart_rx_i2c_scl_spi_mosi__0__HSIOM_SHIFT)
    #define i2c_master_RX_SCL_MOSI_HSIOM_SEL_GPIO  (i2c_master_uart_rx_i2c_scl_spi_mosi__0__HSIOM_GPIO)
    #define i2c_master_RX_SCL_MOSI_HSIOM_SEL_I2C   (i2c_master_uart_rx_i2c_scl_spi_mosi__0__HSIOM_I2C)
    #define i2c_master_RX_SCL_MOSI_HSIOM_SEL_SPI   (i2c_master_uart_rx_i2c_scl_spi_mosi__0__HSIOM_SPI)
    #define i2c_master_RX_SCL_MOSI_HSIOM_SEL_UART  (i2c_master_uart_rx_i2c_scl_spi_mosi__0__HSIOM_UART)
    
#elif (i2c_master_RX_WAKE_SCL_MOSI_PIN)
    #define i2c_master_RX_WAKE_SCL_MOSI_HSIOM_REG   (*(reg32 *) i2c_master_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM)
    #define i2c_master_RX_WAKE_SCL_MOSI_HSIOM_PTR   ( (reg32 *) i2c_master_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM)
    
    #define i2c_master_RX_WAKE_SCL_MOSI_HSIOM_MASK      (i2c_master_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_MASK)
    #define i2c_master_RX_WAKE_SCL_MOSI_HSIOM_POS       (i2c_master_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_SHIFT)
    #define i2c_master_RX_WAKE_SCL_MOSI_HSIOM_SEL_GPIO  (i2c_master_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_GPIO)
    #define i2c_master_RX_WAKE_SCL_MOSI_HSIOM_SEL_I2C   (i2c_master_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_I2C)
    #define i2c_master_RX_WAKE_SCL_MOSI_HSIOM_SEL_SPI   (i2c_master_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_SPI)
    #define i2c_master_RX_WAKE_SCL_MOSI_HSIOM_SEL_UART  (i2c_master_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_UART)    
   
    #define i2c_master_RX_WAKE_SCL_MOSI_INTCFG_REG (*(reg32 *) i2c_master_uart_rx_wake_i2c_scl_spi_mosi__0__INTCFG)
    #define i2c_master_RX_WAKE_SCL_MOSI_INTCFG_PTR ( (reg32 *) i2c_master_uart_rx_wake_i2c_scl_spi_mosi__0__INTCFG)
    #define i2c_master_RX_WAKE_SCL_MOSI_INTCFG_TYPE_POS  (i2c_master_uart_rx_wake_i2c_scl_spi_mosi__SHIFT)
    #define i2c_master_RX_WAKE_SCL_MOSI_INTCFG_TYPE_MASK ((uint32) i2c_master_INTCFG_TYPE_MASK << \
                                                                           i2c_master_RX_WAKE_SCL_MOSI_INTCFG_TYPE_POS)
#else
    /* None of pins i2c_master_RX_SCL_MOSI_PIN or i2c_master_RX_WAKE_SCL_MOSI_PIN present.*/
#endif /* (i2c_master_RX_SCL_MOSI_PIN) */

#if (i2c_master_TX_SDA_MISO_PIN)
    #define i2c_master_TX_SDA_MISO_HSIOM_REG   (*(reg32 *) i2c_master_uart_tx_i2c_sda_spi_miso__0__HSIOM)
    #define i2c_master_TX_SDA_MISO_HSIOM_PTR   ( (reg32 *) i2c_master_uart_tx_i2c_sda_spi_miso__0__HSIOM)
    
    #define i2c_master_TX_SDA_MISO_HSIOM_MASK      (i2c_master_uart_tx_i2c_sda_spi_miso__0__HSIOM_MASK)
    #define i2c_master_TX_SDA_MISO_HSIOM_POS       (i2c_master_uart_tx_i2c_sda_spi_miso__0__HSIOM_SHIFT)
    #define i2c_master_TX_SDA_MISO_HSIOM_SEL_GPIO  (i2c_master_uart_tx_i2c_sda_spi_miso__0__HSIOM_GPIO)
    #define i2c_master_TX_SDA_MISO_HSIOM_SEL_I2C   (i2c_master_uart_tx_i2c_sda_spi_miso__0__HSIOM_I2C)
    #define i2c_master_TX_SDA_MISO_HSIOM_SEL_SPI   (i2c_master_uart_tx_i2c_sda_spi_miso__0__HSIOM_SPI)
    #define i2c_master_TX_SDA_MISO_HSIOM_SEL_UART  (i2c_master_uart_tx_i2c_sda_spi_miso__0__HSIOM_UART)
#endif /* (i2c_master_TX_SDA_MISO_PIN) */

#if (i2c_master_SCLK_PIN)
    #define i2c_master_SCLK_HSIOM_REG   (*(reg32 *) i2c_master_spi_sclk__0__HSIOM)
    #define i2c_master_SCLK_HSIOM_PTR   ( (reg32 *) i2c_master_spi_sclk__0__HSIOM)
    
    #define i2c_master_SCLK_HSIOM_MASK      (i2c_master_spi_sclk__0__HSIOM_MASK)
    #define i2c_master_SCLK_HSIOM_POS       (i2c_master_spi_sclk__0__HSIOM_SHIFT)
    #define i2c_master_SCLK_HSIOM_SEL_GPIO  (i2c_master_spi_sclk__0__HSIOM_GPIO)
    #define i2c_master_SCLK_HSIOM_SEL_I2C   (i2c_master_spi_sclk__0__HSIOM_I2C)
    #define i2c_master_SCLK_HSIOM_SEL_SPI   (i2c_master_spi_sclk__0__HSIOM_SPI)
    #define i2c_master_SCLK_HSIOM_SEL_UART  (i2c_master_spi_sclk__0__HSIOM_UART)
#endif /* (i2c_master_SCLK_PIN) */

#if (i2c_master_SS0_PIN)
    #define i2c_master_SS0_HSIOM_REG   (*(reg32 *) i2c_master_spi_ss0__0__HSIOM)
    #define i2c_master_SS0_HSIOM_PTR   ( (reg32 *) i2c_master_spi_ss0__0__HSIOM)
    
    #define i2c_master_SS0_HSIOM_MASK      (i2c_master_spi_ss0__0__HSIOM_MASK)
    #define i2c_master_SS0_HSIOM_POS       (i2c_master_spi_ss0__0__HSIOM_SHIFT)
    #define i2c_master_SS0_HSIOM_SEL_GPIO  (i2c_master_spi_ss0__0__HSIOM_GPIO)
    #define i2c_master_SS0_HSIOM_SEL_I2C   (i2c_master_spi_ss0__0__HSIOM_I2C)
    #define i2c_master_SS0_HSIOM_SEL_SPI   (i2c_master_spi_ss0__0__HSIOM_SPI)
#if !(i2c_master_CY_SCBIP_V0 || i2c_master_CY_SCBIP_V1)
    #define i2c_master_SS0_HSIOM_SEL_UART  (i2c_master_spi_ss0__0__HSIOM_UART)
#endif /* !(i2c_master_CY_SCBIP_V0 || i2c_master_CY_SCBIP_V1) */
#endif /* (i2c_master_SS0_PIN) */

#if (i2c_master_SS1_PIN)
    #define i2c_master_SS1_HSIOM_REG  (*(reg32 *) i2c_master_spi_ss1__0__HSIOM)
    #define i2c_master_SS1_HSIOM_PTR  ( (reg32 *) i2c_master_spi_ss1__0__HSIOM)
    
    #define i2c_master_SS1_HSIOM_MASK     (i2c_master_spi_ss1__0__HSIOM_MASK)
    #define i2c_master_SS1_HSIOM_POS      (i2c_master_spi_ss1__0__HSIOM_SHIFT)
    #define i2c_master_SS1_HSIOM_SEL_GPIO (i2c_master_spi_ss1__0__HSIOM_GPIO)
    #define i2c_master_SS1_HSIOM_SEL_I2C  (i2c_master_spi_ss1__0__HSIOM_I2C)
    #define i2c_master_SS1_HSIOM_SEL_SPI  (i2c_master_spi_ss1__0__HSIOM_SPI)
#endif /* (i2c_master_SS1_PIN) */

#if (i2c_master_SS2_PIN)
    #define i2c_master_SS2_HSIOM_REG     (*(reg32 *) i2c_master_spi_ss2__0__HSIOM)
    #define i2c_master_SS2_HSIOM_PTR     ( (reg32 *) i2c_master_spi_ss2__0__HSIOM)
    
    #define i2c_master_SS2_HSIOM_MASK     (i2c_master_spi_ss2__0__HSIOM_MASK)
    #define i2c_master_SS2_HSIOM_POS      (i2c_master_spi_ss2__0__HSIOM_SHIFT)
    #define i2c_master_SS2_HSIOM_SEL_GPIO (i2c_master_spi_ss2__0__HSIOM_GPIO)
    #define i2c_master_SS2_HSIOM_SEL_I2C  (i2c_master_spi_ss2__0__HSIOM_I2C)
    #define i2c_master_SS2_HSIOM_SEL_SPI  (i2c_master_spi_ss2__0__HSIOM_SPI)
#endif /* (i2c_master_SS2_PIN) */

#if (i2c_master_SS3_PIN)
    #define i2c_master_SS3_HSIOM_REG     (*(reg32 *) i2c_master_spi_ss3__0__HSIOM)
    #define i2c_master_SS3_HSIOM_PTR     ( (reg32 *) i2c_master_spi_ss3__0__HSIOM)
    
    #define i2c_master_SS3_HSIOM_MASK     (i2c_master_spi_ss3__0__HSIOM_MASK)
    #define i2c_master_SS3_HSIOM_POS      (i2c_master_spi_ss3__0__HSIOM_SHIFT)
    #define i2c_master_SS3_HSIOM_SEL_GPIO (i2c_master_spi_ss3__0__HSIOM_GPIO)
    #define i2c_master_SS3_HSIOM_SEL_I2C  (i2c_master_spi_ss3__0__HSIOM_I2C)
    #define i2c_master_SS3_HSIOM_SEL_SPI  (i2c_master_spi_ss3__0__HSIOM_SPI)
#endif /* (i2c_master_SS3_PIN) */

#if (i2c_master_I2C_PINS)
    #define i2c_master_SCL_HSIOM_REG  (*(reg32 *) i2c_master_scl__0__HSIOM)
    #define i2c_master_SCL_HSIOM_PTR  ( (reg32 *) i2c_master_scl__0__HSIOM)
    
    #define i2c_master_SCL_HSIOM_MASK     (i2c_master_scl__0__HSIOM_MASK)
    #define i2c_master_SCL_HSIOM_POS      (i2c_master_scl__0__HSIOM_SHIFT)
    #define i2c_master_SCL_HSIOM_SEL_GPIO (i2c_master_sda__0__HSIOM_GPIO)
    #define i2c_master_SCL_HSIOM_SEL_I2C  (i2c_master_sda__0__HSIOM_I2C)
    
    #define i2c_master_SDA_HSIOM_REG  (*(reg32 *) i2c_master_sda__0__HSIOM)
    #define i2c_master_SDA_HSIOM_PTR  ( (reg32 *) i2c_master_sda__0__HSIOM)
    
    #define i2c_master_SDA_HSIOM_MASK     (i2c_master_sda__0__HSIOM_MASK)
    #define i2c_master_SDA_HSIOM_POS      (i2c_master_sda__0__HSIOM_SHIFT)
    #define i2c_master_SDA_HSIOM_SEL_GPIO (i2c_master_sda__0__HSIOM_GPIO)
    #define i2c_master_SDA_HSIOM_SEL_I2C  (i2c_master_sda__0__HSIOM_I2C)
#endif /* (i2c_master_I2C_PINS) */

#if (i2c_master_SPI_SLAVE_PINS)
    #define i2c_master_SCLK_S_HSIOM_REG   (*(reg32 *) i2c_master_sclk_s__0__HSIOM)
    #define i2c_master_SCLK_S_HSIOM_PTR   ( (reg32 *) i2c_master_sclk_s__0__HSIOM)
    
    #define i2c_master_SCLK_S_HSIOM_MASK      (i2c_master_sclk_s__0__HSIOM_MASK)
    #define i2c_master_SCLK_S_HSIOM_POS       (i2c_master_sclk_s__0__HSIOM_SHIFT)
    #define i2c_master_SCLK_S_HSIOM_SEL_GPIO  (i2c_master_sclk_s__0__HSIOM_GPIO)
    #define i2c_master_SCLK_S_HSIOM_SEL_SPI   (i2c_master_sclk_s__0__HSIOM_SPI)
    
    #define i2c_master_SS0_S_HSIOM_REG    (*(reg32 *) i2c_master_ss0_s__0__HSIOM)
    #define i2c_master_SS0_S_HSIOM_PTR    ( (reg32 *) i2c_master_ss0_s__0__HSIOM)
    
    #define i2c_master_SS0_S_HSIOM_MASK       (i2c_master_ss0_s__0__HSIOM_MASK)
    #define i2c_master_SS0_S_HSIOM_POS        (i2c_master_ss0_s__0__HSIOM_SHIFT)
    #define i2c_master_SS0_S_HSIOM_SEL_GPIO   (i2c_master_ss0_s__0__HSIOM_GPIO)  
    #define i2c_master_SS0_S_HSIOM_SEL_SPI    (i2c_master_ss0_s__0__HSIOM_SPI)
#endif /* (i2c_master_SPI_SLAVE_PINS) */

#if (i2c_master_SPI_SLAVE_MOSI_PIN)
    #define i2c_master_MOSI_S_HSIOM_REG   (*(reg32 *) i2c_master_mosi_s__0__HSIOM)
    #define i2c_master_MOSI_S_HSIOM_PTR   ( (reg32 *) i2c_master_mosi_s__0__HSIOM)
    
    #define i2c_master_MOSI_S_HSIOM_MASK      (i2c_master_mosi_s__0__HSIOM_MASK)
    #define i2c_master_MOSI_S_HSIOM_POS       (i2c_master_mosi_s__0__HSIOM_SHIFT)
    #define i2c_master_MOSI_S_HSIOM_SEL_GPIO  (i2c_master_mosi_s__0__HSIOM_GPIO)
    #define i2c_master_MOSI_S_HSIOM_SEL_SPI   (i2c_master_mosi_s__0__HSIOM_SPI)
#endif /* (i2c_master_SPI_SLAVE_MOSI_PIN) */

#if (i2c_master_SPI_SLAVE_MISO_PIN)
    #define i2c_master_MISO_S_HSIOM_REG   (*(reg32 *) i2c_master_miso_s__0__HSIOM)
    #define i2c_master_MISO_S_HSIOM_PTR   ( (reg32 *) i2c_master_miso_s__0__HSIOM)
    
    #define i2c_master_MISO_S_HSIOM_MASK      (i2c_master_miso_s__0__HSIOM_MASK)
    #define i2c_master_MISO_S_HSIOM_POS       (i2c_master_miso_s__0__HSIOM_SHIFT)
    #define i2c_master_MISO_S_HSIOM_SEL_GPIO  (i2c_master_miso_s__0__HSIOM_GPIO)
    #define i2c_master_MISO_S_HSIOM_SEL_SPI   (i2c_master_miso_s__0__HSIOM_SPI)
#endif /* (i2c_master_SPI_SLAVE_MISO_PIN) */

#if (i2c_master_SPI_MASTER_MISO_PIN)
    #define i2c_master_MISO_M_HSIOM_REG   (*(reg32 *) i2c_master_miso_m__0__HSIOM)
    #define i2c_master_MISO_M_HSIOM_PTR   ( (reg32 *) i2c_master_miso_m__0__HSIOM)
    
    #define i2c_master_MISO_M_HSIOM_MASK      (i2c_master_miso_m__0__HSIOM_MASK)
    #define i2c_master_MISO_M_HSIOM_POS       (i2c_master_miso_m__0__HSIOM_SHIFT)
    #define i2c_master_MISO_M_HSIOM_SEL_GPIO  (i2c_master_miso_m__0__HSIOM_GPIO)
    #define i2c_master_MISO_M_HSIOM_SEL_SPI   (i2c_master_miso_m__0__HSIOM_SPI)
#endif /* (i2c_master_SPI_MASTER_MISO_PIN) */

#if (i2c_master_SPI_MASTER_MOSI_PIN)
    #define i2c_master_MOSI_M_HSIOM_REG   (*(reg32 *) i2c_master_mosi_m__0__HSIOM)
    #define i2c_master_MOSI_M_HSIOM_PTR   ( (reg32 *) i2c_master_mosi_m__0__HSIOM)
    
    #define i2c_master_MOSI_M_HSIOM_MASK      (i2c_master_mosi_m__0__HSIOM_MASK)
    #define i2c_master_MOSI_M_HSIOM_POS       (i2c_master_mosi_m__0__HSIOM_SHIFT)
    #define i2c_master_MOSI_M_HSIOM_SEL_GPIO  (i2c_master_mosi_m__0__HSIOM_GPIO)
    #define i2c_master_MOSI_M_HSIOM_SEL_SPI   (i2c_master_mosi_m__0__HSIOM_SPI)
#endif /* (i2c_master_SPI_MASTER_MOSI_PIN) */

#if (i2c_master_SPI_MASTER_SCLK_PIN)
    #define i2c_master_SCLK_M_HSIOM_REG   (*(reg32 *) i2c_master_sclk_m__0__HSIOM)
    #define i2c_master_SCLK_M_HSIOM_PTR   ( (reg32 *) i2c_master_sclk_m__0__HSIOM)
    
    #define i2c_master_SCLK_M_HSIOM_MASK      (i2c_master_sclk_m__0__HSIOM_MASK)
    #define i2c_master_SCLK_M_HSIOM_POS       (i2c_master_sclk_m__0__HSIOM_SHIFT)
    #define i2c_master_SCLK_M_HSIOM_SEL_GPIO  (i2c_master_sclk_m__0__HSIOM_GPIO)
    #define i2c_master_SCLK_M_HSIOM_SEL_SPI   (i2c_master_sclk_m__0__HSIOM_SPI)
#endif /* (i2c_master_SPI_MASTER_SCLK_PIN) */

#if (i2c_master_SPI_MASTER_SS0_PIN)
    #define i2c_master_SS0_M_HSIOM_REG    (*(reg32 *) i2c_master_ss0_m__0__HSIOM)
    #define i2c_master_SS0_M_HSIOM_PTR    ( (reg32 *) i2c_master_ss0_m__0__HSIOM)
    
    #define i2c_master_SS0_M_HSIOM_MASK       (i2c_master_ss0_m__0__HSIOM_MASK)
    #define i2c_master_SS0_M_HSIOM_POS        (i2c_master_ss0_m__0__HSIOM_SHIFT)
    #define i2c_master_SS0_M_HSIOM_SEL_GPIO   (i2c_master_ss0_m__0__HSIOM_GPIO)
    #define i2c_master_SS0_M_HSIOM_SEL_SPI    (i2c_master_ss0_m__0__HSIOM_SPI)
#endif /* (i2c_master_SPI_MASTER_SS0_PIN) */

#if (i2c_master_SPI_MASTER_SS1_PIN)
    #define i2c_master_SS1_M_HSIOM_REG    (*(reg32 *) i2c_master_ss1_m__0__HSIOM)
    #define i2c_master_SS1_M_HSIOM_PTR    ( (reg32 *) i2c_master_ss1_m__0__HSIOM)
    
    #define i2c_master_SS1_M_HSIOM_MASK       (i2c_master_ss1_m__0__HSIOM_MASK)
    #define i2c_master_SS1_M_HSIOM_POS        (i2c_master_ss1_m__0__HSIOM_SHIFT)
    #define i2c_master_SS1_M_HSIOM_SEL_GPIO   (i2c_master_ss1_m__0__HSIOM_GPIO)
    #define i2c_master_SS1_M_HSIOM_SEL_SPI    (i2c_master_ss1_m__0__HSIOM_SPI)
#endif /* (i2c_master_SPI_MASTER_SS1_PIN) */

#if (i2c_master_SPI_MASTER_SS2_PIN)
    #define i2c_master_SS2_M_HSIOM_REG    (*(reg32 *) i2c_master_ss2_m__0__HSIOM)
    #define i2c_master_SS2_M_HSIOM_PTR    ( (reg32 *) i2c_master_ss2_m__0__HSIOM)
    
    #define i2c_master_SS2_M_HSIOM_MASK       (i2c_master_ss2_m__0__HSIOM_MASK)
    #define i2c_master_SS2_M_HSIOM_POS        (i2c_master_ss2_m__0__HSIOM_SHIFT)
    #define i2c_master_SS2_M_HSIOM_SEL_GPIO   (i2c_master_ss2_m__0__HSIOM_GPIO)
    #define i2c_master_SS2_M_HSIOM_SEL_SPI    (i2c_master_ss2_m__0__HSIOM_SPI)
#endif /* (i2c_master_SPI_MASTER_SS2_PIN) */

#if (i2c_master_SPI_MASTER_SS3_PIN)
    #define i2c_master_SS3_M_HSIOM_REG    (*(reg32 *) i2c_master_ss3_m__0__HSIOM)
    #define i2c_master_SS3_M_HSIOM_PTR    ( (reg32 *) i2c_master_ss3_m__0__HSIOM)
    
    #define i2c_master_SS3_M_HSIOM_MASK      (i2c_master_ss3_m__0__HSIOM_MASK)
    #define i2c_master_SS3_M_HSIOM_POS       (i2c_master_ss3_m__0__HSIOM_SHIFT)
    #define i2c_master_SS3_M_HSIOM_SEL_GPIO  (i2c_master_ss3_m__0__HSIOM_GPIO)
    #define i2c_master_SS3_M_HSIOM_SEL_SPI   (i2c_master_ss3_m__0__HSIOM_SPI)
#endif /* (i2c_master_SPI_MASTER_SS3_PIN) */

#if (i2c_master_UART_RX_PIN)
    #define i2c_master_RX_HSIOM_REG   (*(reg32 *) i2c_master_rx__0__HSIOM)
    #define i2c_master_RX_HSIOM_PTR   ( (reg32 *) i2c_master_rx__0__HSIOM)
    
    #define i2c_master_RX_HSIOM_MASK      (i2c_master_rx__0__HSIOM_MASK)
    #define i2c_master_RX_HSIOM_POS       (i2c_master_rx__0__HSIOM_SHIFT)
    #define i2c_master_RX_HSIOM_SEL_GPIO  (i2c_master_rx__0__HSIOM_GPIO)
    #define i2c_master_RX_HSIOM_SEL_UART  (i2c_master_rx__0__HSIOM_UART)
#endif /* (i2c_master_UART_RX_PIN) */

#if (i2c_master_UART_RX_WAKE_PIN)
    #define i2c_master_RX_WAKE_HSIOM_REG   (*(reg32 *) i2c_master_rx_wake__0__HSIOM)
    #define i2c_master_RX_WAKE_HSIOM_PTR   ( (reg32 *) i2c_master_rx_wake__0__HSIOM)
    
    #define i2c_master_RX_WAKE_HSIOM_MASK      (i2c_master_rx_wake__0__HSIOM_MASK)
    #define i2c_master_RX_WAKE_HSIOM_POS       (i2c_master_rx_wake__0__HSIOM_SHIFT)
    #define i2c_master_RX_WAKE_HSIOM_SEL_GPIO  (i2c_master_rx_wake__0__HSIOM_GPIO)
    #define i2c_master_RX_WAKE_HSIOM_SEL_UART  (i2c_master_rx_wake__0__HSIOM_UART)
#endif /* (i2c_master_UART_WAKE_RX_PIN) */

#if (i2c_master_UART_CTS_PIN)
    #define i2c_master_CTS_HSIOM_REG   (*(reg32 *) i2c_master_cts__0__HSIOM)
    #define i2c_master_CTS_HSIOM_PTR   ( (reg32 *) i2c_master_cts__0__HSIOM)
    
    #define i2c_master_CTS_HSIOM_MASK      (i2c_master_cts__0__HSIOM_MASK)
    #define i2c_master_CTS_HSIOM_POS       (i2c_master_cts__0__HSIOM_SHIFT)
    #define i2c_master_CTS_HSIOM_SEL_GPIO  (i2c_master_cts__0__HSIOM_GPIO)
    #define i2c_master_CTS_HSIOM_SEL_UART  (i2c_master_cts__0__HSIOM_UART)
#endif /* (i2c_master_UART_CTS_PIN) */

#if (i2c_master_UART_TX_PIN)
    #define i2c_master_TX_HSIOM_REG   (*(reg32 *) i2c_master_tx__0__HSIOM)
    #define i2c_master_TX_HSIOM_PTR   ( (reg32 *) i2c_master_tx__0__HSIOM)
    
    #define i2c_master_TX_HSIOM_MASK      (i2c_master_tx__0__HSIOM_MASK)
    #define i2c_master_TX_HSIOM_POS       (i2c_master_tx__0__HSIOM_SHIFT)
    #define i2c_master_TX_HSIOM_SEL_GPIO  (i2c_master_tx__0__HSIOM_GPIO)
    #define i2c_master_TX_HSIOM_SEL_UART  (i2c_master_tx__0__HSIOM_UART)
#endif /* (i2c_master_UART_TX_PIN) */

#if (i2c_master_UART_RX_TX_PIN)
    #define i2c_master_RX_TX_HSIOM_REG   (*(reg32 *) i2c_master_rx_tx__0__HSIOM)
    #define i2c_master_RX_TX_HSIOM_PTR   ( (reg32 *) i2c_master_rx_tx__0__HSIOM)
    
    #define i2c_master_RX_TX_HSIOM_MASK      (i2c_master_rx_tx__0__HSIOM_MASK)
    #define i2c_master_RX_TX_HSIOM_POS       (i2c_master_rx_tx__0__HSIOM_SHIFT)
    #define i2c_master_RX_TX_HSIOM_SEL_GPIO  (i2c_master_rx_tx__0__HSIOM_GPIO)
    #define i2c_master_RX_TX_HSIOM_SEL_UART  (i2c_master_rx_tx__0__HSIOM_UART)
#endif /* (i2c_master_UART_RX_TX_PIN) */

#if (i2c_master_UART_RTS_PIN)
    #define i2c_master_RTS_HSIOM_REG      (*(reg32 *) i2c_master_rts__0__HSIOM)
    #define i2c_master_RTS_HSIOM_PTR      ( (reg32 *) i2c_master_rts__0__HSIOM)
    
    #define i2c_master_RTS_HSIOM_MASK     (i2c_master_rts__0__HSIOM_MASK)
    #define i2c_master_RTS_HSIOM_POS      (i2c_master_rts__0__HSIOM_SHIFT)    
    #define i2c_master_RTS_HSIOM_SEL_GPIO (i2c_master_rts__0__HSIOM_GPIO)
    #define i2c_master_RTS_HSIOM_SEL_UART (i2c_master_rts__0__HSIOM_UART)    
#endif /* (i2c_master_UART_RTS_PIN) */


/***************************************
*        Registers Constants
***************************************/

/* HSIOM switch values. */ 
#define i2c_master_HSIOM_DEF_SEL      (0x00u)
#define i2c_master_HSIOM_GPIO_SEL     (0x00u)
/* The HSIOM values provided below are valid only for i2c_master_CY_SCBIP_V0 
* and i2c_master_CY_SCBIP_V1. It is not recommended to use them for 
* i2c_master_CY_SCBIP_V2. Use pin name specific HSIOM constants provided 
* above instead for any SCB IP block version.
*/
#define i2c_master_HSIOM_UART_SEL     (0x09u)
#define i2c_master_HSIOM_I2C_SEL      (0x0Eu)
#define i2c_master_HSIOM_SPI_SEL      (0x0Fu)

/* Pins settings index. */
#define i2c_master_RX_WAKE_SCL_MOSI_PIN_INDEX   (0u)
#define i2c_master_RX_SCL_MOSI_PIN_INDEX       (0u)
#define i2c_master_TX_SDA_MISO_PIN_INDEX       (1u)
#define i2c_master_SCLK_PIN_INDEX       (2u)
#define i2c_master_SS0_PIN_INDEX       (3u)
#define i2c_master_SS1_PIN_INDEX                  (4u)
#define i2c_master_SS2_PIN_INDEX                  (5u)
#define i2c_master_SS3_PIN_INDEX                  (6u)

/* Pins settings mask. */
#define i2c_master_RX_WAKE_SCL_MOSI_PIN_MASK ((uint32) 0x01u << i2c_master_RX_WAKE_SCL_MOSI_PIN_INDEX)
#define i2c_master_RX_SCL_MOSI_PIN_MASK     ((uint32) 0x01u << i2c_master_RX_SCL_MOSI_PIN_INDEX)
#define i2c_master_TX_SDA_MISO_PIN_MASK     ((uint32) 0x01u << i2c_master_TX_SDA_MISO_PIN_INDEX)
#define i2c_master_SCLK_PIN_MASK     ((uint32) 0x01u << i2c_master_SCLK_PIN_INDEX)
#define i2c_master_SS0_PIN_MASK     ((uint32) 0x01u << i2c_master_SS0_PIN_INDEX)
#define i2c_master_SS1_PIN_MASK                ((uint32) 0x01u << i2c_master_SS1_PIN_INDEX)
#define i2c_master_SS2_PIN_MASK                ((uint32) 0x01u << i2c_master_SS2_PIN_INDEX)
#define i2c_master_SS3_PIN_MASK                ((uint32) 0x01u << i2c_master_SS3_PIN_INDEX)

/* Pin interrupt constants. */
#define i2c_master_INTCFG_TYPE_MASK           (0x03u)
#define i2c_master_INTCFG_TYPE_FALLING_EDGE   (0x02u)

/* Pin Drive Mode constants. */
#define i2c_master_PIN_DM_ALG_HIZ  (0u)
#define i2c_master_PIN_DM_DIG_HIZ  (1u)
#define i2c_master_PIN_DM_OD_LO    (4u)
#define i2c_master_PIN_DM_STRONG   (6u)


/***************************************
*          Macro Definitions
***************************************/

/* Return drive mode of the pin */
#define i2c_master_DM_MASK    (0x7u)
#define i2c_master_DM_SIZE    (3u)
#define i2c_master_GET_P4_PIN_DM(reg, pos) \
    ( ((reg) & (uint32) ((uint32) i2c_master_DM_MASK << (i2c_master_DM_SIZE * (pos)))) >> \
                                                              (i2c_master_DM_SIZE * (pos)) )

#if (i2c_master_TX_SDA_MISO_PIN)
    #define i2c_master_CHECK_TX_SDA_MISO_PIN_USED \
                (i2c_master_PIN_DM_ALG_HIZ != \
                    i2c_master_GET_P4_PIN_DM(i2c_master_uart_tx_i2c_sda_spi_miso_PC, \
                                                   i2c_master_uart_tx_i2c_sda_spi_miso_SHIFT))
#endif /* (i2c_master_TX_SDA_MISO_PIN) */

#if (i2c_master_SS0_PIN)
    #define i2c_master_CHECK_SS0_PIN_USED \
                (i2c_master_PIN_DM_ALG_HIZ != \
                    i2c_master_GET_P4_PIN_DM(i2c_master_spi_ss0_PC, \
                                                   i2c_master_spi_ss0_SHIFT))
#endif /* (i2c_master_SS0_PIN) */

/* Set bits-mask in register */
#define i2c_master_SET_REGISTER_BITS(reg, mask, pos, mode) \
                    do                                           \
                    {                                            \
                        (reg) = (((reg) & ((uint32) ~(uint32) (mask))) | ((uint32) ((uint32) (mode) << (pos)))); \
                    }while(0)

/* Set bit in the register */
#define i2c_master_SET_REGISTER_BIT(reg, mask, val) \
                    ((val) ? ((reg) |= (mask)) : ((reg) &= ((uint32) ~((uint32) (mask)))))

#define i2c_master_SET_HSIOM_SEL(reg, mask, pos, sel) i2c_master_SET_REGISTER_BITS(reg, mask, pos, sel)
#define i2c_master_SET_INCFG_TYPE(reg, mask, pos, intType) \
                                                        i2c_master_SET_REGISTER_BITS(reg, mask, pos, intType)
#define i2c_master_SET_INP_DIS(reg, mask, val) i2c_master_SET_REGISTER_BIT(reg, mask, val)

/* i2c_master_SET_I2C_SCL_DR(val) - Sets I2C SCL DR register.
*  i2c_master_SET_I2C_SCL_HSIOM_SEL(sel) - Sets I2C SCL HSIOM settings.
*/
/* SCB I2C: scl signal */
#if (i2c_master_CY_SCBIP_V0)
#if (i2c_master_I2C_PINS)
    #define i2c_master_SET_I2C_SCL_DR(val) i2c_master_scl_Write(val)

    #define i2c_master_SET_I2C_SCL_HSIOM_SEL(sel) \
                          i2c_master_SET_HSIOM_SEL(i2c_master_SCL_HSIOM_REG,  \
                                                         i2c_master_SCL_HSIOM_MASK, \
                                                         i2c_master_SCL_HSIOM_POS,  \
                                                         (sel))
    #define i2c_master_WAIT_SCL_SET_HIGH  (0u == i2c_master_scl_Read())

/* Unconfigured SCB: scl signal */
#elif (i2c_master_RX_WAKE_SCL_MOSI_PIN)
    #define i2c_master_SET_I2C_SCL_DR(val) \
                            i2c_master_uart_rx_wake_i2c_scl_spi_mosi_Write(val)

    #define i2c_master_SET_I2C_SCL_HSIOM_SEL(sel) \
                    i2c_master_SET_HSIOM_SEL(i2c_master_RX_WAKE_SCL_MOSI_HSIOM_REG,  \
                                                   i2c_master_RX_WAKE_SCL_MOSI_HSIOM_MASK, \
                                                   i2c_master_RX_WAKE_SCL_MOSI_HSIOM_POS,  \
                                                   (sel))

    #define i2c_master_WAIT_SCL_SET_HIGH  (0u == i2c_master_uart_rx_wake_i2c_scl_spi_mosi_Read())

#elif (i2c_master_RX_SCL_MOSI_PIN)
    #define i2c_master_SET_I2C_SCL_DR(val) \
                            i2c_master_uart_rx_i2c_scl_spi_mosi_Write(val)


    #define i2c_master_SET_I2C_SCL_HSIOM_SEL(sel) \
                            i2c_master_SET_HSIOM_SEL(i2c_master_RX_SCL_MOSI_HSIOM_REG,  \
                                                           i2c_master_RX_SCL_MOSI_HSIOM_MASK, \
                                                           i2c_master_RX_SCL_MOSI_HSIOM_POS,  \
                                                           (sel))

    #define i2c_master_WAIT_SCL_SET_HIGH  (0u == i2c_master_uart_rx_i2c_scl_spi_mosi_Read())

#else
    #define i2c_master_SET_I2C_SCL_DR(val)        do{ /* Does nothing */ }while(0)
    #define i2c_master_SET_I2C_SCL_HSIOM_SEL(sel) do{ /* Does nothing */ }while(0)

    #define i2c_master_WAIT_SCL_SET_HIGH  (0u)
#endif /* (i2c_master_I2C_PINS) */

/* SCB I2C: sda signal */
#if (i2c_master_I2C_PINS)
    #define i2c_master_WAIT_SDA_SET_HIGH  (0u == i2c_master_sda_Read())
/* Unconfigured SCB: sda signal */
#elif (i2c_master_TX_SDA_MISO_PIN)
    #define i2c_master_WAIT_SDA_SET_HIGH  (0u == i2c_master_uart_tx_i2c_sda_spi_miso_Read())
#else
    #define i2c_master_WAIT_SDA_SET_HIGH  (0u)
#endif /* (i2c_master_MOSI_SCL_RX_PIN) */
#endif /* (i2c_master_CY_SCBIP_V0) */

/* Clear UART wakeup source */
#if (i2c_master_RX_SCL_MOSI_PIN)
    #define i2c_master_CLEAR_UART_RX_WAKE_INTR        do{ /* Does nothing */ }while(0)
    
#elif (i2c_master_RX_WAKE_SCL_MOSI_PIN)
    #define i2c_master_CLEAR_UART_RX_WAKE_INTR \
            do{                                      \
                (void) i2c_master_uart_rx_wake_i2c_scl_spi_mosi_ClearInterrupt(); \
            }while(0)

#elif(i2c_master_UART_RX_WAKE_PIN)
    #define i2c_master_CLEAR_UART_RX_WAKE_INTR \
            do{                                      \
                (void) i2c_master_rx_wake_ClearInterrupt(); \
            }while(0)
#else
#endif /* (i2c_master_RX_SCL_MOSI_PIN) */


/***************************************
* The following code is DEPRECATED and
* must not be used.
***************************************/

/* Unconfigured pins */
#define i2c_master_REMOVE_MOSI_SCL_RX_WAKE_PIN    i2c_master_REMOVE_RX_WAKE_SCL_MOSI_PIN
#define i2c_master_REMOVE_MOSI_SCL_RX_PIN         i2c_master_REMOVE_RX_SCL_MOSI_PIN
#define i2c_master_REMOVE_MISO_SDA_TX_PIN         i2c_master_REMOVE_TX_SDA_MISO_PIN
#ifndef i2c_master_REMOVE_SCLK_PIN
#define i2c_master_REMOVE_SCLK_PIN                i2c_master_REMOVE_SCLK_PIN
#endif /* i2c_master_REMOVE_SCLK_PIN */
#ifndef i2c_master_REMOVE_SS0_PIN
#define i2c_master_REMOVE_SS0_PIN                 i2c_master_REMOVE_SS0_PIN
#endif /* i2c_master_REMOVE_SS0_PIN */

/* Unconfigured pins */
#define i2c_master_MOSI_SCL_RX_WAKE_PIN   i2c_master_RX_WAKE_SCL_MOSI_PIN
#define i2c_master_MOSI_SCL_RX_PIN        i2c_master_RX_SCL_MOSI_PIN
#define i2c_master_MISO_SDA_TX_PIN        i2c_master_TX_SDA_MISO_PIN
#ifndef i2c_master_SCLK_PIN
#define i2c_master_SCLK_PIN               i2c_master_SCLK_PIN
#endif /* i2c_master_SCLK_PIN */
#ifndef i2c_master_SS0_PIN
#define i2c_master_SS0_PIN                i2c_master_SS0_PIN
#endif /* i2c_master_SS0_PIN */

#if (i2c_master_MOSI_SCL_RX_WAKE_PIN)
    #define i2c_master_MOSI_SCL_RX_WAKE_HSIOM_REG     i2c_master_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define i2c_master_MOSI_SCL_RX_WAKE_HSIOM_PTR     i2c_master_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define i2c_master_MOSI_SCL_RX_WAKE_HSIOM_MASK    i2c_master_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define i2c_master_MOSI_SCL_RX_WAKE_HSIOM_POS     i2c_master_RX_WAKE_SCL_MOSI_HSIOM_REG

    #define i2c_master_MOSI_SCL_RX_WAKE_INTCFG_REG    i2c_master_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define i2c_master_MOSI_SCL_RX_WAKE_INTCFG_PTR    i2c_master_RX_WAKE_SCL_MOSI_HSIOM_REG

    #define i2c_master_MOSI_SCL_RX_WAKE_INTCFG_TYPE_POS   i2c_master_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define i2c_master_MOSI_SCL_RX_WAKE_INTCFG_TYPE_MASK  i2c_master_RX_WAKE_SCL_MOSI_HSIOM_REG
#endif /* (i2c_master_RX_WAKE_SCL_MOSI_PIN) */

#if (i2c_master_MOSI_SCL_RX_PIN)
    #define i2c_master_MOSI_SCL_RX_HSIOM_REG      i2c_master_RX_SCL_MOSI_HSIOM_REG
    #define i2c_master_MOSI_SCL_RX_HSIOM_PTR      i2c_master_RX_SCL_MOSI_HSIOM_PTR
    #define i2c_master_MOSI_SCL_RX_HSIOM_MASK     i2c_master_RX_SCL_MOSI_HSIOM_MASK
    #define i2c_master_MOSI_SCL_RX_HSIOM_POS      i2c_master_RX_SCL_MOSI_HSIOM_POS
#endif /* (i2c_master_MOSI_SCL_RX_PIN) */

#if (i2c_master_MISO_SDA_TX_PIN)
    #define i2c_master_MISO_SDA_TX_HSIOM_REG      i2c_master_TX_SDA_MISO_HSIOM_REG
    #define i2c_master_MISO_SDA_TX_HSIOM_PTR      i2c_master_TX_SDA_MISO_HSIOM_REG
    #define i2c_master_MISO_SDA_TX_HSIOM_MASK     i2c_master_TX_SDA_MISO_HSIOM_REG
    #define i2c_master_MISO_SDA_TX_HSIOM_POS      i2c_master_TX_SDA_MISO_HSIOM_REG
#endif /* (i2c_master_MISO_SDA_TX_PIN_PIN) */

#if (i2c_master_SCLK_PIN)
    #ifndef i2c_master_SCLK_HSIOM_REG
    #define i2c_master_SCLK_HSIOM_REG     i2c_master_SCLK_HSIOM_REG
    #define i2c_master_SCLK_HSIOM_PTR     i2c_master_SCLK_HSIOM_PTR
    #define i2c_master_SCLK_HSIOM_MASK    i2c_master_SCLK_HSIOM_MASK
    #define i2c_master_SCLK_HSIOM_POS     i2c_master_SCLK_HSIOM_POS
    #endif /* i2c_master_SCLK_HSIOM_REG */
#endif /* (i2c_master_SCLK_PIN) */

#if (i2c_master_SS0_PIN)
    #ifndef i2c_master_SS0_HSIOM_REG
    #define i2c_master_SS0_HSIOM_REG      i2c_master_SS0_HSIOM_REG
    #define i2c_master_SS0_HSIOM_PTR      i2c_master_SS0_HSIOM_PTR
    #define i2c_master_SS0_HSIOM_MASK     i2c_master_SS0_HSIOM_MASK
    #define i2c_master_SS0_HSIOM_POS      i2c_master_SS0_HSIOM_POS
    #endif /* i2c_master_SS0_HSIOM_REG */
#endif /* (i2c_master_SS0_PIN) */

#define i2c_master_MOSI_SCL_RX_WAKE_PIN_INDEX i2c_master_RX_WAKE_SCL_MOSI_PIN_INDEX
#define i2c_master_MOSI_SCL_RX_PIN_INDEX      i2c_master_RX_SCL_MOSI_PIN_INDEX
#define i2c_master_MISO_SDA_TX_PIN_INDEX      i2c_master_TX_SDA_MISO_PIN_INDEX
#ifndef i2c_master_SCLK_PIN_INDEX
#define i2c_master_SCLK_PIN_INDEX             i2c_master_SCLK_PIN_INDEX
#endif /* i2c_master_SCLK_PIN_INDEX */
#ifndef i2c_master_SS0_PIN_INDEX
#define i2c_master_SS0_PIN_INDEX              i2c_master_SS0_PIN_INDEX
#endif /* i2c_master_SS0_PIN_INDEX */

#define i2c_master_MOSI_SCL_RX_WAKE_PIN_MASK i2c_master_RX_WAKE_SCL_MOSI_PIN_MASK
#define i2c_master_MOSI_SCL_RX_PIN_MASK      i2c_master_RX_SCL_MOSI_PIN_MASK
#define i2c_master_MISO_SDA_TX_PIN_MASK      i2c_master_TX_SDA_MISO_PIN_MASK
#ifndef i2c_master_SCLK_PIN_MASK
#define i2c_master_SCLK_PIN_MASK             i2c_master_SCLK_PIN_MASK
#endif /* i2c_master_SCLK_PIN_MASK */
#ifndef i2c_master_SS0_PIN_MASK
#define i2c_master_SS0_PIN_MASK              i2c_master_SS0_PIN_MASK
#endif /* i2c_master_SS0_PIN_MASK */

#endif /* (CY_SCB_PINS_i2c_master_H) */


/* [] END OF FILE */
