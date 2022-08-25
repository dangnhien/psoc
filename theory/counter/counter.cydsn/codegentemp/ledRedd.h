/*******************************************************************************
* File Name: ledRedd.h  
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

#if !defined(CY_PINS_ledRedd_H) /* Pins ledRedd_H */
#define CY_PINS_ledRedd_H

#include "cytypes.h"
#include "cyfitter.h"
#include "ledRedd_aliases.h"


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
} ledRedd_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   ledRedd_Read(void);
void    ledRedd_Write(uint8 value);
uint8   ledRedd_ReadDataReg(void);
#if defined(ledRedd__PC) || (CY_PSOC4_4200L) 
    void    ledRedd_SetDriveMode(uint8 mode);
#endif
void    ledRedd_SetInterruptMode(uint16 position, uint16 mode);
uint8   ledRedd_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void ledRedd_Sleep(void); 
void ledRedd_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(ledRedd__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define ledRedd_DRIVE_MODE_BITS        (3)
    #define ledRedd_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - ledRedd_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the ledRedd_SetDriveMode() function.
         *  @{
         */
        #define ledRedd_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define ledRedd_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define ledRedd_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define ledRedd_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define ledRedd_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define ledRedd_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define ledRedd_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define ledRedd_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define ledRedd_MASK               ledRedd__MASK
#define ledRedd_SHIFT              ledRedd__SHIFT
#define ledRedd_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in ledRedd_SetInterruptMode() function.
     *  @{
     */
        #define ledRedd_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define ledRedd_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define ledRedd_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define ledRedd_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(ledRedd__SIO)
    #define ledRedd_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(ledRedd__PC) && (CY_PSOC4_4200L)
    #define ledRedd_USBIO_ENABLE               ((uint32)0x80000000u)
    #define ledRedd_USBIO_DISABLE              ((uint32)(~ledRedd_USBIO_ENABLE))
    #define ledRedd_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define ledRedd_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define ledRedd_USBIO_ENTER_SLEEP          ((uint32)((1u << ledRedd_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << ledRedd_USBIO_SUSPEND_DEL_SHIFT)))
    #define ledRedd_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << ledRedd_USBIO_SUSPEND_SHIFT)))
    #define ledRedd_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << ledRedd_USBIO_SUSPEND_DEL_SHIFT)))
    #define ledRedd_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(ledRedd__PC)
    /* Port Configuration */
    #define ledRedd_PC                 (* (reg32 *) ledRedd__PC)
#endif
/* Pin State */
#define ledRedd_PS                     (* (reg32 *) ledRedd__PS)
/* Data Register */
#define ledRedd_DR                     (* (reg32 *) ledRedd__DR)
/* Input Buffer Disable Override */
#define ledRedd_INP_DIS                (* (reg32 *) ledRedd__PC2)

/* Interrupt configuration Registers */
#define ledRedd_INTCFG                 (* (reg32 *) ledRedd__INTCFG)
#define ledRedd_INTSTAT                (* (reg32 *) ledRedd__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define ledRedd_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(ledRedd__SIO)
    #define ledRedd_SIO_REG            (* (reg32 *) ledRedd__SIO)
#endif /* (ledRedd__SIO_CFG) */

/* USBIO registers */
#if !defined(ledRedd__PC) && (CY_PSOC4_4200L)
    #define ledRedd_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define ledRedd_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define ledRedd_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define ledRedd_DRIVE_MODE_SHIFT       (0x00u)
#define ledRedd_DRIVE_MODE_MASK        (0x07u << ledRedd_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins ledRedd_H */


/* [] END OF FILE */
