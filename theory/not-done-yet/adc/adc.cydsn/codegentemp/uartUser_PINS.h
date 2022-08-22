/***************************************************************************//**
* \file uartUser_PINS.h
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

#if !defined(CY_SCB_PINS_uartUser_H)
#define CY_SCB_PINS_uartUser_H

#include "cydevice_trm.h"
#include "cyfitter.h"
#include "cytypes.h"


/***************************************
*   Conditional Compilation Parameters
****************************************/

/* Unconfigured pins */
#define uartUser_REMOVE_RX_WAKE_SCL_MOSI_PIN  (1u)
#define uartUser_REMOVE_RX_SCL_MOSI_PIN      (1u)
#define uartUser_REMOVE_TX_SDA_MISO_PIN      (1u)
#define uartUser_REMOVE_SCLK_PIN      (1u)
#define uartUser_REMOVE_SS0_PIN      (1u)
#define uartUser_REMOVE_SS1_PIN                 (1u)
#define uartUser_REMOVE_SS2_PIN                 (1u)
#define uartUser_REMOVE_SS3_PIN                 (1u)

/* Mode defined pins */
#define uartUser_REMOVE_I2C_PINS                (1u)
#define uartUser_REMOVE_SPI_MASTER_PINS         (1u)
#define uartUser_REMOVE_SPI_MASTER_SCLK_PIN     (1u)
#define uartUser_REMOVE_SPI_MASTER_MOSI_PIN     (1u)
#define uartUser_REMOVE_SPI_MASTER_MISO_PIN     (1u)
#define uartUser_REMOVE_SPI_MASTER_SS0_PIN      (1u)
#define uartUser_REMOVE_SPI_MASTER_SS1_PIN      (1u)
#define uartUser_REMOVE_SPI_MASTER_SS2_PIN      (1u)
#define uartUser_REMOVE_SPI_MASTER_SS3_PIN      (1u)
#define uartUser_REMOVE_SPI_SLAVE_PINS          (1u)
#define uartUser_REMOVE_SPI_SLAVE_MOSI_PIN      (1u)
#define uartUser_REMOVE_SPI_SLAVE_MISO_PIN      (1u)
#define uartUser_REMOVE_UART_TX_PIN             (0u)
#define uartUser_REMOVE_UART_RX_TX_PIN          (1u)
#define uartUser_REMOVE_UART_RX_PIN             (0u)
#define uartUser_REMOVE_UART_RX_WAKE_PIN        (1u)
#define uartUser_REMOVE_UART_RTS_PIN            (1u)
#define uartUser_REMOVE_UART_CTS_PIN            (1u)

/* Unconfigured pins */
#define uartUser_RX_WAKE_SCL_MOSI_PIN (0u == uartUser_REMOVE_RX_WAKE_SCL_MOSI_PIN)
#define uartUser_RX_SCL_MOSI_PIN     (0u == uartUser_REMOVE_RX_SCL_MOSI_PIN)
#define uartUser_TX_SDA_MISO_PIN     (0u == uartUser_REMOVE_TX_SDA_MISO_PIN)
#define uartUser_SCLK_PIN     (0u == uartUser_REMOVE_SCLK_PIN)
#define uartUser_SS0_PIN     (0u == uartUser_REMOVE_SS0_PIN)
#define uartUser_SS1_PIN                (0u == uartUser_REMOVE_SS1_PIN)
#define uartUser_SS2_PIN                (0u == uartUser_REMOVE_SS2_PIN)
#define uartUser_SS3_PIN                (0u == uartUser_REMOVE_SS3_PIN)

/* Mode defined pins */
#define uartUser_I2C_PINS               (0u == uartUser_REMOVE_I2C_PINS)
#define uartUser_SPI_MASTER_PINS        (0u == uartUser_REMOVE_SPI_MASTER_PINS)
#define uartUser_SPI_MASTER_SCLK_PIN    (0u == uartUser_REMOVE_SPI_MASTER_SCLK_PIN)
#define uartUser_SPI_MASTER_MOSI_PIN    (0u == uartUser_REMOVE_SPI_MASTER_MOSI_PIN)
#define uartUser_SPI_MASTER_MISO_PIN    (0u == uartUser_REMOVE_SPI_MASTER_MISO_PIN)
#define uartUser_SPI_MASTER_SS0_PIN     (0u == uartUser_REMOVE_SPI_MASTER_SS0_PIN)
#define uartUser_SPI_MASTER_SS1_PIN     (0u == uartUser_REMOVE_SPI_MASTER_SS1_PIN)
#define uartUser_SPI_MASTER_SS2_PIN     (0u == uartUser_REMOVE_SPI_MASTER_SS2_PIN)
#define uartUser_SPI_MASTER_SS3_PIN     (0u == uartUser_REMOVE_SPI_MASTER_SS3_PIN)
#define uartUser_SPI_SLAVE_PINS         (0u == uartUser_REMOVE_SPI_SLAVE_PINS)
#define uartUser_SPI_SLAVE_MOSI_PIN     (0u == uartUser_REMOVE_SPI_SLAVE_MOSI_PIN)
#define uartUser_SPI_SLAVE_MISO_PIN     (0u == uartUser_REMOVE_SPI_SLAVE_MISO_PIN)
#define uartUser_UART_TX_PIN            (0u == uartUser_REMOVE_UART_TX_PIN)
#define uartUser_UART_RX_TX_PIN         (0u == uartUser_REMOVE_UART_RX_TX_PIN)
#define uartUser_UART_RX_PIN            (0u == uartUser_REMOVE_UART_RX_PIN)
#define uartUser_UART_RX_WAKE_PIN       (0u == uartUser_REMOVE_UART_RX_WAKE_PIN)
#define uartUser_UART_RTS_PIN           (0u == uartUser_REMOVE_UART_RTS_PIN)
#define uartUser_UART_CTS_PIN           (0u == uartUser_REMOVE_UART_CTS_PIN)


/***************************************
*             Includes
****************************************/

#if (uartUser_RX_WAKE_SCL_MOSI_PIN)
    #include "uartUser_uart_rx_wake_i2c_scl_spi_mosi.h"
#endif /* (uartUser_RX_SCL_MOSI) */

#if (uartUser_RX_SCL_MOSI_PIN)
    #include "uartUser_uart_rx_i2c_scl_spi_mosi.h"
#endif /* (uartUser_RX_SCL_MOSI) */

#if (uartUser_TX_SDA_MISO_PIN)
    #include "uartUser_uart_tx_i2c_sda_spi_miso.h"
#endif /* (uartUser_TX_SDA_MISO) */

#if (uartUser_SCLK_PIN)
    #include "uartUser_spi_sclk.h"
#endif /* (uartUser_SCLK) */

#if (uartUser_SS0_PIN)
    #include "uartUser_spi_ss0.h"
#endif /* (uartUser_SS0_PIN) */

#if (uartUser_SS1_PIN)
    #include "uartUser_spi_ss1.h"
#endif /* (uartUser_SS1_PIN) */

#if (uartUser_SS2_PIN)
    #include "uartUser_spi_ss2.h"
#endif /* (uartUser_SS2_PIN) */

#if (uartUser_SS3_PIN)
    #include "uartUser_spi_ss3.h"
#endif /* (uartUser_SS3_PIN) */

#if (uartUser_I2C_PINS)
    #include "uartUser_scl.h"
    #include "uartUser_sda.h"
#endif /* (uartUser_I2C_PINS) */

#if (uartUser_SPI_MASTER_PINS)
#if (uartUser_SPI_MASTER_SCLK_PIN)
    #include "uartUser_sclk_m.h"
#endif /* (uartUser_SPI_MASTER_SCLK_PIN) */

#if (uartUser_SPI_MASTER_MOSI_PIN)
    #include "uartUser_mosi_m.h"
#endif /* (uartUser_SPI_MASTER_MOSI_PIN) */

#if (uartUser_SPI_MASTER_MISO_PIN)
    #include "uartUser_miso_m.h"
#endif /*(uartUser_SPI_MASTER_MISO_PIN) */
#endif /* (uartUser_SPI_MASTER_PINS) */

#if (uartUser_SPI_SLAVE_PINS)
    #include "uartUser_sclk_s.h"
    #include "uartUser_ss_s.h"

#if (uartUser_SPI_SLAVE_MOSI_PIN)
    #include "uartUser_mosi_s.h"
#endif /* (uartUser_SPI_SLAVE_MOSI_PIN) */

#if (uartUser_SPI_SLAVE_MISO_PIN)
    #include "uartUser_miso_s.h"
#endif /*(uartUser_SPI_SLAVE_MISO_PIN) */
#endif /* (uartUser_SPI_SLAVE_PINS) */

#if (uartUser_SPI_MASTER_SS0_PIN)
    #include "uartUser_ss0_m.h"
#endif /* (uartUser_SPI_MASTER_SS0_PIN) */

#if (uartUser_SPI_MASTER_SS1_PIN)
    #include "uartUser_ss1_m.h"
#endif /* (uartUser_SPI_MASTER_SS1_PIN) */

#if (uartUser_SPI_MASTER_SS2_PIN)
    #include "uartUser_ss2_m.h"
#endif /* (uartUser_SPI_MASTER_SS2_PIN) */

#if (uartUser_SPI_MASTER_SS3_PIN)
    #include "uartUser_ss3_m.h"
#endif /* (uartUser_SPI_MASTER_SS3_PIN) */

#if (uartUser_UART_TX_PIN)
    #include "uartUser_tx.h"
#endif /* (uartUser_UART_TX_PIN) */

#if (uartUser_UART_RX_TX_PIN)
    #include "uartUser_rx_tx.h"
#endif /* (uartUser_UART_RX_TX_PIN) */

#if (uartUser_UART_RX_PIN)
    #include "uartUser_rx.h"
#endif /* (uartUser_UART_RX_PIN) */

#if (uartUser_UART_RX_WAKE_PIN)
    #include "uartUser_rx_wake.h"
#endif /* (uartUser_UART_RX_WAKE_PIN) */

#if (uartUser_UART_RTS_PIN)
    #include "uartUser_rts.h"
#endif /* (uartUser_UART_RTS_PIN) */

#if (uartUser_UART_CTS_PIN)
    #include "uartUser_cts.h"
#endif /* (uartUser_UART_CTS_PIN) */


/***************************************
*              Registers
***************************************/

#if (uartUser_RX_SCL_MOSI_PIN)
    #define uartUser_RX_SCL_MOSI_HSIOM_REG   (*(reg32 *) uartUser_uart_rx_i2c_scl_spi_mosi__0__HSIOM)
    #define uartUser_RX_SCL_MOSI_HSIOM_PTR   ( (reg32 *) uartUser_uart_rx_i2c_scl_spi_mosi__0__HSIOM)
    
    #define uartUser_RX_SCL_MOSI_HSIOM_MASK      (uartUser_uart_rx_i2c_scl_spi_mosi__0__HSIOM_MASK)
    #define uartUser_RX_SCL_MOSI_HSIOM_POS       (uartUser_uart_rx_i2c_scl_spi_mosi__0__HSIOM_SHIFT)
    #define uartUser_RX_SCL_MOSI_HSIOM_SEL_GPIO  (uartUser_uart_rx_i2c_scl_spi_mosi__0__HSIOM_GPIO)
    #define uartUser_RX_SCL_MOSI_HSIOM_SEL_I2C   (uartUser_uart_rx_i2c_scl_spi_mosi__0__HSIOM_I2C)
    #define uartUser_RX_SCL_MOSI_HSIOM_SEL_SPI   (uartUser_uart_rx_i2c_scl_spi_mosi__0__HSIOM_SPI)
    #define uartUser_RX_SCL_MOSI_HSIOM_SEL_UART  (uartUser_uart_rx_i2c_scl_spi_mosi__0__HSIOM_UART)
    
#elif (uartUser_RX_WAKE_SCL_MOSI_PIN)
    #define uartUser_RX_WAKE_SCL_MOSI_HSIOM_REG   (*(reg32 *) uartUser_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM)
    #define uartUser_RX_WAKE_SCL_MOSI_HSIOM_PTR   ( (reg32 *) uartUser_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM)
    
    #define uartUser_RX_WAKE_SCL_MOSI_HSIOM_MASK      (uartUser_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_MASK)
    #define uartUser_RX_WAKE_SCL_MOSI_HSIOM_POS       (uartUser_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_SHIFT)
    #define uartUser_RX_WAKE_SCL_MOSI_HSIOM_SEL_GPIO  (uartUser_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_GPIO)
    #define uartUser_RX_WAKE_SCL_MOSI_HSIOM_SEL_I2C   (uartUser_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_I2C)
    #define uartUser_RX_WAKE_SCL_MOSI_HSIOM_SEL_SPI   (uartUser_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_SPI)
    #define uartUser_RX_WAKE_SCL_MOSI_HSIOM_SEL_UART  (uartUser_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_UART)    
   
    #define uartUser_RX_WAKE_SCL_MOSI_INTCFG_REG (*(reg32 *) uartUser_uart_rx_wake_i2c_scl_spi_mosi__0__INTCFG)
    #define uartUser_RX_WAKE_SCL_MOSI_INTCFG_PTR ( (reg32 *) uartUser_uart_rx_wake_i2c_scl_spi_mosi__0__INTCFG)
    #define uartUser_RX_WAKE_SCL_MOSI_INTCFG_TYPE_POS  (uartUser_uart_rx_wake_i2c_scl_spi_mosi__SHIFT)
    #define uartUser_RX_WAKE_SCL_MOSI_INTCFG_TYPE_MASK ((uint32) uartUser_INTCFG_TYPE_MASK << \
                                                                           uartUser_RX_WAKE_SCL_MOSI_INTCFG_TYPE_POS)
#else
    /* None of pins uartUser_RX_SCL_MOSI_PIN or uartUser_RX_WAKE_SCL_MOSI_PIN present.*/
#endif /* (uartUser_RX_SCL_MOSI_PIN) */

#if (uartUser_TX_SDA_MISO_PIN)
    #define uartUser_TX_SDA_MISO_HSIOM_REG   (*(reg32 *) uartUser_uart_tx_i2c_sda_spi_miso__0__HSIOM)
    #define uartUser_TX_SDA_MISO_HSIOM_PTR   ( (reg32 *) uartUser_uart_tx_i2c_sda_spi_miso__0__HSIOM)
    
    #define uartUser_TX_SDA_MISO_HSIOM_MASK      (uartUser_uart_tx_i2c_sda_spi_miso__0__HSIOM_MASK)
    #define uartUser_TX_SDA_MISO_HSIOM_POS       (uartUser_uart_tx_i2c_sda_spi_miso__0__HSIOM_SHIFT)
    #define uartUser_TX_SDA_MISO_HSIOM_SEL_GPIO  (uartUser_uart_tx_i2c_sda_spi_miso__0__HSIOM_GPIO)
    #define uartUser_TX_SDA_MISO_HSIOM_SEL_I2C   (uartUser_uart_tx_i2c_sda_spi_miso__0__HSIOM_I2C)
    #define uartUser_TX_SDA_MISO_HSIOM_SEL_SPI   (uartUser_uart_tx_i2c_sda_spi_miso__0__HSIOM_SPI)
    #define uartUser_TX_SDA_MISO_HSIOM_SEL_UART  (uartUser_uart_tx_i2c_sda_spi_miso__0__HSIOM_UART)
#endif /* (uartUser_TX_SDA_MISO_PIN) */

#if (uartUser_SCLK_PIN)
    #define uartUser_SCLK_HSIOM_REG   (*(reg32 *) uartUser_spi_sclk__0__HSIOM)
    #define uartUser_SCLK_HSIOM_PTR   ( (reg32 *) uartUser_spi_sclk__0__HSIOM)
    
    #define uartUser_SCLK_HSIOM_MASK      (uartUser_spi_sclk__0__HSIOM_MASK)
    #define uartUser_SCLK_HSIOM_POS       (uartUser_spi_sclk__0__HSIOM_SHIFT)
    #define uartUser_SCLK_HSIOM_SEL_GPIO  (uartUser_spi_sclk__0__HSIOM_GPIO)
    #define uartUser_SCLK_HSIOM_SEL_I2C   (uartUser_spi_sclk__0__HSIOM_I2C)
    #define uartUser_SCLK_HSIOM_SEL_SPI   (uartUser_spi_sclk__0__HSIOM_SPI)
    #define uartUser_SCLK_HSIOM_SEL_UART  (uartUser_spi_sclk__0__HSIOM_UART)
#endif /* (uartUser_SCLK_PIN) */

#if (uartUser_SS0_PIN)
    #define uartUser_SS0_HSIOM_REG   (*(reg32 *) uartUser_spi_ss0__0__HSIOM)
    #define uartUser_SS0_HSIOM_PTR   ( (reg32 *) uartUser_spi_ss0__0__HSIOM)
    
    #define uartUser_SS0_HSIOM_MASK      (uartUser_spi_ss0__0__HSIOM_MASK)
    #define uartUser_SS0_HSIOM_POS       (uartUser_spi_ss0__0__HSIOM_SHIFT)
    #define uartUser_SS0_HSIOM_SEL_GPIO  (uartUser_spi_ss0__0__HSIOM_GPIO)
    #define uartUser_SS0_HSIOM_SEL_I2C   (uartUser_spi_ss0__0__HSIOM_I2C)
    #define uartUser_SS0_HSIOM_SEL_SPI   (uartUser_spi_ss0__0__HSIOM_SPI)
#if !(uartUser_CY_SCBIP_V0 || uartUser_CY_SCBIP_V1)
    #define uartUser_SS0_HSIOM_SEL_UART  (uartUser_spi_ss0__0__HSIOM_UART)
#endif /* !(uartUser_CY_SCBIP_V0 || uartUser_CY_SCBIP_V1) */
#endif /* (uartUser_SS0_PIN) */

#if (uartUser_SS1_PIN)
    #define uartUser_SS1_HSIOM_REG  (*(reg32 *) uartUser_spi_ss1__0__HSIOM)
    #define uartUser_SS1_HSIOM_PTR  ( (reg32 *) uartUser_spi_ss1__0__HSIOM)
    
    #define uartUser_SS1_HSIOM_MASK     (uartUser_spi_ss1__0__HSIOM_MASK)
    #define uartUser_SS1_HSIOM_POS      (uartUser_spi_ss1__0__HSIOM_SHIFT)
    #define uartUser_SS1_HSIOM_SEL_GPIO (uartUser_spi_ss1__0__HSIOM_GPIO)
    #define uartUser_SS1_HSIOM_SEL_I2C  (uartUser_spi_ss1__0__HSIOM_I2C)
    #define uartUser_SS1_HSIOM_SEL_SPI  (uartUser_spi_ss1__0__HSIOM_SPI)
#endif /* (uartUser_SS1_PIN) */

#if (uartUser_SS2_PIN)
    #define uartUser_SS2_HSIOM_REG     (*(reg32 *) uartUser_spi_ss2__0__HSIOM)
    #define uartUser_SS2_HSIOM_PTR     ( (reg32 *) uartUser_spi_ss2__0__HSIOM)
    
    #define uartUser_SS2_HSIOM_MASK     (uartUser_spi_ss2__0__HSIOM_MASK)
    #define uartUser_SS2_HSIOM_POS      (uartUser_spi_ss2__0__HSIOM_SHIFT)
    #define uartUser_SS2_HSIOM_SEL_GPIO (uartUser_spi_ss2__0__HSIOM_GPIO)
    #define uartUser_SS2_HSIOM_SEL_I2C  (uartUser_spi_ss2__0__HSIOM_I2C)
    #define uartUser_SS2_HSIOM_SEL_SPI  (uartUser_spi_ss2__0__HSIOM_SPI)
#endif /* (uartUser_SS2_PIN) */

#if (uartUser_SS3_PIN)
    #define uartUser_SS3_HSIOM_REG     (*(reg32 *) uartUser_spi_ss3__0__HSIOM)
    #define uartUser_SS3_HSIOM_PTR     ( (reg32 *) uartUser_spi_ss3__0__HSIOM)
    
    #define uartUser_SS3_HSIOM_MASK     (uartUser_spi_ss3__0__HSIOM_MASK)
    #define uartUser_SS3_HSIOM_POS      (uartUser_spi_ss3__0__HSIOM_SHIFT)
    #define uartUser_SS3_HSIOM_SEL_GPIO (uartUser_spi_ss3__0__HSIOM_GPIO)
    #define uartUser_SS3_HSIOM_SEL_I2C  (uartUser_spi_ss3__0__HSIOM_I2C)
    #define uartUser_SS3_HSIOM_SEL_SPI  (uartUser_spi_ss3__0__HSIOM_SPI)
#endif /* (uartUser_SS3_PIN) */

#if (uartUser_I2C_PINS)
    #define uartUser_SCL_HSIOM_REG  (*(reg32 *) uartUser_scl__0__HSIOM)
    #define uartUser_SCL_HSIOM_PTR  ( (reg32 *) uartUser_scl__0__HSIOM)
    
    #define uartUser_SCL_HSIOM_MASK     (uartUser_scl__0__HSIOM_MASK)
    #define uartUser_SCL_HSIOM_POS      (uartUser_scl__0__HSIOM_SHIFT)
    #define uartUser_SCL_HSIOM_SEL_GPIO (uartUser_sda__0__HSIOM_GPIO)
    #define uartUser_SCL_HSIOM_SEL_I2C  (uartUser_sda__0__HSIOM_I2C)
    
    #define uartUser_SDA_HSIOM_REG  (*(reg32 *) uartUser_sda__0__HSIOM)
    #define uartUser_SDA_HSIOM_PTR  ( (reg32 *) uartUser_sda__0__HSIOM)
    
    #define uartUser_SDA_HSIOM_MASK     (uartUser_sda__0__HSIOM_MASK)
    #define uartUser_SDA_HSIOM_POS      (uartUser_sda__0__HSIOM_SHIFT)
    #define uartUser_SDA_HSIOM_SEL_GPIO (uartUser_sda__0__HSIOM_GPIO)
    #define uartUser_SDA_HSIOM_SEL_I2C  (uartUser_sda__0__HSIOM_I2C)
#endif /* (uartUser_I2C_PINS) */

#if (uartUser_SPI_SLAVE_PINS)
    #define uartUser_SCLK_S_HSIOM_REG   (*(reg32 *) uartUser_sclk_s__0__HSIOM)
    #define uartUser_SCLK_S_HSIOM_PTR   ( (reg32 *) uartUser_sclk_s__0__HSIOM)
    
    #define uartUser_SCLK_S_HSIOM_MASK      (uartUser_sclk_s__0__HSIOM_MASK)
    #define uartUser_SCLK_S_HSIOM_POS       (uartUser_sclk_s__0__HSIOM_SHIFT)
    #define uartUser_SCLK_S_HSIOM_SEL_GPIO  (uartUser_sclk_s__0__HSIOM_GPIO)
    #define uartUser_SCLK_S_HSIOM_SEL_SPI   (uartUser_sclk_s__0__HSIOM_SPI)
    
    #define uartUser_SS0_S_HSIOM_REG    (*(reg32 *) uartUser_ss0_s__0__HSIOM)
    #define uartUser_SS0_S_HSIOM_PTR    ( (reg32 *) uartUser_ss0_s__0__HSIOM)
    
    #define uartUser_SS0_S_HSIOM_MASK       (uartUser_ss0_s__0__HSIOM_MASK)
    #define uartUser_SS0_S_HSIOM_POS        (uartUser_ss0_s__0__HSIOM_SHIFT)
    #define uartUser_SS0_S_HSIOM_SEL_GPIO   (uartUser_ss0_s__0__HSIOM_GPIO)  
    #define uartUser_SS0_S_HSIOM_SEL_SPI    (uartUser_ss0_s__0__HSIOM_SPI)
#endif /* (uartUser_SPI_SLAVE_PINS) */

#if (uartUser_SPI_SLAVE_MOSI_PIN)
    #define uartUser_MOSI_S_HSIOM_REG   (*(reg32 *) uartUser_mosi_s__0__HSIOM)
    #define uartUser_MOSI_S_HSIOM_PTR   ( (reg32 *) uartUser_mosi_s__0__HSIOM)
    
    #define uartUser_MOSI_S_HSIOM_MASK      (uartUser_mosi_s__0__HSIOM_MASK)
    #define uartUser_MOSI_S_HSIOM_POS       (uartUser_mosi_s__0__HSIOM_SHIFT)
    #define uartUser_MOSI_S_HSIOM_SEL_GPIO  (uartUser_mosi_s__0__HSIOM_GPIO)
    #define uartUser_MOSI_S_HSIOM_SEL_SPI   (uartUser_mosi_s__0__HSIOM_SPI)
#endif /* (uartUser_SPI_SLAVE_MOSI_PIN) */

#if (uartUser_SPI_SLAVE_MISO_PIN)
    #define uartUser_MISO_S_HSIOM_REG   (*(reg32 *) uartUser_miso_s__0__HSIOM)
    #define uartUser_MISO_S_HSIOM_PTR   ( (reg32 *) uartUser_miso_s__0__HSIOM)
    
    #define uartUser_MISO_S_HSIOM_MASK      (uartUser_miso_s__0__HSIOM_MASK)
    #define uartUser_MISO_S_HSIOM_POS       (uartUser_miso_s__0__HSIOM_SHIFT)
    #define uartUser_MISO_S_HSIOM_SEL_GPIO  (uartUser_miso_s__0__HSIOM_GPIO)
    #define uartUser_MISO_S_HSIOM_SEL_SPI   (uartUser_miso_s__0__HSIOM_SPI)
#endif /* (uartUser_SPI_SLAVE_MISO_PIN) */

#if (uartUser_SPI_MASTER_MISO_PIN)
    #define uartUser_MISO_M_HSIOM_REG   (*(reg32 *) uartUser_miso_m__0__HSIOM)
    #define uartUser_MISO_M_HSIOM_PTR   ( (reg32 *) uartUser_miso_m__0__HSIOM)
    
    #define uartUser_MISO_M_HSIOM_MASK      (uartUser_miso_m__0__HSIOM_MASK)
    #define uartUser_MISO_M_HSIOM_POS       (uartUser_miso_m__0__HSIOM_SHIFT)
    #define uartUser_MISO_M_HSIOM_SEL_GPIO  (uartUser_miso_m__0__HSIOM_GPIO)
    #define uartUser_MISO_M_HSIOM_SEL_SPI   (uartUser_miso_m__0__HSIOM_SPI)
#endif /* (uartUser_SPI_MASTER_MISO_PIN) */

#if (uartUser_SPI_MASTER_MOSI_PIN)
    #define uartUser_MOSI_M_HSIOM_REG   (*(reg32 *) uartUser_mosi_m__0__HSIOM)
    #define uartUser_MOSI_M_HSIOM_PTR   ( (reg32 *) uartUser_mosi_m__0__HSIOM)
    
    #define uartUser_MOSI_M_HSIOM_MASK      (uartUser_mosi_m__0__HSIOM_MASK)
    #define uartUser_MOSI_M_HSIOM_POS       (uartUser_mosi_m__0__HSIOM_SHIFT)
    #define uartUser_MOSI_M_HSIOM_SEL_GPIO  (uartUser_mosi_m__0__HSIOM_GPIO)
    #define uartUser_MOSI_M_HSIOM_SEL_SPI   (uartUser_mosi_m__0__HSIOM_SPI)
#endif /* (uartUser_SPI_MASTER_MOSI_PIN) */

#if (uartUser_SPI_MASTER_SCLK_PIN)
    #define uartUser_SCLK_M_HSIOM_REG   (*(reg32 *) uartUser_sclk_m__0__HSIOM)
    #define uartUser_SCLK_M_HSIOM_PTR   ( (reg32 *) uartUser_sclk_m__0__HSIOM)
    
    #define uartUser_SCLK_M_HSIOM_MASK      (uartUser_sclk_m__0__HSIOM_MASK)
    #define uartUser_SCLK_M_HSIOM_POS       (uartUser_sclk_m__0__HSIOM_SHIFT)
    #define uartUser_SCLK_M_HSIOM_SEL_GPIO  (uartUser_sclk_m__0__HSIOM_GPIO)
    #define uartUser_SCLK_M_HSIOM_SEL_SPI   (uartUser_sclk_m__0__HSIOM_SPI)
#endif /* (uartUser_SPI_MASTER_SCLK_PIN) */

#if (uartUser_SPI_MASTER_SS0_PIN)
    #define uartUser_SS0_M_HSIOM_REG    (*(reg32 *) uartUser_ss0_m__0__HSIOM)
    #define uartUser_SS0_M_HSIOM_PTR    ( (reg32 *) uartUser_ss0_m__0__HSIOM)
    
    #define uartUser_SS0_M_HSIOM_MASK       (uartUser_ss0_m__0__HSIOM_MASK)
    #define uartUser_SS0_M_HSIOM_POS        (uartUser_ss0_m__0__HSIOM_SHIFT)
    #define uartUser_SS0_M_HSIOM_SEL_GPIO   (uartUser_ss0_m__0__HSIOM_GPIO)
    #define uartUser_SS0_M_HSIOM_SEL_SPI    (uartUser_ss0_m__0__HSIOM_SPI)
#endif /* (uartUser_SPI_MASTER_SS0_PIN) */

#if (uartUser_SPI_MASTER_SS1_PIN)
    #define uartUser_SS1_M_HSIOM_REG    (*(reg32 *) uartUser_ss1_m__0__HSIOM)
    #define uartUser_SS1_M_HSIOM_PTR    ( (reg32 *) uartUser_ss1_m__0__HSIOM)
    
    #define uartUser_SS1_M_HSIOM_MASK       (uartUser_ss1_m__0__HSIOM_MASK)
    #define uartUser_SS1_M_HSIOM_POS        (uartUser_ss1_m__0__HSIOM_SHIFT)
    #define uartUser_SS1_M_HSIOM_SEL_GPIO   (uartUser_ss1_m__0__HSIOM_GPIO)
    #define uartUser_SS1_M_HSIOM_SEL_SPI    (uartUser_ss1_m__0__HSIOM_SPI)
#endif /* (uartUser_SPI_MASTER_SS1_PIN) */

#if (uartUser_SPI_MASTER_SS2_PIN)
    #define uartUser_SS2_M_HSIOM_REG    (*(reg32 *) uartUser_ss2_m__0__HSIOM)
    #define uartUser_SS2_M_HSIOM_PTR    ( (reg32 *) uartUser_ss2_m__0__HSIOM)
    
    #define uartUser_SS2_M_HSIOM_MASK       (uartUser_ss2_m__0__HSIOM_MASK)
    #define uartUser_SS2_M_HSIOM_POS        (uartUser_ss2_m__0__HSIOM_SHIFT)
    #define uartUser_SS2_M_HSIOM_SEL_GPIO   (uartUser_ss2_m__0__HSIOM_GPIO)
    #define uartUser_SS2_M_HSIOM_SEL_SPI    (uartUser_ss2_m__0__HSIOM_SPI)
#endif /* (uartUser_SPI_MASTER_SS2_PIN) */

#if (uartUser_SPI_MASTER_SS3_PIN)
    #define uartUser_SS3_M_HSIOM_REG    (*(reg32 *) uartUser_ss3_m__0__HSIOM)
    #define uartUser_SS3_M_HSIOM_PTR    ( (reg32 *) uartUser_ss3_m__0__HSIOM)
    
    #define uartUser_SS3_M_HSIOM_MASK      (uartUser_ss3_m__0__HSIOM_MASK)
    #define uartUser_SS3_M_HSIOM_POS       (uartUser_ss3_m__0__HSIOM_SHIFT)
    #define uartUser_SS3_M_HSIOM_SEL_GPIO  (uartUser_ss3_m__0__HSIOM_GPIO)
    #define uartUser_SS3_M_HSIOM_SEL_SPI   (uartUser_ss3_m__0__HSIOM_SPI)
#endif /* (uartUser_SPI_MASTER_SS3_PIN) */

#if (uartUser_UART_RX_PIN)
    #define uartUser_RX_HSIOM_REG   (*(reg32 *) uartUser_rx__0__HSIOM)
    #define uartUser_RX_HSIOM_PTR   ( (reg32 *) uartUser_rx__0__HSIOM)
    
    #define uartUser_RX_HSIOM_MASK      (uartUser_rx__0__HSIOM_MASK)
    #define uartUser_RX_HSIOM_POS       (uartUser_rx__0__HSIOM_SHIFT)
    #define uartUser_RX_HSIOM_SEL_GPIO  (uartUser_rx__0__HSIOM_GPIO)
    #define uartUser_RX_HSIOM_SEL_UART  (uartUser_rx__0__HSIOM_UART)
#endif /* (uartUser_UART_RX_PIN) */

#if (uartUser_UART_RX_WAKE_PIN)
    #define uartUser_RX_WAKE_HSIOM_REG   (*(reg32 *) uartUser_rx_wake__0__HSIOM)
    #define uartUser_RX_WAKE_HSIOM_PTR   ( (reg32 *) uartUser_rx_wake__0__HSIOM)
    
    #define uartUser_RX_WAKE_HSIOM_MASK      (uartUser_rx_wake__0__HSIOM_MASK)
    #define uartUser_RX_WAKE_HSIOM_POS       (uartUser_rx_wake__0__HSIOM_SHIFT)
    #define uartUser_RX_WAKE_HSIOM_SEL_GPIO  (uartUser_rx_wake__0__HSIOM_GPIO)
    #define uartUser_RX_WAKE_HSIOM_SEL_UART  (uartUser_rx_wake__0__HSIOM_UART)
#endif /* (uartUser_UART_WAKE_RX_PIN) */

#if (uartUser_UART_CTS_PIN)
    #define uartUser_CTS_HSIOM_REG   (*(reg32 *) uartUser_cts__0__HSIOM)
    #define uartUser_CTS_HSIOM_PTR   ( (reg32 *) uartUser_cts__0__HSIOM)
    
    #define uartUser_CTS_HSIOM_MASK      (uartUser_cts__0__HSIOM_MASK)
    #define uartUser_CTS_HSIOM_POS       (uartUser_cts__0__HSIOM_SHIFT)
    #define uartUser_CTS_HSIOM_SEL_GPIO  (uartUser_cts__0__HSIOM_GPIO)
    #define uartUser_CTS_HSIOM_SEL_UART  (uartUser_cts__0__HSIOM_UART)
#endif /* (uartUser_UART_CTS_PIN) */

#if (uartUser_UART_TX_PIN)
    #define uartUser_TX_HSIOM_REG   (*(reg32 *) uartUser_tx__0__HSIOM)
    #define uartUser_TX_HSIOM_PTR   ( (reg32 *) uartUser_tx__0__HSIOM)
    
    #define uartUser_TX_HSIOM_MASK      (uartUser_tx__0__HSIOM_MASK)
    #define uartUser_TX_HSIOM_POS       (uartUser_tx__0__HSIOM_SHIFT)
    #define uartUser_TX_HSIOM_SEL_GPIO  (uartUser_tx__0__HSIOM_GPIO)
    #define uartUser_TX_HSIOM_SEL_UART  (uartUser_tx__0__HSIOM_UART)
#endif /* (uartUser_UART_TX_PIN) */

#if (uartUser_UART_RX_TX_PIN)
    #define uartUser_RX_TX_HSIOM_REG   (*(reg32 *) uartUser_rx_tx__0__HSIOM)
    #define uartUser_RX_TX_HSIOM_PTR   ( (reg32 *) uartUser_rx_tx__0__HSIOM)
    
    #define uartUser_RX_TX_HSIOM_MASK      (uartUser_rx_tx__0__HSIOM_MASK)
    #define uartUser_RX_TX_HSIOM_POS       (uartUser_rx_tx__0__HSIOM_SHIFT)
    #define uartUser_RX_TX_HSIOM_SEL_GPIO  (uartUser_rx_tx__0__HSIOM_GPIO)
    #define uartUser_RX_TX_HSIOM_SEL_UART  (uartUser_rx_tx__0__HSIOM_UART)
#endif /* (uartUser_UART_RX_TX_PIN) */

#if (uartUser_UART_RTS_PIN)
    #define uartUser_RTS_HSIOM_REG      (*(reg32 *) uartUser_rts__0__HSIOM)
    #define uartUser_RTS_HSIOM_PTR      ( (reg32 *) uartUser_rts__0__HSIOM)
    
    #define uartUser_RTS_HSIOM_MASK     (uartUser_rts__0__HSIOM_MASK)
    #define uartUser_RTS_HSIOM_POS      (uartUser_rts__0__HSIOM_SHIFT)    
    #define uartUser_RTS_HSIOM_SEL_GPIO (uartUser_rts__0__HSIOM_GPIO)
    #define uartUser_RTS_HSIOM_SEL_UART (uartUser_rts__0__HSIOM_UART)    
#endif /* (uartUser_UART_RTS_PIN) */


/***************************************
*        Registers Constants
***************************************/

/* HSIOM switch values. */ 
#define uartUser_HSIOM_DEF_SEL      (0x00u)
#define uartUser_HSIOM_GPIO_SEL     (0x00u)
/* The HSIOM values provided below are valid only for uartUser_CY_SCBIP_V0 
* and uartUser_CY_SCBIP_V1. It is not recommended to use them for 
* uartUser_CY_SCBIP_V2. Use pin name specific HSIOM constants provided 
* above instead for any SCB IP block version.
*/
#define uartUser_HSIOM_UART_SEL     (0x09u)
#define uartUser_HSIOM_I2C_SEL      (0x0Eu)
#define uartUser_HSIOM_SPI_SEL      (0x0Fu)

/* Pins settings index. */
#define uartUser_RX_WAKE_SCL_MOSI_PIN_INDEX   (0u)
#define uartUser_RX_SCL_MOSI_PIN_INDEX       (0u)
#define uartUser_TX_SDA_MISO_PIN_INDEX       (1u)
#define uartUser_SCLK_PIN_INDEX       (2u)
#define uartUser_SS0_PIN_INDEX       (3u)
#define uartUser_SS1_PIN_INDEX                  (4u)
#define uartUser_SS2_PIN_INDEX                  (5u)
#define uartUser_SS3_PIN_INDEX                  (6u)

/* Pins settings mask. */
#define uartUser_RX_WAKE_SCL_MOSI_PIN_MASK ((uint32) 0x01u << uartUser_RX_WAKE_SCL_MOSI_PIN_INDEX)
#define uartUser_RX_SCL_MOSI_PIN_MASK     ((uint32) 0x01u << uartUser_RX_SCL_MOSI_PIN_INDEX)
#define uartUser_TX_SDA_MISO_PIN_MASK     ((uint32) 0x01u << uartUser_TX_SDA_MISO_PIN_INDEX)
#define uartUser_SCLK_PIN_MASK     ((uint32) 0x01u << uartUser_SCLK_PIN_INDEX)
#define uartUser_SS0_PIN_MASK     ((uint32) 0x01u << uartUser_SS0_PIN_INDEX)
#define uartUser_SS1_PIN_MASK                ((uint32) 0x01u << uartUser_SS1_PIN_INDEX)
#define uartUser_SS2_PIN_MASK                ((uint32) 0x01u << uartUser_SS2_PIN_INDEX)
#define uartUser_SS3_PIN_MASK                ((uint32) 0x01u << uartUser_SS3_PIN_INDEX)

/* Pin interrupt constants. */
#define uartUser_INTCFG_TYPE_MASK           (0x03u)
#define uartUser_INTCFG_TYPE_FALLING_EDGE   (0x02u)

/* Pin Drive Mode constants. */
#define uartUser_PIN_DM_ALG_HIZ  (0u)
#define uartUser_PIN_DM_DIG_HIZ  (1u)
#define uartUser_PIN_DM_OD_LO    (4u)
#define uartUser_PIN_DM_STRONG   (6u)


/***************************************
*          Macro Definitions
***************************************/

/* Return drive mode of the pin */
#define uartUser_DM_MASK    (0x7u)
#define uartUser_DM_SIZE    (3u)
#define uartUser_GET_P4_PIN_DM(reg, pos) \
    ( ((reg) & (uint32) ((uint32) uartUser_DM_MASK << (uartUser_DM_SIZE * (pos)))) >> \
                                                              (uartUser_DM_SIZE * (pos)) )

#if (uartUser_TX_SDA_MISO_PIN)
    #define uartUser_CHECK_TX_SDA_MISO_PIN_USED \
                (uartUser_PIN_DM_ALG_HIZ != \
                    uartUser_GET_P4_PIN_DM(uartUser_uart_tx_i2c_sda_spi_miso_PC, \
                                                   uartUser_uart_tx_i2c_sda_spi_miso_SHIFT))
#endif /* (uartUser_TX_SDA_MISO_PIN) */

#if (uartUser_SS0_PIN)
    #define uartUser_CHECK_SS0_PIN_USED \
                (uartUser_PIN_DM_ALG_HIZ != \
                    uartUser_GET_P4_PIN_DM(uartUser_spi_ss0_PC, \
                                                   uartUser_spi_ss0_SHIFT))
#endif /* (uartUser_SS0_PIN) */

/* Set bits-mask in register */
#define uartUser_SET_REGISTER_BITS(reg, mask, pos, mode) \
                    do                                           \
                    {                                            \
                        (reg) = (((reg) & ((uint32) ~(uint32) (mask))) | ((uint32) ((uint32) (mode) << (pos)))); \
                    }while(0)

/* Set bit in the register */
#define uartUser_SET_REGISTER_BIT(reg, mask, val) \
                    ((val) ? ((reg) |= (mask)) : ((reg) &= ((uint32) ~((uint32) (mask)))))

#define uartUser_SET_HSIOM_SEL(reg, mask, pos, sel) uartUser_SET_REGISTER_BITS(reg, mask, pos, sel)
#define uartUser_SET_INCFG_TYPE(reg, mask, pos, intType) \
                                                        uartUser_SET_REGISTER_BITS(reg, mask, pos, intType)
#define uartUser_SET_INP_DIS(reg, mask, val) uartUser_SET_REGISTER_BIT(reg, mask, val)

/* uartUser_SET_I2C_SCL_DR(val) - Sets I2C SCL DR register.
*  uartUser_SET_I2C_SCL_HSIOM_SEL(sel) - Sets I2C SCL HSIOM settings.
*/
/* SCB I2C: scl signal */
#if (uartUser_CY_SCBIP_V0)
#if (uartUser_I2C_PINS)
    #define uartUser_SET_I2C_SCL_DR(val) uartUser_scl_Write(val)

    #define uartUser_SET_I2C_SCL_HSIOM_SEL(sel) \
                          uartUser_SET_HSIOM_SEL(uartUser_SCL_HSIOM_REG,  \
                                                         uartUser_SCL_HSIOM_MASK, \
                                                         uartUser_SCL_HSIOM_POS,  \
                                                         (sel))
    #define uartUser_WAIT_SCL_SET_HIGH  (0u == uartUser_scl_Read())

/* Unconfigured SCB: scl signal */
#elif (uartUser_RX_WAKE_SCL_MOSI_PIN)
    #define uartUser_SET_I2C_SCL_DR(val) \
                            uartUser_uart_rx_wake_i2c_scl_spi_mosi_Write(val)

    #define uartUser_SET_I2C_SCL_HSIOM_SEL(sel) \
                    uartUser_SET_HSIOM_SEL(uartUser_RX_WAKE_SCL_MOSI_HSIOM_REG,  \
                                                   uartUser_RX_WAKE_SCL_MOSI_HSIOM_MASK, \
                                                   uartUser_RX_WAKE_SCL_MOSI_HSIOM_POS,  \
                                                   (sel))

    #define uartUser_WAIT_SCL_SET_HIGH  (0u == uartUser_uart_rx_wake_i2c_scl_spi_mosi_Read())

#elif (uartUser_RX_SCL_MOSI_PIN)
    #define uartUser_SET_I2C_SCL_DR(val) \
                            uartUser_uart_rx_i2c_scl_spi_mosi_Write(val)


    #define uartUser_SET_I2C_SCL_HSIOM_SEL(sel) \
                            uartUser_SET_HSIOM_SEL(uartUser_RX_SCL_MOSI_HSIOM_REG,  \
                                                           uartUser_RX_SCL_MOSI_HSIOM_MASK, \
                                                           uartUser_RX_SCL_MOSI_HSIOM_POS,  \
                                                           (sel))

    #define uartUser_WAIT_SCL_SET_HIGH  (0u == uartUser_uart_rx_i2c_scl_spi_mosi_Read())

#else
    #define uartUser_SET_I2C_SCL_DR(val)        do{ /* Does nothing */ }while(0)
    #define uartUser_SET_I2C_SCL_HSIOM_SEL(sel) do{ /* Does nothing */ }while(0)

    #define uartUser_WAIT_SCL_SET_HIGH  (0u)
#endif /* (uartUser_I2C_PINS) */

/* SCB I2C: sda signal */
#if (uartUser_I2C_PINS)
    #define uartUser_WAIT_SDA_SET_HIGH  (0u == uartUser_sda_Read())
/* Unconfigured SCB: sda signal */
#elif (uartUser_TX_SDA_MISO_PIN)
    #define uartUser_WAIT_SDA_SET_HIGH  (0u == uartUser_uart_tx_i2c_sda_spi_miso_Read())
#else
    #define uartUser_WAIT_SDA_SET_HIGH  (0u)
#endif /* (uartUser_MOSI_SCL_RX_PIN) */
#endif /* (uartUser_CY_SCBIP_V0) */

/* Clear UART wakeup source */
#if (uartUser_RX_SCL_MOSI_PIN)
    #define uartUser_CLEAR_UART_RX_WAKE_INTR        do{ /* Does nothing */ }while(0)
    
#elif (uartUser_RX_WAKE_SCL_MOSI_PIN)
    #define uartUser_CLEAR_UART_RX_WAKE_INTR \
            do{                                      \
                (void) uartUser_uart_rx_wake_i2c_scl_spi_mosi_ClearInterrupt(); \
            }while(0)

#elif(uartUser_UART_RX_WAKE_PIN)
    #define uartUser_CLEAR_UART_RX_WAKE_INTR \
            do{                                      \
                (void) uartUser_rx_wake_ClearInterrupt(); \
            }while(0)
#else
#endif /* (uartUser_RX_SCL_MOSI_PIN) */


/***************************************
* The following code is DEPRECATED and
* must not be used.
***************************************/

/* Unconfigured pins */
#define uartUser_REMOVE_MOSI_SCL_RX_WAKE_PIN    uartUser_REMOVE_RX_WAKE_SCL_MOSI_PIN
#define uartUser_REMOVE_MOSI_SCL_RX_PIN         uartUser_REMOVE_RX_SCL_MOSI_PIN
#define uartUser_REMOVE_MISO_SDA_TX_PIN         uartUser_REMOVE_TX_SDA_MISO_PIN
#ifndef uartUser_REMOVE_SCLK_PIN
#define uartUser_REMOVE_SCLK_PIN                uartUser_REMOVE_SCLK_PIN
#endif /* uartUser_REMOVE_SCLK_PIN */
#ifndef uartUser_REMOVE_SS0_PIN
#define uartUser_REMOVE_SS0_PIN                 uartUser_REMOVE_SS0_PIN
#endif /* uartUser_REMOVE_SS0_PIN */

/* Unconfigured pins */
#define uartUser_MOSI_SCL_RX_WAKE_PIN   uartUser_RX_WAKE_SCL_MOSI_PIN
#define uartUser_MOSI_SCL_RX_PIN        uartUser_RX_SCL_MOSI_PIN
#define uartUser_MISO_SDA_TX_PIN        uartUser_TX_SDA_MISO_PIN
#ifndef uartUser_SCLK_PIN
#define uartUser_SCLK_PIN               uartUser_SCLK_PIN
#endif /* uartUser_SCLK_PIN */
#ifndef uartUser_SS0_PIN
#define uartUser_SS0_PIN                uartUser_SS0_PIN
#endif /* uartUser_SS0_PIN */

#if (uartUser_MOSI_SCL_RX_WAKE_PIN)
    #define uartUser_MOSI_SCL_RX_WAKE_HSIOM_REG     uartUser_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define uartUser_MOSI_SCL_RX_WAKE_HSIOM_PTR     uartUser_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define uartUser_MOSI_SCL_RX_WAKE_HSIOM_MASK    uartUser_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define uartUser_MOSI_SCL_RX_WAKE_HSIOM_POS     uartUser_RX_WAKE_SCL_MOSI_HSIOM_REG

    #define uartUser_MOSI_SCL_RX_WAKE_INTCFG_REG    uartUser_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define uartUser_MOSI_SCL_RX_WAKE_INTCFG_PTR    uartUser_RX_WAKE_SCL_MOSI_HSIOM_REG

    #define uartUser_MOSI_SCL_RX_WAKE_INTCFG_TYPE_POS   uartUser_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define uartUser_MOSI_SCL_RX_WAKE_INTCFG_TYPE_MASK  uartUser_RX_WAKE_SCL_MOSI_HSIOM_REG
#endif /* (uartUser_RX_WAKE_SCL_MOSI_PIN) */

#if (uartUser_MOSI_SCL_RX_PIN)
    #define uartUser_MOSI_SCL_RX_HSIOM_REG      uartUser_RX_SCL_MOSI_HSIOM_REG
    #define uartUser_MOSI_SCL_RX_HSIOM_PTR      uartUser_RX_SCL_MOSI_HSIOM_PTR
    #define uartUser_MOSI_SCL_RX_HSIOM_MASK     uartUser_RX_SCL_MOSI_HSIOM_MASK
    #define uartUser_MOSI_SCL_RX_HSIOM_POS      uartUser_RX_SCL_MOSI_HSIOM_POS
#endif /* (uartUser_MOSI_SCL_RX_PIN) */

#if (uartUser_MISO_SDA_TX_PIN)
    #define uartUser_MISO_SDA_TX_HSIOM_REG      uartUser_TX_SDA_MISO_HSIOM_REG
    #define uartUser_MISO_SDA_TX_HSIOM_PTR      uartUser_TX_SDA_MISO_HSIOM_REG
    #define uartUser_MISO_SDA_TX_HSIOM_MASK     uartUser_TX_SDA_MISO_HSIOM_REG
    #define uartUser_MISO_SDA_TX_HSIOM_POS      uartUser_TX_SDA_MISO_HSIOM_REG
#endif /* (uartUser_MISO_SDA_TX_PIN_PIN) */

#if (uartUser_SCLK_PIN)
    #ifndef uartUser_SCLK_HSIOM_REG
    #define uartUser_SCLK_HSIOM_REG     uartUser_SCLK_HSIOM_REG
    #define uartUser_SCLK_HSIOM_PTR     uartUser_SCLK_HSIOM_PTR
    #define uartUser_SCLK_HSIOM_MASK    uartUser_SCLK_HSIOM_MASK
    #define uartUser_SCLK_HSIOM_POS     uartUser_SCLK_HSIOM_POS
    #endif /* uartUser_SCLK_HSIOM_REG */
#endif /* (uartUser_SCLK_PIN) */

#if (uartUser_SS0_PIN)
    #ifndef uartUser_SS0_HSIOM_REG
    #define uartUser_SS0_HSIOM_REG      uartUser_SS0_HSIOM_REG
    #define uartUser_SS0_HSIOM_PTR      uartUser_SS0_HSIOM_PTR
    #define uartUser_SS0_HSIOM_MASK     uartUser_SS0_HSIOM_MASK
    #define uartUser_SS0_HSIOM_POS      uartUser_SS0_HSIOM_POS
    #endif /* uartUser_SS0_HSIOM_REG */
#endif /* (uartUser_SS0_PIN) */

#define uartUser_MOSI_SCL_RX_WAKE_PIN_INDEX uartUser_RX_WAKE_SCL_MOSI_PIN_INDEX
#define uartUser_MOSI_SCL_RX_PIN_INDEX      uartUser_RX_SCL_MOSI_PIN_INDEX
#define uartUser_MISO_SDA_TX_PIN_INDEX      uartUser_TX_SDA_MISO_PIN_INDEX
#ifndef uartUser_SCLK_PIN_INDEX
#define uartUser_SCLK_PIN_INDEX             uartUser_SCLK_PIN_INDEX
#endif /* uartUser_SCLK_PIN_INDEX */
#ifndef uartUser_SS0_PIN_INDEX
#define uartUser_SS0_PIN_INDEX              uartUser_SS0_PIN_INDEX
#endif /* uartUser_SS0_PIN_INDEX */

#define uartUser_MOSI_SCL_RX_WAKE_PIN_MASK uartUser_RX_WAKE_SCL_MOSI_PIN_MASK
#define uartUser_MOSI_SCL_RX_PIN_MASK      uartUser_RX_SCL_MOSI_PIN_MASK
#define uartUser_MISO_SDA_TX_PIN_MASK      uartUser_TX_SDA_MISO_PIN_MASK
#ifndef uartUser_SCLK_PIN_MASK
#define uartUser_SCLK_PIN_MASK             uartUser_SCLK_PIN_MASK
#endif /* uartUser_SCLK_PIN_MASK */
#ifndef uartUser_SS0_PIN_MASK
#define uartUser_SS0_PIN_MASK              uartUser_SS0_PIN_MASK
#endif /* uartUser_SS0_PIN_MASK */

#endif /* (CY_SCB_PINS_uartUser_H) */


/* [] END OF FILE */
