
//=================================
// included dependencies
#include "chaser.h"
#include "rgb.h"
#include "pixel.h"


chaser::chaser(void)
{
}

chaser::chaser(int stripLength, pixel *pixels)
{
	_stripMask = new rgb[stripLength];
	_pixels = _pixels;
}

void chaser::step(void)
{
	for (int i = 0; i < (sizeof(pixel) / sizeof(*_pixels)); i++)
	{
		
	}
}

chaser::~chaser(void)
{
}
