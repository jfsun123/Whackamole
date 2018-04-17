/*******************************************************************************
MASTER
*******************************************************************************/

#include "main.h"
int points = 0;

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
    //initialize variables
    uint8 command = CMD_SET_RED;
    int cycle = 0;
    int* pressed = (int*)malloc(sizeof(int) * 16);
    int tiles[16];
    int colors[16]; //0 = green, 1 = red, 2 = no color
    for(int i = 0; i < 16; i++)
    {
        tiles[i] = i;
    }
    updateTilesAndColors(tiles, colors);
    
    //initialize other things
    srand(time(0));
    StripLights_Start();
    StripLights_Dim(0);
    I2CM_Start();

    CyGlobalIntEnable;

    time_t curTime;
    time(&curTime);
    int timeActual = curTime;
    /***************************************************************************
    * Main polling loop
    ***************************************************************************/
    for(;;)
    {
        /* Send packet with command to the slave */
        if (0u == WriteCommandPacket(command, cycle))
        {
            /* Read response packet from the slave */
            if (0u == ReadStatusPacket(cycle, pressed))
            {
                /* Update game state */
                if(cycle % 4 == 0){
                    time(&curTime);
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

    if(cycle % 4 == 0){
        (void) I2CM_I2CMasterWriteBuf(I2C_SLAVE_ADDR_0, buffer, PACKET_SIZE, \
                                     I2CM_I2C_MODE_COMPLETE_XFER);
    }
    else if(cycle % 4 == 1){
        (void) I2CM_I2CMasterWriteBuf(I2C_SLAVE_ADDR_1, buffer, PACKET_SIZE, \
                                     I2CM_I2C_MODE_COMPLETE_XFER);    
    }
    else if(cycle % 4 == 2){
        (void) I2CM_I2CMasterWriteBuf(I2C_SLAVE_ADDR_2, buffer, PACKET_SIZE, \
                I2CM_I2C_MODE_COMPLETE_XFER);  
    }
    else{
        (void) I2CM_I2CMasterWriteBuf(I2C_SLAVE_ADDR_3, buffer, PACKET_SIZE, \
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
uint32 ReadStatusPacket(int cycle, int* pressed)
{
    uint8  buffer[BUFFER_SIZE];
    uint32 status = TRANSFER_ERROR;

    if(cycle % 4 == 0){
        (void) I2CM_I2CMasterReadBuf(I2C_SLAVE_ADDR_0, buffer, PACKET_SIZE, \
                                     I2CM_I2C_MODE_COMPLETE_XFER);
    }
    else if(cycle % 4 == 1){
        (void) I2CM_I2CMasterReadBuf(I2C_SLAVE_ADDR_1, buffer, PACKET_SIZE, \
                                     I2CM_I2C_MODE_COMPLETE_XFER);    
    }
    else if(cycle % 4 == 2){
        (void) I2CM_I2CMasterReadBuf(I2C_SLAVE_ADDR_2, buffer, PACKET_SIZE, \
                I2CM_I2C_MODE_COMPLETE_XFER);  
    }
    else{
        (void) I2CM_I2CMasterReadBuf(I2C_SLAVE_ADDR_3, buffer, PACKET_SIZE, \
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
            //CHANGED VERSION
            int index;
            for(int i = 0; i < 4; i++){
                index = (cycle * 4) + i;
                pressed[index] = buffer[2 + i];
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

void playGame()
{

    int points = 0;
    int tiles[16];
    int colors[16]; //0 = green, 1 = red, 2 = no color
    for(int i = 0; i < 16; i++)
    {
        tiles[i] = i;
    }
    updateTilesAndColors(tiles, colors);
    //tile[0] = green
    //tile[1]->tile[8] = red
    //tile[9]->tile[15] = blank
    
    bool ar[16];
    int oldGreen = tiles[0];
    
    time_t curTime;
    time(&curTime);
    int timeActual = curTime;
    while( curTime - timeActual < 30)
    { 
        ar = getSteppedTiles(); //gets the bool of teh stepped tiles
        bool pointChange = false;
        for(int i = 0; i < 16; i++)
        {
            if(ar[i]) //tile was stepped on
            {
                if(colors[i] == 0) //green
                {
                    points++;
                    pointChange = true;
                }
                else if(colors[i] == 1) //red
                {
                    points--;
                }
            }
        }
        if(pointChange)
        {
            updateTilesAndColors(tiles, colors);
        }
        time(&curTime);
    
    }
}


void updateTilesAndColors(int tiles[], int colors[])
{
    int temp;
        for(int i = 0; i < 16; i++)
        {
            temp = tiles[i];
            int randomIndex = rand() % 16;
            tiles[i] = tiles[randomIndex];
            tiles[randomIndex] = temp;
        }
        colors[tiles[0]] = StripLights_GREEN;
        for(int i = 1; i < 8; i++)
        {
            colors[tiles[i]] = StripLights_RED;
        }
        for(int i = 9; i < 16; i++)
        {
            colors[tiles[i]] = StripLights_BLACK;
        }
}

/*This function will display a number on the LEDs on the score display
Parameters: 
    position: which block to display it on
    number: number to be shown
*/
void DisplayNumber(int position, int number){
    int zero[] = {1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1};
    int one[] = {1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0};
    int two[] = {1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1};
    int three[] = {1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1};
    int four[] = {0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1};
    int five[] = {1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1};
    int six[] = {1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1};
    int seven[] = {0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};
    int eight[] = {1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1};
    int nine[] = {1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1};
    
    int arrayLen = 15;
    if(number == 0){
            for(int i = 0; i < arrayLen; i++){
                if(zero[i] == 1){
                    StripLights_Pixel(i, position, StripLights_WHITE);
                }
                else{
                    StripLights_Pixel(i, position, StripLights_BLACK);
                }
            }
            while (StripLights_Ready() == 0);
        	StripLights_Trigger(1);
        	CyDelay(10);
    }
    if(number == 1){
            for(int i = 0; i < arrayLen; i++){
                if(one[i] == 1){
                    StripLights_Pixel(i, position, StripLights_WHITE);
                }
                else{
                    StripLights_Pixel(i, position, StripLights_BLACK);
                }
            }
            while (StripLights_Ready() == 0);
        	StripLights_Trigger(1);
        	CyDelay(10);
    }
    if(number == 2){
            for(int i = 0; i < arrayLen; i++){
                if(two[i] == 1){
                    StripLights_Pixel(i, position, StripLights_WHITE);
                }
                else{
                    StripLights_Pixel(i, position, StripLights_BLACK);
                }
            }
            while (StripLights_Ready() == 0);
        	StripLights_Trigger(1);
        	CyDelay(10);
            
    }
    if(number == 3){
            for(int i = 0; i < arrayLen; i++){
                if(three[i] == 1){
                    StripLights_Pixel(i, position, StripLights_WHITE);
                }
                else{
                    StripLights_Pixel(i, position, StripLights_BLACK);
                }
            }
            while (StripLights_Ready() == 0);
        	StripLights_Trigger(1);
        	CyDelay(10);
    }
    if(number == 4){
            for(int i = 0; i < arrayLen; i++){
                if(four[i] == 1){
                    StripLights_Pixel(i, position, StripLights_WHITE);
                }
                else{
                    StripLights_Pixel(i, position, StripLights_BLACK);
                }
            }
            while (StripLights_Ready() == 0);
        	StripLights_Trigger(1);
        	CyDelay(10);
    }
    if(number == 5){
            for(int i = 0; i < arrayLen; i++){
                if(five[i] == 1){
                    StripLights_Pixel(i, position, StripLights_WHITE);
                }
                else{
                    StripLights_Pixel(i, position, StripLights_BLACK);
                }
            }
            while (StripLights_Ready() == 0);
        	StripLights_Trigger(1);
        	CyDelay(10);
    }
    if(number == 6){
            for(int i = 0; i < arrayLen; i++){
                if(six[i] == 1){
                    StripLights_Pixel(i, position, StripLights_WHITE);
                }
                else{
                    StripLights_Pixel(i, position, StripLights_BLACK);
                }
            }
            while (StripLights_Ready() == 0);
        	StripLights_Trigger(1);
        	CyDelay(10);
    }
    if(number == 7){
            for(int i = 0; i < arrayLen; i++){
                if(seven[i] == 1){
                    StripLights_Pixel(i, position, StripLights_WHITE);
                }
                else{
                    StripLights_Pixel(i, position, StripLights_BLACK);
                }
            }
            while (StripLights_Ready() == 0);
        	StripLights_Trigger(1);
        	CyDelay(10);
    }   
    if(number == 8){
            for(int i = 0; i < arrayLen; i++){
                if(eight[i] == 1){
                    StripLights_Pixel(i, position, StripLights_WHITE);
                }
                else{
                    StripLights_Pixel(i, position, StripLights_BLACK);
                }
            }
            while (StripLights_Ready() == 0);
        	StripLights_Trigger(1);
        	CyDelay(10);
    }
    if(number == 9){
            for(int i = 0; i < arrayLen; i++){
                if(nine[i] == 1){
                    StripLights_Pixel(i, position, StripLights_WHITE);
                }
                else{
                    StripLights_Pixel(i, position, StripLights_BLACK);
                }
            }
            while (StripLights_Ready() == 0);
        	StripLights_Trigger(1);
        	CyDelay(10);
    }

}
/* [] END OF FILE */
