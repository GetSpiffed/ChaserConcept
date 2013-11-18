
//=================================
// included dependencies
#include "chaser.h"
#include "rgb.h"
#include "pixel.h"


chaser::chaser(void)
{
}

chaser::chaser(int stripLength, pixel *pixels, int pixelCount)
{
	_stripMask = new rgb[stripLength];
	_pixelCount = pixelCount;
	_pixels = new pixel[_pixelCount];


	for (int i = 0; i < _pixelCount; i++)
		_pixels[i] = pixels[i];

}

void chaser::step(void)
{
	for (int i = 0; i < _pixelCount; i++)
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
	delete[] _pixels;        // important to prevent memory leaks use brackets, 
	//the delete command withoud brackets just deletes the first element

	_pixels = 0;   // even if the pointer no longer exists . . . 
}
