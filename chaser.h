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
	chaser(int stripLength, pixel *pixels);

	/********************************************************************
	* Methods
	********************************************************************/
	void step(void);

	/********************************************************************
	* Destructors
	********************************************************************/
	~chaser(void);

protected:
	//pointer to the array on witch we draw the pixels
	rgb *_stripMask; 

	//pointer to array with the moving pixels
	pixel *_pixels;
};

#endif // __MYCLASS_H_INCLUDED__ 
