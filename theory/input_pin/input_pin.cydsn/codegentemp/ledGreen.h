/*******************************************************************************
* File Name: ledGreen.h  
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

#if !defined(CY_PINS_ledGreen_H) /* Pins ledGreen_H */
#define CY_PINS_ledGreen_H

#include "cytypes.h"
#include "cyfitter.h"
#include "ledGreen_aliases.h"


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
} ledGreen_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   ledGreen_Read(void);
void    ledGreen_Write(uint8 value);
uint8   ledGreen_ReadDataReg(void);
#if defined(ledGreen__PC) || (CY_PSOC4_4200L) 
    void    ledGreen_SetDriveMode(uint8 mode);
#endif
void    ledGreen_SetInterruptMode(uint16 position, uint16 mode);
uint8   ledGreen_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void ledGreen_Sleep(void); 
void ledGreen_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(ledGreen__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define ledGreen_DRIVE_MODE_BITS        (3)
    #define ledGreen_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - ledGreen_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the ledGreen_SetDriveMode() function.
         *  @{
         */
        #define ledGreen_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define ledGreen_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define ledGreen_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define ledGreen_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define ledGreen_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define ledGreen_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define ledGreen_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define ledGreen_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define ledGreen_MASK               ledGreen__MASK
#define ledGreen_SHIFT              ledGreen__SHIFT
#define ledGreen_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in ledGreen_SetInterruptMode() function.
     *  @{
     */
        #define ledGreen_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define ledGreen_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define ledGreen_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define ledGreen_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(ledGreen__SIO)
    #define ledGreen_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(ledGreen__PC) && (CY_PSOC4_4200L)
    #define ledGreen_USBIO_ENABLE               ((uint32)0x80000000u)
    #define ledGreen_USBIO_DISABLE              ((uint32)(~ledGreen_USBIO_ENABLE))
    #define ledGreen_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define ledGreen_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define ledGreen_USBIO_ENTER_SLEEP          ((uint32)((1u << ledGreen_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << ledGreen_USBIO_SUSPEND_DEL_SHIFT)))
    #define ledGreen_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << ledGreen_USBIO_SUSPEND_SHIFT)))
    #define ledGreen_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << ledGreen_USBIO_SUSPEND_DEL_SHIFT)))
    #define ledGreen_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(ledGreen__PC)
    /* Port Configuration */
    #define ledGreen_PC                 (* (reg32 *) ledGreen__PC)
#endif
/* Pin State */
#define ledGreen_PS                     (* (reg32 *) ledGreen__PS)
/* Data Register */
#define ledGreen_DR                     (* (reg32 *) ledGreen__DR)
/* Input Buffer Disable Override */
#define ledGreen_INP_DIS                (* (reg32 *) ledGreen__PC2)

/* Interrupt configuration Registers */
#define ledGreen_INTCFG                 (* (reg32 *) ledGreen__INTCFG)
#define ledGreen_INTSTAT                (* (reg32 *) ledGreen__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define ledGreen_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(ledGreen__SIO)
    #define ledGreen_SIO_REG            (* (reg32 *) ledGreen__SIO)
#endif /* (ledGreen__SIO_CFG) */

/* USBIO registers */
#if !defined(ledGreen__PC) && (CY_PSOC4_4200L)
    #define ledGreen_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define ledGreen_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define ledGreen_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define ledGreen_DRIVE_MODE_SHIFT       (0x00u)
#define ledGreen_DRIVE_MODE_MASK        (0x07u << ledGreen_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins ledGreen_H */


/* [] END OF FILE */
