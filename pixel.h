#pragma once

//=================================
// forward declared dependencies
//class rgb;


//=================================
// included dependencies
#include "rgb.h" //Not using a reference, but an actual object

class pixel
{
public:
	pixel(void);
	pixel(rgb *primaryColor, rgb *secondairyColor, int position, int direction, int jumpInterval);
	~pixel(void);


	//Color of the pixel to which it jumps to
	rgb *primaryColor;

	//Color of the pixel from which it jumps from
	rgb *secondairyColor;

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
protected:
};

