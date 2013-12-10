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

protected:
};

