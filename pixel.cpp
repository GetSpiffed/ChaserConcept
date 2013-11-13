#include "pixel.h"
#include "rgb.h"

pixel::pixel(void)
{
}

pixel::pixel(rgb colorDest, rgb colorSrc, int position, int direction, int jumpInterval)
{
	_colorDest = colorDest;
	_colorSrc = colorSrc;
	_position = position;
	_direction = direction;
	_jumpInterval = jumpInterval;
}


pixel::~pixel(void)
{
}

