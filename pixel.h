#pragma once

//=================================
// forward declared dependencies
//class rgb;


//=================================
// included dependencies
#include "Rgb.h" //Not using a reference, but an actual object

class Pixel
{
public:
	Pixel(void);
	Pixel(Rgb *primaryColor, Rgb *secondairyColor, uint8_t position, uint8_t direction, uint8_t jumpInterval);
	~Pixel(void);


	//Color of the pixel to which it jumps to
	Rgb *primaryColor;

	//Color of the pixel from which it jumps from
	Rgb *secondairyColor;

	//Direction the pixel moves 1 or -1
	uint8_t direction;

	//position of the pixel
	uint8_t position;

	//previous position of the pixel
	uint8_t prevPosition;

	//ticks to wait before moving
	int waitTicks;

	//count how many ticks has been waited
	int waitCounter;

	//How much pixels to jump on the strip
	uint8_t jumpStepInterval;

	//How much ticks to wait before jump
	uint8_t  jumpTickInterval;

	//count how many ticks has been waited
	uint8_t jumpTickCounter;

	//upper and lower boundries for wait randomizer 
	int upperWaitBound;
	int lowerWaitBound;

	//determines behaviour of the pixel 0=default 1=fixedtail...
	uint8_t pixelType;

	Rgb GetNextColor(uint8_t currentPos)
	{
		//Neopixel wheel implementation
		/*

		// Input a value 0 to 255 to get a color value.
		// The colours are a transition r - g - b - back to r.
		uint32_t Wheel(byte WheelPos) {
			if(WheelPos < 85) {
			return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
			} else if(WheelPos < 170) {
			WheelPos -= 85;
			return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
			} else {
			WheelPos -= 170;
			return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
			}
		}
		*/

	}
protected:
};

