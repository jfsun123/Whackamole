/*******************************************************************************
* File Name: flex0.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_flex0_ALIASES_H) /* Pins flex0_ALIASES_H */
#define CY_PINS_flex0_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define flex0_0			(flex0__0__PC)
#define flex0_0_PS		(flex0__0__PS)
#define flex0_0_PC		(flex0__0__PC)
#define flex0_0_DR		(flex0__0__DR)
#define flex0_0_SHIFT	(flex0__0__SHIFT)
#define flex0_0_INTR	((uint16)((uint16)0x0003u << (flex0__0__SHIFT*2u)))

#define flex0_INTR_ALL	 ((uint16)(flex0_0_INTR))


#endif /* End Pins flex0_ALIASES_H */


/* [] END OF FILE */
