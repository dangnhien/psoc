/*******************************************************************************
* File Name: pwmToServer.h  
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

#if !defined(CY_PINS_pwmToServer_H) /* Pins pwmToServer_H */
#define CY_PINS_pwmToServer_H

#include "cytypes.h"
#include "cyfitter.h"
#include "pwmToServer_aliases.h"


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
} pwmToServer_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   pwmToServer_Read(void);
void    pwmToServer_Write(uint8 value);
uint8   pwmToServer_ReadDataReg(void);
#if defined(pwmToServer__PC) || (CY_PSOC4_4200L) 
    void    pwmToServer_SetDriveMode(uint8 mode);
#endif
void    pwmToServer_SetInterruptMode(uint16 position, uint16 mode);
uint8   pwmToServer_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void pwmToServer_Sleep(void); 
void pwmToServer_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(pwmToServer__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define pwmToServer_DRIVE_MODE_BITS        (3)
    #define pwmToServer_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - pwmToServer_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the pwmToServer_SetDriveMode() function.
         *  @{
         */
        #define pwmToServer_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define pwmToServer_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define pwmToServer_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define pwmToServer_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define pwmToServer_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define pwmToServer_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define pwmToServer_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define pwmToServer_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define pwmToServer_MASK               pwmToServer__MASK
#define pwmToServer_SHIFT              pwmToServer__SHIFT
#define pwmToServer_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in pwmToServer_SetInterruptMode() function.
     *  @{
     */
        #define pwmToServer_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define pwmToServer_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define pwmToServer_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define pwmToServer_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(pwmToServer__SIO)
    #define pwmToServer_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(pwmToServer__PC) && (CY_PSOC4_4200L)
    #define pwmToServer_USBIO_ENABLE               ((uint32)0x80000000u)
    #define pwmToServer_USBIO_DISABLE              ((uint32)(~pwmToServer_USBIO_ENABLE))
    #define pwmToServer_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define pwmToServer_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define pwmToServer_USBIO_ENTER_SLEEP          ((uint32)((1u << pwmToServer_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << pwmToServer_USBIO_SUSPEND_DEL_SHIFT)))
    #define pwmToServer_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << pwmToServer_USBIO_SUSPEND_SHIFT)))
    #define pwmToServer_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << pwmToServer_USBIO_SUSPEND_DEL_SHIFT)))
    #define pwmToServer_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(pwmToServer__PC)
    /* Port Configuration */
    #define pwmToServer_PC                 (* (reg32 *) pwmToServer__PC)
#endif
/* Pin State */
#define pwmToServer_PS                     (* (reg32 *) pwmToServer__PS)
/* Data Register */
#define pwmToServer_DR                     (* (reg32 *) pwmToServer__DR)
/* Input Buffer Disable Override */
#define pwmToServer_INP_DIS                (* (reg32 *) pwmToServer__PC2)

/* Interrupt configuration Registers */
#define pwmToServer_INTCFG                 (* (reg32 *) pwmToServer__INTCFG)
#define pwmToServer_INTSTAT                (* (reg32 *) pwmToServer__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define pwmToServer_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(pwmToServer__SIO)
    #define pwmToServer_SIO_REG            (* (reg32 *) pwmToServer__SIO)
#endif /* (pwmToServer__SIO_CFG) */

/* USBIO registers */
#if !defined(pwmToServer__PC) && (CY_PSOC4_4200L)
    #define pwmToServer_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define pwmToServer_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define pwmToServer_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define pwmToServer_DRIVE_MODE_SHIFT       (0x00u)
#define pwmToServer_DRIVE_MODE_MASK        (0x07u << pwmToServer_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins pwmToServer_H */


/* [] END OF FILE */
