/*******************************************************************************
* File Name: button_single.h  
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

#if !defined(CY_PINS_button_single_H) /* Pins button_single_H */
#define CY_PINS_button_single_H

#include "cytypes.h"
#include "cyfitter.h"
#include "button_single_aliases.h"


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
} button_single_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   button_single_Read(void);
void    button_single_Write(uint8 value);
uint8   button_single_ReadDataReg(void);
#if defined(button_single__PC) || (CY_PSOC4_4200L) 
    void    button_single_SetDriveMode(uint8 mode);
#endif
void    button_single_SetInterruptMode(uint16 position, uint16 mode);
uint8   button_single_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void button_single_Sleep(void); 
void button_single_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(button_single__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define button_single_DRIVE_MODE_BITS        (3)
    #define button_single_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - button_single_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the button_single_SetDriveMode() function.
         *  @{
         */
        #define button_single_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define button_single_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define button_single_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define button_single_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define button_single_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define button_single_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define button_single_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define button_single_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define button_single_MASK               button_single__MASK
#define button_single_SHIFT              button_single__SHIFT
#define button_single_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in button_single_SetInterruptMode() function.
     *  @{
     */
        #define button_single_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define button_single_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define button_single_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define button_single_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(button_single__SIO)
    #define button_single_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(button_single__PC) && (CY_PSOC4_4200L)
    #define button_single_USBIO_ENABLE               ((uint32)0x80000000u)
    #define button_single_USBIO_DISABLE              ((uint32)(~button_single_USBIO_ENABLE))
    #define button_single_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define button_single_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define button_single_USBIO_ENTER_SLEEP          ((uint32)((1u << button_single_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << button_single_USBIO_SUSPEND_DEL_SHIFT)))
    #define button_single_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << button_single_USBIO_SUSPEND_SHIFT)))
    #define button_single_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << button_single_USBIO_SUSPEND_DEL_SHIFT)))
    #define button_single_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(button_single__PC)
    /* Port Configuration */
    #define button_single_PC                 (* (reg32 *) button_single__PC)
#endif
/* Pin State */
#define button_single_PS                     (* (reg32 *) button_single__PS)
/* Data Register */
#define button_single_DR                     (* (reg32 *) button_single__DR)
/* Input Buffer Disable Override */
#define button_single_INP_DIS                (* (reg32 *) button_single__PC2)

/* Interrupt configuration Registers */
#define button_single_INTCFG                 (* (reg32 *) button_single__INTCFG)
#define button_single_INTSTAT                (* (reg32 *) button_single__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define button_single_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(button_single__SIO)
    #define button_single_SIO_REG            (* (reg32 *) button_single__SIO)
#endif /* (button_single__SIO_CFG) */

/* USBIO registers */
#if !defined(button_single__PC) && (CY_PSOC4_4200L)
    #define button_single_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define button_single_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define button_single_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define button_single_DRIVE_MODE_SHIFT       (0x00u)
#define button_single_DRIVE_MODE_MASK        (0x07u << button_single_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins button_single_H */


/* [] END OF FILE */
