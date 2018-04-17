/*******************************************************************************
SLAVE
*******************************************************************************/

#include <main.h>

/* I2C slave read and write buffers */
uint8 i2cReadBuffer [BUFFER_SIZE] = {PACKET_SOP, STS_CMD_FAIL, PACKET_EOP};
uint8 i2cWriteBuffer[BUFFER_SIZE];
void SetTileColor(int block_number, uint32 color);
uint8 buttonStatus = 0;

/*******************************************************************************
* Function Name: main
********************************************************************************
* Summary:
*  Main function performs following actions:
*   1. Turns off status RGB LED
*   2. Sets up I2C slave write and read buffers.
*   3. Starts I2C slave (SCB mode) component.
*   4. Enables global interrupts.
*   5. Waits for command from the I2C master to control the RGB LED.
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
    //Start lights and initialize the variables for flex sensors
    StripLights_Start();
    StripLights_Dim(0);

    bool isPressed = false;
    i2cReadBuffer[PACKET_EOP_POS] = PACKET_EOP; //janky way of setting the end packet
    
                    LED_RED_Write  (LED_OFF);
                    LED_GREEN_Write(LED_ON);
                    LED_BLUE_Write (LED_ON);


    /* Start I2C slave (SCB mode) */
    I2CS_I2CSlaveInitReadBuf (i2cReadBuffer,  BUFFER_SIZE);
    I2CS_I2CSlaveInitWriteBuf(i2cWriteBuffer, BUFFER_SIZE);
    I2CS_I2CSlaveSetAddress(0x08u);
    I2CS_Start();

    CyGlobalIntEnable;

    /***************************************************************************
    * Main polling loop
    ***************************************************************************/
    for (;;)
    {   
        /* Write complete: parse command packet */
        if (0u != (I2CS_I2CSlaveStatus() & I2CS_I2C_SSTAT_WR_CMPLT))
        {
//            /* Check packet length */
            if (PACKET_SIZE == I2CS_I2CSlaveGetWriteBufSize())
            {
//                /* Check start and end of packet markers */
                if ((i2cWriteBuffer[PACKET_SOP_POS] == PACKET_SOP) &&
                    (i2cWriteBuffer[PACKET_EOP_POS] == PACKET_EOP))
                {
                    int color0 = i2cWriteBuffer[2];
                    int color1 = i2cWriteBuffer[3];
                    int color2 = i2cWriteBuffer[4];
                    int color3 = i2cWriteBuffer[5];
                    ExecuteCommand(color0, color1, color2, color3);  //CHANGED
                    
                }
            }

            /* Clear slave write buffer and status */
            I2CS_I2CSlaveClearWriteBuf();
            (void) I2CS_I2CSlaveClearWriteStatus();

            /* Update read buffer*/
            i2cReadBuffer[PACKET_STS_POS] = STS_CMD_DONE;
            i2cReadBuffer[2] = flex0_Read();
            i2cReadBuffer[3] = flex1_Read();
            i2cReadBuffer[4] = flex2_Read();
            i2cReadBuffer[5] = flex3_Read();
            //END UPDATE READ BUFFER
        }

        /* Read complete: expose buffer to master */
        if (0u != (I2CS_I2CSlaveStatus() & I2CS_I2C_SSTAT_RD_CMPLT))
        {
            /* Clear slave read buffer and status */
            I2CS_I2CSlaveClearReadBuf();
            (void) I2CS_I2CSlaveClearReadStatus();
        }
    }
}


/*******************************************************************************
* Function Name: ExecuteCommand
********************************************************************************
* Summary:
*  Executes received command to control the LED color and returns status.
*  If the command is unknown, the LED color is not changed.
*
* Parameters:
*  cmd: command to execute. Available commands:
*   - CMD_SET_RED:   set red color of the LED.
*   - CMD_SET_GREEN: set green color of the LED.
*   - CMD_SET_BLUE:  set blue color of the LED.
*   - CMD_SET_OFF:   turn off the LED.
*
* Return:
*  Returns status of command execution. There are two statuses
*  - STS_CMD_DONE: command is executed successfully.
*  - STS_CMD_FAIL: unknown command
*


BIG CHANGES
Parameters: uint8 array[6]
Returns the status of the execution. Includes the number of times that the button
was pressed on the board in binary in an array
*******************************************************************************/

uint8 ExecuteCommand(int color0, int color1, int color2, int color3)
{
    
    SetTileColor(0, color0);
    SetTileColor(1, color1);
    SetTileColor(2, color2);
    SetTileColor(3, color3);
    return (0);
}



void SetTileColor(int block_number, uint32 color) {
	for (uint32 led = 0; led < 15; led++) {
		StripLights_Pixel(led, block_number, color);
	}
    while (StripLights_Ready() == 0);
	StripLights_Trigger(1);
	CyDelay(10);
}
/* [] END OF FILE */
