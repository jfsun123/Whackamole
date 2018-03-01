#include "project.h"
#include <stdlib.h>
#include <time.h>

void SetBlockColor(int block_number, uint32 color);
uint32 IncrementColor(uint32 color);

int main(void)
{
	CyGlobalIntEnable; /* Enable global interrupts. */
	srand(time(NULL)); // seed the randomness with time
	StripLights_Start();
	StripLights_Dim(0);


    uint32 current_color = StripLights_RED;
	for (;;)
	{
        
        //going forward
        for(int i = 0; i < 15; i++){
            //reset the colors for both strips
    		SetBlockColor(0, 0);
    		SetBlockColor(1, 0);
            
    		StripLights_Pixel(i, 0, current_color);
    		StripLights_Pixel(i, 1, current_color);
    		while (StripLights_Ready() == 0);
    		StripLights_Trigger(1);
    		CyDelay(50);
        }
        current_color = IncrementColor(current_color);
        //coming back
        for(int i = 14; i >= 0; i--){
            SetBlockColor(0, 0);
    		SetBlockColor(1, 0);
            
    		StripLights_Pixel(i, 0, current_color);
    		StripLights_Pixel(i, 1, current_color);
    		while (StripLights_Ready() == 0);
    		StripLights_Trigger(1);
    		CyDelay(50);
        }
		current_color = IncrementColor(current_color);
	}
}

/**
This function will set the lights inside the block number to be a certain color.
Changes are assumemd to be the first 60 LEDs, 
The block number is set to be the "y" coordinate in the top down design
*/
void SetBlockColor(int block_number, uint32 color) {
	for (uint32 led = 0; led < 60; led++) {
		StripLights_Pixel(led, block_number, color);
		while (StripLights_Ready() == 0);
		StripLights_Trigger(1);
	}
	CyDelay(10);
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