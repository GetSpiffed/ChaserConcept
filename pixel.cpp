#include "pixel.h"
#include "rgb.h"

pixel::pixel(void)
{
	primaryColor = new rgb();
	secondairyColor = new rgb();
	upperWaitBound = 30;
	lowerWaitBound = 5;
}

pixel::pixel(rgb *primaryColor, rgb *secondairyColor, int position, int direction, int jumpInterval)
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


pixel::~pixel(void)
{
}

