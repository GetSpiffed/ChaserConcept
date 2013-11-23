#pragma once
#include "stdint.h"

struct rgb
{
public:
	rgb(uint8_t red, uint8_t green, uint8_t blue);

	rgb();

	uint8_t green;
	uint8_t red;
	uint8_t blue;
};

