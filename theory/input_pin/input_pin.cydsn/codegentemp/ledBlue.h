/*******************************************************************************
* File Name: ledBlue.h  
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

#if !defined(CY_PINS_ledBlue_H) /* Pins ledBlue_H */
#define CY_PINS_ledBlue_H

#include "cytypes.h"
#include "cyfitter.h"
#include "ledBlue_aliases.h"


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
} ledBlue_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   ledBlue_Read(void);
void    ledBlue_Write(uint8 value);
uint8   ledBlue_ReadDataReg(void);
#if defined(ledBlue__PC) || (CY_PSOC4_4200L) 
    void    ledBlue_SetDriveMode(uint8 mode);
#endif
void    ledBlue_SetInterruptMode(uint16 position, uint16 mode);
uint8   ledBlue_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void ledBlue_Sleep(void); 
void ledBlue_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(ledBlue__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define ledBlue_DRIVE_MODE_BITS        (3)
    #define ledBlue_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - ledBlue_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the ledBlue_SetDriveMode() function.
         *  @{
         */
        #define ledBlue_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define ledBlue_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define ledBlue_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define ledBlue_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define ledBlue_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define ledBlue_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define ledBlue_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define ledBlue_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define ledBlue_MASK               ledBlue__MASK
#define ledBlue_SHIFT              ledBlue__SHIFT
#define ledBlue_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in ledBlue_SetInterruptMode() function.
     *  @{
     */
        #define ledBlue_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define ledBlue_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define ledBlue_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define ledBlue_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(ledBlue__SIO)
    #define ledBlue_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(ledBlue__PC) && (CY_PSOC4_4200L)
    #define ledBlue_USBIO_ENABLE               ((uint32)0x80000000u)
    #define ledBlue_USBIO_DISABLE              ((uint32)(~ledBlue_USBIO_ENABLE))
    #define ledBlue_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define ledBlue_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define ledBlue_USBIO_ENTER_SLEEP          ((uint32)((1u << ledBlue_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << ledBlue_USBIO_SUSPEND_DEL_SHIFT)))
    #define ledBlue_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << ledBlue_USBIO_SUSPEND_SHIFT)))
    #define ledBlue_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << ledBlue_USBIO_SUSPEND_DEL_SHIFT)))
    #define ledBlue_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(ledBlue__PC)
    /* Port Configuration */
    #define ledBlue_PC                 (* (reg32 *) ledBlue__PC)
#endif
/* Pin State */
#define ledBlue_PS                     (* (reg32 *) ledBlue__PS)
/* Data Register */
#define ledBlue_DR                     (* (reg32 *) ledBlue__DR)
/* Input Buffer Disable Override */
#define ledBlue_INP_DIS                (* (reg32 *) ledBlue__PC2)

/* Interrupt configuration Registers */
#define ledBlue_INTCFG                 (* (reg32 *) ledBlue__INTCFG)
#define ledBlue_INTSTAT                (* (reg32 *) ledBlue__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define ledBlue_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(ledBlue__SIO)
    #define ledBlue_SIO_REG            (* (reg32 *) ledBlue__SIO)
#endif /* (ledBlue__SIO_CFG) */

/* USBIO registers */
#if !defined(ledBlue__PC) && (CY_PSOC4_4200L)
    #define ledBlue_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define ledBlue_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define ledBlue_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define ledBlue_DRIVE_MODE_SHIFT       (0x00u)
#define ledBlue_DRIVE_MODE_MASK        (0x07u << ledBlue_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins ledBlue_H */


/* [] END OF FILE */
