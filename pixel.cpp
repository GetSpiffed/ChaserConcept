#include "pixel.h"
#include "rgb.h"

pixel::pixel(void)
{
}

pixel::pixel(rgb *primaryColor, rgb *secondairyColor, int position, int direction, int jumpInterval)
{
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

