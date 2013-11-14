#include "pixel.h"
#include "rgb.h"

pixel::pixel(void)
{
}

pixel::pixel(rgb *colorDest, rgb *colorSrc, int position, int direction, int jumpInterval)
{
	colorDest = colorDest;
	colorSrc = colorSrc;
	position = position;
	direction = direction;
	jumpInterval = jumpInterval;
}


pixel::~pixel(void)
{
}

