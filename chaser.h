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
	chaser::chaser(void);
	chaser::chaser(int stripLength, pixel *pixels, int pixelCount);

	/********************************************************************
	* Methods
	********************************************************************/
	void chaser::step(void);

	/********************************************************************
	* Destructors
	********************************************************************/
	chaser::~chaser(void);

	//pointer to the array on witch we draw the pixels
	rgb *stripMask;


protected:

	//pointer to array with the moving pixels
	pixel *_pixels;

	int _pixelCount;

	int _stripLength;

	void chaser::jump(pixel &currentPixel);
	void chaser::setStripMask(pixel &currentPixel);
};

#endif // __MYCLASS_H_INCLUDED__ 
