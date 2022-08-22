/*******************************************************************************
* File Name: lcd_LCDPort.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_lcd_LCDPort_H) /* Pins lcd_LCDPort_H */
#define CY_PINS_lcd_LCDPort_H

#include "cytypes.h"
#include "cyfitter.h"
#include "lcd_LCDPort_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} lcd_LCDPort_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   lcd_LCDPort_Read(void);
void    lcd_LCDPort_Write(uint8 value);
uint8   lcd_LCDPort_ReadDataReg(void);
#if defined(lcd_LCDPort__PC) || (CY_PSOC4_4200L) 
    void    lcd_LCDPort_SetDriveMode(uint8 mode);
#endif
void    lcd_LCDPort_SetInterruptMode(uint16 position, uint16 mode);
uint8   lcd_LCDPort_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void lcd_LCDPort_Sleep(void); 
void lcd_LCDPort_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(lcd_LCDPort__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define lcd_LCDPort_DRIVE_MODE_BITS        (3)
    #define lcd_LCDPort_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - lcd_LCDPort_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the lcd_LCDPort_SetDriveMode() function.
         *  @{
         */
        #define lcd_LCDPort_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define lcd_LCDPort_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define lcd_LCDPort_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define lcd_LCDPort_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define lcd_LCDPort_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define lcd_LCDPort_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define lcd_LCDPort_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define lcd_LCDPort_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define lcd_LCDPort_MASK               lcd_LCDPort__MASK
#define lcd_LCDPort_SHIFT              lcd_LCDPort__SHIFT
#define lcd_LCDPort_WIDTH              7u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in lcd_LCDPort_SetInterruptMode() function.
     *  @{
     */
        #define lcd_LCDPort_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define lcd_LCDPort_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define lcd_LCDPort_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define lcd_LCDPort_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(lcd_LCDPort__SIO)
    #define lcd_LCDPort_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(lcd_LCDPort__PC) && (CY_PSOC4_4200L)
    #define lcd_LCDPort_USBIO_ENABLE               ((uint32)0x80000000u)
    #define lcd_LCDPort_USBIO_DISABLE              ((uint32)(~lcd_LCDPort_USBIO_ENABLE))
    #define lcd_LCDPort_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define lcd_LCDPort_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define lcd_LCDPort_USBIO_ENTER_SLEEP          ((uint32)((1u << lcd_LCDPort_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << lcd_LCDPort_USBIO_SUSPEND_DEL_SHIFT)))
    #define lcd_LCDPort_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << lcd_LCDPort_USBIO_SUSPEND_SHIFT)))
    #define lcd_LCDPort_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << lcd_LCDPort_USBIO_SUSPEND_DEL_SHIFT)))
    #define lcd_LCDPort_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(lcd_LCDPort__PC)
    /* Port Configuration */
    #define lcd_LCDPort_PC                 (* (reg32 *) lcd_LCDPort__PC)
#endif
/* Pin State */
#define lcd_LCDPort_PS                     (* (reg32 *) lcd_LCDPort__PS)
/* Data Register */
#define lcd_LCDPort_DR                     (* (reg32 *) lcd_LCDPort__DR)
/* Input Buffer Disable Override */
#define lcd_LCDPort_INP_DIS                (* (reg32 *) lcd_LCDPort__PC2)

/* Interrupt configuration Registers */
#define lcd_LCDPort_INTCFG                 (* (reg32 *) lcd_LCDPort__INTCFG)
#define lcd_LCDPort_INTSTAT                (* (reg32 *) lcd_LCDPort__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define lcd_LCDPort_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(lcd_LCDPort__SIO)
    #define lcd_LCDPort_SIO_REG            (* (reg32 *) lcd_LCDPort__SIO)
#endif /* (lcd_LCDPort__SIO_CFG) */

/* USBIO registers */
#if !defined(lcd_LCDPort__PC) && (CY_PSOC4_4200L)
    #define lcd_LCDPort_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define lcd_LCDPort_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define lcd_LCDPort_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define lcd_LCDPort_DRIVE_MODE_SHIFT       (0x00u)
#define lcd_LCDPort_DRIVE_MODE_MASK        (0x07u << lcd_LCDPort_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins lcd_LCDPort_H */


/* [] END OF FILE */
