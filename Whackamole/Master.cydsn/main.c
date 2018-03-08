/*******************************************************************************
MASTER
*******************************************************************************/

#include "main.h"


/*******************************************************************************
* Function Name: main
********************************************************************************
* Summary:
*  The main function performs the following actions:
*   1. Turns off the RGB LED.
*   2. Starts the I2C master (SCB mode) component.
*   3. Enables global interrupts.
*   4. Sends command and status packets to the slave every 500mS.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
int main()
{
    uint8 command = CMD_SET_RED;

    RGB_LED_OFF;

    I2CM_Start();

    CyGlobalIntEnable;

    /***************************************************************************
    * Main polling loop
    ***************************************************************************/
    for(;;)
    {
        /* Send packet with command to the slave */
        if (0u == WriteCommandPacket(command))
        {
            /* Read response packet from the slave */
            if (0u == ReadStatusPacket())
            {
                /* Next command to be written */
                command++;
                if (command >= NUM_COLORS)
                {
                    command = CMD_SET_OFF;
                }

                /* Turn off status LED */
                //RGB_LED_OFF;
            }
        }

//        CyDelay(CMD_TO_CMD_DELAY); /* Delay between commands */
    }
}


/*******************************************************************************
* Function Name: WriteCommandPacket
********************************************************************************
* Summary:
*  Master initiates the transfer to write command packet into the slave.
*  The status of the transfer is returned.
*
* Parameters:
*  cmd: command to execute. Available commands:
*   - CMD_SET_RED:   set red color of the LED.
*   - CMD_SET_GREEN: set green color of the LED.
*   - CMD_SET_BLUE:  set blue color of the LED.
*   - CMD_SET_OFF:   turn off the LED.
*
* Return:
*  Returns status of the transfer. There are two statuses
*  - TRANSFER_CMPLT: transfer completed successfully.
*  - TRANSFER_ERROR: the error occurred while transfer.
*
*******************************************************************************/
uint32 WriteCommandPacket(uint8 cmd)
{
    uint8  buffer[BUFFER_SIZE];
    uint32 status = TRANSFER_ERROR;

    /* Initialize buffer with packet */
    buffer[PACKET_SOP_POS] = PACKET_SOP;
    buffer[PACKET_CMD_POS] = cmd;
    buffer[PACKET_EOP_POS] = PACKET_EOP;

    (void) I2CM_I2CMasterWriteBuf(I2C_SLAVE_ADDR, buffer, PACKET_SIZE, \
                                  I2CM_I2C_MODE_COMPLETE_XFER);

    /* Waits until master completes write transfer */
    while (0u == (I2CM_I2CMasterStatus() & I2CM_I2C_MSTAT_WR_CMPLT))
    {
    }

    /* Displays transfer status */
    if (0u == (I2CM_I2C_MSTAT_ERR_XFER & I2CM_I2CMasterStatus()))
    {
        /* Check if all bytes was written */
        if (I2CM_I2CMasterGetWriteBufSize() == BUFFER_SIZE)
        {
            RGB_LED_ON_GREEN;
            status = TRANSFER_CMPLT;
        }
    }
    else
    {
//        RGB_LED_ON_RED;
    }

    (void) I2CM_I2CMasterClearStatus();

    return (status);
}


/*******************************************************************************
* Function Name: ReadStatusPacket
********************************************************************************
* Summary:
*  Master initiates the transfer to read status packet from the slave.
*  The status of the transfer is returned.
*
* Parameters:
*  None
*
* Return:
*  Returns status of the transfer. There are two statuses
*  - TRANSFER_CMPLT: transfer completed successfully.
*  - TRANSFER_ERROR: the error occurred while transfer.
*
*******************************************************************************/
uint32 ReadStatusPacket(void)
{
    uint8  buffer[BUFFER_SIZE];
    uint32 status = TRANSFER_ERROR;

    (void) I2CM_I2CMasterReadBuf(I2C_SLAVE_ADDR, buffer, PACKET_SIZE, \
                                 I2CM_I2C_MODE_COMPLETE_XFER);

    /* Waits until master complete read transfer */
    while (0u == (I2CM_I2CMasterStatus() & I2CM_I2C_MSTAT_RD_CMPLT))
    {
    }

    /* Displays transfer status */
    if (0u == (I2CM_I2C_MSTAT_ERR_XFER & I2CM_I2CMasterStatus()))
    {
        /* Check packet structure */
        if ((I2CM_I2CMasterGetReadBufSize() == BUFFER_SIZE) &&
            (PACKET_SOP == buffer[PACKET_SOP_POS]) &&
            (PACKET_EOP == buffer[PACKET_EOP_POS]))
        {
            /* Check packet status */
            if (100 == buffer[PACKET_STS_POS]) // STS_CMD_DONE
            {
                RGB_LED_ON_GREEN;
                status = TRANSFER_CMPLT;
            }
            else{ //this used to not be here
                RGB_LED_OFF;
            }
        }
    }
    else
    {
        RGB_LED_ON_RED;
        status = TRANSFER_ERROR;
    }

    (void) I2CM_I2CMasterClearStatus();

    return (status);
}


/* [] END OF FILE */
