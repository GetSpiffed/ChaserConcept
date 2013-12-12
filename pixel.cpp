#include "Pixel.h"
#include "Rgb.h"

Pixel::Pixel(void)
{
	primaryColor = new Rgb();
	secondairyColor = new Rgb();
	upperWaitBound = 30;
	lowerWaitBound = 5;
	jumpTickInterval = 0;
	jumpTickCounter = 0;
	pixelType = 0;
}

Pixel::Pixel(Rgb *primaryColor, Rgb *secondairyColor, uint8_t position, uint8_t direction, uint8_t jumpStepInterval)
{
	jumpTickInterval = 0;
	upperWaitBound = 30;
	lowerWaitBound = 5;
	waitCounter = 0;
	waitTicks = 0;
	primaryColor = primaryColor;
	secondairyColor = secondairyColor;
	position = position;
	direction = direction;
	jumpStepInterval = jumpStepInterval;
	prevPosition = position + (((-1)*direction)*jumpStepInterval);
	jumpTickCounter = 0;
	pixelType = 0;
}


Pixel::~Pixel(void)
{
}

