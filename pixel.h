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
	pixel(rgb colorDest, rgb colorSrc, int position, int direction, int jumpInterval);
	~pixel(void);

protected:
	//Color of the pixel to which it jumps to
	rgb _colorDest;

	//Color of the pixel from which it jumps from
	rgb _colorSrc;

	//Direction the pixel moves 1 or -1
	int _direction;

	//position of the pixel
	int _position;

	//How much pixels to jump in on the strip
	int _jumpInterval;
};

