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
	chaser(void);
	chaser(rgb stripMask, pixel pixels);

	void step(void);

	~chaser(void);

protected:
	rgb _stripMask;
	pixel _pixels;
};

#endif // __MYCLASS_H_INCLUDED__ 
