#include "project.h"
#include <stdlib.h>
#include <time.h>

void SetBlockColor(int block_number, uint32 color);

int main(void)
{
	CyGlobalIntEnable; /* Enable global interrupts. */
	srand(time(NULL)); // seed the randomness with time
	StripLights_Start();
	StripLights_Dim(1);

	uint32 color1 = StripLights_BLUE;
	uint32 color2 = StripLights_RED;
	int counter = 0;
	for (;;)
	{

		SetBlockColor(0, 0);
		SetBlockColor(1, 0);
		StripLights_Pixel(counter % 15, 0, color1);
		StripLights_Pixel(counter % 15, 1, color2);
		while (StripLights_Ready() == 0);
		StripLights_Trigger(1);
		counter++;
		//CyDelay(10);


	}
}

/**
This function will set the lights inside the block number to be a certain color.
Changes are assumemd to be the first 60 LEDs, so make sure that each block has exactly 20 LEDS
Block number starts from 0
*/
void SetBlockColor(int block_number, uint32 color) {
	uint32 starting_led_index = (block_number) * 60;
	uint32 ending_led_index = (block_number + 1) * 60;
	for (uint32 led = starting_led_index; led < ending_led_index; led++) {
		StripLights_Pixel(led, block_number, color);
		while (StripLights_Ready() == 0);
		StripLights_Trigger(1);
	}
	CyDelay(10);
}
