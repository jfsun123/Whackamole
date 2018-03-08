/*******************************************************************************
* File Name: flex2.h  
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

#if !defined(CY_PINS_flex2_ALIASES_H) /* Pins flex2_ALIASES_H */
#define CY_PINS_flex2_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define flex2_0			(flex2__0__PC)
#define flex2_0_PS		(flex2__0__PS)
#define flex2_0_PC		(flex2__0__PC)
#define flex2_0_DR		(flex2__0__DR)
#define flex2_0_SHIFT	(flex2__0__SHIFT)
#define flex2_0_INTR	((uint16)((uint16)0x0003u << (flex2__0__SHIFT*2u)))

#define flex2_INTR_ALL	 ((uint16)(flex2_0_INTR))


#endif /* End Pins flex2_ALIASES_H */


/* [] END OF FILE */
