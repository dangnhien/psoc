/*******************************************************************************
* File Name: LedYellow_6.h  
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

#if !defined(CY_PINS_LedYellow_6_H) /* Pins LedYellow_6_H */
#define CY_PINS_LedYellow_6_H

#include "cytypes.h"
#include "cyfitter.h"
#include "LedYellow_6_aliases.h"


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
} LedYellow_6_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   LedYellow_6_Read(void);
void    LedYellow_6_Write(uint8 value);
uint8   LedYellow_6_ReadDataReg(void);
#if defined(LedYellow_6__PC) || (CY_PSOC4_4200L) 
    void    LedYellow_6_SetDriveMode(uint8 mode);
#endif
void    LedYellow_6_SetInterruptMode(uint16 position, uint16 mode);
uint8   LedYellow_6_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void LedYellow_6_Sleep(void); 
void LedYellow_6_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(LedYellow_6__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define LedYellow_6_DRIVE_MODE_BITS        (3)
    #define LedYellow_6_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - LedYellow_6_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the LedYellow_6_SetDriveMode() function.
         *  @{
         */
        #define LedYellow_6_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define LedYellow_6_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define LedYellow_6_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define LedYellow_6_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define LedYellow_6_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define LedYellow_6_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define LedYellow_6_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define LedYellow_6_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define LedYellow_6_MASK               LedYellow_6__MASK
#define LedYellow_6_SHIFT              LedYellow_6__SHIFT
#define LedYellow_6_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in LedYellow_6_SetInterruptMode() function.
     *  @{
     */
        #define LedYellow_6_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define LedYellow_6_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define LedYellow_6_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define LedYellow_6_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(LedYellow_6__SIO)
    #define LedYellow_6_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(LedYellow_6__PC) && (CY_PSOC4_4200L)
    #define LedYellow_6_USBIO_ENABLE               ((uint32)0x80000000u)
    #define LedYellow_6_USBIO_DISABLE              ((uint32)(~LedYellow_6_USBIO_ENABLE))
    #define LedYellow_6_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define LedYellow_6_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define LedYellow_6_USBIO_ENTER_SLEEP          ((uint32)((1u << LedYellow_6_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << LedYellow_6_USBIO_SUSPEND_DEL_SHIFT)))
    #define LedYellow_6_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << LedYellow_6_USBIO_SUSPEND_SHIFT)))
    #define LedYellow_6_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << LedYellow_6_USBIO_SUSPEND_DEL_SHIFT)))
    #define LedYellow_6_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(LedYellow_6__PC)
    /* Port Configuration */
    #define LedYellow_6_PC                 (* (reg32 *) LedYellow_6__PC)
#endif
/* Pin State */
#define LedYellow_6_PS                     (* (reg32 *) LedYellow_6__PS)
/* Data Register */
#define LedYellow_6_DR                     (* (reg32 *) LedYellow_6__DR)
/* Input Buffer Disable Override */
#define LedYellow_6_INP_DIS                (* (reg32 *) LedYellow_6__PC2)

/* Interrupt configuration Registers */
#define LedYellow_6_INTCFG                 (* (reg32 *) LedYellow_6__INTCFG)
#define LedYellow_6_INTSTAT                (* (reg32 *) LedYellow_6__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define LedYellow_6_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(LedYellow_6__SIO)
    #define LedYellow_6_SIO_REG            (* (reg32 *) LedYellow_6__SIO)
#endif /* (LedYellow_6__SIO_CFG) */

/* USBIO registers */
#if !defined(LedYellow_6__PC) && (CY_PSOC4_4200L)
    #define LedYellow_6_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define LedYellow_6_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define LedYellow_6_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define LedYellow_6_DRIVE_MODE_SHIFT       (0x00u)
#define LedYellow_6_DRIVE_MODE_MASK        (0x07u << LedYellow_6_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins LedYellow_6_H */


/* [] END OF FILE */
