#include "pixel.h"
#include "rgb.h"

pixel::pixel(void)
{
}

pixel::pixel(rgb color, int position, int direction)
{
	_color = color;
	_position = position;
	_direction = direction;
}


pixel::~pixel(void)
{
}

