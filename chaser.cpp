
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
	stripMask = new rgb[_stripLength];
	_stripLength = stripLength;
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

	for (int i = 0; i < _pixelCount; i++)
	{
		if (_pixels[i].direction<0)
		{
			jump(_pixels[i]);
		}
	}
}

void chaser::jump(pixel &currentPixel)
{
	//If outside boundries, revert direction
	if (currentPixel.position < 0 && currentPixel.position >= _stripLength)
		currentPixel.direction = currentPixel.direction*-1;

	//store current location as prevLocation
	currentPixel.prevPosition = currentPixel.position;

	//Set new location
	currentPixel.position += currentPixel.direction*currentPixel.jumpInterval;

	//
	setStripMask(currentPixel);
}


void chaser::setStripMask(pixel &currentPixel)
{
	//If position within boundries, set stripMask
	if (currentPixel.position > 0 && currentPixel.position<_stripLength)
	{
		//Draw main pixel
		stripMask[currentPixel.position].red = currentPixel.primaryColor->red;
		stripMask[currentPixel.position].green = currentPixel.primaryColor->green;
		stripMask[currentPixel.position].blue = currentPixel.primaryColor->blue;
	}


	//If prevPosition within boundries, set stripMask
	if (currentPixel.prevPosition>0 && currentPixel.prevPosition < _stripLength)
	{
		//Draw prevPosition
		stripMask[currentPixel.prevPosition].red = currentPixel.secondairyColor->red;
		stripMask[currentPixel.prevPosition].green = currentPixel.secondairyColor->green;
		stripMask[currentPixel.prevPosition].blue = currentPixel.secondairyColor->blue;
	}
}

chaser::~chaser(void)
{
	delete[] _pixels;        // important to prevent memory leaks use brackets, 
	//the delete command withoud brackets just deletes the first element

	_pixels = 0;   // even if the pointer no longer exists . . . 
}
