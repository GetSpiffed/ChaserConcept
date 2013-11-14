
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
	_pixels = pixels;
}

void chaser::step(void)
{
	for (int i = 0; i < (sizeof(pixel) / sizeof(*_pixels)); i++)
	{
		if (_pixels[i].direction>0)
		{
			jump(_pixels[i]);
		}
	}
}

void chaser::jump(pixel &currentPixel)
{
	currentPixel.position += (currentPixel.direction)*currentPixel.jumpInterval;
}

chaser::~chaser(void)
{
}
