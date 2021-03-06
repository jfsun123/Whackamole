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
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

/***************************************
*         Function Prototypes
****************************************/

/* Function prototypes */
uint32 CheckSwitchState(void);
uint32 WriteCommandPacket(uint8 cmd, int cycle);
uint32 ReadStatusPacket(int cycle, int* pressed);
void DisplayNumber(int position, int number);
void playGame();
void updateTilesAndColors(int tiles[], int colors[]);


/***************************************
*            Constants
****************************************/

/* I2C slave address to communicate with */
#define I2C_SLAVE_ADDR_0  (0x08u)
#define I2C_SLAVE_ADDR_1  (0x09u)
#define I2C_SLAVE_ADDR_2  (0x0Au)
#define I2C_SLAVE_ADDR_3  (0x0Bu)

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

/* Command valid status */
#define TRANSFER_CMPLT    (0x00u)
#define TRANSFER_ERROR    (0xFFu)

/* Set the LEDS to be on or off*/
#define LED_ON  (0u)
#define LED_OFF (1u)

/* Commands set */
typedef enum 
{
 CMD_SET_OFF,     
 CMD_SET_RED,   
 CMD_SET_GREEN,   
CMD_SET_BLUE   ,
 CMD_SET_RED_GREEN,
 CMD_SET_RED_BLUE,
 CMD_SET_GREEN_BLUE,
 CMD_SET_RED_GREEN_BLUE,
    NUM_COLORS
}LED_State;
/* Delay between commands in milliseconds */
#define CMD_TO_CMD_DELAY  (500u)


/***************************************
*               Macros
****************************************/

/* Set LED RED color */
#define RGB_LED_ON_RED  \
                do{     \
                    LED_RED_Write  (0u); \
                    LED_GREEN_Write(1u); \
                }while(0)

/* Set LED GREEN color */
#define RGB_LED_ON_GREEN \
                do{      \
                    LED_RED_Write  (1u); \
                    LED_GREEN_Write(0u); \
                }while(0)

/* Set LED TURN OFF */
#define RGB_LED_OFF \
                do{ \
                    LED_RED_Write  (1u); \
                    LED_GREEN_Write(1u); \
                }while(0)

#endif /* (CY_MAIN_H) */


/* [] END OF FILE */
