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

protected:
	//pointer to the array on witch we draw the pixels
	rgb *_stripMask; 

	//pointer to array with the moving pixels
	pixel *_pixels;

	int _pixelCount;

	void chaser::jump(pixel &currentPixel);
};

#endif // __MYCLASS_H_INCLUDED__ 
