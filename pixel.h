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
	pixel(rgb color, int position, int direction);
	~pixel(void);

protected:
	//Color of the pixel
	rgb _color;

	//Direction the pixel moves 1 or -1
	int _direction;

	//position of the pixel
	int _position;
};

