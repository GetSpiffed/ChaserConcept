
//=================================
// included dependencies
#include "Chaser.h"
#include "Pixel.h"

#include <stdlib.h>
//#include "CppFix.h"

Chaser::Chaser(void)
{
}

Chaser::Chaser(uint8_t stripLength, Pixel *pixels, uint8_t pixelCount)
{
	Chaser::stripLength = stripLength;
	stripMask = new uint32_t[Chaser::stripLength];

	for (int i = 0; i < Chaser::stripLength; i++)
	{
		stripMask[i] = 0;
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
		//Pixel is not on the strip and counter is not at max value
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

			if (currentPixel.pixelType == 1)
			{
				currentPixel.primaryColor = GetNextColor(currentPixel.colorPointer);

				if (currentPixel.colorPointer >= 255)
				{
					currentPixel.colorPointer = 0;
				}
				else
				{
					currentPixel.colorPointer+=16;
				}
			}

		}
		//store current location as prevLocation
		currentPixel.prevPosition = currentPixel.position;

		//Set new location
		currentPixel.position += (currentPixel.direction*currentPixel.jumpStepInterval);

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
		stripMask[currentPixel.position] = currentPixel.primaryColor;
	}


	//If prevPosition within boundries, set stripMask
	if (currentPixel.prevPosition >= 0 && currentPixel.prevPosition < Chaser::stripLength)
	{
		//Draw prevPosition
		stripMask[currentPixel.prevPosition] = currentPixel.secondairyColor;
	}
}


uint32_t Chaser::Color(uint8_t r, uint8_t g, uint8_t b) 
{
	return ((uint32_t)r << 16) | ((uint32_t)g << 8) | b;
}

uint32_t Chaser::GetNextColor(uint8_t colorPointer)
{
	//Neopixel wheel implementation
	if (colorPointer < 85) {
		return Chaser::Color(colorPointer * 3, 255 - colorPointer * 3, 0);
	}
	else if (colorPointer < 170) {
		colorPointer -= 85;
		return Chaser::Color(255 - colorPointer * 3, 0, colorPointer * 3);
	}
	else {
		colorPointer -= 170;
		return Chaser::Color(0, colorPointer * 3, 255 - colorPointer * 3);
	}

}


Chaser::~Chaser(void)
{
	delete[] Chaser::pixels;        // important to prevent memory leaks use brackets, 
	//the delete command withoud brackets just deletes the first element

	Chaser::pixels = 0;   // even if the pointer no longer exists . . . 
}
