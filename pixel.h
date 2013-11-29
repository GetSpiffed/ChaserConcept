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
	Pixel(Rgb *primaryColor, Rgb *secondairyColor, int position, int direction, int jumpInterval);
	~Pixel(void);


	//Color of the pixel to which it jumps to
	Rgb *primaryColor;

	//Color of the pixel from which it jumps from
	Rgb *secondairyColor;

	//Direction the pixel moves 1 or -1
	int direction;

	//position of the pixel
	int position;

	//previous position of the pixel
	int prevPosition;

	//ticks to wait before moving
	int waitTicks;

	//count how many ticks sre waited
	int waitCounter;

	//How much pixels to jump in on the strip
	int jumpInterval;

	//upper and lower boundries for wait randomizer 
	int upperWaitBound;
	int lowerWaitBound;

protected:
};

