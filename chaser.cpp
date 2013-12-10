
//=================================
// included dependencies
#include "Chaser.h"
#include "RGB.h"
#include "Pixel.h"

#include <stdlib.h>
//#include "CppFix.h"

Chaser::Chaser(void)
{
}

Chaser::Chaser(uint8_t stripLength, Pixel *pixels, uint8_t pixelCount)
{
	Chaser::stripLength = stripLength;
	stripMask = new Rgb[Chaser::stripLength];

	for (int i = 0; i < Chaser::stripLength; i++)
	{
		stripMask[i].red = 0;
		stripMask[i].green = 0;
		stripMask[i].blue = 0;
	}

	Chaser::pixelCount = pixelCount;
	Chaser::pixels = new Pixel[Chaser::pixelCount];


	for (int i = 0; i < Chaser::pixelCount; i++)
		Chaser::pixels[i] = pixels[i];

}

void Chaser::step(void)
{
	for (int i = 0; i < Chaser::pixelCount; i++)
	{
		jump(Chaser::pixels[i]);
	}
}

void Chaser::jump(Pixel &currentPixel)
{
	if ((currentPixel.position < 0 || currentPixel.position >= Chaser::stripLength) && currentPixel.waitCounter != currentPixel.waitTicks)
	{
		currentPixel.waitCounter++;
	}
	else if (currentPixel.jumpTickCounter<currentPixel.jumpTickInterval)
	{
		currentPixel.jumpTickCounter++;
	}
	else
	{
		if (currentPixel.jumpTickInterval >0 && currentPixel.jumpTickCounter == currentPixel.jumpTickInterval)
		{
			//reset jumpTickCounter
			currentPixel.jumpTickCounter = 0;
		}

		if (currentPixel.waitCounter == currentPixel.waitTicks)
		{
			//reset wait
			currentPixel.waitCounter = 0;
			currentPixel.waitTicks = currentPixel.lowerWaitBound + rand() % currentPixel.upperWaitBound;
		}
		//store current location as prevLocation
		currentPixel.prevPosition = currentPixel.position;

		//Set new location
		currentPixel.position += currentPixel.direction*currentPixel.jumpStepInterval;

		//If outside boundries, revert direction
		if (currentPixel.position < 0 || currentPixel.position >= Chaser::stripLength)
			currentPixel.direction = currentPixel.direction*-1;

		setStripMask(currentPixel);
	}
}


void Chaser::setStripMask(Pixel &currentPixel)
{
	//If position within boundries, set stripMask
	if (currentPixel.position >= 0 && currentPixel.position < Chaser::stripLength)
	{
		//Draw main pixel
		stripMask[currentPixel.position].red = currentPixel.primaryColor->red;
		stripMask[currentPixel.position].green = currentPixel.primaryColor->green;
		stripMask[currentPixel.position].blue = currentPixel.primaryColor->blue;
	}


	//If prevPosition within boundries, set stripMask
	if (currentPixel.prevPosition >= 0 && currentPixel.prevPosition < Chaser::stripLength)
	{
		//Draw prevPosition
		stripMask[currentPixel.prevPosition].red = currentPixel.secondairyColor->red;
		stripMask[currentPixel.prevPosition].green = currentPixel.secondairyColor->green;
		stripMask[currentPixel.prevPosition].blue = currentPixel.secondairyColor->blue;
	}
}

Chaser::~Chaser(void)
{
	delete[] Chaser::pixels;        // important to prevent memory leaks use brackets, 
	//the delete command withoud brackets just deletes the first element

	Chaser::pixels = 0;   // even if the pointer no longer exists . . . 
}
