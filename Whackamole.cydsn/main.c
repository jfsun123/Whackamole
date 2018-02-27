/* ========================================
 *
 * EX2_String
 *
 * A simple function to cycle the color table
 * through the string.
 *
 * ========================================
*/
#include "project.h"
#include <stdlib.h>
#include <time.h>

void SlowColorBlend(uint32 delay, uint32 time);
void SetBlockColor(int block_number, uint32 color);

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    srand(time(NULL)); // seed the randomness with time
    StripLights_Start();
    StripLights_Dim(0);
    
    uint32 color = StripLights_RED;
    for(;;)
    {
        int random = rand() % 4; //random number between 0 and 3
        uint8 button = Pin_Flex_Read();
        if(button){
            color = StripLights_GREEN;
        }
        else{
            color = StripLights_RED;
        }
        
        SetBlockColor(1, color);
        /*for(uint32 led = 0; led <= 30; led++){
            
            StripLights_Pixel(led, 0, color);
            while( StripLights_Ready() == 0);
	
            StripLights_Trigger(1);
            
        }
        CyDelay(10);*/
        

    }
}

/**
    This function will set the lights inside the block number to be a certain color.
    Changes are assumemd to be the first 20 LEDs, so make sure that each block has exactly 20 LEDS
    Block number starts from 1, not 0
*/
void SetBlockColor(int block_number, uint32 color){
    uint32 starting_led_index = (block_number - 1) * 20;
    uint32 ending_led_index = (block_number) * 20;
    for (uint32 led = starting_led_index; led < ending_led_index; led++){
        StripLights_Pixel(led, 0, color);
        while(StripLights_Ready() == 0);
        StripLights_Trigger(1);
    }
    CyDelay(10);
}


/************************************************
 *                    SlowColorBlend()
 *
 *  Slowly migate all the LEDs through the color
 *  table.
 *  Not being used right now
 ************************************************/
void SlowColorBlend(uint32 delay, uint32 time)
{
    uint32 timeCnt = 0; 
    uint32 led = 0;
    uint32 x = 0;
    uint32 pct = 0;
    uint32 fromColor, toColor, color;
    extern const uint32 StripLights_CLUT[ ];

    

    for(;;)
    {   
        while(1)
        {
           
            for(pct = 0; pct < 100; pct += 4)
            {
                for(led = 0; led <= StripLights_MAX_X; led++)
                {
 
                    fromColor =  StripLights_CLUT[(x + 0 + ((led * StripLights_COLOR_WHEEL_SIZE)/StripLights_TOTAL_LEDS)) % StripLights_COLOR_WHEEL_SIZE];
                    toColor =  StripLights_CLUT[(x + 1 + ((led * StripLights_COLOR_WHEEL_SIZE)/StripLights_TOTAL_LEDS)) % StripLights_COLOR_WHEEL_SIZE];
                    
                    color = StripLights_RgbBlend(fromColor, toColor, pct);                  
                    StripLights_Pixel(led, 0, color );
                }
                
                while( StripLights_Ready() == 0);
	
                StripLights_Trigger(1);
                
                CyDelay(delay);

            }
            x++;  // Advance through color wheel
        }
        timeCnt += delay;
 
     
     if(SW1_Read() == 0) break;  // If SW1 pressed leave
         if(timeCnt > time) break;
    }	
	// Wait for SW1 to be released then delay a bit for debouncing
	while(SW1_Read() == 0);         
	CyDelay(50);  
}

/* [] END OF FILE */
