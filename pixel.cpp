#include "Pixel.h"
#include "Rgb.h"

Pixel::Pixel(void)
{
	primaryColor = new Rgb();
	secondairyColor = new Rgb();
	upperWaitBound = 30;
	lowerWaitBound = 5;
}

Pixel::Pixel(Rgb *primaryColor, Rgb *secondairyColor, int position, int direction, int jumpInterval)
{
	upperWaitBound = 30;
	lowerWaitBound = 5;
	waitCounter = 0;
	waitTicks = 0;
	primaryColor = primaryColor;
	secondairyColor = secondairyColor;
	position = position;
	direction = direction;
	jumpInterval = jumpInterval;
	prevPosition = position + (((-1)*direction)*jumpInterval);
}


Pixel::~Pixel(void)
{
}

