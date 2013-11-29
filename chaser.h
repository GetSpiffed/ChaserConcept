//=================================
// include guard
#ifndef __MYCLASS_H_INCLUDED__
#define __MYCLASS_H_INCLUDED__

//=================================
// included dependencies
#include "RGB.h"
#include "Pixel.h"


#pragma once
class Chaser
{
public:
	/********************************************************************
	* Constructors
	********************************************************************/
	Chaser(void);
	Chaser(int stripLength, Pixel *pixels, int pixelCount);

	/********************************************************************
	* Methods
	********************************************************************/
	void step(void);

	/********************************************************************
	* Destructors
	********************************************************************/
	~Chaser(void);

	//pointer to the array on witch we draw the pixels
	Rgb *stripMask;

	//pointer to array with the moving pixels
	Pixel *pixels;

protected:


	int pixelCount;

	int stripLength;

	void jump(Pixel &currentPixel);
	void setStripMask(Pixel &currentPixel);
};

#endif // __MYCLASS_H_INCLUDED__ 
