#pragma once
#include "stdint.h"

struct Rgb
{
public:
	Rgb(uint8_t red, uint8_t green, uint8_t blue);

	Rgb();

	uint8_t green;
	uint8_t red;
	uint8_t blue;
};

