/*******************************************************************************
* File Name: main.h
*
* Version: 1.20
*
* Description:
*  This file provides function prototypes, constants and macros for the example
*  project.
*
********************************************************************************
* Copyright 2014-2015, Cypress Semiconductor Corporation. All rights reserved.
* This software is owned by Cypress Semiconductor Corporation and is protected
* by and subject to worldwide patent and copyright laws and treaties.
* Therefore, you may use this software only as provided in the license agreement
* accompanying the software package from which you obtained this software.
* CYPRESS AND ITS SUPPLIERS MAKE NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
* WITH REGARD TO THIS SOFTWARE, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT,
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*******************************************************************************/

#if !defined(CY_MAIN_H)
#define CY_MAIN_H

#include <project.h>


/***************************************
*         Function Prototypes
****************************************/

uint8 ExecuteCommand(int color0, int color1, int color2, int color3);


/***************************************
*            Constants
****************************************/

/* Buffer and packet size */
#define BUFFER_SIZE     (32u)
#define PACKET_SIZE     (BUFFER_SIZE)

/* Packet positions */
#define PACKET_SOP_POS  (0u)
#define PACKET_CMD_POS  (1u)
#define PACKET_STS_POS  (PACKET_CMD_POS)
#define PACKET_EOP_POS  (31u)

/* Start and end of packet markers */
#define PACKET_SOP      (0x01u)
#define PACKET_EOP      (0x17u)

/* Command valid status */
#define STS_CMD_DONE    (0x00u)
#define STS_CMD_FAIL    (0xFFu)

/* Commands set */
typedef enum 
{
 CMD_SET_OFF,     
 CMD_SET_RED,   
 CMD_SET_GREEN,   
CMD_SET_BLUE,
 CMD_SET_RED_GREEN,
 CMD_SET_RED_BLUE,
 CMD_SET_GREEN_BLUE,
 CMD_SET_RED_GREEN_BLUE,
    NUM_COLORS
}LED_State;



/***************************************
*               Macros
****************************************/
#define LED_ON  (0u)
#define LED_OFF (1u)

/* Set LED RED color */
#include <stdbool.h>

#endif /* (CY_MAIN_H) */


/* [] END OF FILE */
