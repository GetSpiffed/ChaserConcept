//=================================
// include guard
#ifndef __MYCLASS_H_INCLUDED__
#define __MYCLASS_H_INCLUDED__

//=================================
// included dependencies
#include "Pixel.h"


#pragma once
class Chaser
{
public:
	/********************************************************************
	* Constructors
	********************************************************************/
	Chaser(void);
	Chaser(uint8_t stripLength, Pixel *pixels, uint8_t pixelCount);

	/********************************************************************
	* Methods
	********************************************************************/
	void step(void);
	uint32_t GetNextColor(uint8_t colorPointer);
	uint32_t Color(uint8_t r, uint8_t g, uint8_t b);


	/********************************************************************
	* Destructors
	********************************************************************/
	~Chaser(void);

	//pointer to the array on witch we draw the pixels
	uint32_t *stripMask;

	//pointer to array with the moving pixels
	Pixel *pixels;

protected:


	uint8_t pixelCount;
	uint8_t stripLength;

	void jump(Pixel &currentPixel);
	void setStripMask(Pixel &currentPixel);
};

#endif // __MYCLASS_H_INCLUDED__ 
