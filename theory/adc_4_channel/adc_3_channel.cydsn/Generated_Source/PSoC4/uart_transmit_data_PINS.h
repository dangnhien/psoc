/***************************************************************************//**
* \file uart_transmit_data_PINS.h
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

#if !defined(CY_SCB_PINS_uart_transmit_data_H)
#define CY_SCB_PINS_uart_transmit_data_H

#include "cydevice_trm.h"
#include "cyfitter.h"
#include "cytypes.h"


/***************************************
*   Conditional Compilation Parameters
****************************************/

/* Unconfigured pins */
#define uart_transmit_data_REMOVE_RX_WAKE_SCL_MOSI_PIN  (1u)
#define uart_transmit_data_REMOVE_RX_SCL_MOSI_PIN      (1u)
#define uart_transmit_data_REMOVE_TX_SDA_MISO_PIN      (1u)
#define uart_transmit_data_REMOVE_SCLK_PIN      (1u)
#define uart_transmit_data_REMOVE_SS0_PIN      (1u)
#define uart_transmit_data_REMOVE_SS1_PIN                 (1u)
#define uart_transmit_data_REMOVE_SS2_PIN                 (1u)
#define uart_transmit_data_REMOVE_SS3_PIN                 (1u)

/* Mode defined pins */
#define uart_transmit_data_REMOVE_I2C_PINS                (1u)
#define uart_transmit_data_REMOVE_SPI_MASTER_PINS         (1u)
#define uart_transmit_data_REMOVE_SPI_MASTER_SCLK_PIN     (1u)
#define uart_transmit_data_REMOVE_SPI_MASTER_MOSI_PIN     (1u)
#define uart_transmit_data_REMOVE_SPI_MASTER_MISO_PIN     (1u)
#define uart_transmit_data_REMOVE_SPI_MASTER_SS0_PIN      (1u)
#define uart_transmit_data_REMOVE_SPI_MASTER_SS1_PIN      (1u)
#define uart_transmit_data_REMOVE_SPI_MASTER_SS2_PIN      (1u)
#define uart_transmit_data_REMOVE_SPI_MASTER_SS3_PIN      (1u)
#define uart_transmit_data_REMOVE_SPI_SLAVE_PINS          (1u)
#define uart_transmit_data_REMOVE_SPI_SLAVE_MOSI_PIN      (1u)
#define uart_transmit_data_REMOVE_SPI_SLAVE_MISO_PIN      (1u)
#define uart_transmit_data_REMOVE_UART_TX_PIN             (0u)
#define uart_transmit_data_REMOVE_UART_RX_TX_PIN          (1u)
#define uart_transmit_data_REMOVE_UART_RX_PIN             (0u)
#define uart_transmit_data_REMOVE_UART_RX_WAKE_PIN        (1u)
#define uart_transmit_data_REMOVE_UART_RTS_PIN            (1u)
#define uart_transmit_data_REMOVE_UART_CTS_PIN            (1u)

/* Unconfigured pins */
#define uart_transmit_data_RX_WAKE_SCL_MOSI_PIN (0u == uart_transmit_data_REMOVE_RX_WAKE_SCL_MOSI_PIN)
#define uart_transmit_data_RX_SCL_MOSI_PIN     (0u == uart_transmit_data_REMOVE_RX_SCL_MOSI_PIN)
#define uart_transmit_data_TX_SDA_MISO_PIN     (0u == uart_transmit_data_REMOVE_TX_SDA_MISO_PIN)
#define uart_transmit_data_SCLK_PIN     (0u == uart_transmit_data_REMOVE_SCLK_PIN)
#define uart_transmit_data_SS0_PIN     (0u == uart_transmit_data_REMOVE_SS0_PIN)
#define uart_transmit_data_SS1_PIN                (0u == uart_transmit_data_REMOVE_SS1_PIN)
#define uart_transmit_data_SS2_PIN                (0u == uart_transmit_data_REMOVE_SS2_PIN)
#define uart_transmit_data_SS3_PIN                (0u == uart_transmit_data_REMOVE_SS3_PIN)

/* Mode defined pins */
#define uart_transmit_data_I2C_PINS               (0u == uart_transmit_data_REMOVE_I2C_PINS)
#define uart_transmit_data_SPI_MASTER_PINS        (0u == uart_transmit_data_REMOVE_SPI_MASTER_PINS)
#define uart_transmit_data_SPI_MASTER_SCLK_PIN    (0u == uart_transmit_data_REMOVE_SPI_MASTER_SCLK_PIN)
#define uart_transmit_data_SPI_MASTER_MOSI_PIN    (0u == uart_transmit_data_REMOVE_SPI_MASTER_MOSI_PIN)
#define uart_transmit_data_SPI_MASTER_MISO_PIN    (0u == uart_transmit_data_REMOVE_SPI_MASTER_MISO_PIN)
#define uart_transmit_data_SPI_MASTER_SS0_PIN     (0u == uart_transmit_data_REMOVE_SPI_MASTER_SS0_PIN)
#define uart_transmit_data_SPI_MASTER_SS1_PIN     (0u == uart_transmit_data_REMOVE_SPI_MASTER_SS1_PIN)
#define uart_transmit_data_SPI_MASTER_SS2_PIN     (0u == uart_transmit_data_REMOVE_SPI_MASTER_SS2_PIN)
#define uart_transmit_data_SPI_MASTER_SS3_PIN     (0u == uart_transmit_data_REMOVE_SPI_MASTER_SS3_PIN)
#define uart_transmit_data_SPI_SLAVE_PINS         (0u == uart_transmit_data_REMOVE_SPI_SLAVE_PINS)
#define uart_transmit_data_SPI_SLAVE_MOSI_PIN     (0u == uart_transmit_data_REMOVE_SPI_SLAVE_MOSI_PIN)
#define uart_transmit_data_SPI_SLAVE_MISO_PIN     (0u == uart_transmit_data_REMOVE_SPI_SLAVE_MISO_PIN)
#define uart_transmit_data_UART_TX_PIN            (0u == uart_transmit_data_REMOVE_UART_TX_PIN)
#define uart_transmit_data_UART_RX_TX_PIN         (0u == uart_transmit_data_REMOVE_UART_RX_TX_PIN)
#define uart_transmit_data_UART_RX_PIN            (0u == uart_transmit_data_REMOVE_UART_RX_PIN)
#define uart_transmit_data_UART_RX_WAKE_PIN       (0u == uart_transmit_data_REMOVE_UART_RX_WAKE_PIN)
#define uart_transmit_data_UART_RTS_PIN           (0u == uart_transmit_data_REMOVE_UART_RTS_PIN)
#define uart_transmit_data_UART_CTS_PIN           (0u == uart_transmit_data_REMOVE_UART_CTS_PIN)


/***************************************
*             Includes
****************************************/

#if (uart_transmit_data_RX_WAKE_SCL_MOSI_PIN)
    #include "uart_transmit_data_uart_rx_wake_i2c_scl_spi_mosi.h"
#endif /* (uart_transmit_data_RX_SCL_MOSI) */

#if (uart_transmit_data_RX_SCL_MOSI_PIN)
    #include "uart_transmit_data_uart_rx_i2c_scl_spi_mosi.h"
#endif /* (uart_transmit_data_RX_SCL_MOSI) */

#if (uart_transmit_data_TX_SDA_MISO_PIN)
    #include "uart_transmit_data_uart_tx_i2c_sda_spi_miso.h"
#endif /* (uart_transmit_data_TX_SDA_MISO) */

#if (uart_transmit_data_SCLK_PIN)
    #include "uart_transmit_data_spi_sclk.h"
#endif /* (uart_transmit_data_SCLK) */

#if (uart_transmit_data_SS0_PIN)
    #include "uart_transmit_data_spi_ss0.h"
#endif /* (uart_transmit_data_SS0_PIN) */

#if (uart_transmit_data_SS1_PIN)
    #include "uart_transmit_data_spi_ss1.h"
#endif /* (uart_transmit_data_SS1_PIN) */

#if (uart_transmit_data_SS2_PIN)
    #include "uart_transmit_data_spi_ss2.h"
#endif /* (uart_transmit_data_SS2_PIN) */

#if (uart_transmit_data_SS3_PIN)
    #include "uart_transmit_data_spi_ss3.h"
#endif /* (uart_transmit_data_SS3_PIN) */

#if (uart_transmit_data_I2C_PINS)
    #include "uart_transmit_data_scl.h"
    #include "uart_transmit_data_sda.h"
#endif /* (uart_transmit_data_I2C_PINS) */

#if (uart_transmit_data_SPI_MASTER_PINS)
#if (uart_transmit_data_SPI_MASTER_SCLK_PIN)
    #include "uart_transmit_data_sclk_m.h"
#endif /* (uart_transmit_data_SPI_MASTER_SCLK_PIN) */

#if (uart_transmit_data_SPI_MASTER_MOSI_PIN)
    #include "uart_transmit_data_mosi_m.h"
#endif /* (uart_transmit_data_SPI_MASTER_MOSI_PIN) */

#if (uart_transmit_data_SPI_MASTER_MISO_PIN)
    #include "uart_transmit_data_miso_m.h"
#endif /*(uart_transmit_data_SPI_MASTER_MISO_PIN) */
#endif /* (uart_transmit_data_SPI_MASTER_PINS) */

#if (uart_transmit_data_SPI_SLAVE_PINS)
    #include "uart_transmit_data_sclk_s.h"
    #include "uart_transmit_data_ss_s.h"

#if (uart_transmit_data_SPI_SLAVE_MOSI_PIN)
    #include "uart_transmit_data_mosi_s.h"
#endif /* (uart_transmit_data_SPI_SLAVE_MOSI_PIN) */

#if (uart_transmit_data_SPI_SLAVE_MISO_PIN)
    #include "uart_transmit_data_miso_s.h"
#endif /*(uart_transmit_data_SPI_SLAVE_MISO_PIN) */
#endif /* (uart_transmit_data_SPI_SLAVE_PINS) */

#if (uart_transmit_data_SPI_MASTER_SS0_PIN)
    #include "uart_transmit_data_ss0_m.h"
#endif /* (uart_transmit_data_SPI_MASTER_SS0_PIN) */

#if (uart_transmit_data_SPI_MASTER_SS1_PIN)
    #include "uart_transmit_data_ss1_m.h"
#endif /* (uart_transmit_data_SPI_MASTER_SS1_PIN) */

#if (uart_transmit_data_SPI_MASTER_SS2_PIN)
    #include "uart_transmit_data_ss2_m.h"
#endif /* (uart_transmit_data_SPI_MASTER_SS2_PIN) */

#if (uart_transmit_data_SPI_MASTER_SS3_PIN)
    #include "uart_transmit_data_ss3_m.h"
#endif /* (uart_transmit_data_SPI_MASTER_SS3_PIN) */

#if (uart_transmit_data_UART_TX_PIN)
    #include "uart_transmit_data_tx.h"
#endif /* (uart_transmit_data_UART_TX_PIN) */

#if (uart_transmit_data_UART_RX_TX_PIN)
    #include "uart_transmit_data_rx_tx.h"
#endif /* (uart_transmit_data_UART_RX_TX_PIN) */

#if (uart_transmit_data_UART_RX_PIN)
    #include "uart_transmit_data_rx.h"
#endif /* (uart_transmit_data_UART_RX_PIN) */

#if (uart_transmit_data_UART_RX_WAKE_PIN)
    #include "uart_transmit_data_rx_wake.h"
#endif /* (uart_transmit_data_UART_RX_WAKE_PIN) */

#if (uart_transmit_data_UART_RTS_PIN)
    #include "uart_transmit_data_rts.h"
#endif /* (uart_transmit_data_UART_RTS_PIN) */

#if (uart_transmit_data_UART_CTS_PIN)
    #include "uart_transmit_data_cts.h"
#endif /* (uart_transmit_data_UART_CTS_PIN) */


/***************************************
*              Registers
***************************************/

#if (uart_transmit_data_RX_SCL_MOSI_PIN)
    #define uart_transmit_data_RX_SCL_MOSI_HSIOM_REG   (*(reg32 *) uart_transmit_data_uart_rx_i2c_scl_spi_mosi__0__HSIOM)
    #define uart_transmit_data_RX_SCL_MOSI_HSIOM_PTR   ( (reg32 *) uart_transmit_data_uart_rx_i2c_scl_spi_mosi__0__HSIOM)
    
    #define uart_transmit_data_RX_SCL_MOSI_HSIOM_MASK      (uart_transmit_data_uart_rx_i2c_scl_spi_mosi__0__HSIOM_MASK)
    #define uart_transmit_data_RX_SCL_MOSI_HSIOM_POS       (uart_transmit_data_uart_rx_i2c_scl_spi_mosi__0__HSIOM_SHIFT)
    #define uart_transmit_data_RX_SCL_MOSI_HSIOM_SEL_GPIO  (uart_transmit_data_uart_rx_i2c_scl_spi_mosi__0__HSIOM_GPIO)
    #define uart_transmit_data_RX_SCL_MOSI_HSIOM_SEL_I2C   (uart_transmit_data_uart_rx_i2c_scl_spi_mosi__0__HSIOM_I2C)
    #define uart_transmit_data_RX_SCL_MOSI_HSIOM_SEL_SPI   (uart_transmit_data_uart_rx_i2c_scl_spi_mosi__0__HSIOM_SPI)
    #define uart_transmit_data_RX_SCL_MOSI_HSIOM_SEL_UART  (uart_transmit_data_uart_rx_i2c_scl_spi_mosi__0__HSIOM_UART)
    
#elif (uart_transmit_data_RX_WAKE_SCL_MOSI_PIN)
    #define uart_transmit_data_RX_WAKE_SCL_MOSI_HSIOM_REG   (*(reg32 *) uart_transmit_data_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM)
    #define uart_transmit_data_RX_WAKE_SCL_MOSI_HSIOM_PTR   ( (reg32 *) uart_transmit_data_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM)
    
    #define uart_transmit_data_RX_WAKE_SCL_MOSI_HSIOM_MASK      (uart_transmit_data_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_MASK)
    #define uart_transmit_data_RX_WAKE_SCL_MOSI_HSIOM_POS       (uart_transmit_data_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_SHIFT)
    #define uart_transmit_data_RX_WAKE_SCL_MOSI_HSIOM_SEL_GPIO  (uart_transmit_data_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_GPIO)
    #define uart_transmit_data_RX_WAKE_SCL_MOSI_HSIOM_SEL_I2C   (uart_transmit_data_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_I2C)
    #define uart_transmit_data_RX_WAKE_SCL_MOSI_HSIOM_SEL_SPI   (uart_transmit_data_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_SPI)
    #define uart_transmit_data_RX_WAKE_SCL_MOSI_HSIOM_SEL_UART  (uart_transmit_data_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_UART)    
   
    #define uart_transmit_data_RX_WAKE_SCL_MOSI_INTCFG_REG (*(reg32 *) uart_transmit_data_uart_rx_wake_i2c_scl_spi_mosi__0__INTCFG)
    #define uart_transmit_data_RX_WAKE_SCL_MOSI_INTCFG_PTR ( (reg32 *) uart_transmit_data_uart_rx_wake_i2c_scl_spi_mosi__0__INTCFG)
    #define uart_transmit_data_RX_WAKE_SCL_MOSI_INTCFG_TYPE_POS  (uart_transmit_data_uart_rx_wake_i2c_scl_spi_mosi__SHIFT)
    #define uart_transmit_data_RX_WAKE_SCL_MOSI_INTCFG_TYPE_MASK ((uint32) uart_transmit_data_INTCFG_TYPE_MASK << \
                                                                           uart_transmit_data_RX_WAKE_SCL_MOSI_INTCFG_TYPE_POS)
#else
    /* None of pins uart_transmit_data_RX_SCL_MOSI_PIN or uart_transmit_data_RX_WAKE_SCL_MOSI_PIN present.*/
#endif /* (uart_transmit_data_RX_SCL_MOSI_PIN) */

#if (uart_transmit_data_TX_SDA_MISO_PIN)
    #define uart_transmit_data_TX_SDA_MISO_HSIOM_REG   (*(reg32 *) uart_transmit_data_uart_tx_i2c_sda_spi_miso__0__HSIOM)
    #define uart_transmit_data_TX_SDA_MISO_HSIOM_PTR   ( (reg32 *) uart_transmit_data_uart_tx_i2c_sda_spi_miso__0__HSIOM)
    
    #define uart_transmit_data_TX_SDA_MISO_HSIOM_MASK      (uart_transmit_data_uart_tx_i2c_sda_spi_miso__0__HSIOM_MASK)
    #define uart_transmit_data_TX_SDA_MISO_HSIOM_POS       (uart_transmit_data_uart_tx_i2c_sda_spi_miso__0__HSIOM_SHIFT)
    #define uart_transmit_data_TX_SDA_MISO_HSIOM_SEL_GPIO  (uart_transmit_data_uart_tx_i2c_sda_spi_miso__0__HSIOM_GPIO)
    #define uart_transmit_data_TX_SDA_MISO_HSIOM_SEL_I2C   (uart_transmit_data_uart_tx_i2c_sda_spi_miso__0__HSIOM_I2C)
    #define uart_transmit_data_TX_SDA_MISO_HSIOM_SEL_SPI   (uart_transmit_data_uart_tx_i2c_sda_spi_miso__0__HSIOM_SPI)
    #define uart_transmit_data_TX_SDA_MISO_HSIOM_SEL_UART  (uart_transmit_data_uart_tx_i2c_sda_spi_miso__0__HSIOM_UART)
#endif /* (uart_transmit_data_TX_SDA_MISO_PIN) */

#if (uart_transmit_data_SCLK_PIN)
    #define uart_transmit_data_SCLK_HSIOM_REG   (*(reg32 *) uart_transmit_data_spi_sclk__0__HSIOM)
    #define uart_transmit_data_SCLK_HSIOM_PTR   ( (reg32 *) uart_transmit_data_spi_sclk__0__HSIOM)
    
    #define uart_transmit_data_SCLK_HSIOM_MASK      (uart_transmit_data_spi_sclk__0__HSIOM_MASK)
    #define uart_transmit_data_SCLK_HSIOM_POS       (uart_transmit_data_spi_sclk__0__HSIOM_SHIFT)
    #define uart_transmit_data_SCLK_HSIOM_SEL_GPIO  (uart_transmit_data_spi_sclk__0__HSIOM_GPIO)
    #define uart_transmit_data_SCLK_HSIOM_SEL_I2C   (uart_transmit_data_spi_sclk__0__HSIOM_I2C)
    #define uart_transmit_data_SCLK_HSIOM_SEL_SPI   (uart_transmit_data_spi_sclk__0__HSIOM_SPI)
    #define uart_transmit_data_SCLK_HSIOM_SEL_UART  (uart_transmit_data_spi_sclk__0__HSIOM_UART)
#endif /* (uart_transmit_data_SCLK_PIN) */

#if (uart_transmit_data_SS0_PIN)
    #define uart_transmit_data_SS0_HSIOM_REG   (*(reg32 *) uart_transmit_data_spi_ss0__0__HSIOM)
    #define uart_transmit_data_SS0_HSIOM_PTR   ( (reg32 *) uart_transmit_data_spi_ss0__0__HSIOM)
    
    #define uart_transmit_data_SS0_HSIOM_MASK      (uart_transmit_data_spi_ss0__0__HSIOM_MASK)
    #define uart_transmit_data_SS0_HSIOM_POS       (uart_transmit_data_spi_ss0__0__HSIOM_SHIFT)
    #define uart_transmit_data_SS0_HSIOM_SEL_GPIO  (uart_transmit_data_spi_ss0__0__HSIOM_GPIO)
    #define uart_transmit_data_SS0_HSIOM_SEL_I2C   (uart_transmit_data_spi_ss0__0__HSIOM_I2C)
    #define uart_transmit_data_SS0_HSIOM_SEL_SPI   (uart_transmit_data_spi_ss0__0__HSIOM_SPI)
#if !(uart_transmit_data_CY_SCBIP_V0 || uart_transmit_data_CY_SCBIP_V1)
    #define uart_transmit_data_SS0_HSIOM_SEL_UART  (uart_transmit_data_spi_ss0__0__HSIOM_UART)
#endif /* !(uart_transmit_data_CY_SCBIP_V0 || uart_transmit_data_CY_SCBIP_V1) */
#endif /* (uart_transmit_data_SS0_PIN) */

#if (uart_transmit_data_SS1_PIN)
    #define uart_transmit_data_SS1_HSIOM_REG  (*(reg32 *) uart_transmit_data_spi_ss1__0__HSIOM)
    #define uart_transmit_data_SS1_HSIOM_PTR  ( (reg32 *) uart_transmit_data_spi_ss1__0__HSIOM)
    
    #define uart_transmit_data_SS1_HSIOM_MASK     (uart_transmit_data_spi_ss1__0__HSIOM_MASK)
    #define uart_transmit_data_SS1_HSIOM_POS      (uart_transmit_data_spi_ss1__0__HSIOM_SHIFT)
    #define uart_transmit_data_SS1_HSIOM_SEL_GPIO (uart_transmit_data_spi_ss1__0__HSIOM_GPIO)
    #define uart_transmit_data_SS1_HSIOM_SEL_I2C  (uart_transmit_data_spi_ss1__0__HSIOM_I2C)
    #define uart_transmit_data_SS1_HSIOM_SEL_SPI  (uart_transmit_data_spi_ss1__0__HSIOM_SPI)
#endif /* (uart_transmit_data_SS1_PIN) */

#if (uart_transmit_data_SS2_PIN)
    #define uart_transmit_data_SS2_HSIOM_REG     (*(reg32 *) uart_transmit_data_spi_ss2__0__HSIOM)
    #define uart_transmit_data_SS2_HSIOM_PTR     ( (reg32 *) uart_transmit_data_spi_ss2__0__HSIOM)
    
    #define uart_transmit_data_SS2_HSIOM_MASK     (uart_transmit_data_spi_ss2__0__HSIOM_MASK)
    #define uart_transmit_data_SS2_HSIOM_POS      (uart_transmit_data_spi_ss2__0__HSIOM_SHIFT)
    #define uart_transmit_data_SS2_HSIOM_SEL_GPIO (uart_transmit_data_spi_ss2__0__HSIOM_GPIO)
    #define uart_transmit_data_SS2_HSIOM_SEL_I2C  (uart_transmit_data_spi_ss2__0__HSIOM_I2C)
    #define uart_transmit_data_SS2_HSIOM_SEL_SPI  (uart_transmit_data_spi_ss2__0__HSIOM_SPI)
#endif /* (uart_transmit_data_SS2_PIN) */

#if (uart_transmit_data_SS3_PIN)
    #define uart_transmit_data_SS3_HSIOM_REG     (*(reg32 *) uart_transmit_data_spi_ss3__0__HSIOM)
    #define uart_transmit_data_SS3_HSIOM_PTR     ( (reg32 *) uart_transmit_data_spi_ss3__0__HSIOM)
    
    #define uart_transmit_data_SS3_HSIOM_MASK     (uart_transmit_data_spi_ss3__0__HSIOM_MASK)
    #define uart_transmit_data_SS3_HSIOM_POS      (uart_transmit_data_spi_ss3__0__HSIOM_SHIFT)
    #define uart_transmit_data_SS3_HSIOM_SEL_GPIO (uart_transmit_data_spi_ss3__0__HSIOM_GPIO)
    #define uart_transmit_data_SS3_HSIOM_SEL_I2C  (uart_transmit_data_spi_ss3__0__HSIOM_I2C)
    #define uart_transmit_data_SS3_HSIOM_SEL_SPI  (uart_transmit_data_spi_ss3__0__HSIOM_SPI)
#endif /* (uart_transmit_data_SS3_PIN) */

#if (uart_transmit_data_I2C_PINS)
    #define uart_transmit_data_SCL_HSIOM_REG  (*(reg32 *) uart_transmit_data_scl__0__HSIOM)
    #define uart_transmit_data_SCL_HSIOM_PTR  ( (reg32 *) uart_transmit_data_scl__0__HSIOM)
    
    #define uart_transmit_data_SCL_HSIOM_MASK     (uart_transmit_data_scl__0__HSIOM_MASK)
    #define uart_transmit_data_SCL_HSIOM_POS      (uart_transmit_data_scl__0__HSIOM_SHIFT)
    #define uart_transmit_data_SCL_HSIOM_SEL_GPIO (uart_transmit_data_sda__0__HSIOM_GPIO)
    #define uart_transmit_data_SCL_HSIOM_SEL_I2C  (uart_transmit_data_sda__0__HSIOM_I2C)
    
    #define uart_transmit_data_SDA_HSIOM_REG  (*(reg32 *) uart_transmit_data_sda__0__HSIOM)
    #define uart_transmit_data_SDA_HSIOM_PTR  ( (reg32 *) uart_transmit_data_sda__0__HSIOM)
    
    #define uart_transmit_data_SDA_HSIOM_MASK     (uart_transmit_data_sda__0__HSIOM_MASK)
    #define uart_transmit_data_SDA_HSIOM_POS      (uart_transmit_data_sda__0__HSIOM_SHIFT)
    #define uart_transmit_data_SDA_HSIOM_SEL_GPIO (uart_transmit_data_sda__0__HSIOM_GPIO)
    #define uart_transmit_data_SDA_HSIOM_SEL_I2C  (uart_transmit_data_sda__0__HSIOM_I2C)
#endif /* (uart_transmit_data_I2C_PINS) */

#if (uart_transmit_data_SPI_SLAVE_PINS)
    #define uart_transmit_data_SCLK_S_HSIOM_REG   (*(reg32 *) uart_transmit_data_sclk_s__0__HSIOM)
    #define uart_transmit_data_SCLK_S_HSIOM_PTR   ( (reg32 *) uart_transmit_data_sclk_s__0__HSIOM)
    
    #define uart_transmit_data_SCLK_S_HSIOM_MASK      (uart_transmit_data_sclk_s__0__HSIOM_MASK)
    #define uart_transmit_data_SCLK_S_HSIOM_POS       (uart_transmit_data_sclk_s__0__HSIOM_SHIFT)
    #define uart_transmit_data_SCLK_S_HSIOM_SEL_GPIO  (uart_transmit_data_sclk_s__0__HSIOM_GPIO)
    #define uart_transmit_data_SCLK_S_HSIOM_SEL_SPI   (uart_transmit_data_sclk_s__0__HSIOM_SPI)
    
    #define uart_transmit_data_SS0_S_HSIOM_REG    (*(reg32 *) uart_transmit_data_ss0_s__0__HSIOM)
    #define uart_transmit_data_SS0_S_HSIOM_PTR    ( (reg32 *) uart_transmit_data_ss0_s__0__HSIOM)
    
    #define uart_transmit_data_SS0_S_HSIOM_MASK       (uart_transmit_data_ss0_s__0__HSIOM_MASK)
    #define uart_transmit_data_SS0_S_HSIOM_POS        (uart_transmit_data_ss0_s__0__HSIOM_SHIFT)
    #define uart_transmit_data_SS0_S_HSIOM_SEL_GPIO   (uart_transmit_data_ss0_s__0__HSIOM_GPIO)  
    #define uart_transmit_data_SS0_S_HSIOM_SEL_SPI    (uart_transmit_data_ss0_s__0__HSIOM_SPI)
#endif /* (uart_transmit_data_SPI_SLAVE_PINS) */

#if (uart_transmit_data_SPI_SLAVE_MOSI_PIN)
    #define uart_transmit_data_MOSI_S_HSIOM_REG   (*(reg32 *) uart_transmit_data_mosi_s__0__HSIOM)
    #define uart_transmit_data_MOSI_S_HSIOM_PTR   ( (reg32 *) uart_transmit_data_mosi_s__0__HSIOM)
    
    #define uart_transmit_data_MOSI_S_HSIOM_MASK      (uart_transmit_data_mosi_s__0__HSIOM_MASK)
    #define uart_transmit_data_MOSI_S_HSIOM_POS       (uart_transmit_data_mosi_s__0__HSIOM_SHIFT)
    #define uart_transmit_data_MOSI_S_HSIOM_SEL_GPIO  (uart_transmit_data_mosi_s__0__HSIOM_GPIO)
    #define uart_transmit_data_MOSI_S_HSIOM_SEL_SPI   (uart_transmit_data_mosi_s__0__HSIOM_SPI)
#endif /* (uart_transmit_data_SPI_SLAVE_MOSI_PIN) */

#if (uart_transmit_data_SPI_SLAVE_MISO_PIN)
    #define uart_transmit_data_MISO_S_HSIOM_REG   (*(reg32 *) uart_transmit_data_miso_s__0__HSIOM)
    #define uart_transmit_data_MISO_S_HSIOM_PTR   ( (reg32 *) uart_transmit_data_miso_s__0__HSIOM)
    
    #define uart_transmit_data_MISO_S_HSIOM_MASK      (uart_transmit_data_miso_s__0__HSIOM_MASK)
    #define uart_transmit_data_MISO_S_HSIOM_POS       (uart_transmit_data_miso_s__0__HSIOM_SHIFT)
    #define uart_transmit_data_MISO_S_HSIOM_SEL_GPIO  (uart_transmit_data_miso_s__0__HSIOM_GPIO)
    #define uart_transmit_data_MISO_S_HSIOM_SEL_SPI   (uart_transmit_data_miso_s__0__HSIOM_SPI)
#endif /* (uart_transmit_data_SPI_SLAVE_MISO_PIN) */

#if (uart_transmit_data_SPI_MASTER_MISO_PIN)
    #define uart_transmit_data_MISO_M_HSIOM_REG   (*(reg32 *) uart_transmit_data_miso_m__0__HSIOM)
    #define uart_transmit_data_MISO_M_HSIOM_PTR   ( (reg32 *) uart_transmit_data_miso_m__0__HSIOM)
    
    #define uart_transmit_data_MISO_M_HSIOM_MASK      (uart_transmit_data_miso_m__0__HSIOM_MASK)
    #define uart_transmit_data_MISO_M_HSIOM_POS       (uart_transmit_data_miso_m__0__HSIOM_SHIFT)
    #define uart_transmit_data_MISO_M_HSIOM_SEL_GPIO  (uart_transmit_data_miso_m__0__HSIOM_GPIO)
    #define uart_transmit_data_MISO_M_HSIOM_SEL_SPI   (uart_transmit_data_miso_m__0__HSIOM_SPI)
#endif /* (uart_transmit_data_SPI_MASTER_MISO_PIN) */

#if (uart_transmit_data_SPI_MASTER_MOSI_PIN)
    #define uart_transmit_data_MOSI_M_HSIOM_REG   (*(reg32 *) uart_transmit_data_mosi_m__0__HSIOM)
    #define uart_transmit_data_MOSI_M_HSIOM_PTR   ( (reg32 *) uart_transmit_data_mosi_m__0__HSIOM)
    
    #define uart_transmit_data_MOSI_M_HSIOM_MASK      (uart_transmit_data_mosi_m__0__HSIOM_MASK)
    #define uart_transmit_data_MOSI_M_HSIOM_POS       (uart_transmit_data_mosi_m__0__HSIOM_SHIFT)
    #define uart_transmit_data_MOSI_M_HSIOM_SEL_GPIO  (uart_transmit_data_mosi_m__0__HSIOM_GPIO)
    #define uart_transmit_data_MOSI_M_HSIOM_SEL_SPI   (uart_transmit_data_mosi_m__0__HSIOM_SPI)
#endif /* (uart_transmit_data_SPI_MASTER_MOSI_PIN) */

#if (uart_transmit_data_SPI_MASTER_SCLK_PIN)
    #define uart_transmit_data_SCLK_M_HSIOM_REG   (*(reg32 *) uart_transmit_data_sclk_m__0__HSIOM)
    #define uart_transmit_data_SCLK_M_HSIOM_PTR   ( (reg32 *) uart_transmit_data_sclk_m__0__HSIOM)
    
    #define uart_transmit_data_SCLK_M_HSIOM_MASK      (uart_transmit_data_sclk_m__0__HSIOM_MASK)
    #define uart_transmit_data_SCLK_M_HSIOM_POS       (uart_transmit_data_sclk_m__0__HSIOM_SHIFT)
    #define uart_transmit_data_SCLK_M_HSIOM_SEL_GPIO  (uart_transmit_data_sclk_m__0__HSIOM_GPIO)
    #define uart_transmit_data_SCLK_M_HSIOM_SEL_SPI   (uart_transmit_data_sclk_m__0__HSIOM_SPI)
#endif /* (uart_transmit_data_SPI_MASTER_SCLK_PIN) */

#if (uart_transmit_data_SPI_MASTER_SS0_PIN)
    #define uart_transmit_data_SS0_M_HSIOM_REG    (*(reg32 *) uart_transmit_data_ss0_m__0__HSIOM)
    #define uart_transmit_data_SS0_M_HSIOM_PTR    ( (reg32 *) uart_transmit_data_ss0_m__0__HSIOM)
    
    #define uart_transmit_data_SS0_M_HSIOM_MASK       (uart_transmit_data_ss0_m__0__HSIOM_MASK)
    #define uart_transmit_data_SS0_M_HSIOM_POS        (uart_transmit_data_ss0_m__0__HSIOM_SHIFT)
    #define uart_transmit_data_SS0_M_HSIOM_SEL_GPIO   (uart_transmit_data_ss0_m__0__HSIOM_GPIO)
    #define uart_transmit_data_SS0_M_HSIOM_SEL_SPI    (uart_transmit_data_ss0_m__0__HSIOM_SPI)
#endif /* (uart_transmit_data_SPI_MASTER_SS0_PIN) */

#if (uart_transmit_data_SPI_MASTER_SS1_PIN)
    #define uart_transmit_data_SS1_M_HSIOM_REG    (*(reg32 *) uart_transmit_data_ss1_m__0__HSIOM)
    #define uart_transmit_data_SS1_M_HSIOM_PTR    ( (reg32 *) uart_transmit_data_ss1_m__0__HSIOM)
    
    #define uart_transmit_data_SS1_M_HSIOM_MASK       (uart_transmit_data_ss1_m__0__HSIOM_MASK)
    #define uart_transmit_data_SS1_M_HSIOM_POS        (uart_transmit_data_ss1_m__0__HSIOM_SHIFT)
    #define uart_transmit_data_SS1_M_HSIOM_SEL_GPIO   (uart_transmit_data_ss1_m__0__HSIOM_GPIO)
    #define uart_transmit_data_SS1_M_HSIOM_SEL_SPI    (uart_transmit_data_ss1_m__0__HSIOM_SPI)
#endif /* (uart_transmit_data_SPI_MASTER_SS1_PIN) */

#if (uart_transmit_data_SPI_MASTER_SS2_PIN)
    #define uart_transmit_data_SS2_M_HSIOM_REG    (*(reg32 *) uart_transmit_data_ss2_m__0__HSIOM)
    #define uart_transmit_data_SS2_M_HSIOM_PTR    ( (reg32 *) uart_transmit_data_ss2_m__0__HSIOM)
    
    #define uart_transmit_data_SS2_M_HSIOM_MASK       (uart_transmit_data_ss2_m__0__HSIOM_MASK)
    #define uart_transmit_data_SS2_M_HSIOM_POS        (uart_transmit_data_ss2_m__0__HSIOM_SHIFT)
    #define uart_transmit_data_SS2_M_HSIOM_SEL_GPIO   (uart_transmit_data_ss2_m__0__HSIOM_GPIO)
    #define uart_transmit_data_SS2_M_HSIOM_SEL_SPI    (uart_transmit_data_ss2_m__0__HSIOM_SPI)
#endif /* (uart_transmit_data_SPI_MASTER_SS2_PIN) */

#if (uart_transmit_data_SPI_MASTER_SS3_PIN)
    #define uart_transmit_data_SS3_M_HSIOM_REG    (*(reg32 *) uart_transmit_data_ss3_m__0__HSIOM)
    #define uart_transmit_data_SS3_M_HSIOM_PTR    ( (reg32 *) uart_transmit_data_ss3_m__0__HSIOM)
    
    #define uart_transmit_data_SS3_M_HSIOM_MASK      (uart_transmit_data_ss3_m__0__HSIOM_MASK)
    #define uart_transmit_data_SS3_M_HSIOM_POS       (uart_transmit_data_ss3_m__0__HSIOM_SHIFT)
    #define uart_transmit_data_SS3_M_HSIOM_SEL_GPIO  (uart_transmit_data_ss3_m__0__HSIOM_GPIO)
    #define uart_transmit_data_SS3_M_HSIOM_SEL_SPI   (uart_transmit_data_ss3_m__0__HSIOM_SPI)
#endif /* (uart_transmit_data_SPI_MASTER_SS3_PIN) */

#if (uart_transmit_data_UART_RX_PIN)
    #define uart_transmit_data_RX_HSIOM_REG   (*(reg32 *) uart_transmit_data_rx__0__HSIOM)
    #define uart_transmit_data_RX_HSIOM_PTR   ( (reg32 *) uart_transmit_data_rx__0__HSIOM)
    
    #define uart_transmit_data_RX_HSIOM_MASK      (uart_transmit_data_rx__0__HSIOM_MASK)
    #define uart_transmit_data_RX_HSIOM_POS       (uart_transmit_data_rx__0__HSIOM_SHIFT)
    #define uart_transmit_data_RX_HSIOM_SEL_GPIO  (uart_transmit_data_rx__0__HSIOM_GPIO)
    #define uart_transmit_data_RX_HSIOM_SEL_UART  (uart_transmit_data_rx__0__HSIOM_UART)
#endif /* (uart_transmit_data_UART_RX_PIN) */

#if (uart_transmit_data_UART_RX_WAKE_PIN)
    #define uart_transmit_data_RX_WAKE_HSIOM_REG   (*(reg32 *) uart_transmit_data_rx_wake__0__HSIOM)
    #define uart_transmit_data_RX_WAKE_HSIOM_PTR   ( (reg32 *) uart_transmit_data_rx_wake__0__HSIOM)
    
    #define uart_transmit_data_RX_WAKE_HSIOM_MASK      (uart_transmit_data_rx_wake__0__HSIOM_MASK)
    #define uart_transmit_data_RX_WAKE_HSIOM_POS       (uart_transmit_data_rx_wake__0__HSIOM_SHIFT)
    #define uart_transmit_data_RX_WAKE_HSIOM_SEL_GPIO  (uart_transmit_data_rx_wake__0__HSIOM_GPIO)
    #define uart_transmit_data_RX_WAKE_HSIOM_SEL_UART  (uart_transmit_data_rx_wake__0__HSIOM_UART)
#endif /* (uart_transmit_data_UART_WAKE_RX_PIN) */

#if (uart_transmit_data_UART_CTS_PIN)
    #define uart_transmit_data_CTS_HSIOM_REG   (*(reg32 *) uart_transmit_data_cts__0__HSIOM)
    #define uart_transmit_data_CTS_HSIOM_PTR   ( (reg32 *) uart_transmit_data_cts__0__HSIOM)
    
    #define uart_transmit_data_CTS_HSIOM_MASK      (uart_transmit_data_cts__0__HSIOM_MASK)
    #define uart_transmit_data_CTS_HSIOM_POS       (uart_transmit_data_cts__0__HSIOM_SHIFT)
    #define uart_transmit_data_CTS_HSIOM_SEL_GPIO  (uart_transmit_data_cts__0__HSIOM_GPIO)
    #define uart_transmit_data_CTS_HSIOM_SEL_UART  (uart_transmit_data_cts__0__HSIOM_UART)
#endif /* (uart_transmit_data_UART_CTS_PIN) */

#if (uart_transmit_data_UART_TX_PIN)
    #define uart_transmit_data_TX_HSIOM_REG   (*(reg32 *) uart_transmit_data_tx__0__HSIOM)
    #define uart_transmit_data_TX_HSIOM_PTR   ( (reg32 *) uart_transmit_data_tx__0__HSIOM)
    
    #define uart_transmit_data_TX_HSIOM_MASK      (uart_transmit_data_tx__0__HSIOM_MASK)
    #define uart_transmit_data_TX_HSIOM_POS       (uart_transmit_data_tx__0__HSIOM_SHIFT)
    #define uart_transmit_data_TX_HSIOM_SEL_GPIO  (uart_transmit_data_tx__0__HSIOM_GPIO)
    #define uart_transmit_data_TX_HSIOM_SEL_UART  (uart_transmit_data_tx__0__HSIOM_UART)
#endif /* (uart_transmit_data_UART_TX_PIN) */

#if (uart_transmit_data_UART_RX_TX_PIN)
    #define uart_transmit_data_RX_TX_HSIOM_REG   (*(reg32 *) uart_transmit_data_rx_tx__0__HSIOM)
    #define uart_transmit_data_RX_TX_HSIOM_PTR   ( (reg32 *) uart_transmit_data_rx_tx__0__HSIOM)
    
    #define uart_transmit_data_RX_TX_HSIOM_MASK      (uart_transmit_data_rx_tx__0__HSIOM_MASK)
    #define uart_transmit_data_RX_TX_HSIOM_POS       (uart_transmit_data_rx_tx__0__HSIOM_SHIFT)
    #define uart_transmit_data_RX_TX_HSIOM_SEL_GPIO  (uart_transmit_data_rx_tx__0__HSIOM_GPIO)
    #define uart_transmit_data_RX_TX_HSIOM_SEL_UART  (uart_transmit_data_rx_tx__0__HSIOM_UART)
#endif /* (uart_transmit_data_UART_RX_TX_PIN) */

#if (uart_transmit_data_UART_RTS_PIN)
    #define uart_transmit_data_RTS_HSIOM_REG      (*(reg32 *) uart_transmit_data_rts__0__HSIOM)
    #define uart_transmit_data_RTS_HSIOM_PTR      ( (reg32 *) uart_transmit_data_rts__0__HSIOM)
    
    #define uart_transmit_data_RTS_HSIOM_MASK     (uart_transmit_data_rts__0__HSIOM_MASK)
    #define uart_transmit_data_RTS_HSIOM_POS      (uart_transmit_data_rts__0__HSIOM_SHIFT)    
    #define uart_transmit_data_RTS_HSIOM_SEL_GPIO (uart_transmit_data_rts__0__HSIOM_GPIO)
    #define uart_transmit_data_RTS_HSIOM_SEL_UART (uart_transmit_data_rts__0__HSIOM_UART)    
#endif /* (uart_transmit_data_UART_RTS_PIN) */


/***************************************
*        Registers Constants
***************************************/

/* HSIOM switch values. */ 
#define uart_transmit_data_HSIOM_DEF_SEL      (0x00u)
#define uart_transmit_data_HSIOM_GPIO_SEL     (0x00u)
/* The HSIOM values provided below are valid only for uart_transmit_data_CY_SCBIP_V0 
* and uart_transmit_data_CY_SCBIP_V1. It is not recommended to use them for 
* uart_transmit_data_CY_SCBIP_V2. Use pin name specific HSIOM constants provided 
* above instead for any SCB IP block version.
*/
#define uart_transmit_data_HSIOM_UART_SEL     (0x09u)
#define uart_transmit_data_HSIOM_I2C_SEL      (0x0Eu)
#define uart_transmit_data_HSIOM_SPI_SEL      (0x0Fu)

/* Pins settings index. */
#define uart_transmit_data_RX_WAKE_SCL_MOSI_PIN_INDEX   (0u)
#define uart_transmit_data_RX_SCL_MOSI_PIN_INDEX       (0u)
#define uart_transmit_data_TX_SDA_MISO_PIN_INDEX       (1u)
#define uart_transmit_data_SCLK_PIN_INDEX       (2u)
#define uart_transmit_data_SS0_PIN_INDEX       (3u)
#define uart_transmit_data_SS1_PIN_INDEX                  (4u)
#define uart_transmit_data_SS2_PIN_INDEX                  (5u)
#define uart_transmit_data_SS3_PIN_INDEX                  (6u)

/* Pins settings mask. */
#define uart_transmit_data_RX_WAKE_SCL_MOSI_PIN_MASK ((uint32) 0x01u << uart_transmit_data_RX_WAKE_SCL_MOSI_PIN_INDEX)
#define uart_transmit_data_RX_SCL_MOSI_PIN_MASK     ((uint32) 0x01u << uart_transmit_data_RX_SCL_MOSI_PIN_INDEX)
#define uart_transmit_data_TX_SDA_MISO_PIN_MASK     ((uint32) 0x01u << uart_transmit_data_TX_SDA_MISO_PIN_INDEX)
#define uart_transmit_data_SCLK_PIN_MASK     ((uint32) 0x01u << uart_transmit_data_SCLK_PIN_INDEX)
#define uart_transmit_data_SS0_PIN_MASK     ((uint32) 0x01u << uart_transmit_data_SS0_PIN_INDEX)
#define uart_transmit_data_SS1_PIN_MASK                ((uint32) 0x01u << uart_transmit_data_SS1_PIN_INDEX)
#define uart_transmit_data_SS2_PIN_MASK                ((uint32) 0x01u << uart_transmit_data_SS2_PIN_INDEX)
#define uart_transmit_data_SS3_PIN_MASK                ((uint32) 0x01u << uart_transmit_data_SS3_PIN_INDEX)

/* Pin interrupt constants. */
#define uart_transmit_data_INTCFG_TYPE_MASK           (0x03u)
#define uart_transmit_data_INTCFG_TYPE_FALLING_EDGE   (0x02u)

/* Pin Drive Mode constants. */
#define uart_transmit_data_PIN_DM_ALG_HIZ  (0u)
#define uart_transmit_data_PIN_DM_DIG_HIZ  (1u)
#define uart_transmit_data_PIN_DM_OD_LO    (4u)
#define uart_transmit_data_PIN_DM_STRONG   (6u)


/***************************************
*          Macro Definitions
***************************************/

/* Return drive mode of the pin */
#define uart_transmit_data_DM_MASK    (0x7u)
#define uart_transmit_data_DM_SIZE    (3u)
#define uart_transmit_data_GET_P4_PIN_DM(reg, pos) \
    ( ((reg) & (uint32) ((uint32) uart_transmit_data_DM_MASK << (uart_transmit_data_DM_SIZE * (pos)))) >> \
                                                              (uart_transmit_data_DM_SIZE * (pos)) )

#if (uart_transmit_data_TX_SDA_MISO_PIN)
    #define uart_transmit_data_CHECK_TX_SDA_MISO_PIN_USED \
                (uart_transmit_data_PIN_DM_ALG_HIZ != \
                    uart_transmit_data_GET_P4_PIN_DM(uart_transmit_data_uart_tx_i2c_sda_spi_miso_PC, \
                                                   uart_transmit_data_uart_tx_i2c_sda_spi_miso_SHIFT))
#endif /* (uart_transmit_data_TX_SDA_MISO_PIN) */

#if (uart_transmit_data_SS0_PIN)
    #define uart_transmit_data_CHECK_SS0_PIN_USED \
                (uart_transmit_data_PIN_DM_ALG_HIZ != \
                    uart_transmit_data_GET_P4_PIN_DM(uart_transmit_data_spi_ss0_PC, \
                                                   uart_transmit_data_spi_ss0_SHIFT))
#endif /* (uart_transmit_data_SS0_PIN) */

/* Set bits-mask in register */
#define uart_transmit_data_SET_REGISTER_BITS(reg, mask, pos, mode) \
                    do                                           \
                    {                                            \
                        (reg) = (((reg) & ((uint32) ~(uint32) (mask))) | ((uint32) ((uint32) (mode) << (pos)))); \
                    }while(0)

/* Set bit in the register */
#define uart_transmit_data_SET_REGISTER_BIT(reg, mask, val) \
                    ((val) ? ((reg) |= (mask)) : ((reg) &= ((uint32) ~((uint32) (mask)))))

#define uart_transmit_data_SET_HSIOM_SEL(reg, mask, pos, sel) uart_transmit_data_SET_REGISTER_BITS(reg, mask, pos, sel)
#define uart_transmit_data_SET_INCFG_TYPE(reg, mask, pos, intType) \
                                                        uart_transmit_data_SET_REGISTER_BITS(reg, mask, pos, intType)
#define uart_transmit_data_SET_INP_DIS(reg, mask, val) uart_transmit_data_SET_REGISTER_BIT(reg, mask, val)

/* uart_transmit_data_SET_I2C_SCL_DR(val) - Sets I2C SCL DR register.
*  uart_transmit_data_SET_I2C_SCL_HSIOM_SEL(sel) - Sets I2C SCL HSIOM settings.
*/
/* SCB I2C: scl signal */
#if (uart_transmit_data_CY_SCBIP_V0)
#if (uart_transmit_data_I2C_PINS)
    #define uart_transmit_data_SET_I2C_SCL_DR(val) uart_transmit_data_scl_Write(val)

    #define uart_transmit_data_SET_I2C_SCL_HSIOM_SEL(sel) \
                          uart_transmit_data_SET_HSIOM_SEL(uart_transmit_data_SCL_HSIOM_REG,  \
                                                         uart_transmit_data_SCL_HSIOM_MASK, \
                                                         uart_transmit_data_SCL_HSIOM_POS,  \
                                                         (sel))
    #define uart_transmit_data_WAIT_SCL_SET_HIGH  (0u == uart_transmit_data_scl_Read())

/* Unconfigured SCB: scl signal */
#elif (uart_transmit_data_RX_WAKE_SCL_MOSI_PIN)
    #define uart_transmit_data_SET_I2C_SCL_DR(val) \
                            uart_transmit_data_uart_rx_wake_i2c_scl_spi_mosi_Write(val)

    #define uart_transmit_data_SET_I2C_SCL_HSIOM_SEL(sel) \
                    uart_transmit_data_SET_HSIOM_SEL(uart_transmit_data_RX_WAKE_SCL_MOSI_HSIOM_REG,  \
                                                   uart_transmit_data_RX_WAKE_SCL_MOSI_HSIOM_MASK, \
                                                   uart_transmit_data_RX_WAKE_SCL_MOSI_HSIOM_POS,  \
                                                   (sel))

    #define uart_transmit_data_WAIT_SCL_SET_HIGH  (0u == uart_transmit_data_uart_rx_wake_i2c_scl_spi_mosi_Read())

#elif (uart_transmit_data_RX_SCL_MOSI_PIN)
    #define uart_transmit_data_SET_I2C_SCL_DR(val) \
                            uart_transmit_data_uart_rx_i2c_scl_spi_mosi_Write(val)


    #define uart_transmit_data_SET_I2C_SCL_HSIOM_SEL(sel) \
                            uart_transmit_data_SET_HSIOM_SEL(uart_transmit_data_RX_SCL_MOSI_HSIOM_REG,  \
                                                           uart_transmit_data_RX_SCL_MOSI_HSIOM_MASK, \
                                                           uart_transmit_data_RX_SCL_MOSI_HSIOM_POS,  \
                                                           (sel))

    #define uart_transmit_data_WAIT_SCL_SET_HIGH  (0u == uart_transmit_data_uart_rx_i2c_scl_spi_mosi_Read())

#else
    #define uart_transmit_data_SET_I2C_SCL_DR(val)        do{ /* Does nothing */ }while(0)
    #define uart_transmit_data_SET_I2C_SCL_HSIOM_SEL(sel) do{ /* Does nothing */ }while(0)

    #define uart_transmit_data_WAIT_SCL_SET_HIGH  (0u)
#endif /* (uart_transmit_data_I2C_PINS) */

/* SCB I2C: sda signal */
#if (uart_transmit_data_I2C_PINS)
    #define uart_transmit_data_WAIT_SDA_SET_HIGH  (0u == uart_transmit_data_sda_Read())
/* Unconfigured SCB: sda signal */
#elif (uart_transmit_data_TX_SDA_MISO_PIN)
    #define uart_transmit_data_WAIT_SDA_SET_HIGH  (0u == uart_transmit_data_uart_tx_i2c_sda_spi_miso_Read())
#else
    #define uart_transmit_data_WAIT_SDA_SET_HIGH  (0u)
#endif /* (uart_transmit_data_MOSI_SCL_RX_PIN) */
#endif /* (uart_transmit_data_CY_SCBIP_V0) */

/* Clear UART wakeup source */
#if (uart_transmit_data_RX_SCL_MOSI_PIN)
    #define uart_transmit_data_CLEAR_UART_RX_WAKE_INTR        do{ /* Does nothing */ }while(0)
    
#elif (uart_transmit_data_RX_WAKE_SCL_MOSI_PIN)
    #define uart_transmit_data_CLEAR_UART_RX_WAKE_INTR \
            do{                                      \
                (void) uart_transmit_data_uart_rx_wake_i2c_scl_spi_mosi_ClearInterrupt(); \
            }while(0)

#elif(uart_transmit_data_UART_RX_WAKE_PIN)
    #define uart_transmit_data_CLEAR_UART_RX_WAKE_INTR \
            do{                                      \
                (void) uart_transmit_data_rx_wake_ClearInterrupt(); \
            }while(0)
#else
#endif /* (uart_transmit_data_RX_SCL_MOSI_PIN) */


/***************************************
* The following code is DEPRECATED and
* must not be used.
***************************************/

/* Unconfigured pins */
#define uart_transmit_data_REMOVE_MOSI_SCL_RX_WAKE_PIN    uart_transmit_data_REMOVE_RX_WAKE_SCL_MOSI_PIN
#define uart_transmit_data_REMOVE_MOSI_SCL_RX_PIN         uart_transmit_data_REMOVE_RX_SCL_MOSI_PIN
#define uart_transmit_data_REMOVE_MISO_SDA_TX_PIN         uart_transmit_data_REMOVE_TX_SDA_MISO_PIN
#ifndef uart_transmit_data_REMOVE_SCLK_PIN
#define uart_transmit_data_REMOVE_SCLK_PIN                uart_transmit_data_REMOVE_SCLK_PIN
#endif /* uart_transmit_data_REMOVE_SCLK_PIN */
#ifndef uart_transmit_data_REMOVE_SS0_PIN
#define uart_transmit_data_REMOVE_SS0_PIN                 uart_transmit_data_REMOVE_SS0_PIN
#endif /* uart_transmit_data_REMOVE_SS0_PIN */

/* Unconfigured pins */
#define uart_transmit_data_MOSI_SCL_RX_WAKE_PIN   uart_transmit_data_RX_WAKE_SCL_MOSI_PIN
#define uart_transmit_data_MOSI_SCL_RX_PIN        uart_transmit_data_RX_SCL_MOSI_PIN
#define uart_transmit_data_MISO_SDA_TX_PIN        uart_transmit_data_TX_SDA_MISO_PIN
#ifndef uart_transmit_data_SCLK_PIN
#define uart_transmit_data_SCLK_PIN               uart_transmit_data_SCLK_PIN
#endif /* uart_transmit_data_SCLK_PIN */
#ifndef uart_transmit_data_SS0_PIN
#define uart_transmit_data_SS0_PIN                uart_transmit_data_SS0_PIN
#endif /* uart_transmit_data_SS0_PIN */

#if (uart_transmit_data_MOSI_SCL_RX_WAKE_PIN)
    #define uart_transmit_data_MOSI_SCL_RX_WAKE_HSIOM_REG     uart_transmit_data_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define uart_transmit_data_MOSI_SCL_RX_WAKE_HSIOM_PTR     uart_transmit_data_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define uart_transmit_data_MOSI_SCL_RX_WAKE_HSIOM_MASK    uart_transmit_data_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define uart_transmit_data_MOSI_SCL_RX_WAKE_HSIOM_POS     uart_transmit_data_RX_WAKE_SCL_MOSI_HSIOM_REG

    #define uart_transmit_data_MOSI_SCL_RX_WAKE_INTCFG_REG    uart_transmit_data_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define uart_transmit_data_MOSI_SCL_RX_WAKE_INTCFG_PTR    uart_transmit_data_RX_WAKE_SCL_MOSI_HSIOM_REG

    #define uart_transmit_data_MOSI_SCL_RX_WAKE_INTCFG_TYPE_POS   uart_transmit_data_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define uart_transmit_data_MOSI_SCL_RX_WAKE_INTCFG_TYPE_MASK  uart_transmit_data_RX_WAKE_SCL_MOSI_HSIOM_REG
#endif /* (uart_transmit_data_RX_WAKE_SCL_MOSI_PIN) */

#if (uart_transmit_data_MOSI_SCL_RX_PIN)
    #define uart_transmit_data_MOSI_SCL_RX_HSIOM_REG      uart_transmit_data_RX_SCL_MOSI_HSIOM_REG
    #define uart_transmit_data_MOSI_SCL_RX_HSIOM_PTR      uart_transmit_data_RX_SCL_MOSI_HSIOM_PTR
    #define uart_transmit_data_MOSI_SCL_RX_HSIOM_MASK     uart_transmit_data_RX_SCL_MOSI_HSIOM_MASK
    #define uart_transmit_data_MOSI_SCL_RX_HSIOM_POS      uart_transmit_data_RX_SCL_MOSI_HSIOM_POS
#endif /* (uart_transmit_data_MOSI_SCL_RX_PIN) */

#if (uart_transmit_data_MISO_SDA_TX_PIN)
    #define uart_transmit_data_MISO_SDA_TX_HSIOM_REG      uart_transmit_data_TX_SDA_MISO_HSIOM_REG
    #define uart_transmit_data_MISO_SDA_TX_HSIOM_PTR      uart_transmit_data_TX_SDA_MISO_HSIOM_REG
    #define uart_transmit_data_MISO_SDA_TX_HSIOM_MASK     uart_transmit_data_TX_SDA_MISO_HSIOM_REG
    #define uart_transmit_data_MISO_SDA_TX_HSIOM_POS      uart_transmit_data_TX_SDA_MISO_HSIOM_REG
#endif /* (uart_transmit_data_MISO_SDA_TX_PIN_PIN) */

#if (uart_transmit_data_SCLK_PIN)
    #ifndef uart_transmit_data_SCLK_HSIOM_REG
    #define uart_transmit_data_SCLK_HSIOM_REG     uart_transmit_data_SCLK_HSIOM_REG
    #define uart_transmit_data_SCLK_HSIOM_PTR     uart_transmit_data_SCLK_HSIOM_PTR
    #define uart_transmit_data_SCLK_HSIOM_MASK    uart_transmit_data_SCLK_HSIOM_MASK
    #define uart_transmit_data_SCLK_HSIOM_POS     uart_transmit_data_SCLK_HSIOM_POS
    #endif /* uart_transmit_data_SCLK_HSIOM_REG */
#endif /* (uart_transmit_data_SCLK_PIN) */

#if (uart_transmit_data_SS0_PIN)
    #ifndef uart_transmit_data_SS0_HSIOM_REG
    #define uart_transmit_data_SS0_HSIOM_REG      uart_transmit_data_SS0_HSIOM_REG
    #define uart_transmit_data_SS0_HSIOM_PTR      uart_transmit_data_SS0_HSIOM_PTR
    #define uart_transmit_data_SS0_HSIOM_MASK     uart_transmit_data_SS0_HSIOM_MASK
    #define uart_transmit_data_SS0_HSIOM_POS      uart_transmit_data_SS0_HSIOM_POS
    #endif /* uart_transmit_data_SS0_HSIOM_REG */
#endif /* (uart_transmit_data_SS0_PIN) */

#define uart_transmit_data_MOSI_SCL_RX_WAKE_PIN_INDEX uart_transmit_data_RX_WAKE_SCL_MOSI_PIN_INDEX
#define uart_transmit_data_MOSI_SCL_RX_PIN_INDEX      uart_transmit_data_RX_SCL_MOSI_PIN_INDEX
#define uart_transmit_data_MISO_SDA_TX_PIN_INDEX      uart_transmit_data_TX_SDA_MISO_PIN_INDEX
#ifndef uart_transmit_data_SCLK_PIN_INDEX
#define uart_transmit_data_SCLK_PIN_INDEX             uart_transmit_data_SCLK_PIN_INDEX
#endif /* uart_transmit_data_SCLK_PIN_INDEX */
#ifndef uart_transmit_data_SS0_PIN_INDEX
#define uart_transmit_data_SS0_PIN_INDEX              uart_transmit_data_SS0_PIN_INDEX
#endif /* uart_transmit_data_SS0_PIN_INDEX */

#define uart_transmit_data_MOSI_SCL_RX_WAKE_PIN_MASK uart_transmit_data_RX_WAKE_SCL_MOSI_PIN_MASK
#define uart_transmit_data_MOSI_SCL_RX_PIN_MASK      uart_transmit_data_RX_SCL_MOSI_PIN_MASK
#define uart_transmit_data_MISO_SDA_TX_PIN_MASK      uart_transmit_data_TX_SDA_MISO_PIN_MASK
#ifndef uart_transmit_data_SCLK_PIN_MASK
#define uart_transmit_data_SCLK_PIN_MASK             uart_transmit_data_SCLK_PIN_MASK
#endif /* uart_transmit_data_SCLK_PIN_MASK */
#ifndef uart_transmit_data_SS0_PIN_MASK
#define uart_transmit_data_SS0_PIN_MASK              uart_transmit_data_SS0_PIN_MASK
#endif /* uart_transmit_data_SS0_PIN_MASK */

#endif /* (CY_SCB_PINS_uart_transmit_data_H) */


/* [] END OF FILE */
