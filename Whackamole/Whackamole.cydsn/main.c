//#include "whackamole.h"


#include "project.h"
#include <stdlib.h>
#include <time.h>
    
const int LEDS_PER_TILE = 60;
uint8 button;
uint8 flex0;
uint8 flex1;
uint8 flex2;
uint8 flex3;
int currentSet; //0 = fantastic floor, 1 = flood random lights throughout the board
    
void FantasticFloor();
void EYECANCER();
void DisplayNumber(int position, int number);
void FancyLights();
uint32 IncrementColor(uint32 color);
void RunPattern();
void SetTileColor(int tile_number, uint32 color);
void ResetBlock();
uint32 GetRandomColor();
    

int main(void)
{
	CyGlobalIntEnable; /* Enable global interrupts. */

    //start the interrupts
	StripLights_Start();
	StripLights_Dim(0);
    srand(time(NULL)); // seed the randomness with time
    

    
    for(int i = 0; i < 15; i++){
        StripLights_Pixel(i, 0, StripLights_BLACK);
    }
    while (StripLights_Ready() == 0);
	StripLights_Trigger(1);
	CyDelay(10);
//    EYECANCER();
    
    int i = 0;
    while(1){
        DisplayNumber(0, i);
        i++;
        CyDelay(1000);
        if(i == 10)
            i = 0;
    }
    
//    ResetBlock();
//    FantasticFloor();
}

/**
    OOH SHINEY LIGHTSSSS
*/
void FancyLights(){
    for(;;){
        
        //First sequence of lights
        for(int i = 0; i < 4; i++){
            SetTileColor(i, GetRandomColor());
            button = Button_Read();
            //leave function if toggle button is set
            if(!button){
                currentSet = 0;
                return;
            }
            CyDelay(800);
        }
        
        //Second sequence
        for(int k = 0; k < 2; k++){
            for(int i = 0; i < 4; i++){
                for(int j = 0; j < LEDS_PER_TILE; j++){
                    StripLights_Pixel(j, i, GetRandomColor());
                    while (StripLights_Ready() == 0);
            	    StripLights_Trigger(1);
                    CyDelay(30);
                    
                    button = Button_Read();
                    //leave function if toggle button is set
                    if(!button){
                        currentSet = 0;
                        return;
                    }
                }
            }
        }
        
        //Last Sequence
        uint32 color = StripLights_RED;
        for(int j = 0; j < 7; j++){
            for(int i = 0; i < 4; i++){
                SetTileColor(i, color);
            }
            color = IncrementColor(color);
            CyDelay(100);
            button = Button_Read();
            //leave function if toggle button is set
            if(!button){
                currentSet = 0;
                return;
            }
        }
    }
}

/**
When a block is pressed, light it up with a random color from the rainbow
Break and leave function if the p0.7 button is pressed
*/
void FantasticFloor(){
    for(;;){
        //read the digital inputs
        button = Button_Read();
        flex0 = flex0_Read();
        flex1 = flex1_Read();
        flex2 = flex2_Read();
        flex3 = flex3_Read();
        
        //leave function if toggle button is set
        if(!button){
            currentSet = 1;
//            return;
        }
        
        //otherwise, light the tiles that read flex inputs with a random color
        if(!flex0)
            SetTileColor(0, GetRandomColor());
        else
            SetTileColor(0, StripLights_DIM_WHITE);
        if(!flex1)
            SetTileColor(1, GetRandomColor());
        else
            SetTileColor(1, StripLights_DIM_WHITE);
        if(!flex2)
            SetTileColor(2, GetRandomColor());
        else
            SetTileColor(2, StripLights_DIM_WHITE);
        if(!flex3)
            SetTileColor(3, GetRandomColor());
        else
            SetTileColor(3, StripLights_DIM_WHITE);
        
    }
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
        	SetTileColor(0, 0);
        	SetTileColor(1, 0);
            CyDelay(10);
        	StripLights_Pixel(i, 0, current_color);
        	StripLights_Pixel(i, 1, current_color);
        	while (StripLights_Ready() == 0);
        	StripLights_Trigger(1);
        }
        current_color = IncrementColor(current_color);
        //coming back
        for(int i = 13; i >= 1; i--){
            SetTileColor(0, 0);
        	SetTileColor(1, 0);
            CyDelay(10);
        	StripLights_Pixel(i, 0, current_color);
        	StripLights_Pixel(i, 1, current_color);
        	while (StripLights_Ready() == 0);
        	StripLights_Trigger(1);
        }
        current_color = IncrementColor(current_color);
    }
}


/**
This function will set the lights inside the block number to be a certain color.
Changes are assumemd to be the first 60 LEDs, 
The block number is set to be the "y" coordinate in the top down design
Remember to put a CyDelay after setting colors
*/
void SetTileColor(int tile_number, uint32 color) {
	for (uint32 led = 0; led < LEDS_PER_TILE; led++) {
		StripLights_Pixel(led, tile_number, color);
	}

    while (StripLights_Ready() == 0);
	StripLights_Trigger(1);
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
    uint32 color7 = StripLights_WHITE;
    
    if(color == color1)return color2;
    else if(color == color2)return color3;
    else if(color == color3)return color4;
    else if(color == color4)return color5;
    else if(color == color5)return color6;
    else if (color == color6) return color7;
    else return color1;
}

//Returns a random color
uint32 GetRandomColor(){
    int random = rand() % 7;
    
    switch(random){
        case 0:
            return StripLights_RED;
        case 1:
            return StripLights_ORANGE;
        case 2:
            return StripLights_YELLOW;
        case 3:
            return StripLights_GREEN;
        case 4:
            return StripLights_BLUE;
        case 5:
            return StripLights_VIOLET;
        case 6:
            return StripLights_WHITE;
        default:
            return 0;
    }
}

/*Countdown to epilepsy
*/
void EYECANCER(){
    for(int i = 20; i >= 0; i--){
        DisplayNumber(0, i / 10);
        DisplayNumber(1, i % 10);
        CyDelay(1000);
    }
    
    for(;;){
        for(int i = 0; i < 15; i++){
            StripLights_Pixel(i, 0, GetRandomColor());
            StripLights_Pixel(i, 1, GetRandomColor());
        }
        while(StripLights_Ready() == 0);
        StripLights_Trigger(1);
        CyDelay(10);
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

//Resets all the tile colors to blank
void ResetBlock(){
    SetTileColor(0, 0);
    SetTileColor(1, 0);
    SetTileColor(2, 0);
    SetTileColor(3, 0);
}