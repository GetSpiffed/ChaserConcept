//=================================
// include guard
#ifndef __MYCLASS_H_INCLUDED__
#define __MYCLASS_H_INCLUDED__

//=================================
// included dependencies
#include "rgb.h"
#include "pixel.h"


#pragma once
class chaser
{
public:
	/********************************************************************
	* Constructors
	********************************************************************/
	chaser(void);
	chaser(int stripLength, pixel *pixels, int pixelCount);

	/********************************************************************
	* Methods
	********************************************************************/
	void step(void);

	/********************************************************************
	* Destructors
	********************************************************************/
	~chaser(void);

	//pointer to the array on witch we draw the pixels
	rgb *stripMask;

	//pointer to array with the moving pixels
	pixel *_pixels;

protected:


	int _pixelCount;

	int _stripLength;

	void jump(pixel &currentPixel);
	void setStripMask(pixel &currentPixel);
};

#endif // __MYCLASS_H_INCLUDED__ 
