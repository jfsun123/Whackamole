/*******************************************************************************
SLAVE
*******************************************************************************/

#include <main.h>

/* I2C slave read and write buffers */
uint8 i2cReadBuffer [BUFFER_SIZE] = {PACKET_SOP, STS_CMD_FAIL, PACKET_EOP};
uint8 i2cWriteBuffer[BUFFER_SIZE];
void SetBlockColor(int block_number, uint32 color);


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
    StripLights_Start();
    StripLights_Dim(1);
    uint8 status = STS_CMD_FAIL;
                    LED_RED_Write  (LED_OFF);
                    LED_GREEN_Write(LED_OFF);
                    LED_BLUE_Write (LED_OFF);


    /* Start I2C slave (SCB mode) */
    I2CS_I2CSlaveInitReadBuf (i2cReadBuffer,  BUFFER_SIZE);
    I2CS_I2CSlaveInitWriteBuf(i2cWriteBuffer, BUFFER_SIZE);
    I2CS_Start();

    CyGlobalIntEnable;
    uint8 buttonStatus = 0;
    /***************************************************************************
    * Main polling loop
    ***************************************************************************/
    for (;;)
    {
        buttonStatus = Button_Read();
        if(buttonStatus == 0) buttonStatus = 100;
        else buttonStatus = 99;
        /* Write complete: parse command packet */
        if (0u != (I2CS_I2CSlaveStatus() & I2CS_I2C_SSTAT_WR_CMPLT))
        {
            /* Check packet length */
            if (PACKET_SIZE == I2CS_I2CSlaveGetWriteBufSize())
            {
                /* Check start and end of packet markers */
                if ((i2cWriteBuffer[PACKET_SOP_POS] == PACKET_SOP) &&
                    (i2cWriteBuffer[PACKET_EOP_POS] == PACKET_EOP))
                {
                    status = ExecuteCommand(i2cWriteBuffer[PACKET_CMD_POS]);
                }
            }

            /* Clear slave write buffer and status */
            I2CS_I2CSlaveClearWriteBuf();
            (void) I2CS_I2CSlaveClearWriteStatus();

            /* Update read buffer */
            i2cReadBuffer[PACKET_STS_POS] = buttonStatus;  //used to be status
            status = STS_CMD_FAIL;
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
*******************************************************************************/
uint8 ExecuteCommand(uint32 cmd)
{
    uint8 status;

    status = STS_CMD_DONE;

    /* Execute received command */
    switch (cmd)
    {
        case CMD_SET_RED:
            LED_RED_Write  (LED_ON);
            LED_GREEN_Write(LED_OFF);
            LED_BLUE_Write (LED_OFF);
            SetBlockColor(0, StripLights_RED);
            break;

        case CMD_SET_GREEN:
            LED_RED_Write  (LED_OFF);
            LED_GREEN_Write(LED_ON);
            LED_BLUE_Write (LED_OFF);
            SetBlockColor(0, StripLights_GREEN);
            break;

        case CMD_SET_BLUE:
            LED_RED_Write  (LED_OFF);
            LED_GREEN_Write(LED_OFF);
            LED_BLUE_Write (LED_ON);
            SetBlockColor(0, StripLights_BLUE);
            break;
        case CMD_SET_RED_GREEN:
            LED_RED_Write  (LED_ON);
            LED_GREEN_Write(LED_ON);
            LED_BLUE_Write (LED_OFF);
            SetBlockColor(0, StripLights_YELLOW);
            break;
        case CMD_SET_RED_BLUE:
            LED_RED_Write  (LED_ON);
            LED_GREEN_Write(LED_OFF);
            LED_BLUE_Write (LED_ON);
            SetBlockColor(0, StripLights_VIOLET);
            break;
        case CMD_SET_GREEN_BLUE:
            LED_RED_Write  (LED_OFF);
            LED_GREEN_Write(LED_ON);
            LED_BLUE_Write (LED_ON);
            SetBlockColor(0, StripLights_TURQUOSE);
            break;
        case CMD_SET_RED_GREEN_BLUE:
            LED_RED_Write  (LED_ON);
            LED_GREEN_Write(LED_ON);
            LED_BLUE_Write (LED_ON);
            SetBlockColor(0, StripLights_DIM_WHITE);
            break;

        case CMD_SET_OFF:
                    LED_RED_Write  (LED_OFF);
                    LED_GREEN_Write(LED_OFF);
                    LED_BLUE_Write (LED_OFF);
                    SetBlockColor(0, 0);
            break;

        default:
            status = STS_CMD_FAIL;
            break;
    }
  
    return (status);
}



void SetBlockColor(int block_number, uint32 color) {
	for (uint32 led = 0; led < 15; led++) {
		StripLights_Pixel(led, block_number, color);
	}
    while (StripLights_Ready() == 0);
	StripLights_Trigger(1);
	CyDelay(10);
}
/* [] END OF FILE */
