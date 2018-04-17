/*******************************************************************************
MASTER
*******************************************************************************/

#include "main.h"
int value;

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
    int cycle = 0;
    LED_RED_Write(LED_ON);
    LED_GREEN_Write(LED_OFF);

    StripLights_Start();
    StripLights_Dim(0);
    I2CM_Start();

    CyGlobalIntEnable;

    /***************************************************************************
    * Main polling loop
    ***************************************************************************/
    for(;;)
    {
        /* Send packet with command to the slave */
        if (0u == WriteCommandPacket(command, cycle))
        {
            /* Read response packet from the slave */
            if (0u == ReadStatusPacket(cycle))
            {
                /* Update game state */
                if(cycle % 4 == 0){
                    //update the game state
                    //0 green, 1 red, 2 nothing
                    
                    
                }
            }
        }
        cycle++;
        
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
uint32 WriteCommandPacket(uint8 cmd, int cycle)
{
    uint8  buffer[BUFFER_SIZE];
    uint32 status = TRANSFER_ERROR;

    /* Initialize buffer with packet */
    buffer[PACKET_SOP_POS] = PACKET_SOP;
    buffer[PACKET_CMD_POS] = cmd;
    buffer[PACKET_EOP_POS] = PACKET_EOP;

    if(cycle % 2 == 0){
        (void) I2CM_I2CMasterWriteBuf(I2C_SLAVE_ADDR_0, buffer, PACKET_SIZE, \
                                  I2CM_I2C_MODE_COMPLETE_XFER);
    }
    else if(cycle % 2 == 1){
        (void) I2CM_I2CMasterWriteBuf(I2C_SLAVE_ADDR_1, buffer, PACKET_SIZE, \
                                  I2CM_I2C_MODE_COMPLETE_XFER);
    }
    /* Waits until master completes write transfer */
    while (0u == (I2CM_I2CMasterStatus() & I2CM_I2C_MSTAT_WR_CMPLT))
    {
    }

    /* Displays transfer status */
    unsigned int v = (I2CM_I2C_MSTAT_ERR_XFER & I2CM_I2CMasterStatus());
    if (0u == v)
    {
        /* Check if all bytes was written */
        if (I2CM_I2CMasterGetWriteBufSize() == BUFFER_SIZE)
        {
//            RGB_LED_ON_GREEN;
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
uint32 ReadStatusPacket(int cycle)
{
    uint8  buffer[BUFFER_SIZE];
    uint32 status = TRANSFER_ERROR;

    if(cycle % 2 == 0){
        (void) I2CM_I2CMasterReadBuf(I2C_SLAVE_ADDR_0, buffer, PACKET_SIZE, \
                                     I2CM_I2C_MODE_COMPLETE_XFER);
    }
    else if(cycle % 2 == 1){
        (void) I2CM_I2CMasterReadBuf(I2C_SLAVE_ADDR_1, buffer, PACKET_SIZE, \
                                     I2CM_I2C_MODE_COMPLETE_XFER);    
    }
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
            /*if (100 == buffer[PACKET_STS_POS]) // STS_CMD_DONE
            {
                RGB_LED_ON_GREEN;
                status = TRANSFER_CMPLT;
            }
            else{
                RGB_LED_OFF;
            }*/
            
            //CHANGED VERSION
            value = value + buffer[2];
            if(value % 2 == 0){
                LED_GREEN_Write(LED_ON);
            }
            else{
                LED_GREEN_Write(LED_OFF);
            }
            status = TRANSFER_CMPLT;
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

/*This function will display a number on the LEDs on the score display
Parameters: 
    position: which block to display it on
    number: number to be shown
*/
void DisplayNumber (int position, int number){
    int zero[] = {0, 1, 2, 3, 4, 5, 9, 10, 11, 12, 13, 14};
    int one[] = {0, 4, 5, 6, 7, 8, 9, 10};
    int two[] = {0, 1, 2, 4, 5, 7, 9, 10, 12, 13, 14};
    int three[] = {0, 2, 4, 5, 7, 9, 10, 11, 12, 13, 14};
    int four[] = {2, 3, 4, 7, 9, 10, 11, 12, 13, 14};
    int five[] = {0, 2, 3, 4, 5, 7, 9, 10, 11, 12, 14};
    int six[] = {0, 1, 2, 3, 4, 5, 7, 9, 10, 11, 12, 14};
    int seven[] = {4, 9, 10, 11, 12, 13, 14};
    int eight[] = {0, 1, 2, 3, 4, 5, 7, 9, 10, 11, 12, 13, 14};
    int nine[] = {0, 2, 3, 4, 5, 7, 9, 10, 11, 12, 13, 14};
    
    int arrayLen = 0;
    switch (number){
        case 0:
            arrayLen = 12;
        case 1:
            arrayLen = 8;
        case 2:
            arrayLen = 11;
        case 3:
            arrayLen = 11;
        case 4:
            arrayLen = 10;
        case 5:
            arrayLen = 11;
        case 6:
            arrayLen = 12;
        case 7:
            arrayLen = 7;
        case 8:
            arrayLen = 13;
        case 9:
            arrayLen = 12;
        default:
            return;
    }
    
    for(int i = 0; i < arrayLen; i++){
        StripLights_Pixel(i, position, StripLights_WHITE);
    }
    while (StripLights_Ready() == 0);
	StripLights_Trigger(1);
	CyDelay(10);
}

/* [] END OF FILE */
