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
	pixel(rgb *colorDest, rgb *colorSrc, int position, int direction, int jumpInterval);
	~pixel(void);


	//Color of the pixel to which it jumps to
	rgb *colorDest;

	//Color of the pixel from which it jumps from
	rgb *colorSrc;

	//Direction the pixel moves 1 or -1
	int direction;

	//position of the pixel
	int position;

	//How much pixels to jump in on the strip
	int jumpInterval;
protected:
};

