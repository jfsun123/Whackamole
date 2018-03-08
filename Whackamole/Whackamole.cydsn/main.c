#include "project.h"
#include <stdlib.h>
#include <time.h>

CY_ISR_PROTO(Button_Interrupt);

void SetBlockColor(int block_number, uint32 color);
uint32 IncrementColor(uint32 color);
void RunPattern();

uint8 buttonCheck = 1;

int main(void)
{
	CyGlobalIntEnable; /* Enable global interrupts. */
	srand(time(NULL)); // seed the randomness with time
    //start the interrupts
    (void) Button_ClearInterrupt();
//    ISR_Write_StartEx(&ISR_WriteSW1_Interrupt);
	StripLights_Start();
	StripLights_Dim(1);

    RunPattern();
}

/**
This function will set the lights inside the block number to be a certain color.
Changes are assumemd to be the first 60 LEDs, 
The block number is set to be the "y" coordinate in the top down design
Remember to put a CyDelay after setting colors
*/
void SetBlockColor(int block_number, uint32 color) {
	for (uint32 led = 0; led < 15; led++) {
		StripLights_Pixel(led, block_number, color);
		while (StripLights_Ready() == 0);
		StripLights_Trigger(1);
	}
//	CyDelay(10);
}

/**
This function will "increment" the color such that it goes through the rainbow
Then it will return the color as a uint32
*/

uint32 IncrementColor(uint32 color){
    //the colors of the rainbow
	uint32 color1 = StripLights_RED;
	uint32 color2 = StripLights_ORANGE;
    uint32 color3 = StripLights_YELLOW;
    uint32 color4 = StripLights_GREEN;
    uint32 color5 = StripLights_BLUE;
    uint32 color6 = StripLights_VIOLET;
    
    if(color == color1)return color2;
    else if(color == color2)return color3;
    else if(color == color3)return color4;
    else if(color == color4)return color5;
    else if(color == color5)return color6;
    else return color1;
}

/**
Runs the LED pattern where light moves along the line
And then goes back, changes colors every time it gets to an edge
*/

void RunPattern(){
    //start the pattern at red
    uint32 current_color = StripLights_RED;
    for(;;){
        //going forward
        for(int i = 0; i < 15; i++){
            //reset the colors for both strips
        	SetBlockColor(0, 0);
        	SetBlockColor(1, 0);
            CyDelay(10);
        	StripLights_Pixel(i, 0, current_color);
        	StripLights_Pixel(i, 1, current_color);
        	while (StripLights_Ready() == 0);
        	StripLights_Trigger(1);
        }
        current_color = IncrementColor(current_color);
        //coming back
        for(int i = 13; i >= 1; i--){
            SetBlockColor(0, 0);
        	SetBlockColor(1, 0);
            CyDelay(10);
        	StripLights_Pixel(i, 0, current_color);
        	StripLights_Pixel(i, 1, current_color);
        	while (StripLights_Ready() == 0);
        	StripLights_Trigger(1);
        }
        current_color = IncrementColor(current_color);
    }
}

CY_ISR(Button_Interrupt)
{
    /* Clear pin interrupt request bit */
    (void) Button_ClearInterrupt();

    /* Select write action */
    buttonCheck = 0;
}